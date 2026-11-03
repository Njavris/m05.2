#!/usr/bin/env python3
"""Generate a byte-exact reproduction listing from the 256 KB dump.

The listing is data-oriented: each .byte line carries the exact original
bytes, with the physical address and printable ASCII in comments. Long zero
runs become .space directives. tools/assemble_listing.py turns it back into
the original image.
"""
import sys

REGIONS = {
    0x00000: "boot block: vector table + boot/loader + ISRs",
    0x02000: "boot pad (erased)",
    0x04000: "adaptation / EEPROM log (runtime mutable)",
    0x04D00: "adaptation pad (erased)",
    0x05000: "calibration block: ID D000101 + tables",
    0x0B000: "application block: code, strings, maps",
    0x3FFE0: "ID footer / magic / application checksum",
}

def ascii_of(data):
    return "".join(chr(b) if 32 <= b < 127 else "." for b in data)

def emit_region(lines, offset):
    if offset in REGIONS:
        lines.append("")
        lines.append("; " + "=" * 74)
        lines.append(f"; 0x{0xC00000 + offset:06X}  {REGIONS[offset]}")
        lines.append("; " + "=" * 74)

def main():
    if len(sys.argv) != 3:
        print("usage: generate_listing.py <dump.bin> <firmware.s>", file=sys.stderr)
        return 2
    data = open(sys.argv[1], "rb").read()
    if len(data) != 0x40000:
        print(f"expected 256 KB dump, got {len(data)} bytes", file=sys.stderr)
        return 2

    lines = []
    lines.append("; Delphi MT05.2 (Infineon XC164CS-32) reproduction listing")
    lines.append("; Generated from the supplied dump. Physical address = 0xC00000 + file offset.")
    lines.append("; Assemble with: python3 tools/assemble_listing.py asm/firmware.s out.bin")
    lines.append(".org 0x000000")

    i = 0
    n = len(data)
    while i < n:
        emit_region(lines, i)

        if data[i] == 0:
            j = i
            while j < n and data[j] == 0:
                j += 1
            if j - i >= 16:
                lines.append(f"; 0x{0xC00000 + i:06X}..0x{0xC00000 + j - 1:06X}: zero fill")
                lines.append(f".space {j - i}")
                i = j
                continue

        j = min(i + 16, n)
        # Do not run into a long zero fill.
        k = i
        while k < j:
            if data[k] == 0:
                z = k
                while z < n and data[z] == 0:
                    z += 1
                if z - k >= 16:
                    j = k
                    break
            k += 1
        if j == i:
            j = i + 1

        chunk = data[i:j]
        values = ",".join(f"0x{b:02X}" for b in chunk)
        lines.append(f"; 0x{0xC00000 + i:06X}")
        lines.append(f".byte {values} ; {ascii_of(chunk)}")
        i = j

    open(sys.argv[2], "w", encoding="ascii").write("\n".join(lines) + "\n")
    print(f"wrote {sys.argv[2]}: {len(lines)} lines, {n} bytes covered")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
