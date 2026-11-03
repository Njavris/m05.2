#ifndef KWP_H
#define KWP_H

#include "c166.h"

#define KWP_MAX_PAYLOAD 256

typedef struct {
    u8  req[KWP_MAX_PAYLOAD];
    int req_len;
    u8  resp[KWP_MAX_PAYLOAD];
    int resp_len;
    int security_unlocked;
} kwp_ctx_t;

void kwp_ctx_init(kwp_ctx_t *ctx);

/*
 * Models the KWP2000 service dispatcher at 0xC01482.
 *
 * The model payload layout is:
 *   req[0]   service identifier (0x10, 0x23, 0x27, ...)
 *   req[1..] service data
 * The firmware's on-wire RAM buffer at 0xC147/0xC148 uses a one-byte
 * offset; that transport detail is handled by kwp_parse_kline_frame().
 */
void kwp_dispatch(kwp_ctx_t *ctx);

/*
 * Builds the K-line response frame observed in asc0_state5:
 *   0x80, 0xF1 (tester), 0x11 (ECU), length, payload..., 8-bit checksum
 */
int kwp_build_kline_frame(const kwp_ctx_t *ctx, u8 *out, int max);

/*
 * Parses a tester request frame:
 *   0x80, 0x11 (ECU), 0xF1 (tester), length, payload..., 8-bit checksum
 */
int kwp_parse_kline_frame(const u8 *in, int len, kwp_ctx_t *ctx);

#endif
