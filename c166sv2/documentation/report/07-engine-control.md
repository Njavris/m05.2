# 7. Engine-control architecture (partially reconstructed)

This section describes what the code structure proves and clearly separates it
from what is inferred. The engine-control equations are **not** fully recovered;
the firmware uses many indirect calls, external-RAM task tables and
calibration descriptors that are not in the flash dump.

## 7.1 Time base and scheduler

* Timer 7 (`T7`, 0xF050) is the primary time base. The timer 7 ISR at 0xC00D34
  runs the 1 ms communication tick.
* The application scheduler at 0xC11EB4 waits on a flag, services the watchdog,
  increments the tick counter at 0xC54A, and calls periodic hooks.
* The scheduler dispatches tasks through a table in **external RAM at 0x705E**
  for state values 4..15. Those task pointers are not in the dump.
* Two counters are read from a 6-byte-stride table at external RAM 0x7088 and
  used to time two callbacks. Again, the table contents are not captured.

This is a time-triggered cooperative scheduler with a small number of periodic
tasks, not a preemptive RTOS.

## 7.2 CAPCOM event channels

Two CAPCOM channels are configured for timed events:

| Item | Address/resource |
|---|---|
| Channel 16 | `CC16` 0xFE60, channel ID 0x10 |
| Channel 17 | `CC17` 0xFE62, channel ID 0x11 |
| Additional CAPCOM control | 0xFF22 (Ghidra `CCM4`) and 0xF0C4 (used during init) |
| Channel interrupt enable (observed) | 0xFE28 / 0xFE2A |
| Compare-mode/control bits (observed) | 0xFF2C bit 0 (ch 0x10), bit 1 (ch 0x11) |
| Time base snapshot | `_DAT_00C3FC = T7` |
| Channel parameter array | 0xC410–0xC421 |

`capcom16_17_init` (0xC0BD58) records the addresses of the two compare
registers and their control registers. `capcom_event_config` (0xC0BCA4) and
`capcom_event_config2` (0xC0BBC4) load a channel's parameters. The helper
`cc_irq_enable_bit` at 0xC0DB90 enables bit 0 or 1 of 0xFE2A (the per-channel
interrupt enable), and `cc_compare_mode_set` at 0xC0DBA6 sets/clears bit 0 or 1
of 0xFF2C (the per-channel compare-mode control). The two channels are therefore
**CAPCOM 16 and 17**, with channel IDs 0x10 and 0x11. The exact XC164 SFR names
are not fully confirmed by the C167-oriented Ghidra processor spec; the
addresses and bit behavior are observed.

```
0xC410 + 0x12*i   parameter 1
0xC412 + 0x12*i   parameter 2
0xC414 + 0x12*i   parameter 3
0xC416 + 0x12*i   accumulator low
0xC418 + 0x12*i   accumulator high
0xC41C + 0x12*i   state bits
0xC41D + 0x12*i   channel index
0xC41E + 0x12*i   compare value
0xC420 + 0x12*i   control word
```

Two channels (`i = 0, 1`) are supported. the live-data profile's live-data fields separate
**injector time** (`FPWVC1/2`) from **spark dwell** (`SPDWELL`) and **spark
advance** (`SAESTA`/`SAGLOBAL1`), and a 1-cylinder MT05.2 log shows injector
time tracking MAP (r≈0.93) while dwell falls with engine speed (r≈-0.73).
That supports the **injection + ignition** interpretation, but the exact
channel-to-function assignment (which CC16/17 channel is which) is still
inferred from the code.

## 7.3 Event scheduling functions

| Function | Address | Observed role | Confidence |
|---|---|---|---|
| `event_init` | 0xC0D528 | configure both channels and start | high |
| `event_start` | 0xC0D39E | program initial compare values | high |
| `event_reset` | 0xC0D516 | clear scheduler accumulators | high |
| `angle_init` | 0xC0D562 | convert a calibration constant (0x3C0 = 960) into a 0..23 angle value | medium |
| `event_schedule` | 0xC0DC8A | schedule/refresh a channel compare event | high |
| `event_cancel` | 0xC0DC62 | clear one channel | high |
| `event_force` | 0xC0DBDE | force a compare value at T7+10 | high |
| `event_idle` | 0xC0E1B6 | set a channel to a long idle delay | high |
| `event_accum` | 0xC0E236 | accumulate elapsed time into 0xC416/0xC418 | high |
| `event_schedule_duration` | 0xC0E27C | schedules an event from the 32-bit duration fields | high |

