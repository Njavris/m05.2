# Semantic reconstruction

This directory is a C-developer navigation tree for the recovered firmware.
It has exactly three parts: **01-bootloader**, **02-application** and
**03-data**. Functions are consolidated into one C and one ASM file per
executable part; all tables, records and maps are C arrays/structs in
`03-data/`, not CSV files.

The decompiled C/ASM files are Ghidra output, not original source and not
a compilable translation unit. The buildable host model is in
`../firmware/src/`.

## Parts

| Part | Address | Size | Functions | Files |
|---|---|---:|---:|---|
| [`01-bootloader/`](01-bootloader/README.md) | `0xC00000–0xC01FFF` | 8 KB | 16 | [C](01-bootloader/bootloader.c) · [ASM](01-bootloader/bootloader.asm) |
| [`02-application/`](02-application/README.md) | `0xC0B000–0xC3FFFF` | 212 KB | 179 | [C](02-application/application.c) · [ASM](02-application/application.asm) |
| [`03-data/`](03-data/README.md) | `0xC05000–0xC0AFFF` + log | 24 KB + 3.25 KB | 0 | [data.c](03-data/data.c) · [data.h](03-data/data.h) · headers |

`03-data` holds the calibration block/tables, adaptation-log records and
dump deltas, the live-data map, the function index, and the shared
headers. Generated C-only views of the whole-image names and the
0xC0BB56 RAM-init table are added by `build_auto_names.py`.

## Start here

1. [`01-bootloader/README.md`](01-bootloader/README.md) — 16 functions in [`bootloader.c`](01-bootloader/bootloader.c).
2. [`02-application/README.md`](02-application/README.md) — 179 functions in [`application.c`](02-application/application.c), grouped by area.
3. [`03-data/README.md`](03-data/README.md) — calibration tables, adaptation log, live-data map, function index and headers.
4. [`03-data/data.c`](03-data/data.c) — the C function index and all data arrays/structs.

## Function counts by application area

| Area | Functions | C section | ASM section |
|---|---:|---|---|
| Startup / runtime | 15 | [line 9](02-application/application.c#L9) | [line 9](02-application/application.asm#L9) |
| Drivers / CAN | 4 | [line 756](02-application/application.c#L756) | [line 510](02-application/application.asm#L510) |
| Drivers / K-line ASC0 | 23 | [line 1051](02-application/application.c#L1051) | [line 852](02-application/application.asm#L852) |
| Drivers / SSC | 13 | [line 1795](02-application/application.c#L1795) | [line 1435](02-application/application.asm#L1435) |
| Drivers / timers | 10 | [line 2277](02-application/application.c#L2277) | [line 1786](02-application/application.asm#L1786) |
| Drivers / ADC | 2 | [line 2791](02-application/application.c#L2791) | [line 2132](02-application/application.asm#L2132) |
| Drivers / IO | 8 | [line 2850](02-application/application.c#L2850) | [line 2174](02-application/application.asm#L2174) |
| Drivers / PWM | 3 | [line 3156](02-application/application.c#L3156) | [line 2406](02-application/application.asm#L2406) |
| Drivers / clock | 2 | [line 3272](02-application/application.c#L3272) | [line 2520](02-application/application.asm#L2520) |
| Diagnostics / KWP2000 | 12 | [line 3440](02-application/application.c#L3440) | [line 2614](02-application/application.asm#L2614) |
| Diagnostics / K-line transport | 9 | [line 3895](02-application/application.c#L3895) | [line 3169](02-application/application.asm#L3169) |
| Diagnostics / CAN transport | 7 | [line 4208](02-application/application.c#L4208) | [line 3461](02-application/application.asm#L3461) |
| Diagnostics / status | 1 | [line 4467](02-application/application.c#L4467) | [line 3893](02-application/application.asm#L3893) |
| Diagnostics / test commands | 2 | [line 4516](02-application/application.c#L4516) | [line 4042](02-application/application.asm#L4042) |
| Calibration / accessors | 5 | [line 4594](02-application/application.c#L4594) | [line 4095](02-application/application.asm#L4095) |
| Calibration / checksum | 1 | [line 4891](02-application/application.c#L4891) | [line 4576](02-application/application.asm#L4576) |
| Engine control / events | 18 | [line 4925](02-application/application.c#L4925) | [line 4617](02-application/application.asm#L4617) |
| Engine control / CC22-23 outputs | 10 | [line 5604](02-application/application.c#L5604) | [line 5481](02-application/application.asm#L5481) |
| Engine control / speed | 2 | [line 5992](02-application/application.c#L5992) | [line 5822](02-application/application.asm#L5822) |
| Engine control / load | 1 | [line 6107](02-application/application.c#L6107) | [line 5951](02-application/application.asm#L5951) |
| Engine control / limits | 4 | [line 6161](02-application/application.c#L6161) | [line 6058](02-application/application.asm#L6058) |
| Engine control / sensor | 1 | [line 6340](02-application/application.c#L6340) | [line 6355](02-application/application.asm#L6355) |
| Runtime library | 26 | [line 6456](02-application/application.c#L6456) | [line 6533](02-application/application.asm#L6533) |
| **application total** | **179** | | |

## Key entry points

- Boot/reset: [boot_reset](01-bootloader/bootloader.c#L443), [boot_main](01-bootloader/bootloader.c#L9), [checksum16_be](01-bootloader/bootloader.c#L131)
- Application start: [app_cstart](02-application/application.c#L324), [app_main](02-application/application.c#L51), [app_scheduler](02-application/application.c#L566)
- KWP2000: [kwp_dispatch](02-application/application.c#L3440)
- Calibration accessors: [axis16_unsigned](02-application/application.c#L4858), [tbl8_interp](02-application/application.c#L4650), [tbl2d_interp](02-application/application.c#L4710)
- Engine load/limits: [calc_load](02-application/application.c#L6107), [calc_limit1](02-application/application.c#L6199), [calc_limit2](02-application/application.c#L6243), [calc_limit3](02-application/application.c#L6304)

## Caveats

- Decompiler artifacts (`undefined2`, `halt_baddata`, `extraout_*`) remain.
- Some names are mechanical (`*_var_*`, `diag_flag_*`, `isr_save_*`); see
  `../firmware/SEMANTIC_NAMES.md` for evidence and confidence.
- The 9x9 map at `0xC0794A` is most likely a volume-efficiency map; live-data
  live-data fields and logs support that, but the axis descriptors are external RAM.
- The CC16/17 pair is most likely injection + ignition; live-data separates injector
  time, dwell and spark advance. The exact channel assignment remains open.
- The application `0x21`/`0x30` live-data handlers and the axis/task tables
  are in external RAM (`0x7164`, `0x750A..0x7564`, `0x705E`) and are not in the dump.

## Related documents

- `../docs/00-INDEX.md` — full analysis report
- `../docs/12-debug-channels.md` — live-data packet and status bits
- `../docs/13-live-data-inferences.md` — revised firmware interpretation
- `../firmware/SEMANTIC_NAMES.md` — naming evidence
- `../firmware/ALGORITHMS.md` — algorithm cross-index
