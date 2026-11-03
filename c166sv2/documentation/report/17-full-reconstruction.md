# 17. Full C166SV2 reconstruction project

## 17.1 Purpose

`c166sv2/deliverables/reconstruction/full/` turns the final 902-function C166SV2 result into a normal
C11 project with a stable catalog, typed accessors and a named reference tree.
It is additive to the curated 195-function tree in `c166/deliverables/reconstruction/`; the
curated model remains the source for reviewed behavior claims.

## 17.2 Project layout

| Path | Contents |
|---|---|
| `c166sv2/deliverables/reconstruction/full/catalog/FUNCTIONS.csv` | 902 functions with address, area, confidence, evidence, callers, callees, table/variable evidence and reference paths |
| `c166sv2/deliverables/reconstruction/full/catalog/VARIABLES.csv` | 491 named RAM/flash variables, including 12 HUD aliases |
| `c166sv2/deliverables/reconstruction/full/catalog/STRUCTURES.csv` | 34 recovered or catalog structures |
| `c166sv2/deliverables/reconstruction/full/catalog/HUD_*.csv` | HUD ECU Hacker commands, fields, bits, slew entries and 368 cross-firmware tuning table shapes |
| `c166sv2/deliverables/reconstruction/full/catalog/HUD_LOG_SUMMARY.csv` | decoded ranges from 12 HUD logs (15,317 samples) |
| `c166sv2/deliverables/reconstruction/full/include/mt05/` | C types and lookup APIs |
| `c166sv2/deliverables/reconstruction/full/src/` | generated catalog arrays and accessors |
| `c166sv2/deliverables/reconstruction/full/reference/` | 7 merged C files with `mt05_reconstruction.h`, plus 7 merged ASM files |
| `c166sv2/deliverables/reconstruction/full/tests/test_catalog.c` | catalog integrity tests |
| `c166sv2/deliverables/reconstruction/full/tools/build_catalog.py` | reproducible catalog/reference generator |
| `c166sv2/deliverables/reconstruction/full/tools/summarize_hud_logs.py` | HUD log range extractor |

## 17.3 Counts and confidence

| Metric | Value |
|---|---:|
| Functions | 902 |
| High confidence | 220 |
| Medium confidence | 340 |
| Low/address-derived | 342 |
| Variables | 491 |
| Structures | 34 |
| HUD commands | 6 |
| HUD response fields | 60 (55 in `21 01`) |
| HUD status bits | 40 |
| HUD slew entries | 13 |

`high` means curated evidence, a named 2-D map/axis call, or a reviewed manual
mapping. `medium` means one strong call-graph, table, or semantic-variable
signal. `low` names are evidence labels, not proven roles.

### Iterative refinement

The naming pass does not stop at the static table. `build_catalog.py` runs a
fixed-point call-graph refinement:

1. Start from curated, high- and medium-confidence functions.
2. If a low function has exactly one known callee, name it
   `<callee>_wrapper_<address>`.
3. If it has exactly one known caller and no other calls, name it
   `<caller>_helper_<address>`.
4. If it calls several known functions, name it `<first-callee>_dispatch_<address>`.
5. Re-run the pass until no names change.

This promoted 217 additional functions from low to medium without inventing
table semantics. The remaining 342 low names are mostly tiny helpers whose only
callees are other unresolved `FUN_*`/`gap_*` blocks.

## 17.4 HUD ECU Hacker evidence

The project uses the HUD ECU Hacker MT05 profile and English translation:

- `secret/MT05/Parameters/Delphi + Rongmao MT05.xml`
- `secret/MT05/Translation/English.xml`
- `secret/MT05/Tuning/*.xml`

The `21 01` packet yields 55 fields; five status bytes yield 40 live-data bits.
`HUD_FIRMWARE_MAP.csv` contains the 56 firmware/live-data alias rows. The Tuning
XML files yield 368 cross-firmware map/table shapes
(`HUD_TUNING_PATCHES.csv`) and the log files yield range checks
(`HUD_LOG_SUMMARY.csv`, 12 logs / 15,317 samples). HUD names are diagnostic
names, not original firmware symbols.

The `secret/MT05/FlashMemory/*.definitions` files are high-entropy/encrypted;
they were hashed and recorded but not parsed.

## 17.5 Build and verify

```bash
cd reconstruction
make test
# or
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

The catalog library is portable C11. The `reference/` tree is documentation
only: its 902 `.c` files and 902 `.asm` files are merged into seven matching
domain files in `reference/c_project/` and `reference/asm_project/`; the C is
Ghidra output, not compilable original source. Ghidra pseudo-types are
normalized to `stdint.h` types, function/data names use catalog names, and
remaining raw memory/calls are named `mem_...`, `unk_...`, `ram_...` and
`sub_c...` instead of `DAT_`/`Ram`/`func_0x` labels. Redundant pointer/integer
casts are removed where equivalent; indexed table accesses use byte-pointer
arithmetic instead of stacked address casts.

## 17.6 Limitations

- 342 low-confidence functions remain address-derived; most are small runtime
  helpers with only `FUN_*`/`gap_*` callees.
- External RAM at `0x705E`, `0x7164`, `0x7500`, `0x7564`, `0x7666` is absent.
- The encrypted HUD definitions were not decrypted.
- HUD logs are from other MT05/MT05.2 machines; ranges are validation evidence,
  not a trace of this exact ECU.
- Axis descriptors, exact limiter RPM, injector/ignition channel assignment and
  the application `0x21`/`0x30` handler remain open.
