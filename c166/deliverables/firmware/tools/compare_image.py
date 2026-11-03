#!/usr/bin/env python3
"""Compare two 256 KB ECU images and verify their internal checksums."""
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

def verify(data):
    ok = True
    for name, start, end, stored_at in BLOCKS:
        stored = struct.unpack_from("<H", data, stored_at)[0]
        computed = csum(data, start, end)
        status = "ok" if stored == computed else "MISMATCH"
        if stored != computed:
            ok = False
        print(f"  {name:12s} stored=0x{stored:04X} computed=0x{computed:04X} {status}")
    return ok

def main():
    if len(sys.argv) != 3:
        print("usage: compare_image.py <a.bin> <b.bin>", file=sys.stderr)
        return 2
    a = open(sys.argv[1], "rb").read()
    b = open(sys.argv[2], "rb").read()
    print(f"A: {sys.argv[1]}  {len(a)} bytes  sha256={hashlib.sha256(a).hexdigest()}")
    print(f"B: {sys.argv[2]}  {len(b)} bytes  sha256={hashlib.sha256(b).hexdigest()}")
    if len(a) != len(b):
        print("size mismatch")
        return 1

    diffs = 0
    ranges = []
    i = 0
    while i < len(a):
        if a[i] != b[i]:
            j = i
            while j < len(a) and a[j] != b[j]:
                j += 1
            ranges.append((i, j))
            diffs += j - i
            i = j
        else:
            i += 1

    print(f"differing bytes: {diffs} in {len(ranges)} ranges")
    for start, end in ranges[:40]:
        print(f"  0x{start:06X}..0x{end - 1:06X}  {end - start} bytes")
    if len(ranges) > 40:
        print(f"  ... {len(ranges) - 40} more ranges")

    print("A checksums:")
    ok_a = verify(a)
    print("B checksums:")
    ok_b = verify(b)

    if diffs != 0 or not ok_a or not ok_b:
        return 1
    print("images are byte-identical and checksums pass")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
