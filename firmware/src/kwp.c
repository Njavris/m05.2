#include "kwp.h"
#include "mem.h"

#include <string.h>

static void set_resp(kwp_ctx_t *ctx, const u8 *data, int len)
{
    if (len < 0) {
        len = 0;
    }
    if (len > KWP_MAX_PAYLOAD) {
        len = KWP_MAX_PAYLOAD;
    }
    memcpy(ctx->resp, data, (size_t)len);
    ctx->resp_len = len;
}

static void negative(kwp_ctx_t *ctx, u8 sid, u8 nrc)
{
    u8 r[3];
    r[0] = 0x7F;
    r[1] = sid;
    r[2] = nrc;
    set_resp(ctx, r, 3);
}

static u32 addr24(const u8 *data)
{
    return ((u32)data[0] << 16) | ((u32)data[1] << 8) | (u32)data[2];
}

/*
 * The firmware range-checks 0x23/0x3D against RAM/flash windows. This model
 * allows the windows the recovered code uses: external memory work areas,
 * XRAM, IRAM and the flash image. It is a functional model, not a security
 * boundary.
 */
static int allowed_window(u32 addr, u32 len)
{
    static const struct {
        u32 start;
        u32 end;
    } windows[] = {
        { 0x000000u, 0x008000u },
        { 0x00C000u, 0x00D000u },
        { 0x00E000u, 0x00E800u },
        { 0x00F600u, 0x00FE00u },
        { 0xC00000u, 0xC40000u },
    };
    size_t i;

    if (!mem_range_ok(addr, len)) {
        return 0;
    }
    for (i = 0; i < sizeof(windows) / sizeof(windows[0]); ++i) {
        if (addr >= windows[i].start && addr + len <= windows[i].end) {
            return 1;
        }
    }
    return 0;
}

void kwp_ctx_init(kwp_ctx_t *ctx)
{
    memset(ctx, 0, sizeof(*ctx));
}

