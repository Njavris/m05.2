#include "adaptation.h"
#include "mem.h"

int adaptation_scan(adapt_record_t *out, int max)
{
    int count = 0;
    u32 off;

    if (out == NULL || max <= 0) {
        return 0;
    }

    /* Six 0x200-byte records at 0x4000..0x4A00. */
    for (off = C166_ADAPT_START; off <= C166_ADAPT_START + 0xA00u && count < max; off += 0x200u) {
        out[count].offset = off;
        out[count].sequence = mem_read16(off);
        out[count].has_signature =
            (mem_read8(off + 0x1FCu) == 0x5Au &&
             mem_read8(off + 0x1FDu) == 0xA5u);
        out[count].tail = (u16)(((u16)mem_read8(off + 0x1FEu) << 8) |
                                (u16)mem_read8(off + 0x1FFu));
        count++;
    }

    /* The final record is 0x100 bytes: 0x4C00..0x4CFF. */
    if (count < max) {
        off = C166_ADAPT_START + 0xC00u;
        out[count].offset = off;
        out[count].sequence = mem_read16(off);
        out[count].has_signature =
            (mem_read8(off + 0xFCu) == 0x5Au &&
             mem_read8(off + 0xFDu) == 0xA5u);
        out[count].tail = (u16)(((u16)mem_read8(off + 0xFEu) << 8) |
                                (u16)mem_read8(off + 0xFFu));
        count++;
    }

    return count;
}
