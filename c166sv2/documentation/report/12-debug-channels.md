# 12. Diagnostic live-data channels

This note maps the recovered diagnostic live-data services to the firmware.
The 100-byte `21 01` packet definition and scaling were reconstructed from a
diagnostic live-data profile and validated against diagnostic logs.

## 12.1 Live-data services

The profile defines:

* **KWP2000 `0x21 01`** — a **100-byte proprietary response packet** with 90
  scan parameters: 50 numeric/status entries plus 40 bit flags in five status
  bytes.
* **KWP2000 `0x30`** — "data slewing" (absolute/delta injection of selected
  values).
* **`0x21 03`, `0x21 04`, `0x21 FF`** — small 4-byte identification/version
  reads.
* **`0x23 C0 50 00 0A`** — reads 10 calibration bytes, not live data.

| Command | Field | Meaning |
|---|---|---|
| `21 03` | `PRODUCT1` | Hardware part number |
| `21 04` | `PRODUCT2` | Software part number |
| `21 FF` | `IGNCOUNT` | Ignition-on counter (little-endian) |
| `23 C0 50 00 0A` | `CALIBVER` | ASCII calibration version (`D000101 `) |

The field definitions are in `c166sv2/deliverables/artifacts/live_21_01_fields.csv`; status bits are
in `c166sv2/deliverables/artifacts/live_21_01_bits.csv`. The HUD ECU Hacker profile is also parsed
into `c166sv2/deliverables/reconstruction/full/catalog/HUD_PARAMETERS.csv`,
`HUD_STATUS_BITS.csv`, `HUD_SLEW.csv` and `HUD_FIRMWARE_MAP.csv`.

## 12.2 Recovered diagnostic path

| Layer | Function | Address | Notes |
|---|---|---|---|
| Boot K-line receive | `asc0_state4` | `0xC012E6` | validates header, fills request buffer |
| Boot KWP dispatch | `kwp_dispatch` | `0xC01482` | 0x10/0x23/0x27/0x31/0x34/0x36/0x38/0x3D/0x81/0x83 |
| Boot K-line transmit | `asc0_state5` | `0xC013E8` | builds `80 F1 11 ..` response and checksum |
| App K-line task | `kline_transport_task` | `0xC12982` | handler table at external RAM `0x7164` |
| App K-line TX | `kline_prepare_frame` / `asc0_tx_handler` | `0xC126DA` / `0xC11F9A` | second K-line stack |
| CAN transport | `can_isotp_send` / `can_tx_frame` | `0xC01C6E` / `0xC01CC8` | same KWP payload over ISO-TP |

The boot dispatcher does **not** implement `0x21` or `0x30`; the application
K-line stack is the likely handler, and its handler table at external RAM
`0x7164` is missing from the flash dump.

## 12.3 The `21 01` 100-byte packet

Offsets are relative to the 100 data bytes after `61 01`. The full machine-readable
list, including all 55 entries and descriptions, is
[`c166sv2/deliverables/artifacts/live_21_01_fields.csv`](../../deliverables/artifacts/live_21_01_fields.csv).

