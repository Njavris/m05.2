# 10. Method, evidence and limitations

## 10.1 Toolchain

| Tool | Version / source | Use |
|---|---|---|
| Ghidra | 12.1.4 PUBLIC | C166 disassembly/decompilation |
| C166 processor module | local `emulator/ghidra/c166sv2/` extension | `C166SV2:LE:16:xc164cs`, XC164CS SFRs, EXTR/0x85 fixes |
| Python 3 | system | checksum verification, table parsing, diff analysis |
| XC164CS documentation | Infineon datasheet / XC164 user manual | memory map, vector table, SFR names |

The image was imported as:

```bash
analyzeHeadless <project> <name> \
  -import dumps/mash_dump.bin \
  -processor 'C166SV2:LE:16:xc164cs' -cspec tasking \
  -loader BinaryLoader \
  -loader-baseAddr 0xC00000
```

The extension is built and installed from `emulator/ghidra/c166sv2/`. The older
XC164CS artifact used a scratch copy of the upstream module and is archived in
`c166/`.

## 10.2 C166SV2 extension fixes

The local extension differs from upstream in three places that matter for this
image:

* `EXTR #n` remains active for exactly the next *n* instructions, so ESFR
  operands decode as `0xF1D0`, `0xF0C0`, `0xF054`, etc., not as SFR aliases.
* The observed C166SV2 `0x85` words at `0xC003B0`/`0xC003B2` decode as
  `co_mac_unknown`, allowing the checksum epilogue to continue.
* The XC164CS processor spec supplies the SFR/ESFR and TwinCAN/segment-E0
  windows used by the firmware.

The extension build uses Ghidra's Sleigh compiler; it does not alter the target
bytes.

## 10.3 Verification performed

1. **Checksum verification** — the three blocks were recomputed independently in
   Python on all four dumps. All pass:
   * boot 0xEE88
   * calibration 0x8D79
   * application 0x25C2
2. **Vector table verification** — every active vector was disassembled and its
   target checked; the offsets match the XC164CS datasheet default 4-byte
   spacing.
3. **Cross-dump comparison** — all differences are confined to
   0xC04000–0xC04CFF; the flash code/tables are identical.
4. **String verification** — `D000101`, `ht007r1504`, `28097344`,
   `-Engine Control`, `-Powertrain Ctrl`, `ECM`, `PCM` were read directly from
   the image.
5. **Table verification** — the calibration table formats were checked against
   the assembly of the accessor functions (`tbl8_interp`, `tbl16_interp`,
   `tbl2d_interp`, `axis16_*`).

## 10.4 What is certain vs. inferred

| Category | Certain (observed) | Inferred | Unknown |
|---|---|---|---|
| MCU/flash | C166 code, 256 KB at 0xC00000, XC164CS memory map | exact order code | — |
| Boot | reset flow, ADC decision tree, checksum checks, app handoff | physical meaning of ADC levels | factory/test semantics |
| Checksums | algorithm, ranges, stored values, all four dumps pass | magic 0xAA00 purpose | — |
| Vectors | active vectors, targets, ISR addresses | tick period in µs | — |
| K-line | frame header, addresses, boot service IDs, seed/key | application `0x21`/`0x30` handlers | exact app handler table |
| CAN | IDs 0x7E0/0x7E4, bit-timing register, transport buffers | response IDs 0x7E8/0x7EC | full ISO-TP state machine |
| Calibration | block, ID, checksum, table formats, VE map | exact units of remaining tables | axis descriptor contents |
| Engine control | scheduler, event channels, calc call graph, VE map | exact injector/ignition channel assignment | full equations |
| Adaptation | record layout, sequence progression, live deltas, fuel-trim clues | tail-value checksum | per-cell mapping |
| Live data | live-data `21 01` 100-byte field map, status bits, `30` slew map | producer of each field | source RAM/calculation |

## 10.5 Limitations

