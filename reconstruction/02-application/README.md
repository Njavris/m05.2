# Application

Firmware part: application, `0xC0B000–0xC3FFFF`, 212 KB.

179 functions in [`application.c`](application.c) and [`application.asm`](application.asm).
Calibration access code is application code; the calibration block itself is
data in `../03-data/`.

[Back to reconstruction index](../README.md) · [Function index](../03-data/data.c)

| Area | Functions |
|---|---:|
| Startup / runtime | 15 |
| Drivers / CAN | 4 |
| Drivers / K-line ASC0 | 23 |
| Drivers / SSC | 13 |
| Drivers / timers | 10 |
| Drivers / ADC | 2 |
| Drivers / IO | 8 |
| Drivers / PWM | 3 |
| Drivers / clock | 2 |
| Diagnostics / KWP2000 | 12 |
| Diagnostics / K-line transport | 9 |
| Diagnostics / CAN transport | 7 |
| Diagnostics / status | 1 |
| Diagnostics / test commands | 2 |
| Calibration / accessors | 5 |
| Calibration / checksum | 1 |
| Engine control / events | 18 |
| Engine control / CC22-23 outputs | 10 |
| Engine control / speed | 2 |
| Engine control / load | 1 |
| Engine control / limits | 4 |
| Engine control / sensor | 1 |
| Runtime library | 26 |
| **total** | **179** |

## Startup / runtime

