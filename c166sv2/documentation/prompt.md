Continue the Mash Black Seven 125 / Delphi MT05.2 project in `/home/user/mash`.

Read `TODO.md` first. Then read:

- `docs/12-debug-channels.md`
- `docs/13-live-data-inferences.md`
- `docs/06-calibration.md`
- `docs/07-engine-control.md`
- `firmware/SEMANTIC_NAMES.md`
- the current `tools/ecu_tool/` and `tools/ecu_diag/` sources

I have new data here:

- `incoming/xram_7000.bin`
- `incoming/xram_7500.bin`
- `incoming/live_*.csv`
- `incoming/trace_*.log`
- `incoming/mac_test_*.txt`

Replace that list with the actual files I provide under `incoming/`.

Inspect and validate the new files first. Do not ask me to repeat information already in the repository. Tell me exactly what is missing or inconsistent.

Priorities:

1. Decode external memory at `0x7000`, `0x755E`, `0x7564`, `0x705E`, `0x7164` and `0x7666`.
2. Resolve the DPP page and whether those addresses are external RAM, flash, memory-mapped NVM or EEPROM.
3. Convert the `0x1450` rev-limit threshold into RPM and check the ~9000 rpm estimate; verify `calc_limit1/2/3`.
4. Fit the `0xC0794A` VE map axes from the `21 01` logs; validate the `0xC07860`/`0xC07874` spark hypothesis and `0xC07912` injector hypothesis.
5. Update docs, artifacts and reconstruction C data, and tick off completed TODO items.
6. Run `make test`, `make repro`, `make maps`, `make reconstruction`, compile `reconstruction/03-data/data.c`, and run the tool tests.
7. Fix any Mac/Windows portability or timing issues revealed by the new results.
8. Commit locally under **Njavris**. Do not push. Keep private capture data out of Git.

Be explicit about what is measured versus inferred. End with findings, changed files, test results and the commit hash.
