# MT05.2 dynamic-analysis findings

All results below come from `emulator/` executing the supplied image
`dumps/mash_dump.bin` (SHA-256 `e413f54f...37d2`).  A dynamic hit proves that
an instruction or address was executed; it does **not** by itself prove the
semantic role of the code.  Conclusions are labelled accordingly.

## 1. Commands that worked

Run from the repository root.

```bash
# Boot to the application scheduler (default stop address 0xC11EB4)
python3 -m emulator.tools.run --dump dumps/mash_dump.bin --reset \
  --out /tmp/emu_boot --trace-limit 200000

# Boot + supervised scheduler run (4,000,000 instructions, injected ticks)
python3 -m emulator.tools.run --dump dumps/mash_dump.bin --reset \
  --no-default-stops --stop-after 4000000 --trace-limit 200000 \
  --tick-every 1000 \
  --watch-phys 0x00C93C --watch-phys 0x00C962 --watch-phys 0x00CB60 \
  --out /tmp/emu_sched

# Deterministic experiments
python3 -m emulator.tools.experiments boot
python3 -m emulator.tools.experiments checksums
python3 -m emulator.tools.experiments engine-state --steps 4000000
python3 -m emulator.tools.experiments limit2
python3 -m emulator.tools.experiments scheduler-table
python3 -m emulator.tools.experiments tables

# Static/dynamic comparison (does not modify artifacts)
python3 -m emulator.tools.run --dump dumps/mash_dump.bin --reset \
  --stop-after 4000000 --no-default-stops --tick-every 1000 \
  --out /tmp/emu_compare --compare-static

# Tests
python3 -m unittest discover -s emulator/tests -v
```

## 2. Reset, boot and checksums

Observed stop: `app_scheduler` at **0xC11EB4** after **2,241,976**
instructions, with 5,560 unique executed PCs.  The boot chain reached:

```
0xC00000 JMPS -> 0xC00A78 boot_reset
0xC00A78       -> 0xC00200 boot_main
0xC00200       -> 0xC10000 app_entry
0xC10000 JMPS  -> 0xC11AA0 app_cstart
0xC11AA0       -> 0xC0FFDE app_main
0xC0FFDE       -> 0xC11EB4 app_scheduler
```

The reset ADC path took the normal `boot_main` branch (ADC channels default to
512 counts, an explicit emulator assumption).  The magic word at `0xC3FFFC`
was `0x0000`, so the checksums ran.

Executing `checksum16_be` at `0xC0037E` for each block gave:

| Block | Range passed to routine | Routine result | Stored | Match |
|---|---|---|---:|---:|
| boot | `0xC00000..0xC01FFD` | `0xEE88` | `0xEE88` | yes |
| calibration | `0xC05000..0xC0AFFD` | `0x8D79` | `0x8D79` | yes |
| application | `0xC0B000..0xC3FFFB` | `0x25C2` | `0x25C2` | yes |

The application checksum takes 1,845,227 interpreter instructions by itself;
this is why boot tests cache a single reset-to-scheduler run.

Two decoder facts matter for the checksum path:

* `EXTS Rw,#n` uses the low byte of `Rw` as the 64 KiB segment.  Without it,
  the second block would read `0x00C0xxxx` (RAM) instead of flash.
* The `C166SV2` MAC-unit opcode `0x85`, marked undefined in the C166 manual,
  occurs at `0xC003B0` immediately before `MOV R4,R1; RETS`.  It is treated as
  a 4-byte no-effect MAC instruction; otherwise the checksum routine would
  trap on its own epilogue.

## 3. Dynamic coverage and calls

The 4,000,000-instruction supervised run executed 6,042 unique PCs and
215,592 call/jump events.  Against `c166sv2/rest/artifacts/ghidra-full/functions.csv`
(1,333 rows, 1,328 non-thunk) it touched 332 function bodies, of which 328
static entry addresses were hit exactly.  The boot-only run (to
`app_scheduler`) touched 299 function bodies.

This is not a rejection of the other static functions: most engine-control
code depends on external-RAM tables, injected sensor data, or scheduler states
that an offline run with zero-filled RAM never enters.  The prompt's "1,277
functions" count differs from the current CSV; the CSV row count is used here.

Representative dynamically reached functions:

