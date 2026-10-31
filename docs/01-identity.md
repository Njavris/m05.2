# 1. Identity and inventory

## 1.1 Input files

| File | Size | SHA-256 |
|---|---|---|
| `dumps/mash_dump.bin` | 262,144 B | `e413f54ffa1c2c53cedaa603dd9d572e4b5485310d83ab477332efbd933a37d2` |
| `dumps/mash_dump_1.bin` | 262,144 B | `e413f54ffa1c2c53cedaa603dd9d572e4b5485310d83ab477332efbd933a37d2` |
| `dumps/mash_dump_05_0_2.bin` | 262,144 B | `b67c1d01e07ed8b063c24dcc70a5ca442f1243431846ba1e33b3f7da48356eaf` |
| `dumps/mash_dump_05_2_2.bin` | 262,144 B | `67eb490fed7dcdf20f1f8abe9a0baca5e582d74641cba649ac4e5783ac8b4295` |

`dumps/mash_dump.bin` and `dumps/mash_dump_1.bin` are byte-identical. The other two
differ only inside the adaptation log at file offsets 0x4600–0x4BFF
(see [08-adaptive-data.md](08-adaptive-data.md)).

## 1.2 Vehicle and ECU

| Item | Value | Basis |
|---|---|---|
| Vehicle | Mash Black Seven 125, Euro 4, 2018 | User-supplied |
| ECU family | Delphi MT05.2 | 256 KB flash image and XC164CS address map |
| MCU | Infineon **XC164CS** (C166SV2 / C16x family) | 24-bit `JMPS` targets, C166 instruction set, XC164 memory map |
| Likely order code | **SAK-XC164CS-32F40BB** (256 KB flash) | Public MT05.2 teardown information; image size and memory map agree |
| Core | 16-bit C166SV2, little-endian, 24-bit linear address space | Instruction decoding and datasheet |
| Program memory | 256 KB on-chip flash at 0xC00000–0xC3FFFF | The image fills this range; app code/checksums extend to 0xC3FFFF |
| RAM used by firmware | XRAM 0xE000–0xE7FF; IRAM 0xF600–0xFDFF; external memory work areas 0x00C000–0x00CFFF and 0x007000–0x007FFF (likely RAM; not in dump) | SFR/DPP analysis; see [02](02-image-layout.md) |

### Why this is MT05.2 and not MT05

Public repair/tuning data lists:

* MT05 = Infineon **SAK-XC164CM-16F40F**, **128 KB** flash.
* MT05.2 = Infineon **SAK-XC164CS-32F40BB**, **256 KB** flash.

The supplied image is 262,144 bytes and contains live code/data beyond 0x28000
(160 KB) up to the application checksum at 0xC3FFFE. That cannot fit the 128 KB
MT05 part. The address map, the 256 KB application checksum range, and the
XC164CS vector table all match MT05.2.

**Confidence:** high for the MCU family and flash size; the exact order code is
from public ECU references, not read from the dump.

## 1.3 Firmware identifiers in the image

All strings below were read directly from the dump. Their *meaning* is inferred
from their location and from Delphi calibration conventions.

| Address | Bytes | ASCII | Interpretation |
|---|---|---|---|
| 0xC05000 | `44 30 30 30 31 30 31 20` | `D000101 ` | Calibration/application ID at the start of the calibration block |
| 0xC3FFE0 | `0F 00 04 00 04 0F` | — | ID-footer header/version fields |
| 0xC3FFE6 | `68 74 30 30 37 72 31 35 30 34` | `ht007r1504` | Software/customer/calibration identifier (Delphi style) |
| 0xC3FFF4 | `32 38 30 39 37 33 34 34` | `28097344` | Likely Delphi part number |
| 0xC3FFFC | `00 00` | — | Application-valid magic; 0xAA00 would skip re-validation |
| 0xC3FFFE | `C2 25` | — | Application block checksum, 0x25C2 (little-endian) |

The literal `D000101` also appears as a human-readable calibration ID in the
calibration block. `28097344` is formatted like a Delphi/Bosch-style eight-digit
part number. Treat the exact model/year mapping of these IDs as **inferred**;
only the ASCII itself is observed.

## 1.4 Diagnostic identity observed in code

* K-line (ISO 14230 / KWP2000) ECU address: **0x11**.
* K-line tester address: **0xF1**.
* K-line format byte: **0x80**.
* CAN diagnostic request IDs: **0x7E0** and **0x7E4** (two TwinCAN nodes).
* Security access: fixed seed **0x1234**, expected key **0x8474**.
* OBD strings: `ECM` / `-Engine Control`, `PCM` / `-Powertrain Ctrl` at 0xC0B680–0xC0B6BE.

These are described in [05-communications.md](05-communications.md).

## 1.5 What this image is *not*

* It is not a raw 128 KB MT05 image padded with zeros: valid code, tables and a
  second checksum exist above 0x20000.
* It is not an encrypted or compressed container. The C166 instruction stream,
  vector table, ASCII IDs and 16-bit checksums are directly readable.
* It is not only flash. The 0xC04000–0xC04CFF area behaves like a live,
  wear-leveled adaptation/EEPROM log that is outside every flash checksum and
  changes between reads taken minutes apart.
