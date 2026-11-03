# Named reference tree

This directory contains the full C166SV2 decompilation, renamed by the
full catalog. Both C and ASM are merged into seven matching domain-level
files. Function identifiers and known data symbols have been replaced with
the catalog names; unresolved calls remain `func_0x...`. The `.c` files in
`c_project/` are Ghidra decompiler output, not original source and not
compilable C; the matching `.asm` files in `asm_project/` are the
instruction-level authority.

| Merged file | Functions |
|---|---:|
| `c_project/mt05_boot.c` + `asm_project/mt05_boot.asm` | 108 |
| `c_project/mt05_comm.c` + `asm_project/mt05_comm.asm` | 21 |
| `c_project/mt05_diagnostics.c` + `asm_project/mt05_diagnostics.asm` | 4 |
| `c_project/mt05_io_timing.c` + `asm_project/mt05_io_timing.asm` | 36 |
| `c_project/mt05_engine.c` + `asm_project/mt05_engine.asm` | 269 |
| `c_project/mt05_math.c` + `asm_project/mt05_math.asm` | 42 |
| `c_project/mt05_application.c` + `asm_project/mt05_application.asm` | 422 |

The mapping back to the artifact is in `../catalog/FUNCTIONS.csv`.
