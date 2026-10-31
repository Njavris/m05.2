# Source-tree architecture

This tree presents the firmware in three views. They are meant to be used
together.

| View | Location | Purpose |
|---|---|---|
| Clean model | `src/` | Small, readable C implementation of the recovered logic; builds and tests on a PC |
| Reference decompilation | `reference/` | Complete Ghidra C/ASM for all 195 recovered functions |
| Reproduction listing | `asm/firmware.s` | Byte-exact data listing; rebuilds the supplied 256 KB image |

## Reading path

1. Start with `src/` for the concepts and naming.
2. Open the matching `reference/<address>_<name>.c` for the exact function.
3. Use `reference/<address>_<name>.asm` when the decompiler output is ambiguous.
4. Use `tools/` to verify checksums, patch calibration data, or rebuild the
   exact image.

## Boot and integrity flow

```
dump 0xC00000
  |
  +-- vector table (vectors.c)
  |     8 active vectors -> boot/ISR handlers
  |
  +-- boot_reset 0xC00A78
  |     ADC decision tree (boot.c: boot_select_mode)
  |
  +-- boot_main 0xC00200
  |     magic 0xC3FFFC == 0xAA00 ?
  |     checksum boot 0xC00000..0xC01FFD vs 0xC01FFE
  |     checksum app  0xC0B000..0xC3FFFB vs 0xC3FFFE
  |
  +-- app entry 0xC10000 -> 0xC11AA0 -> 0xC0FFDE -> scheduler 0xC11EB4
```

`src/checksum.c` and `src/boot.c` are the readable implementation of this flow.
`src/vectors.c` decodes the table. The scheduler and engine-control tasks are
only partially modeled; the reference decompilation is the complete view.

## Diagnostic flow

```
K-line (ASC0)                          CAN (TwinCAN)
  response 80 F1 11 len payload cs     0x7E0 / 0x7E4 request IDs
  request  80 11 F1 len payload cs
        |                                     |
        +------------- KWP2000 -------------+
                       |
                 kwp_dispatch 0xC01482
                  0x10  session
                  0x23  read memory
                  0x27  security (1234/8474)
                  0x31  routine
                  0x34  request download
                  0x36  transfer data (0x80 bytes)
                  0x38  transfer-related
                  0x3D  write memory
                  0x83  Delphi-specific
```

`src/kwp.c` implements the service layer and the K-line frame codec. The CAN
transport is described in `../docs/05-communications.md` but is not modeled at
the register level.

## Calibration flow

```
axis descriptor {count,min,max}  (external RAM, not in dump)
        |
        v
axis16_unsigned 0xC2850E  -> 8.8 index
        |
        v
tbl2d_interp 0xC2826E  -> base map value
        |
        v
tbl8_interp 0xC27FCA   -> correction
        |
        v
calc_load 0xC1FD9C     -> (base * corr) >> 15
```

`src/calibration.c` implements the accessors and the `calc_load` composition.
The axis descriptors are supplied by the caller; the model uses synthetic
descriptors because the originals live in external RAM.

## Adaptation flow

```
0xC04000..0xC04CFF
  0x200-byte records (six) + one 0x100-byte record
  sequence word | payload | 5A A5 | 16-bit tail
```

`src/adaptation.c` scans the records. The tail value is not a simple CRC; it is
preserved rather than interpreted.

## Naming conventions

| Prefix | Meaning |
|---|---|
| `boot_*` | boot block / reset / integrity |
| `kwp_*` | KWP2000 service handlers |
| `axis*`, `tbl*` | calibration accessors |
| `calc_*` | calibration-based calculations |
| `event_*`, `capcom_*` | timed output scheduler |
| `can_*`, `asc0_*`, `ssc_*` | communication drivers |
| `fp_*`, `cc22_23_*`, `kline_*` | evidence-based names; see `SEMANTIC_NAMES.md` |

## Fidelity

The clean model is **semantic**, not cycle-accurate. It is useful for reading,
testing and experimenting with the recovered behavior. The reference
decompilation is the complete static view. The reproduction listing is the only
byte-exact build path.
