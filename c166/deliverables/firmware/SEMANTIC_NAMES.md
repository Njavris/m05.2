# Semantic names, evidence and recovered structures

This is the evidence trail for the renamed decompilation. Names are based on
observed behavior (SFR writes, call graph, data flow, calibration tables and the
XC164CS peripheral map), not on guessed mnemonics. Where a name is mechanical
rather than physical, it says so. Where a physical role remains unproven, the
confidence column says so.

A C-developer navigation tree generated from these names is in
`../../deliverables/reconstruction/` (see `../../deliverables/reconstruction/README.md`).

The combined file is:

* `reference/decompiled_all.c` — all 195 functions with these names
* `reference/decompiled_all.asm` — all 195 instruction listings

The structure definitions are in `include/firmware_types.h`. Algorithm-level
descriptions are in `ALGORITHMS.md`; the machine-readable index is
`SEMANTIC_INDEX.csv`.

## 1. How the renames were derived

1. **Call graph.** Ghidra caller/callee edges grouped the unnamed functions into
   clusters: K-line transport, CC16/CC17 events, CC22/CC23 events, sensor/config,
   scheduler/diagnostics, and the software-float runtime.
2. **SFR evidence.** Functions that write `CC22`, `CC23`, `CC16`, `CC17`,
   `CCM*`, `T7`, `S0CON`, `S0TBUF`, `S0RBUF`, `PWMCON0`, `P1L`, etc. were named by
   the peripheral they operate.
3. **Data-flow evidence.** Global writes/reads were extracted per function
   (`/tmp/var_access.csv` in the analysis workspace). This separated producers
   from consumers and identified state variables.
4. **Calibration/table evidence.** The limit/load functions were traced to the
   exact table addresses (0xC0784C, 0xC07860, 0xC07874, 0xC078D8, 0xC078E2,
   0xC07912, 0xC0794A, 0xC079B6).
5. **External RAM limitation.** The task table at 0x705E/0x7164/0x7666 and the
   axis descriptors at 0x7000/0x750A–0x7564 are not in the flash dump. Functions
   that read them are named by what they do with the *result*, not by the
   unknown table contents.

## 2. Function names

### 2.1 Boot, ASC0 and K-line

| Address | Name | Evidence | Confidence |
|---|---|---|---|
| 0xC00C84 | `asc0_tx_byte` | writes `S0TBUF` | high |
| 0xC00C8A | `asc0_read_rx_clear` | clears `S0RIC.7`, returns `S0RBUF` | high |
| 0xC11F60 | `asc0_read_rx_raw` | returns `S0RBUF` without clearing the flag | high |
| 0xC11F66 | `asc0_rx_handler` | reads `S0RBUF`, pushes into the K-line ring at 0xF600, `RETI`; not referenced by the active 8-vector table | high for ASC0 behavior; invocation path unknown |
| 0xC11F9A | `asc0_tx_handler` | handles the K-line transmit state and calls the 0xC126xx helpers, `RETI`; not referenced by the active vector table | medium |
| 0xC01212 | `kline_receive_pattern` | compares received bytes at 0xC144 to the 5-byte pattern at 0xC0A3, advances 0xC0AE | high |
| 0xC00EE8 | `boot_extint_init` | calls `boot_bus_mode`, writes `EXICON`, `T1IC` | high |
| 0xC12696 | `kline_get_status` | returns 0xC56D | high |
| 0xC126B0 | `kline_start_timeout` | writes 0x0500 to 0xC56A | high |
| 0xC126BC | `kline_state_reset` | clears 0xC582/0xC57D/0xC588/0xC584 | high |
| 0xC126DA | `kline_prepare_frame` | computes timing from 0xC57F/0xC598/0xC599/0xC580/0xC592, sets state 6 | high |
| 0xC12826 | `kline_rx_state_7` | sets 0xC584 = 7 | high |
| 0xC12848 | `kline_rx_state_8` | sets 0xC584 = 8 | high |
| 0xC1293C | `kline_push_rx_byte` | writes received bytes into the 0xF600 ring | high |
| 0xC12982 | `kline_transport_task` | state 0xC584 selects a handler table at 0x7164 | high |
| 0xC13D50 | `test_command_clear` | clears 0xFD18 low byte and 0xC5E8/0xC5EA | high |
| 0xC13D5E | `test_command_dispatch` | 0xFD18 bits 0/1/2 dispatch to CC22/23 start, event start, PWM | high |
| 0xC13F9A | `capture_input_select` | writes low bits of 0xFD1A | high |

