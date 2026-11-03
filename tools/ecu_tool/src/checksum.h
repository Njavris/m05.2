#ifndef ECU_TOOL_CHECKSUM_H
#define ECU_TOOL_CHECKSUM_H

#include <stddef.h>
#include <stdint.h>

uint16_t checksum16_be(const uint8_t *data, size_t len);
int checksum_selftest(void);

#endif
