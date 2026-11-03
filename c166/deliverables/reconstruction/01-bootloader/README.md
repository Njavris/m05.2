# Bootloader

Firmware part: bootloader, `0xC00000–0xC01FFF`, 8 KB.

16 functions in [`bootloader.c`](bootloader.c) and [`bootloader.asm`](bootloader.asm).

[Back to reconstruction index](../README.md) · [Function index](../03-data/data.c)

| Address | Function | Size | Description | C | ASM |
|---|---|---:|---|---|---|
| 0xC00200 | `boot_main` | 220 | Boot-block main: checks magic/checksums, selects app or bootloader. | [C](bootloader.c#L9) | [ASM](bootloader.asm#L9) |
| 0xC002DC | `boot_periph_init` | 50 | Boot peripheral initialization wrapper. | [C](bootloader.c#L66) | [ASM](bootloader.asm#L83) |
| 0xC0030E | `boot_bus_mode` | 112 | External bus mode configuration based on SYSCON bits. | [C](bootloader.c#L96) | [ASM](bootloader.asm#L105) |
| 0xC0037E | `checksum16_be` | 50 | 16-bit sum of big-endian words over a flash range. | [C](bootloader.c#L131) | [ASM](bootloader.asm#L148) |
| 0xC003B8 | `delay_loop` | 10 | Simple delay loop. | [C](bootloader.c#L157) | [ASM](bootloader.asm#L178) |
| 0xC003C2 | `delay_ticks` | 28 | Delay loop parameterized by r12. | [C](bootloader.c#L182) | [ASM](bootloader.asm#L190) |
| 0xC003DE | `boot_minimal_main` | 18 | Reduced boot path used when configuration ADC check selects it. | [C](bootloader.c#L211) | [ASM](bootloader.asm#L208) |
| 0xC003F0 | `bootloader_entry` | 56 | Bootloader/test loop; bit-bangs P1L.6 and waits on P1L.4. | [C](bootloader.c#L231) | [ASM](bootloader.asm#L222) |
| 0xC00904 | `boot_cinit` | 372 | Boot-block C runtime init (zero/init tables). | [C](bootloader.c#L275) | [ASM](bootloader.asm#L249) |
| 0xC00A78 | `boot_reset` | 440 | Reset vector: watchdog, stack, DPPs, self-test, then boot_main. | [C](bootloader.c#L443) | [ASM](bootloader.asm#L400) |
| 0xC00DAE | `boot_port_adc_init` | 44 | Boot-block port/ADC-related register initialization. | [C](bootloader.c#L606) | [ASM](bootloader.asm#L547) |
| 0xC00EE8 | `boot_extint_init` | 36 | Boot external-interrupt init: bus mode, EXICON, T1IC. | [C](bootloader.c#L633) | [ASM](bootloader.asm#L567) |
| 0xC00F0C | `trap_stack_overflow` | 94 | Stack overflow trap handler. | [C](bootloader.c#L657) | [ASM](bootloader.asm#L586) |
| 0xC00F6A | `trap_stack_underflow` | 94 | Stack underflow trap handler. | [C](bootloader.c#L792) | [ASM](bootloader.asm#L633) |
| 0xC00FC8 | `trap_bootstrap` | 128 | Bootstrap trap handler. | [C](bootloader.c#L927) | [ASM](bootloader.asm#L680) |
| 0xC01AD4 | `can_bootloader_wait` | 78 | Initializes CAN diagnostic objects and enters the boot wait loop. | [C](bootloader.c#L1083) | [ASM](bootloader.asm#L737) |

Files are Ghidra decompiler output; they are not a compilable translation unit.
