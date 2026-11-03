# 13. Revisiting the firmware with the live-data map

This note records what changed after the live-data map was recovered. It is a
cross-check of the earlier static analysis, not a replacement for it.

## 13.1 Corrections to earlier conclusions

| Earlier view | Revised view | Evidence |
|---|---|---|
| Live data likely used `0x23` ReadMemoryByAddress | Live data uses `0x21 01` (100-byte packet) and `0x30` (data slewing); `0x23` is a 10-byte calibration read | profile command list |
| `0x21`/`0x30` were missing from the recovered stack | They are absent from the boot dispatcher; the application K-line stack at `0x7164` is the likely handler | boot `kwp_dispatch` vs profile |
| `0xC0794A` was a generic load/fuel map | It is most likely the **volumetric-efficiency (VE) map**; `FVE1` is its live output | map max 244 ↔ log max 95.20%; FVE2 constant = map cell 221 |
| CC16/17 were “injection/ignition inferred” | The map separates **injector time** (`FPWVC1/2`), **dwell** (`SPDWELL`) and **spark advance** (`SAESTA`); log correlations support injection + ignition | 1-cylinder MT05.2 log |
| `diag_status_build` flags were mechanical | 40 flags now have exact live-data names | `c166sv2/deliverables/artifacts/live_firmware_map.csv`; running-engine log |
| Closed-loop lambda/O2 control was “if present” | It **exists**: `AFFNLAFR`, `AFTAFR`, `FCLCINT`, `FCLCMUL`, `BLM` fields are live | live-data packet |
| Idle-air/EVAP paths were unknown | Idle/IACV and purge paths are present (`IARDRPM`, `IACVDSMP`, `IAINTEGOFST`, `VAFRRAW2`) but their code is not isolated | live-data packet |

## 13.2 Quantitative checks

From 2,155 running samples in a 1-cylinder MT05.2 diagnostic log (the full
12-log summary is in `c166sv2/deliverables/reconstruction/full/catalog/HUD_LOG_SUMMARY.csv`):

| Quantity | Range / result |
|---|---|
| Engine speed | 1,555–8,495 rpm |
| MAP | 25.7–94.8 kPa |
| `FVE1` | 53.6–95.2% |
| `FVE2` | constant 86.2976% |
| Injector time 1 | 0–12.59 ms |
| Injector time 2 | 0–13.63 ms |
| Spark dwell | 0.906–1.344 ms |
| Spark advance | 10.5–36.25 °CA |
| Correlation `FPWVC1` vs MAP | **0.926** |
| Correlation `FPWVC1` vs `FVE1` | 0.763 |
| Correlation `SPDWELL` vs RPM | **-0.732** |
| Correlation `SAESTA` vs RPM | 0.772 |
| Correlation `SAESTA` vs MAP | 0.719 |
| Correlation `FVE1` vs MAP | 0.795 |

The map scaling is exact enough to identify it:

* maximum map cell = 244; `244 × 0.390625 = 95.3125%`
* logged `FVE1` maximum = 95.1996%
* warm correction at `0x80` (128) gives `calc_load` result = `map / 2`
* `FVE1` raw value = `load_calc_result × 256`
* `FVE2` constant 86.2976% corresponds to map cell 221

This strongly indicates that `calc_load` produces a VE/load quantity and that
the `0xC079B6` correction curve is a multiplier saturating at 1.0 (`0x80`) when
warm. The exact axes and idle-point correction still need the missing external
RAM descriptors.

A second running sample at 7,804.5 rpm with closed throttle (MAP 25.7 kPa) has
`0x37=0x8D`, decoding to Fuel Cut Off, DFCO Met, DFCO Enter and C/L Reset
Cyl 2. That is the expected overrun fuel-cut state and independently confirms
the status-bit mapping.

## 13.3 Reinterpreted firmware blocks

### `calc_load` / map `0xC0794A`

* The map is a 9×9 8-bit **VE map**.
* `load_calc_result` at `0xE008B2` is the VE/load result used by the fuel and
  ignition paths.
* `FVE1` is the live map output; `FVE2` is a fixed/default value on this
  1-cylinder log, not a second live cylinder measurement.

### CC16/17 event pair

* live-data distinguishes injector time (`FPWVC1/2`), dwell (`SPDWELL`) and spark
  advance (`SAESTA`/`SAGLOBAL1`).
* In the log, injector time tracks MAP and VE; dwell falls with RPM; spark
  advance rises with RPM/MAP.
* This supports one **injection** channel and one **ignition** channel in the
  CC16/17 pair. The exact channel-to-function assignment still needs a RAM
  trace or output capture.

