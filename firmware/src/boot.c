#include "boot.h"
#include "checksum.h"
#include "mem.h"

const char *boot_mode_name(boot_mode_t mode)
{
    switch (mode) {
    case BOOT_APP:
        return "application";
    case BOOT_BOOTLOADER:
        return "bootloader";
    case BOOT_MINIMAL:
        return "minimal";
    default:
        return "unknown";
    }
}

boot_mode_t boot_select_mode(u16 ch0, u16 ch3, u16 ch4, u16 ch5, u16 ch6)
{
    /*
     * Decision tree from boot_reset at 0xC00A78.
     * ADC results are 10-bit: (ADDAT & 0x0FFF) >> 2.
     */
    if (ch0 > 0x396u) {
        if (ch3 > 0x396u) {
            if (ch4 < 0x67u) {
                if (ch6 < 0x67u) {
                    return BOOT_MINIMAL;
                }
            }
        }
    }

    if (ch6 > 0x396u) {
        if (ch4 > 0x396u) {
            if (ch5 < 0x15u) {
                return BOOT_BOOTLOADER;
            }
        }
    }

    return BOOT_APP;
}

boot_mode_t boot_validate(void)
{
    /*
     * boot_main at 0xC00200.
     * 0xC3FFFC == 0xAA00 is the already-validated fast path.
     */
    if (mem_read16(0xC3FFFCu) == 0xAA00u) {
        return BOOT_APP;
    }

    if (checksum16_be(0xC00000u, 0xC01FFEu) != mem_read16(0xC01FFEu)) {
        return BOOT_BOOTLOADER;
    }

    if (checksum16_be(0xC0B000u, 0xC3FFFCu) != mem_read16(0xC3FFFEu)) {
        return BOOT_BOOTLOADER;
    }

    return BOOT_APP;
}
