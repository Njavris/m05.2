# TODO — Njavris

Status: the firmware analysis, reconstruction and `ecu_tool/` build are in place;
the remaining work is mainly hardware validation, mapping the live-data packet
back to RAM, and deciding what is safe to publish.

## 1. Hardware validation

- [ ] Build the tool:
  ```bash
  cmake -S ecu_tool -B ecu_tool/build
  cmake --build ecu_tool/build
  ./ecu_tool/build/ecu_tool selftest
  ```
- [ ] Connect the FT232RL KKL adapter (K-line, ground, +12 V) and identify the
      serial port (`/dev/ttyUSB0` or `COM3`).
- [ ] Test connection:
  ```bash
  ./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 --verbose live --count 1
  ```
- [ ] If StartCommunication fails, capture the verbose trace and check fast-init
      timing; 5-baud init is **not implemented yet**.
- [ ] Log live data at idle and several steady RPMs:
  ```bash
  ./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 --csv live --count 60
  ```
- [ ] Dump the full flash and verify checksums:
  ```bash
  ./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 dump --out backup_flash.bin
  ```
- [ ] Read the missing external-RAM regions while the ECU is powered:
  ```bash
  ./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 read --addr 0x7000 --len 0x40 --out xram_7000.bin
  ./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 read --addr 0x7500 --len 0x80 --out xram_7500.bin
  ./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 read --addr 0x7050 --len 0x100 --out xram_7050.bin
  ./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 read --addr 0x7160 --len 0x100 --out xram_7160.bin
  ./ecu_tool/build/ecu_tool --port /dev/ttyUSB0 read --addr 0x7660 --len 0x100 --out xram_7660.bin
  ```
- [ ] If `0x23` rejects those RAM addresses, use XC164 OCDS/JTAG or dump the
      external EEPROM/SSC device instead.
- [ ] Decode the 6-byte axis descriptors `{count, min, max}` at `0x7000` and
      `0x7564`, then convert the rev-limit threshold `0x1450` to RPM.
- [ ] Confirm the five live-data status bytes on this specific bike.
- [ ] Test the Windows and macOS builds; only Linux has been exercised so far.

## 2. Flash/calibration write safety

- [ ] Keep at least one verified full-flash backup.
- [ ] Establish a recovery path (bench harness, spare ECU/BDM, or known-good
      calibration) before using `write-cal`.
- [ ] Treat `write-cal` as experimental: it uses `27` + `34` + `36` and has only
      been tested against the offline fake ECU, not real hardware.
- [ ] Do not attempt boot/application writes with the current tool.

## 3. Live-data and calibration mapping

- [ ] Capture `21 01` and `30` traffic at idle, part load and high load.
- [ ] Match each packet offset to its source RAM cell/function.
- [ ] Fit the `0xC0794A` volume-efficiency map axes from the logs.
- [ ] Verify the `0xC07860`/`0xC07874` spark-advance hypothesis and the
      `0xC07912` injector-time/limit hypothesis.
- [ ] Identify the application-side `0x21`/`0x30` handler and the table at
      `0x7164` if the external-RAM read does not expose it.

## 4. Publication and legal

- [ ] Decide whether to publish the vendor firmware dumps, decompiled output,
      calibration data and fixed diagnostic seed/key. Get a legal review first.
- [ ] Confirm `LICENSE` and `NOTICE` correctly exclude vendor materials.
- [ ] For a public-safe release, replace `dumps/` with hashes and a
      “supply your own dump” workflow, then adjust `make test`/`make repro`.
- [ ] Check that private profiles, logs and the ignored `secret/`/`incoming/`
      directories are not tracked:
  ```bash
  git status --short
  git ls-files | grep -E '(^|/)(secret|incoming)/'
  ```
- [ ] Set a real Git author email if desired; it is currently
      `njavris@localhost`.
- [ ] Add a remote and push only after the checks above.

## 5. Optional polish

- [ ] Add 5-baud initialization support.
- [ ] Add wiring/photos and adapter notes to `ecu_tool/README.md`.
- [ ] Add a release tag and short changelog.
