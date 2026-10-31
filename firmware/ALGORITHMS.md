# Recovered algorithms

This document names the algorithms, lists their entry points, inputs, outputs
and evidence. It is a cross-index, not a replacement for the per-function
assembly. Confidence is stated per algorithm.

Naming convention: an algorithm name describes the observed transformation.
Physical units or injector/ignition mapping are only claimed when the code or a
table makes them explicit.

## 1. Flash integrity (`checksum16_be`)

* **Entry:** `checksum16_be` 0xC0037E; `cal_checksum` 0xC11B9A is the
  calibration-block caller.
* **Input:** 24-bit start/end pointers; reads the flash image.
* **Operation:** `sum += (byte[addr] << 8) | byte[addr+1]` over even addresses.
* **Output:** 16-bit sum.
* **Evidence:** `checksum16_be` assembly loop; verified values: boot 0xEE88,
  calibration 0x8D79, application 0x25C2 on all four dumps.
* **Confidence:** high.

## 2. Boot validation (`boot_validate`)

* **Entry:** `boot_main` 0xC00200.
* **Inputs:** `app_magic` 0xC3FFFC, `boot_checksum` 0xC01FFE,
  `app_checksum` 0xC3FFFE.
* **Operation:** if magic == 0xAA00, skip; else verify boot sum and app sum.
* **Output:** application entry (0xC10000) or bootloader (0xC003F0).
* **Evidence:** two `JMPA cc_NZ` failure branches and `JMPS 0xC1:0x0000`
  success branch; checksums verified.
* **Confidence:** high.

## 3. Reset mode selection (`boot_select_mode`)

* **Entry:** `boot_reset` 0xC00A78.
* **Inputs:** ADC channels 0, 3, 4, 5, 6 (`ADDAT` 10-bit results).
* **Operation:** nested threshold tree with 0x396, 0x67, 0x15 thresholds.
* **Output:** `boot_main`, `boot_minimal_main`, or `bootloader_entry`.
* **Evidence:** exact branch tree in the decompiled reset function.
* **Confidence:** high for the code path; physical meaning of the analog
  levels is inferred.

## 4. C-runtime init tables (`boot_cinit`, `app_cinit`)

* **Entries:** `boot_cinit` 0xC00904; `app_cinit` 0xC1192C.
* **Inputs:** init table at 0xC008BA (boot) / 0xC0BB56 (app).
* **Record format:** type (1/5/6/7), destination offset/page, source
  offset/page, length.
* **Operation:** copy initialized bytes from flash to external RAM/IRAM; zero
  selected IRAM ranges.
* **Evidence:** record walkers in both functions; example records decoded.
* **Confidence:** high.

## 5. K-line receive pattern and transport (`kline_*`)

* **Entries:** `kline_receive_pattern` 0xC01212, `kline_transport_task`
  0xC12982, `kline_prepare_frame` 0xC126DA, `kline_push_rx_byte` 0xC1293C,
  `asc0_rx_handler` 0xC11F66, `asc0_tx_handler` 0xC11F9A.
* **Inputs:** ASC0 `S0RBUF` bytes, `kline_state` 0xC584, timing parameters
  0xC57F/0xC598/0xC599/0xC580/0xC592.
* **Operation:** match the 5-byte wake-up pattern, receive/validate a frame,
  compute K-line timing, transmit a response, age timeouts.
* **Outputs:** `kline_rx_buffer` 0xC144, `kwp_request` 0xC147,
  `kline_response_frame` 0xC0B2, `kwp_request_pending` 0xC1D1.
* **Evidence:** SFR reads/writes, state variable transitions, frame checksum
  builder in `asc0_state5`, buffer copies.
* **Confidence:** high for behavior; the ASC0 handlers are not in the active
  vector table, so their invocation path is unresolved.

## 6. KWP2000 service dispatch (`kwp_dispatch`)

