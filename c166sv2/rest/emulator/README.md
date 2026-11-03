# MT05.2 / C166SV2 offline emulator

This directory contains an independent, deterministic interpreter for the
Delphi MT05.2 firmware dump (`../../../dumps/mash_dump.bin`, SHA-256
`e413f54f...37d2`).  It executes the supplied flash image from reset and emits
machine-readable traces for dynamic analysis.  It is **not** a cycle-accurate
XC164CS model and it is **not** a production virtual ECU.

The existing analysis, reconstruction, artifacts and dumps are not modified.

## Quick start

From the repository root:

```bash
# Reset -> boot checksum validation -> application -> app_scheduler
python3 -m emulator.tools.run --dump dumps/mash_dump.bin --reset

# Bounded outputs
python3 -m emulator.tools.run --dump dumps/mash_dump.bin --reset \
  --stop-after 3000000 --trace-limit 200000 --out emulator/out/boot

# Boot plus a supervised scheduler run with injected 1 ms ticks
python3 -m emulator.tools.run --dump dumps/mash_dump.bin --reset \
  --no-default-stops --stop-after 4000000 --tick-every 1000 \
  --out emulator/out/scheduler

# Or use the shell wrappers
emulator/examples/run_boot.sh
emulator/examples/run_scheduler.sh

# Unit tests (about 35 s; the boot checksum dominates)
python3 -m unittest discover -s emulator/tests -v
# or: pytest emulator/tests
```

Useful options:

| Option | Meaning |
|---|---|
| `--stop-after N` | instruction limit |
| `--trace-limit N` | maximum rows written to `trace.csv` |
| `--stop-at ADDR` | stop before executing `ADDR` (repeatable) |
| `--no-default-stops` | do not stop at `app_scheduler` (0xC11EB4) |
| `--tick-every N` | inject one deterministic timer tick every N instructions |
| `--watch ADDR` | watch a logical data address |
| `--watch-phys ADDR` | watch a physical data address |
| `--fill 0xFF` | fill pattern for RAM/external memory (default `0x00`) |
| `--external-image FILE` | initial contents of physical `0x000000..0x007FFF` |
| `--adc CH=VALUE` | override a 10-bit virtual ADC channel value (repeatable) |
| `--set-physical ADDR=VALUE` | preload a physical RAM word before run |
| `--set-logical ADDR=VALUE` | preload a DPP-translated logical RAM word before run |
| `--inject-physical STEP:ADDR=VALUE` | write a physical RAM word before a given instruction step |
| `--inject-logical STEP:ADDR=VALUE` | write a DPP-translated logical RAM word before a given step |
| `--compare-static` | compare dynamic PCs with `c166sv2/rest/artifacts/ghidra-full/functions.csv` |

## Virtual inputs

This is a deterministic stimulus model, not a sensor simulator:

* ADC channels default to 512 counts and can be changed with `--adc`.
* `--tick-every N` injects periodic timer ticks.
* `--set-logical`/`--set-physical` preload RAM before execution.  The
  application's startup zero-fill can overwrite these, so timed injection is
  usually more useful.
* `--inject-logical STEP:ADDR=VALUE` (or `--inject-physical`) writes a word at
  a chosen instruction step.  For example,
  `--inject-logical 2500000:0xC9D0=0x8CA0` sets the quarter-rpm
  `engine_speed_input` to the raw value corresponding to 9,000 rpm after the
  boot/application initialization has completed.
* ASC0/SSC/CAN/port register state is writable and the stub objects expose
  RX/TX queues, but there is no CLI waveform/traffic injection yet.

It does **not** synthesise crank/cam edges, MAP/TPS waveforms, closed-loop
lambda, or K-line/CAN traffic over time.

## What is emulated

The CPU core follows the Infineon *C166 Family Instruction Set Manual* V2.0
(2001-03), including the encodings used by this image:

* 16-bit GPRs R0-R15, byte aliases RL0..RH7, context pointer CP (SFR `0xFE10`).
* DPP0-DPP3, `EXTP`/`EXTS` page/segment overrides and `EXTR` extended-SFR
  sequences.
* Hardware system stack pointer SP (`0xFE12`), `PUSH`/`POP`, `SCXT`, `CALLS`,
  `RETS`, `RETI`, `CALLA`, `CALLR`, `JMPA`, `JMPS`, `JMPI`.
* PSW flags N/C/V/Z/E in bits 0..4, condition-code tests, arithmetic,
  multiply/divide, shifts/rotates, bit operations and bit fields.
* The opcodes actually executed by the image: 0x00-0xFE families used by the
  boot block, application init, K-line/CAN initialization, scheduler and
  software-float helpers.

Memory is a 24-bit physical byte array with these modelled windows:

| Physical range | Model |
|---|---|
| `0xC00000..0xC3FFFF` | flash, loaded from the dump, writes rejected |
| `0x000000..0x007FFF` | external RAM (fill pattern or `--external-image`) |
| `0x008000..0x00FFFF` | internal RAM / SFR / ESFR |
| `0x200000..0x2007FF` | TwinCAN register stub |
| `0x200800..0x3FFFFF` | external I/O (read as zero, writes retained) |
| `0xE00000..0xE0FFFF` | XRAM segment-0xE0 window (assumption, see below) |

