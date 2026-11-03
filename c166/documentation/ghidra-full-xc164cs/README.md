> **Archived baseline.** This directory is the superseded XC164CS pass
> (`C166:CS:LE:16:default`, 1,355 functions / 43,001 instructions). The
> current pass is `../../../c166sv2/` using `C166SV2:LE:16:xc164cs`.
> Files are split: documentation here, named output in
> `../../../c166/deliverables/ghidra-full-xc164cs/`, raw listing in
> `../../../c166/rest/ghidra-full-xc164cs/`.

# Full Ghidra disassembly

This directory is the raw, whole-image Ghidra disassembly pass, separate from the
curated 195-function reference in `firmware/reference/`.

## Input and toolchain

- Input: `dumps/mash_dump.bin` (262,144 bytes, SHA-256
  `e413f54ffa1c2c53cedaa603dd9d572e4b5485310d83ab477332efbd933a37d2`)
- Ghidra: 12.1.4_PUBLIC
- Language: `C166:CS:LE:16:default` (the language file also registers
  `C166:LE:16:default`)
- Loader: raw binary at base `0xC00000`
- Extension: `keyhana/c166-ghidra-module`, rebuilt after removing the
  `rwm = 0` restriction from the `JMPA`/`CALLA` constructors.

## How the pass was seeded

1. The 195 addresses in `firmware/SEMANTIC_INDEX.csv` were created and named.
2. The 128-slot `0xC10000` far-call trampoline table was disassembled. Its
   non-trampoline targets created ten additional named entry points and exposed
   a large call graph that Ghidra had not followed from the 195 seeds.
3. Direct code references were followed to a fixed point.
4. Unresolved code blocks were found by probing gaps between known instructions,
   disassembling at each `RETS`/gap boundary, and accepting only blocks that
   ended in `RETS`, `JMPA`, or `JMPS`.
5. Steps 3-4 were repeated for seven gap generations, then 22 remaining code-shaped candidates were recovered.
6. Ghidra's Aggressive Instruction Finder was run over the remaining undefined
   bytes. It recovered another ~2,000 instructions, including the hidden
   `0xC02000-0xC03DF6` block.
7. The hidden block entry was corrected from `0xC02020` to `0xC02000`; its
   helpers were named `boot_hidden_*`.

## Result

| Metric | Value |
|---|---:|
| Functions created by Ghidra | 1,355 |
| Instructions | 43,001 |
| Code bytes | 123,430 |
| Data bytes (gaps in `flash.lst`) | 138,714 |
| Total bytes covered | 262,144 |
| Remaining instruction gaps | 36 |

The whole 256 KB image is accounted for in `flash.lst`: every byte is either a
disassembled instruction or a `.byte` data line. `disassembly.txt` contains only
the code instructions. `coverage.csv` lists the remaining gaps; these are
candidate data tables, padding, or table-like stubs.

## Naming and confidence

- `boot_*`, `can_*`, `kwp_*`, `asc0_*`, `calc_*`, etc. come from the curated
  semantic index and retain their original evidence.
- `farcall_NN` names are 0xC10000 trampoline targets.
- `gap_*` names are code blocks recovered from gaps; they are addresses, not
  semantic names.
- `FUN_*` names are Ghidra/analysis-created functions that were reached through
  calls but not yet named in the semantic index.

This is an exhaustive *disassembly* pass, not a claim that all 1,355 functions
have been semantically named. Several gap blocks may be switch-table stubs,
small helpers, or data that decoded as valid C166 instructions. The pristine
195-function model in `firmware/reference/` and `reconstruction/` remains the
reviewed source for the reconstructed behavior.

## Files

| File | Contents |
|---|---|
| `flash.lst` | byte-accurate 0xC00000-0xC3FFFF listing, code plus data |
| `disassembly.txt` | all 43,001 instructions |
| `functions.csv` | raw Ghidra function list with callers, callees, xrefs |
| `functions_named.csv` | function list joined with evidence-based auto names and confidence |
| `coverage.csv` | code/data totals and 36 remaining gaps |
| `summary.txt` | Ghidra program identity and counts |
| `scripts/` | Ghidra headless scripts used to seed, disassemble, recover gaps, and export |

## Limitations

- External RAM at `0x705E`, `0x7164`, `0x7500`, and `0x7666` is not in the flash
  dump. Decompilation still reports unreadable RAM operands.
- C166 decompiler output is not original source and still contains
  `undefined*`, `extraout_*`, and `halt_baddata` artifacts.
- DPP-dependent data references and indirect table dispatch remain unresolved
  where the DPP context is unknown.
- The 0xC10000 table and external dispatch tables are only partially interpretable
  statically.