void kwp_dispatch(kwp_ctx_t *ctx)
{
    u8 sid;
    const u8 *data;
    int len;

    if (ctx->req_len < 1) {
        ctx->resp_len = 0;
        return;
    }

    sid = ctx->req[0];
    data = ctx->req + 1;
    len = ctx->req_len - 1;

    switch (sid) {
    case 0x81: {                       /* StartCommunication */
        static const u8 r[] = { 0xC1, 0xEF, 0x8F };
        set_resp(ctx, r, (int)sizeof(r));
        break;
    }
    case 0x10: {                       /* StartDiagnosticSession */
        u8 r[2];
        if (len >= 1 && (data[0] == 0x81u || data[0] == 0x85u)) {
            r[0] = 0x50;
            r[1] = data[0];
            set_resp(ctx, r, 2);
        } else {
            negative(ctx, 0x10, 0x12);
        }
        break;
    }
    case 0x27: {                       /* SecurityAccess */
        u8 r[4];
        if (len >= 1 && data[0] == 0x01u) {
            r[0] = 0x67;
            r[1] = 0x01;
            r[2] = 0x12;
            r[3] = 0x34;
            set_resp(ctx, r, 4);
        } else if (len >= 3 && data[0] == 0x02u) {
            if (data[1] == 0x84u && data[2] == 0x74u) {
                ctx->security_unlocked = 1;
                r[0] = 0x67;
                r[1] = 0x02;
                r[2] = 0x34;
                set_resp(ctx, r, 3);
            } else {
                negative(ctx, 0x27, 0x35);
            }
        } else {
            negative(ctx, 0x27, 0x12);
        }
        break;
    }
    case 0x83: {                       /* Delphi-specific service */
        u8 r[8];
        if (len >= 1 && data[0] == 0x00u) {
            static const u8 id[] = { 0xC3, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00 };
            set_resp(ctx, id, (int)sizeof(id));
        } else if (len >= 1 && data[0] == 0x03u) {
            r[0] = 0xC3;
            r[1] = 0x03;
            set_resp(ctx, r, 2);
        } else {
            negative(ctx, 0x83, 0x12);
        }
        break;
    }
    case 0x34: {                       /* RequestDownload */
        if (ctx->security_unlocked) {
            static const u8 r[] = { 0x74, 0xFB };
            set_resp(ctx, r, (int)sizeof(r));
        } else {
            negative(ctx, 0x34, 0x33);
        }
        break;
    }
    case 0x36: {                       /* TransferData */
        u32 addr;
        u8 sum = 0;
        int i;
        u8 r[2];

        if (!ctx->security_unlocked) {
            negative(ctx, 0x36, 0x33);
            break;
        }
        if (len < 3 + 0x80) {
            negative(ctx, 0x36, 0x13);
            break;
        }
        addr = addr24(data);
        if (!allowed_window(addr, 0x80u)) {
            negative(ctx, 0x36, 0x31);
            break;
        }
        if (mem_write_block(addr, data + 3, 0x80u) != 0) {
            negative(ctx, 0x36, 0x31);
            break;
        }
        for (i = 0; i < 0x80; ++i) {
            sum = (u8)(sum + data[3 + i]);
        }
        r[0] = 0x76;
        r[1] = sum;
        set_resp(ctx, r, 2);
        break;
    }
    case 0x23: {                       /* ReadMemoryByAddress */
        u32 addr;
        u8 count;
        u8 r[KWP_MAX_PAYLOAD];

        if (len < 4) {
            negative(ctx, 0x23, 0x13);
            break;
        }
        addr = addr24(data);
        count = data[3];
        if (count > 0x80u || !allowed_window(addr, count)) {
            negative(ctx, 0x23, 0x31);
            break;
        }
        r[0] = 0x63;
        if (mem_read_block(addr, r + 1, count) != 0) {
            negative(ctx, 0x23, 0x31);
            break;
        }
        set_resp(ctx, r, 1 + count);
        break;
    }
    case 0x3D: {                       /* WriteMemoryByAddress */
        u32 addr;
        u8 count;
        u8 r[4];

        if (!ctx->security_unlocked) {
            negative(ctx, 0x3D, 0x33);
            break;
        }
        if (len < 5) {
            negative(ctx, 0x3D, 0x13);
            break;
        }
        addr = addr24(data);
        count = data[3];
        if (count > 0x80u || !allowed_window(addr, count)) {
            negative(ctx, 0x3D, 0x31);
            break;
        }
        if (mem_write_block(addr, data + 4, count) != 0) {
            negative(ctx, 0x3D, 0x31);
            break;
        }
        r[0] = 0x7D;
        r[1] = data[0];
        r[2] = data[1];
        r[3] = data[2];
        set_resp(ctx, r, 4);
        break;
    }
    default:
        negative(ctx, sid, 0x11);
        break;
    }
}

int kwp_build_kline_frame(const kwp_ctx_t *ctx, u8 *out, int max)
{
    int i;
    int n = ctx->resp_len;
    u8 sum = 0;

    if (n < 0 || n > 0xFF || n + 5 > max) {
        return -1;
    }
    out[0] = 0x80;                 /* format */
    out[1] = 0xF1;                 /* tester */
    out[2] = 0x11;                 /* ECU */
    out[3] = (u8)n;
    memcpy(out + 4, ctx->resp, (size_t)n);
    for (i = 0; i < 4 + n; ++i) {
        sum = (u8)(sum + out[i]);
    }
    out[4 + n] = sum;
    return 5 + n;
}

int kwp_parse_kline_frame(const u8 *in, int len, kwp_ctx_t *ctx)
{
    int i;
    int n;
    u8 sum = 0;

    if (len < 5) {
        return -1;
    }
    if (in[0] != 0x80u) {
        return -2;
    }
    if (in[1] != 0x11u || in[2] != 0xF1u) {
        return -3;
    }
    n = in[3];
    if (len != n + 5) {
        return -4;
    }
    for (i = 0; i < 4 + n; ++i) {
        sum = (u8)(sum + in[i]);
    }
    if (sum != in[4 + n]) {
        return -5;
    }
    memcpy(ctx->req, in + 4, (size_t)n);
    ctx->req_len = n;
    return n;
}
