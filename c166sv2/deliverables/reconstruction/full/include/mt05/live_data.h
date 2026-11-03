#ifndef MT05_LIVE_DATA_H
#define MT05_LIVE_DATA_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    const char *tx_bytes;
    const char *rx_size;
    const char *read;
    const char *byte_order;
    const char *description;
} mt05_hud_command_t;

typedef struct {
    uint8_t offset;
    uint8_t bytes;
    const char *type;
    const char *uid;
    const char *name;
    const char *formula;
    const char *unit;
    uint8_t digits;
    const char *description;
} mt05_live_field_t;

typedef struct {
    uint8_t offset;
    uint8_t bit;
    const char *uid;
    const char *name;
    const char *description;
    const char *inverted;
    const char *firmware_alias;
} mt05_live_bit_t;

typedef struct {
    uint8_t slew_id;
    const char *type;
    const char *uid;
    const char *name;
    const char *formula_set;
    int16_t min;
    int16_t max;
    uint8_t value_on;
    const char *description;
} mt05_slew_t;

extern const mt05_hud_command_t mt05_hud_commands[];
extern const size_t mt05_hud_command_count;
extern const mt05_live_field_t mt05_live_fields[];
extern const size_t mt05_live_field_count;
extern const mt05_live_bit_t mt05_live_bits[];
extern const size_t mt05_live_bit_count;
extern const mt05_slew_t mt05_slew[];
extern const size_t mt05_slew_count;

const mt05_live_field_t *mt05_live_field_by_uid(const char *uid);
const mt05_live_bit_t *mt05_live_bit_by_uid(const char *uid);

#endif
