# MT05.2 full reconstruction project

This is the normal, buildable reconstruction project for the final C166SV2
analysis. It complements the curated 195-function semantic tree in the parent
directory and turns the whole 902-function result into a source tree with a
stable catalog.

## What is here

| Path | Purpose |
|---|---|
| `catalog/FUNCTIONS.csv` | all 902 functions: address, name, area, confidence, evidence, callers, callees, table/variable evidence, reference source |
| `catalog/FUNCTIONS.md` | human-readable area summary and high/medium names |
| `catalog/VARIABLES.csv` | 491 RAM/flash variables and HUD aliases |
| `catalog/STRUCTURES.csv` / `STRUCTURES.md` | 34 recovered firmware/catalog structures |
| `catalog/HUD_COMMANDS.csv` | HUD ECU Hacker MT05 command set |
| `catalog/HUD_PARAMETERS.csv` | 60 HUD response fields, including the 55-field `21 01` packet |
| `catalog/HUD_STATUS_BITS.csv` | 40 live-data status bits and firmware aliases |
| `catalog/HUD_SLEW.csv` | 13 HUD data-slewing entries |
| `catalog/HUD_TUNING_PATCHES.csv` | 368 cross-firmware HUD map/table shapes |
| `catalog/APP_INIT_TABLE.csv` | decoded 0xC0BB56 RAM-init copies and initial values |
| `catalog/HUD_FIRMWARE_MAP.csv` | 56 firmware/live-data alias rows from the HUD mapping |
| `catalog/HUD_LOG_SUMMARY.csv` | decoded ranges from 12 HUD logs / 15,317 samples |
| `catalog/EVIDENCE.md` | input hashes and naming policy |
| `catalog/REFACTORING.md` | refactoring rules and no-functionality-loss constraints |
| `include/mt05/` | C types, catalog API and live-data API |
| `src/` | generated catalog data and lookup implementation |
| `reference/` | 7 merged C files with shared `mt05_reconstruction.h`, plus 7 merged ASM files |
| `tests/test_catalog.c` | catalog integrity and lookup tests |
| `tools/build_catalog.py` | reproducible catalog/reference generator |
| `tools/summarize_hud_logs.py` | HUD log range extractor |

## Counts

- Functions: **902** (220 high, 340 medium, 342 low/address-derived)
- Variables: **491**
- Structures: **34**
- HUD `21 01` fields: **55** (60 total HUD response fields)
- HUD status bits: **40**
- HUD slew entries: **13**
- Cross-firmware HUD tuning table records: **368**
- Reference files: **1,804** C/ASM pairs
- HUD logs summarized: **12**, **15,317** samples

## Build

```bash
cd reconstruction
make test
# or
cmake -S . -B build && cmake --build build && ctest --test-dir build --output-on-failure
make catalog   # regenerate catalog/reference from the latest artifact and HUD files
```

The library `mt05_catalog` is portable C11. The `reference/` tree is not
compiled: its seven merged `.c` files in `reference/c_project/` are Ghidra
decompiler output, not original source. Ghidra pseudo-types are normalized to
`stdint.h` types, function identifiers and known data symbols use catalog names,
and remaining raw memory is named `mem_...`, `unk_...`, `ram_...` or `sub_c...`
instead of `DAT_`/`Ram`/`func_0x` labels. The `.asm` files are merged into the matching seven domain files
and their function headers use the same names.

The `.asm` files and `catalog/FUNCTIONS.csv` are the evidence authority.

## Naming policy

Curated names from `firmware/SEMANTIC_INDEX.csv` are authoritative. HUD ECU
Hacker names are used for diagnostic/live-data fields, not as original firmware
symbols. High confidence means a curated entry, a named 2-D table/axis call, or
a reviewed manual mapping. Medium means one strong call-graph, table, or
semantic variable signal. Low names are address-derived evidence labels.

The full method, input hashes and limitations are in `catalog/EVIDENCE.md`.
