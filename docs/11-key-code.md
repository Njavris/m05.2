# 11. Key code excerpts (cleaned)

This is **cleaned pseudo-C**, reconstructed from the Ghidra decompilation and
the assembly. It is not original source. The exact instruction listings are in
`artifacts/decompiled/*.asm`; the raw decompiler output is in `*.c`.

## 11.1 Flash checksum (`checksum16_be`, 0xC0037E)

```c
uint16_t checksum16_be(const uint8_t *start, const uint8_t *end)
{
    uint16_t sum = 0;
    while (start < end) {
        /* words are stored little-endian but summed byte-swapped */
        sum += ((uint16_t)start[0] << 8) | start[1];
        start += 2;
    }
    return sum;
}
```

The boot block calls it with `0xC00000..0xC01FFE`; the stored result is at
`0xC01FFE`. The application uses the same algorithm over
`0xC0B000..0xC3FFFC`; the calibration block over `0xC05000..0xC0AFFE`.

## 11.2 Boot validation (`boot_main`, 0xC00200)

```c
void boot_main(void)
{
    if (*(volatile uint16_t *)0xC3FFFC == 0xAA00) {
        /* already validated; skip the two sums */
        goto start_application;
    }

    if (checksum16_be((const uint8_t *)0xC00000,
                      (const uint8_t *)0xC01FFE)
        != *(volatile uint16_t *)0xC01FFE) {
        goto bootloader;
    }

    if (checksum16_be((const uint8_t *)0xC0B000,
                      (const uint8_t *)0xC3FFFC)
        != *(volatile uint16_t *)0xC3FFFE) {
        goto bootloader;
    }

start_application:
    /* JMPS 0xC1:0x0000 */
    jump_segment(0xC1, 0x0000);        /* -> 0xC10000 */

bootloader:
    /* CALLS 0xC0:0x03F0 */
    call_segment(0xC0, 0x03F0);        /* -> 0xC003F0 */
}
```

The two failure branches are encoded with the Delphi `JMPA cc_NZ, 0x02D6`
form that the stock C166 Sleigh module rejects; after the Sleigh fix they decode
as branches to 0xC002D6.

## 11.3 KWP service dispatcher (`kwp_dispatch`, 0xC01482)

```c
/* req[] points at the KWP payload: req[0] is the first service byte,
   req[1] is the SID for the normal services. */
void kwp_dispatch(void)
{
    if (req[0] == 0x81) {          /* StartCommunication */
        kwp_sid81();
        return;
    }

    switch (req[1]) {
    case 0x10: kwp_sid10_session();  break;
    case 0x83: kwp_sid83();          break;  /* Delphi-specific */
    case 0x23: kwp_sid23_read_mem(); break;
    case 0x27: kwp_sid27_security(); break;
    case 0x31: kwp_sid31_routine();  break;
    case 0x34: kwp_sid34_download(); break;
    case 0x36: kwp_sid36_transfer(); break;
    case 0x38: kwp_sid38();          break;
    case 0x3D: kwp_sid3D_write_mem();break;
    default:   kwp_negative();       break;
    }
}
```

The handlers write a response into the K-line buffer at 0xC0B2:

```c
resp[0] = 0x80;    /* format */
resp[1] = 0xF1;    /* tester */
resp[2] = 0x11;    /* ECU */
resp[3] = length;
/* payload at resp[4..] */
/* 8-bit checksum after the payload */
```

## 11.4 Security access (`kwp_sid27_security`, 0xC01544)

```c
void kwp_sid27_security(void)
{
    uint8_t sub = req[2];          /* 0xC149 */

    if (sub == 1) {                /* request seed */
        resp = {0x67, 0x01, 0x12, 0x34};   /* fixed seed 0x1234 */
        return;
    }
    if (sub == 2) {                /* send key */
        if (req[3] == 0x84 && req[4] == 0x74) {  /* key 0x8474 */
            security_unlocked = 1;               /* 0xC09A = 1 */
            resp = {0x67, 0x02, 0x34};
        } else {
            resp = {0x7F, 0x27, 0x35};           /* NRC 0x35 */
        }
    }
}
```

## 11.5 Download data transfer (`kwp_sid36_transfer`, 0xC0170A)

```c
void kwp_sid36_transfer(void)
{
    if (!security_unlocked) {
        negative_response(0x36, 0xBD);   /* observed NRC path */
        return;
    }

    uint32_t addr = ((uint32_t)req[2] << 16) |
                    ((uint32_t)req[3] << 8)  |
                     (uint32_t)req[4];       /* 24-bit address */
    uint8_t sum = 0;

    for (int i = 0; i < 0x80; ++i) {
        write_byte_24(addr + i, req[5 + i]);
        sum += req[5 + i];
    }

    resp = {0x76, sum};                  /* TransferData positive response */
}
```

The exact byte offsets are the ones used by the KWP request layout; the
decompiled function reads `0xC149/0xC14A/0xC14B` for the address and copies from
`0xC14C`. The loop length is fixed at **0x80 bytes**.

## 11.6 Axis scaling (`axis16_unsigned`, 0xC2850E)

```c
struct axis16 {
    uint16_t count;    /* number of points */
    uint16_t min;
    uint16_t max;
};

uint16_t axis16_unsigned(const struct axis16 *a, uint16_t value)
{
    if (value <= a->min)
        return 0;
    if (value >= a->max)
        return (uint16_t)((a->count - 1) << 8);

    uint32_t span = (uint32_t)(a->max - a->min);
    uint32_t scaled = (uint32_t)(value - a->min) *
                      ((uint32_t)(a->count - 1) << 8);
    return (uint16_t)(scaled / span);
}
```

The result is an 8.8 fixed-point index: integer part in the high byte,
fraction in the low byte. `axis16_signed` at 0xC284D8 is the signed variant.

