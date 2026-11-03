# 5. Communications and diagnostics

The ECU implements two diagnostic transports that share one KWP2000-style
service layer:

* **K-line / ISO 14230 (KWP2000)** on ASC0 (UART).
* **CAN / ISO-TP-like transport** on the XC164 TwinCAN module.

A separate synchronous serial channel (SSC0) handles a 7-byte peripheral frame
stream (likely an external EEPROM or sensor; see 5.6).

## 5.1 K-line physical/frame layer

Observed in `asc0_state5` (0xC013E8) and `asc0_init` (0xC00C36):

| Item | Value |
|---|---|
| UART | ASC0 |
| Baud generator | `S0BG = 0x9C` (156) in the application init |
| UART control | `S0CON = 0x811` |
| Format byte | `0x80` |
| Tester address | `0xF1` |
| ECU address | `0x11` |
| Frame checksum | 8-bit sum of the header+payload bytes |

The application sets `S0BG = 0x9C` (156). At a 26.1 MHz CPU clock this is
about 10.4 kbaud; the exact clock is not measured. The boot `asc0_init` can
also load 0x1CE or 0xCD, which are slower/faster bootloader rates.

A response frame is built in RAM at 0xC0B2:

```
0xC0B2: 0x80        format
0xC0B3: 0xF1        target (tester)
0xC0B4: 0x11        source (ECU)
0xC0B5: length      payload length
0xC0B6..: payload   service response + data
...: checksum       8-bit sum of the preceding length+4 bytes
```

The K-line state machine is dispatched by `asc0_state_dispatch` (0xC01144) from
the timer 7 ISR. The dispatcher reads a 6-entry table at 0xC00428:

| State | Entry | Function | Role |
|---:|---|---|---|
| 0 | 0xC00428 | 0xC01158 → 0xC01188 | idle / start |
| 1 | 0xC0042A | 0xC0115E → 0xC0119E | wake-up / 5-baud handling |
| 2 | 0xC0042C | 0xC01164 → 0xC011D6 | receive frame bytes |
| 3 | 0xC0042E | 0xC0116A → 0xC01252 | receive/validate |
| 4 | 0xC00430 | 0xC01170 → 0xC012E6 | transmit response |
| 5 | 0xC00432 | 0xC01176 → 0xC013E8 | finish/checksum |

The state variable is 0xC0AF. The receive buffer and service request bytes begin
at 0xC147/0xC148. The K-line state machine was likely entered after a 5-baud
wake-up; the exact timing is inferred from the state names and the use of
P3.11/S0RIC/S0CON.

## 5.2 KWP2000 service dispatcher

The service request bytes are in RAM at:

| Byte | Meaning |
|---|---|
| 0xC147 | first service byte (used for the 0x81 special case) |
| 0xC148 | service identifier (SID) |
| 0xC149.. | sub-function / address / data |

`kwp_dispatch` at 0xC01482 selects the handler:

| SID | Handler | Positive response | Observed behavior |
|---:|---|---|---|
| 0x81 | 0xC0151C | 0xC1 + key bytes | StartCommunication; returns `C1 EF 8F` |
| 0x10 | 0xC015F8 | 0x50 | StartDiagnosticSession; sessions 0x81/0x85 |
| 0x83 | 0xC0166A | 0xC3 | Access Timing Parameters; returns `C3 00 00 FF 00 FF 00` or `C3 03` |
| 0x23 | 0xC01840 | 0x63 | ReadMemoryByAddress |
| 0x27 | 0xC01544 | 0x67 | SecurityAccess |
| 0x31 | 0xC017A8 | 0x71 | StartRoutineByLocalIdentifier |
| 0x34 | 0xC016C2 | 0x74 | RequestDownload |
| 0x36 | 0xC0170A | 0x76 | TransferData |
| 0x38 | 0xC017EA | 0x78 | StartRoutineByAddress / address echo |
| 0x3D | 0xC0190C | 0x7D | Write memory / write data by local identifier |
| other | 0xC015DA | 0x7F | negative response |

A negative response is built at 0xC0B6 as `7F <SID> <NRC>`; the common
unsupported-service NRC path is 0x7F 0x10 0x01 for the default case.

The **live-data services** used by live-data are not in this boot dispatcher:

* `0x21 01` returns the 100-byte live-data packet.
* `0x21 03` / `0x21 04` / `0x21 FF` return hardware/software IDs and the
  ignition counter.
* `0x30` performs data slewing on selected values.

They must be handled by the application K-line stack; see
`12-debug-channels.md`. The boot dispatcher only implements the
memory/reflash/security services listed above.

### Security access (SID 0x27)

`kwp_sid27_security` at 0xC01544 uses a **fixed seed/key**:

* Seed request (sub-function 1): positive response `67 01 12 34`
  (seed = **0x1234**).
* Key request (sub-function 2): the code accepts the two key bytes
  `0x84 0x74` (**0x8474**) and sets the "security unlocked" flag at 0xC09A.
* The positive key response is `67 02 34`; a wrong key returns `7F 27 35` (NRC 0x35, invalid key).

This is not a rolling seed; it is a static development/production unlock. It is
documented here as observed firmware behavior, not as an exploitation guide.

### Memory read/write services

* **0x23 ReadMemoryByAddress** (0xC01840) copies up to 0x80 bytes from a 24-bit
  address into the response buffer. The code applies 24-bit range checks before reading; the exact allowed
  windows are encoded in the comparisons at 0xC018xx (the constants reference
  the 0x00C0xx and 0x00E0xx regions).
