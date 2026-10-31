# Reconstructed source tree

This directory is a human-readable, buildable reconstruction of the recovered
parts of the Delphi MT05.2 firmware. It is deliberately split into what can be
verified on a PC and what requires a real C166 toolchain.

## Quick start

```bash
cd firmware
make            # build the host model
make test       # run checks against ../dumps/mash_dump.bin
make demo       # print checksums, vectors, KWP exchange, maps and adaptation
make maps       # render calibration maps to ../artifacts/maps/index.html
make reconstruction # rebuild ../reconstruction/ semantic function tree
```

The host model builds with any C11 compiler (GCC/Clang). It is a **semantic
model** of the recovered logic, not a binary-identical ECU image.

See [ARCHITECTURE.md](ARCHITECTURE.md) for the module map and data flows,
[SEMANTIC_NAMES.md](SEMANTIC_NAMES.md) for naming evidence, and
[ALGORITHMS.md](ALGORITHMS.md) for algorithm-level descriptions.

## Layout

```
firmware/
  include/            public headers and recovered structures
  SEMANTIC_NAMES.md   semantic naming evidence and variable/structure map
  SEMANTIC_INDEX.csv  machine-readable index: functions/variables/SFRs/structures/algorithms
  ALGORITHMS.md       recovered algorithm cross-index and evidence
  src/                host-buildable C model
    mem.c             simulated 24-bit address space, dump loader
    checksum.c        checksum16_be
    boot.c            ADC mode selection + boot validation
    vectors.c         C166 vector table decoder
    kwp.c             KWP2000 dispatcher + K-line frame codec
    calibration.c     axis / table / 2D map accessors, calc_load
    adaptation.c      adaptation-log scanner
    main.c            demo and self-tests
  reference/          full Ghidra C/ASM, plus decompiled_all.c/.asm
  tools/              verification, listing, patching helpers
  asm/                byte-exact reproduction listing
  target/             notes/skeleton for a real C166 toolchain
```

## Human-readable views

The tree has three complementary views:

1. `src/` — the clean, buildable C model of the recovered logic.
2. `reference/` — the full Ghidra C/ASM decompilation, one file per function,
   plus `decompiled_all.c` / `decompiled_all.asm` with all 195 functions
   collected into single files. Semantic names and their evidence are in
   `SEMANTIC_NAMES.md`; the machine-readable index is `SEMANTIC_INDEX.csv`;
   recovered structures are in `include/firmware_types.h`; algorithm-level
   descriptions are in `ALGORITHMS.md`.
3. `asm/firmware.s` — a byte-exact reproduction listing for rebuilding the
   original image without a C166 compiler.
4. `../reconstruction/` — three-part navigation tree: `01-bootloader/`,
   `02-application/` and `03-data/`; functions are one C/ASM pair per executable
   part, and all tables/records/live-data maps are C arrays/structs in `03-data/`
   (generated).

## What is modeled

| Module | Recovered behavior |
|---|---|
| `checksum.c` | 16-bit sum of byte-swapped words, verified against all three flash blocks |
| `boot.c` | ADC decision tree from `boot_reset`; magic + checksum validation from `boot_main` |
| `vectors.c` | 128-slot, 4-byte-spaced XC164CS vector table and active handlers |
| `kwp.c` | service dispatch, fixed seed/key `0x1234`/`0x8474`, memory read/write, 0x80-byte transfer, K-line framing |
| `calibration.c` | axis scaling, 8/16-bit table interpolation, 9×9 map, `calc_load` |
| `adaptation.c` | 0x200-byte records, `5A A5` signature, sequence/tail values |

The model is intentionally small and readable. It is not a cycle-accurate
emulator and does not model the XC164 peripherals (ASC0, TwinCAN, CAPCOM, ADC)
at the register level.

## What is not modeled / not verified

* The complete engine-control equations (fuel, ignition, idle, limits).
* External RAM at `0x007000`/`0x00C000`; the original axis descriptors and
  scheduler task table live there.
* A binary-identical target build. This requires a commercial C166 compiler and
  the original linker/startup configuration; see `target/README.md`.
* Real hardware behavior. There is no live CAN/K-line capture in this analysis.

## Target build

The `target/` directory contains notes and a starter layout for TASKING or Keil
C166. The host model and the target model share the same algorithms, but the
target build needs:

* an XC164CS startup (vector table, stack, `cstart`/init table),
* a linker script placing flash at `0xC00000`, RAM at the XC164 addresses,
* the three checksums at `0xC01FFE`, `0xC0AFFE`, `0xC3FFFE`.

No C166 toolchain is installed in this environment, so the target build is not
verified.

## Byte-exact reproduction

`asm/firmware.s` is a generated reproduction listing. `make repro` assembles it
with the Python helper and compares the result byte-for-byte with
`../dumps/mash_dump.bin`. This proves the tree can rebuild the exact image
without a C166 compiler; it does not replace the readable C model. `make maps`
renders the recovered calibration tables to SVG/HTML under
`../artifacts/maps/`.

## Verification of the original image

```bash
python3 tools/verify_checksums.py ../dumps/mash_dump.bin
```

This prints the stored/computed checksums for boot, calibration and application
blocks, plus the dump SHA-256.