## 11.7 8-bit table lookup (`tbl8_interp`, 0xC27FCA)

The table layout is:

```
+0  count
+1  shift   (output scale; 0 in the recovered tables)
+2  count bytes of data
```

The function uses the high byte of the 8.8 index as the cell index and the low
byte as the fraction between two adjacent cells. The output is scaled by
`1 << (8 - shift)`. For the recovered tables `shift = 0`, so the output is an
8-bit value scaled by 256.

## 11.8 2D map lookup (`tbl2d_interp`, 0xC2826E)

```c
/* table[0] = columns, table[1] = row count, table[2] = shift,
   table[3..] = row-major cells */
uint16_t tbl2d_interp(const uint8_t *table, uint8_t segment,
                      uint16_t x_index, uint16_t y_index)
{
    uint8_t cols = table[0];
    uint16_t cell = (y_index >> 8) * cols + (x_index >> 8);
    uint16_t frac_x = x_index & 0xFF;
    uint16_t frac_y = y_index & 0xFF;

    uint8_t v00 = table[3 + cell];
    uint8_t v10 = table[3 + cell + 1];
    uint8_t v01 = table[3 + cell + cols];
    uint8_t v11 = table[3 + cell + cols + 1];

    /* bilinear interpolation; exact integer sequence is in the .asm file */
    uint16_t top    = v00 + (((v10 - v00) * frac_x) >> 8);
    uint16_t bottom = v01 + (((v11 - v01) * frac_x) >> 8);
    return top + (((bottom - top) * frac_y) >> 8);
}
```

The 0xC0794A map is a 9×9 example with `cols = 9`, `shift = 1`.

## 11.9 Main scheduler (`app_scheduler`, 0xC11EB4)

```c
void app_scheduler(void)
{
    for (;;) {
        if (empty_stub_0() != 0) {          /* fatal/return path */
            disable_watchdog();
            if (ext_ram[0x7096] || ext_ram[0x7094])
                empty_stub_0();
            P1H &= ~0x0004;
            software_reset();
            return;
        }

        if (!(reg_FD14 & 0x04)) {
            app_scheduler();             /* recursive wait path */
            return;
        }

        service_watchdog();
        reg_FD14 &= ~0x04;
        tick_counter_0xC54A++;

        periodic_hook_0F3D2();
        periodic_hook_10342();
        periodic_hook_108B4();

        if (tick_counter_0xC54A & 1) {
            periodic_hook_0CD24();
            if (engine_state_0xC962 < 0x5800 ||
                engine_state_0xC962 > 0x6800 ||
                ext_ram[0xCB60] != 0 ||
                ext_ram[0xC280] != 0) {
                ext_ram[0xC5E6] = 0;
                ext_ram[0xFD18] &= 0x80;
                ext_ram[0xC5E8] = 0;
                ext_ram[0xC5EA] = 0;
            } else {
                ext_ram[0xC5E6] = 1;
                periodic_hook_13D5E(0);
            }
        }

        update_two_callbacks_from_table_0x7088();

        if (task_state_0xC584 >= 4 && task_state_0xC584 < 16) {
            /* task table at external RAM 0x705E */
            task = ext_ram16[0x705E + (task_state_0xC584 - 4) * 2];
            call_segment(0xC1, task);
        }

        periodic_hook_1482C();
    }
}
```

This is a simplified view. The task table and several callbacks are in external
RAM and are not present in the flash dump; the function names `empty_stub_0`,
`periodic_hook_*` are placeholders for addresses whose semantics are not fully
recovered.

## 11.10 CAPCOM event scheduling (`event_schedule`, 0xC0DC8A)

The recovered logic for one event channel (`i = 0` or `1`):

```c
void event_schedule(uint8_t ch)
{
    struct event *e = &events[ch];      /* 0xC410 + 0x12*ch */
    uint16_t now = T7;                  /* snapshot in 0xC3FC */
    uint16_t next;

    e->flags &= ~0x1C;
    next = e->compare;                  /* initial value */
    update_channel_hw(ch);

    if ((e->flags & 0x01) == 0 ||
        ((e->flags & 0x04) == 0 && (e->control & 0x80) == 0)) {
        e->compare = now;
        next = e->compare;
    }

    e->control &= ~0x80;
    e->flags |= 0x20;

    if (e->flags & 0x01) {
        event_accumulate(ch, next);
        e->flags &= ~0x01;
        if ((e->duration_lo | e->duration_hi) == 0) {
            event_idle(ch);
        } else {
            uint16_t d = lookup_duration(e->duration_lo, e->duration_hi);
            if ((uint32_t)e->duration_lo + e->offset + e->base <
                (uint32_t)e->duration_hi_pad - d) {
                e->compare = now + e->base;
                set_channel_mode(ch, 4);
                event_force(ch, 0);
                e->flags |= 0x02;
            } else {
                event_force2(ch);
                e->flags |= 0x40;
            }
        }
    } else {
        if (e->flags & 0x02) {
            if (now - e->last < e->gap + 10)
                e->compare = now + 10;
            else
                e->compare = e->last + e->gap;
            set_channel_mode(ch, 4);
            event_force(ch);
        } else {
            event_idle(ch);
        }
    }
}
```

This is the closest readable reconstruction; the exact field names
(`duration_lo`, `offset`, `gap`, ...) are inferred from the memory layout and
the arithmetic. The assembly file
`artifacts/decompiled/c0dc8a_event_schedule.asm` remains authoritative.

## 11.11 What is intentionally omitted

The full fuel/ignition equations, lambda control, idle-air control and the
external-RAM task table are not reconstructed. See
[07-engine-control.md](07-engine-control.md) and
[10-method-and-limitations.md](10-method-and-limitations.md).
