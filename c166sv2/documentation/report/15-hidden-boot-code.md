# 15. Hidden boot/test block at 0xC02000

## 15.1 Discovery

The original region table described `0xC02000-0xC03FFF` as erased/unused. That
was wrong. A whole-image Ghidra pass and Ghidra's Aggressive Instruction Finder
(AIF) recovered a coherent code block at **`0xC02000-0xC03DF6`**.

The block is outside the boot checksum (`0xC00000-0xC01FFD`), so it can be
changed without breaking the recorded boot checksum `0xEE88`.

## 15.2 Entry and control flow

The real entry is **`0xC02000`**. An earlier AIF pass created a function at
`0xC02020`; that was a mid-function label. The corrected function is
`boot_hidden_main` at `0xC02000`, and the `0xC02020` function was removed.

`boot_hidden_main`:

1. writes `0xFF` to external address `0xE00000`;
2. clears the XRAM byte at `0xF800`;
3. sets P1H.2;
4. calls `boot_hidden_periph` at `0xC02140`;
5. sets P1H.3;
6. calls `boot_hidden_xram_init` at `0xC02250`;
7. calls `boot_hidden_xram2` at `0xC022FC`;
8. calls `boot_hidden_xram3` at `0xC0231E`;
9. if P5.11 is set, copies two 32-bit values from `0xC04000` and passes them
   through `boot_hidden_store32`/`boot_hidden_memcpy`;
10. enters an infinite loop that polls `0xE00000`, dispatches command values
    below `0x1A`, writes `0xFF` back to `0xE00000`, and services the watchdog.

This is a command-driven boot/test loop, not the normal application scheduler.

## 15.3 Recovered routines

| Address | Name | Role |
|---|---|---|
| `0xC02000` | `boot_hidden_main` | entry, external command loop |
| `0xC020C4` | `boot_hidden_copy` | 32-bit copy helper |
| `0xC0210A` | `boot_hidden_memcpy` | byte copy with watchdog service |
| `0xC02140` | `boot_hidden_periph` | port/PICON/BUSCON initialization |
| `0xC02250` | `boot_hidden_xram_init` | XRAM/port setup |
| `0xC022FC` | `boot_hidden_xram2` | XRAM setup |
| `0xC0231E` | `boot_hidden_xram3` | XRAM setup |
| `0xC0248A` | `boot_hidden_task` | command/task helper |
| `0xC02B76` | `boot_hidden_eeprom` | serial/EEPROM helper |
| `0xC03CB8` | `boot_hidden_i2c_a` | bit/byte serial helper |
| `0xC03CD0` | `boot_hidden_i2c_b` | bit/byte serial helper |
| `0xC03DDC` | `boot_hidden_delay` | delay helper |
| `0xC03DE2` | `boot_hidden_store32` | 32-bit store helper |

The names are descriptive working labels, not proven vendor names.

## 15.4 Why it was missed

- The normal reset vector targets `0xC00A78`, and normal boot never branches to
  `0xC02000`.
- The boot checksum ends at `0xC01FFD`; the hidden block is outside it.
- The block is not in the 195-function semantic index.
- Ghidra's default analysis had no entry point there, so it did not follow it.
- AIF found it by scanning undefined bytes for instruction-shaped sequences.

## 15.5 Relation to normal boot

Static evidence does not show a direct call or jump from `boot_main`,
`boot_reset`, `bootloader_entry`, or the `0xC10000` table to `0xC02000`. Possible
explanations:

1. factory/production test firmware left in the image;
2. an alternate boot path entered by an external bootstrap/master;
3. dead code from a previous calibration/tooling build;
4. a block copied or called through an external table not present in the dump.

The emulator task in `emulator_prompt.md` should test the first two by starting
execution at `0xC02000` with external command bytes and by tracing reset for any
indirect entry.

## 15.6 Limits

- The block's entry is inferred from code shape and fall-through, not from an
  observed vector or call.
- `0xE00000` is external memory and is not present in the flash dump.
- The command values below `0x1A` and the helper at `0xC0248A` are not decoded.
- The `boot_hidden_eeprom`/`boot_hidden_i2c_*` names are provisional; the
  serial protocol and target device are not proven.
