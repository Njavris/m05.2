#ifndef MT05_RECON_DATA_H
#define MT05_RECON_DATA_H

#include "c166.h"
#include "app_init_table.h"
#include "auto_symbols.h"
#include "auto_functions.h"
#include <stddef.h>

enum {
    MT05_CAL_TBL8 = 0,
    MT05_CAL_TBL16 = 1,
    MT05_CAL_MAP2D = 2
};

typedef struct {
    u32 address;
    const char *name;
    const char *part;
    const char *area;
    u16 size;
    const char *c_file;
    u16 c_line;
    const char *asm_file;
    u16 asm_line;
    const char *description;
    const char *confidence;
} mt05_function_t;

typedef struct {
    const char *name;
    u32 address;
    u8 kind;
    u8 cols;
    u8 rows;
    u8 shift;
    u16 count;
    const void *data;
    const char *used_by;
} mt05_cal_table_t;

typedef struct {
    const char *dump;
    u16 offset;
    u16 sequence;
    u16 signature;
    u16 tail;
} mt05_adapt_record_t;

typedef struct {
    const char *dump;
    u16 start;
    u16 end;
    u16 length;
} mt05_diff_range_t;

typedef struct {
    s16 offset;
    u8 bytes;
    const char *type;
    const char *uid;
    const char *name;
    const char *formula;
    const char *unit;
    u8 digits;
    u8 bit_count;
} mt05_live_field_t;

typedef struct {
    u8 offset;
    u8 bit;
    const char *uid;
    const char *name;
    u8 inverted;
    const char *disp_vals;
} mt05_live_bit_t;

typedef struct {
    u8 slew_id;
    const char *uid;
    const char *name;
    const char *formula_set;
    s16 min;
    s16 max;
} mt05_live_slew_t;

typedef struct {
    u32 firmware_address;
    const char *firmware_name;
    s16 firmware_bit;
    s16 live_offset;
    s16 live_bit;
    const char *live_uid;
    const char *live_name;
    u8 inverted;
    const char *firmware_alias;
    const char *evidence;
    const char *confidence;
} mt05_live_fw_map_t;

typedef struct {
    u32 address;
    const char *name;
    const char *direction;
    const char *producers;
    const char *consumers;
    const char *observed_role;
    const char *candidate_meaning;
    const char *confidence;
} mt05_debug_channel_t;

extern const u8 mt05_calibration_block[0x6000];
extern const u8 mt05_adaptation_log[0xD00];
extern const u8 mt05_cal_limit_curve_0[17];
extern const u8 mt05_cal_limit_curve_1[17];
extern const u8 mt05_cal_limit_curve_2[17];
extern const u8 mt05_cal_limit_curve_3[6];
extern const u8 mt05_cal_limit_multiplier[17];
extern const u16 mt05_cal_limit_table16[17];
extern const u8 mt05_cal_load_map[81];
extern const u8 mt05_cal_constant_curve_0[9];
extern const u8 mt05_cal_constant_curve_1[9];
extern const u8 mt05_cal_correction_curve[17];

extern const mt05_function_t mt05_functions[];
extern const size_t mt05_function_count;
extern const mt05_cal_table_t mt05_cal_tables[];
extern const size_t mt05_cal_table_count;
extern const mt05_adapt_record_t mt05_adapt_records[];
extern const size_t mt05_adapt_record_count;
extern const mt05_diff_range_t mt05_diff_ranges[];
extern const size_t mt05_diff_range_count;
extern const mt05_live_field_t mt05_live_fields[];
extern const size_t mt05_live_field_count;
extern const mt05_live_bit_t mt05_live_bits[];
extern const size_t mt05_live_bit_count;
extern const mt05_live_slew_t mt05_live_slew[];
extern const size_t mt05_live_slew_count;
extern const mt05_live_fw_map_t mt05_live_fw_map[];
extern const size_t mt05_live_fw_map_count;
extern const mt05_debug_channel_t mt05_debug_channels[];
extern const size_t mt05_debug_channel_count;

#endif /* MT05_RECON_DATA_H */
