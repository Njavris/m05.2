# Reference decompilation

This directory contains the full Ghidra decompilation and instruction listing
for the 195 recovered functions. It is the **reference** view; the clean,
buildable model is in `../src/`.

| File | Contents |
|---|---|
| `<address>_<name>.c` | Ghidra decompiler output |
| `<address>_<name>.asm` | exact instruction listing |
| `function_map.csv` | entry, name, size, area, C/ASM file |
| `decompiled_all.c` | all 195 C function bodies in one file, sorted by address |
| `decompiled_all.asm` | all 195 instruction listings in one file |

The semantic naming rationale is in `../SEMANTIC_NAMES.md`; recovered
structures are in `../include/firmware_types.h`.

Regenerate the combined files with `python3 ../tools/collect_ghidra.py`
or `make collect` from the `firmware/` directory.

Caveats:

* The `.c` files are decompiler output, not original source. They contain
  `undefined2`, `halt_baddata`, `extraout_*` and similar artifacts.
* The `.asm` files are authoritative for instruction-level behavior.
* All 195 functions now have evidence-based names; no `FUN_` names remain.
  See `../SEMANTIC_NAMES.md` for the evidence and confidence.
* Functions that read external RAM (`0x007000`, `0x00C000`) produce
  "Unable to read bytes at ram:..." warnings because that RAM is not in the
  flash dump.
* The C166 Ghidra module was patched to accept the Delphi `JMPA`/`CALLA`
  encoding with a non-zero reserved nibble. See `../../docs/10-method-and-limitations.md`.