DPP translation is applied to every 16-bit logical data address.  Firmware
variables named `0xC9xx`/`0xFDxx` in the repository are **logical** addresses;
with `DPP3 = 3` they resolve to physical `0x00C9xx`/`0x00FDxx`.  Calibration
and the scheduler tables named `0x7xxx` are logical; with `DPP1 = 0x302` they
resolve to physical `0xC0Bxxx`, i.e. they **are present in the dump**.

### Peripheral stubs

| Peripheral | Behaviour |
|---|---|
| Watchdog | `DISWDT`/`SRVWDT`/`EINIT` counted; reset delivery is not enforced |
| ADC | channel table (default 512 counts), immediate conversion, ADCIC bit 7 |
| Timer 7 | counter/reload state; `--tick-every` requests the scheduler flag |
| ASC0/K-line | byte FIFOs and transmit sink fields; no baud/fast-init timing |
| SSC0 | register/FIFO stub, 7-byte frame state is not executed autonomously |
| TwinCAN | message-object register file and TX/RX queues; no protocol engine |
| Ports | latches, direction/pin writes recorded |
| Interrupt controller | generic vector entry (`PSW`, `CSP`, `IP` push, `RETI`) |
| PLL/clock | register writes stored; no clock tree |

The emulator reaches the application scheduler with no external devices.

## Dynamic outputs

Each run writes these files into `--out` (default `emulator/out/run`):

| File | Contents |
|---|---|
| `trace.csv` | `step,pc,opcode,mnemonic,sp,dpp0..3,flags` |
| `coverage.csv` | unique PC, execution count, opcode, executed bytes |
| `calls.csv` | caller, call type (`calls`, `calls`, `jmpa`, `jmpi`, …), target, static name if known |
| `mem_writes.csv` | step, physical address, width, value, PC |
| `external_ram.csv` | reads/writes in external, internal-RAM, XRAM windows |
| `watch.csv` | explicit `--watch`/`--watch-phys` hits |
| `stops.json` | stop reason, PC, registers, last 32 instructions |
| `summary.json` | counts, deterministic trace SHA-256, stop summary |

`trace-limit` bounds `trace.csv`; the run can continue while later rows are
truncated, and `summary.json` records the truncation.  `mem_writes.csv` and
`external_ram.csv` are bounded separately by the same limit.

## Assumptions (explicitly not silicon facts)

1. RAM and external memory default to `0x00`; this is configurable and is
   reported in the output.  The dump does not contain those regions.
2. ADC channels default to 512 counts, which makes the boot reset ADC decision
   take the normal `boot_main` path.  Override with `--adc`.
3. ESFR `0xF110` bit 15 is pre-set to satisfy `adc_calibrate()`'s
   self-calibration wait.  The real producer is the ADC state machine.
4. A timer tick sets the firmware scheduler flag at physical `0x00FD14.2`;
   no genuine Timer 7 interrupt dispatch is required for this effect.
5. Physical `0xE00000..0xE0FFFF` is mapped as RAM because the boot code uses
   `EXTS` segment `0xE0` (`mem_write_word(0x7FC, 0xE0)`).  This follows the
   firmware's addressing, not a verified XC164CS data-sheet mapping.
6. Opcode `0x85`, which the C166 manual marks undefined but the C166SV2 MAC
   unit may implement, is treated as a 4-byte MAC no-op.  It occurs once, in
   the checksum epilogue before `MOV R4,R1; RETS`.
7. `INT`/trap entry always uses CSP `0xC0` (the vector table segment) and
   pushes PSW/CSP/IP.  Interrupt priority and PEC are not modelled.

## Tests

`python3 -m unittest discover -s emulator/tests -v` passes.  The suite checks:

* `checksum16_be` executed on the boot and calibration blocks and compared with
  the stored words; the Python byte-swapped-sum implementation is checked
  against all three blocks;
* reset-to-scheduler boot, known boot-chain PCs and the application table at
  physical `0xC0B09C`;
* `--stop-after`/`--trace-limit` bounds and deterministic trace hashes;
* clean stop on an invalid PC;
* scheduler task-table dispatch with a forced K-line state.

`tests/common.py` caches one boot run so the 2.2M-step checksum is not repeated
inside a single test process.

## Ghidra C166SV2 extension

`emulator/ghidra/` contains an installable Ghidra extension adding the
`C166SV2:LE:16:xc164cs` language.  It fixes the upstream `EXTR #n` window,
decodes the observed `0x85` C166SV2 MAC opcode, adds XC164 SFR/ESFR names and
supports the MT05.2 memory/function workflow.  See
[`ghidra/c166sv2/README.md`](ghidra/c166sv2/README.md) for build, install and
headless commands.

## Limitations / unresolved

* No real peripheral timing; serial, CAN, SSC, ADC and watchdog behaviour is
  functional only.
* The scheduler task table and K-line dispatch tables are read from flash at
  their real DPP-mapped physical addresses; their *semantics* and the exact
  `0x21`/`0x30` K-line handlers are still not proven.
* The external-RAM initial contents are unknown; the default zero fill is an
  assumption and directly affects engine-control results.
* The MAC/CoMUL unit, PEC, interrupt priority nesting, stack-overflow traps and
  watchdog reset delivery are not modelled.
* A dynamic hit proves execution, not meaning.  See `FINDINGS.md` for which
  conclusions have dynamic evidence and which remain static or inferred.