* **Entry:** `kwp_dispatch` 0xC01482.
* **Inputs:** `kwp_request` 0xC147/0xC148/...; `security_unlocked` 0xC09A.
* **Services:** 0x10 session, 0x23 read memory, 0x27 security, 0x31 routine,
  0x34 download, 0x36 transfer, 0x38 transfer-related, 0x3D write memory,
  0x81 start communication, 0x83 Delphi-specific.
* **Outputs:** `kline_response_frame` 0xC0B2; response SID = request + 0x40 for
  normal services; negative response 0x7F SID NRC.
* **Evidence:** dispatch chain and each handler's response constants.
* **Confidence:** high.

## 7. KWP security access (`kwp_sid27_security`)

* **Entry:** 0xC01544.
* **Inputs:** sub-function 1/2; key bytes.
* **Operation:** seed = 0x1234; key = 0x8474; sets `security_unlocked`.
* **Outputs:** `67 01 12 34`, `67 02 34`, or `7F 27 35`.
* **Evidence:** literal constants and branch structure.
* **Confidence:** high.

## 8. CAN diagnostic transport (`can_*`)

* **Entries:** `can_diag_object_init` 0xC019D6, `can_rx_process` 0xC01A1C,
  `can_rx_dispatch` 0xC01B22, `can_isotp_send` 0xC01C6E,
  `can_tx_frame` 0xC01CC8.
* **Inputs:** TwinCAN message objects 9/10; IDs 0x7EE/0x7EF (init) and
  0x7E0/0x7E4 (object 0); message data at 0xF740.
* **Operation:** copy an 8-byte CAN frame into the transport state, decode the
  small-frame header fields, send up to 8 bytes, set TXRQ/confirm bits.
* **Outputs:** `can_tx_staging` 0xC3750, CAN message objects, KWP payload.
* **Evidence:** TwinCAN register writes, object ID values, buffer copies,
  `can_transport_t` fields.
* **Confidence:** high for object IDs and transport mechanics; the exact
  ISO-TP multi-frame behavior is only partially recovered.

## 9. CAPCOM CC16/CC17 event scheduling (`event_*`)

* **Entries:** `event_init` 0xC0D528, `event_start` 0xC0D39E,
  `event_schedule` 0xC0DC8A, `event_schedule_duration` 0xC0E27C,
  `event_force` 0xC0DBDE, `event_cancel` 0xC0DC62, `event_idle` 0xC0E1B6,
  `event_accum` 0xC0E236.
* **State:** `cc16_17_channels` at 0xC410, two 0x12-byte channels:
  start time, 32-bit duration, 32-bit accumulator, flags, CC channel ID
  (0x10/0x11), compare value, control.
* **Time base:** `t7_timestamp` 0xC1064C and `t7_timestamp_extended` 0xC106E6;
  `t7_snapshot` 0xC3FC; `cc_compare_mode_shadow` 0xC402.
* **Operation:** compute a compare value from T7 and the channel duration,
  program `CC16`/`CC17`, enable the CC interrupt, accumulate elapsed time.
* **Outputs:** CC16/CC17 compare registers, `cc16_17_channels` fields.
* **Evidence:** 0x12 stride field accesses, CC16/CC17 SFR writes, event
  scheduler arithmetic.
* **Confidence:** high for scheduling mechanics. live-data separates injector time
  (`FPWVC1/2`) from spark dwell (`SPDWELL`) and spark advance (`SAESTA`), and
  log correlations support injection + ignition; the exact channel assignment
  remains inferred.

## 10. CC22/CC23 actuator/test output (`cc22_23_*`)

* **Entries:** `test_command_dispatch` 0xC13D5E, `cc22_23_start_once`
  0xC0FB36, `cc22_23_start_pair` 0xC0FACE, `cc22_23_schedule` 0xC0BE6A,
  `cc22_23_output_init` 0xC0BF02, `cc22_23_output_disable` 0xC0BE46,
  `cc22_23_task` 0xC0F3D2.
* **Inputs:** `test_command` 0xFD18 bit 0; `cc22_23_state_machine_a/b`
  0xC450/0xC454; external inputs 0x7046/0x7048.
