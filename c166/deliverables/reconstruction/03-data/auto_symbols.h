#ifndef MT05_AUTO_SYMBOLS_H
#define MT05_AUTO_SYMBOLS_H

#include "c166.h"
#include <stddef.h>

/*
 * Evidence-based variables/calibration objects named after the whole-image
 * pass. This is separate from the curated variable table in SEMANTIC_INDEX.csv.
 * "kind" is ram, xram, external, table, or calibration. Width is bytes where
 * known; logical structures are documented in firmware_types.h.
 */
typedef struct {
    u32 address;
    const char *name;
    const char *type;
    const char *kind;
    u16 width;
    const char *evidence;
    const char *confidence;
} mt05_auto_symbol_t;

extern const mt05_auto_symbol_t mt05_auto_symbols[];
extern const size_t mt05_auto_symbol_count;

#endif