```
boot_reset 0xC00A78          boot_main 0xC00200
checksum16_be 0xC0037E       boot_cinit 0xC00904
boot_periph_init 0xC002DC    clock_init 0xC01080
app_entry 0xC10000           app_cstart 0xC11AA0
app_cinit 0xC1192C           app_main 0xC0FFDE
app_hw_init 0xC11BF4         adc_calibrate 0xC105EC
config_sensor_setup 0xC0F628 fp_load/fp_store/fp_div_* 0xC28F6C/0xC28F1E/0xC28C*
app_scheduler 0xC11EB4       app_idle_wait 0xC11CAE
kline_transport_task 0xC12982 diag_status_build 0xC1482C
```

## 4. `engine_state` at logical `0xC93C`

With `DPP3 = 3`, logical `0xC93C` is physical **`0x00C93C`**.  Watching that
physical address during the 4M-instruction run produced:

| Access | PC | Function | Value |
|---|---|---|---|
| write | `0xC11A92` | `app_cinit` | `0x00` (startup clear) |
| write | `0xC1B4B0` | `FUN_c1b478` | `0x01` |
| read | `0xC147AE` | `gap_c147ae` | 46,107 times |
| read | `0xC149D2` | `diag_status_build` | 1,759 times |

`0xC1B4B0` is the only non-init writer observed at runtime.  The containing
function `FUN_c1b478` also sets `0xC942` from input-latch bits and is reached
from `FUN_c1be78`.  The same application state machine contains static writes
of other values (`0xC1B68A` writes `5`, `0xC1B69C` writes `2`), but those paths
were not entered in this offline run.

`gap_c147ae` reads the state and returns 1 when it is zero, otherwise 0.
`diag_status_build` reads it at `0xC149D2`, compares it with 3, and ORs `0x20`
into live-data status byte `0xC60C` when equal.  That is concrete dynamic
evidence for one live-data status bit; the rest of the 100-byte packet build is
still inferred.

### Scheduler gate variables

The scheduler's normal-path gate is also observed directly:

* `0xC11CDC` reads logical `0xC962` (physical `0x00C962`), the value compared
  with `0x5800..0x6800`;
* `0xC11CEC` reads logical `0xCB60` (physical `0x00CB60`);
* `FUN_c1bb34` writes `0xC962` at `0xC1BB56` from `MDH` after a
  `MULU` by constant `0xCD9A`.

## 5. Rev/limit path (`calc_limit2` at `0xC201AE`)

`calc_limit1` (`0xC200AA`) and `calc_limit2` (`0xC201AE`) statically read
`0xC93C`; `calc_limit2` was also executed directly from the post-boot state
with controlled inputs.  The relevant flash thresholds, mapped by
`EXTP 0x301` to physical `0xC078xx`, are:

| Address | Value | Use |
|---|---:|---|
| `0xC07832` | `0x00A0` = 160 | counter threshold |
| `0xC07834` | `0x0006` = 6 | secondary count |
| `0xC0781E` | `0x1450` | `C9D0` threshold |
| `0xC0784C` | 17-entry curve, shift 1 | interpolation table |
| `0xC07860` | 17-entry curve, shift 1 | interpolation table |

Controlled calls to `0xC201AE` produced:

| `engine_state` | `C86A` counter | `C9D0` | XRAM `0xE008A2` | Notes |
|---:|---:|---:|---:|---|
| 1 | 0 | `0x1450` | 0 | non-state-3 path |
| 3 | 159 | `0x1450` | 0 | below 160 threshold |
| 3 | 160 | `0x1000` | 0 | counter passed, `C9D0` too low |
| 3 | 160 | `0x1450` | 1 | both gates pass |
| 4 | 160 | `0x1450` | 0 | non-state-3 path |

The `0xE008A2` write is at `0xC20298`.  This is evidence that state 3 plus
the 160-count condition enters the limit-active path; it is **not** proof that
the result cuts fuel or spark.

### What the raw numbers mean

`engine_speed_input` (`0xC9D0`) is the live-data `VRPM` raw value, and the
live-data profile scales it by 4 (`VRPM = raw / 4` rpm).  Therefore:

* `0xC0781E = 0x1450` (5,200 raw) is only **1,300 rpm**.  In `calc_limit2` it
  is tested as a *lower* speed gate (`0xC9D0 < 0x1450` deactivates
  `speed_limit_active`); it is not a 9,000-rpm cut.
* The fuel-cut/DFCO window in `FUN_c1d46e` is `[0x1388, 0x7080)` raw =
  **1,250..7,200 rpm**, written to `C9F0` at `0xC1D71C`.  This is a
  deceleration fuel-cut window, not proof of a hard rev limiter.