* **Operation:** schedule compare values for CC22/CC23, enable outputs, run
  two hysteresis state machines, age timeouts.
* **Outputs:** CC22/CC23 compare registers, `cc22_23_channels` 0xC3D2,
  `output_gate_*` 0xFD08/0xFD06.
* **Evidence:** CC22/CC23 SFR writes, 0x1A stride channel accesses, test command
  bit 0 dispatch.
* **Confidence:** high that this is an actuator/test pair; not the normal
  injection/ignition scheduler.

## 11. Speed/timing conversion (`speed_timing_calc`)

* **Entry:** `speed_timing_calc` 0xC0CD24.
* **Inputs:** `engine_speed_input` 0xC9D0; axis `axis_speed_capture` 0x7000;
  calibration tables 0x504C and 0x5038.
* **Operation:** `index = axis16_unsigned(0x7000, engine_speed_input)`;
  `speed_table_504c = tbl16(0x504C, index)`;
  `speed_table_5038 = tbl16(0x5038, index)`.
* **Outputs:** `speed_axis_index` 0xC254, `speed_table_504c` 0xC274,
  `speed_table_5038` 0xC26E.
* **Evidence:** exact calls and table addresses in the function.
* **Confidence:** high.

## 12. Load/base calculation (`calc_load`)

* **Entry:** `calc_load` 0xC1FD9C.
* **Inputs:** `engine_speed_input` 0xC9D0, `calc_input_y` 0xCA2A,
  `calc_input_correction` 0xC97C; axes 0x7564/0x755E; map 0xC0794A;
  correction curve 0xC079B6.
* **Operation:** `x = axis16(0x7564, speed)`, `y = axis16(0x755E, y_input)`,
  `base = tbl2d(0xC0794A, x, y)`, `corr = tbl8(0xC079B6, corr_input)`,
  `result = (base * corr) >> 15`.
* **Outputs:** `load_calc_result` 0xE008B2; also `limit_value_0` 0xE008A0.
* **Evidence:** exact table addresses and arithmetic; 9x9 map shape verified.
  the live-data profile's `FVE1` field and a 1-cylinder MT05.2 log identify the result as volume
  efficiency: map max 244 -> 95.31%, log max 95.20%; warm correction 0x80 gives
  `result = map/2`; live-data raw `FVE1` = result * 256.
* **Confidence:** high for VE/load; exact normalized unit remains raw counts.

## 13. Limit calculations (`calc_limit1/2/3`)

* **Entries:** `calc_limit1` 0xC200AA, `calc_limit2` 0xC201AE,
  `calc_limit3` 0xC202EE.
* **Inputs:** `engine_state` 0xC93C, `engine_speed_input` 0xC9D0,
  `calc_input_x/z/w` 0xC958/0xC936/0xC06A, counters 0xC86A/6C/6E.
* **Tables:** 0xC0784C/0xC07860/0xC07874/0xC078D8/0xC078E2/0xC07912.
* **Outputs:** `limit_flag_0/1/2` 0xC884/5/6, `speed_limit_active` 0xE008A2,
  `limit_value_*` 0xE008A0/AA/AC/A4/A6/B0.
* **Operation:** select a base limit from a table, apply a multiplier or
  threshold, set the limit-active flags with hysteresis.
* **Evidence:** table addresses, state branches, flag writes, comparison with
  `cal_speed_limit_threshold` 0xC0781E.
* **Confidence:** high for the mechanics; which path is the hard rev limiter
  remains an inference. `calc_limit2` is the strongest candidate because it
  directly consumes `engine_speed_input` and the 0x1450 threshold.

## 14. PWM calculation (`pwm_period_duty_calc`)

* **Entries:** `pwm_init` 0xC108CE, `pwm_period_duty_calc` 0xC10A74,
  `pwm_output_enable` 0xC10AFC, `div32_checked` 0xC1096E,
  `mul_div32` 0xC109A2.