`angle_init` uses the calibration constant at 0xC05032/0xC05034 (0x03C0 = 960)
and computes `value/960 + 4`, reduced modulo 24. That looks like a crank-angle
sector calculation (24 sectors of 15° would make sense for a single-cylinder
engine), but it is not proven.

## 7.4 Calculation functions using calibration maps

The four functions below are the clearest engine-control calculations recovered:

| Function | Address | Inputs | Tables | Output |
|---|---|---|---|---|
| `calc_load` | 0xC1FD9C | 0xC9D0, 0xCA2A, 0xC97C (external RAM) | axis 0x7564/0x755E, map 0xC0794A, correction 0xC079B6 | XRAM 0xE008B2, 0xE008A8 |
| `calc_limit1` | 0xC200AA | 0xC93C state, 0xC97C, 0xC86E, 0xE008A0/AC | 0xC07912 | XRAM 0xE008A6, 0xE008A0/AC limits |
| `calc_limit2` | 0xC201AE | 0xC93C state, 0xC9D0, 0xC958, 0xC86A/6C | 0xC07860, 0xC0784C | XRAM 0xE008AA, 0xE008B0 |
| `calc_limit3` | 0xC202EE | 0xC936, 0xC06A | 0xC07552, 0xC07912, 0xC078E2, 0xC07874, 0xC078D8 | XRAM 0xE008A4/AC/A6 |

`calc_load` is the most interpretable:

```c
x = axis16_unsigned(0x7564, rpm_or_load_1);
y = axis16_unsigned(0x755E, load_or_tps_2);
base = tbl2d_interp(0xC0794A, 0xC0, x, y);
corr = tbl8_interp(0xC079B6, 0xC0, correction_index);
result = (base * corr) >> 15;
```

The result is a corrected 16-bit quantity. live-data labels the result **Volume Efficiency** (`FVE1`/`FVE2`). The logged
`FVE1` maximum is 95.20%, matching the map maximum 244 × 0.390625 = 95.31%;
with the warm correction at 0x80, `calc_load` yields `map/2` and the live-data profile's raw
`FVE1` is that result × 256. This strongly indicates a volumetric-efficiency/load
map. The exact input axes, idle-point correction and normalized unit remain
open; the max-cell match is the strongest evidence.

The `calc_limit*` functions manipulate limits and state flags:
`0xC93C` takes values 1, 3, 4 in the recovered paths, and `0xC885`/`0xC886`
are "limit active" flags. They are consistent with **idle-speed control,
over-rev/fuel-cut limits, or torque limiting**. live-data ranges also make the
`0xC07860`/`0xC07874` curves spark-advance candidates and the `0xC07912` table
an injection-time/limit candidate; the function names remain provisional.

## 7.5 Engine-state variables

| Address | Area | Observed use |
|---|---|---|
| 0x00C93C | external RAM | engine state 1/3/4 in `calc_limit1/2` |
| 0xC962 | external RAM | compared with 0x5800–0x6800 in the scheduler |
| 0xC97C | external RAM | input to `calc_load` maps |
| 0xC9D0 | external RAM | input to axis 0x7564 (`calc_load`, `calc_limit2`) |
| 0xCA2A | external RAM | input to axis 0x755E |
| 0xE008A0..0xE008B2 | XRAM | calculation results and limits |
| 0xC54A | external RAM | scheduler tick counter |
| 0xC584 | external RAM | scheduler task state |
| 0xC5E6/0xC5E8/0xC5EA | external RAM | scheduler state flags |

## 7.6 What is *not* reconstructed

* The complete fuel and ignition equations.
* The physical meaning of every calibration table.
* The task table at 0x705E and the axis descriptors at 0x750A–0x7564
  (external RAM, not in the dump).
* The exact injector/ignition output mapping to CC16/CC17.
* Closed-loop lambda/O2 control: live-data fields prove it exists (`AFFNLAFR`,
  `AFTAFR`, `FCLCINT`, `FCLCMUL`, `FBLMCOR`, `VAFCMULT`, `FCNO`), but the
  controller itself is not isolated in the recovered code.
* Idle-air actuator and EVAP/canister control: live-data fields `IARDRPM`,
  `IACVDSMP`, `IAINTEGOFST`, and `VAFRRAW2` prove these paths exist, but the
  actuator code is not isolated.

These are concrete next steps for a follow-up session with a running ECU, a RAM
snapshot, or a logic-analyzer capture of the injector/ignition outputs.