* The calibration block contains quarter-rpm axes ending at 8,000/9,000 and
  9,500 rpm (physical `0xC05118`, `0xC05144`, `0xC05168`) and a
  threshold list 4,000..11,000 rpm at `0xC05110`.  A ~9,000 rpm limit is
  therefore plausible as a calibration endpoint, but no executed path was
  found comparing `engine_speed_input` directly against 9,000 rpm and cutting
  fuel/spark.

The honest answer is that **the hard rev-limit RPM is not yet established**.
The earlier notes' ~9,000 rpm remains an estimate.  The next experiment is to
find the producer of `engine_state == 3` and the consumer of
`speed_limit_active`/`C9F0`, rather than treating `0x1450` as the redline.

## 6. Tables formerly called "external RAM"

At application runtime `DPP1 = 0x302`, so logical `0x4000..0x7FFF` maps to
physical `0xC08000..0xC0BFFF`.  Therefore the tables at logical `0x705E`,
`0x709C`, `0x7500`, `0x750A`, `0x7510`, `0x7552`, `0x755E`, `0x7564` and
`0x7666` are **present in the dump** as physical `0xC0B05E`, `0xC0B09C`,
`0xC0B500`, `0xC0B50A`, `0xC0B510`, `0xC0B552`, `0xC0B55E`, `0xC0B564` and
`0xC0B666`.  This directly contradicts the older statement that these
addresses are absent external RAM.

Selected values read from the image:

| Logical | Physical | First bytes / words |
|---|---|---|
| `0x705E` | `0xC0B05E` | `941E 941E 941E B01E` |
| `0x709C` | `0xC0B09C` | `47AE C100` -> task `0xC147AE` |
| `0x709E` | `0xC0B09E` | high word `0x00C1` |
| `0x7500` | `0xC0B500` | `0C80 2BC0 0011 0000` |
| `0x750A` | `0xC0B50A` | `0006 3700 6900 0011` |
| `0x7510` | `0xC0B510` | `0011 3000 9666 0011` |
| `0x7552` | `0xC0B552` | `0011 F200 5212 0000` |
| `0x755E` | `0xC0B55E` | `0009 0000 4000 0009` |
| `0x7564` | `0xC0B564` | `0009 0C80 7080 0016` |
| `0x7666` | `0xC0B666` | `9A62 9A3E 9A44 9A4A` |

Dynamic reads confirmed several of these:

* `0xC11EB4` reads physical `0xC0B09C` and the far-call trampoline returns to
  `0xC147AE` (observed task entry);
* with the K-line state forced to 4, the task table at physical `0xC0B05E`
  yields `0x1E94`, and `JMPI` dispatches to `0xC11E94` (observed);
* axis/table reads occur at `0xC28C56` (`0xC0B500`), `0xC28516`
  (`0xC0B50A`), `0xC284E0` (`0xC0B552`) and `0xC19A3A` (`0xC0B666`).

The boot routine writes zero to physical `0xE007FC`/`0xE007FE` through
`EXTS` segment `0xE0`; this is why the emulator maps `0xE00000..0xE0FFFF`.
Those addresses are separate from the logical `0xE008xx` XRAM values used by
`calc_limit2` under `EXTP 0x380` (physical `0xE008xx`).

## 7. K-line application dispatch

`kline_transport_task` at `0xC12982` indexes logical `0x7164`
(physical `0xC0B164`) with the K-line state, then executes `JMPI`:

```
0x2F46 0x29D6 0x29E2 0x2A16 0x2F6E 0x2F6E 0x2A78 0x2AFC
0x2D28 0x2EDE 0x2F10 0x2F6E 0x2F6E 0x2F6E 0x2F6E 0x2F40
```

As segment-C1 offsets these are `0xC12F46`, `0xC129D6`, `0xC129E2`,
`0xC12A16`, `0xC12A78`, `0xC12AFC`, `0xC12D28`, `0xC12EDE`, `0xC12F10`,
`0xC12F40`, etc.  The table is also **in the dump**, not missing external RAM.

The boot KWP dispatcher (`0xC01482`) does not implement services `0x21`/`0x30`;
the application-side service handler for those IDs was not reached because it
depends on an injected K-line request and the application state machine.  The
`0x21`/`0x30` handler identities therefore remain unresolved.  The table above
is the correct next target for a K-line request injection experiment.

## 8. RAM initialization and peripheral stubs