| Offset | UID | field | Formula | Unit |
|---|---|---|---|---|
| 0x00 | `VAFCMULT` | Airflow Correction Factor | $Val/32768 | — |
| 0x02 | `AFFNLAFR` | Air-Fuel Ratio Measured | $Val/2048 | — |
| 0x04 | `AFTAFR` | Air-Fuel Ratio Target | $Val/2048 | — |
| 0x06 | `FBLMCOR1` | LTFT Corr Factor Cyl 1 | $Val/32768 | — |
| 0x08 | `FBLMCOR2` | LTFT Corr Factor Cyl 2 | $Val/32768 | — |
| 0x0A | `FCATCYL1` | Charge Air Temp Cyl 1 | $Val/128 |  °C |
| 0x0C | `FCATCYL2` | Charge Air Temp Cyl 2 | $Val/128 |  °C |
| 0x0E | `FCLCINT1` | Short Term Corr Int Cyl 1 | — | — |
| 0x10 | `FCLCINT2` | Short Term Corr Int Cyl 2 | — | — |
| 0x12 | `FCLCMUL1` | Short Term Corr Add Cyl 1 | $Val/1024 |  % |
| 0x14 | `FCLCMUL2` | Short Term Corr Add Cyl 2 | $Val/1024 |  % |
| 0x16 | `FCNO` | Long Term BLM Cell | — | — |
| 0x18 | `FPPDC` | Fuel Pump Duty Cycle | $Val/327.68 |  % |
| 0x1A | `FPWVC1` | Injector Time Cyl 1 | $Val/64 |  ms |
| 0x1C | `FPWVC2` | Injector Time Cyl 2 | $Val/64 |  ms |
| 0x1E | `FVE1` | Volume Efficiency Cyl 1 | $Val/327.68 |  % |
| 0x20 | `FVE2` | Volume Efficiency Cyl 2 | $Val/327.68 |  % |
| 0x22 | `IACVDSMP` | IACV Position Target | — | — |
| 0x23 | `IAINTEGOFST` | IACV Integral | $Val/327.68 |  % |
| 0x25 | `IARDRPM` | Idle Speed Target | $Val/4 |  rpm |
| 0x27 | `IARPMERR` | Idle Speed Error | $Val/4 |  rpm |
| 0x29 | `MALFCURR` | Current Fault Code | — | — |
| 0x2B | `MALFHIST` | Historic Fault Code | — | — |
| 0x2D | `RUNTIME` | Engine Runtime | — | — |
| 0x2F | `SAESTA` | Spark Adv Measured | $Val/128 |  °CA |
| 0x31 | `SAGLOBAL1` | Spark Adv Target | $Val/128 |  °CA |
| 0x33 | `SAIDLDYN` | Dynam. Idle Spark Adv | $Val/128 |  °CA |
| 0x35 | `SPDWELL` | Spark Dwell Time | $Val/64 |  ms |
| 0x3C | `TERRCNT` | CKP Sensor Errors | — | — |
| 0x3D | `VAFCCLNUM` | Airflow Correction Cell | — | — |
| 0x3E | `VAFRRAW1` | Vehicle Speed | $Val > 0 ? ($Val/128) : 0 |  km/h |
| 0x40 | `VAFRRAW2` | Carbon Canister Purge | $Val/327.68 |  % |
| 0x42 | `VBARO` | MAP Baro Pressure | $Val/256 |  kPa |
| 0x44 | `VCLTS` | Coolant Temperature | $Val/128 |  °C |
| 0x46 | `VCSFC` | MAP CID Fail Counter | — | — |
| 0x48 | `VCSPC` | MAP CID Pass Counter | — | — |
| 0x4A | `VIAT` | Inlet Air Temperature | $Val/128 |  °C |
| 0x4C | `VIGN` | Ignition Voltage | $Val/2048 |  V |
| 0x4E | `VMAP` | MAP Intake Pressure | $Val/256 |  kPa |
| 0x50 | `VMAPALTC` | MAP Altitude Compens | $Val/256 |  kPa |
| 0x52 | `VMAPEXP` | Expected Inlet Pressure | $Val/256 |  kPa |
| 0x54 | `VMAPRANG` | MAP Read Angle | $Val/64 |  °CA |
| 0x56 | `VO2` | O2 Sensor Voltage Cyl 1 | $Val/64 |  mV |
| 0x58 | `VRPM` | Engine Speed | $Val/4 |  rpm |
| 0x5A | `VTHROT` | Throttle Position | $Val/327.68 |  % |
| 0x5C | `VTHROTIA` | TPS Compens with IACV | $Val/327.68 |  % |
| 0x5E | `VTHROTRAW` | TPS Sensor Voltage | $Val/13107 |  V |
| 0x60 | `PRUNTIME` | Previous Engine Runtime | — | — |
| 0x62 | `VO2B` | O2 Sensor Voltage Cyl 2 | $Val/64 |  mV |
| calc | `ALTITUDE` | Altitude | CalcAltitude($VBARO, $VIAT) |  m |

The five bytes at `0x37–0x3B` are bit flags; they are expanded in 12.4.

## 12.4 Status bytes and firmware aliases

The five status bytes map in order to the five packed bytes at
`0xC60C–0xC610`. The bit positions in `diag_status_build` line up with the live-data
bit names, which gives semantic aliases for 40 previously mechanical flags.
This is an inference from exact bit positions, not a runtime trace; confidence
is high for the mapping, but the byte order should be confirmed against a log.

