# Function catalog

Full catalog: `FUNCTIONS.csv` (902 functions). Generated from the C166SV2
listing and decompilation. `confidence` is evidence strength, not a claim
that every low-confidence name is a proven role.

## Areas

| Area | Functions |
|---|---:|
| `00-reset` | 1 |
| `01-boot` | 81 |
| `02-hidden-boot` | 26 |
| `04-kline-kwp` | 12 |
| `05-can` | 1 |
| `06-ssc` | 8 |
| `07-diagnostics` | 2 |
| `08-io-timing` | 36 |
| `09-engine-calc` | 269 |
| `10-math` | 42 |
| `11-adaptation` | 2 |
| `12-app-low` | 245 |
| `13-app-io` | 159 |
| `14-app-runtime` | 18 |

## Confidence

| Confidence | Functions |
|---|---:|
| high | 220 |
| medium | 340 |
| low | 342 |

## High/medium confidence

| Address | Name | Confidence | Evidence |
|---|---|---|---|
| `0xC00000` | `reset_vector` | high | far jump at the reset vector; targets boot_reset |
| `0xC00200` | `boot_main` | high | Boot-block main: checks magic/checksums, selects app or bootloader. |
| `0xC002DC` | `boot_periph_init` | high | Boot peripheral initialization wrapper. |
| `0xC0030E` | `boot_bus_mode` | high | External bus mode configuration based on SYSCON bits. |
| `0xC0037E` | `checksum16_be` | high | 16-bit sum of big-endian words over a flash range. |
| `0xC003B8` | `delay_loop` | high | Simple delay loop. |
| `0xC003C2` | `delay_ticks` | high | Delay loop parameterized by r12. |
| `0xC003DE` | `boot_minimal_main` | high | Reduced boot path used when configuration ADC check selects it. |
| `0xC003F0` | `bootloader_entry` | high | Bootloader/test loop; bit-bangs P1L.6 and waits on P1L.4. |
| `0xC00428` | `boot_timer_a_init` | medium | boot gap block; timer setup |
| `0xC00434` | `can_twincan_init` | high | TwinCAN initialization; message object 0 ID 0x7E0/0x7E4 (diagnostic). |
| `0xC00694` | `can0_isr` | high | CAN0 interrupt handler; processes message object 0 and calls can_rx_process. |
| `0xC0077C` | `boot_timer_b_setup` | medium | boot gap block; timer/compare setup |
| `0xC00898` | `boot_ssc_rx_setup` | medium | boot gap; SSC pointer setup |
| `0xC00904` | `boot_cinit` | high | Boot-block C runtime init (zero/init tables). |
| `0xC00A78` | `boot_reset` | high | Reset vector: watchdog, stack, DPPs, self-test, then boot_main. |
| `0xC00C30` | `boot_idle` | medium | boot gap; single idle/rets block |
| `0xC00C36` | `asc0_init` | high | ASC0 (UART/K-line) initialization; S0BG, S0CON, port setup. |
| `0xC00C84` | `asc0_tx_byte` | high | Writes one byte to the ASC0 transmit buffer S0TBUF. |
| `0xC00C8A` | `asc0_read_rx_clear` | high | Clears the ASC0 receive flag and returns one S0RBUF byte. |
| `0xC00C92` | `boot_timer_clear_stub` | medium | boot gap; short timer clear |
| `0xC00CA2` | `capcom_timer_init` | high | CAPCOM/T0/T7/T8 timer initialization. |
| `0xC00D34` | `timer7_isr` | high | Timer7 interrupt: ASC0 state machine + KWP dispatcher, 1 ms tick. |
| `0xC00DAA` | `boot_fill_words` | medium | boot gap; word initialization |
| `0xC00DAE` | `boot_port_adc_init` | high | Boot-block port/ADC-related register initialization. |
| `0xC00DDA` | `boot_fill_bytes` | medium | boot gap; byte initialization |
| `0xC00DDC` | `asc0_pin_init` | high | ASC0 alternate-function pin setup. |
| `0xC00E08` | `ssc_send_byte` | high | Write one byte to SSC transmit buffer. |
| `0xC00E14` | `ssc0_rx_isr` | high | SSC0 receive interrupt; 7-byte frame engine. |
| `0xC00ECA` | `ssc_start_frame` | high | Start SSC transfer with 7-byte buffer. |
| `0xC00EE8` | `boot_extint_init` | high | Boot external-interrupt init: bus mode, EXICON, T1IC. |
| `0xC00F0C` | `trap_stack_overflow` | high | Stack overflow trap handler. |
| `0xC00F6A` | `trap_stack_underflow` | high | Stack underflow trap handler. |
| `0xC00FC8` | `trap_bootstrap` | high | Bootstrap trap handler. |
| `0xC01048` | `pll_isr` | high | PLL/oscillator watchdog interrupt; performs software reset. |
| `0xC01080` | `clock_init` | high | Clock/PLL and port initialization. |
| `0xC01130` | `boot_capture_vector_stub` | medium | boot gap; capture setup |
| `0xC01144` | `asc0_state_dispatch` | high | Dispatch ASC0 K-line state 0..5 through table at 0xC00428. |
| `0xC01158` | `asc0_task0` | high | K-line state 0 wrapper. |
| `0xC0115E` | `asc0_task1` | high | K-line state 1 wrapper. |
| `0xC01164` | `asc0_task2` | high | K-line state 2 wrapper. |
| `0xC0116A` | `asc0_task3` | high | K-line state 3 wrapper. |
| `0xC01170` | `asc0_task4` | high | K-line state 4 wrapper. |
| `0xC01176` | `asc0_task5` | high | K-line state 5 wrapper. |
| `0xC01182` | `asc0_clear_state` | high | Clear ASC0/K-line state. |
| `0xC01188` | `asc0_state0` | high | K-line state 0: idle / start. |
| `0xC0119E` | `asc0_state1` | high | K-line state 1: wake-up / 5-baud handling. |
| `0xC011D6` | `asc0_state2` | high | K-line state 2: receive frame bytes. |
| `0xC01212` | `kline_receive_pattern` | high | Receives the 5-byte K-line wake-up pattern and advances state. |
| `0xC01218` | `asc0_state2_init` | high | Initialize K-line receive frame. |
| `0xC01252` | `asc0_state3` | high | K-line state 3: receive/validate. |
| `0xC012E6` | `asc0_state4` | high | K-line state 4: transmit response. |
| `0xC013E8` | `asc0_state5` | high | K-line state 5: finish. |
| `0xC01482` | `kwp_dispatch` | high | KWP2000 service dispatcher (0x10/0x23/0x27/0x31/0x34/0x36/0x38/0x3D/0x83). |
| `0xC0151C` | `kwp_sid81` | high | KWP service 0x81 handler (start communication). |
| `0xC01544` | `kwp_sid27_security` | high | KWP service 0x27 security access; fixed seed 0x1234, key 0x8474. |
| `0xC015DA` | `kwp_negative` | high | KWP negative response / unsupported service. |
| `0xC015F8` | `kwp_sid10_session` | high | KWP service 0x10 start diagnostic session. |
| `0xC0166A` | `kwp_sid83` | high | KWP service 0x83 handler (Delphi-specific). |
| `0xC016C2` | `kwp_sid34_download` | high | KWP service 0x34 request download. |
| `0xC0170A` | `kwp_sid36_transfer` | high | KWP service 0x36 transfer data (0x80-byte blocks to flash/RAM). |
| `0xC017A8` | `kwp_sid31_routine` | high | KWP service 0x31 start routine. |
| `0xC017EA` | `kwp_sid38` | high | KWP service 0x38 handler. |
| `0xC01840` | `kwp_sid23_read_mem` | high | KWP service 0x23 read memory by address. |
| `0xC0190C` | `kwp_sid3D_write_mem` | high | KWP service 0x3D write memory by address. |
| `0xC019D6` | `can_diag_object_init` | high | Initializes TwinCAN message objects 9/10 with IDs 0x7EE/0x7EF. |
| `0xC01A1C` | `can_rx_process` | high | TwinCAN receive processing and message-object copy. |
| `0xC01AD4` | `can_bootloader_wait` | high | Initializes CAN diagnostic objects and enters the boot wait loop. |
| `0xC01B22` | `can_rx_dispatch` | high | Dispatch received CAN message to ISO-TP transport. |
| `0xC01BE4` | `can_rx_cmd` | high | CAN diagnostic receive command handling. |
| `0xC01C6E` | `can_isotp_send` | high | Send up to 8 bytes over the diagnostic CAN message object. |
| `0xC01CC8` | `can_tx_frame` | high | Load and transmit one 8-byte CAN frame. |
| `0xC01D9A` | `memcpy_wdt` | high | Byte copy with watchdog service. |
| `0xC01DC2` | `boot_clock_check` | medium | boot gap; reads 0x450 clock/config constant |
| `0xC01DEC` | `can_tx_confirm` | high | Set CAN message object transmission-request/confirm bits. |
| `0xC01EC0` | `boot_atomic_stub` | medium | boot gap; atomic sequence |
| `0xC01EC8` | `ret_stub` | high | Empty function. |
| `0xC01ECE` | `mem_read_word` | high | Read two words through a 16:16 pointer. |
| `0xC01EDC` | `mem_write_word` | high | Write two words through a 16:16 pointer. |
| `0xC01EEA` | `seg_to_ptr` | high | Convert 16-bit pointer/DPP offset into a 24-bit pointer. |
| `0xC01F00` | `boot_fill_page` | medium | boot gap; zero-fill helper |
| `0xC02000` | `boot_hidden_main` | high | entry of hidden boot/test block; polls external 0xE00000 |
| `0xC020C0` | `boot_hidden_copy_tail` | medium | hidden boot copy tail |
| `0xC020C4` | `boot_hidden_copy` | high | copy helper in hidden block; ends at c02108 |
| `0xC0210A` | `boot_hidden_memcpy` | high | byte copy with SRVWDT; called by boot_hidden_main |
| `0xC02132` | `boot_hidden_pin_stub` | medium | hidden boot pin helper |
| `0xC02140` | `boot_hidden_periph` | high | port/PICON/BUSCON init; writes 0xF120/0xF126/0xF128 |
| `0xC021DE` | `boot_hidden_cmd_decode` | medium | hidden boot command decode |
| `0xC02250` | `boot_hidden_xram_init` | high | initializes XRAM 0xE892..0xE8CE |
| `0xC022FC` | `boot_hidden_xram2` | high | XRAM setup helper in hidden block |
| `0xC0231E` | `boot_hidden_xram3` | high | XRAM setup helper in hidden block |
| `0xC02430` | `boot_hidden_task_dispatch` | medium | hidden boot task dispatch |
| `0xC0248A` | `boot_hidden_task` | high | command/task helper in hidden block |
| `0xC02A46` | `boot_hidden_eeprom_tail` | medium | hidden boot EEPROM tail |
| `0xC02B76` | `boot_hidden_eeprom` | high | serial/EEPROM helper in hidden block |
| `0xC02DDC` | `boot_hidden_serial_loop` | medium | hidden boot serial/EEPROM loop |
| `0xC03A04` | `boot_hidden_serial_cmd` | medium | hidden boot serial command helper |
| `0xC03CB8` | `boot_hidden_i2c_a` | high | bit/byte serial helper in hidden block |
| `0xC03CD0` | `boot_hidden_i2c_b` | high | bit/byte serial helper in hidden block |
| `0xC03DD4` | `boot_hidden_atomic_stub` | medium | hidden boot atomic helper |
| `0xC03DDC` | `boot_hidden_delay` | high | delay helper in hidden block |
| `0xC03DE2` | `boot_hidden_store32` | high | 32-bit store helper in hidden block |
| `0xC03DF8` | `boot_hidden_final` | medium | hidden boot final helper |
| `0xC0BA9E` | `set_can_flag` | high | Set CAN/application flag. |
| `0xC0BAB4` | `sat_add_s16_wrapper_c0bab4` | medium | calls sat_add_s16_wrapper_c1ac7c (0xC1AC7C) |
| `0xC0BB54` | `update_event_offset_3` | medium | writes event_offset_3/0 |
| `0xC0BBC4` | `capcom_event_config2` | high | Configure one CAPCOM event channel (second form). |
| `0xC0BC44` | `math_div_32_b_wrapper_c0bc44` | medium | calls math_div_32_b (0xC0DF4C) |
| `0xC0BC74` | `math_div_32_b_wrapper_c0bc74` | medium | calls math_div_32_b (0xC0DF4C) |
| `0xC0BCA4` | `capcom_event_config` | high | Configure one CAPCOM event channel. |
| `0xC0BD54` | `p1l1_set` | high | Sets port P1L.1. |
| `0xC0BD58` | `capcom16_17_init` | high | CAPCOM CC16/CC17 channel setup. |
| `0xC0BDA2` | `timer4_init` | high | Timer T4 initialization. |
| `0xC0BDC8` | `command_wrapper_c0bdc8` | medium | calls command_wrapper_c14824 (0xC14824) |
| `0xC0BE46` | `cc22_23_output_disable` | high | Clears the CC22/CC23 output-enable bits in CCM5. |
| `0xC0BE6A` | `cc22_23_schedule` | high | Programs the CC22/CC23 compare values from a T7 timestamp. |
| `0xC0BEF0` | `cc_control_ptr_init` | high | Caches pointers to 0xFF2C and 0xFE2A. |
| `0xC0BF02` | `cc22_23_output_init` | high | Initializes CC22/CC23 interrupt/port/compare pointers. |
| `0xC0BF40` | `timer6_init` | high | Timer T6 initialization. |
| `0xC0BF54` | `cc_irq_enable` | high | Sets or clears a per-channel CC interrupt-enable bit. |
| `0xC0BF8C` | `cc_irq_is_enabled` | high | Tests a per-channel CC interrupt-enable bit in 0xFF2C. |
| `0xC0BFCC` | `update_security_unlocked_helper_c0bfcc` | medium | called only by update_security_unlocked_wrapper_c19766 (0xC19766) |
| `0xC0BFD2` | `app_clear_flag` | high | Clear application flag. |
| `0xC0BFE2` | `app_run` | high | Application run entry. |
| `0xC0BFF4` | `empty_stub_1` | high | Empty function. |
| `0xC0BFF6` | `empty_stub_2` | high | Empty function. |
| `0xC0C5DE` | `update_capture_speed_state_helper_c0c5de` | medium | called only by update_capture_speed_state (0xC0CADA) |
| `0xC0C65A` | `update_input_status_flags_c0c65a` | medium | writes input_status_flags |
| `0xC0C6F2` | `update_input_status_flags_dispatch_c0c6f2` | medium | calls update_input_status_flags_c0c65a,empty_stub_0 |
| `0xC0C8E2` | `update_capture_state` | medium | writes capture_state/capture_enable |
| `0xC0CAC2` | `watchdog_pin` | high | Watchdog/port pin control. |
| `0xC0CADA` | `update_capture_speed_state` | medium | writes capture_state/speed flags |
| `0xC0CD24` | `speed_timing_calc` | high | Maps engine speed input 0xC9D0 through axis 0x7000 and tables 0x504C/0x5038. |
| `0xC0CDFA` | `timer5_init` | high | Timer T5/ASC0 error init. |
| `0xC0CEA2` | `capcom_start` | high | Start CAPCOM/T7/T8 time base. |
| `0xC0CF18` | `command_wrapper_c0cf18` | medium | calls command_wrapper_c11f10 (0xC11F10) |
| `0xC0CF48` | `update_capture_speed_state_wrapper_c0cf48` | medium | calls update_capture_speed_state (0xC0CADA) |
| `0xC0D010` | `update_t7_offset_short` | medium | writes T7 offset |
| `0xC0D040` | `update_input_status_flags_wrapper_c0d040` | medium | calls update_input_status_flags_dispatch_c0c6f2 (0xC0C6F2) |
| `0xC0D076` | `math_mul_div_32_b_wrapper_c0d076` | medium | calls math_mul_div_32_b (0xC0D5CA) |
| `0xC0D082` | `update_output_gate_1_wrapper_c0d082` | medium | calls update_output_gate_1 (0xC0EE3C) |
| `0xC0D08E` | `update_output_gates_wrapper_c0d08e` | medium | calls update_output_gates (0xC0EF4A) |
| `0xC0D094` | `update_output_gate_1_b_wrapper_c0d094` | medium | calls update_output_gate_1_b (0xC0F032) |
| `0xC0D09A` | `update_app_flags_wrapper_c0d09a` | medium | calls update_app_flags (0xC0F2B8) |
| `0xC0D0A0` | `update_app_flag_wrapper_c0d0a0` | medium | calls update_app_flag (0xC0F378) |
| `0xC0D0B2` | `cc_irq_is_enabled_wrapper_c0d0b2` | medium | calls cc_irq_is_enabled_dispatch_c0f132 (0xC0F132) |
| `0xC0D0E0` | `capcom_event_config2_wrapper_c0d0e0` | medium | calls capcom_event_config2 (0xC0BBC4) |
| `0xC0D296` | `update_capture_speed_state_helper_c0d296` | medium | called only by update_capture_speed_state (0xC0CADA) |
| `0xC0D2E4` | `math_mul_div_32` | medium | calls mul32/div32u |
| `0xC0D314` | `math_mul_div_32_wrapper_c0d314` | medium | calls math_mul_div_32 (0xC0D2E4) |
| `0xC0D39E` | `event_start` | high | Start event scheduler channels. |
| `0xC0D516` | `event_reset` | high | Reset event scheduler state. |
| `0xC0D528` | `event_init` | high | Initialize event scheduler channels. |
| `0xC0D562` | `angle_init` | high | Initialize angle/time conversion from calibration. |
| `0xC0D5CA` | `math_mul_div_32_b` | medium | calls mul32/div32u |
| `0xC0D6F0` | `event_start_fixed` | high | Loads fixed event parameters and starts the CC16/CC17 scheduler. |
| `0xC0D70A` | `update_capture_state_helper_c0d70a` | medium | called only by update_capture_state (0xC0C8E2) |
| `0xC0D71E` | `math_div_32` | medium | calls div32u |
| `0xC0D956` | `math_div_32_wrapper_c0d956` | medium | calls math_div_32 (0xC0D71E) |
| `0xC0D9E4` | `ssc_init` | high | SSC/CC26 initialization; installs handlers at 0xC0D8FA and 0xC0D914. |
| `0xC0DA62` | `cc26_ptr_init` | high | Stores CC26/CCM6/CC26IC pointers used by the SSC timing path. |
| `0xC0DA8C` | `dtc_status_bit5_wrapper_c0da8c` | medium | calls dtc_status_bit5 (0xC243A8) |
| `0xC0DB90` | `cc_irq_enable_bit` | high | Enables the CC16/CC17 interrupt bit for a channel ID. |
| `0xC0DBA6` | `cc_compare_mode_set` | high | Sets the CC16/CC17 compare-mode bit for a channel ID. |
| `0xC0DBDE` | `event_force` | high | Force event at fixed offset. |
| `0xC0DC62` | `event_cancel` | high | Cancel/initialize one event channel. |
| `0xC0DC8A` | `event_schedule` | high | Schedule CAPCOM event (dwell/pulse) for a channel. |
| `0xC0DF4C` | `math_div_32_b` | medium | calls div32u |
| `0xC0E1B6` | `event_idle` | high | Set channel to idle. |
| `0xC0E236` | `event_accum` | high | Accumulate event time. |
| `0xC0E27C` | `event_schedule_duration` | high | Schedules a CC16/CC17 event using the 32-bit duration fields. |
| `0xC0E3DA` | `cc_irq_enable_bit_wrapper_c0e3da` | medium | calls cc_irq_enable_bit (0xC0DB90) |
| `0xC0E722` | `cc22_23_hysteresis_a` | high | Hysteresis thresholds for the first CC22/CC23 input; state in cc22_23_state_machine_a. |
| `0xC0E760` | `cc22_23_hysteresis_b` | high | Hysteresis thresholds for the second CC22/CC23 input; state in cc22_23_state_machine_b. |
| `0xC0E7CA` | `update_app_helper_c0e7ca` | medium | called by update_app_flags,update_app_flag |
| `0xC0E7EC` | `update_output_helper_c0e7ec` | medium | called by update_output_gates,update_output_gate_1_b |
| `0xC0E830` | `math_div_32_c` | medium | calls div32u |
| `0xC0E894` | `update_output_gate_1_helper_c0e894` | medium | called only by update_output_gate_1 (0xC0EE3C) |
| `0xC0EBE6` | `cc_output_gate_update` | high | Updates the CC output gate bits in 0xFD08/0xFD06. |
| `0xC0ECE6` | `update_output_gate_1_helper_c0ece6` | medium | called only by update_output_gate_1 (0xC0EE3C) |
| `0xC0EE3C` | `update_output_gate_1` | medium | writes output gate |
| `0xC0EF4A` | `update_output_gates` | medium | writes output gates |
| `0xC0F032` | `update_output_gate_1_b` | medium | writes output gate |
| `0xC0F0E6` | `app_low_helper_c0f0e6` | medium | called by cc_irq_is_enabled_dispatch_c0f132,t7_timestamp_wrapper_c0f482 |
| `0xC0F132` | `cc_irq_is_enabled_dispatch_c0f132` | medium | calls cc_irq_is_enabled,math_div_32_c,t7_timestamp |
| `0xC0F2B8` | `update_app_flags` | medium | writes app flag/gates |
| `0xC0F32C` | `t7_timestamp_dispatch_c0f32c` | medium | calls t7_timestamp_wrapper_c0f482,cc22_23_schedule_dispatch_c0f97a |
| `0xC0F378` | `update_app_flag` | medium | writes app flag/gate |
| `0xC0F3D2` | `cc22_23_task` | high | Periodic task for the CC22/CC23 event pair; uses engine speed/timing input 0xC9D0. |
| `0xC0F476` | `t7_timestamp_helper_c0f476` | medium | called only by t7_timestamp_wrapper_c0f482 (0xC0F482) |
| `0xC0F482` | `t7_timestamp_wrapper_c0f482` | medium | calls t7_timestamp (0xC1064C) |
| `0xC0F55A` | `app_low_helper_c0f55a` | medium | callers/callees update_output_gate_0,update_output_gate_1_c,update_output_gate_0_b,update_output_gate_1_d,update_capture_status_b |
| `0xC0F628` | `config_sensor_setup` | high | Selects sensor/ADC handler pointers from calibration config 0xC05036 and builds a float threshold. |
| `0xC0F842` | `update_output_gate_0` | medium | writes output gate |
| `0xC0F8DE` | `update_output_gate_1_c` | medium | writes output gate |
| `0xC0F97A` | `cc22_23_schedule_dispatch_c0f97a` | medium | calls cc22_23_schedule,cc_irq_is_enabled,t7_timestamp |
| `0xC0FA8E` | `update_output_gate_0_b` | medium | writes output gate |
| `0xC0FA98` | `update_output_gate_1_d` | medium | writes output gate |
| `0xC0FAA2` | `update_cc22_23_started` | medium | writes CC22/23 started |
| `0xC0FACE` | `cc22_23_start_pair` | high | Starts both CC22/CC23 channels at a common timestamp. |
| `0xC0FAF8` | `update_cc22_23_started_b` | medium | writes CC22/23 started |
| `0xC0FB36` | `cc22_23_start_once` | high | One-shot start of the CC22/CC23 pair. |
| `0xC0FB6E` | `timer6_start` | high | Start timer T6. |
| `0xC0FB8C` | `cc_event_timeout_tick` | high | Decrements the CC event timeout counters. |
| `0xC0FBCC` | `update_capture_status_b_wrapper_c0fbcc` | medium | calls update_capture_status_b (0xC0FD82) |
| `0xC0FC42` | `update_capture_status` | medium | writes capture status |
| `0xC0FC90` | `ssc_state_reset` | high | Reset SSC state. |
| `0xC0FCA6` | `update_cc_event_timeout` | medium | writes CC event timeout |
| `0xC0FD82` | `update_capture_status_b` | medium | writes capture status |
| `0xC0FE0C` | `cc22_23_schedule_helper_c0fe0c` | medium | called only by cc22_23_schedule_dispatch_c0f97a (0xC0F97A) |
| `0xC0FE7E` | `ssc_pin_config` | high | SSC/port configuration. |
| `0xC0FEAE` | `ssc_mode_select` | high | Select SSC mode from calibration byte 0xC05036. |
| `0xC0FF00` | `ssc0_init_app` | high | Application SSC0 initialization. |
| `0xC0FF28` | `ssc_send` | high | Send one SSC byte. |
| `0xC0FF34` | `ssc_send_wrapper_c0ff34` | medium | calls ssc_send (0xC0FF28) |
| `0xC0FFC0` | `ssc_rx_start` | high | Start SSC receive engine. |
| `0xC0FFDE` | `app_main` | high | Application main entry. |
| `0xC0FFEE` | `math_div_32_d_wrapper_c0ffee` | medium | calls math_div_32_d_wrapper_c13e94 (0xC13E94) |
| `0xC10000` | `app_entry` | high | Application far-call entry trampoline; jumps to app_cstart. |
| `0xC10200` | `ssc_rx_queue_init` | high | SSC receive queue initialization. |
| `0xC10240` | `empty_stub_3` | high | Empty function. |
| `0xC10242` | `input_debounce_sample` | high | Samples P1L pins and updates input_state_bits/input_low_bits/input_high_bits. |
| `0xC102DC` | `update_ssc_control_flags` | medium | writes SSC control flags |
| `0xC10342` | `ssc_task` | high | Periodic SSC task: start transfer, timeout, sample port. |
| `0xC10370` | `adc_start` | high | Start ADC conversion; selects pin mode from calibration. |
| `0xC10398` | `math_div_32_d_helper_c10398` | medium | called only by math_div_32_d_wrapper_c13e12 (0xC13E12) |
| `0xC103C0` | `port_bus_init` | high | Application port and external-bus initialization. |
| `0xC105EC` | `adc_calibrate` | high | ADC calibration/start. |
| `0xC10618` | `update_scheduler_event_flag` | medium | writes scheduler event flag |
| `0xC1064C` | `t7_timestamp` | high | Returns a short T7 timestamp with overflow extension. |
| `0xC106E6` | `t7_timestamp_extended` | high | Returns a T7 timestamp extended by the T7 overflow flag. |
| `0xC1072A` | `timer8_init` | high | Timer T8/CAPCOM init. |
| `0xC1078C` | `math_mul_div_32_d` | medium | calls mul32/div32u |
| `0xC108B4` | `timeout_counter_tick` | high | Increments timeout_counter and clears timeout_value_0/1 at 0x81. |
| `0xC108CE` | `pwm_init` | high | PWM/CAPCOM6 initialization. |
| `0xC1096E` | `div32_checked` | high | Checked 32-bit division; returns 0xFFFFFFFF on overflow/zero. |
| `0xC109A2` | `mul_div32` | high | 32-bit multiply followed by checked division. |
| `0xC10A74` | `pwm_period_duty_calc` | high | Computes PWM period/duty from the 32-bit division result. |
| `0xC10AFC` | `pwm_output_enable` | high | Enables the PWM output (PWMCON0 and P1L.4). |
| `0xC10B0C` | `math_div_32_d` | medium | calls div32u |
| `0xC1105E` | `load_axis_pair_7052` | high | indexes 0x7052/0x7054 |
| `0xC1192C` | `app_cinit` | high | Application C runtime init table walker. |
| `0xC11AA0` | `app_cstart` | high | Application C runtime startup; copies init data then calls app_main. |
| `0xC11B2A` | `can_bus_config` | high | CAN bus pin/mode configuration. |
| `0xC11B9A` | `cal_checksum` | high | Verify calibration block checksum 0xC05000-0xC0AFFD vs 0xC0AFFE. |
| `0xC11BF4` | `app_hw_init` | high | Application hardware initialization sequence. |
| `0xC11C62` | `app_main_init` | high | Application main initialization; enters scheduler. |
| `0xC11CAE` | `app_idle_wait` | high | Scheduler idle/wait path. |
| `0xC11D98` | `update_kline_state` | medium | writes K-line/scheduler state |
| `0xC11DBA` | `update_kline_event_flag` | medium | writes scheduler event flag |
| `0xC11DD0` | `update_kline_event_flag_b` | medium | writes scheduler event flag |
| `0xC11E3C` | `update_kline_event_flag_c` | medium | writes scheduler event flag |
| `0xC11E94` | `update_kline_event_flag_d` | medium | writes scheduler event flag |
| `0xC11EB4` | `app_scheduler` | high | Application scheduler entry. |
| `0xC11EC6` | `app_scheduler_path` | high | Scheduler alternate path. |
| `0xC11EEC` | `scheduler_tick` | high | Increments the scheduler counter and dispatches command 3. |
| `0xC11F10` | `command_wrapper_c11f10` | medium | calls command_wrapper_c147ce (0xC147CE) |
| `0xC11F16` | `command_wrapper_c11f16` | medium | calls command_wrapper_c147d6 (0xC147D6) |
| `0xC11F1C` | `asc0_init_app` | high | Application ASC0/K-line initialization. |
| `0xC11F5A` | `update_kline_state_b_helper_c11f5a` | medium | called only by update_kline_state_b (0xC127A2) |
| `0xC11F60` | `asc0_read_rx_raw` | high | Returns one S0RBUF byte without changing the receive flag. |
| `0xC11F66` | `asc0_rx_handler` | high | ASC0 receive handler: reads S0RBUF and pushes the byte into the K-line ring. |
| `0xC11F9A` | `asc0_tx_handler` | high | ASC0 transmit/status handler for the K-line transport. |
| `0xC125F4` | `kline_start_timeout_helper_c125f4` | medium | called only by kline_start_timeout_wrapper_c13902 (0xC13902) |
| `0xC125FA` | `kline_start_timeout_helper_c125fa` | medium | called only by kline_start_timeout_wrapper_c13902 (0xC13902) |
| `0xC1267A` | `kline_start_timeout_helper_c1267a` | medium | called only by kline_start_timeout_wrapper_c13902 (0xC13902) |
| `0xC12696` | `kline_get_status` | high | Returns the K-line status byte 0xC56D. |
| `0xC126B0` | `kline_start_timeout` | high | Loads the K-line timeout 0xC56A with 0x0500. |
| `0xC126BC` | `kline_state_reset` | high | Clears K-line state to 0. |
| `0xC126D2` | `kline_rx_state_8_helper_c126d2` | medium | called only by kline_rx_state_8_wrapper_c12ca4 (0xC12CA4) |
| `0xC126DA` | `kline_prepare_frame` | high | Computes K-line timing fields and enters state 6. |
| `0xC127A2` | `update_kline_state_b` | medium | writes K-line state |
| `0xC12826` | `kline_rx_state_7` | high | K-line receive/transport state 7. |
| `0xC12848` | `kline_rx_state_8` | high | K-line receive/transport state 8. |
| `0xC12856` | `update_kline_state_c` | medium | writes K-line state |
| `0xC1293C` | `kline_push_rx_byte` | high | Stores a received K-line byte into the IRAM ring at 0xF600. |
| `0xC12982` | `kline_transport_task` | high | K-line transport state machine; state 0xC584 selects a handler table at 0x7164. |
| `0xC129D6` | `update_kline_timeout` | medium | writes K-line timeout |
| `0xC129E2` | `update_kline_state_c129e2` | medium | writes kline_state |
| `0xC12A16` | `kline_state_reset_dispatch_c12a16` | medium | calls kline_state_reset,kline_prepare_frame |
| `0xC12C92` | `kline_rx_state_8_wrapper_c12c92` | medium | calls kline_rx_state_8_helper_c126d2 (0xC126D2) |
| `0xC12CA4` | `kline_rx_state_8_wrapper_c12ca4` | medium | calls kline_rx_state_8 (0xC12848) |
| `0xC12D28` | `update_kline_flag_c57d_c12d28` | medium | writes kline_flag_c57d,kline_state |
| `0xC12EDE` | `kline_prepare_frame_wrapper_c12ede` | medium | calls kline_prepare_frame (0xC126DA) |
| `0xC12F46` | `update_kline_mode_c12f46` | medium | writes kline_mode,kline_state,kline_flag_c588 |
| `0xC13104` | `update_test_command` | medium | writes test command |
| `0xC13132` | `update_test_command_b` | medium | writes test command |
| `0xC13160` | `update_test_command_c` | medium | writes test command |
| `0xC1318E` | `update_test_command_d` | medium | writes test command |
| `0xC131CE` | `update_scheduler_event_flag_b_helper_c131ce` | medium | called only by update_scheduler_event_flag_b (0xC131D6) |
| `0xC131D6` | `update_scheduler_event_flag_b` | medium | writes scheduler event flag |
| `0xC132EC` | `update_scheduler_event_flag_b_wrapper_c132ec` | medium | calls update_scheduler_event_flag_b_helper_c131ce (0xC131CE) |
| `0xC13484` | `select_active_record_wrapper_c13484` | medium | calls select_active_record_helper_c244ce (0xC244CE) |
| `0xC13902` | `kline_start_timeout_wrapper_c13902` | medium | calls kline_start_timeout (0xC126B0) |
| `0xC13C70` | `update_test_command_wrapper_c13c70` | medium | calls update_test_command (0xC13104) |
| `0xC13C7A` | `update_test_command_b_wrapper_c13c7a` | medium | calls update_test_command_b (0xC13132) |
| `0xC13C84` | `update_test_command_c_wrapper_c13c84` | medium | calls update_test_command_c (0xC13160) |
| `0xC13D50` | `test_command_clear` | high | Clears the 0xFD18 command and its counters. |
| `0xC13D5E` | `test_command_dispatch` | high | Dispatches 0xFD18 actuator/test command bits. |
| `0xC13DC8` | `engine_calc_helper_c13dc8` | medium | called by update_calc_input_z,update_calc_input_z_b,calc_table_6c7a_b,calc_table_6d48 |
| `0xC13DE0` | `math_div_32_d_wrapper_c13de0` | medium | calls math_div_32_d_helper_c10398 (0xC10398) |
| `0xC13DEA` | `math_div_32_d_wrapper_c13dea` | medium | calls math_div_32_d_helper_c10398 (0xC10398) |
| `0xC13DF4` | `math_div_32_d_wrapper_c13df4` | medium | calls math_div_32_d_helper_c10398 (0xC10398) |
| `0xC13DFE` | `math_div_32_d_wrapper_c13dfe` | medium | calls math_div_32_d_helper_c10398 (0xC10398) |
| `0xC13E08` | `math_div_32_d_wrapper_c13e08` | medium | calls math_div_32_d_helper_c10398 (0xC10398) |
| `0xC13E12` | `math_div_32_d_wrapper_c13e12` | medium | calls math_div_32_d_wrapper_c14cde (0xC14CDE) |
| `0xC13E62` | `math_div_32_d_wrapper_c13e62` | medium | calls math_div_32_d_helper_c10398 (0xC10398) |
| `0xC13E94` | `math_div_32_d_wrapper_c13e94` | medium | calls math_div_32_d_helper_c10398 (0xC10398) |
| `0xC13F3C` | `math_mul_div_32_e` | medium | calls mul32/div32u |
| `0xC13F6C` | `capture_control` | high | Capture input control. |
| `0xC13F84` | `update_capture_input_select` | medium | writes capture input select |
| `0xC13F88` | `update_capture_input_select_b` | medium | writes capture input select |
| `0xC13F9A` | `capture_input_select` | high | Writes the low bits of 0xFD1A (capture input selection). |
| `0xC13FB2` | `update_speed_input_ready_dispatch_helper_c13fb2` | medium | called by update_speed_input_ready_dispatch_c1587e,update_speed_input_ready_dispatch_c158b2 |
| `0xC13FE6` | `update_capture_input_select_c` | medium | writes capture input select |
| `0xC1408A` | `event_start_wrapper_c1408a` | medium | calls event_start (0xC0D39E) |
| `0xC141B6` | `math_mul_div_32_wrapper_c141b6` | medium | calls math_mul_div_32_wrapper_c0d314 (0xC0D314) |
| `0xC141DE` | `update_event_offset_1` | medium | writes event offset |
| `0xC14298` | `capture_init` | high | Capture input initialization. |
| `0xC142A4` | `timer5_init_dispatch_c142a4` | medium | calls timer5_init,config_sensor_setup,capture_init |
| `0xC142DA` | `math_div_32_d_wrapper_c142da` | medium | calls math_div_32_d_helper_c10398 (0xC10398) |
| `0xC14300` | `math_div_32_d_wrapper_c14300` | medium | calls math_div_32_d_helper_c10398 (0xC10398) |
| `0xC14682` | `math_div_32_e` | medium | calls div32u |
| `0xC146DE` | `math_div_32_d_helper_c146de` | medium | called only by math_div_32_d_wrapper_c13e12 (0xC13E12) |
| `0xC14714` | `input_latch` | high | Latch input port bits into 0xFD1C. |
| `0xC14772` | `command_wrapper_c14772` | medium | calls command_dispatch (0xC19A2C) |
| `0xC1477A` | `command_wrapper_c1477a` | medium | calls command_dispatch (0xC19A2C) |
| `0xC147C6` | `command_dispatch_index3` | high | Calls command_dispatch with index 3. |
| `0xC147CE` | `command_wrapper_c147ce` | medium | calls command_dispatch (0xC19A2C) |
| `0xC147D6` | `command_wrapper_c147d6` | medium | calls command_dispatch (0xC19A2C) |
| `0xC14824` | `command_wrapper_c14824` | medium | calls command_dispatch (0xC19A2C) |
| `0xC1482C` | `diag_status_build` | high | Builds the packed diagnostic status bytes 0xC60C..0xC610. |
| `0xC14CDE` | `math_div_32_d_wrapper_c14cde` | medium | calls math_div_32_d (0xC10B0C) |
| `0xC15064` | `update_speed_input_ready_wrapper_c15064` | medium | calls update_speed_input_ready_helper_c24d9a (0xC24D9A) |
| `0xC15828` | `update_speed_input_ready_wrapper_c15828` | medium | calls update_speed_input_ready_wrapper_c15064 (0xC15064) |
| `0xC15836` | `dtc_status_bit5_wrapper_c15836` | medium | calls dtc_status_bit5_wrapper_c265aa (0xC265AA) |
| `0xC15848` | `update_speed_input_ready_wrapper_c15848` | medium | calls update_speed_input_ready_wrapper_c15064 (0xC15064) |
| `0xC1585A` | `update_speed_input_ready_wrapper_c1585a` | medium | calls update_speed_input_ready_wrapper_c15064 (0xC15064) |
| `0xC1586C` | `dtc_status_bit5_wrapper_c1586c` | medium | calls dtc_status_bit5_wrapper_c26586 (0xC26586) |
| `0xC1587E` | `update_speed_input_ready_dispatch_c1587e` | medium | calls update_speed_input_ready_helper_c24d9a,dtc_status_bit5_wrapper_c25e52 |
| `0xC158B2` | `update_speed_input_ready_dispatch_c158b2` | medium | calls update_speed_input_ready_helper_c24d9a,dtc_status_bit5_wrapper_c25e60 |
| `0xC158E6` | `update_speed_input_ready_wrapper_c158e6` | medium | calls update_speed_input_ready_wrapper_c15064 (0xC15064) |
| `0xC158F4` | `dtc_status_bit5_wrapper_c158f4` | medium | calls dtc_status_bit5_wrapper_c265ca (0xC265CA) |
| `0xC1590A` | `update_speed_input_ready_wrapper_c1590a` | medium | calls update_speed_input_ready_wrapper_c15064 (0xC15064) |
| `0xC1596E` | `rate_limit` | high | Rate limiter / slew helper. |
| `0xC159E8` | `calc_table_helper_c159e8` | medium | called only by calc_table_dispatch_c17b70 (0xC17B70) |
| `0xC15EA6` | `update_security_unlocked_helper_c15ea6` | medium | called only by update_security_unlocked_wrapper_c19766 (0xC19766) |
| `0xC15ECC` | `calc_map_helper_c15ecc` | medium | called only by calc_map_dispatch_c1c0b4 (0xC1C0B4) |
| `0xC166A2` | `calc_table_helper_c166a2` | medium | called only by calc_table_6d48 (0xC1DEEE) |
| `0xC16790` | `sat_sub_u16_wrapper_c16790` | medium | calls sat_sub_u16_wrapper_c1b982 (0xC1B982) |
| `0xC16946` | `sat_sub_u16_wrapper_c16946` | medium | calls sat_sub_u16_wrapper_c16790 (0xC16790) |
| `0xC16CDE` | `calc_map_5c62` | high | calls tbl2d 0x5C62 and correction curves |
| `0xC17B70` | `calc_table_dispatch_c17b70` | medium | calls calc_table_5db0,calc_table_613e |
| `0xC17C70` | `calc_table_wrapper_c17c70` | medium | calls calc_table_wrapper_c181c4 (0xC181C4) |
| `0xC17C8E` | `calc_table_wrapper_c17c8e` | medium | calls calc_table_wrapper_c181da (0xC181DA) |
| `0xC17F44` | `calc_table_5db0` | medium | calls tbl16 0x5DB0/0x7CDC/0x5D9C |
| `0xC18138` | `calc_table_helper_c18138` | medium | called only by calc_table_5d9c (0xC18176) |
| `0xC18176` | `calc_table_5d9c` | medium | calls tbl16 0x5D9C |
| `0xC181C4` | `calc_table_wrapper_c181c4` | medium | calls calc_table_helper_c18138 (0xC18138) |
| `0xC181DA` | `calc_table_wrapper_c181da` | medium | calls calc_table_helper_c18138 (0xC18138) |
| `0xC1823C` | `calc_table_613e` | medium | calls tbl16 0x613E/0x61F4 |
| `0xC18528` | `calc_table_helper_c18528` | medium | called only by calc_table_wrapper_c17c70 (0xC17C70) |
| `0xC18554` | `calc_table_helper_c18554` | medium | called only by calc_table_wrapper_c17c8e (0xC17C8E) |
| `0xC18C5C` | `calc_table_636c` | medium | calls tbl16 0x636C |
| `0xC18D8A` | `calc_table_63b4` | medium | calls tbl8 0x63B4 |
| `0xC193D6` | `update_security_unlocked_dispatch_c193d6` | medium | calls update_security_unlocked_c1f61e,calc_table_7860 |
| `0xC19420` | `update_security_unlocked_wrapper_c19420` | medium | calls update_security_unlocked_c1f664 (0xC1F664) |
| `0xC1971A` | `update_security_unlocked_helper_c1971a` | medium | called only by update_security_unlocked_wrapper_c19420 (0xC19420) |
| `0xC19766` | `update_security_unlocked_wrapper_c19766` | medium | calls update_security_unlocked_dispatch_c193d6 (0xC193D6) |
| `0xC197AC` | `calc_table_wrapper_c197ac` | medium | calls calc_table_wrapper_c1beca (0xC1BECA) |
| `0xC197C2` | `empty_stub_0_wrapper_c197c2` | medium | calls empty_stub_0_wrapper_c24e60 (0xC24E60) |
| `0xC1981A` | `update_engine_state_helper_c1981a` | medium | called only by update_engine_state_c1b714 (0xC1B714) |
| `0xC1983E` | `update_ssc_rx_frame_wrapper_c1983e` | medium | calls update_ssc_rx_frame_wrapper_c1bf0a (0xC1BF0A) |
| `0xC19850` | `update_security_unlocked_wrapper_c19850` | medium | calls update_security_unlocked_wrapper_c19766 (0xC19766) |
| `0xC1990E` | `update_calc_correction_wrapper_c1990e` | medium | calls update_calc_correction_wrapper_c19b4a (0xC19B4A) |
| `0xC19924` | `calc_table_wrapper_c19924` | medium | calls calc_table_wrapper_c19ae6 (0xC19AE6) |
| `0xC19932` | `math_div_32_d_wrapper_c19932` | medium | calls math_div_32_d_wrapper_c19b56 (0xC19B56) |
| `0xC19948` | `calc_table_dispatch_c19948` | medium | calls calc_table_wrapper_c19ae6,calc_table_wrapper_c19b60 |
| `0xC19968` | `calc_table_wrapper_c19968` | medium | calls calc_table_wrapper_c19ae6 (0xC19AE6) |
| `0xC19988` | `calc_table_wrapper_c19988` | medium | calls calc_table_wrapper_c19ae6 (0xC19AE6) |
| `0xC199BA` | `calc_table_wrapper_c199ba` | medium | calls calc_table_wrapper_c19ae6 (0xC19AE6) |
| `0xC199D2` | `calc_table_wrapper_c199d2` | medium | calls calc_table_wrapper_c19ae6 (0xC19AE6) |
| `0xC19A00` | `update_kline_response_source_b_wrapper_c19a00` | medium | calls update_kline_response_source_b_wrapper_c19b84 (0xC19B84) |
| `0xC19A06` | `select_active_record_wrapper_c19a06` | medium | calls select_active_record_wrapper_c19b92 (0xC19B92) |
| `0xC19A2C` | `command_dispatch` | high | Dispatches command index 0..6 through the external-RAM table at 0x7666. |
| `0xC19A56` | `calc_map_wrapper_c19a56` | medium | calls calc_map_dispatch_c1c0b4 (0xC1C0B4) |
| `0xC19AA6` | `calc_table_6c7a_b_wrapper_c19aa6` | medium | calls calc_table_6c7a_b_wrapper_c1c098 (0xC1C098) |
| `0xC19AE6` | `calc_table_wrapper_c19ae6` | medium | calls calc_table_dispatch_c17b70 (0xC17B70) |
| `0xC19B4A` | `update_calc_correction_wrapper_c19b4a` | medium | calls update_calc_correction (0xC1C024) |
| `0xC19B50` | `update_timer7_tick_wrapper_c19b50` | medium | calls update_timer7_tick_wrapper_c1c04a (0xC1C04A) |
| `0xC19B56` | `math_div_32_d_wrapper_c19b56` | medium | calls math_div_32_d_wrapper_c0ffee (0xC0FFEE) |
| `0xC19B60` | `calc_table_wrapper_c19b60` | medium | calls calc_table_wrapper_c1f20a (0xC1F20A) |
| `0xC19B84` | `update_kline_response_source_b_wrapper_c19b84` | medium | calls update_kline_response_source_b_wrapper_c1c05e (0xC1C05E) |
| `0xC19B92` | `select_active_record_wrapper_c19b92` | medium | calls select_active_record_wrapper_c24eee (0xC24EEE) |
| `0xC19EBC` | `math_mul32_c_wrapper_c19ebc` | medium | calls math_mul32_c_dispatch_c1e714 (0xC1E714) |
| `0xC19F80` | `math_div_32_d_helper_c19f80` | medium | called only by math_div_32_d_wrapper_c19b56 (0xC19B56) |
| `0xC1A1F0` | `capture_control_wrapper_c1a1f0` | medium | calls capture_control (0xC13F6C) |
| `0xC1A44E` | `math_mul32_c_helper_c1a44e` | medium | called only by math_mul32_c_wrapper_c19ebc (0xC19EBC) |
| `0xC1A51A` | `rate_limit_dispatch_c1a51a` | medium | calls rate_limit,math_mul32_c,axis16_signed,axis16_unsigned,math_div32 |
| `0xC1AC7C` | `sat_add_s16_wrapper_c1ac7c` | medium | calls sat_add_s16_wrapper_c1aeac (0xC1AEAC) |
| `0xC1AC8C` | `update_calc_input_w` | medium | writes calc_input_w |
| `0xC1ACD6` | `calc_table_6ca4` | medium | calls tbl8 0x6CA4 |
| `0xC1AEAC` | `sat_add_s16_wrapper_c1aeac` | medium | calls sat_add_s16 (0xC276BA) |
| `0xC1AEDC` | `limit_condition_eval` | high | speed/threshold limiter check |
| `0xC1B2E2` | `calc_table_helper_c1b2e2` | medium | called only by calc_table_wrapper_c1beca (0xC1BECA) |
| `0xC1B2FC` | `update_calc_input_z` | medium | writes calc_input_z/correction |
| `0xC1B34A` | `update_calc_input_z_b` | medium | writes calc_input_z |
| `0xC1B5FE` | `update_timer7_tick_wrapper_c1b5fe` | medium | calls update_timer7_tick (0xC1C410) |
| `0xC1B682` | `update_engine_state` | medium | writes engine_state |
| `0xC1B6A6` | `update_engine_state_c1b6a6` | medium | writes engine_state,speed_status_flags |
| `0xC1B6CC` | `update_engine_state_c1b6cc` | medium | writes engine_state |
| `0xC1B6F0` | `update_engine_state_c1b6f0` | medium | writes engine_state |
| `0xC1B714` | `update_engine_state_c1b714` | medium | writes engine_state |
| `0xC1B73A` | `update_engine_state_c1b73a` | medium | writes engine_state |
| `0xC1B784` | `update_kline_response_payload_wrapper_c1b784` | medium | calls update_kline_response_payload (0xC20450) |
| `0xC1B866` | `calc_table_6b6a` | medium | calls tbl16 0x6B6A |
| `0xC1B982` | `sat_sub_u16_wrapper_c1b982` | medium | calls sat_sub_u16 (0xC28852) |
| `0xC1BECA` | `calc_table_wrapper_c1beca` | medium | calls calc_table_6c7a (0xC1D8C6) |
| `0xC1BF0A` | `update_ssc_rx_frame_wrapper_c1bf0a` | medium | calls update_ssc_rx_frame (0xC1CB9E) |
| `0xC1C024` | `update_calc_correction` | medium | writes calc_input_correction |
| `0xC1C04A` | `update_timer7_tick_wrapper_c1c04a` | medium | calls update_timer7_tick_wrapper_c1b5fe (0xC1B5FE) |
| `0xC1C05E` | `update_kline_response_source_b_wrapper_c1c05e` | medium | calls update_kline_response_source_b (0xC2046C) |
| `0xC1C098` | `calc_table_6c7a_b_wrapper_c1c098` | medium | calls calc_table_6c7a_b (0xC1D950) |
| `0xC1C09E` | `calc_map_wrapper_c1c09e` | medium | calls calc_map_70f6 (0xC1DA6E) |
| `0xC1C0B4` | `calc_map_dispatch_c1c0b4` | medium | calls calc_map_wrapper_c1c09e,calc_table_helper_c1c3ee |
| `0xC1C0EA` | `calc_table_helper_c1c0ea` | medium | called only by calc_table_wrapper_c1beca (0xC1BECA) |
| `0xC1C2B8` | `calc_table_helper_c1c2b8` | medium | called by calc_table_5db0,calc_table_5d9c |
| `0xC1C3EE` | `calc_table_helper_c1c3ee` | medium | called only by calc_table_5d9c (0xC18176) |
| `0xC1C410` | `update_timer7_tick` | medium | writes timer7_tick |
| `0xC1C718` | `update_speed_status` | medium | writes speed flags/input |
| `0xC1C956` | `math_mul32` | medium | calls mul32 |
| `0xC1CB9E` | `update_ssc_rx_frame` | medium | writes SSC RX frame |
| `0xC1D8C6` | `calc_table_6c7a` | medium | calls tbl16 0x6C7A |
| `0xC1D950` | `calc_table_6c7a_b` | medium | calls tbl16 0x6C7A |
| `0xC1DA6E` | `calc_map_70f6` | high | axis 0x50DC, map 0x70F6 |
| `0xC1DB18` | `calc_map_6e50` | high | map 0x6E50 |
| `0xC1DCF2` | `calc_map_dispatch_c1dcf2` | medium | calls calc_map_70f6,calc_map_6e50 |
| `0xC1DEEE` | `calc_table_6d48` | medium | calls tbl8 0x6D48 |
| `0xC1E714` | `math_mul32_c_dispatch_c1e714` | medium | calls math_mul32_c,math_div32,math_div32_b |
| `0xC1ED9E` | `calc_table_7616` | medium | calls tbl16 0x7616 |
| `0xC1F20A` | `calc_table_wrapper_c1f20a` | medium | calls calc_table_7616 (0xC1ED9E) |
| `0xC1F61E` | `update_security_unlocked_c1f61e` | medium | writes security_unlocked |
| `0xC1F664` | `update_security_unlocked_c1f664` | medium | writes security_unlocked |
| `0xC1FD9C` | `calc_load` | high | Calibration-based VE/load calculation; axes 0x7564/0x755E, VE map 0x794A, correction 0x79B6; live-data FVE1. |
| `0xC1FEDE` | `update_kline_response_source_b_helper_c1fede` | medium | called only by update_kline_response_source_b (0xC2046C) |
| `0xC2006E` | `calc_table_7860` | medium | calls tbl8 0x7860 |
| `0xC20096` | `calc_limit3_wrapper_c20096` | medium | calls calc_limit3 (0xC202EE) |
| `0xC200AA` | `calc_limit1` | high | Provisional injection-time/limit calculation (table 0x7912); live-data injector-time range cross-check. |
| `0xC201AE` | `calc_limit2` | high | Provisional spark/limit calculation (tables 0x7860/0x784C); live-data spark-advance range cross-check. |
| `0xC202EE` | `calc_limit3` | high | Provisional spark/limit calculation (tables 0x7552/0x7912/0x78E2/0x7874/0x78D8). |
| `0xC20398` | `update_kline_response_source` | medium | writes K-line response source |
| `0xC20400` | `update_kline_response_payload_4_c20400` | medium | writes kline_response_payload_4 |
| `0xC2042A` | `update_kline_rx_index` | medium | writes K-line RX index |
| `0xC20450` | `update_kline_response_payload` | medium | writes K-line response payload |
| `0xC2046C` | `update_kline_response_source_b` | medium | writes K-line response source |
| `0xC205D8` | `math_mul32_wrapper_c205d8` | medium | calls math_mul32_helper_c27738 (0xC27738) |
| `0xC20600` | `math_mul32_wrapper_c20600` | medium | calls math_mul32_wrapper_c205d8 (0xC205D8) |
| `0xC21F42` | `dtc_status_bit5_wrapper_c21f42` | medium | calls dtc_status_bit5 (0xC243A8) |
| `0xC22312` | `calc_table_helper_c22312` | medium | called only by calc_table_wrapper_c17c70 (0xC17C70) |
| `0xC225A8` | `calc_table_helper_c225a8` | medium | called only by calc_table_wrapper_c17c70 (0xC17C70) |
| `0xC225E4` | `calc_table_helper_c225e4` | medium | called only by calc_table_wrapper_c1beca (0xC1BECA) |
| `0xC2292C` | `math_div32_c_wrapper_c2292c` | medium | calls math_div32_c (0xC28B88) |
| `0xC22CFC` | `sat_sub_u16_wrapper_c22cfc` | medium | calls sat_sub_u16 (0xC28852) |
| `0xC22F3A` | `sat_sub_u16_wrapper_c22f3a` | medium | calls sat_sub_u16 (0xC28852) |
| `0xC232EA` | `dtc_status_bit5_wrapper_c232ea` | medium | calls dtc_status_bit5 (0xC243A8) |
| `0xC23446` | `math_helper_c23446` | medium | called by math_c23790,math_c2380a,math_c238d4,math_c23982 |
| `0xC2368A` | `dtc_status_bit5_dispatch_c2368a` | medium | calls dtc_status_bit5_wrapper_c21f42,math_helper_c23446 |
| `0xC236C6` | `axis16_unsigned_wrapper_c236c6` | medium | calls axis16_unsigned (0xC2850E) |
| `0xC23720` | `axis16_signed_wrapper_c23720` | medium | calls axis16_signed (0xC284D8) |
| `0xC2376A` | `math_c2376a` | medium | calls axis16_signed |
| `0xC23790` | `math_c23790` | medium | calls axis16_signed |
| `0xC237E4` | `math_c237e4` | medium | calls axis16_signed |
| `0xC2380A` | `math_c2380a` | medium | calls axis16_signed |
| `0xC2385E` | `math_wrapper_c2385e` | medium | calls math_helper_c23446 (0xC23446) |
| `0xC2389C` | `math_wrapper_c2389c` | medium | calls math_helper_c23446 (0xC23446) |
| `0xC238D4` | `math_c238d4` | medium | calls axis16_unsigned |
| `0xC2392E` | `math_c2392e` | medium | calls axis16_signed |
| `0xC23958` | `math_c23958` | medium | calls axis16_signed |
| `0xC23982` | `math_c23982` | medium | calls axis16_unsigned |
| `0xC23B88` | `math_wrapper_c23b88` | medium | calls math_helper_c23446 (0xC23446) |
| `0xC240FE` | `select_active_record` | high | record table 0x71EA |
| `0xC243A8` | `dtc_status_bit5` | high | fault-index table 0x7286, bit 5 |
| `0xC244CE` | `select_active_record_helper_c244ce` | medium | called only by select_active_record (0xC240FE) |
| `0xC247AA` | `empty_stub_0_wrapper_c247aa` | medium | calls empty_stub_0 (0xC28C4E) |
| `0xC24828` | `empty_stub_0_wrapper_c24828` | medium | calls empty_stub_0_wrapper_c247aa (0xC247AA) |
| `0xC24846` | `empty_stub_0_wrapper_c24846` | medium | calls empty_stub_0_wrapper_c247aa (0xC247AA) |
| `0xC2485A` | `empty_stub_0_wrapper_c2485a` | medium | calls empty_stub_0_wrapper_c247aa (0xC247AA) |
| `0xC24864` | `empty_stub_0_wrapper_c24864` | medium | calls empty_stub_0_wrapper_c247aa (0xC247AA) |
| `0xC24878` | `empty_stub_0_wrapper_c24878` | medium | calls empty_stub_0_wrapper_c247aa (0xC247AA) |
| `0xC24882` | `empty_stub_0_wrapper_c24882` | medium | calls empty_stub_0_wrapper_c247aa (0xC247AA) |
| `0xC24CB4` | `config_mode_update_helper_c24cb4` | medium | called only by config_mode_update (0xC27216) |
| `0xC24D1C` | `config_mode_update_helper_c24d1c` | medium | called only by config_mode_update (0xC27216) |
| `0xC24D9A` | `update_speed_input_ready_helper_c24d9a` | medium | called only by update_speed_input_ready_c26cd4 (0xC26CD4) |
| `0xC24E5A` | `calc_table_helper_c24e5a` | medium | called only by calc_table_wrapper_c197ac (0xC197AC) |
| `0xC24E60` | `empty_stub_0_wrapper_c24e60` | medium | calls empty_stub_0_wrapper_c24846 (0xC24846) |
| `0xC24E72` | `empty_stub_0_wrapper_c24e72` | medium | calls empty_stub_0_wrapper_c2485a (0xC2485A) |
| `0xC24E78` | `empty_stub_0_wrapper_c24e78` | medium | calls empty_stub_0_wrapper_c24864 (0xC24864) |
| `0xC24E88` | `update_adapt_age_wrapper_c24e88` | medium | calls update_adapt_age (0xC25600) |
| `0xC24EEE` | `select_active_record_wrapper_c24eee` | medium | calls select_active_record (0xC240FE) |
| `0xC24F3E` | `dtc_status_bit5_wrapper_c24f3e` | medium | calls dtc_status_bit5_wrapper_c21f42 (0xC21F42) |
| `0xC24F76` | `math_mul32_wrapper_c24f76` | medium | calls math_mul32_wrapper_c20600 (0xC20600) |
| `0xC25300` | `select_active_record_helper_c25300` | medium | called only by select_active_record_wrapper_c24eee (0xC24EEE) |
| `0xC25600` | `update_adapt_age` | high | walks 0x1E records |
| `0xC25C6C` | `config_mode_update_dispatch_c25c6c` | medium | calls config_mode_update_helper_c24cb4,config_mode_update_helper_c24d1c |
| `0xC25E52` | `dtc_status_bit5_wrapper_c25e52` | medium | calls dtc_status_bit5 (0xC243A8) |
| `0xC25E60` | `dtc_status_bit5_wrapper_c25e60` | medium | calls dtc_status_bit5 (0xC243A8) |
| `0xC25EB2` | `config_mode_update_dispatch_c25eb2` | medium | calls config_mode_update_helper_c24cb4,config_mode_update_helper_c24d1c |
| `0xC26086` | `table_7d88_c26086` | medium | calls tbl16_interp@0x7D88 |
| `0xC260B4` | `table_7d88_c260b4` | medium | calls tbl16_interp@0x7D88 |
| `0xC260D8` | `config_mode_update_dispatch_c260d8` | medium | calls config_mode_update_helper_c24cb4,config_mode_update_helper_c24d1c |
| `0xC26586` | `dtc_status_bit5_wrapper_c26586` | medium | calls dtc_status_bit5 (0xC243A8) |
| `0xC265AA` | `dtc_status_bit5_wrapper_c265aa` | medium | calls dtc_status_bit5 (0xC243A8) |
| `0xC265CA` | `dtc_status_bit5_wrapper_c265ca` | medium | calls dtc_status_bit5 (0xC243A8) |
| `0xC266DC` | `math_c266dc` | medium | calls rate_limit |
| `0xC26850` | `math_c26850` | medium | calls rate_limit |
| `0xC26A6A` | `math_c26a6a` | medium | calls rate_limit |
| `0xC26A9E` | `math_helper_c26a9e` | medium | called only by math_wrapper_c26b6e (0xC26B6E) |
| `0xC26AC6` | `math_helper_c26ac6` | medium | called only by math_wrapper_c26b6e (0xC26B6E) |
| `0xC26B04` | `math_helper_c26b04` | medium | called only by math_wrapper_c26b6e (0xC26B6E) |
| `0xC26B6E` | `math_wrapper_c26b6e` | medium | calls math_c26a6a (0xC26A6A) |
| `0xC26CD4` | `update_speed_input_ready_c26cd4` | medium | writes speed_input_ready |
| `0xC26D3A` | `update_speed_input_ready_dispatch_c26d3a` | medium | calls update_speed_input_ready_helper_c24d9a,sat_sub_u16_wrapper_c26dca |
| `0xC26DCA` | `sat_sub_u16_wrapper_c26dca` | medium | calls sat_sub_u16 (0xC28852) |
| `0xC2702A` | `dtc_status_bit5_helper_c2702a` | medium | called only by dtc_status_bit5_wrapper_c2705e (0xC2705E) |
| `0xC2705E` | `dtc_status_bit5_wrapper_c2705e` | medium | calls dtc_status_bit5_wrapper_c270da (0xC270DA) |
| `0xC270DA` | `dtc_status_bit5_wrapper_c270da` | medium | calls dtc_status_bit5 (0xC243A8) |
| `0xC27216` | `config_mode_update` | high | writes XRAM mode flags |
| `0xC276BA` | `sat_add_s16` | high | signed saturating add |
| `0xC27738` | `math_mul32_helper_c27738` | medium | called only by math_mul32 (0xC1C956) |
| `0xC27BF8` | `math_mul32_b` | medium | calls mul32 |
| `0xC27CA4` | `tbl16_interp` | high | 16-bit table lookup with 8.8 fixed-point interpolation. |
| `0xC27F0E` | `math_mul32_c` | medium | calls mul32 |
| `0xC27FCA` | `tbl8_interp` | high | 8-bit table lookup with 8.8 fixed-point interpolation. |
| `0xC2826E` | `tbl2d_interp` | high | 2D 8-bit map lookup with bilinear interpolation. |
| `0xC28450` | `math_mul32_d` | medium | calls mul32 |
| `0xC284D8` | `axis16_signed` | high | Signed axis descriptor -> 8.8 fixed-point index. |
| `0xC2850E` | `axis16_unsigned` | high | Unsigned axis descriptor -> 8.8 fixed-point index. |
| `0xC28544` | `math_div32` | medium | calls div32u |
| `0xC286CA` | `math_div32_b` | medium | calls div32u |
| `0xC28852` | `sat_sub_u16` | high | unsigned saturating subtract |
| `0xC288A8` | `math_mul32_helper_c288a8` | medium | called only by math_mul32 (0xC1C956) |
| `0xC289C2` | `math_helper_c289c2` | medium | called by math_c23790,math_c2380a |
| `0xC28B64` | `mul32` | high | 32x16/32-bit multiply helper. |
| `0xC28B88` | `math_div32_c` | medium | calls div32u |
| `0xC28BB2` | `div32u` | high | 32-bit unsigned division helper. |
| `0xC28C4E` | `empty_stub_0` | high | Empty function. |
| `0xC28C62` | `store32` | high | Stores a 32-bit value as two 16-bit words. |
| `0xC28CA4` | `fp_div_signed` | high | Software float division with sign handling. |
| `0xC28CAC` | `fp_div_unsigned` | high | Software float division helper. |
| `0xC28DBE` | `fp_to_int` | high | Software float to integer conversion. |
| `0xC28DEC` | `fp_neg` | high | Software float negation/absolute-value helper. |
| `0xC28E06` | `fp_store_dispatch_c28e06` | medium | calls fp_store,fp_store_zero |
| `0xC28E50` | `fp_compare` | high | Software float comparison. |
| `0xC28E94` | `fp_pack` | high | Packs a software float into four 16-bit words. |
| `0xC28ED2` | `fp_pack_zero` | high | Packs a zero software float. |
| `0xC28F0E` | `fp_round` | high | Rounds and stores a software float. |
| `0xC28F1E` | `fp_store` | high | Stores four words of a software float. |
| `0xC28F5E` | `fp_store_zero` | high | Stores a zero software float. |
| `0xC28F6C` | `fp_load` | high | Loads four words of a software float. |
| `0xC28F84` | `fp_copy` | high | Copies four words of a software float. |
