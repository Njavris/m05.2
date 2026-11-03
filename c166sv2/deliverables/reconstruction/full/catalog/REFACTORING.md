# c_project refactoring rules

All 902 functions in `../reference/c_project/` are passed through the same
deterministic refactoring pipeline. No control-flow or arithmetic rewrite is
performed; the original Ghidra output remains available under
`c166sv2/rest/artifacts/ghidra-full/decompiled/`.

## Applied transformations

1. **Type normalization** — Ghidra pseudo-types (`undefined`, `uint3`, `ushort`,
   `byte`, `short`) become fixed-width `<stdint.h>` types.
2. **Symbol naming** — function names and known variables use the catalog
   names; leftover raw memory becomes `mem_*`, `unk_*`, `ram_*`, and calls to
   addresses without a recovered function become `sub_c*`.
3. **Redundant casts** — duplicate casts and pointer chains are collapsed;
   indexed accesses use `(uint8_t *)&base + offset` instead of stacked
   `(uint32_t)((int16_t)&base + offset)` casts.
4. **SFR read/modify/write folding** — `tmp = SFR; SFR = tmp & mask` becomes
   `SFR &= mask`; the same for `|` and `^`.
5. **Dead local scalars** — a local assignment is removed only when its next
   use is an overwrite, its right-hand side is local/constant-only, and it
   contains no call or increment/decrement. This preserves calls and hardware
   reads.
6. **Comma conditions** — the common `(x = value, x == c)` idiom becomes
   `ASSIGN_EQ(x, value, c)`; `!=` uses `ASSIGN_NE`. Short-circuit behaviour and
   the assignment side effect are preserved.
7. **Compound assignments** — `x = x op y` becomes `x op= y` for simple
   scalar lvalues, including loop increments.
8. **Single-use temporaries** — a local is inlined only when it has exactly one
   declaration, one assignment and one adjacent use, and the right-hand side
   has no call or increment/decrement. Calls and SFR reads are never moved.
9. **Local names** — decompiler `uVar*/bVar*/sVar*/iVar*` names become typed,
   source-derived names such as `speed_sample_counter_value_1`; domain-only
   globals use `kline_value_*`, `ssc_value_*`, etc.
10. **Indirect dispatch** — table-based `(*(code *)(...))()` calls become
   `call_app_slot(...)` / `call_boot_slot(...)` through a typed function-pointer
   helper; the table address, mask and call result are preserved.
8. **Shared header** — types, dispatch helpers, pseudo-intrinsics, SFRs and
   memory-mapped symbols live in `mt05_reconstruction.h`; each merged C file
   includes only that header.
11. **Formatting** — decompiler warning comments and blank lines between a
   signature and body are removed; source/address separators are retained.

## What is intentionally not changed

- No branch, loop, switch or return restructuring.
- No constant folding, algebraic reassociation, or signedness changes.
- No removal of assignments whose RHS reads memory-mapped state or calls a
  function.
- Width-preserving casts used for 16/32-bit arithmetic are retained.
- External RAM and unresolved indirect calls remain unresolved.

## Verification

- `catalog/FUNCTIONS.csv` still has 902 unique address/name rows.
- Every function has a `reference_c` and `reference_asm` file and line.
- `mt05_catalog_test` passes.
- The original per-function C/ASM remains in the C166SV2 `rest/` artifact tree
  for byte-for-byte comparison.
