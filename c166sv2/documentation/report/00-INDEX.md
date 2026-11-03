# Delphi MT05.2 ECU firmware — reverse engineering report

**Target:** Mash Black Seven 125, model year 2018, Euro 4
**ECU:** Delphi MT05.2 (Infineon XC164CS, C166SV2 core, 256 KB flash)
**Dumps:** four 262,144-byte reads of the same ECU, taken minutes apart

This directory contains a static reverse engineering of the ECU flash image. The
work covered the boot chain, flash integrity scheme, interrupt vector table,
K-line/CAN diagnostic stack, calibration tables, and the runtime adaptation log.
The engine-control math is partially reconstructed; see
[10-method-and-limitations.md](10-method-and-limitations.md) for the boundaries.

## Executive summary

| Finding | Confidence |
|---|---|
| The ECU is **MT05.2**, not the older MT05: 256 KB image and XC164CS-32 memory layout; MT05 uses a 128 KB XC164CM. | High |
| MCU is an **Infineon XC164CS** (C166SV2, little-endian, 16-bit, 24-bit address space). | High |
| The image is a linear flash dump based at **0xC00000**, size 256 KB. | High |
| Flash is split into three independently checksummed blocks: boot (8 KB), calibration (24 KB), application (212 KB). | High, all checksums verified |
| Checksum is a **16-bit sum of byte-swapped (big-endian) words**, not a CRC. | High, verified on all four dumps |
| Reset performs an **ADC-coded mode/variant selection** before normal boot. | High for the code path; physical meaning inferred |
| Main application entry is **0xC11AA0**; the scheduler is at **0xC11EB4**. | High |
| Diagnostics use **KWP2000 over K-line (ASC0)** and **ISO-TP-like transport over TwinCAN**, with a shared service dispatcher. | High |
| K-line ECU address is **0x11**; tester address **0xF1**; format byte **0x80**. | High |
| Security access uses a fixed seed **0x1234** and fixed key **0x8474**. | High from code |
| CAN diagnostic request IDs are **0x7E0** and **0x7E4** (two nodes). | High from arbitration values; response IDs inferred |
| Calibration block ID is **`D000101`** at 0xC05000; application ID footer contains `ht007r1504` and `28097344`. | High (ASCII observed) |
| The four dumps differ **only** in the 0xC04000–0xC04CFF adaptation log; all three flash checksums are identical. | High |
| The adaptation log is a wear-leveled record ring with `5A A5` signatures and a sequence counter. | High for layout; tail-value meaning unknown |
| live data uses KWP2000 `21 01` (100-byte packet, 90 fields) and `30`; the 9×9 map is most likely a volume-efficiency map. | High from live-data profile/logs; axes open |

## Source tree

`c166/deliverables/firmware/` contains a buildable host model of the recovered logic, the full
per-function Ghidra C/ASM reference under `c166/deliverables/firmware/reference/`, and a byte-exact
reproduction listing under `c166/deliverables/firmware/asm/`:

```bash
make -C c166/deliverables/firmware test
make -C c166/deliverables/firmware demo
make -C c166/deliverables/firmware repro
```

See `c166/deliverables/firmware/README.md`.

For the curated C navigation tree see [`../../../c166/deliverables/reconstruction/README.md`](../../../c166/deliverables/reconstruction/README.md).
For the full buildable catalog and named reference tree see
[`../../deliverables/reconstruction/full/README.md`](../../deliverables/reconstruction/full/README.md).

## Documentation index