* **External RAM is not in the dump.** Ordinary RAM `0x0000–0x7FFF` and the
  `0xE00000` segment are missing. The task table at logical 0x705E and axis
  descriptors at 0x750A–0x7564 are DPP1-mapped flash at `0xC0Bxxx` and are
  available.
* **Limited runtime trace.** live-data logs from other MT05/MT05.2 bikes provide the
  live-data field map and validate status bits, but there is no capture from
  this specific ECU or a RAM snapshot. The producer of most non-status fields and the
  per-cell adaptation mapping remain inferred.
* **Semantic coverage is partial.** The curated map reviewed 195 functions.
  A C166SV2 whole-image Ghidra pass recovered 902 functions and 46,430 instructions,
  but many of the new `FUN_*`/`gap_*` names are mechanical and some gap blocks
  may be tables that decoded as instructions. The 0xC10000 far-call table is
  disassembled; its ten non-trampoline entry points are not yet semantically
  named.
* **Decompiler artifacts.** Where the C166 module cannot model a construct the
  C output contains `undefined`, `halt_baddata`, `extraout_*`, or warnings.
  The `.asm` files are authoritative for exact instruction-level behavior.
* **No board-level evidence.** The SSC0 target, the external EEPROM/RAM
  topology, and the ADC configuration inputs are inferred from code, not from a
  schematic or a physical inspection.
* **Name semantics.** Names such as `calc_load`, `event_schedule`,
  `kwp_sid27_security` are working labels. Only the addresses, instruction
  behavior, and observed constants are proven.

## 10.6 Reproduction recipes

### Recompute all checksums

```python
import struct
d = open('dumps/mash_dump.bin','rb').read()
def csum(a,b):
    return sum(((d[i]<<8)|d[i+1]) for i in range(a,b,2)) & 0xFFFF
assert csum(0x00000,0x01FFE) == struct.unpack_from('<H',d,0x01FFE)[0]
assert csum(0x05000,0x0AFFE) == struct.unpack_from('<H',d,0x0AFFE)[0]
assert csum(0x0B000,0x3FFFC) == struct.unpack_from('<H',d,0x3FFFE)[0]
```

### Disassemble the vector table

```bash
perl c166-dis.pl dumps/mash_dump.bin 0 200
```

### Inspect a function

Open `c166/deliverables/decompiled/<address>_<name>.asm` for the exact instructions, or
`<address>_<name>.c` for the decompiler view. Cross-reference
`c166/deliverables/function_map.csv`.

## 10.7 Evidence chain

The conclusions in this report are backed by:

* raw bytes in `mash_dump*.bin`;
* the generated function/table/vector CSVs in `artifacts/`;
* Ghidra C and assembly in `c166/deliverables/decompiled/`;
* checksum recomputation independent of Ghidra;
* the XC164CS datasheet for vector/SFR/memory-map names.

No conclusion in this report relies on executing the firmware. Where a
conclusion is inferred, the word **inferred** or the confidence column says so.

## 10.8 External references used

These were used to identify the MCU/flash family and to interpret the C166
vector/SFR/memory map. They are not part of the dump.

* Infineon XC164CS datasheet (Keil mirror):
  <https://www.keil.com/dd/docs/datashts/infineon/xc164cs_ds_new.pdf>
* Infineon XC164 user manual, peripheral volume (Keil mirror, partial):
  <https://www.keil.com/dd/docs/datashts/infineon/xc164_periph_um.pdf>
* Infineon XC164CS manual (archive.org OCR copy):
  <https://archive.org/details/manuallib-id-2622772>
* Ghidra C166 processor module:
  <https://github.com/keyhana/c166-ghidra-module>
* MT05 / MT05.2 MCU and flash-size references:
  <https://ecutools.eu/chip-tuning/ecuflash-tool/module/ecu-controller-from-delphi-mt05x/>
  <https://www.mastertuningfile.com/ecu/en/ecu/delphi-mt05mt052>
