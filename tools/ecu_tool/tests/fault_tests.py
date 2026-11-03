#!/usr/bin/env python3
"""Failure-path tests for ecu_tool using a PTY fake ECU."""
import os
import pty
import select
import subprocess
import sys
import threading
import tty

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))
TOOL = os.path.join(ROOT, "tools", "ecu_tool", "build", "ecu_tool")
DUMP = os.path.join(ROOT, "dumps", "mash_dump.bin")


def checksum(data):
    return sum(data) & 0xFF


def frame(payload):
    body = bytes([0x80, 0xF1, 0x11, len(payload)]) + payload
    return body + bytes([checksum(body)])


def live_packet():
    data = bytearray(100)
    data[0x58:0x5A] = (1801 * 4).to_bytes(2, "big")
    return bytes([0x61, 0x01]) + bytes(data)


class Fake:
    def __init__(self, image, live_reply, read_reply):
        self.image = image
        self.live_reply = live_reply
        self.read_reply = read_reply
        self.stop = threading.Event()

    def serve(self, master):
        buf = bytearray()
        while not self.stop.is_set():
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
                    response = self.live_reply
                elif payload and payload[0] == 0x23:
                    if self.read_reply and self.read_reply[0] == 0x7F:
                        response = self.read_reply
                    else:
                        addr = (payload[1] << 16) | (payload[2] << 8) | payload[3]
                        count = payload[4]
                        off = addr - 0xC00000
                        response = bytes([0x63]) + bytes(self.image[off:off + count])
                else:
                    response = self.read_reply
                os.write(master, frame(response))


def run(args, fake, timeout=30):
    master, slave = pty.openpty()
    tty.setraw(master)
    tty.setraw(slave)
    slave_name = os.ttyname(slave)
    thread = threading.Thread(target=fake.serve, args=(master,), daemon=True)
    thread.start()
    try:
        proc = subprocess.run([TOOL, "--port", slave_name, "--timeout", "300"] + args,
                              stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                              timeout=timeout)
    finally:
        fake.stop.set()
        os.close(master)
        os.close(slave)
    return proc


def main():
    image = bytearray(open(DUMP, "rb").read())
    ok = True

    cases = [
        ("negative live", ["live", "--count", "1"],
         bytes([0x7F, 0x21, 0x12]), bytes([0x7F, 0x23, 0x12]), 1),
        ("short live", ["live", "--count", "1"],
         bytes([0x61, 0x01]) + bytes(50), bytes([0x7F, 0x23, 0x12]), 1),
        ("negative read", ["read", "--addr", "0xC05000", "--len", "1"],
         live_packet(), bytes([0x7F, 0x23, 0x31]), 1),
    ]
    for name, args, live_reply, read_reply, expected in cases:
        fake = Fake(image, live_reply, read_reply)
        proc = run(args, fake)
        passed = proc.returncode == expected
        print("%-16s rc=%d expected=%d %s" % (name, proc.returncode, expected,
                                              "ok" if passed else "FAIL"))
        if not passed:
            sys.stderr.write(proc.stdout.decode(errors="replace"))
            sys.stderr.write(proc.stderr.decode(errors="replace"))
            ok = False

    bad = bytearray(image)
    bad[0xC10000 - 0xC00000] ^= 0xFF
    fake = Fake(bad, live_packet(), None)
    import tempfile
    with tempfile.TemporaryDirectory() as td:
        proc = run(["dump", "--out", os.path.join(td, "dump.bin")], fake, timeout=60)
    passed = proc.returncode == 2
    print("%-16s rc=%d expected=2 %s" % ("bad flash checksum", proc.returncode,
                                         "ok" if passed else "FAIL"))
    if not passed:
        sys.stderr.write(proc.stdout.decode(errors="replace"))
        sys.stderr.write(proc.stderr.decode(errors="replace"))
        ok = False

    print("fault tests", "passed" if ok else "FAILED")
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
