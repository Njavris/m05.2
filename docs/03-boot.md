# 3. Boot chain and startup

## 3.1 Reset vector

The reset vector is the first vector slot:

```
0xC00000: FA C0 78 0A     JMPS 0xC0:0x0A78  ->  0xC00A78
```

`JMPS` switches to code segment 0xC0 and jumps to offset 0x0A78, i.e. physical
address **0xC00A78**. The first instruction of the reset handler is a watchdog
and bus setup sequence.

## 3.2 `boot_reset` at 0xC00A78

The decompiled reset handler (full file:
`artifacts/decompiled/c00a78_boot_reset.c`) performs:

1. `WDTCON = 0xCF01`, `ADDRSEL1 = 0x17`, `ADDRSEL2 = 0x8FBB`
2. Port/DPP/stack setup:
   * `DPP0 = 0x300` → 0xC00000–0xC03FFF
   * `DPP1 = 0x301` → 0xC04000–0xC07FFF
   * `DPP2 = 0x302` → 0xC08000–0xC0BFFF
   * `SP = 0xFC00`, `STKOV = 0xFA0C`, `STKUN = 0xFC00`
   * `SYSCON = 0xC0`
3. ADC-based mode selection (see 3.3).
4. Branch to one of:
   * `boot_main` 0xC00200 — normal application boot
   * `boot_minimal_main` 0xC003DE — reduced/safe mode
   * `bootloader_entry` 0xC003F0 — bit-banged bootstrap/test loop

## 3.3 ADC-coded mode selection

Before any flash validation, the reset code reads ADC channels 0, 3, 4, 5 and 6
and decides between three boot paths. The decompiled decision tree is:

```c
/* pseudo-C, channel writes are 0x9000 | channel to 0xFFBE */
read_ch0();
if (adc10(ch0) > 0x396) {          /* 918 of 1023 */
    read_ch3();
    if (adc10(ch3) > 0x396) {
        read_ch4();
        if (adc10(ch4) < 0x67) {   /* 103 */
            read_ch6();
            if (adc10(ch6) < 0x67) {
                boot_periph_init();
                boot_minimal_main();   /* not the normal app path */
                return;
            }
        }
    }
}
read_ch6();
if (adc10(ch6) > 0x396) {
    read_ch4();
    if (adc10(ch4) > 0x396) {
        read_ch5();
        if (adc10(ch5) < 0x15) {   /* 21 */
            boot_periph_init();
            bootloader_entry();    /* bit-banged bootstrap */
            return;
        }
    }
}
boot_periph_init();
boot_main();                       /* normal application validation */
```

`adc10(x)` is `(ADDAT & 0x0FFF) >> 2`, i.e. a 10-bit conversion result. The
thresholds and channel order are exact; the *physical meaning* of the analog
levels (configuration resistor, programming voltage, test fixture) is not
proven. The pattern is consistent with Delphi production variant coding or a
factory test input.

## 3.4 `boot_main` — integrity validation and hand-off

`boot_main` at 0xC00200 is the normal path. Its logic is:

```c
/* pseudo-C */
if (*(uint16_t*)0xC3FFFC == 0xAA00) {
    goto start_application;                 /* fast path: already validated */
}
sum = checksum16_be(0xC00000, 0xC01FFD);    /* boot block */
if (sum != *(uint16_t*)0xC01FFE)
    goto bootloader;                        /* JMPA cc_NZ, 0xC002D6 */

sum = checksum16_be(0xC0B000, 0xC3FFFB);    /* application block */
if (sum != *(uint16_t*)0xC3FFFE)
    goto bootloader;                        /* JMPA cc_NZ, 0xC002D6 */

start_application:
    JMPS 0xC1:0x0000;                       /* 0xC10000: application entry */
```

The two `JMPA` instructions use the Delphi compiler's encoding with a non-zero
reserved nibble (`EA 31 D6 02`). The Ghidra C166 module initially rejected them;
after relaxing the `JMPA`/`CALLA` constructor they decode consistently as
`JMPA cc_NZ, 0x02D6` → `0xC002D6`, which is the bootloader call.

If validation fails, 0xC002D6 executes:

```
CALLS 0xC0:0x03F0    ; bootloader_entry
RETS
```

If validation passes, the application entry is reached via the far-call table:

```
0xC10000: FA C1 A0 1A    JMPS 0xC1:0x1AA0  ->  0xC11AA0
```

## 3.5 Bootloader / test loop at 0xC003F0

`bootloader_entry` is short and unusual:

* clears P1L.5, BUSCON2.4 and P1L.6
* calls a delay (`delay_ticks`) twice and an SSC transfer starter
* waits until P1L.4 is low
* toggles P1L.6 in a loop (`bmovn P1L.6,P1L.6`)

This is a **bit-banged bootstrap/test loop**, not the normal KWP2000 service
stack. It probably drives a single-wire bootstrap clock/data pin. The exact
protocol is not recovered; no live capture is available. Treat the physical
meaning as inferred.

