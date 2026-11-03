# Mash Black Seven 125 (2018) — Delphi MT05.2 firmware analysis

Static reverse engineering of the Delphi MT05.2 ECU flash dump
(Infineon XC164CS-32, 256 KB) from a Mash Black Seven 125, Euro 4, 2018.

## Project layout

The repository is split by the Ghidra architecture used for each analysis.
Shared inputs and host tools stay at the root.

```text
c166/                         superseded C166:CS / XC164CS analysis
  documentation/              old pass method and reports
  deliverables/               curated 195-function firmware/reconstruction
  rest/                       old raw Ghidra listing and scripts

c166sv2/                      current C166SV2:LE:16:xc164cs analysis
  documentation/              current report and Ghidra notes
  deliverables/               full 902-function reconstruction and artifacts
  rest/                       raw Ghidra listing, decompilation and emulator

dumps/                        shared original flash reads
tools/                        shared host tools (ecu_tool, ecu_diag)
secret/                       private HUD/log evidence (ignored)
```

## Start here

* [`c166sv2/documentation/report/00-INDEX.md`](c166sv2/documentation/report/00-INDEX.md) — full report
* [`c166/deliverables/reconstruction/README.md`](c166/deliverables/reconstruction/README.md) — curated 195-function C tree
* [`c166sv2/deliverables/reconstruction/full/README.md`](c166sv2/deliverables/reconstruction/full/README.md) — full 902-function C11 catalog
* [`c166/deliverables/firmware/README.md`](c166/deliverables/firmware/README.md) — host model and byte-exact rebuild
* [`c166sv2/rest/emulator/README.md`](c166sv2/rest/emulator/README.md) — C166SV2 emulator and Ghidra extension
* [`tools/ecu_tool/README.md`](tools/ecu_tool/README.md) — K-line live-data/flash tool
* [`tools/ecu_diag/README.md`](tools/ecu_diag/README.md) — terminal diagnostic software
* [`c166sv2/documentation/artifacts-README.md`](c166sv2/documentation/artifacts-README.md) — artifact index

## Build and verify

```bash
# Curated C166 firmware model and byte-exact image
make -C c166/deliverables/firmware test
make -C c166/deliverables/firmware demo
make -C c166/deliverables/firmware repro
make -C c166/deliverables/firmware maps
make -C c166/deliverables/firmware reconstruction

# Both reconstructed trees
make -C c166/deliverables/reconstruction test
make -C c166sv2/deliverables/reconstruction test

# Shared host tools
cmake -S tools/ecu_tool -B tools/ecu_tool/build
cmake --build tools/ecu_tool/build
./tools/ecu_tool/build/ecu_tool selftest

cmake -S tools/ecu_diag -B tools/ecu_diag/build
cmake --build tools/ecu_diag/build
```

`make -C c166/deliverables/firmware test` passes; `repro` produces a
byte-identical 256 KB image. The host model is a semantic reimplementation, not
a target ECU binary.

## Key results

* ECU is **MT05.2** (XC164CS, 256 KB), not the 128 KB MT05.
* Three checksummed blocks: boot `0xEE88`, calibration `0x8D79`, application `0x25C2`.
* Checksum is a byte-swapped 16-bit word sum, not a CRC.
* K-line KWP2000 (ECU `0x11`, tester `0xF1`) and CAN (IDs `0x7E0`/`0x7E4`).
* Fixed security seed/key: `0x1234` / `0x8474`.
* Four dumps differ only in the `0xC04000–0xC04CFF` adaptation log.
* Live data uses KWP2000 `21 01` (100-byte packet) and `30` data slewing.
* Curated C166 model: 195 functions with evidence names and recovered structures.
* C166SV2 full pass: 902 functions, 46,430 instructions, full 256 KB coverage,
  491 variables, 34 structures and a 7-file C/ASM reference tree.

## Limits

The target rebuild requires a commercial C166 toolchain (TASKING VX for C166 or
Keil C166); none is installed here. Ordinary external RAM is absent from the
dump; the logical `0x705E`, `0x7164`, `0x7500`/`0x7564` and `0x7666` tables are
DPP1-mapped flash at `0xC0Bxxx`. See
[`c166sv2/documentation/report/10-method-and-limitations.md`](c166sv2/documentation/report/10-method-and-limitations.md).

## Credits

Analysis, reverse engineering, documentation and implementation were performed by
**DeepSeek v4.1 Flash 1017**.

## License and provenance

The original analysis, documentation, host model, tools and reconstruction are
released under the MIT License; see [LICENSE](LICENSE). Vendor firmware images,
calibration data, decompiler output and derived machine tables are excluded from
that license and remain the property of their owners; see [NOTICE](NOTICE).