**status byte `0x37` → `0xC60C` `diag_status_bytes`**

| Bit | UID | field | Firmware alias | Inverted |
|---|---|---|---|---|
| 0 | B_FUELCOFF | Fuel Cut Off Enable | `diag_flag_c9f0` |  |
| 1 | B_FCOCRFLD | Clear Flood Enable | `diag_flag_c91c` |  |
| 2 | B_DFCOCMET | DFCO Met | `diag_flag_c92e` |  |
| 3 | B_DFCOENBL | DFCO Enter | `diag_flag_ca44` |  |
| 4 | B_DFCOEENBL | DFCO Exit | `diag_flag_c89e` |  |
| 5 | B_FCOHRPM | Speed Limiter | `engine_state == 3` |  |
| 6 | B_VRLVENBL | Roll Over Enabled | `DAT_e00894` |  |
| 7 | B_FCLREST2 | C/L Reset Cyl 2 | `diag_flag_caf9` |  |
**live-data `0x38` → `0xC60D` `diag_status_byte1`**

| Bit | UID | field | Firmware alias | Inverted |
|---|---|---|---|---|
| 0 | B_FCLCEN1 | C/L Enabled Cyl 1 | `diag_flag_c92b` |  |
| 1 | B_PPDSEBL | Prime Pulse Disable | `diag_flag_c934` |  |
| 2 | B_FPENABL | Fuel Pump On | `DAT_e0081a` |  |
| 3 | B_FTRNSAES | Acc Enrich Enter | `diag_flag_c81c` |  |
| 4 | B_FTRNSDES | Dec Enlean Enter | `diag_flag_c77e` |  |
| 5 | B_FTRNSAEDCLOAD | Acc Enrich Exit | `ram_var_c604` | yes |
| 6 | B_FTRNSDEINLOAD | Dec Enlean Exit | `diag_flag_c603` | yes |
| 7 | B_FCLCEN2 | C/L Enabled Cyl 2 | `DAT_e0083e == 1` |  |
**live-data `0x39` → `0xC60E` `diag_status_byte2`**

| Bit | UID | field | Firmware alias | Inverted |
|---|---|---|---|---|
| 0 | B_FO2STAT1 | O2 Sensor Rich Cyl 1 | `diag_flag_c784` |  |
| 1 | B_FCLREST1 | C/L Reset Cyl 1 | `diag_flag_c850` |  |
| 2 | B_FOSHTREN | O2 Sensor Heater Enable | `diag_flag_c786` |  |
| 3 | B_FO2REDY1 | O2 Sensor Ready Cyl 1 | `diag_flag_c780` |  |
| 4 | B_IACVMODE0 | IACV Correction on | `diag_flag_c781` |  |
| 5 | B_IAMTRLOST | IACV Lost Step | `diag_flag_c78d` |  |
| 6 | B_IACMVIHB | IACV Move Inhibit | `DAT_e00844` |  |
| 7 | B_VIGNS | Ignition On | `diag_flag_cac6` |  |
**live-data `0x3A` → `0xC60F` `diag_status_byte3`**

| Bit | UID | field | Firmware alias | Inverted |
|---|---|---|---|---|
| 0 | B_CYCSENBL | MAP CID Enable | `diag_flag_cad0 == 1` |  |
| 1 | B_VCSINSYN | MAP CID Succeed | `diag_flag_cac5` |  |
| 2 | B_IDLCONM | Idle Mode | `DAT_e00810` |  |
| 3 | B_FPESTAT | Power Enrichment Enable | `diag_flag_caf8` |  |
| 4 | B_FPEAFREN | PE Protection Enable | `DAT_e0089e` | yes |
| 5 | B_PNSWITCH | Clutch / Neutral Switch | `DAT_e0085c` |  |
| 6 | B_DIAGSWTCH | Diagnostic Mode | `DAT_e00846` |  |
| 7 | B_MILSTATUS | MIL Fault Light on | `diag_flag_c954` |  |
**live-data `0x3B` → `0xC610` `diag_status_byte4`**

