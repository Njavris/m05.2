# Data

Firmware data part: calibration block and tables, adaptation log and dump deltas,
live-data map, function index, constants and recovered structures.

[Back to reconstruction index](../README.md) · [Function index](data.c)

## Files

| File | Contents |
|---|---|
| `data.c` | C arrays/structs for all data below |
| `data.h` | struct definitions and extern declarations |
| `constants.h` | flash block boundaries, checksums, calibration selectors and table bases |
| `firmware_types.h` | recovered firmware structures |
| `c166.h` | fixed-width C166 types and flash macros |

## Function index

`data.c` contains `mt05_functions[]` (195 entries) with address, name, part,
area, size, C/ASM file, line number, description and confidence. Use it instead
of a CSV index.

## Calibration data

`data.c` contains:

* `mt05_calibration_block[0x6000]` — raw `0xC05000–0xC0AFFF` block
* `mt05_cal_tables[]` — 10 table descriptors (address, kind, shape, used-by)
* per-table C arrays:
  * 8-bit tables: `mt05_cal_limit_curve_0[]` … `mt05_cal_correction_curve[]`
  * 16-bit table: `mt05_cal_limit_table16[]`
  * 9×9 map: `mt05_cal_load_map[81]`

Table formats:

* 8-bit: `{u8 count, u8 shift, u8 data[]}`
* 16-bit: `{u16 count, u16 data[]}`
* 2D: `{u8 cols, u8 rows, u8 shift, u8 data[]}`

The 9×9 map is most likely a volume-efficiency map; see `../docs/06-calibration.md`
and `../docs/13-live-data-inferences.md`.

## Adaptation log

`data.c` contains:

* `mt05_adaptation_log[0xD00]` — raw log
* `mt05_adapt_records[]` — record sequence/tail descriptors
* `mt05_diff_ranges[]` — byte ranges that differ between dumps

The log is a `0x200`-byte record ring with `5A A5` signatures; see
`../docs/08-adaptive-data.md`.

## live-data map

`data.c` contains the C form of the live-data MT05/MT05.2 profile:

* `mt05_live_fields[]` — `21 01` 100-byte packet fields/formulas/units
* `mt05_live_bits[]` — 40 status-bit names
* `mt05_live_slew[]` — `0x30` data-slewing channels
* `mt05_live_fw_map[]` — firmware byte/bit to live-data field/status aliases
* `mt05_debug_channels[]` — candidate live-data/debug variables

See `../docs/12-debug-channels.md` and `../docs/13-live-data-inferences.md`.

## No CSV files

All data previously exported as CSV in this tree is now C. The source analysis
CSVs remain in `../../artifacts/`; this reconstruction is self-contained C.


## Auto-named post-195 recovery

`auto_functions.c` / `.h` contain `mt05_auto_functions[]`, the evidence-based
names for the post-195 functions (`../../firmware/AUTO_NAMES.csv`).
`auto_symbols.c` / `.h` contain the corresponding new variables and calibration
objects (`../../firmware/AUTO_VARIABLES.csv`). `app_init_table.c` / `.h`
contain the nine type-6 copies from the application init table at `0xC0BB56`
(`../../firmware/APP_INIT_TABLE.csv`). Methodology and confidence rules are in
`../../docs/16-auto-naming.md`.
