# 9. Function map and decompiled artifacts

## 9.1 Inventory

The curated map contains **195 reviewed functions** covering about **18 KB** of
code. The machine-readable inventory is `c166/deliverables/function_map.csv`; each
function also has a decompiled C file and an assembly listing in
`c166/deliverables/decompiled/`. The separate C166SV2 whole-image pass recovered 902 functions
and is documented in [14-ghidra-full-disassembly.md](14-ghidra-full-disassembly.md).

Naming conventions:

* `boot_*` — boot block (0xC00000–0xC01FFF)
* `trap_*` — hardware trap handlers
* `asc0_*` — K-line UART state machine and helpers
* `kwp_*` — KWP2000 service handlers
* `can_*` — TwinCAN driver/transport
* `ssc_*` — synchronous serial channel
* `capcom_*` / `event_*` — timed output event scheduler
* `tbl*` / `axis*` — calibration table accessors
* `calc_*` — calibration-based engine calculations

All 195 functions now have evidence-based semantic names. The naming evidence
and confidence levels are in `../SEMANTIC_NAMES.md`; no `FUN_` names remain.
The decompiled C is Ghidra output, not original source; it contains decompiler
artifacts (`undefined2`, `halt_baddata`, `extraout_*`) where the C166 module
could not fully recover types or control flow.

## 9.2 Key functions

### Boot / integrity

| Address | Name | Role |
|---|---|---|
| 0xC00A78 | `boot_reset` | reset, self-test, ADC mode selection |
| 0xC00200 | `boot_main` | magic/checksum validation, app or bootloader |
| 0xC0037E | `checksum16_be` | 16-bit byte-swapped word sum |
| 0xC003F0 | `bootloader_entry` | bit-banged bootstrap/test loop |
| 0xC003DE | `boot_minimal_main` | reduced boot path |
| 0xC00904 | `boot_cinit` | boot init-table walker |
| 0xC00434 | `can_twincan_init` | TwinCAN initialization |

### Hidden boot/test block

| Address | Name | Role |
|---|---|---|
| 0xC02000 | `boot_hidden_main` | external-command boot/test loop; outside the boot checksum |
| 0xC02140 | `boot_hidden_periph` | port/PICON/BUSCON initialization |
| 0xC02250 | `boot_hidden_xram_init` | XRAM/port setup |
| 0xC0248A | `boot_hidden_task` | command/task helper |
| 0xC02B76 | `boot_hidden_eeprom` | provisional serial/EEPROM helper |

See [15-hidden-boot-code.md](15-hidden-boot-code.md).

### Interrupts / hardware abstraction

| Address | Name | Role |
|---|---|---|
| 0xC00694 | `can0_isr` | CAN0 interrupt |
| 0xC00D34 | `timer7_isr` | 1 ms tick, K-line + KWP dispatch |
| 0xC00E14 | `ssc0_rx_isr` | SSC0 7-byte frame engine |
| 0xC01048 | `pll_isr` | clock fault → software reset |
| 0xC00F0C/0xC00F6A/0xC00FC8 | trap handlers | stack/bootstrap traps |
| 0xC00C36 | `asc0_init` | K-line UART init |
| 0xC00CA2 | `capcom_timer_init` | timer/CAPCOM init |

### K-line / KWP2000

| Address | Name | Role |
|---|---|---|
| 0xC01144 | `asc0_state_dispatch` | 6-state K-line machine |
| 0xC01188–0xC013E8 | `asc0_state0..5` | idle/wake/rx/validate/tx/finish |
| 0xC01482 | `kwp_dispatch` | service dispatcher |
| 0xC0151C | `kwp_sid81` | StartCommunication |
| 0xC01544 | `kwp_sid27_security` | seed/key |
| 0xC015F8 | `kwp_sid10_session` | session control |
| 0xC0166A | `kwp_sid83` | Delphi-specific service |
| 0xC016C2 | `kwp_sid34_download` | RequestDownload |
| 0xC0170A | `kwp_sid36_transfer` | TransferData (0x80-byte blocks) |
| 0xC017A8 | `kwp_sid31_routine` | StartRoutine |
| 0xC017EA | `kwp_sid38` | transfer-related service |
| 0xC01840 | `kwp_sid23_read_mem` | ReadMemoryByAddress |
| 0xC0190C | `kwp_sid3D_write_mem` | WriteMemoryByAddress |
| 0xC015DA | `kwp_negative` | negative response |

### CAN