> The CC22/CC23 pair is reached from `test_command` bit 0 (`test_command_dispatch` -> `cc22_23_start_once`). Treat it as an **actuator/test output pair**, not the normal injection/ignition scheduler. The normal event pair is CC16/CC17 (`event_schedule` / `event_start`). live-data `0x30` exposes test spark/injector/IACV/fuel-pump channels (`0x8C–0x8F`) and live trim of dwell, advance, idle target, AFR, VE and pump duty; the recovered `test_command`/CC22/23 path is the likely actuator interface, but the exact mapping is open.

### 2.2 CAPCOM CC16/CC17 events

| Address | Name | Evidence | Confidence |
|---|---|---|---|
| 0xC0BE46 | `cc22_23_output_disable` | masks `CCM5` bits 0x0800/0x7000 | high |
| 0xC0BE6A | `cc22_23_schedule` | writes `CC22`/`CC23` compare from a T7 timestamp | high |
| 0xC0BEF0 | `cc_control_ptr_init` | caches 0xFF2C and 0xFE2A pointers | high |
| 0xC0BF02 | `cc22_23_output_init` | sets `CC22IC`/`CC23IC`, `CCM5`, port pins, shadow pointers | high |
| 0xC0BF54 | `cc_irq_enable` | sets/clears a bit in 0xFF2C for a channel | high |
| 0xC0BF8C | `cc_irq_is_enabled` | tests a bit in 0xFF2C | high |
| 0xC0BD54 | `p1l1_set` | sets P1L.1 | high |
| 0xC0D6F0 | `event_start_fixed` | loads 0x1194/0 and calls `event_start` | high |
| 0xC0DB90 | `cc_irq_enable_bit` | enables bit 0/1 of 0xFE2A for channel 0x10/0x11 | high |
| 0xC0DBA6 | `cc_compare_mode_set` | sets/clears bit 0/1 of 0xFF2C for channel 0x10/0x11 | high |
| 0xC0E722 | `cc22_23_hysteresis_a` | hysteresis on a timing value, state 0xC450 | medium |
| 0xC0E760 | `cc22_23_hysteresis_b` | hysteresis on a timing value, state 0xC454 | medium |
| 0xC0EBE6 | `cc_output_gate_update` | updates 0xFD08/0xFD06 gate bits | high |
| 0xC0E27C | `event_schedule_duration` | uses `t7_timestamp_extended`, 32-bit duration fields, CC16/17 compare mode 4/5 | high |
| 0xC0FACE | `cc22_23_start_pair` | starts channels 0 and 1 via `cc22_23_schedule` | high |
| 0xC0FB36 | `cc22_23_start_once` | one-shot start flag 0xC456, calls start_pair | high |
| 0xC0FB8C | `cc_event_timeout_tick` | ages 0xFD12/0xFD0E every 0xA00 ticks | high |

### 2.3 CC22/CC23 task and timing

| Address | Name | Evidence | Confidence |
|---|---|---|---|
| 0xC0F3D2 | `cc22_23_task` | reads `engine_speed_input`, calls state A/B, schedules CC22/23, handles two channel flags | high |
| 0xC0CD24 | `speed_timing_calc` | `axis16_unsigned(0x7000, engine_speed_input)`, tables 0x504C/0x5038 -> 0xC274/0xC26E | high |
| 0xC1064C | `t7_timestamp` | reads T7/T7IC, adds 0xC4C8, shifts by 3 | high |
| 0xC106E6 | `t7_timestamp_extended` | T7>>8 + 0xC4CA plus T7 overflow bit | high |
| 0xC108B4 | `timeout_counter_tick` | saturates 0xC4CC at 0x81, clears 0xC4D2/0xC4D4 | high |
| 0xC10242 | `input_debounce_sample` | samples P1L pins into 0xC49A/0xC49C/0xC4B6 | high |
| 0xC10342 | `ssc_task` | starts SSC, handles timeout 0xC498, samples port | high |
| 0xC0D9E4 | `ssc_init` | installs 0xC0D8FA/0xC0D914 handlers, calls `cc26_ptr_init` and `ssc_pin_config` | high |
| 0xC0DA62 | `cc26_ptr_init` | caches CC26/CCM6/CC26IC pointers | high |

