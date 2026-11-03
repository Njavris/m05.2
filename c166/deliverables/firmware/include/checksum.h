#ifndef CHECKSUM_H
#define CHECKSUM_H

#include "c166.h"

/*
 * The Delphi boot block sums 16-bit words in big-endian byte order:
 *   sum += (byte[addr] << 8) | byte[addr + 1]
 * The range is [start, end), and both addresses are even.
 */
u16 checksum16_be(u32 start, u32 end);

#endif
