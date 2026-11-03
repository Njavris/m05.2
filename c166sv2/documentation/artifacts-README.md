# Generated reverse-engineering artifacts

This folder contains generated artifacts from the four ECU dumps. It is split
by the Ghidra architecture used to produce the disassembly/decompilation:

| Directory | Architecture | Use |
|---|---|---|
| `c166/` | `C166:CS:LE:16:default` | superseded XC164CS/upstream pass and curated 195-function outputs |
| `c166sv2/` | `C166SV2:LE:16:xc164cs` | current C166SV2 pass and architecture-independent data deliverables |

Within each architecture:

| Subdirectory | Contents |
|---|---|
| `documentation/` | README, summary, coverage and method notes |
| `deliverables/` | named function tables, final listings, decompiled outputs and data |
| `rest/` | raw disassembly, raw function inventories, scripts and per-function decompilation |

## Current C166SV2 artifacts

| Path | Contents |
|---|---|
| `c166sv2/documentation/ghidra-full/README.md` | method and limitations of the 902-function pass |
| `c166sv2/documentation/ghidra-full/summary.txt` | language and counts |
| `c166sv2/documentation/ghidra-full/coverage.csv` | code/data totals and gaps |
| `c166sv2/deliverables/artifacts/ghidra-full/functions_named.csv` | 902 named functions |
| `c166sv2/deliverables/artifacts/ghidra-full/flash.lst` | complete 256 KB byte listing |
| `c166sv2/rest/artifacts/ghidra-full/disassembly.txt` | instruction-only listing |
| `c166sv2/rest/artifacts/ghidra-full/functions.csv` | raw Ghidra function inventory |
| `c166sv2/rest/artifacts/ghidra-full/decompiled/` | 1,804 per-function C/ASM files |
| `c166sv2/rest/artifacts/ghidra-full/scripts/` | headless scripts |
| `c166sv2/deliverables/artifacts/` | calibration, live-data, maps, blocks and checksum artifacts |

## Archived C166 artifacts

| Path | Contents |
|---|---|
| `c166/documentation/` | old XC164CS pass README, summary, coverage |
| `c166/deliverables/artifacts/decompiled/` | curated 195-function C/ASM |
| `c166/deliverables/artifacts/decompiled_all.c/.asm` | collected curated decompilation |
| `c166/deliverables/artifacts/function_map.csv` | curated function map |
| `c166/deliverables/artifacts/ghidra-full-xc164cs/functions_named.csv` | old full-pass named functions |
| `c166/rest/artifacts/ghidra-full-xc164cs/` | old raw listing, function inventory and scripts |

## Caveats

* The C files are decompiler output, not original C. They contain
  `undefined2`, `halt_baddata`, `extraout_*` and similar artifacts.
* Use the `.asm` files when exact instruction behavior matters.
* The current pass uses the local C166SV2 extension
  (`C166SV2:LE:16:xc164cs`), which fixes the `EXTR #n` window and the observed
  `0x85` checksum bytes; the old C166/XC164CS module was patched for
  `JMPA`/`CALLA`.
* External RAM (0x007000–0x007FFF, 0x00C000–0x00CFFF) is not part of the dump.
  Functions that read it show "Unable to read bytes at ram:..." warnings.