### 2.4 Scheduler, diagnostics and commands

| Address | Name | Evidence | Confidence |
|---|---|---|---|
| 0xC11EEC | `scheduler_tick` | increments 0xC54C, calls `command_dispatch_index3` | high |
| 0xC147C6 | `command_dispatch_index3` | calls `command_dispatch(3)` | high |
| 0xC19A2C | `command_dispatch` | 7-case jump table at external RAM 0x7666 | high |
| 0xC1482C | `diag_status_build` | packs flags into 0xC60C..0xC610 | high |
| 0xC0F628 | `config_sensor_setup` | selects sensor handler pointers from 0xC05036, calls `fp_*`, initializes CC22/23 | high |

### 2.5 CAN diagnostic objects

| Address | Name | Evidence | Confidence |
|---|---|---|---|
| 0xC019D6 | `can_diag_object_init` | sets MO9/MO10 arbitration 0x1FB8/0x1FBC (IDs 0x7EE/0x7EF), masks 0xFFFF | high |
| 0xC01AD4 | `can_bootloader_wait` | calls `can_diag_object_init`, copies a 4-byte value, loops | high |

### 2.6 PWM / float / math

| Address | Name | Evidence | Confidence |
|---|---|---|---|
| 0xC1096E | `div32_checked` | calls `div32u`; returns 0xFFFFFFFF on invalid result | high |
| 0xC109A2 | `mul_div32` | calls `mul32` then `div32u` | high |
| 0xC10A74 | `pwm_period_duty_calc` | uses the float division result to write 0xE892/0xE8A2/0xE8A6 | high |
| 0xC10AFC | `pwm_output_enable` | sets `PWMCON0.2` and P1L.4 | high |
| 0xC28BB2 | `div32u` | 32-bit unsigned division with LZCOUNT/remainder | high |
| 0xC28C62 | `store32` | stores two 16-bit words at a pointer | high |
| 0xC28CA4 | `fp_div_signed` | software float division with sign-bit handling | medium |
| 0xC28CAC | `fp_div_unsigned` | software float division without initial sign toggle | medium |
| 0xC28DBE | `fp_to_int` | extracts exponent/mantissa and shifts to integer | high |
| 0xC28DEC | `fp_neg` | toggles the float sign bit and stores | high |
| 0xC28E50 | `fp_compare` | compares two 4-word floats | high |
| 0xC28E94 | `fp_pack` | packs three words into a 4-word float | high |
| 0xC28ED2 | `fp_pack_zero` | packs a zero float | high |
| 0xC28F0E | `fp_round` | rounds a float and stores | high |
| 0xC28F1E | `fp_store` | stores four words of a float | high |
| 0xC28F5E | `fp_store_zero` | stores a zero float | high |
| 0xC28F6C | `fp_load` | loads four words of a float | high |
| 0xC28F84 | `fp_copy` | copies four words of a float | high |

### 2.7 Empty stubs

| Address | Name |
|---|---|
| 0xC0BFF4 | `empty_stub_1` |
| 0xC0BFF6 | `empty_stub_2` |
| 0xC10240 | `empty_stub_3` |
| 0xC28C4E | `empty_stub_0` |

## 3. Key variables

