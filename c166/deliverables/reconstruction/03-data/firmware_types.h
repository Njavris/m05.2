#ifndef FIRMWARE_TYPES_H
#define FIRMWARE_TYPES_H

/*
 * Recovered data structures for the Delphi MT05.2 / XC164CS firmware.
 *
 * These are documentation models reconstructed from access patterns in the
 * decompiled code. They are not compiler-generated debug information. Field
 * names marked "inferred" are supported by usage but not by an original
 * symbol table.
 *
 * The C166 is 16-bit little-endian. The structs below use the same byte order
 * as the firmware; padding is explicit where the original layout is known.
 */

#include "c166.h"

/* ------------------------------------------------------------------------- */
/* K-line / KWP2000 frame buffer at 0xC0B2                                   */
/* ------------------------------------------------------------------------- */

typedef struct {
    u8  format;                 /* +0x00: 0x80 format byte */
    u8  target;                 /* +0x01: tester 0xF1 for responses */
    u8  source;                 /* +0x02: ECU 0x11 */
    u8  length;                 /* +0x03: payload length */
    u8  payload[256];           /* +0x04: service response/data */
    /* checksum is at payload[length]; not a fixed struct member */
} kline_frame_t;

/* K-line receive/transport state (0xC0AE, 0xC0AF, 0xC0B0, ...). */
typedef struct {
    u8  rx_index;               /* 0xC0AE: wake-up pattern index */
    u8  state;                  /* 0xC0AF: 5-state K-line machine */
    u16 rx_timeout;             /* 0xC0B0 */
    u8  rx_buffer[0x100];       /* 0xC144: received frame / request bytes */
    u8  wakeup_pattern[5];      /* 0xC0A3: expected 5-byte wake-up pattern (RAM) */
    u8  request_pending;        /* 0xC1D1: KWP request ready */
    u8  security_unlocked;      /* 0xC09A: SID 0x27 result */
} kline_state_t;

/* ------------------------------------------------------------------------- */
/* CAPCOM CC16/CC17 event channels at 0xC410 (stride 0x12, two channels).
 * live data separates injector time (FPWVC1/2), spark dwell (SPDWELL) and
 * spark advance (SAESTA); the pair is most likely injection + ignition, but the
 * exact channel assignment is not proven. */
/* ------------------------------------------------------------------------- */

typedef struct {
    u16 start_time;             /* +0x00: event start/reference (T7) */
    u16 duration_lo;            /* +0x02: 32-bit duration/period, low word */
    u16 duration_hi;            /* +0x04: 32-bit duration/period, high word */
    u16 accum_lo;               /* +0x06: elapsed accumulator, low word */
    u16 accum_hi;               /* +0x08: elapsed accumulator, high word */
    u16 last_time;              /* +0x0A: previous time value (inferred) */
    u8  flags;                  /* +0x0C: active/retrigger/force bits */
    u8  cc_channel;             /* +0x0D: 0x10 = CC16, 0x11 = CC17 */
    u16 compare;                /* +0x0E: CAPCOM compare value */
    u16 control;                /* +0x10: compare-mode/control word */
} cc_event_channel_t;           /* 0x12 bytes */

/* ------------------------------------------------------------------------- */
/* CAPCOM CC22/CC23 test/output channels at 0xC3D2 (stride 0x1A)             */
/* ------------------------------------------------------------------------- */

typedef struct {
    u16 timestamp;              /* +0x00: scheduled T7 timestamp */
    u8  reserved_02[5];         /* +0x02..+0x06: fields not yet recovered */
    u8  flag_07;                /* +0x07 (0xC3D9): channel flag */
    u8  flag_08;                /* +0x08 (0xC3DA): channel flag */
    u8  reserved_09[0x11];      /* +0x09..+0x19: remaining fields */
} cc22_23_channel_t;            /* 0x1A bytes; partial model */

/* ------------------------------------------------------------------------- */
/* Sensor/config setup selected by calibration byte 0xC05036                 */
/* ------------------------------------------------------------------------- */

typedef struct {
    u32 handler[8];             /* 0xC220..0xC23F: selected sensor handlers */
    u8  started;                /* 0xC456: one-shot start flag */
    u8  channel_count;          /* 0xC45E: number of configured channels */
    u16 status;                 /* 0xC44C: setup status */
    u16 coefficients[5];        /* 0xC468..0xC471: from external RAM 0x700E.. */
} sensor_setup_t;

/* ------------------------------------------------------------------------- */
/* Diagnostic status snapshot packed by diag_status_build (0xC60C..0xC610)    */
/* ------------------------------------------------------------------------- */