1. [01-identity.md](01-identity.md) — hardware, ECU variant, firmware IDs, input hashes
2. [02-image-layout.md](02-image-layout.md) — memory map, flash regions, checksum algorithm
3. [03-boot.md](03-boot.md) — reset, self-test, integrity checks, bootloader, application start
4. [04-vectors-and-interrupts.md](04-vectors-and-interrupts.md) — vector table and active ISRs
5. [05-communications.md](05-communications.md) — K-line, KWP2000 services, CAN, OBD, SSC
6. [06-calibration.md](06-calibration.md) — calibration block, table formats, accessors
7. [07-engine-control.md](07-engine-control.md) — scheduler, event channels, calculation functions
8. [08-adaptive-data.md](08-adaptive-data.md) — EEPROM/adaptation log and dump-to-dump changes
9. [09-function-map.md](09-function-map.md) — recovered function inventory and key routines
10. [10-method-and-limitations.md](10-method-and-limitations.md) — toolchain, evidence, unknowns
11. [11-key-code.md](11-key-code.md) — cleaned pseudo-C for the key routines
12. [12-debug-channels.md](12-debug-channels.md) — live-data `21 01`/`30` live-data map and firmware aliases
13. [13-live-data-inferences.md](13-live-data-inferences.md) — what the live-data map changes in the firmware analysis
14. [14-ghidra-full-disassembly.md](14-ghidra-full-disassembly.md) — whole-image C166SV2 Ghidra pass, 902 functions and full byte coverage
15. [15-hidden-boot-code.md](15-hidden-boot-code.md) — hidden boot/test block at 0xC02000-0xC03DF6
16. [16-auto-naming.md](16-auto-naming.md) — evidence-based names for the post-195 functions, variables and structures
17. [17-full-reconstruction.md](17-full-reconstruction.md) — normal C11 project, full 902-function catalog, HUD evidence and reference tree

## Generated artifacts

| Artifact | Contents |
|---|---|
| `c166/deliverables/function_map.csv` | every recovered function, address, size, area, decompiled file |
| `c166sv2/deliverables/artifacts/vector_table.csv` | every vector slot, name, and active handler |
| `c166sv2/deliverables/artifacts/flash_regions.csv` | region map and checksum facts |
| `c166sv2/deliverables/artifacts/calibration_tables.csv` | calibration tables referenced by code, formats, raw data |
| `c166sv2/deliverables/artifacts/eeprom_records.csv` | adaptation-log record headers across the four dumps |
| `c166sv2/deliverables/artifacts/dump_differences.csv` | byte ranges that differ between dumps |
| `c166sv2/deliverables/artifacts/live_21_01_fields.csv` | live-data `21 01` 100-byte live-data packet fields and formulas |
| `c166sv2/deliverables/artifacts/live_firmware_map.csv` | firmware byte/bit → live-data field/status-bit aliases |
| `c166sv2/deliverables/artifacts/live_30_slew.csv` | live-data `0x30` data-slewing channels |
| `c166sv2/deliverables/artifacts/checksums.txt` | independent checksum verification and dump hashes |
| `c166/deliverables/firmware/SEMANTIC_NAMES.md` | function/variable/structure naming evidence |
| `c166/deliverables/firmware/ALGORITHMS.md` | recovered algorithm cross-index |
| `c166/deliverables/firmware/SEMANTIC_INDEX.csv` | machine-readable semantic index (195 curated functions) |
| `c166/deliverables/firmware/AUTO_NAMES.csv` | evidence-based names for 707 post-195 functions |
| `c166/deliverables/firmware/AUTO_VARIABLES.csv` | evidence-based names for 31 new variables/calibration objects |
| `c166/deliverables/firmware/APP_INIT_TABLE.csv` | decoded 0xC0BB56 init-table copies into RAM, with initial values |
| `c166/deliverables/firmware/include/firmware_types.h` | recovered C structures |
| `c166sv2/deliverables/artifacts/boot_block.bin`, `calibration_block.bin`, `application_block.bin`, `adaptation_log.bin` | extracted regions |
| `c166/deliverables/decompiled/` | Ghidra C decompilation and per-function assembly for 195 functions |
| `c166sv2/` | whole C166SV2 pass, split into documentation, deliverables and rest |
| `c166sv2/deliverables/reconstruction/full/` | Normal C11 catalog project: 902 functions, 491 variables, 34 structures, HUD evidence |
| `c166sv2/deliverables/artifacts/maps/` | calibration map heatmaps/curves (`index.html`, SVGs, `maps.json`, `decoded_tables.csv`) |
| `c166/deliverables/reconstruction/03-data/data.c` | C function index plus calibration, adaptation and live-data data |

## Reproducing the analysis

The image was imported into Ghidra 12.1.4 as a raw binary at base `0xC00000`
with language `C166SV2:LE:16:xc164cs`, using the local
`emulator/ghidra/c166sv2/` extension. The previous XC164CS baseline is archived
under `c166/`. The extension fixes the `EXTR #n`
window and decodes the observed `0x85` checksum bytes; commands and details are in
[10-method-and-limitations.md](10-method-and-limitations.md).

> This is a static analysis of a user-supplied dump. No vehicle was driven or
> modified, and no live diagnostic session was captured. Use any derived
> information at your own risk.
