#ifndef CALIBRATION_H
#define CALIBRATION_H

#include "c166.h"

typedef struct {
    u16 count;
    u16 min;
    u16 max;
} axis16_t;

/* 8.8 fixed-point axis scaling, as in axis16_unsigned at 0xC2850E. */
u16 axis16_unsigned(const axis16_t *axis, u16 value);

/* Reads {count,min,max} from the 24-bit address space and scales. */
u16 axis16_unsigned_mem(u32 axis_addr, u16 value);

/*
 * 8-bit table: [count][shift][count bytes].
 * Returns the cell value scaled by 1 << (8 - shift), with linear
 * interpolation using the low byte of the 8.8 index.
 */
u16 tbl8_interp(u32 table_addr, u16 index);

/* 16-bit table: [count:u16][count words], 8.8 index. */
u16 tbl16_interp(u32 table_addr, u16 index);

/* 2D map: [columns][rows][shift][row-major bytes], bilinear interpolation. */
u16 tbl2d_interp(u32 table_addr, u16 x_index, u16 y_index);

/*
 * Semantic model of calc_load at 0xC1FD9C:
 *   result = (tbl2d(map) * tbl8(correction)) >> 15
 * The axis descriptors are read from the 24-bit address space because the
 * originals live in external RAM, which is not part of the flash dump.
 */
u16 calc_load(u32 axis_x_addr, u32 axis_y_addr,
              u32 map_addr, u32 correction_addr,
              u16 input_x, u16 input_y, u16 correction_input);

#endif
