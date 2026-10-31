# Mash Black Seven 125 (2018) — Delphi MT05.2 firmware analysis

Static reverse engineering of the Delphi MT05.2 ECU flash dump
(Infineon XC164CS-32, 256 KB) from a Mash Black Seven 125, Euro 4, 2018.

## Project order

The workspace is arranged as an evidence pipeline:

| Stage | Directory | Contents |
|---|---|---|
| 1. Evidence | [`dumps/`](dumps/README.md) | the four original 256 KB reads (read-only) |
| 2. Analysis | [`docs/`](docs/00-INDEX.md) | the reverse-engineering report, start at `00-INDEX.md` |
| 3. Reconstruction | [`reconstruction/`](reconstruction/README.md) | three-part C tree: bootloader, application, data |
| 4. Firmware tree | [`firmware/`](firmware/README.md) | buildable host model, full decompilation, byte-exact rebuild |
| 5. Generated artifacts | [`artifacts/`](artifacts/README.md) | function map, CSVs, decompiled files, block extracts |
| 6. Host tool | [`ecu_tool/`](ecu_tool/README.md) | cross-platform FT232RL K-line live-data/flash tool |
| 7. Diagnostic console | [`ecu_diag/`](ecu_diag/README.md) | cross-platform terminal diagnostic software |

## Start here

* [docs/00-INDEX.md](docs/00-INDEX.md) — executive summary and full report index
* [docs/01-identity.md](docs/01-identity.md) — ECU/MCU identity, firmware IDs, input hashes
* [docs/02-image-layout.md](docs/02-image-layout.md) — memory map, regions, checksums
* [docs/03-boot.md](docs/03-boot.md) — reset, integrity validation, application start
* [docs/05-communications.md](docs/05-communications.md) — K-line/KWP2000 and CAN
* [docs/06-calibration.md](docs/06-calibration.md) — calibration tables and accessors
* [reconstruction/README.md](reconstruction/README.md) — semantic decompilation by firmware part
* [firmware/README.md](firmware/README.md) — buildable source tree
* [firmware/SEMANTIC_NAMES.md](firmware/SEMANTIC_NAMES.md) — naming evidence
* [firmware/ALGORITHMS.md](firmware/ALGORITHMS.md) — algorithm cross-index
* [ecu_tool/README.md](ecu_tool/README.md) — FT232RL K-line live-data/flash tool
* [ecu_diag/README.md](ecu_diag/README.md) — terminal diagnostic software
* [docs/12-debug-channels.md](docs/12-debug-channels.md) — live-data `21 01`/`30` live-data map and firmware aliases
* [docs/13-live-data-inferences.md](docs/13-live-data-inferences.md) — what the live-data map changes in the firmware analysis

## Build and verify

```bash
cd firmware
make test      # host model checks against ../dumps/mash_dump.bin
make demo      # checksums, vectors, KWP exchange, calibration tables
make repro     # byte-exact rebuild of the original image
make maps      # render calibration maps and interactive fuel map
make reconstruction # rebuild ../reconstruction/ semantic tree
```

`make test` passes; `make repro` produces a byte-identical 256 KB image. The
host model is a semantic reimplementation, not a target ECU binary.

## For C developers

Start at [`reconstruction/README.md`](reconstruction/README.md). It has three
parts: `01-bootloader/`, `02-application/` and `03-data/`. The function index,
calibration tables, adaptation records and live-data maps are C arrays/structs
in `reconstruction/03-data/data.c` and `data.h`; there are no CSV files in the
reconstruction tree. A compile check is:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -Ireconstruction/03-data \
    -fsyntax-only reconstruction/03-data/data.c
```

## Key results

* ECU is **MT05.2** (XC164CS, 256 KB), not the 128 KB MT05.
* Three checksummed blocks: boot `0xEE88`, calibration `0x8D79`, application `0x25C2`.
* Checksum is a byte-swapped 16-bit word sum, not a CRC.
* K-line KWP2000 (ECU `0x11`, tester `0xF1`) and CAN (IDs `0x7E0`/`0x7E4`).
* Fixed security seed/key: `0x1234` / `0x8474`.
* Four dumps differ only in the `0xC04000–0xC04CFF` adaptation log.
* live data uses KWP2000 `21 01` (100-byte packet, 90 fields) and `30` data
  slewing; the field map and firmware aliases are in
  [`docs/12-debug-channels.md`](docs/12-debug-channels.md). live-data logs indicate the
  `0xC0794A` 9×9 map is a volume-efficiency map and confirm the 40 status bits.
* All 195 recovered functions and all RAM variables outside the SFR/ESFR area
  have evidence-based names; structures are in
  [`firmware/include/firmware_types.h`](firmware/include/firmware_types.h).

## Generated artifacts

* [`artifacts/function_map.csv`](artifacts/function_map.csv) — 195 functions
* [`artifacts/decompiled/`](artifacts/decompiled/) — per-function Ghidra C/ASM
* [`artifacts/vector_table.csv`](artifacts/vector_table.csv) — complete vector table
* [`artifacts/flash_regions.csv`](artifacts/flash_regions.csv) — region/checksum map
* [`artifacts/calibration_tables.csv`](artifacts/calibration_tables.csv) — calibration tables
* [`artifacts/eeprom_records.csv`](artifacts/eeprom_records.csv) — adaptation records
* [`artifacts/dump_differences.csv`](artifacts/dump_differences.csv) — dump deltas
* [`artifacts/debug_channels.csv`](artifacts/debug_channels.csv) — candidate live-data/debug channels
* [`artifacts/live_21_01_fields.csv`](artifacts/live_21_01_fields.csv) — live-data `21 01` 100-byte live-data fields
* [`artifacts/live_firmware_map.csv`](artifacts/live_firmware_map.csv) — firmware → live-data field/status-bit aliases
* [`artifacts/live_30_slew.csv`](artifacts/live_30_slew.csv) — live-data `0x30` data-slewing channels
* [`artifacts/checksums.txt`](artifacts/checksums.txt) — checksum/hash evidence
* [`artifacts/maps/`](artifacts/maps/index.html) — calibration map heatmaps/curves (SVG/HTML)

## Limits

The target rebuild requires a commercial C166 toolchain (TASKING VX for C166 or
Keil C166); none is installed here. External RAM at `0x7000`/`0xC000` is not in
the dump, so several axis descriptors and task tables remain unknown. See
[docs/10-method-and-limitations.md](docs/10-method-and-limitations.md).

## Build the host tool

```bash
cmake -S ecu_tool -B ecu_tool/build
cmake --build ecu_tool/build
./ecu_tool/build/ecu_tool selftest

cmake -S ecu_diag -B ecu_diag/build
cmake --build ecu_diag/build
./ecu_diag/build/ecu_diag --port /dev/ttyUSB0
```

## Credits

Analysis, reverse engineering, documentation and implementation were performed by
**DeepSeek v4.1 Flash 1017**.

## License and provenance

The original analysis, documentation, host model, tools and reconstruction are
released under the MIT License; see [LICENSE](LICENSE). Vendor firmware images,
calibration data, decompiler output and derived machine tables are excluded from
that license and remain the property of their owners; see [NOTICE](NOTICE).
