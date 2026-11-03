#include "app_init_table.h"

const mt05_app_init_copy_t mt05_app_init_copies[] = {
    { 0x00C1FC, 0xC0BB54, 2, 0, "pwm_phase_counter", "c0cf48 increments this value while PWM config steps; init table zeroes it", "medium" },
    { 0x00C3A0, 0xC0BD9E, 3, 0, "timer4_gate_state", "c0bdc8 writes 1 and tests this field; init table zeroes it", "medium" },
    { 0x00C492, 0xC0BFD8, 1, 0, "ssc_rx_bytes_remaining", "c0ff34 decrements per SSCRB byte and reloads 7", "high" },
    { 0x00C4CC, 0xC0BFDA, 1, 0, "t8_capture_state", "c1078c uses this in the T8 capture path; init table zeroes it", "medium" },
    { 0x00C506, 0xC0BFDC, 2, 0, "engine_start_phase", "c1168a selects phase 0/1 and stores this state", "medium" },
    { 0x00C546, 0xC0BFDE, 4, 0, "cal_checksum_accum", "cal_checksum accumulates here; init table zeroes it", "high" },
    { 0x00C550, 0xC0BFF2, 2, 3855, "scheduler_counter_reload", "scheduler_tick compares counter 0xC54C with this reload", "high" },
    { 0x00C5FE, 0xC0BFFA, 4, 0, "engine_limit_state", "c142da sets/clears this around a 0x2CB threshold", "medium" },
    { 0x00FD1E, 0xC0BFFE, 2, 0, "status_flag_fd1e", "bit0/bit1 status bits cleared by c23e42/c23e4e", "medium" },
};
const size_t mt05_app_init_copy_count = sizeof(mt05_app_init_copies) / sizeof(mt05_app_init_copies[0]);