| Address | Name | Role |
|---|---|---|
| 0xC01A1C | `can_rx_process` | receive-message processing |
| 0xC01B22 | `can_rx_dispatch` | message-object → transport |
| 0xC01C6E | `can_isotp_send` | send up to 8 bytes |
| 0xC01CC8 | `can_tx_frame` | load/transmit frame |
| 0xC01D9A | `memcpy_wdt` | copy with watchdog |
| 0xC01DEC | `can_tx_confirm` | transmit request/confirm |

### Application startup / scheduler

| Address | Name | Role |
|---|---|---|
| 0xC11AA0 | `app_cstart` | application C startup |
| 0xC1192C | `app_cinit` | application init-table walker |
| 0xC0FFDE | `app_main` | application main |
| 0xC11BF4 | `app_hw_init` | peripheral init |
| 0xC0BFE2 | `app_run` | run entry |
| 0xC11C62 | `app_main_init` | counters/interrupts then scheduler |
| 0xC11EB4 | `app_scheduler` | main scheduler |
| 0xC11CAE | `app_idle_wait` | scheduler wait path |

### Calibration / engine control

| Address | Name | Role |
|---|---|---|
| 0xC11B9A | `cal_checksum` | calibration block checksum |
| 0xC2850E | `axis16_unsigned` | axis → 8.8 index |
| 0xC284D8 | `axis16_signed` | signed axis → 8.8 index |
| 0xC27FCA | `tbl8_interp` | 8-bit table + interpolation |
| 0xC27CA4 | `tbl16_interp` | 16-bit table + interpolation |
| 0xC2826E | `tbl2d_interp` | 2D map + bilinear interpolation |
| 0xC28B64 | `mul32` | multiply helper |
| 0xC1FD9C | `calc_load` | base map × correction |
| 0xC200AA | `calc_limit1` | limit/idle calculation |
| 0xC201AE | `calc_limit2` | limit/idle calculation |
| 0xC202EE | `calc_limit3` | limit/idle calculation |
| 0xC0DC8A | `event_schedule` | CAPCOM event schedule |
| 0xC0D528 | `event_init` | event channel init |
| 0xC0D39E | `event_start` | event start |
| 0xC0D562 | `angle_init` | angle/timer conversion |

## 9.3 Decompiled file naming

Each file is named `<entry>_<name>.c` or `.asm`, for example:

```
c166/deliverables/decompiled/c00a78_boot_reset.c
c166/deliverables/decompiled/c00200_boot_main.c
c166/deliverables/decompiled/c01482_kwp_dispatch.c
c166/deliverables/decompiled/c27fca_tbl8_interp.c
c166/deliverables/decompiled/c1fd9c_calc_load.c
```

The `.asm` files contain the exact Ghidra instruction listing for the function
body. Use them when the C decompiler output looks suspicious.

## 9.4 Coverage

* The curated semantic map contains 195 reviewed functions.
* A later C166SV2 whole-image Ghidra pass recovered **902 functions and 46,430
  instructions**; see [14-ghidra-full-disassembly.md](14-ghidra-full-disassembly.md).
* All 262,144 flash bytes are accounted for in
  `c166sv2/deliverables/artifacts/ghidra-full/flash.lst` as instruction or `.byte` data.
* The 0xC10000 far-call table exposed ten additional entry points and a much
  larger application call graph than the original 195-function view.
* Data tables are not functions; they are preserved in the raw dump and in
  `c166sv2/deliverables/artifacts/calibration_tables.csv`.
* The decompiler cannot read external RAM at 0x705E/0x7500/0x00C9xx, which is
  why several functions show `Unable to read bytes at ram:...` warnings.

## 9.5 How to use the map

1. Start with `c166/deliverables/function_map.csv` to find an address or reconstruction area.
2. Open the corresponding `.c` file for the high-level view.
3. Open the `.asm` file for exact control flow, especially around the
   `JMPA`/`CALLA` branches and the CAPCOM event scheduling.
4. Cross-check table addresses against `c166sv2/deliverables/artifacts/calibration_tables.csv`.
5. Treat the confidence column in `SEMANTIC_NAMES.md` as the authority; some
   names are mechanical (e.g. `cc22_23_schedule`) rather than physical.

## 9.6 Whole-image pass

The 902-function pass is a disassembly baseline, not a semantically reviewed
function map. It uses `farcall_*`, `gap_*`, and `FUN_*` names for newly recovered
functions. Some gap blocks may be switch-table stubs or data that decoded as
valid C166 instructions. The reviewed 195-function reference remains the source
for reconstruction and algorithm claims. Full coverage is in
`c166sv2/`.
