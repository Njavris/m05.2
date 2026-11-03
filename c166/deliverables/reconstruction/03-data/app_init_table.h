#ifndef MT05_APP_INIT_TABLE_H
#define MT05_APP_INIT_TABLE_H

#include "c166.h"
#include <stddef.h>

/* Type-6 records from the application init table at 0xC0BB56. */
typedef struct {
    u16 dest;
    u16 source;
    u16 length;
    u16 initial_value;
    const char *name;
    const char *evidence;
    const char *confidence;
} mt05_app_init_copy_t;

extern const mt05_app_init_copy_t mt05_app_init_copies[];
extern const size_t mt05_app_init_copy_count;

#endif