typedef struct {
    u8 byte0;                   /* 0xC60C: live-data 0x37 fuel cut/DFCO/rollover/C-L reset */
    u8 byte1;                   /* 0xC60D: live-data 0x38 C-L enable/prime/fuel pump/enrich */
    u8 byte2;                   /* 0xC60E: live-data 0x39 O2/IACV/ignition-on */
    u8 byte3;                   /* 0xC60F: live-data 0x3A MAP-CID/idle/PE/clutch/diag/MIL */
    u8 byte4;                   /* 0xC610: live-data 0x3B airflow/baro/spark/cat/run/idle/O2 */
} diag_status_t;

/* ------------------------------------------------------------------------- */
/* Software floating-point value used by the fp_* runtime (4 x 16-bit words)  */
/* ------------------------------------------------------------------------- */

typedef struct {
    u16 word[4];                /* 8 bytes; layout is software-float, not IEEE-754 */
} fp32_t;

/* ------------------------------------------------------------------------- */
/* TwinCAN message object (observed layout, one object per 0x20 bytes)       */
/* ------------------------------------------------------------------------- */

typedef struct {
    u32 arbitration;            /* +0x00 (observed at +0x0A for ID) */
    u32 mask;                   /* +0x04 */
    u16 control;                /* +0x08 */
    u16 reserved_0a;
    u8  data[8];                /* +0x0C: eight data bytes */
    u8  dlc;                    /* +0x14 */
    u8  reserved_15;
    u16 reserved_16;
    u16 reserved_18;
    u16 reserved_1a;
    u16 reserved_1c;
    u16 reserved_1e;
} can_msg_object_t;             /* 0x20 bytes; field offsets are approximate */

/* ------------------------------------------------------------------------- */
/* Calibration table headers                                                 */
/* ------------------------------------------------------------------------- */

typedef struct {
    u16 count;                  /* number of points */
    u16 min;
    u16 max;
} cal_axis_t;

typedef struct {
    u8  count;
    u8  shift;
    u8  data[];                 /* count bytes */
} cal_tbl8_t;

typedef struct {
    u16 count;
    u16 data[];                 /* count words */
} cal_tbl16_t;

typedef struct {
    u8  cols;
    u8  rows;
    u8  shift;
    u8  data[];                 /* row-major cells */
} cal_map2d_t;

/* ------------------------------------------------------------------------- */
/* Adaptation log record (0x200 bytes)                                       */
/* ------------------------------------------------------------------------- */

typedef struct {
    u16 sequence;               /* +0x000 */
    u8  payload[0x1FA];         /* +0x002 */
    u8  signature[2];           /* +0x1FC: 5A A5 */
    u16 tail;                   /* +0x1FE: checksum/tag, big-endian access */
} adapt_record_layout_t;

/* ------------------------------------------------------------------------- */
/* Logical state groups (addresses are not necessarily contiguous)            */
/* ------------------------------------------------------------------------- */

typedef struct {
    u8  rx_index;               /* 0xC0AE */
    u8  state;                  /* 0xC0AF: 5-state receive machine */
    u16 rx_timeout;             /* 0xC0B0 */
    u8  rx_retry;               /* 0xC13E */
    u8  frame_retry;            /* 0xC140 */
    u8  frame_total;            /* 0xC142 */
    u8  tx_phase;               /* 0xC1D0 */
    u8  tx_index;               /* 0xC138 */
    u8  frame_flag;             /* 0xC13C */
    u8  init_mode;              /* 0xC09E */
    u16 init_timer;             /* 0xC0A0 */
    u8  rx_timeout_limit;       /* 0xC0A2 */
    u8  wakeup_pattern[5];      /* 0xC0A3 (RAM) */
    u8  header_pattern[6];      /* 0xC0A8 (RAM, three words) */
    u8  request_pending;        /* 0xC1D1 */
    u8  security_unlocked;      /* 0xC09A */
} kline_transport_t;            /* logical view, not contiguous */

typedef struct {
    u16 state;                  /* 0xC450 */
    u16 state2;                 /* 0xC454 */
    u8  started;                /* 0xC456 */
    u16 input_0;                /* 0x7046 (external RAM) */
    u16 input_1;                /* 0x7048 (external RAM) */
} cc22_23_state_t;              /* logical view */

typedef struct {
    u16 callback_0_lo;          /* 0xC240 */
    u16 callback_0_hi;          /* 0xC242 */
    u16 callback_1_lo;          /* 0xC244 */
    u16 callback_1_hi;          /* 0xC246 */
    u8  sample_counter;         /* 0xC268 */
    u8  input_ready;            /* 0xC280 */
    u16 period_initial;         /* 0xC2B4 */
    u16 period_a;               /* 0xC26A */
    u16 period_b;               /* 0xC26C */
    u16 overflow;               /* 0xC25C */
    u16 enable;                 /* 0xC2AA */
    u16 irq_mask;               /* 0xC28A */
    u16 irq_mask2;              /* 0xC2A2 */
} capture_state_t;              /* logical view */