| Address | Name | Type | Evidence |
|---|---|---|---|
| 0x00C9D0 | `engine_speed_input` | u16 | read by `speed_timing_calc`, `cc22_23_task`, `calc_load`, `calc_limit2`; live-data field `VRPM`; no writer in the recovered set |
| 0x00C93C | `engine_state` | u8 | values 1/3/4; read by `calc_limit1/2` and `diag_status_build` |
| 0x00C884 | `limit_flag_0` | u8 | written by `calc_limit2` |
| 0x00C885 | `limit_flag_1` | u8 | written by `calc_limit2` |
| 0x00C886 | `limit_flag_2` | u8 | written by `calc_limit1` |
| 0x00E008A2 | `speed_limit_active` | u8 | written by `calc_limit2` |
| 0x00E008B2 | `load_calc_result` | u16 | written by `calc_load`; live-data `FVE1`/`FVE2`; map 0xC0794A |
| 0x00C54A | `scheduler_tick` | u16 | incremented by the scheduler |
| 0x00C54C | `scheduler_counter` | u16 | incremented by `scheduler_tick`, wraps at 0xC550 |
| 0x00C550 | `scheduler_counter_reload` | u16 | reload for 0xC54C |
| 0x00C584 | `kline_state` | u8 | selects the K-line handler table at 0x7164 |
| 0x00C56A | `kline_timeout` | u16 | K-line timeout |
| 0x00C09A | `security_unlocked` | u8 | set by SID 0x27 key check |
| 0x00C0B2 | `kline_response_frame` | kline_frame_t | response header/payload |
| 0x00C144 | `kline_rx_buffer` | u8[] | received K-line bytes |
| 0x00C147 | `kwp_request` | u8[] | KWP request payload |
| 0x00F600 | `kline_rx_ring` | u8[0x3D] | IRAM ring used by `kline_push_rx_byte` |
| 0x00F740 | `can_diag_rx_buffer` | u8[8] | CAN diagnostic receive buffer |
| 0x00C3740 | `can_rx_staging` | u8[8] | CAN receive staging |
| 0x00C3750 | `can_tx_staging` | u8[8] | CAN transmit staging |
| 0x00FD18 | `test_command` | u8 | actuator/test command bits |
| 0x00FD1A | `capture_input_select` | u8 | low-bit capture selection |
| 0x00FD14 | `scheduler_event_flag` | u16 | scheduler event flag |
| 0x00FD02 | `speed_status_flags` | u16 | speed/CC status flags |
| 0x00FD00 | `input_status_flags` | u16 | input/capture status flags |
| 0x00C254 | `speed_axis_index` | u16 | 8.8 speed index from axis 0x7000 |
| 0x00C274 | `speed_table_504c` | u16 | table 0x504C at the speed index |
| 0x00C26E | `speed_table_5038` | u16 | table 0x5038 at the speed index |
| 0x00E892 | `pwm_period` | u16 | PWM period value |
| 0x00E8A2 | `pwm_duty` | u16 | PWM duty value |
| 0x00E8A6 | `pwm_control` | u16 | PWM control value |
| 0x00C504 | `pwm_divisor` | u32 | intermediate PWM divisor |
| 0x00C4EA | `pwm_duty_calc` | u32 | intermediate PWM duty |
| 0x00C402 | `cc_compare_mode_shadow` | u16 | shadow of the CAPCOM compare-mode register |
| 0x00C3FC | `t7_snapshot` | u16 | T7 snapshot used by the event scheduler |
| 0x00C450 | `cc22_23_state_machine_a` | u16 | state machine A |
| 0x00C454 | `cc22_23_state_machine_b` | u16 | state machine B |
| 0x00C456 | `cc22_23_started` | u8 | one-shot start flag |
| 0x00C220 | `sensor_setup` | sensor_setup_t | seven selected handler pointers |
| 0x00C468 | `sensor_coefficients` | u16[5] | copied from external RAM 0x700E..0x702C |
| 0x00C45E | `sensor_channel_count` | u8 | number of configured channels |
| 0x00C60C | `diag_status_bytes` | diag_status_t | five packed diagnostic bytes |

## 4. Structures

See `include/firmware_types.h` for C definitions. The layout evidence is:

| Structure | Location | Size/stride | Evidence |
|---|---|---|---|
| `kline_frame_t` | 0xC0B2 | 4 + payload + 1 | `asc0_state5` builds format 0x80, target 0xF1, source 0x11, length, payload, checksum |
| `kline_state_t` | 0xC0AE/0xC144/0xC1D1 | scattered | `kline_receive_pattern`, `kline_transport_task`, `asc0_state*` |
| `cc_event_channel_t` | 0xC410 | 0x12 | `event_schedule`, `capcom_event_config`, `event_schedule_duration` field accesses |
| `cc22_23_channel_t` | 0xC3D2 | 0x1A | `cc22_23_schedule` writes timestamp at +0, `config_sensor_setup` touches +7/+8 |
| `sensor_setup_t` | 0xC220/0xC468 | 0x30 + coeff | `config_sensor_setup` writes seven handler pointers and five coefficients |
| `diag_status_t` | 0xC60C | 5 bytes | `diag_status_build` packs flags into five bytes |
| `fp32_t` | anywhere | 8 bytes (4 words) | `fp_load`/`fp_store`/`fp_copy` move exactly four words |
| `can_msg_object_t` | 0x200300 + 0x20*i | 0x20 | TwinCAN object layout; IDs/masks/control observed in `can_twincan_init`/`can_diag_object_init` |
| `cal_axis_t` | 0xC075xx etc. | 6 bytes | `axis16_unsigned` reads count/min/max |
| `cal_tbl8_t` | 0xC0784C etc. | 2 + count | `tbl8_interp` reads count/shift/data |
| `cal_tbl16_t` | 0xC07912 | 2 + 2*count | `tbl16_interp` reads count/data |
| `cal_map2d_t` | 0xC0794A | 3 + cols*rows | `tbl2d_interp` reads cols/rows/shift/data |
| `adapt_record_layout_t` | 0xC04000 | 0x200 | sequence/payload/5A A5/tail |

## 5. What is still uncertain

* The physical unit of `engine_speed_input` (0xC9D0): live-data labels the live
  channel `VRPM` and scales it by 4 from the raw packet, so it behaves like
  engine speed rather than an inverse period; the producer is still not in the
  recovered function set.
* The exact engine map units (fuel, ignition advance, etc.) of the calibration
  tables. The table shapes and consumers are known; the physical scaling is not.
* The axis descriptors at 0x7000/0x750A–0x7564 and the task/command tables at
  0x705E/0x7164/0x7666 are in external RAM and are not in the flash dump.
* `cc22_23_channel_t` fields beyond +0/+7/+8 are a partial model.
* The software-float format is inferred from the 4-word load/store and
  exponent/mantissa bit operations; it is not claimed to be IEEE-754.
* The limit paths (`calc_limit1/2/3`) are named by behavior and data flow, not
  by a recovered tuning document. Which one is the hard rev limiter remains an
  inference, not a proven fact.
* `asc0_rx_handler`/`asc0_tx_handler` are ASC0 handlers but are not in the
  active vector table; their actual invocation path (alternate vector table,
  function pointer, or dormant code) is unresolved.
* CC22/CC23 are test/actuator outputs; CC16/CC17 are the normal timed event pair.
  The injector/ignition mapping is still inferred, not proven by a schematic.


## 6. Complete RAM variable classification

After the semantic and mechanical passes, every referenced RAM variable outside
the SFR/ESFR area has a label. The labels come in two grades:

* **Semantic** — a physical or logical role is supported by data flow/hardware
  evidence (e.g. `engine_speed_input`, `kline_state`, `cc16_17_channels`).
* **Mechanical** — the exact physical meaning is unknown, but the address is
  used only by one subsystem or one function, so the name records that fact
  (e.g. `kline_var_c57f`, `capture_var_c2b4`, `diag_flag_c77e`).