### Candidate table reclassifications

These are not proven, but the live-data ranges make them worth testing:

* `0xC07860` (17-point, shift 1) has values `/2` from 2.0 to 36.5 °CA. live-data
  spark advance spans 10.5–36.25 °CA, so `calc_limit2`'s 0x7860 table is a
  strong **spark-advance** candidate, not necessarily a pure limit.
* `0xC07912` (17-point 16-bit) has values `/64` from 2.47 to 5.42 ms. live-data
  injector time spans 0–12.6 ms, so this is a candidate **injection-time /
  injection-limit** table used by `calc_limit1/2/3`.
* `0xC07874` (17-point, shift 1) has values `/2` from 2.5 to 48.5 °CA and may
  be a second spark-advance or limit curve.

The current function names (`calc_limit1/2/3`) are therefore provisional; they
may be ignition/injection calculations with limit flags attached. Fitting these
tables to the live-data logs (with the missing axis descriptors) is the next step.

### Fuel trim and adaptation

* live-data proves closed-loop fuel control exists: `AFFNLAFR`/`AFTAFR` (measured and
  target AFR), `FCLCINT1/2`, `FCLCMUL1/2`, `FBLMCOR1/2`, `VAFCMULT`, `FCNO`,
  `VAFCCLNUM`.
* The adaptation log at `0xC04000` is therefore likely to contain fuel-trim/BLM
  cells and runtime/ignition counters (`PRUNTIME`, `21 FF` `IGNCOUNT`), not just
  opaque learned bytes. The byte-level layout is still unknown.

### Idle and purge

* `IARDRPM` is a constant 1,700 rpm target in the 1-cylinder log; `IACVDSMP`
  is 25–27 and `IAINTEGOFST` about 11.3–11.9%.
* `VAFRRAW2` (canister purge) varies 0–100%.
* The idle-air and purge code paths are not in the recovered function set; live-data
  confirms they are real, active outputs.

### PWM outputs

In the 1-cylinder log `FPPDC` (fuel pump duty) is constant 100%, while
`VAFRRAW2` (canister purge) varies 0–100%. The recovered PWM block at
`0xE892/0xE8A2/0xE8A6` is therefore a better candidate for **purge or idle-air
PWM** than for fuel-pump control; this is low confidence because the fuel pump
may be relay-controlled and the PWM mapping is not traced.

### Actuator/test interface

`0x30` exposes `0x8C` test spark, `0x8D` test injector, `0x8E` test IACV and
`0x8F` test fuel pump, plus live trimming of dwell, spark advance, idle target,
AFR, VE, IACV position and fuel-pump duty. The recovered `test_command` bits
0/1/2 dispatch to the CC22/23 pair, the normal event scheduler and PWM, which is
the likely actuation path for these tests. The exact `0x8C–0x8F` to
`test_command` bit mapping is not proven.

### K-line

* The boot dispatcher handles memory/reflash/security; the application K-line
  stack must handle `0x21`/`0x30`.
* `21 03`/`21 04`/`21 FF` are hardware ID, software ID and ignition counter;
  `23 C0 50 00 0A` reads the ASCII calibration version (`D000101 `).
* The app handler table at external RAM `0x7164` remains the main missing code
  path for live data.

## 13.4 1-cylinder vs 2-cylinder caveat

the live-data profile's field names say “Cyl 1/Cyl 2”, but the 1-cylinder MT05.2 log has:

* `FVE2` constant at 86.2976% (map cell 221);
* `FPWVC2` varying 0–13.6 ms;
* status bit `0x38` bit 7 (“C/L Enabled Cyl 2”) set.

So the “Cyl 2” labels are the live-data profile's generic MT05/MT05.2 profile names, not proof
that this bike has two cylinders. On the 125, treat Cyl2 fields as
fixed/default or second-event values until a capture from this specific ECU
settles it.

## 13.5 Still open

* The application `0x21`/`0x30` handler and the 100-byte packet source block.
* Exact CC16/17 channel assignment (injector vs ignition).
* Axis descriptors at `0x750A–0x7564`; logs can now be used to fit them.
* Exact injector/dwell/spark equations and the 0xC07912 limit table meaning.
* Adaptation-log cell layout and whether `IGNCOUNT`/`PRUNTIME` are stored there.
* Which internal RAM cells feed MAP, TPS, coolant, IAT, battery voltage and O2.

## 13.6 Next data to collect

A `21 01`/`30` capture from the Mash 125 at idle and several steady RPMs would
close most of 13.5. The field map itself is already known; the missing part is
the producer side.
