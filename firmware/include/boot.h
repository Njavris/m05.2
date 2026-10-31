#ifndef BOOT_H
#define BOOT_H

#include "c166.h"

typedef enum {
    BOOT_APP = 0,
    BOOT_BOOTLOADER,
    BOOT_MINIMAL
} boot_mode_t;

const char *boot_mode_name(boot_mode_t mode);

/*
 * Models the reset-code ADC decision tree. The arguments are 10-bit ADC
 * results for the channels the firmware samples (0, 3, 4, 5, 6).
 */
boot_mode_t boot_select_mode(u16 ch0, u16 ch3, u16 ch4, u16 ch5, u16 ch6);

/*
 * Models boot_main at 0xC00200: magic check, boot-block checksum, then
 * application-block checksum.
 */
boot_mode_t boot_validate(void);

#endif
