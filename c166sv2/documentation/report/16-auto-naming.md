# 16. Evidence-based naming of the post-195 functions

## 16.1 What was named

The curated map in `c166/deliverables/firmware/SEMANTIC_INDEX.csv` has 195 reviewed functions.
The C166SV2 whole-image pass has 902 functions, leaving 707 post-195 entries
(`FUN_*`, `gap_*`, `farcall_*`). The naming table gives evidence-based names to
all 707: 525 names carried over by address from the XC164CS pass and 182 new
C166SV2 gap entries:

| Confidence | Count | Meaning |
|---|---:|---|
| high | 24 | direct callee/table/constant evidence; hidden-boot or named helper |
| medium | 77 | one strong signal (map table, axis call, named variable write, or DTC bit helper) |
| low | 606 | no strong semantic signal; name is address-derived, not a proven role |

The names are in `c166/deliverables/firmware/AUTO_NAMES.csv` and the C reconstruction array
`c166/deliverables/reconstruction/03-data/auto_functions.c`. The superseded 1,157-row XC164CS
table is archived as `c166/deliverables/firmware/AUTO_NAMES_XC164CS.csv`.

## 16.2 Naming rules

A name is evidence-based only when it is supported by one of these observations:

1. **Direct table/axis call**: the decompiled function calls
   `tbl2d_interp(0x....,0xC0,...)`, `tbl8_interp`, `tbl16_interp`,
   `axis16_unsigned`, or `axis16_signed`. The table address is part of the
   name, e.g. `calc_map_70f6`, `map_56d4_c15eda`.
2. **Named callee**: the function calls an already reviewed helper such as
   `rate_limit`, `dtc_status_bit5`, `boot_hidden_memcpy`, or `mul32`/`div32u`.
3. **Named variable access**: the function writes or reads a canonical variable
   with a non-generic name (`engine_speed_input`, `limit_flag_*`,
   `scheduler_event_flag`, etc.).
4. **Hidden-block structure**: the hidden boot/test block at
   `0xC02000-0xC03DF6` was named from its external-command loop and helper
   roles, not from an original symbol table.
5. **Function shape only**: if none of the above exists, the name is
   `<domain>_sub_<address>` and confidence is `low`. It is a placeholder, not a
   semantic claim.

Names that merely restate a generic `DAT_00...` or `ram_var_...` write were
downgraded to low confidence.

## 16.3 High-value names

Examples:

| Address | Name | Evidence |
|---|---|---|
| 0xC02000 | `boot_hidden_main` | hidden-block entry; polls external `0xE00000`, services watchdog |
| 0xC02140 | `boot_hidden_periph` | writes PICON/POCON/BUSCON/ports in hidden block |
| 0xC1DA6E | `calc_map_70f6` | `axis16_unsigned(0x50DC)`, `tbl2d_interp(0x70F6)`, writes `0xCA00`/`0xC9F4` |
| 0xC1DB18 | `map_6e50_c1db18` | `axis16_unsigned`, `tbl2d_interp(0x6E50)` |
| 0xC1AEDC | `limit_condition_eval` | reads speed `0xC9D0`, thresholds `0xC06C68/6A/6C`, writes `0xC92B` |
| 0xC243A8 | `dtc_status_bit5` | fault-index table `0x7286`, bit 5 of `0xC168` |
| 0xC25600 | `update_adapt_age` | walks 0x1E-byte records at `0xC10E` |

The full list, including evidence and confidence, is the CSV.

## 16.4 Variables and structures

`c166/deliverables/firmware/AUTO_VARIABLES.csv` names 31 new variables/calibration objects with
evidence. Important groups:

* `map_70f6_raw` / `map_70f6_output_clamped` (`0xCA00` / `0xC9F4`)
* `map_6e50_raw` / `ratio` / `correction` / `output`
  (`0xCA16/0xCA12/0xCA06/0xCA1C`)
* `record_select_state` / `record_select_index` (`0xCB64` / `0xCB68`)
* `fault_status_bits` (`0xC168`) and `fault_index_table` (`0x7286`)
* hidden-boot mode bits at `0xE008FE`, `0xE00903..05`
* calibration objects `cal_axis_50dc`, `cal_axis_5146`, `cal_map_6e50`,
  `cal_map_70f6`, `cal_record_table_71ea`

The application init table at `0xC0BB56` is decoded separately in
`c166/deliverables/firmware/APP_INIT_TABLE.csv` and `c166/deliverables/reconstruction/03-data/app_init_table.c`.
Its nine type-6 records copy from `0xC0Bxxx` into low RAM/SFRs; all values are
zero except `scheduler_counter_reload` (`0xC550 = 0x0F0F`). This is the source
of the emulator's “missing fields filled from flash from 0xC0Bxxx” observation,
but it does not cover the external-RAM axis/task tables.

New logical structures are in `firmware_types.h`:
`map_70f6_state_t`, `map_6e50_state_t`, `record_select_t`, `config_mode_t`,
`adapt_record_1e_t`, `fault_status_t`, `axis_pair_7052_t`. They are documented
as logical views, not contiguous memory layouts.

## 16.5 What is still missing

* 606 low-confidence entries still have no proven semantic role. They are
  address-derived placeholders, not role claims.
* 37 gaps remain in the whole-image listing, mostly data tables, vector-table
  slack, or padding.
* External RAM at `0x705E`, `0x7164`, `0x7500`, `0x7564`, and `0x7666` is still
  absent from the flash dump.
* The hidden boot/test block is still not proven reachable; its entry is
  inferred from code shape.
* The full project in `c166sv2/deliverables/reconstruction/full/` supersedes this table with a
  902-entry catalog: 220 high, 340 medium and 342 low after iterative
  call-graph refinement. See `c166sv2/documentation/report/17-full-reconstruction.md`.
* The emulator task in `emulator_prompt.md` is the next path for runtime
  evidence, especially for indirect calls and external-RAM tables.

## 16.6 How to challenge a name

Open the function’s row in `AUTO_NAMES.csv`, then the corresponding
`c166sv2/rest/artifacts/ghidra-full/disassembly.txt` address and decompiled block. A name
should be rejected if the cited callee, table, or variable is not present in
that body. Low-confidence names should be treated as address labels only.
