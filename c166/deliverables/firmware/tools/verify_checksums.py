#!/usr/bin/env python3
"""Verify the three Delphi MT05.2 flash checksums and print the dump hash."""
import hashlib
import struct
import sys

BLOCKS = [
    ("boot", 0x00000, 0x01FFE, 0x01FFE),
    ("calibration", 0x05000, 0x0AFFE, 0x0AFFE),
    ("application", 0x0B000, 0x3FFFC, 0x3FFFE),
]

def csum(data, start, end):
    total = 0
    for i in range(start, end, 2):
        total += (data[i] << 8) | data[i + 1]
    return total & 0xFFFF

def main():
    if len(sys.argv) != 2:
        print("usage: verify_checksums.py <dump.bin>", file=sys.stderr)
        return 2
    data = open(sys.argv[1], "rb").read()
    print(f"file: {sys.argv[1]}")
    print(f"size: {len(data)} bytes")
    print(f"sha256: {hashlib.sha256(data).hexdigest()}")
    print("algorithm: sum of (byte[i]<<8 | byte[i+1]), modulo 65536")
    ok = True
    for name, start, end, stored_at in BLOCKS:
        stored = struct.unpack_from("<H", data, stored_at)[0]
        computed = csum(data, start, end)
        status = "ok" if stored == computed else "MISMATCH"
        if stored != computed:
            ok = False
        print(f"  {name:12s} range=0x{start:05X}-0x{end-1:05X} "
              f"stored=0x{stored:04X} computed=0x{computed:04X} {status}")
    return 0 if ok else 1

if __name__ == "__main__":
    raise SystemExit(main())