* **0x3D WriteMemoryByAddress** (0xC0190C) writes up to 0x80 bytes to a 24-bit
  address, with similar range checks.
* **0x34 RequestDownload** (0xC016C2) requires the security flag; it returns
  `74 FB`.
* **0x36 TransferData** (0xC0170A) writes **0x80-byte blocks** to a 24-bit
  address computed from the request bytes. This is the flash/EEPROM programming
  data path.
* **0x38** (0xC017EA) echoes the 24-bit address in a `78` response; it is part
  of the download/transfer sequence.
* **0x83** is Delphi-specific; the returned bytes look like an identification
  or data-record response.

The presence of 0x23/0x27/0x34/0x36/0x3D is a complete read/write/reflash
capability over the diagnostic link, gated by the static security access.

## 5.3 CAN / TwinCAN

The XC164CS TwinCAN registers are at **0x200000–0x2007FF** and are accessed
through the LXBus. `can_twincan_init` at 0xC00434 configures:

| Register | Value | Meaning |
|---|---:|---|
| 0x20020C | 0x2387 | CAN bit-timing register |
| 0x20030A | 0x1F80 | Node 0 message object 0 arbitration = **ID 0x7E0** |
| 0x20050A | 0x1F90 | Node 1 message object 0 arbitration = **ID 0x7E4** |
| 0x20030C/0x20030E | 0xFFFF | acceptance mask |
| 0x200310 | 0x1599 | message-object control |
| 0x200510 | 0x1595 | message-object control |
| message objects | 15 per node | loop at 0x200300+0x20*i and 0x200500+0x20*i |

The arbitration values are left-shifted by 2 (`0x7E0 << 2 = 0x1F80`,
`0x7E4 << 2 = 0x1F90`), which is the standard C166 CAN ID register layout.
These are the **ISO 15765 diagnostic request IDs** observed for the two CAN
nodes. The application transport functions use message objects 9/10
(0x200430/0x200450), which the application may reconfigure; the exact mapping
from those objects to 0x7E0/0x7E4 is inferred. The response IDs are normally
0x7E8 and 0x7EC; that part is also inferred, not directly printed in the image.

CAN receive path:

* `can0_isr` (0xC00694) services node 0.
* `can_rx_process` (0xC01A1C) copies a received message object into the
  diagnostic buffer (8 bytes at 0xC3740).
* `can_rx_dispatch` (0xC01B22) feeds the ISO-TP-like transport for message
  objects 9/10.
* `can_isotp_send` (0xC01C6E) sends up to 8 bytes from a buffer.
* `can_tx_frame` (0xC01CC8) loads 8 bytes from 0xC3750 into the CAN message
  object at 0x200420, sets the DLC, and requests transmission.
* `can_tx_confirm` (0xC01DEC) handles the transmit-request/confirm bits.

The CAN transport uses IRAM buffers at **0xF740–0xF747** (receive) and
0xC3750 (transmit staging). The service payload is the same KWP2000 payload
used on K-line; the timer 7 ISR dispatches it through `kwp_dispatch`.

## 5.4 OBD-II strings

At 0xC0B680 there is a pointer table and ASCII strings:

```
0xC0B69A  "-Engine Control"
0xC0B6AA  "ECM"
0xC0B6AE  "-Powertrain Ctrl"
0xC0B6BE  "PCM"
```

These are the standard OBD-II **Service 09 PID 0A** ECU-name strings
(`ECM - Engine Control`, `PCM - Powertrain Control`). Their presence and the
adjacent 16-bit pointer table are strong evidence that the firmware also
supports OBD-II mode 09. The exact OBD handler was not fully traced; the
strings are observed, the service mapping is inferred.

## 5.5 Diagnostic address summary

| Transport | Request | Response | Notes |
|---|---|---|---|
| K-line | tester 0xF1 → ECU 0x11 | ECU 0x11 → tester 0xF1 | format byte 0x80 |
| CAN node 0 | 0x7E0 | 0x7E8 (typical) | 11-bit IDs |
| CAN node 1 | 0x7E4 | 0x7EC (typical) | 11-bit IDs |

## 5.6 SSC0 7-byte frame engine

SSC0 is a separate synchronous serial channel, not the K-line UART:

* `ssc0_init_app` (0xC0FF00) configures SSCCON, baud and P3 pins.
* `ssc_send_byte` (0xC00E08) writes to SSCTB.
* `ssc0_rx_isr` (0xC00E14) reads SSCRB into a 7-byte buffer at 0xC078.
* `ssc_start_frame` (0xC00ECA) sets up a 7-byte transfer.

The 7-byte frame length and the buffer at 0xC078 suggest a small external
peripheral. The adaptation log at 0xC04000 is a plausible external EEPROM
image, but this is not proven; the device could also be a sensor or a smart
driver. Treat the SSC target as **unknown**.

## 5.7 Confidence

* K-line frame layout, ECU/tester addresses, KWP service IDs: **high**
  (directly visible in the K-line state machine and handlers).
* Security seed/key: **high** (constants in code).
* CAN IDs 0x7E0/0x7E4: **high** (arbitration values); response IDs **inferred**.
* OBD support: **high** for the strings, **inferred** for the exact service path.
* SSC target: **unknown**.