Application startup, scheduler, command dispatch.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC0BFD2 | `app_clear_flag` | 6 | Clear application flag. | [C](application.c#L9) | [ASM](application.asm#L9) |
| 0xC0BFE2 | `app_run` | 16 | Application run entry. | [C](application.c#L28) | [ASM](application.asm#L19) |
| 0xC0FFDE | `app_main` | 16 | Application main entry. | [C](application.c#L51) | [ASM](application.asm#L34) |
| 0xC10000 | `app_entry` | 4 | Application far-call entry trampoline; jumps to app_cstart. | [C](application.c#L71) | [ASM](application.asm#L47) |
| 0xC108B4 | `timeout_counter_tick` | 26 | Increments timeout_counter and clears timeout_value_0/1 at 0x81. | [C](application.c#L132) | [ASM](application.asm#L56) |
| 0xC1192C | `app_cinit` | 372 | Application C runtime init table walker. | [C](application.c#L156) | [ASM](application.asm#L72) |
| 0xC11AA0 | `app_cstart` | 138 | Application C runtime startup; copies init data then calls app_main. | [C](application.c#L324) | [ASM](application.asm#L223) |
| 0xC11BF4 | `app_hw_init` | 102 | Application hardware initialization sequence. | [C](application.c#L385) | [ASM](application.asm#L274) |
| 0xC11C62 | `app_main_init` | 76 | Application main initialization; enters scheduler. | [C](application.c#L432) | [ASM](application.asm#L308) |
| 0xC11CAE | `app_idle_wait` | 238 | Scheduler idle/wait path. | [C](application.c#L471) | [ASM](application.asm#L345) |
| 0xC11EB4 | `app_scheduler` | 18 | Application scheduler entry. | [C](application.c#L566) | [ASM](application.asm#L432) |
| 0xC11EC6 | `app_scheduler_path` | 38 | Scheduler alternate path. | [C](application.c#L661) | [ASM](application.asm#L445) |
| 0xC11EEC | `scheduler_tick` | 24 | Increments the scheduler counter and dispatches command 3. | [C](application.c#L690) | [ASM](application.asm#L465) |
| 0xC147C6 | `command_dispatch_index3` | 8 | Calls command_dispatch with index 3. | [C](application.c#L712) | [ASM](application.asm#L480) |
| 0xC19A2C | `command_dispatch` | 20 | Dispatches command index 0..6 through the external-RAM table at 0x7666. | [C](application.c#L730) | [ASM](application.asm#L491) |

## Drivers / CAN

TwinCAN driver and message objects.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC00434 | `can_twincan_init` | 608 | TwinCAN initialization; message object 0 ID 0x7E0/0x7E4 (diagnostic). | [C](application.c#L756) | [ASM](application.asm#L510) |
| 0xC00694 | `can0_isr` | 232 | CAN0 interrupt handler; processes message object 0 and calls can_rx_process. | [C](application.c#L846) | [ASM](application.asm#L702) |
| 0xC0BA9E | `set_can_flag` | 22 | Set CAN/application flag. | [C](application.c#L988) | [ASM](application.asm#L792) |
| 0xC11B2A | `can_bus_config` | 112 | CAN bus pin/mode configuration. | [C](application.c#L1014) | [ASM](application.asm#L807) |

## Drivers / K-line ASC0

ASC0/K-line UART driver.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC00C36 | `asc0_init` | 78 | ASC0 (UART/K-line) initialization; S0BG, S0CON, port setup. | [C](application.c#L1051) | [ASM](application.asm#L852) |
| 0xC00C84 | `asc0_tx_byte` | 6 | Writes one byte to the ASC0 transmit buffer S0TBUF. | [C](application.c#L1093) | [ASM](application.asm#L886) |
| 0xC00C8A | `asc0_read_rx_clear` | 8 | Clears the ASC0 receive flag and returns one S0RBUF byte. | [C](application.c#L1111) | [ASM](application.asm#L896) |
| 0xC00DDC | `asc0_pin_init` | 44 | ASC0 alternate-function pin setup. | [C](application.c#L1134) | [ASM](application.asm#L907) |
| 0xC01144 | `asc0_state_dispatch` | 26 | Dispatch ASC0 K-line state 0..5 through table at 0xC00428. | [C](application.c#L1181) | [ASM](application.asm#L934) |
| 0xC01158 | `asc0_task0` | 6 | K-line state 0 wrapper. | [C](application.c#L1205) | [ASM](application.asm#L952) |
| 0xC0115E | `asc0_task1` | 6 | K-line state 1 wrapper. | [C](application.c#L1223) | [ASM](application.asm#L962) |
| 0xC01164 | `asc0_task2` | 6 | K-line state 2 wrapper. | [C](application.c#L1241) | [ASM](application.asm#L972) |
| 0xC0116A | `asc0_task3` | 6 | K-line state 3 wrapper. | [C](application.c#L1259) | [ASM](application.asm#L982) |
| 0xC01170 | `asc0_task4` | 6 | K-line state 4 wrapper. | [C](application.c#L1277) | [ASM](application.asm#L992) |
| 0xC01176 | `asc0_task5` | 6 | K-line state 5 wrapper. | [C](application.c#L1295) | [ASM](application.asm#L1002) |
| 0xC01182 | `asc0_clear_state` | 6 | Clear ASC0/K-line state. | [C](application.c#L1313) | [ASM](application.asm#L1012) |
| 0xC01188 | `asc0_state0` | 22 | K-line state 0: idle / start. | [C](application.c#L1332) | [ASM](application.asm#L1022) |
| 0xC0119E | `asc0_state1` | 56 | K-line state 1: wake-up / 5-baud handling. | [C](application.c#L1358) | [ASM](application.asm#L1037) |
| 0xC011D6 | `asc0_state2` | 60 | K-line state 2: receive frame bytes. | [C](application.c#L1392) | [ASM](application.asm#L1063) |
| 0xC01218 | `asc0_state2_init` | 58 | Initialize K-line receive frame. | [C](application.c#L1433) | [ASM](application.asm#L1092) |
| 0xC01252 | `asc0_state3` | 148 | K-line state 3: receive/validate. | [C](application.c#L1464) | [ASM](application.asm#L1119) |
| 0xC012E6 | `asc0_state4` | 258 | K-line state 4: transmit response. | [C](application.c#L1522) | [ASM](application.asm#L1173) |
| 0xC013E8 | `asc0_state5` | 154 | K-line state 5: finish. | [C](application.c#L1593) | [ASM](application.asm#L1268) |
| 0xC11F1C | `asc0_init_app` | 62 | Application ASC0/K-line initialization. | [C](application.c#L1648) | [ASM](application.asm#L1326) |
| 0xC11F60 | `asc0_read_rx_raw` | 6 | Returns one S0RBUF byte without changing the receive flag. | [C](application.c#L1684) | [ASM](application.asm#L1353) |
| 0xC11F66 | `asc0_rx_handler` | 52 | ASC0 receive handler: reads S0RBUF and pushes the byte into the K-line ring. | [C](application.c#L1704) | [ASM](application.asm#L1363) |
| 0xC11F9A | `asc0_tx_handler` | 98 | ASC0 transmit/status handler for the K-line transport. | [C](application.c#L1745) | [ASM](application.asm#L1390) |

## Drivers / SSC

Synchronous serial frame engine.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC00E08 | `ssc_send_byte` | 12 | Write one byte to SSC transmit buffer. | [C](application.c#L1795) | [ASM](application.asm#L1435) |
| 0xC00E14 | `ssc0_rx_isr` | 182 | SSC0 receive interrupt; 7-byte frame engine. | [C](application.c#L1817) | [ASM](application.asm#L1448) |
| 0xC00ECA | `ssc_start_frame` | 30 | Start SSC transfer with 7-byte buffer. | [C](application.c#L1943) | [ASM](application.asm#L1525) |
| 0xC0D9E4 | `ssc_init` | 126 | SSC/CC26 initialization; installs handlers at 0xC0D8FA and 0xC0D914. | [C](application.c#L1969) | [ASM](application.asm#L1542) |
| 0xC0DA62 | `cc26_ptr_init` | 42 | Stores CC26/CCM6/CC26IC pointers used by the SSC timing path. | [C](application.c#L2013) | [ASM](application.asm#L1587) |
| 0xC0FC90 | `ssc_state_reset` | 22 | Reset SSC state. | [C](application.c#L2036) | [ASM](application.asm#L1606) |
| 0xC0FE7E | `ssc_pin_config` | 48 | SSC/port configuration. | [C](application.c#L2059) | [ASM](application.asm#L1620) |
| 0xC0FEAE | `ssc_mode_select` | 82 | Select SSC mode from calibration byte 0xC05036. | [C](application.c#L2082) | [ASM](application.asm#L1646) |
| 0xC0FF00 | `ssc0_init_app` | 40 | Application SSC0 initialization. | [C](application.c#L2121) | [ASM](application.asm#L1683) |
| 0xC0FF28 | `ssc_send` | 12 | Send one SSC byte. | [C](application.c#L2164) | [ASM](application.asm#L1708) |
| 0xC0FFC0 | `ssc_rx_start` | 30 | Start SSC receive engine. | [C](application.c#L2186) | [ASM](application.asm#L1721) |
| 0xC10200 | `ssc_rx_queue_init` | 64 | SSC receive queue initialization. | [C](application.c#L2212) | [ASM](application.asm#L1738) |
| 0xC10342 | `ssc_task` | 46 | Periodic SSC task: start transfer, timeout, sample port. | [C](application.c#L2246) | [ASM](application.asm#L1763) |

## Drivers / timers

CAPCOM/timer time base.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC00CA2 | `capcom_timer_init` | 146 | CAPCOM/T0/T7/T8 timer initialization. | [C](application.c#L2277) | [ASM](application.asm#L1786) |
| 0xC00D34 | `timer7_isr` | 118 | Timer7 interrupt: ASC0 state machine + KWP dispatcher, 1 ms tick. | [C](application.c#L2334) | [ASM](application.asm#L1835) |
| 0xC0BDA2 | `timer4_init` | 38 | Timer T4 initialization. | [C](application.c#L2469) | [ASM](application.asm#L1890) |
| 0xC0BF40 | `timer6_init` | 20 | Timer T6 initialization. | [C](application.c#L2502) | [ASM](application.asm#L1911) |
| 0xC0CDFA | `timer5_init` | 168 | Timer T5/ASC0 error init. | [C](application.c#L2528) | [ASM](application.asm#L1925) |
| 0xC0CEA2 | `capcom_start` | 118 | Start CAPCOM/T7/T8 time base. | [C](application.c#L2598) | [ASM](application.asm#L1986) |
| 0xC0FB6E | `timer6_start` | 30 | Start timer T6. | [C](application.c#L2656) | [ASM](application.asm#L2031) |
| 0xC1064C | `t7_timestamp` | 40 | Returns a short T7 timestamp with overflow extension. | [C](application.c#L2681) | [ASM](application.asm#L2047) |
| 0xC106E6 | `t7_timestamp_extended` | 68 | Returns a T7 timestamp extended by the T7 overflow flag. | [C](application.c#L2710) | [ASM](application.asm#L2068) |
| 0xC1072A | `timer8_init` | 76 | Timer T8/CAPCOM init. | [C](application.c#L2751) | [ASM](application.asm#L2099) |

## Drivers / ADC

ADC conversion/calibration.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC10370 | `adc_start` | 32 | Start ADC conversion; selects pin mode from calibration. | [C](application.c#L2791) | [ASM](application.asm#L2132) |
| 0xC105EC | `adc_calibrate` | 44 | ADC calibration/start. | [C](application.c#L2815) | [ASM](application.asm#L2150) |

## Drivers / IO

Ports, input sampling, capture.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC0BD54 | `p1l1_set` | 4 | Sets port P1L.1. | [C](application.c#L2850) | [ASM](application.asm#L2174) |
| 0xC0CAC2 | `watchdog_pin` | 24 | Watchdog/port pin control. | [C](application.c#L2871) | [ASM](application.asm#L2184) |
| 0xC10242 | `input_debounce_sample` | 154 | Samples P1L pins and updates input_state_bits/input_low_bits/input_high_bits. | [C](application.c#L2898) | [ASM](application.asm#L2200) |
| 0xC103C0 | `port_bus_init` | 260 | Application port and external-bus initialization. | [C](application.c#L2966) | [ASM](application.asm#L2256) |
| 0xC13F6C | `capture_control` | 24 | Capture input control. | [C](application.c#L3052) | [ASM](application.asm#L2339) |
| 0xC13F9A | `capture_input_select` | 24 | Writes the low bits of 0xFD1A (capture input selection). | [C](application.c#L3081) | [ASM](application.asm#L2355) |
| 0xC14298 | `capture_init` | 12 | Capture input initialization. | [C](application.c#L3102) | [ASM](application.asm#L2372) |
| 0xC14714 | `input_latch` | 36 | Latch input port bits into 0xFD1C. | [C](application.c#L3121) | [ASM](application.asm#L2384) |

## Drivers / PWM

PWM setup and calculation.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC108CE | `pwm_init` | 160 | PWM/CAPCOM6 initialization. | [C](application.c#L3156) | [ASM](application.asm#L2406) |
| 0xC10A74 | `pwm_period_duty_calc` | 106 | Computes PWM period/duty from the 32-bit division result. | [C](application.c#L3205) | [ASM](application.asm#L2459) |
| 0xC10AFC | `pwm_output_enable` | 16 | Enables the PWM output (PWMCON0 and P1L.4). | [C](application.c#L3243) | [ASM](application.asm#L2502) |

## Drivers / clock

Clock/PLL.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC01048 | `pll_isr` | 56 | PLL/oscillator watchdog interrupt; performs software reset. | [C](application.c#L3272) | [ASM](application.asm#L2520) |
| 0xC01080 | `clock_init` | 176 | Clock/PLL and port initialization. | [C](application.c#L3379) | [ASM](application.asm#L2554) |

## Diagnostics / KWP2000

KWP2000 services.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC01482 | `kwp_dispatch` | 154 | KWP2000 service dispatcher (0x10/0x23/0x27/0x31/0x34/0x36/0x38/0x3D/0x83). | [C](application.c#L3440) | [ASM](application.asm#L2614) |
| 0xC0151C | `kwp_sid81` | 40 | KWP service 0x81 handler (start communication). | [C](application.c#L3494) | [ASM](application.asm#L2673) |
| 0xC01544 | `kwp_sid27_security` | 150 | KWP service 0x27 security access; fixed seed 0x1234, key 0x8474. | [C](application.c#L3516) | [ASM](application.asm#L2692) |
| 0xC015DA | `kwp_negative` | 30 | KWP negative response / unsupported service. | [C](application.c#L3556) | [ASM](application.asm#L2745) |
| 0xC015F8 | `kwp_sid10_session` | 114 | KWP service 0x10 start diagnostic session. | [C](application.c#L3577) | [ASM](application.asm#L2762) |
| 0xC0166A | `kwp_sid83` | 88 | KWP service 0x83 handler (Delphi-specific). | [C](application.c#L3613) | [ASM](application.asm#L2804) |
| 0xC016C2 | `kwp_sid34_download` | 72 | KWP service 0x34 request download. | [C](application.c#L3648) | [ASM](application.asm#L2838) |
| 0xC0170A | `kwp_sid36_transfer` | 158 | KWP service 0x36 transfer data (0x80-byte blocks to flash/RAM). | [C](application.c#L3676) | [ASM](application.asm#L2867) |
| 0xC017A8 | `kwp_sid31_routine` | 66 | KWP service 0x31 start routine. | [C](application.c#L3728) | [ASM](application.asm#L2936) |
| 0xC017EA | `kwp_sid38` | 86 | KWP service 0x38 handler. | [C](application.c#L3756) | [ASM](application.asm#L2964) |
| 0xC01840 | `kwp_sid23_read_mem` | 204 | KWP service 0x23 read memory by address. | [C](application.c#L3786) | [ASM](application.asm#L2997) |
| 0xC0190C | `kwp_sid3D_write_mem` | 200 | KWP service 0x3D write memory by address. | [C](application.c#L3843) | [ASM](application.asm#L3085) |

## Diagnostics / K-line transport

K-line transport state machine.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC01212 | `kline_receive_pattern` | 6 | Receives the 5-byte K-line wake-up pattern and advances state. | [C](application.c#L3895) | [ASM](application.asm#L3169) |
| 0xC12696 | `kline_get_status` | 6 | Returns the K-line status byte 0xC56D. | [C](application.c#L3936) | [ASM](application.asm#L3179) |
| 0xC126B0 | `kline_start_timeout` | 10 | Loads the K-line timeout 0xC56A with 0x0500. | [C](application.c#L3953) | [ASM](application.asm#L3189) |
| 0xC126BC | `kline_state_reset` | 22 | Clears K-line state to 0. | [C](application.c#L3972) | [ASM](application.asm#L3200) |
| 0xC126DA | `kline_prepare_frame` | 200 | Computes K-line timing fields and enters state 6. | [C](application.c#L3998) | [ASM](application.asm#L3215) |
| 0xC12826 | `kline_rx_state_7` | 34 | K-line receive/transport state 7. | [C](application.c#L4047) | [ASM](application.asm#L3288) |
| 0xC12848 | `kline_rx_state_8` | 14 | K-line receive/transport state 8. | [C](application.c#L4073) | [ASM](application.asm#L3307) |
| 0xC1293C | `kline_push_rx_byte` | 50 | Stores a received K-line byte into the IRAM ring at 0xF600. | [C](application.c#L4093) | [ASM](application.asm#L3320) |
| 0xC12982 | `kline_transport_task` | 324 | K-line transport state machine; state 0xC584 selects a handler table at 0x7164. | [C](application.c#L4123) | [ASM](application.asm#L3344) |

## Diagnostics / CAN transport

CAN/ISO-TP diagnostic transport.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC019D6 | `can_diag_object_init` | 70 | Initializes TwinCAN message objects 9/10 with IDs 0x7EE/0x7EF. | [C](application.c#L4208) | [ASM](application.asm#L3461) |
| 0xC01A1C | `can_rx_process` | 184 | TwinCAN receive processing and message-object copy. | [C](application.c#L4233) | [ASM](application.asm#L3487) |
| 0xC01B22 | `can_rx_dispatch` | 194 | Dispatch received CAN message to ISO-TP transport. | [C](application.c#L4276) | [ASM](application.asm#L3556) |
| 0xC01BE4 | `can_rx_cmd` | 138 | CAN diagnostic receive command handling. | [C](application.c#L4315) | [ASM](application.asm#L3630) |
| 0xC01C6E | `can_isotp_send` | 90 | Send up to 8 bytes over the diagnostic CAN message object. | [C](application.c#L4363) | [ASM](application.asm#L3684) |
| 0xC01CC8 | `can_tx_frame` | 210 | Load and transmit one 8-byte CAN frame. | [C](application.c#L4400) | [ASM](application.asm#L3723) |
| 0xC01DEC | `can_tx_confirm` | 212 | Set CAN message object transmission-request/confirm bits. | [C](application.c#L4438) | [ASM](application.asm#L3808) |

## Diagnostics / status

Diagnostic status packing.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC1482C | `diag_status_build` | 464 | Builds the packed diagnostic status bytes 0xC60C..0xC610. | [C](application.c#L4467) | [ASM](application.asm#L3893) |

## Diagnostics / test commands

Actuator/test command dispatch.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC13D50 | `test_command_clear` | 14 | Clears the 0xFD18 command and its counters. | [C](application.c#L4516) | [ASM](application.asm#L4042) |
| 0xC13D5E | `test_command_dispatch` | 106 | Dispatches 0xFD18 actuator/test command bits. | [C](application.c#L4537) | [ASM](application.asm#L4054) |

## Calibration / accessors

Axis/table/map accessors.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC27CA4 | `tbl16_interp` | 168 | 16-bit table lookup with 8.8 fixed-point interpolation. | [C](application.c#L4594) | [ASM](application.asm#L4095) |
| 0xC27FCA | `tbl8_interp` | 182 | 8-bit table lookup with 8.8 fixed-point interpolation. | [C](application.c#L4650) | [ASM](application.asm#L4184) |
| 0xC2826E | `tbl2d_interp` | 482 | 2D 8-bit map lookup with bilinear interpolation. | [C](application.c#L4710) | [ASM](application.asm#L4279) |
| 0xC284D8 | `axis16_signed` | 54 | Signed axis descriptor -> 8.8 fixed-point index. | [C](application.c#L4827) | [ASM](application.asm#L4514) |
| 0xC2850E | `axis16_unsigned` | 54 | Unsigned axis descriptor -> 8.8 fixed-point index. | [C](application.c#L4858) | [ASM](application.asm#L4544) |

## Calibration / checksum

Calibration block checksum.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC11B9A | `cal_checksum` | 90 | Verify calibration block checksum 0xC05000-0xC0AFFD vs 0xC0AFFE. | [C](application.c#L4891) | [ASM](application.asm#L4576) |

## Engine control / events

CC16/CC17 normal event scheduler.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC0BBC4 | `capcom_event_config2` | 50 | Configure one CAPCOM event channel (second form). | [C](application.c#L4925) | [ASM](application.asm#L4617) |
| 0xC0BCA4 | `capcom_event_config` | 176 | Configure one CAPCOM event channel. | [C](application.c#L4959) | [ASM](application.asm#L4643) |
| 0xC0BD58 | `capcom16_17_init` | 70 | CAPCOM CC16/CC17 channel setup. | [C](application.c#L5008) | [ASM](application.asm#L4718) |
| 0xC0BEF0 | `cc_control_ptr_init` | 18 | Caches pointers to 0xFF2C and 0xFE2A. | [C](application.c#L5040) | [ASM](application.asm#L4745) |
| 0xC0BF54 | `cc_irq_enable` | 56 | Sets or clears a per-channel CC interrupt-enable bit. | [C](application.c#L5060) | [ASM](application.asm#L4758) |
| 0xC0BF8C | `cc_irq_is_enabled` | 36 | Tests a per-channel CC interrupt-enable bit in 0xFF2C. | [C](application.c#L5087) | [ASM](application.asm#L4790) |
| 0xC0D39E | `event_start` | 88 | Start event scheduler channels. | [C](application.c#L5115) | [ASM](application.asm#L4814) |
| 0xC0D516 | `event_reset` | 18 | Reset event scheduler state. | [C](application.c#L5148) | [ASM](application.asm#L4857) |
| 0xC0D528 | `event_init` | 58 | Initialize event scheduler channels. | [C](application.c#L5170) | [ASM](application.asm#L4870) |
| 0xC0D6F0 | `event_start_fixed` | 26 | Loads fixed event parameters and starts the CC16/CC17 scheduler. | [C](application.c#L5206) | [ASM](application.asm#L4900) |
| 0xC0DB90 | `cc_irq_enable_bit` | 22 | Enables the CC16/CC17 interrupt bit for a channel ID. | [C](application.c#L5229) | [ASM](application.asm#L4915) |
| 0xC0DBA6 | `cc_compare_mode_set` | 56 | Sets the CC16/CC17 compare-mode bit for a channel ID. | [C](application.c#L5255) | [ASM](application.asm#L4930) |
| 0xC0DBDE | `event_force` | 132 | Force event at fixed offset. | [C](application.c#L5293) | [ASM](application.asm#L4959) |
| 0xC0DC62 | `event_cancel` | 40 | Cancel/initialize one event channel. | [C](application.c#L5327) | [ASM](application.asm#L5023) |
| 0xC0DC8A | `event_schedule` | 428 | Schedule CAPCOM event (dwell/pulse) for a channel. | [C](application.c#L5351) | [ASM](application.asm#L5047) |
| 0xC0E1B6 | `event_idle` | 128 | Set channel to idle. | [C](application.c#L5448) | [ASM](application.asm#L5229) |
| 0xC0E236 | `event_accum` | 70 | Accumulate event time. | [C](application.c#L5486) | [ASM](application.asm#L5290) |
| 0xC0E27C | `event_schedule_duration` | 350 | Schedules a CC16/CC17 event using the 32-bit duration fields. | [C](application.c#L5517) | [ASM](application.asm#L5327) |

## Engine control / CC22-23 outputs

CC22/CC23 actuator/test outputs.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC0BE46 | `cc22_23_output_disable` | 18 | Clears the CC22/CC23 output-enable bits in CCM5. | [C](application.c#L5604) | [ASM](application.asm#L5481) |
| 0xC0BE6A | `cc22_23_schedule` | 134 | Programs the CC22/CC23 compare values from a T7 timestamp. | [C](application.c#L5630) | [ASM](application.asm#L5495) |
| 0xC0BF02 | `cc22_23_output_init` | 62 | Initializes CC22/CC23 interrupt/port/compare pointers. | [C](application.c#L5683) | [ASM](application.asm#L5553) |
| 0xC0E722 | `cc22_23_hysteresis_a` | 62 | Hysteresis thresholds for the first CC22/CC23 input; state in cc22_23_state_machine_a. | [C](application.c#L5723) | [ASM](application.asm#L5580) |
| 0xC0E760 | `cc22_23_hysteresis_b` | 106 | Hysteresis thresholds for the second CC22/CC23 input; state in cc22_23_state_machine_b. | [C](application.c#L5765) | [ASM](application.asm#L5611) |
| 0xC0EBE6 | `cc_output_gate_update` | 38 | Updates the CC output gate bits in 0xFD08/0xFD06. | [C](application.c#L5810) | [ASM](application.asm#L5658) |
| 0xC0F3D2 | `cc22_23_task` | 164 | Periodic task for the CC22/CC23 event pair; uses engine speed/timing input 0xC9D0. | [C](application.c#L5846) | [ASM](application.asm#L5679) |
| 0xC0FACE | `cc22_23_start_pair` | 42 | Starts both CC22/CC23 channels at a common timestamp. | [C](application.c#L5897) | [ASM](application.asm#L5740) |
| 0xC0FB36 | `cc22_23_start_once` | 56 | One-shot start of the CC22/CC23 pair. | [C](application.c#L5927) | [ASM](application.asm#L5765) |
| 0xC0FB8C | `cc_event_timeout_tick` | 64 | Decrements the CC event timeout counters. | [C](application.c#L5955) | [ASM](application.asm#L5792) |

## Engine control / speed

Speed timing conversion.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC0CD24 | `speed_timing_calc` | 214 | Maps engine speed input 0xC9D0 through axis 0x7000 and tables 0x504C/0x5038. | [C](application.c#L5992) | [ASM](application.asm#L5822) |
| 0xC0D562 | `angle_init` | 104 | Initialize angle/time conversion from calibration. | [C](application.c#L6063) | [ASM](application.asm#L5902) |

## Engine control / load

Load/base calculation.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC1FD9C | `calc_load` | 322 | Calibration-based VE/load calculation; axes 0x7564/0x755E, VE map 0x794A, correction 0x79B6; live-data FVE1. | [C](application.c#L6107) | [ASM](application.asm#L5951) |

## Engine control / limits

Limit calculations.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC1596E | `rate_limit` | 78 | Rate limiter / slew helper. | [C](application.c#L6161) | [ASM](application.asm#L6058) |
| 0xC200AA | `calc_limit1` | 260 | Provisional injection-time/limit calculation (table 0x7912); live-data injector-time range cross-check. | [C](application.c#L6199) | [ASM](application.asm#L6103) |
| 0xC201AE | `calc_limit2` | 320 | Provisional spark/limit calculation (tables 0x7860/0x784C); live-data spark-advance range cross-check. | [C](application.c#L6243) | [ASM](application.asm#L6187) |
| 0xC202EE | `calc_limit3` | 170 | Provisional spark/limit calculation (tables 0x7552/0x7912/0x78E2/0x7874/0x78D8). | [C](application.c#L6304) | [ASM](application.asm#L6294) |

## Engine control / sensor

Sensor/config setup.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC0F628 | `config_sensor_setup` | 532 | Selects sensor/ADC handler pointers from calibration config 0xC05036 and builds a float threshold. | [C](application.c#L6340) | [ASM](application.asm#L6355) |

## Runtime library

Fixed-point/software-float and memory helpers.

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC01D9A | `memcpy_wdt` | 40 | Byte copy with watchdog service. | [C](application.c#L6456) | [ASM](application.asm#L6533) |
| 0xC01EC8 | `ret_stub` | 6 | Empty function. | [C](application.c#L6487) | [ASM](application.asm#L6559) |
| 0xC01ECE | `mem_read_word` | 14 | Read two words through a 16:16 pointer. | [C](application.c#L6504) | [ASM](application.asm#L6570) |
| 0xC01EDC | `mem_write_word` | 14 | Write two words through a 16:16 pointer. | [C](application.c#L6521) | [ASM](application.asm#L6585) |
| 0xC01EEA | `seg_to_ptr` | 22 | Convert 16-bit pointer/DPP offset into a 24-bit pointer. | [C](application.c#L6545) | [ASM](application.asm#L6600) |
| 0xC0BFF4 | `empty_stub_1` | 2 | Empty function. | [C](application.c#L6566) | [ASM](application.asm#L6616) |
| 0xC0BFF6 | `empty_stub_2` | 2 | Empty function. | [C](application.c#L6583) | [ASM](application.asm#L6625) |
| 0xC10240 | `empty_stub_3` | 2 | Empty function. | [C](application.c#L6600) | [ASM](application.asm#L6634) |
| 0xC1096E | `div32_checked` | 52 | Checked 32-bit division; returns 0xFFFFFFFF on overflow/zero. | [C](application.c#L6617) | [ASM](application.asm#L6643) |
| 0xC109A2 | `mul_div32` | 24 | 32-bit multiply followed by checked division. | [C](application.c#L6643) | [ASM](application.asm#L6672) |
| 0xC28B64 | `mul32` | 36 | 32x16/32-bit multiply helper. | [C](application.c#L6662) | [ASM](application.asm#L6689) |
| 0xC28BB2 | `div32u` | 148 | 32-bit unsigned division helper. | [C](application.c#L6688) | [ASM](application.asm#L6711) |
| 0xC28C4E | `empty_stub_0` | 6 | Empty function. | [C](application.c#L6751) | [ASM](application.asm#L6780) |
| 0xC28C62 | `store32` | 14 | Stores a 32-bit value as two 16-bit words. | [C](application.c#L6768) | [ASM](application.asm#L6791) |
| 0xC28CA4 | `fp_div_signed` | 28 | Software float division with sign handling. | [C](application.c#L6792) | [ASM](application.asm#L6806) |
| 0xC28CAC | `fp_div_unsigned` | 274 | Software float division helper. | [C](application.c#L6925) | [ASM](application.asm#L6825) |
| 0xC28DBE | `fp_to_int` | 50 | Software float to integer conversion. | [C](application.c#L7055) | [ASM](application.asm#L6955) |
| 0xC28DEC | `fp_neg` | 82 | Software float negation/absolute-value helper. | [C](application.c#L7088) | [ASM](application.asm#L6984) |
| 0xC28E50 | `fp_compare` | 68 | Software float comparison. | [C](application.c#L7120) | [ASM](application.asm#L7025) |
| 0xC28E94 | `fp_pack` | 62 | Packs a software float into four 16-bit words. | [C](application.c#L7177) | [ASM](application.asm#L7065) |
| 0xC28ED2 | `fp_pack_zero` | 56 | Packs a zero software float. | [C](application.c#L7219) | [ASM](application.asm#L7094) |
| 0xC28F0E | `fp_round` | 16 | Rounds and stores a software float. | [C](application.c#L7252) | [ASM](application.asm#L7121) |
| 0xC28F1E | `fp_store` | 64 | Stores four words of a software float. | [C](application.c#L7297) | [ASM](application.asm#L7135) |
| 0xC28F5E | `fp_store_zero` | 14 | Stores a zero software float. | [C](application.c#L7326) | [ASM](application.asm#L7164) |
| 0xC28F6C | `fp_load` | 24 | Loads four words of a software float. | [C](application.c#L7344) | [ASM](application.asm#L7179) |
| 0xC28F84 | `fp_copy` | 16 | Copies four words of a software float. | [C](application.c#L7371) | [ASM](application.asm#L7198) |

Files are Ghidra decompiler output; they are not a compilable translation unit.
