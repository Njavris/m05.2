# 14. Full Ghidra disassembly

## 14.1 Scope

The original semantic map contains 195 reviewed functions. The current
whole-image pass used the local **C166SV2** extension and created **902
functions and 46,430 instructions**, covering all 262,144 flash bytes in
`c166sv2/deliverables/artifacts/ghidra-full/flash.lst`.

This pass supersedes the XC164CS baseline (`1,355 functions / 43,001
instructions`) archived in `c166/`. The old pass used
`C166:CS:LE:16:default` with a locally patched upstream module. Its function
count is not directly comparable: many old entries were small gap blocks.

## 14.2 Method

1. Import `dumps/mash_dump.bin` as raw binary at `0xC00000`, language
   `C166SV2:LE:16:xc164cs`, compiler spec `tasking`.
2. Create the 195 known functions from `c166/deliverables/firmware/SEMANTIC_INDEX.csv`.
3. Disassemble all 128 entries of the `0xC10000` far-call table and create
   functions at non-trampoline targets.
4. Seed the hidden boot block at `0xC02000-0xC03DF6` and its helpers.
5. Disassemble the previous code-label inventory and follow direct code
   references.
6. Add the reset entry at `0xC00000` and the populated far-jump vector targets.
7. Alternate Ghidra's Aggressive Instruction Finder with gap recovery for 31
   generations. Accept a gap block only when it has at least two instructions
   and ends in `RETS`, `JMPA`, or `JMPS`.
8. Stop when AIF and the gap probe are stable. Four undefined code targets
   remain and are data-like; they are listed in the artifact README.

## 14.3 Result

| Metric | Value |
|---|---:|
| Functions | 902 |
| Instructions | 46,430 |
| Code bytes | 133,912 |
| Data bytes | 128,232 |
| Total | 262,144 |
| Remaining gaps | 37 |
| Decompiled functions | 901 |

`c166sv2/deliverables/artifacts/ghidra-full/flash.lst` is byte-accurate: code instructions and
`.byte` data lines cover every address from `0xC00000` to `0xC3FFFF`.
`c166sv2/rest/artifacts/ghidra-full/disassembly.txt` is the instruction-only listing.
`c166sv2/rest/artifacts/ghidra-full/functions.csv` includes callers, callees, and xrefs.
The buildable full catalog and named reference tree are in
[`../../deliverables/c166sv2/deliverables/reconstruction/full/README.md`](../../deliverables/c166sv2/deliverables/reconstruction/full/README.md).

## 14.4 What changed in the model

The 0xC10000 trampoline table still exposes ten new entry points, and following
their calls still shows that the application is much larger than the
195-function view. The C166SV2 pass additionally corrects the `EXTR #n`
window, so ESFR operands are now right:

- `0xC002E2`: `mov 0xf1d0,#0x7f13` (was `mov 0xffd0,#0x7f13`)
- `0xC00346`: `mov 0xf0c0,#0x5554`
- `0xC00CB2`: `mov 0xf054,#0xfbe0`
- `0xC00CCC`: `mov 0xf17a,#0x58`

The observed C166SV2 `0x85` bytes at `0xC003B0` now decode as
`co_mac_unknown`, allowing the checksum epilogue to continue to
`mov r4,r1; rets`. Full CoMUL/CoMAC semantics are not claimed.

AIF also confirms the hidden boot/test block at `0xC02000-0xC03DF6`, outside
the boot checksum. Its entry is `0xC02000` (`boot_hidden_main`): it initializes
ports/XRAM, calls helpers, then loops on the external command byte at
`0xE00000` while servicing the watchdog. It is not reached from the normal
reset vector or the `0xC10000` table, so it is either factory/test code or
entered by an external bootstrap path. See
[15-hidden-boot-code.md](15-hidden-boot-code.md).

## 14.5 Limitations

- `farcall_*` and `gap_*` are address-derived names, not semantic names.
- Some `gap_*` blocks may be switch-table stubs or data that decoded as valid
  C166 instructions. They are retained because they are reachable code-shaped
  blocks, not because their meaning is proven.
- The 902-function pass does not replace the reviewed 195-function reference
  in `c166/deliverables/firmware/reference/`; that remains the source for reconstruction and
  algorithm claims.
- The four remaining undefined code targets (`0xC12690`, `0xC19A0E`,
  `0xC19E9A`, `0xC2060A`) are data-like and remain explicit unknowns.
- External RAM at `0x705E`, `0x7164`, `0x7500`, and `0x7666` is still absent.
- DPP context and indirect table dispatch are still unresolved where the code
  depends on runtime data.

## 14.6 Reproduction

The extension is in `emulator/ghidra/c166sv2/`; build it with `build.sh` and
install it with `install.sh`. The headless scripts used for the pass are in
`c166sv2/rest/artifacts/ghidra-full/scripts/`. They expect the dump at
`/home/user/mash/dumps/mash_dump.bin` and write under `/tmp/opencode/`; adjust
those paths for another host. The resulting listing is stored as the
`c166sv2/` tree (documentation, deliverables and rest).
