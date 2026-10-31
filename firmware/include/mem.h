#ifndef MEM_H
#define MEM_H

#include "c166.h"

u8  *mem_space(void);
int  mem_load_dump(const char *path);

u8   mem_read8(u32 addr);
u16  mem_read16(u32 addr);
u32  mem_read32(u32 addr);

void mem_write8(u32 addr, u8 value);
void mem_write16(u32 addr, u16 value);
void mem_write32(u32 addr, u32 value);

int  mem_read_block(u32 addr, u8 *dst, u32 len);
int  mem_write_block(u32 addr, const u8 *src, u32 len);

int  mem_range_ok(u32 addr, u32 len);

#endif
