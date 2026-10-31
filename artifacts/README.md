# Generated reverse-engineering artifacts

This folder is generated from the four ECU dumps by the analysis documented in
`../docs/`. It is not original source code.

| Path | Contents |
|---|---|
| `function_map.csv` | 195 recovered functions: entry, name, size, area, C/ASM files |
| `decompiled/*.c` | Ghidra decompiler output for each function |
| `decompiled/*.asm` | exact Ghidra instruction listing for each function |
| `decompiled_all.c` | all 195 C function bodies collected into one file, sorted by address |
| `decompiled_all.asm` | all 195 instruction listings collected into one file |
| `vector_table.csv` | every C166 vector slot, source name, handler, status |
| `flash_regions.csv` | flash region map and checksum facts |
| `calibration_tables.csv` | calibration tables referenced by code, formats and raw data |
| `eeprom_records.csv` | adaptation-log record headers in all four dumps |
| `dump_differences.csv` | every differing byte range between the dumps |
| `debug_channels.csv` | candidate firmware live-data/debug variables |
| `live_21_01_fields.csv` | live-data `21 01` 100-byte live-data packet fields, formulas and units |
| `live_21_01_bits.csv` | live-data `21 01` status-bit names |
| `live_30_slew.csv` | live-data `0x30` data-slewing channels |
| `live_firmware_map.csv` | firmware byte/bit → live-data field/status-bit mapping |
| `maps/` | calibration map visualisations (`index.html`, SVGs, JSON/CSV) |
| `boot_block.bin` | 0xC00000–0xC01FFF extracted boot block |
| `adaptation_log.bin` | 0xC04000–0xC04CFF extracted adaptation log |
| `calibration_block.bin` | 0xC05000–0xC0AFFF extracted calibration block |
| `application_block.bin` | 0xC0B000–0xC3FFFF extracted application block |

## Caveats

* The C files are decompiler output, not original C. They contain
  `undefined2`, `halt_baddata`, `extraout_*` and similar artifacts.
* Use the `.asm` files when exact instruction behavior matters.
* The Ghidra C166 module was patched to accept the Delphi `JMPA`/`CALLA`
  encoding with a non-zero reserved nibble; see `../docs/10-method-and-limitations.md`.
* External RAM (0x007000–0x007FFF, 0x00C000–0x00CFFF) is not part of the dump.
  Functions that read it show "Unable to read bytes at ram:..." warnings.
