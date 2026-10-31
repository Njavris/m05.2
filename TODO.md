# TODO — Njavris

Status: the firmware analysis, reconstruction and `ecu_tool/` build are in place;
the remaining work is mainly hardware validation, mapping the live-data packet
back to RAM, and deciding what is safe to publish.

## 0. Next hardware session (M4 Mac)

- [ ] Bring the M4 Mac, a USB-C to USB-A adapter/hub, the FT232RL KKL adapter,
      the K-line harness and a multimeter.
- [ ] Install the FTDI VCP driver for Apple Silicon and confirm a device such as
      `/dev/cu.usbserial-*` appears.
- [ ] Install Xcode Command Line Tools and CMake, then build `ecu_tool/` natively.
- [ ] Test `live --count 1`, `ids`, `read` and `dump` on the Mac.
- [ ] If macOS fast-init timing is unreliable, try a Linux VM with USB
      passthrough; do not assume the Mac timing is good until tested.
- [ ] Do not run `write-cal` on the Mac until the flash backup and recovery path
      are verified.

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

## 1a. Rev-limit investigation (~9000 rpm target)

- [ ] Treat 9000 rpm as an estimate, not a measured value.
- [ ] Do the limiter test safely on a dyno or closed road, not by holding the
      engine at high rpm in neutral for long periods.
- [ ] Log `21 01` from about 7500 rpm upward and capture the first fuel cut /
      speed-limiter event.
- [ ] Record RPM, MAP, throttle, injector time, dwell and the five status bytes
      at the moment the limiter cuts.
- [ ] Read external RAM at `0x7000` and `0x7564` during the same session.
- [ ] Determine whether those addresses are external RAM, memory-mapped NVM, or
      a serial EEPROM copy; compare the read bytes with calibration candidates.
- [ ] Resolve the DPP page used by `calc_load`/`speed_timing_calc` so the
      physical address of `0x7564` is known.
- [ ] Convert the measured cut RPM back through the axis to check whether the
      raw threshold `0x1450` is the limiter or only one part of it.
- [ ] If the observed cut is near 9000 rpm and the raw threshold does not fit,
      look for a second limiter path in `calc_limit1`/`calc_limit3`.

## 2. Flash/calibration write safety

- [ ] Keep at least one verified full-flash backup.
- [ ] Establish a recovery path (bench harness, spare ECU/BDM, or known-good
      calibration) before using `write-cal`.
- [ ] Treat `write-cal` as experimental: it uses `27` + `34` + `36`, asks
      backup/recovery/engine-state questions interactively, and has only been
      tested against the offline fake ECU, not real hardware.
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
