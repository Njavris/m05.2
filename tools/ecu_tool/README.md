# ECU K-line tool

A small cross-platform C11 command-line tool for the Delphi MT05.2 ECU over
K-line (ISO 14230 / KWP2000) using an **FT232RL-based KKL / VAG KKL adapter**.
It uses the FTDI virtual COM port, so no libftdi or vendor DLL is required.

The tool can:

- poll `21 01` and display live engine data
- dump the complete 256 KB flash with `23` ReadMemoryByAddress
- read arbitrary memory ranges
- read hardware/software IDs and the calibration version
- **experimentally** write the calibration block with `27` + `34` + `36`

## Hardware

Use an FT232RL KKL adapter with the FTDI VCP driver installed. Connect:

```text
adapter K-line (pin 7) -> ECU K-line
adapter ground (pin 4/5) -> ECU ground
adapter +12 V (pin 16) -> ECU +12 V
```

The ECU is addressed as `0x11`; the tester is `0xF1`; the link is 10400 baud,
8N1, ISO 14230 fast init.

On Linux the user normally needs `dialout` access:

```bash
sudo usermod -aG dialout "$USER"
```

On Windows the adapter appears as `COM3`, `COM4`, etc. On macOS use the FTDI
serial device and the FTDI VCP driver; the tool uses `IOSSIOSPEED` for 10400 baud.

## Build

```bash
cmake -S ecu_tool -B ecu_tool/build
cmake --build ecu_tool/build
```

or directly:

```bash
cc -std=c11 -O2 -Wall -Wextra -Wpedantic \
   -Iecu_tool/src ecu_tool/src/*.c -o ecu_tool/build/ecu_tool
```

## Commands

```bash
# live dashboard
./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 live

# CSV log, 60 samples at 250 ms
./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 --csv live --count 60

# full 256 KB flash dump
./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 dump --out mash_read.bin

# read 16 calibration bytes
./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 \
    read --addr 0xC05000 --len 16

# hardware/software IDs and calibration version
./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 ids

# offline checks
./ecu_tool/build/ecu_tool selftest
```

Use `--verbose` to print TX/RX frames. On Windows replace `/dev/ttyUSB0` with
`COM3` (or the actual port).

## Live fields

The `21 01` packet is 100 bytes after `61 01`. The tool prints engine speed,
MAP, throttle, coolant, inlet air, ignition voltage, O2, injector time, dwell,
spark advance, volume efficiency, AFR, idle target, vehicle speed, fuel-pump
duty, purge and runtime, plus the five status bytes. `--status` expands the
status bits.

CSV mode prints the same fields plus the five raw status bytes.

## Flash read

`dump` reads `0xC00000..0xC3FFFF` in `0x80`-byte chunks and verifies the three
stored checksums (boot, calibration, application). A checksum mismatch is
reported; the image is still written for inspection.

## Dump everything

```bash
./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 \
    dump-all --out incoming/session_001
```

or:

```bash
./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 \
    --dump-all --out incoming/session_001
```

The directory contains:

- `flash.bin` — full 256 KB flash, with `checksums.txt`
- `xram_0000_7fff.bin` — 32 KB external-RAM window
- `eeprom_4000.bin` — 4 KB EEPROM candidate at `0x4000`
- `iram_c000_cfff.bin`, `xram_e000_e7ff.bin`, `iram_f600_fdff.bin`
- targeted reads: `axis_7000.bin`, `axis_7500.bin`, `table_7050.bin`, `handler_7160.bin`, `table_7660.bin`
- `ids.txt`, `live_21_01.bin`, `metadata.txt`, `failures.txt`

It continues after a rejected window and records the exact range and error. A
failed window does not mean the whole ECU read failed. Only K-line-accessible
memory is covered; SFRs and a serial EEPROM behind SSC0 still need JTAG/OCDS or
a chip/bus capture.

## Calibration write (experimental)

```bash
./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 \
    write-cal --file tuned.bin --i-understand
```

`tuned.bin` may be either a full 256 KB image (calibration block at `0x5000`) or
a standalone 24 KB calibration block. The tool recalculates the calibration
checksum at `0xC0AFFE`, unlocks security, sends `34`, writes `0x80`-byte blocks
with `36`, and reads the block back for verification.

When run interactively it asks:

1. Do you have a verified full-flash backup?
2. Do you have a recovery path if the ECU does not boot?
3. Is the engine off and the ignition stable?
4. Type `WRITE` exactly to confirm.

Non-interactive writes are refused unless `--i-understand` is supplied for
automation.

**This path is experimental.** The exact erase/programming sequence of the
bootloader was not fully recovered. A failed or partial write can leave the ECU
unbootable. The tool only writes the calibration block, never boot or
application.

## Protocol notes

- Request frame: `80 11 F1 <len> <payload> <sum>`
- Response frame: `80 F1 11 <len> <payload> <sum>`
- Checksum: 8-bit sum of all bytes before the checksum
- Fast init: K-line low 25 ms, high 25 ms, then `81` StartCommunication
- Live data: `21 01`, 100-byte response
- Read memory: `23 <addr24> <count>` (count up to `0x80`)
- Security: seed `27 01`, fixed key `27 02 84 74`
- Calibration write: `34`, then `36 <addr24> <128 bytes>`

5-baud initialization and CAN are not implemented.

## Tests

```bash
./ecu_tool/build/ecu_tool selftest
python3 ecu_tool/tests/fake_ecu.py ecu_tool/build/ecu_tool
```

The second test creates a PTY, emulates StartCommunication, live data, flash
read and calibration transfer, and runs the tool end-to-end without hardware.
`ecu_tool/tests/fault_tests.py` covers negative responses, short live packets,
bad read responses and checksum-mismatched dumps.

## Credits

Analysis, reverse engineering, documentation and implementation were performed by
**DeepSeek v4.1 Flash 1017**.

## Safety

Run live logging with the bike stationary and in neutral. Do not write
calibration data unless you have a verified backup and a recovery path.
