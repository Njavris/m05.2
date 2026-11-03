#include "mt05/live_data.h"

#include <string.h>

const mt05_live_field_t *mt05_live_field_by_uid(const char *uid)
{
    if (uid == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < mt05_live_field_count; ++i) {
        if (strcmp(mt05_live_fields[i].uid, uid) == 0) {
            return &mt05_live_fields[i];
        }
    }
    return NULL;
}

const mt05_live_bit_t *mt05_live_bit_by_uid(const char *uid)
{
    if (uid == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < mt05_live_bit_count; ++i) {
        if (strcmp(mt05_live_bits[i].uid, uid) == 0) {
            return &mt05_live_bits[i];
        }
    }
    return NULL;
}