typedef struct {
    u8  command;                /* 0xFD18: test/actuator command bits */
    u8  timer_0;                /* 0xC5E8 */
    u8  timer_1;                /* 0xC5EA */
    u16 output_gate_0;          /* 0xFD08 */
    u16 output_gate_1;          /* 0xFD06 */
    u16 status;                 /* 0xFD0A */
} test_command_t;               /* logical view */

typedef struct {
    u8  rx_object;              /* 0xC1D2: 9/10 */
    u8  tx_remaining;           /* 0xC1D4 */
    u8  tx_active;              /* 0xC1D6 */
    u16 rx_word_01;             /* 0xC1DA */
    u16 rx_word_23;             /* 0xC1D8 */
    u16 tx_ptr_lo;              /* 0xC1DC */
    u16 tx_ptr_hi;              /* 0xC1DE */
    u8  rx_flag;                /* 0xC016 */
} can_transport_t;              /* logical view */

typedef struct {
    u16 tick;                   /* 0xC54A */
    u16 counter;                /* 0xC54C */
    u16 counter_reload;         /* 0xC550 */
    u16 event_flag;             /* 0xFD14 */
    u16 speed_status;           /* 0xFD02 */
    u16 input_status;           /* 0xFD00 */
    u8  engine_state_valid;     /* 0xC5E6 */
    u16 engine_state;           /* 0xC962: checked against 0x5800..0x6800 */
    u16 fault_flag;             /* 0xCB60 */
} scheduler_state_t;            /* logical view */

typedef struct {
    u16 period;                 /* 0xE892 */
    u16 duty;                   /* 0xE8A2 */
    u16 control;                /* 0xE8A6 */
    u32 divisor;                /* 0xC504 */
    u32 duty_calc;              /* 0xC4EA */
    u16 xram_a0;                /* 0xE8A0 */
    u16 xram_a4;                /* 0xE8A4 */
    u16 xram_a8;                /* 0xE8A8 */
    u16 xram_ac;                /* 0xE8AC */
    u16 xram_ae;                /* 0xE8AE */
    u16 xram_c0;                /* 0xE8C0 */
    u16 xram_c2;                /* 0xE8C2 */
    u16 xram_c4;                /* 0xE8C4 */
    u16 xram_c6;                /* 0xE8C6 */
    u16 xram_ca;                /* 0xE8CA */
    u16 xram_ce;                /* 0xE8CE */
} pwm_state_t;                  /* logical view */

/* ------------------------------------------------------------------------- */
/* Auto-named evidence structures from the whole-image pass (docs/16)        */
/* ------------------------------------------------------------------------- */

/* Logical view of the 0xC9F4/0xCA00 map result block used by c1da6e. */
typedef struct {
    u16 map_70f6_raw;           /* 0xCA00: tbl2d_interp(0x70F6) */
    u16 map_70f6_output;        /* 0xC9F4: clamped output */
} map_70f6_state_t;             /* logical view; not contiguous */

/* Logical view of the 0xCA06..0xCA1C map result block used by c228be. */
typedef struct {
    u16 map_6e50_raw;           /* 0xCA16 */
    u16 map_6e50_ratio;         /* 0xCA12 */
    u16 map_6e50_correction;    /* 0xCA06 */
    u16 map_6e50_output;        /* 0xCA1C */
} map_6e50_state_t;             /* logical view; not contiguous */

/* Record selection state used by c240fe. */
typedef struct {
    u16 selected_value;         /* 0xCB60 */
    u8  select_state;           /* 0xCB64 */
    u8  select_index;           /* 0xCB68 */
} record_select_t;              /* logical view; not contiguous */

/* Hidden-boot/config mode bits written by c27216. */
typedef struct {
    u8  source;                 /* 0xE00903 */
    u8  mode_a;                 /* 0xE008FE */
    u8  mode_b;                 /* 0xE00904 */
    u8  limit_enable;           /* 0xE00905 */
} config_mode_t;                /* logical view */

/* 0x1E-byte records walked by c25600 at 0xC10E. */
typedef struct {
    u8 raw[0x1E];
} adapt_record_1e_t;

/* Fault-index table 0x7286 maps a code to a bit number in 0xC168. */
typedef struct {
    u16 bits;                   /* 0xC168: bit n = fault-index entry maps to n */
} fault_status_t;

/* External-RAM axis pair read by c1105e at 0x7052/0x7054. */
typedef struct {
    u16 a;                      /* 0x7052 */
    u16 b;                      /* 0x7054 */
} axis_pair_7052_t;

#endif
