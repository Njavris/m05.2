#!/usr/bin/env python3
"""Assemble the reproduction listing into a 256 KB image.

Supported directives:
  .org <addr>          set output file offset
  .byte v1,v2,...      append bytes
  .word v1,v2,...      append 16-bit little-endian words
  .ascii "text"        append literal bytes (basic \\n, \\r, \\t, \\0)
  .space N             append N zero bytes
  .fill N, value       append N copies of value

The listing is data-oriented; this is not a full C166 macro assembler.
"""
import re
import sys

def parse_number(text):
    text = text.strip()
    if text == "":
        raise ValueError("empty number")
    return int(text, 0)

def append(out, data):
    out.extend(data)

def main():
    if len(sys.argv) != 3:
        print("usage: assemble_listing.py <firmware.s> <out.bin>", file=sys.stderr)
        return 2

    out = bytearray()
    pos = 0

    def ensure(offset):
        nonlocal pos
        if offset < 0:
            raise ValueError("negative .org")
        while len(out) < offset:
            out.append(0)
        pos = offset

    for lineno, raw in enumerate(open(sys.argv[1], "r", encoding="ascii"), 1):
        line = raw.split(";", 1)[0].strip()
        if not line:
            continue

        if line.startswith(".org"):
            ensure(parse_number(line[4:]))
            continue

        if line.startswith(".byte"):
            values = [parse_number(v) for v in line[5:].split(",") if v.strip()]
            for v in values:
                if not (0 <= v <= 0xFF):
                    raise ValueError(f"line {lineno}: byte out of range")
                out.append(v)
                pos += 1
            continue

        if line.startswith(".word"):
            values = [parse_number(v) for v in line[5:].split(",") if v.strip()]
            for v in values:
                if not (0 <= v <= 0xFFFF):
                    raise ValueError(f"line {lineno}: word out of range")
                out.append(v & 0xFF)
                out.append((v >> 8) & 0xFF)
                pos += 2
            continue

        if line.startswith(".space"):
            count = parse_number(line[6:])
            out.extend(b"\x00" * count)
            pos += count
            continue

        if line.startswith(".fill"):
            args = [parse_number(v) for v in line[5:].split(",")]
            if len(args) != 2:
                raise ValueError(f"line {lineno}: .fill needs N,value")
            count, value = args
            out.extend(bytes([value & 0xFF]) * count)
            pos += count
            continue

        if line.startswith(".ascii"):
            m = re.match(r'\.ascii\s+"(.*)"\s*$', line)
            if not m:
                raise ValueError(f"line {lineno}: bad .ascii")
            text = m.group(1)
            text = text.replace("\\n", "\n").replace("\\r", "\r").replace("\\t", "\t")
            text = text.replace("\\0", "\0").replace('\\"', '"').replace("\\\\", "\\")
            raw_bytes = text.encode("latin-1")
            out.extend(raw_bytes)
            pos += len(raw_bytes)
            continue

        raise ValueError(f"line {lineno}: unknown directive: {line}")

    if len(out) < 0x40000:
        out.extend(b"\x00" * (0x40000 - len(out)))
    if len(out) > 0x40000:
        raise ValueError(f"image is {len(out)} bytes, expected 262144")

    open(sys.argv[2], "wb").write(out)
    print(f"wrote {sys.argv[2]}: {len(out)} bytes")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
