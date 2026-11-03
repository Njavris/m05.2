#ifndef ECU_TOOL_LIVE_H
#define ECU_TOOL_LIVE_H

#include <stdint.h>

void live_print_header(int csv);
void live_print(const uint8_t data[100], int csv);
void live_print_status(const uint8_t data[100]);
int live_selftest(void);

#endif
