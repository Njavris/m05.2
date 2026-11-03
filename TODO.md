# TODO — Njavris

Status: the firmware analysis, whole-image disassembly, reconstruction and
`tools/ecu_tool/` build are in place; the remaining work is mainly semantic naming of
the newly recovered functions, hardware validation, mapping the live-data packet
back to RAM, and deciding what is safe to publish.

## 0. Full disassembly follow-up

- [x] Run the C166SV2 whole-image Ghidra pass: 902 functions, 46,430 instructions,
      all 262,144 bytes covered in `c166sv2/deliverables/artifacts/ghidra-full/flash.lst`.
- [x] Run the earlier evidence-based naming pass over the post-195 functions:
      24 high, 77 medium, 606 low-confidence placeholders (superseded by the
      full 902-entry catalog below); see `c166/deliverables/firmware/AUTO_NAMES.csv`,
      `c166/deliverables/firmware/AUTO_VARIABLES.csv`, `c166/deliverables/reconstruction/03-data/auto_functions.c`
      and `c166sv2/documentation/report/16-auto-naming.md`.
- [x] Promote the medium/high-confidence names into the full catalog:
      `c166sv2/deliverables/reconstruction/full/catalog/FUNCTIONS.csv` (220 high, 340 medium,
      342 low after iterative call-graph refinement).
- [x] Build the normal C11 project in `c166sv2/deliverables/reconstruction/full/`: CMake,
      catalog accessors, tests, HUD live-data tables and 1,804-file reference tree.
- [x] Parse HUD ECU Hacker profile/translation/tuning/log evidence into
      `c166sv2/deliverables/reconstruction/full/catalog/HUD_*.csv`.
- [ ] Resolve or delete the 342 low-confidence `<domain>_sub_<address>` names.
- [ ] Resolve the 37 remaining byte gaps in
      `c166sv2/documentation/ghidra-full/coverage.csv`; most are data tables or padding.
- [ ] Review the 342 low-confidence catalog names and promote only the ones
      with new table/variable/caller evidence.
- [ ] Decide what the hidden `0xC02000-0xC03DF6` boot/test block is and whether
      it is reachable from an external bootstrap path.
- [ ] Map the ten `farcall_*` entry points and the 0xC10000 trampoline table to
      their diagnostic or engine-control roles.
- [ ] Reconcile the 902-function C166SV2 pass with the curated 195-function reference;
      keep the latter as the reviewed source until naming catches up.

## 0a. Next hardware session (M4 Mac)

- [ ] Bring the M4 Mac, a USB-C to USB-A adapter/hub, the FT232RL KKL adapter,
      the K-line harness and a multimeter.
- [ ] Install the FTDI VCP driver for Apple Silicon and confirm a device such as
      `/dev/cu.usbserial-*` appears.
- [ ] Install Xcode Command Line Tools and CMake, then build `tools/ecu_tool/` natively.
- [ ] Test `live --count 1`, `ids`, `read` and `dump` on the Mac.
- [ ] If macOS fast-init timing is unreliable, try a Linux VM with USB
      passthrough; do not assume the Mac timing is good until tested.
- [ ] Do not run `write-cal` on the Mac until the flash backup and recovery path
      are verified.

## 1. Hardware validation

- [ ] Build the tool:
  ```bash
  cmake -S tools/ecu_tool -B tools/ecu_tool/build
  cmake --build tools/ecu_tool/build
  ./tools/ecu_tool/build/ecu_tool selftest
  ```
- [ ] Connect the FT232RL KKL adapter (K-line, ground, +12 V) and identify the
      serial port (`/dev/ttyUSB0` or `COM3`).
- [ ] Test connection:
  ```bash
  ./tools/ecu_tool/build/ecu_tool --port /dev/ttyUSB0 --verbose live --count 1
  ```
- [ ] If StartCommunication fails, capture the verbose trace and check fast-init
      timing; 5-baud init is **not implemented yet**.
- [ ] Log live data at idle and several steady RPMs:
  ```bash
  ./tools/ecu_tool/build/ecu_tool --port /dev/ttyUSB0 --csv live --count 60
  ```
- [ ] Dump the full flash and verify checksums:
  ```bash
  ./tools/ecu_tool/build/ecu_tool --port /dev/ttyUSB0 dump --out backup_flash.bin
  ```
- [x] Account for the logical `0x705E`, `0x7164`, `0x7500`, `0x7564` and
      `0x7666` tables: they are DPP1-mapped flash at `0xC0Bxxx`, not missing RAM.
- [ ] Optional runtime snapshot of ordinary external RAM `0x0000–0x7FFF`; this
      is no longer required to recover the axis/task/table contents.
- [ ] If `0x23` rejects ordinary RAM addresses, use XC164 OCDS/JTAG or read the
      external EEPROM/SSC device instead.
- [x] Decode the axis descriptors from flash `0xC0B50A–0xC0B564`; convert the
      rev-limit threshold `0x1450` after the runtime cut is measured.
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
- [x] Resolve the DPP page used by `calc_load`/`speed_timing_calc`:
      `DPP1 = 0x302`, so logical `0x7564` is physical `0xC0B564`.
- [ ] Compare the decoded `0xC0Bxxx` axis values with live-data RPM/MAP and
      confirm the rev-limit path.
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
- [ ] Identify the application-side `0x21`/`0x30` handler; the dispatch table at
      logical `0x7164` is present at flash `0xC0B164`.

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
- [ ] Add wiring/photos and adapter notes to `tools/ecu_tool/README.md`.
- [ ] Add a release tag and short changelog.
