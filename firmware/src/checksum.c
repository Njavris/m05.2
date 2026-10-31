#include "checksum.h"
#include "mem.h"

u16 checksum16_be(u32 start, u32 end)
{
    u32 addr;
    u32 sum = 0;

    if (end < start) {
        return 0;
    }
    for (addr = start; addr + 1 < end; addr += 2) {
        sum += ((u32)mem_read8(addr) << 8) | (u32)mem_read8(addr + 1);
    }
    return (u16)(sum & 0xFFFFu);
}
