#ifndef MT05_AUTO_FUNCTIONS_H
#define MT05_AUTO_FUNCTIONS_H

#include "c166.h"
#include <stddef.h>

/*
 * Evidence-based auto-named functions recovered after the curated 195-function
 * map. Names are mechanical or role-derived; see AUTO_NAMES.csv and
 * ../../docs/16-auto-naming.md for evidence and confidence.
 *
 * This table is separate from mt05_functions[] because these functions do not
 * yet have a reviewed semantic description. It is documentation, not a claim
 * that every entry is a real function: some low-confidence gap blocks may be
 * switch tables or data that decoded as C166 instructions.
 */
typedef struct {
    u32 address;
    const char *old_name;
    const char *name;
    u16 size;
    const char *evidence;
    const char *confidence;
} mt05_auto_function_t;

extern const mt05_auto_function_t mt05_auto_functions[];
extern const size_t mt05_auto_function_count;

#endif