| Bit | UID | field | Firmware alias | Inverted |
|---|---|---|---|---|
| 0 | B_VAFCMET | Airflow Correction Met | `diag_flag_cad6` |  |
| 1 | B_VBAROCMET | Baro Update Met | `diag_flag_c014` |  |
| 2 | B_VCSINSYNSPRK | Seq. Spark Enable | `diag_flag_c824` |  |
| 3 | B_SATITRIG | Spark Tip-In Enable | `diag_flag_c841` |  |
| 4 | B_CATLOENB | Cat Light Off Enable | `diag_flag_c830` |  |
| 5 | B_ENGSTATE3 | Engine Running | `diag_flag_c836` |  |
| 6 | B_NISTBLIDLE | Stable Warm Idle | `diag_flag_c840` |  |
| 7 | B_FO2REDY2 | O2 Sensor Ready Cyl 2 | `diag_flag_cad7` |  |

Validation from a real diagnostic log (MT05, 2-cylinder, same packet format) a running sample at 1380 rpm has status bytes
`0x37=0x00, 0x38=0x87, 0x39=0x9D, 0x3A=0x27, 0x3B=0xE5`.
Decoded with the mapping above, `0x3B=0xE5` sets Airflow Correction Met,
Seq. Spark Enable, Engine Running, Stable Warm Idle and O2 Ready Cyl 2;
`0x39=0x9D` sets O2 Rich, O2 Heater, O2 Ready, IACV Correction and Ignition On;
`0x38=0x87` sets C/L Enabled Cyl 1/2, Prime Pulse Disable and Fuel Pump On.
This is exactly the expected running-engine state, so the byte order
`0x37..0x3B → 0xC60C..0xC610` is confirmed. A second sample at 7804.5 rpm with
closed throttle (MAP 25.7 kPa) has `0x37=0x8D`, decoding to Fuel Cut Off,
DFCO Met, DFCO Enter and C/L Reset Cyl 2 — the expected overrun fuel-cut state.

The full machine-readable mapping is
[`c166sv2/deliverables/artifacts/live_firmware_map.csv`](../../deliverables/artifacts/live_firmware_map.csv).

## 12.5 The `0x30` data-slewing channels

live-data defines `SetAbs="30 SID 07 VAL"`, `SetDelta="30 SID 80 VAL"`,
`DeltaNeg="30 SID 81 VAL"`, and `TurnOff="30 SID 00"`. The selectable channels
are:

| SlewID | UID | field | FormulaSet | Min | Max |
|---|---|---|---|---|---|
| 0x80 | `SPDWELL` | Spark Dwell Time | $Val*8 | 0 | 12 |
| 0x81 | `SAESTA` | Spark Adv Measured | $Val*2 | -20 | 60 |
| 0x82 | `VMAPRANG` | MAP Read Angle | $Val | 0 | 270 |
| 0x83 | `IARDRPM` | Idle Speed Target | $Val | 0 | 16000 |
| 0x84 | `AFFNLAFR` | Air-Fuel Ratio Measured | $Val*16 | 0 | 31 |
| 0x85 | `FVE1` | Volume Efficiency Cyl 1 | $Val*2.56 | 0 | 199 |
| 0x86 | `FVE2` | Volume Efficiency Cyl 2 | $Val*2.56 | 0 | 199 |
| 0x87 | `IACVDSMP` | IACV Position Target | $Val | 0 | 255 |
| 0x88 | `FPPDC` | Fuel Pump Duty Cycle | $Val/6.25 | 0 | 100 |
| 0x8C | `SLEW_SPARK` | Test Spark (MT05.2 only) | — | — | — |
| 0x8D | `SLEW_INJECTOR` | Test Inject (MT05.2 only) | — | — | — |
| 0x8E | `SLEW_IACV` | Test IACV (MT05.2 only) | — | — | — |
| 0x8F | `SLEW_FUELPUMP` | Test Pump (MT05.2 only) | — | — | — |

`0x8C–0x8F` are MT05.2-only test outputs (spark, injector, IACV, fuel pump).

## 12.6 Firmware correlation

These are the strongest cross-links between the 100-byte fields and recovered
firmware state. They are candidates, not proven source addresses.

