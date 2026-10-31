#ifndef ADAPTATION_H
#define ADAPTATION_H

#include "c166.h"

#define ADAPT_MAX_RECORDS 8

typedef struct {
    u32 offset;
    u16 sequence;
    u16 tail;
    int has_signature;
} adapt_record_t;

/*
 * Scans the adaptation log at 0xC04000..0xC04CFF.
 * Records are 0x200 bytes: sequence word, payload, 5A A5 signature at
 * +0x1FC, and a 16-bit tail value at +0x1FE.
 */
int adaptation_scan(adapt_record_t *out, int max);

#endif