| Prefix | Scope | Basis |
|---|---|---|
| `engine_*` | engine/speed/limit state | producers/consumers in limit/load/speed code |
| `limit_*` | limit calculations | `calc_limit1/2` writes |
| `kline_*` | K-line transport and frame | only `kline_*` / `asc0_*` functions |
| `can_*` | CAN transport | only `can_*` functions |
| `capture_*` | capture/timer state | `timer5_init`, `capture_*`, `input_debounce_sample` |
| `event_*` | CC16/CC17 event state | `event_*` functions |
| `cc*_` | CAPCOM registers/shadows | `capcom_*`, `cc*` functions |
| `sensor_*` | sensor/config setup | `config_sensor_setup`, `angle_init` |
| `pwm_*` | PWM state | `pwm_init`, `pwm_period_duty_calc` |
| `ssc_*` | SSC frame engine | `ssc_*` functions |
| `diag_flag_*` | status bits consumed by `diag_status_build` | read only by that function |
| `diag_status_*` | packed diagnostic bytes | `0xC60C..0xC610` |
| `status_flag_*` | external-RAM status flags | `0xFD00..0xFD1F` |
| `isr_save_*` | ISR context/stack save slots | written by ISR prologues |
| `stack_guard_*` | stack boundary words | trap handlers |
| `can_msg_*` | CAN message-object data bytes | `0xF740..0xF74F` |
| `xram_var_*` | XRAM variables without a proven role | `0xE000..0xE7FF` |
| `ram_var_*` | RAM variables without a proven role | low external RAM |
| `boot_port_cfg_*` | boot port/ADC setup words | `boot_port_adc_init` |

All of these are labels in the Ghidra database, so they appear in
`reference/decompiled_all.c` and the per-function files. A mechanical name is
not a claim about a physical signal; it records the subsystem that accesses the
address.

## 7. Expanded structure catalog

`include/firmware_types.h` contains both the contiguous structures and the
logical address-group structures.

| Structure | Addresses | Purpose |
|---|---|---|
| `kline_frame_t` | 0xC0B2 | K-line response frame (format/target/firmware/length/payload/checksum) |
| `kline_transport_t` | 0xC0AE, 0xC0AF, 0xC0B0, 0xC13E, 0xC140, 0xC142, 0xC1D0, 0xC138, 0xC13C, 0xC09E, 0xC0A0, 0xC0A2, 0xC0A3, 0xC0A8, 0xC1D1, 0xC09A | logical K-line receive/transmit state |
| `cc_event_channel_t` | 0xC410 + 0x12*i | CC16/CC17 event channel (2 channels); live-data injector/dwell/spark fields |
| `cc22_23_channel_t` | 0xC3D2 + 0x1A*i | CC22/CC23 test/actuator channel (partial) |
| `cc22_23_state_t` | 0xC450, 0xC454, 0xC456, 0x7046, 0x7048 | CC22/23 states and external inputs |
| `capture_state_t` | 0xC240/242/244/246, 0xC268, 0xC280, 0xC2B4, 0xC26A/26C, 0xC25C, 0xC2AA, 0xC28A, 0xC2A2 | capture/timer5 state and callbacks |
| `test_command_t` | 0xFD18, 0xC5E8, 0xC5EA, 0xFD08, 0xFD06, 0xFD0A | actuator/test command |
| `can_transport_t` | 0xC1D2, 0xC1D4, 0xC1D6, 0xC1DA, 0xC1D8, 0xC1DC, 0xC1DE, 0xC016 | CAN ISO-TP transport state |
| `scheduler_state_t` | 0xC54A, 0xC54C, 0xC550, 0xFD14, 0xFD02, 0xFD00, 0xC5E6, 0xC962, 0xCB60 | scheduler/timing state |
| `pwm_state_t` | 0xE892, 0xE8A2, 0xE8A6, 0xC504, 0xC4EA, 0xE8A0..0xE8CE | PWM set-up |
| `sensor_setup_t` | 0xC220..0xC23F, 0xC456, 0xC45E, 0xC44C, 0xC468 | selected sensor handlers/coefficients |
| `diag_status_t` | 0xC60C..0xC610 | packed diagnostic status; live-data `21 01` bytes 0x37..0x3B |
| `fp32_t` | any 8-byte slot | four-word software float |
| `can_msg_object_t` | 0x200300 + 0x20*i | TwinCAN message object (observed layout) |
| `cal_axis_t`, `cal_tbl8_t`, `cal_tbl16_t`, `cal_map2d_t` | calibration block | table headers |
| `adapt_record_layout_t` | 0xC04000 + 0x200*i | adaptation log record |