## 3.6 Application C startup at 0xC11AA0

The application entry trampoline at 0xC10000 jumps to **0xC11AA0**
(`app_cstart`). It:

1. Disables interrupts/watchdog and configures `SYSCON = 0xC1`.
2. Sets `SP = 0xFC00`, `STKOV = 0xFADA`, `STKUN = 0xFC00`.
3. Fills two RAM windows with constant words: 0x0165 over IRAM
   0xFACE–0xFBFE, and 0x0167 over DPP0 page 3 offsets 0x02CA–0x0368,
   i.e. physical 0x00C2CA–0x00C368. This is a startup fill/marker, not a zero-fill.
4. Sets `DPP0 = 0x301`, `DPP1 = 0x302`, `DPP2 = 0x303`:
   * 0xC04000–0xC07FFF
   * 0xC08000–0xC0BFFF
   * 0xC0C000–0xC0FFFF
5. Calls `app_cinit` at 0xC1192C. It zeroes IRAM 0xFDFE–0xFD00 (except two
   words) and then walks the application init table at 0xC0BB56.
6. Calls `app_main` at 0xC0FFDE.
7. If `app_main` returns, the CPU enters an endless `IDLE` loop.

## 3.7 C runtime init tables

Both the boot block and the application contain a Tasking-style init table:

| Block | Table address | Routine |
|---|---|---|
| Boot | 0xC008BA | `boot_cinit` 0xC00904 |
| Application | 0xC0BB56 | `app_cinit` 0xC1192C |

Record format observed (little-endian fields):

```
+0  type   (1, 5, 6, 7)
+2  dest_offset
+4  dest_page  (DPP value)
+6  src_offset
+8  src_page   (DPP value)
+10 length
```

Type 6 copies `length` bytes from the source page/offset to the destination
page/offset. Type 5 terminates the table. Type 1 records (14-byte stride) and
type 7 records are also handled by the same walker. Example from the application
table at 0xC0BB56:

```
06 00  FC 01  03 00  54 3B  02 03  02 00
```

means: copy 2 bytes from physical `0xC0BB54` to physical `0x00C1FC`
(the application's external RAM). The init table initializes small variables in
external RAM and IRAM, not the calibration block.

## 3.8 Application main and scheduler

`app_main` at 0xC0FFDE calls:

* `input_latch` (0xC14714) — copies input port state into 0xFD1C
* `app_hw_init` (0xC11BF4) — long peripheral initialization sequence
* `app_run` (0xC0BFE2) — enters the application scheduler

`app_run` calls `app_main_init` (0xC11C62), which sets up counters, enables
interrupts and then jumps to **0xC11EB4** (the scheduler).

The scheduler at 0xC11EB4:

1. Waits for flag bit `0xFD14.2`.
2. Services the watchdog (`SRVWDT`).
3. Clears `0xFD14.2`, increments the tick counter at 0xC54A.
4. Calls the periodic hooks `cc22_23_task`, `ssc_task`, `timeout_counter_tick`.
5. Every other tick runs `speed_timing_calc` and an engine-state check:
   `0xC962` must lie in 0x5800–0x6800, `0xCB60`/`0xC280` must be zero for the
   normal path; otherwise the code clears 0xC5E6/0xC5E8/0xC5EA and skips
   `test_command_dispatch`.
6. Updates two counters from the table at external RAM 0x7088 and calls a
   callback via a RAM function pointer.
7. Dispatches a task from the external-RAM table at **0x705E** when the state
   variable 0xC584 is in 4..15.
8. Calls `diag_status_build` (periodic work) and may reset the CPU on a fatal state.

The task table at 0x705E is in external RAM and is **not present in the dump**;
the task addresses cannot be enumerated from flash alone. The scheduler
structure and the fixed calls are observed.

## 3.9 Boot-flow summary

```
0xC00000  RESET vector  JMPS C0:0A78
   |
0xC00A78  boot_reset
   |-- ADC self-test/variant coding
   |-- normal  -> 0xC00200 boot_main
   |-- minimal -> 0xC003DE boot_minimal_main
   |-- boot    -> 0xC003F0 bootloader_entry
   |
0xC00200  boot_main
   |-- 0xC3FFFC == 0xAA00 ? -> 0xC10000 (skip checks)
   |-- checksum boot block vs 0xC01FFE
   |-- checksum app block vs 0xC3FFFE
   |-- pass -> 0xC002D2 JMPS C1:0000 -> 0xC10000
   |-- fail -> 0xC002D6 CALLS C0:03F0 (bootloader)
   |
0xC10000  JMPS C1:1AA0 -> 0xC11AA0 app_cstart
   |-- 0xC1192C app_cinit
   |-- 0xC0FFDE app_main
   |     |-- 0xC14714 input_latch
   |     |-- 0xC11BF4 app_hw_init
   |     |-- 0xC0BFE2 app_run -> 0xC11C62 app_main_init -> 0xC11EB4 scheduler
   |
   +-- endless IDLE if app_main returns
```
