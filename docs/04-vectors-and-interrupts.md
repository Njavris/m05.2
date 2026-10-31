# 4. Vector table and interrupts

## 4.1 Format

The vector table is at `0xC00000` and occupies the first 0x200 bytes of flash.
It contains **128 four-byte slots** (default XC164 `VECSC = 4`, i.e. a 4-byte
distance between vectors). Each active slot is a C166 `JMPS seg, offset`
instruction; inactive slots are `FA 00 00 00` (`JMPS 0:0`).

The whole table lives in the boot block and is therefore covered by the boot
checksum (0xEE88).

## 4.2 Active vectors

Only eight slots are non-zero:

| Vector address | Source (XC164CS name) | Target | Handler |
|---|---|---|---|
| 0xC00000 | RESET | 0xC00A78 | `boot_reset` |
| 0xC00010 | STOTRAP (stack overflow) | 0xC00F0C | `trap_stack_overflow` |
| 0xC00018 | STUTRAP (stack underflow) | 0xC00F6A | `trap_stack_underflow` |
| 0xC00028 | BTRAP (bootstrap trap) | 0xC00FC8 | `trap_bootstrap` |
| 0xC000B8 | SSC0_RIC (SSC0 receive) | 0xC00E14 | `ssc0_rx_isr` |
| 0xC000F4 | T7IC (CAPCOM timer 7) | 0xC00D34 | `timer7_isr` |
| 0xC0010C | PLLIC (PLL/oscillator watchdog) | 0xC01048 | `pll_isr` |
| 0xC00150 | CAN0IC (TwinCAN node 0) | 0xC00694 | `can0_isr` |

All other slots are `JMPS 0:0`. The full machine-readable list, including the
unused entries and the datasheet names, is in `artifacts/vector_table.csv`.

The vector numbers and names come from the XC164CS datasheet Table 4. The
image's active offsets match the datasheet's default 4-byte vector spacing
exactly: 0x00, 0x10, 0x18, 0x28, 0xB8, 0xF4, 0x10C, 0x150.

## 4.3 Why so few interrupts?

The XC164 has a **Peripheral Event Controller (PEC)** that can move bytes/words
without a normal interrupt. Many serial and ADC transfers can therefore run
without an ISR. The firmware enables only:

* the 1 ms timer 7 interrupt (system tick and communication state machines),
* the CAN0 interrupt (diagnostic receive),
* the SSC0 receive interrupt (synchronous serial frame engine),
* the PLL/oscillator watchdog interrupt (fatal clock fault → reset),
* the three hardware traps.

This is consistent with a small engine ECU: most ADC/serial work is polled or
PEC-driven, while the 1 ms tick drives the control/communication scheduler.

## 4.4 ISR descriptions

### Timer 7 — 0xC00D34 (`timer7_isr`)

* Saves the C166 context (`DAT_00FC40 = SP`, DPPs, arithmetic registers).
* Calls `asc0_state_dispatch` at 0xC01144 — the K-line state machine.
* Calls `kwp_dispatch` at 0xC01482 — the KWP2000 service dispatcher.
* Maintains a free-running 16-bit counter at 0xC06E, wrapping at 1000.
* Restores context and executes `RETI`.

This is the **1 ms system tick** (the exact tick period depends on the T7
reload value and CPU clock; the counter wraps at 1000, consistent with a
1 ms tick and a 1 s secondary counter).

### CAN0 — 0xC00694 (`can0_isr`)

* Saves context.
* Calls `can_rx_process` (0xC01A1C).
* Polls the TwinCAN status/message-object registers at 0x200284 and 0x200310.
* Handles message object 0, the diagnostic request object.
* Sets a flag at 0xC016 when a message is accepted.
* Restores context and executes `RETI`.

The CAN transport itself is described in [05](05-communications.md).

### SSC0 receive — 0xC00E14 (`ssc0_rx_isr`)

* Saves context.
* Reads `SSCRB` (SSC receive buffer) into the 7-byte frame buffer at 0xC078.
* Decrements a byte counter at 0xC094; when it reaches zero it resets the
  pointers and starts the next 7-byte frame.
* Toggles P1H.3 as a frame marker.
* Calls `ssc_send_byte` for the next byte.

This is a **7-byte synchronous serial frame engine**. The peripheral could be an
external serial EEPROM, a smart driver, or a sensor; the exact device is not
identified. The adaptation log at 0xC04000 is a plausible EEPROM image, but the
link is not proven.

### PLL — 0xC01048 (`pll_isr`)

* Saves context, then executes `SRST` (software reset).
* The restore path is present but unreachable after a reset.

This is the clock-fault safety path.

### Traps — 0xC00F0C / 0xC00F6A / 0xC00FC8

The trap handlers preserve context and record/flag the fault. The exact
recovery behavior is not fully reconstructed; they are part of the C166
runtime/trap layer.

## 4.5 Interrupt-related firmware constants

| Item | Value / address | Notes |
|---|---|---|
| Vector table base | 0xC00000 | `VECSEG` selects segment 0xC0 |
| Vector spacing | 4 bytes | default `VECSC` |
| Timer 7 counter | 0xC06E, wraps at 1000 | 1 ms tick likely |
| CAN0 message-object 0 | 0x200300 + 0x00 | ID 0x7E0 |
| CAN1 message-object 0 | 0x200500 + 0x00 | ID 0x7E4 |
| SSC frame buffer | 0xC078–0xC08F | 7-byte frames |
| CAN RX buffer | 0xF740–0xF747 | IRAM |
