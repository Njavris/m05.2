# Full Ghidra disassembly (C166SV2)

This directory is the raw whole-image Ghidra disassembly pass produced with the
local C166SV2 extension. It supersedes the XC164CS baseline archived in
`../../../c166/`.

## Input and toolchain

- Input: `dumps/mash_dump.bin` (262,144 bytes, SHA-256
  `e413f54ffa1c2c53cedaa603dd9d572e4b5485310d83ab477332efbd933a37d2`)
- Ghidra: 12.1.4_PUBLIC
- Language: `C166SV2:LE:16:xc164cs` (processor `Infineon XC164CS`)
- Compiler spec: `tasking`
- Loader: raw binary at base `0xC00000`
- Extension: `emulator/ghidra/c166sv2/`, built and installed from
  `build/C166SV2.zip` (SHA-256
  `6ae1b257a714d9b84fc6c251a4d3022b8d891e3b99b4d3f5a097fcd2bc532c8c`)

The extension corrects the upstream `EXTR #n` window, decodes the observed
C166SV2 `0x85` bytes as `co_mac_unknown`, and adds the XC164CS SFR/ESFR spec.
The previous artifact used `C166:CS:LE:16:default` with a locally patched
upstream module.

## How the pass was seeded

1. The 195 functions in `firmware/SEMANTIC_INDEX.csv` were created and named.
2. The `0xC10000` 128-slot far-call table was decoded; ten non-trampoline
   targets became functions.
3. The hidden boot block at `0xC02000-0xC03DF6` was seeded (`boot_hidden_*`).
4. Every address from the previous code-label inventory was disassembled and
   direct code references were followed.
5. The reset vector at `0xC00000` and the populated far-jump vector targets
   were added explicitly (`AddBootVectors.java`).
6. Ghidra's Aggressive Instruction Finder and gap probing were alternated for
   31 generations. A gap block was accepted only when it contained at least
   two instructions and ended in `RETS`, `JMPA`, or `JMPS`.
7. The pass stabilized at 902 functions / 46,430 instructions. The four
   remaining undefined code targets (`0xC12690`, `0xC19A0E`, `0xC19E9A`,
   `0xC2060A`) are two-byte data-like locations and were not forced into code.

## Result

| Metric | Value |
|---|---:|
| Functions | 902 |
| Instructions | 46,430 |
| Code bytes | 133,912 |
| Data bytes | 128,232 |
| Total bytes covered | 262,144 |
| Remaining gaps | 37 |
| Decompiled functions | 901 |

The complete 256 KB image is accounted for in
`deliverables/artifacts/ghidra-full/flash.lst`: every byte is either
a disassembled instruction or a `.byte` data line. `rest/artifacts/ghidra-full/disassembly.txt` contains
only instructions in the flash range.

## Differences from the XC164CS baseline

- `EXTR #n` now applies to exactly the next *n* instructions. Example:
  `0xC002E2` is `mov 0xf1d0,#0x7f13`, not `mov 0xffd0,#0x7f13`.
- `0xC003B0` and `0xC003B2` decode as `co_mac_unknown`; the checksum epilogue
  now continues to `mov r4,r1; rets` instead of ending in undefined bytes.
- The new pass recovered 46,430 instructions versus 43,001. Function
  partitioning also changed substantially: 902 functions versus 1,355. The
  counts are not directly comparable because the old pass created many small
  gap functions; address-level comparison, not count equality, is the useful
  measure.

## Files

| File | Contents |
|---|---|
| `documentation/ghidra-full/README.md` | this method and limitations note |
| `documentation/ghidra-full/summary.txt` | toolchain and count summary |
| `documentation/ghidra-full/coverage.csv` | code/data totals and remaining gaps |
| `deliverables/artifacts/ghidra-full/flash.lst` | byte-accurate `0xC00000-0xC3FFFF` listing, code plus data |
| `deliverables/artifacts/ghidra-full/functions_named.csv` | function list joined with curated/auto names |
| `rest/artifacts/ghidra-full/disassembly.txt` | all 46,430 flash instructions |
| `rest/artifacts/ghidra-full/functions.csv` | Ghidra function list with callers, callees, xrefs |
| `rest/artifacts/ghidra-full/decompiled/` | 902 per-function Ghidra C and ASM files (1,804 files) |
| `rest/artifacts/ghidra-full/scripts/` | headless scripts used for seeding, recovery, and export |

## Limitations

- External RAM at `0x705E`, `0x7164`, `0x7500`, and `0x7666` is still absent
  from the flash dump; decompilation reports unreadable operands.
- Full C166SV2 MAC/CoMUL/CoMAC semantics are not implemented; only the observed
  `0x85` bytes are decoded as a no-op.
- The four undefined code targets above are data-like and remain explicit
  unknowns.
- C166 decompiler output is not original source and still contains
  `undefined*`, `extraout_*`, and `halt_baddata` artifacts.
- DPP-dependent data references and indirect table dispatch remain unresolved
  where the DPP context is unknown.
