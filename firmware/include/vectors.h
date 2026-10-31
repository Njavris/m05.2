#ifndef VECTORS_H
#define VECTORS_H

#include "c166.h"

typedef struct {
    u32         address;  /* vector slot, e.g. 0xC00000 */
    const char *source;   /* XC164CS interrupt/trap name, or "RESERVED" */
    u32         target;   /* handler address, 0 if unused */
    int         active;
} vector_t;

/*
 * Decodes the 128-slot, 4-byte-spaced C166 vector table at 0xC00000.
 * Returns the number of slots written (up to max).
 */
int vector_decode_all(vector_t *out, int max);

const char *vector_source_name(u32 vector_address);

#endif