* Physical `0x000000..0x007FFF` (external RAM) and all ordinary RAM default to
  `0x00`; `--fill` and `--external-image` change this.
* Physical `0xE00000..0xE0FFFF` is mapped as RAM to satisfy the boot code's
  `EXTS 0xE0:0x07FC` access.
* ADC channels default to 512 counts; this selects the normal boot branch.
* ESFR `0xF110` bit 15 is pre-set so `adc_calibrate()` leaves its wait loop.
* Timer ticks set physical `0x00FD14` bit 2 (the scheduler event flag).  The
  real producer is an application interrupt, not Timer 7 itself.
* Watchdog service/disable/init are counted; watchdog timeout reset is not
  enforced.
* CAN/SSC/ASC0 registers accept writes and expose deterministic state, but no
  protocol timing or external device is simulated.

## 8a. Ghidra C166SV2 extension

A separate Ghidra extension was built under `emulator/ghidra/` with language
`C166SV2:LE:16:xc164cs`.  Headless import and decompilation of
`dumps/mash_dump.bin` succeeded.  On 8,853 addresses shared with the previous
whole-image listing, 103 rows changed operand text with identical bytes and
mnemonics; all are the intended `EXTR`/ESFR corrections.  For example
`0xC00A86` now decodes as `mov 0xf1dc,#0x0` (SYSCON1) instead of
`mov 0xffdc,#0x0`, and `0xC00CB2` now decodes as `mov 0xf054,#0xfbe0`
(T7REL) instead of `mov 0xfe54,#0xfbe0`.  The checksum epilogue at
`0xC003B0` decodes as two `co_mac_unknown` instructions instead of bad data.
Build/install/limitations are in `emulator/ghidra/c166sv2/README.md` and
`emulator/ghidra/c166sv2/FINDINGS.md`.

## 9. Evidence for / against the current hypotheses

| Hypothesis | Dynamic evidence |
|---|---|
| Boot checksums are the three byte-swapped sums and pass | **Supported**: all three routine results equal stored words; boot took the app branch. |
| `0xC10000` is the application entry trampoline | **Supported**: reset path reached `0xC10000` then `0xC11AA0`. |
| Scheduler is at `0xC11EB4` and dispatches through `0x705E`/`0x709C` | **Supported**: `0xC11EB4` reads physical `0xC0B09C`; forced state 4 dispatched through `0xC0B05E` to `0xC11E94`. |
| `0xC93C` is `engine_state` | **Supported as a state variable**: one runtime writer (`0xC1B4B0`, value 1), two readers (boolean check and status-byte 0x20). Exact state names are not proven. |
| `engine_state` gates fuel/spark cut | **Partially supported / unresolved**: `calc_limit2` uses state 3 and a 160-count gate to set an XRAM limit flag; `0x1450` is a 1,300-rpm low-speed gate, not the redline. No fuel/spark actuator path was reached. |
| The `0x7000`/`0x7500`/`0x7564` descriptors are absent external RAM | **Contradicted**: they map through DPP1 to physical `0xC0Bxxx` and are present in the dump; reads were observed. |
| Scheduler/K-line tables are absent external RAM | **Contradicted** for the same DPP reason. |
| `0x21`/`0x30` are application K-line services | **Still inferred**: boot dispatcher does not implement them; the app dispatch table is present but the service path was not exercised. |
| Live-data status byte `0xC60C` bit 5 is tied to engine state 3 | **Supported statically and by reached code**: `diag_status_build` reads `0xC93C` and ORs `0x20` on equality at `0xC149DE`. |

## 10. Remaining unknowns

1. Real peripheral timing and interrupt priority/nesting; the emulator uses
   deterministic stubs and injected scheduler ticks.
2. The complete `0x21 01` packet construction and field-to-RAM map; only the
   `engine_state == 3 -> 0xC60C.5` status path is evidenced here.
3. The `0x21`/`0x30` K-line handler implementations.
4. Fuel/spark cut actuator path and whether the `calc_limit2` XRAM flag is
   consumed by it.
5. Initial contents of external RAM and the true meaning of the scheduler
   task arguments; zero fill is an assumption.
6. C166SV2 MAC-unit semantics beyond the single no-effect epilogue occurrence.
7. Watchdog reset delivery, PEC transfers, stack-overflow traps and real
   ADC/SSC/CAN handshakes.
8. Exact semantic names for the many `FUN_*`/`gap_*` functions; dynamic
   execution alone does not establish them.
