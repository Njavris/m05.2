# 2. Image layout, memory map and integrity

## 2.1 Address space

The C166SV2 uses a 24-bit linear address space. The flash image is a byte-for-byte
copy of the on-chip flash starting at **0xC00000**, so:

```
file offset = physical_address - 0xC00000
physical_address = 0xC00000 + file offset
```

The image is little-endian at the byte/word level, like normal C166 code and data.
Instruction words are 16-bit little-endian, but the flash checksum routine sums
the same words in **big-endian byte order** (see 2.3).

## 2.2 Region map

| Physical range | File range | Size | Contents | Integrity |
|---|---:|---:|---|---|
| 0xC00000–0xC01FFF | 0x00000–0x01FFF | 8 KB | Boot block: vector table, reset, self-test, bootloader, HAL ISRs, boot C init | 16-bit sum at 0xC01FFE = **0xEE88** |
| 0xC02000–0xC03FFF | 0x02000–0x03FFF | 8 KB | Erased/unused in this image | — |
| 0xC04000–0xC04CFF | 0x04000–0x04CFF | 3.25 KB | Wear-leveled adaptation/EEPROM log; runtime mutable | Not covered by any flash checksum |
| 0xC04D00–0xC04FFF | 0x04D00–0x04FFF | 0.75 KB | Erased/unused | — |
| 0xC05000–0xC0AFFF | 0x05000–0x0AFFF | 24 KB | Calibration/parameter block; starts with ASCII `D000101 ` | 16-bit sum at 0xC0AFFE = **0x8D79** |
| 0xC0B000–0xC3FFFF | 0x0B000–0x3FFFF | 212 KB | Application block: code, OBD strings, calibration maps, ID footer | 16-bit sum of 0xC0B000–0xC3FFFB at 0xC3FFFE = **0x25C2**; magic at 0xC3FFFC is outside the sum |

Inside the application block:

| Range | Contents |
|---|---|
| 0xC0B000–0xC0B6FF | OBD-II name strings and related pointer/data tables |
| 0xC0B6FF–0xC0C000 | application helper functions |
| 0xC0C000–0xC28F93 | engine-control, diagnostics, calibration-access and math code/data |
| 0xC28F93–0xC3FFDF | erased/zero |
| 0xC3FFE0–0xC3FFFB | ID strings and footer data (inside the application checksum) |
| 0xC3FFFC–0xC3FFFF | Magic (0xC3FFFC) and application checksum (0xC3FFFE), outside the sum |

The **calibration block is *not* covered by the application checksum**, and the
adaptation log is outside all three checksums. This is a deliberate three-block
design: a small boot block, a separately changeable calibration block, and the
main application.

## 2.3 Checksum algorithm (verified)

`checksum16_be(start, end)` in the boot block (0xC0037E) and in the application
(0xC11B9A) computes:

```c
uint16_t sum = 0;
for (addr = start; addr < end; addr += 2) {
    uint8_t lo = flash[addr];       /* little-endian storage */
    uint8_t hi = flash[addr + 1];
    sum += (lo << 8) | hi;          /* big-endian interpretation of the word */
}
return sum;                         /* modulo 65536 */
```

It is a byte-swapped 16-bit sum, **not** a CRC. The values were verified on all
four dumps:

| Block | Range summed | Stored at | Stored value | Recomputed |
|---|---|---|---:|---:|
| Boot | 0xC00000–0xC01FFD | 0xC01FFE | 0xEE88 | 0xEE88 |
| Calibration | 0xC05000–0xC0AFFD | 0xC0AFFE | 0x8D79 | 0x8D79 |
| Application | 0xC0B000–0xC3FFFB | 0xC3FFFE | 0x25C2 | 0x25C2 |

All four dumps pass all three checks. The runtime adaptation log is not part of
any sum, which is why it can change while every checksum stays valid.

### Application-valid magic

`boot_main` (0xC00200) first reads the word at 0xC3FFFC. If it equals **0xAA00**,
the checksum validation is skipped. In all four dumps it is **0x0000**, so the
checks run at every boot. A reflash/programming tool may set 0xAA00 after a
successful write; this is inferred from the code, not observed in the dumps.

## 2.4 XC164CS memory map used by the firmware

The C166 code addresses more than the flash. The following map is from the
XC164CS datasheet and is confirmed by the instructions:

| Address range | Resource | Evidence in firmware |
|---|---|---|
| 0xC00000–0xC3FFFF | 256 KB on-chip flash | image base; `JMPS` targets |
| 0x200000–0x2007FF | TwinCAN registers | `can_twincan_init` writes 0x200200/0x200300/0x200500 |
| 0x200800–0x3FFFFF | external I/O area | not used in captured code |
| 0x000000–0x007FFF | external memory area | code uses 0x7088/0x7090/0x709C/0x70xx work area |
| 0x008000–0x00FFFF | data RAMs/SFRs (partly used) | firmware variables at 0x00C000–0x00CFFF |
| 0x00E000–0x00E7FF | on-chip XRAM | engine variables at 0xE008xx |
| 0x00F600–0x00FDFF | on-chip IRAM | stack and CAN buffers at 0xF740 |
| 0x00FE00–0x00FFFF | SFR area | ports, timers, ASC0, ADC, CAPCOM |

Important consequence: the dump contains **flash plus the adaptation log**, but
not the external memory/RAM at 0x007000–0x007FFF or 0x00C000–0x00CFFF. Several
calibration axis descriptors and the scheduler task table live in that external
RAM, so their contents are unknown from this image alone. This is the largest
single limitation of the analysis.

## 2.5 Visible structure of the image

* The first 0x200 bytes are a **C166 vector table** of 4-byte `JMPS` entries
  (128 slots, default VECSC=4). Only eight slots are active; the rest are
  `FA 00 00 00` (`JMPS 0:0`). See [04](04-vectors-and-interrupts.md).
* The boot block contains real code up to about 0xC01EEC, then a few small
  helpers and the checksum. The boot block is not just a bootloader: it also
  holds the timer/CAN/SSC/K-line interrupt handlers used by the application.
* The application block contains a 4-byte `JMPS` far-call table at 0xC10000,
  whose first entry jumps to 0xC11AA0 (application C startup).
* The calibration block starts with `D000101 ` and configuration bytes, then a
  set of count-prefixed 8/16-bit tables at 0xC07500–0xC07A00.
* The adaptation log at 0xC04000 is a ring of 0x200-byte records with `5A A5`
  signatures. It is described in [08](08-adaptive-data.md).
* The image ends with a small ID block and the application checksum; the unused
  space between the code and the ID block is zero-filled.

## 2.6 Region-integrity table (generated)

`artifacts/flash_regions.csv` contains the same region table in machine-readable
form. `artifacts/vector_table.csv` contains every vector slot.
