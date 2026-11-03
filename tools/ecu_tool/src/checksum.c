#include "checksum.h"

uint16_t checksum16_be(const uint8_t *data, size_t len)
{
    uint32_t sum = 0;
    size_t i;

    for (i = 0; i + 1 < len; i += 2) {
        sum += ((uint32_t)data[i] << 8) | data[i + 1];
    }
    return (uint16_t)(sum & 0xFFFFu);
}

int checksum_selftest(void)
{
    static const uint8_t sample[] = {0x01, 0x02, 0x03, 0x04};
    return checksum16_be(sample, sizeof(sample)) == 0x0406u ? 0 : -1;
}
