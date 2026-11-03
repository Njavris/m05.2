# Target build notes (TASKING / Keil C166)

A real XC164CS build requires a commercial C166 toolchain. None is installed in
this environment, so the target build is **not verified**. The host model in
`../src/` is the buildable, testable part; this directory records what a target
project needs.

## Toolchains

| Toolchain | Use |
|---|---|
| **TASKING VX-toolset for C166** | `cctc` compiler, `astc` assembler, `ltc` linker, `artc` archiver. Best match for the recovered startup/init-table style. |
| **Keil C166** | `C166`, `A166`, `L166`; µVision device support for the C166/XC166 family. |

Both need a license/evaluation. The host `gcc` cannot target C166.

## Memory layout

| Range | Use |
|---|---|
| `0xC00000–0xC01FFF` | boot block: vector table, reset, self-test, bootloader, ISRs |
| `0xC04000–0xC04CFF` | adaptation/EEPROM log (outside all checksums) |
| `0xC05000–0xC0AFFF` | calibration block, checksum at `0xC0AFFE` |
| `0xC0B000–0xC3FFFF` | application block, checksum at `0xC3FFFE` |
| `0x00E000–0x00E7FF` | XRAM |
| `0x00F600–0x00FDFF` | IRAM / stack / CAN buffers |
| `0x00FE00–0x00FFFF` | SFR area |
| `0x200000–0x2007FF` | TwinCAN registers |

## Vector table

The target startup must reproduce the 128-slot, 4-byte-spaced table at
`0xC00000`. Only eight slots are active:

```
0xC00000 -> 0xC00A78   RESET
0xC00010 -> 0xC00F0C   STOTRAP
0xC00018 -> 0xC00F6A   STUTRAP
0xC00028 -> 0xC00FC8   BTRAP
0xC000B8 -> 0xC00E14   SSC0_RIC
0xC000F4 -> 0xC00D34   T7IC
0xC0010C -> 0xC01048   PLLIC
0xC00150 -> 0xC00694   CAN0IC
```

## Post-build checksum repair

After linking, place the binary at `0xC00000` and run:

```bash
python3 ../tools/verify_checksums.py image.bin
python3 ../tools/patch_calibration.py image.bin image_fixed.bin 0xC0794D 11
```

The second command patches one byte and recomputes the containing block
checksum; use it as a template for a post-link checksum step. (A production
build should have a dedicated checksum tool that only updates the three words.)

## Important

* The host model is **not** a complete target firmware. It implements the
  recovered checksum, boot selection, vector decoding, KWP service layer,
  calibration accessors and adaptation scanner, not the full engine-control
  application.
* A binary-identical target rebuild needs the original compiler version,
  startup, linker script and optimization settings. Those are not recoverable
  from the dump alone.
* The byte-exact reproduction path (`../asm/` + `../tools/assemble_listing.py`)
  rebuilds the supplied image without a C166 compiler.
