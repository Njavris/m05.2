#ifndef C166_H
#define C166_H

#include <stdint.h>
#include <stddef.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;

#define C166_FLASH_BASE   0xC00000u
#define C166_FLASH_SIZE   0x00040000u
#define C166_SPACE_SIZE   0x01000000u

#define C166_BOOT_START   0xC00000u
#define C166_BOOT_END     0xC02000u
#define C166_CAL_START    0xC05000u
#define C166_CAL_END      0xC0B000u
#define C166_APP_START    0xC0B000u
#define C166_APP_END      0xC40000u
#define C166_ADAPT_START  0xC04000u
#define C166_ADAPT_END    0xC04D00u

#endif