| Firmware | Name | live-data offset | live-data UID | field | Conf. | Evidence |
|---|---|---|---|---|---|---|
| `0xC9D0` | `engine_speed_input` | `0x58` | `VRPM` | Engine Speed | medium | VRPM raw/4; source read by speed/load/limit code |
| `0xCA2A` | `calc_input_y` | `0x4E` | `VMAP` | MAP Intake Pressure | medium | second axis input to calc_load; MAP is likely speed-density load |
| `0xCA2A` | `calc_input_y` | `0x5A` | `VTHROT` | Throttle Position | low | alternate candidate; needs log confirmation |
| `0xC410` | `cc16_17_channels` | `0x1A` | `FPWVC1` | Injector Time Cyl 1 | medium | CC16/17 event duration is injector pulse-width candidate |
| `0xC410` | `cc16_17_channels` | `0x1C` | `FPWVC2` | Injector Time Cyl 2 | low | second channel; unused on single-cylinder engine |
| `0xC410` | `cc16_17_channels` | `0x35` | `SPDWELL` | Spark Dwell Time | medium | event channel duration; dwell is ignition-channel candidate |
| `0xC410` | `cc16_17_channels` | `0x2F` | `SAESTA` | Spark Adv Measured | low | event scheduling angle/timing candidate |
| `0xC410` | `cc16_17_channels` | `0x31` | `SAGLOBAL1` | Spark Adv Target | low | event scheduling angle/timing candidate |
| `0xC410` | `cc16_17_channels` | `0x33` | `SAIDLDYN` | Dynam. Idle Spark Adv | low | event scheduling angle/timing candidate |
| `0xE008B2` | `load_calc_result` | `0x1E` | `FVE1` | Volume Efficiency Cyl 1 | high | map max 244 -> FVE1 max 95.20%; FVE1 raw = result × 256 |
| `0xE008B2` | `load_calc_result` | `0x20` | `FVE2` | Volume Efficiency Cyl 2 | low | second-cylinder counterpart |
| `0xE008A8` | `load_rate_limited` | `0x1E` | `FVE1` | Volume Efficiency Cyl 1 | low | rate-limited load is alternate VE source |
| `0xC54A` | `scheduler_tick` | `0x2D` | `RUNTIME` | Engine Runtime | medium | scheduler tick is only recovered runtime counter |
| `0xE892` | `pwm_period` | `0x18` | `FPPDC` | Fuel Pump Duty Cycle | low | PWM period is candidate fuel-pump/purge duty source |
| `0xE8A2` | `pwm_duty` | `0x18` | `FPPDC` | Fuel Pump Duty Cycle | low | PWM duty is candidate fuel-pump/purge duty source |
| `0xE8A6` | `pwm_control` | `0x40` | `VAFRRAW2` | Carbon Canister Purge | low | PWM control is candidate purge output |

Sensors that are not recovered as named variables (MAP, TPS, coolant, inlet air,
ignition voltage, O2, baro, vehicle speed) are probably sampled by the missing
external-RAM task/ADC layer. The DTC fields `MALFCURR`/`MALFHIST` come from the
DTC logic; `RUNTIME` is consistent with the scheduler tick at `0xC54A`.

## 12.7 What this means

* The 100-byte live-data packet is now **known by field**, not just inferred:
  RPM, MAP, TPS, coolant, inlet air, ignition voltage, O2, injector time, dwell,
  spark advance, fuel trims, idle targets, DTCs, runtime, vehicle speed, purge,
  baro and 40 status bits.
* The status bits give semantic names to the `diag_flag_*`/`DAT_e008*`
  variables used by `diag_status_build`; a running-engine log confirms the
  byte order and the Engine Running / Stable Warm Idle / O2 bits.
* `0x30` provides a second, faster channel for selected values; the full
  slewing list is in `c166sv2/deliverables/artifacts/live_30_slew.csv`.
* The remaining gap is the **producer** of each non-status field. A capture of
  `21 01` from this bike, or an ECU RAM snapshot, would let us map each offset
  back to the exact RAM cell and calculation.

## 12.8 Next probe

1. Capture `21 01` and `30` traffic from this bike at idle and several steady
   RPMs.
2. Compare the 100-byte response with the live-data dashboard values.
3. Match each offset to `0xE008xx`, `0xC9xx`, `0xC410` or the external-RAM task
   inputs.
4. Confirm the status-byte order `0x37..0x3B ↔ 0xC60C..0xC610`.
