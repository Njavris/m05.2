#!/usr/bin/env python3
"""Offline K-line ECU emulator for the ecu_tool test suite.

Creates a PTY, runs the tool against it, and answers KWP2000 requests from the
local dump. Unix only (PTY); no hardware or ECU is touched.
"""
import os
import pty
import select
import subprocess
import sys
import tempfile
import tty

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
DUMP = os.path.join(ROOT, "dumps", "mash_dump.bin")
CAL = os.path.join(ROOT, "artifacts", "calibration_block.bin")

image = bytearray(open(DUMP, "rb").read())
calibration = open(CAL, "rb").read()


def checksum(data):
    return sum(data) & 0xFF


def frame(payload):
    body = bytes([0x80, 0xF1, 0x11, len(payload)]) + payload
    return body + bytes([checksum(body)])


def live_packet():
    data = bytearray(100)
    def put(off, value):
        data[off] = (value >> 8) & 0xFF
        data[off + 1] = value & 0xFF
    put(0x58, 1801 * 4)
    put(0x4E, 45 * 256)
    put(0x44, 84 * 128)
    put(0x4A, 29 * 128)
    put(0x4C, int(12.9 * 2048))
    put(0x56, 1014 * 64)
    put(0x1A, int(2.73 * 64))
    put(0x35, int(1.34 * 64))
    put(0x2F, int(15.0 * 128))
    put(0x1E, int(54.4 * 327.68))
    data[0x37:0x3C] = bytes([0x8D, 0x87, 0x9F, 0x6F, 0xE5])
    return bytes([0x61, 0x01]) + bytes(data)


def serve(master, stop):
    buf = bytearray()
    while not stop.is_set():
        ready, _, _ = select.select([master], [], [], 0.1)
        if not ready:
            continue
        try:
            chunk = os.read(master, 4096)
        except OSError:
            break
        if not chunk:
            break
        buf.extend(chunk)
        while len(buf) >= 5:
            if buf[0] != 0x80:
                del buf[0]
                continue
            length = buf[3]
            total = 4 + length + 1
            if len(buf) < total:
                break
            payload = bytes(buf[4:4 + length])
            del buf[:total]
            if payload and payload[0] == 0x81:
                response = bytes([0xC1, 0xEF, 0x8F])
            elif payload[:2] == b"\x21\x01":
                response = live_packet()
            elif payload[:2] == b"\x21\x03":
                response = bytes([0x61, 0x03, 0x01, 0x02, 0x03, 0x04])
            elif payload[:2] == b"\x21\x04":
                response = bytes([0x61, 0x04, 0x05, 0x06, 0x07, 0x08])
            elif payload[:2] == b"\x21\xFF":
                response = bytes([0x61, 0xFF, 0x00, 0x00, 0x12, 0x34])
            elif payload and payload[0] == 0x23:
                addr = (payload[1] << 16) | (payload[2] << 8) | payload[3]
                count = payload[4]
                off = addr - 0xC00000
                response = bytes([0x63]) + bytes(image[off:off + count])
            elif payload[:2] == b"\x27\x01":
                response = bytes([0x67, 0x01, 0x12, 0x34])
            elif payload[:2] == b"\x27\x02":
                response = bytes([0x67, 0x02, 0x34]) if payload[2:] == b"\x84\x74" else bytes([0x7F, 0x27, 0x35])
            elif payload and payload[0] == 0x34:
                response = bytes([0x74, 0xFB])
            elif payload and payload[0] == 0x36:
                addr = (payload[1] << 16) | (payload[2] << 8) | payload[3]
                data = payload[4:4 + 128]
                off = addr - 0xC00000
                image[off:off + 128] = data
                response = bytes([0x76, sum(data) & 0xFF])
            else:
                response = bytes([0x7F, payload[0] if payload else 0, 0x12])
            os.write(master, frame(response))


def run(tool, args, timeout=30):
    master, slave = pty.openpty()
    tty.setraw(master)
    tty.setraw(slave)
    slave_name = os.ttyname(slave)
    stop = __import__("threading").Event()
    import threading
    thread = threading.Thread(target=serve, args=(master, stop), daemon=True)
    thread.start()
    try:
        proc = subprocess.run([tool, "--port", slave_name, "--timeout", "1000"] + args,
                              stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                              timeout=timeout)
    finally:
        stop.set()
        try:
            os.close(master)
        except OSError:
            pass
        try:
            os.close(slave)
        except OSError:
            pass
    return proc


def main():
    tool = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "ecu_tool", "build", "ecu_tool")
    ok = True
    live = run(tool, ["live", "--count", "1"])
    print("live rc", live.returncode)
    if live.returncode != 0 or b"rpm=" not in live.stdout:
        sys.stderr.write(live.stderr.decode(errors="replace"))
        ok = False
    ids = run(tool, ["ids"])
    print("ids rc", ids.returncode)
    if ids.returncode != 0 or b"21 03" not in ids.stdout:
        sys.stderr.write(ids.stderr.decode(errors="replace"))
        ok = False
    unsafe = run(tool, ["write-cal", "--file", CAL])
    print("write-without-confirmation rc", unsafe.returncode)
    if unsafe.returncode == 0:
        sys.stderr.write("write-cal accepted a non-interactive write without --i-understand\n")
        ok = False
    with tempfile.TemporaryDirectory() as td:
        out = os.path.join(td, "dump.bin")
        dump = run(tool, ["dump", "--out", out])
        print("dump rc", dump.returncode)
        if dump.returncode != 0 or not os.path.exists(out):
            sys.stderr.write(dump.stderr.decode(errors="replace"))
            ok = False
        write = run(tool, ["write-cal", "--file", CAL, "--i-understand"], timeout=120)
        print("write rc", write.returncode)
        if write.returncode != 0:
            sys.stderr.write(write.stderr.decode(errors="replace"))
            ok = False
    print("fake ECU tests", "passed" if ok else "FAILED")
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