* **Inputs:** `pwm_divisor` 0xC504, `pwm_duty_calc` 0xC4EA; PWM config values
  0xE8A0..0xE8CE.
* **Operation:** 32-bit multiply/divide, float helpers for scaling, write
  `pwm_period` 0xE892, `pwm_duty` 0xE8A2, `pwm_control` 0xE8A6.
* **Outputs:** CAPCOM6/PWM registers and XRAM config values.
* **Evidence:** exact calls and register writes.
* **Confidence:** high for the arithmetic flow; the output pin mapping is
  inferred.

## 15. Software float runtime (`fp_*`, `div32u`)

* **Entries:** `fp_load`/`fp_store`/`fp_copy`/`fp_pack`/`fp_pack_zero`/
  `fp_round`/`fp_neg`/`fp_compare`/`fp_to_int`/`fp_div_signed`/
  `fp_div_unsigned`; `div32u`; `store32`.
* **Representation:** four 16-bit words per value (8 bytes). Load/store/copy
  move exactly four words. Exponent/mantissa bit operations are visible in the
  pack/unpack/round helpers.
* **Operation:** software arithmetic used by `config_sensor_setup` and PWM.
* **Evidence:** four-word moves; exponent masks 0x7FF0/0x3FE/0x40E; sign bit
  toggles; division loops.
* **Confidence:** high that this is a software float runtime; the exact format
  is not claimed to be IEEE-754.

## 16. Input debounce/sampling (`input_debounce_sample`)

* **Entry:** 0xC10242.
* **Inputs:** P1L bits 0x40/0x01/0x04/0x20.
* **State:** `input_state_bits` 0xC49A, `input_low_bits` 0xC49C,
  `input_high_bits` 0xC4B6.
* **Operation:** sample selected pins, update a stable state and two edge
  accumulators.
* **Evidence:** exact pin masks and state writes.
* **Confidence:** high.

## 17. Diagnostic status build (`diag_status_build`)

* **Entry:** 0xC1482C.
* **Inputs:** ~40 status flags, including `engine_state` 0xC93C and many
  `diag_flag_*`/`diag_input_*` variables.
* **Operation:** pack flags into five bytes `diag_status_byte1..4`
  (0xC60C..0xC610).
* **Evidence:** exact bit shifts and source addresses.
* **Confidence:** high for the packing; the physical meaning of each flag is
  not recovered.

## 18. Calibration accessors

* **Entries:** `axis16_unsigned` 0xC2850E, `axis16_signed` 0xC284D8,
  `tbl8_interp` 0xC27FCA, `tbl16_interp` 0xC27CA4,
  `tbl2d_interp` 0xC2826E.
* **Formats:** axis {count,min,max}; 8-bit {count,shift,data}; 16-bit
  {count,data}; 2D {cols,rows,shift,data}.
* **Evidence:** exact header reads and interpolation arithmetic; table shapes
  verified.
* **Confidence:** high.

## 19. Adaptation log scan (data structure, not code)

* **Range:** 0xC04000–0xC04CFF.
* **Record:** 0x200 bytes: sequence, payload, `5A A5`, 16-bit tail.
* **Evidence:** six 0x200 records plus one 0x100 record; sequence progression
  between dumps.
* **Confidence:** high for layout; tail-value checksum and physical storage
  remain unknown.

## 20. Scheduler (`app_scheduler`)

* **Entries:** `app_scheduler` 0xC11EB4, `scheduler_tick` 0xC11EEC.
* **Inputs:** `scheduler_event_flag` 0xFD14, task state 0xC584, task table
  0x705E, counter table 0x7088.
* **Operation:** wait for the event flag, service watchdog, increment tick,
  run periodic hooks, dispatch a task, pack diagnostics.
* **Outputs:** task invocation, `diag_status_*`.
* **Evidence:** scheduler loop, table lookups, periodic call list.
* **Confidence:** high for the scheduler structure; task table contents are in
  external RAM and not in the dump.
