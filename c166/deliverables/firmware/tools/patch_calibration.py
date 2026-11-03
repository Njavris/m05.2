#!/usr/bin/env python3
"""Apply a byte patch to an ECU image and repair the containing checksum.

Examples:
  python3 tools/patch_calibration.py in.bin out.bin 0xC0794A 00,01,02,03
  python3 tools/patch_calibration.py in.bin out.bin 0x00C100 AA,BB

Blocks and checksum locations:
  boot         0xC00000..0xC01FFD  -> 0xC01FFE
  calibration  0xC05000..0xC0AFFD  -> 0xC0AFFE
  application  0xC0B000..0xC3FFFB  -> 0xC3FFFE
The adaptation log at 0xC04000..0xC04CFF has no checksum.
"""
import struct
import sys

BLOCKS = [
    ("boot", 0xC00000, 0xC01FFE, 0xC01FFE),
    ("calibration", 0xC05000, 0xC0AFFE, 0xC0AFFE),
    ("application", 0xC0B000, 0xC3FFFC, 0xC3FFFE),
]

def csum(data, start, end):
    total = 0
    for i in range(start, end, 2):
        total += (data[i] << 8) | data[i + 1]
    return total & 0xFFFF

def main():
    if len(sys.argv) < 5:
        print(__doc__)
        return 2
    in_path, out_path, addr_text = sys.argv[1], sys.argv[2], sys.argv[3]
    payload_text = ",".join(sys.argv[4:])
    addr = int(addr_text, 0)
    payload = bytes(int(x, 0) for x in payload_text.split(",") if x.strip())

    data = bytearray(open(in_path, "rb").read())
    if len(data) != 0x40000:
        print(f"expected 256 KB image, got {len(data)}", file=sys.stderr)
        return 2
    if addr < 0xC00000 or addr + len(payload) > 0xC40000:
        print("address outside the 256 KB flash image", file=sys.stderr)
        return 2

    off = addr - 0xC00000
    data[off:off + len(payload)] = payload
    print(f"patched {len(payload)} byte(s) at 0x{addr:06X}")

    patched_blocks = []
    for name, start, end, stored_at in BLOCKS:
        if start <= addr < end or start <= addr + len(payload) <= end:
            value = csum(data, start - 0xC00000, end - 0xC00000)
            struct.pack_into("<H", data, stored_at - 0xC00000, value)
            patched_blocks.append((name, value))

    for name, value in patched_blocks:
        print(f"recomputed {name} checksum = 0x{value:04X}")
    if not patched_blocks:
        print("patch is outside a checksummed block; no checksum changed")

    open(out_path, "wb").write(data)
    print(f"wrote {out_path}")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