## 8. Remaining `DAT_` addresses

After the naming passes, the remaining `DAT_` tokens in the combined file are
not firmware variables:

* `0xF000–0xF1FF` — ESFR/hardware registers and ISR context-save slots.
* `0xFE00–0xFFFF` — SFR area (ports, timers, ASC0, CAN control, ADC).
* `0x200000–0x2007FF` — TwinCAN registers/message objects.
* `0xC0xxxx` and `0xCxxxxx` — flash constants, calibration bytes and table
  bases (not RAM variables).
* `0xFC00–0xFCFF`, `0xFDFC–0xFDFE` — stack/context guards; named where they are
  firmware state.

The named SFRs come from the XC164/C167 register map; unnamed ESFR/SFR addresses
are left as `DAT_` rather than inventing a register name that the available
device spec does not confirm.

## 9. live-data aliases

The live-data MT05/MT05.2 profile (`21 01`, 100-byte live-data packet) supplies names
for the five packed status bytes at `0xC60C..0xC610`. The bit order matches
`diag_status_build` exactly; the inferred aliases are:

| Firmware alias | live-data status name |
|---|---|
| `diag_flag_c9f0` | Fuel Cut Off Enable |
| `diag_flag_c91c` | Clear Flood Enable |
| `diag_flag_c92e` | DFCO Met |
| `diag_flag_ca44` | DFCO Enter |
| `diag_flag_c89e` | DFCO Exit |
| `engine_state == 3` | Speed Limiter |
| `DAT_e00894` | Roll Over Enabled |
| `diag_flag_caf9` | C/L Reset Cyl 2 |
| `diag_flag_c92b` | C/L Enabled Cyl 1 |
| `diag_flag_c934` | Prime Pulse Disable |
| `DAT_e0081a` | Fuel Pump On |
| `diag_flag_c81c` | Acc Enrich Enter |
| `diag_flag_c77e` | Dec Enlean Enter |
| `ram_var_c604` (inverted) | Acc Enrich Exit |
| `diag_flag_c603` (inverted) | Dec Enlean Exit |
| `DAT_e0083e == 1` | C/L Enabled Cyl 2 |
| `diag_flag_c784` | O2 Sensor Rich Cyl 1 |
| `diag_flag_c850` | C/L Reset Cyl 1 |
| `diag_flag_c786` | O2 Sensor Heater Enable |
| `diag_flag_c780` | O2 Sensor Ready Cyl 1 |
| `diag_flag_c781` | IACV Correction on |
| `diag_flag_c78d` | IACV Lost Step |
| `DAT_e00844` | IACV Move Inhibit |
| `diag_flag_cac6` | Ignition On |
| `diag_flag_cad0 == 1` | MAP CID Enable |
| `diag_flag_cac5` | MAP CID Succeed |
| `DAT_e00810` | Idle Mode |
| `diag_flag_caf8` | Power Enrichment Enable |
| `DAT_e0089e` (inverted) | PE Protection Enable |
| `DAT_e0085c` | Clutch / Neutral Switch |
| `DAT_e00846` | Diagnostic Mode |
| `diag_flag_c954` | MIL Fault Light on |
| `diag_flag_cad6` | Airflow Correction Met |
| `diag_flag_c014` | Baro Update Met |
| `diag_flag_c824` | Seq. Spark Enable |
| `diag_flag_c841` | Spark Tip-In Enable |
| `diag_flag_c830` | Cat Light Off Enable |
| `diag_flag_c836` | Engine Running |
| `diag_flag_c840` | Stable Warm Idle |
| `diag_flag_cad7` | O2 Sensor Ready Cyl 2 |

A running-engine live-data log (`Regal Raptor 350 - Hot Engine.xml`) confirms the byte
order and the Engine Running / Stable Warm Idle / O2 status bits. The complete
live-data field list and firmware-field correlation are in
`../docs/12-debug-channels.md` and `../c166sv2/deliverables/artifacts/live_firmware_map.csv`.
