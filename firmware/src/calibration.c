#include "calibration.h"
#include "mem.h"

u16 axis16_unsigned(const axis16_t *axis, u16 value)
{
    u32 span;
    u32 scaled;

    if (axis == NULL || axis->count == 0 || axis->max <= axis->min) {
        return 0;
    }
    if (value <= axis->min) {
        return 0;
    }
    if (value >= axis->max) {
        return (u16)((axis->count - 1u) << 8);
    }
    span = (u32)axis->max - (u32)axis->min;
    scaled = ((u32)value - (u32)axis->min) *
             ((u32)(axis->count - 1u) << 8);
    return (u16)(scaled / span);
}

u16 axis16_unsigned_mem(u32 axis_addr, u16 value)
{
    axis16_t axis;
    axis.count = mem_read16(axis_addr);
    axis.min = mem_read16(axis_addr + 2u);
    axis.max = mem_read16(axis_addr + 4u);
    return axis16_unsigned(&axis, value);
}

u16 tbl8_interp(u32 table_addr, u16 index)
{
    u16 count;
    u8 shift;
    u16 cell;
    u8 frac;
    int a;
    int b;
    int base;
    int delta;

    count = mem_read8(table_addr);
    if (count == 0) {
        return 0;
    }
    shift = mem_read8(table_addr + 1u);
    if (shift > 8u) {
        shift = 8u;
    }

    cell = (u16)(index >> 8);
    frac = (u8)(index & 0xFFu);
    if (cell >= (u16)(count - 1u)) {
        cell = (u16)(count - 1u);
        frac = 0;
    }

    a = (int)mem_read8(table_addr + 2u + cell);
    b = (cell + 1u < count)
        ? (int)mem_read8(table_addr + 2u + cell + 1u)
        : a;

    base = a << (8u - shift);
    delta = b - a;
    return (u16)(base + ((delta * (int)frac) >> shift));
}

u16 tbl16_interp(u32 table_addr, u16 index)
{
    u16 count;
    u16 cell;
    u8 frac;
    s16 a;
    s16 b;

    count = mem_read16(table_addr);
    if (count == 0) {
        return 0;
    }

    cell = (u16)(index >> 8);
    frac = (u8)(index & 0xFFu);
    if (cell >= (u16)(count - 1u)) {
        cell = (u16)(count - 1u);
        frac = 0;
    }

    a = (s16)mem_read16(table_addr + 2u + 2u * cell);
    b = (cell + 1u < count)
        ? (s16)mem_read16(table_addr + 2u + 2u * (cell + 1u))
        : a;

    return (u16)((s32)a + (((s32)b - (s32)a) * (s32)frac >> 8));
}

u16 tbl2d_interp(u32 table_addr, u16 x_index, u16 y_index)
{
    u8 cols;
    u8 rows;
    u8 shift;
    u16 cell;
    u16 ix;
    u16 iy;
    u8 fx;
    u8 fy;
    s32 v00;
    s32 v10;
    s32 v01;
    s32 v11;
    s32 top;
    s32 bottom;
    s32 value;

    cols = mem_read8(table_addr);
    rows = mem_read8(table_addr + 1u);
    shift = mem_read8(table_addr + 2u);
    if (cols == 0 || rows == 0) {
        return 0;
    }
    if (shift > 8u) {
        shift = 8u;
    }

    ix = (u16)(x_index >> 8);
    iy = (u16)(y_index >> 8);
    fx = (u8)(x_index & 0xFFu);
    fy = (u8)(y_index & 0xFFu);

    if (ix >= (u16)(cols - 1u)) {
        ix = (u16)(cols - 1u);
        fx = 0;
    }
    if (iy >= (u16)(rows - 1u)) {
        iy = (u16)(rows - 1u);
        fy = 0;
    }

    cell = (u16)(iy * cols + ix);
    v00 = (s32)mem_read8(table_addr + 3u + cell);
    v10 = (s32)mem_read8(table_addr + 3u + cell + 1u);
    v01 = (s32)mem_read8(table_addr + 3u + cell + cols);
    v11 = (s32)mem_read8(table_addr + 3u + cell + cols + 1u);

    top = v00 + (((v10 - v00) * (s32)fx) >> 8);
    bottom = v01 + (((v11 - v01) * (s32)fx) >> 8);
    value = top + (((bottom - top) * (s32)fy) >> 8);

    if (shift < 8u) {
        value <<= (8u - shift);
    }
    return (u16)value;
}

u16 calc_load(u32 axis_x_addr, u32 axis_y_addr,
              u32 map_addr, u32 correction_addr,
              u16 input_x, u16 input_y, u16 correction_input)
{
    u16 x_index = axis16_unsigned_mem(axis_x_addr, input_x);
    u16 y_index = axis16_unsigned_mem(axis_y_addr, input_y);
    u16 base = tbl2d_interp(map_addr, x_index, y_index);
    u16 correction = tbl8_interp(correction_addr, correction_input);

    return (u16)(((u32)base * (u32)correction) >> 15);
}
