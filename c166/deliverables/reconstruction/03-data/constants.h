#ifndef MT05_CONSTANTS_H
#define MT05_CONSTANTS_H

/* Delphi MT05.2 / Infineon XC164CS-32 flash and calibration constants.
 * These are addresses and fixed values observed in the firmware. */

#define FLASH_BASE                 0xC00000u
#define FLASH_SIZE                 0x00040000u

#define BOOT_BLOCK_START           0xC00000u
#define BOOT_BLOCK_END             0xC02000u
#define BOOT_CHECKSUM_ADDR         0xC01FFEu

#define ADAPTATION_LOG_START       0xC04000u
#define ADAPTATION_LOG_END         0xC04D00u

#define CAL_BLOCK_START            0xC05000u
#define CAL_BLOCK_END              0xC0B000u
#define CAL_CHECKSUM_ADDR          0xC0AFFEu
#define CAL_ID_ADDR                0xC05000u

#define APP_BLOCK_START            0xC0B000u
#define APP_BLOCK_END              0xC40000u
#define APP_CHECKSUM_ADDR          0xC3FFFEu
#define APP_MAGIC_ADDR             0xC3FFFCu

/* Calibration configuration selectors */
#define CAL_CONFIG_SELECTOR_ADDR   0xC05036u
#define CAL_CAPTURE_CONFIG_ADDR    0xC05064u
#define CAL_TIMER_CONFIG_ADDR      0xC05068u
#define CAL_ADC_CONFIG_ADDR        0xC0506Au
#define CAL_CALC_VARIANT_ADDR      0xC0507Au
#define CAL_CC22_CONFIG_ADDR       0xC05080u
#define CAL_PWM_CONFIG_ADDR        0xC05081u

/* Limit/load scalars */
#define CAL_SPEED_LIMIT_THRESHOLD  0xC0781Eu
#define CAL_LIMIT_MULTIPLIER       0xC07830u
#define CAL_LIMIT_COUNTER_THRESHOLD 0xC07832u
#define CAL_LIMIT_COUNT            0xC07834u
#define CAL_LIMIT_FALLBACK_SPEED   0xC0783Cu
#define CAL_PWM_SCALE              0xC078E0u
#define CAL_LIMIT_FLAG             0xC079CAu
#define CAL_CC_START_OFFSET        0xC079DAu

/* Table bases (see data.c) */
#define CAL_LIMIT_CURVE_0          0xC0784Cu
#define CAL_LIMIT_CURVE_1          0xC07860u
#define CAL_LIMIT_CURVE_2          0xC07874u
#define CAL_LIMIT_CURVE_3          0xC078D8u
#define CAL_LIMIT_MULTIPLIER_CURVE 0xC078E2u
#define CAL_LIMIT_TABLE16          0xC07912u
#define CAL_LOAD_MAP               0xC0794Au
#define CAL_CONSTANT_CURVE_0       0xC0799Eu
#define CAL_CONSTANT_CURVE_1       0xC079AAu
#define CAL_CORRECTION_CURVE       0xC079B6u

#endif /* MT05_CONSTANTS_H */
