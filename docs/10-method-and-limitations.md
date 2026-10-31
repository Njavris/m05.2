# 10. Method, evidence and limitations

## 10.1 Toolchain

| Tool | Version / source | Use |
|---|---|---|
| Ghidra | 12.1.4 PUBLIC | C166 disassembly/decompilation |
| C166 processor module | `keyhana/c166-ghidra-module` v1.2.2 | C166/C167 language and decompiler support |
| Python 3 | system | checksum verification, table parsing, diff analysis |
| XC164CS documentation | Infineon datasheet / XC164 user manual | memory map, vector table, SFR names |

The image was imported as:

```bash
analyzeHeadless <project> <name> \
  -import dumps/mash_dump.bin \
  -processor 'C166:LE:16:default' \
  -loader BinaryLoader \
  -loader-baseAddr 0xC00000
```

The C166 module was used from a scratch copy of Ghidra so the user's main
installation was not modified.

## 10.2 Sleigh fix for `JMPA` / `CALLA`

Some Delphi-compiler branches are encoded as:

```
EA 31 D6 02     ; JMPA cc_NZ, 0x02D6
```

The C166 module's Sleigh constructor required the reserved nibble (bits 8–11)
to be zero, so it rejected these instructions. The real CPU ignores that nibble
and executes the branch. The constructor was relaxed:

```
:jmpa cc1215, absCaddr is ExtCountDec & op=0xEA & cc1215; absCaddr
:calla cc1215, absCaddr is ExtCountDec & op=0xCA & cc1215; absCaddr
```

and the `.sla` was rebuilt with the Ghidra Sleigh compiler. After that the
application scheduler and the integrity checks decompile coherently. This is a
tooling fix; it does not alter the target bytes.

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

* **No external RAM in the dump.** The task table at 0x705E and the calibration
  axis descriptors at 0x750A–0x7564 are not available. This prevents full
  reconstruction of the scheduler tasks and the engine map axes.
* **Limited runtime trace.** live-data logs from other MT05/MT05.2 bikes provide the
  live-data field map and validate status bits, but there is no capture from
  this specific ECU or a RAM snapshot. The producer of most non-status fields and the
  per-cell adaptation mapping remain inferred.
* **Partial function coverage.** Ghidra recovered 195 functions; some are
  reachable only through tables in external RAM or hand-written indirect jumps.
  The 0xC10000 far-call table still contains unanalyzed targets.
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

Open `artifacts/decompiled/<address>_<name>.asm` for the exact instructions, or
`<address>_<name>.c` for the decompiler view. Cross-reference
`artifacts/function_map.csv`.

## 10.7 Evidence chain

The conclusions in this report are backed by:

* raw bytes in `mash_dump*.bin`;
* the generated function/table/vector CSVs in `artifacts/`;
* Ghidra C and assembly in `artifacts/decompiled/`;
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
