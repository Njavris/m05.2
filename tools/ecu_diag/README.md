# ECU diagnostic console

A separate cross-platform terminal diagnostic tool for the Delphi MT05.2 over
K-line, using the same FT232RL KKL adapter as `ecu_tool`.

It is deliberately read-only for flash: it can read live data, IDs, memory and
dump flash, but it cannot write calibration or firmware.

## Build

```bash
cmake -S tools/ecu_diag -B tools/ecu_diag/build
cmake --build tools/ecu_diag/build
```

The tool links the shared serial/K-line/live-data sources from `ecu_tool/`.

## Use

```bash
./tools/ecu_diag/build/ecu_diag --port /dev/ttyUSB0
```

On Windows use `COM3` (or the actual port). On macOS use the FTDI
`/dev/cu.usbserial-*` device and install the Apple Silicon VCP driver.

Menu:

1. Live data dashboard
2. ECU information (`21 03`, `21 04`, `21 FF`, calibration version)
3. Read DTCs (OBD mode `03`)
4. Read pending DTCs (OBD mode `07`)
5. Clear DTCs (OBD mode `04`)
6. Service/EEPROM reset (`30 8B 00`, experimental)
7. Read memory
8. Dump flash with checksum verification
9. Manual KWP command
T. Toggle frame trace
0. Exit

The DTC and service-reset paths are marked experimental. The recovered
bootloader dispatcher does not implement OBD modes `03`/`04`/`07`; they may be
handled by the application stack. If the ECU returns a negative response, the
tool prints the raw bytes and NRC.

## Safety

Live logging is safe with the bike stationary in neutral. DTC clear and service
reset change ECU state; use them only when intended. This tool does not write
calibration or flash.

## Credits

Analysis and implementation performed by DeepSeek v4.1 Flash 1017.
