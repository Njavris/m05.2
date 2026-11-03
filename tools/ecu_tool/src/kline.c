#include "kline.h"

#include <stdio.h>
#include <string.h>

static void set_error(char *err, size_t errlen, const char *msg)
{
    if (err && errlen) {
        snprintf(err, errlen, "%s", msg);
    }
}

static uint8_t frame_checksum(const uint8_t *data, size_t len)
{
    uint8_t sum = 0;
    size_t i;
    for (i = 0; i < len; ++i) {
        sum = (uint8_t)(sum + data[i]);
    }
    return sum;
}

static void dump_hex(const char *tag, const uint8_t *data, size_t len)
{
    size_t i;
    fprintf(stderr, "%s", tag);
    for (i = 0; i < len; ++i) {
        fprintf(stderr, " %02X", data[i]);
    }
    fputc('\n', stderr);
}

static int read_prefix(kline_ctx *ctx, uint8_t *data, size_t maxlen)
{
    int n = serial_read(ctx->port, data, maxlen, ctx->timeout_ms);
    size_t got;
    if (n <= 0) {
        return n;
    }
    got = (size_t)n;
    while (got < maxlen) {
        n = serial_read(ctx->port, data + got, maxlen - got, 20);
        if (n <= 0) {
            break;
        }
        got += (size_t)n;
    }
    return (int)got;
}

static int request_retries(kline_ctx *ctx, const uint8_t *req, size_t req_len,
                           uint8_t *resp, size_t resp_cap, size_t *resp_len,
                           int retries, char *err, size_t errlen)
{
    uint8_t frame[4 + KLINE_MAX_PAYLOAD + 1];
    uint8_t echo[4 + KLINE_MAX_PAYLOAD + 1];
    uint8_t rx[4 + KLINE_MAX_PAYLOAD + 1 + 64];
    int attempt;

    if (!ctx || !ctx->port || !req || req_len > KLINE_MAX_PAYLOAD ||
        !resp || !resp_len) {
        set_error(err, errlen, "invalid request");
        return -1;
    }
    frame[0] = 0x80;
    frame[1] = KLINE_ECU_ADDR;
    frame[2] = KLINE_TESTER_ADDR;
    frame[3] = (uint8_t)req_len;
    memcpy(frame + 4, req, req_len);
    frame[4 + req_len] = frame_checksum(frame, 4 + req_len);

    for (attempt = 0; attempt < retries; ++attempt) {
        size_t frame_len = 5 + req_len;
        size_t rxlen = 0;
        size_t need;
        int n;
        uint8_t len;
        uint8_t sum;

        serial_flush(ctx->port);
        if (ctx->verbose) {
            dump_hex("TX", frame, frame_len);
        }
        if (serial_write_all(ctx->port, frame, frame_len) != 0) {
            set_error(err, errlen, "serial write failed");
            continue;
        }
        n = read_prefix(ctx, echo, frame_len);
        if (n == (int)frame_len && memcmp(echo, frame, frame_len) == 0) {
            if (ctx->verbose) {
                dump_hex("ECHO", echo, frame_len);
            }
            rxlen = 0;
        } else if (n > 0) {
            memcpy(rx, echo, (size_t)n);
            rxlen = (size_t)n;
        }

        while (rxlen < 4) {
            n = serial_read(ctx->port, rx + rxlen, sizeof(rx) - rxlen,
                            ctx->timeout_ms);
            if (n <= 0) {
                break;
            }
            rxlen += (size_t)n;
        }
        if (rxlen < 4) {
            set_error(err, errlen, "timeout waiting for response header");
            continue;
        }
        if (ctx->verbose) {
            dump_hex("RX", rx, rxlen);
        }
        if (rx[0] != 0x80) {
            set_error(err, errlen, "not a K-line 0x80 frame");
            continue;
        }
        if (rx[1] != KLINE_TESTER_ADDR || rx[2] != KLINE_ECU_ADDR) {
            set_error(err, errlen, "unexpected K-line addresses");
            continue;
        }
        len = rx[3];
        need = 4u + len + 1u;
        if (need > sizeof(rx)) {
            set_error(err, errlen, "response too large");
            continue;
        }
        while (rxlen < need) {
            n = serial_read(ctx->port, rx + rxlen, sizeof(rx) - rxlen,
                            ctx->timeout_ms);
            if (n <= 0) {
                break;
            }
            rxlen += (size_t)n;
        }
        if (rxlen < need) {
            set_error(err, errlen, "timeout waiting for response body");
            continue;
        }
        sum = frame_checksum(rx, need - 1);
        if (sum != rx[need - 1]) {
            set_error(err, errlen, "K-line checksum mismatch");
            continue;
        }
        if (len > resp_cap) {
            set_error(err, errlen, "response buffer too small");
            return -1;
        }
        memcpy(resp, rx + 4, len);
        *resp_len = len;
        if (ctx->verbose) {
            dump_hex("PAYLOAD", resp, len);
        }
        return 0;
    }
    return -1;
}

int kline_request(kline_ctx *ctx, const uint8_t *req, size_t req_len,
                  uint8_t *resp, size_t resp_cap, size_t *resp_len,
                  char *err, size_t errlen)
{
    return request_retries(ctx, req, req_len, resp, resp_cap, resp_len, 3,
                           err, errlen);
}

int kline_connect(kline_ctx *ctx, serial_port *port,
                  unsigned timeout_ms, int verbose,
                  char *err, size_t errlen)
{
    uint8_t req[] = {0x81};
    uint8_t resp[16];
    size_t resp_len = 0;
    int attempt;

    if (!ctx || !port) {
        set_error(err, errlen, "invalid port");
        return -1;
    }
    memset(ctx, 0, sizeof(*ctx));
    ctx->port = port;
    ctx->timeout_ms = timeout_ms;
    ctx->verbose = verbose;

    for (attempt = 0; attempt < 3; ++attempt) {
        serial_flush(port);
        serial_set_break(port, 1);
        serial_sleep_ms(25);
        serial_set_break(port, 0);
        serial_sleep_ms(25);
        serial_flush(port);
        if (request_retries(ctx, req, sizeof(req), resp, sizeof(resp),
                            &resp_len, 1, err, errlen) == 0) {
            if (resp_len >= 1 && resp[0] == 0xC1) {
                return 0;
            }
            set_error(err, errlen, "StartCommunication was rejected");
        }
    }
    set_error(err, errlen, "no K-line StartCommunication response");
    return -1;
}

int kline_read_memory(kline_ctx *ctx, uint32_t addr, uint8_t *data, size_t len,
                      char *err, size_t errlen)
{
    while (len > 0) {
        uint8_t req[5];
        uint8_t resp[1 + 0x80];
        size_t resp_len = 0;
        size_t count = len > 0x80 ? 0x80 : len;

        req[0] = 0x23;
        req[1] = (uint8_t)(addr >> 16);
        req[2] = (uint8_t)(addr >> 8);
        req[3] = (uint8_t)addr;
        req[4] = (uint8_t)count;
        if (kline_request(ctx, req, sizeof(req), resp, sizeof(resp),
                          &resp_len, err, errlen) != 0) {
            return -1;
        }
        if (resp_len < 1 || resp[0] != 0x63) {
            set_error(err, errlen, "ReadMemoryByAddress rejected");
            return -1;
        }
        if (resp_len < 1 + count) {
            set_error(err, errlen, "short ReadMemoryByAddress response");
            return -1;
        }
        memcpy(data, resp + 1, count);
        addr += (uint32_t)count;
        data += count;
        len -= count;
    }
    return 0;
}

int kline_read_live(kline_ctx *ctx, uint8_t data[100],
                    char *err, size_t errlen)
{
    uint8_t req[] = {0x21, 0x01};
    uint8_t resp[128];
    size_t resp_len = 0;

    if (kline_request(ctx, req, sizeof(req), resp, sizeof(resp),
                      &resp_len, err, errlen) != 0) {
        return -1;
    }
    if (resp_len < 2 || resp[0] != 0x61 || resp[1] != 0x01) {
        set_error(err, errlen, "21 01 live-data packet not supported");
        return -1;
    }
    if (resp_len < 102) {
        set_error(err, errlen, "short 21 01 live-data packet");
        return -1;
    }
    memcpy(data, resp + 2, 100);
    return 0;
}

int kline_security_unlock(kline_ctx *ctx, char *err, size_t errlen)
{
    uint8_t req[4];
    uint8_t resp[16];
    size_t resp_len = 0;

    req[0] = 0x27;
    req[1] = 0x01;
    if (kline_request(ctx, req, 2, resp, sizeof(resp), &resp_len,
                      err, errlen) != 0) {
        return -1;
    }
    if (resp_len < 2 || resp[0] != 0x67 || resp[1] != 0x01) {
        set_error(err, errlen, "security seed request rejected");
        return -1;
    }
    req[0] = 0x27;
    req[1] = 0x02;
    req[2] = 0x84;
    req[3] = 0x74;
    if (kline_request(ctx, req, sizeof(req), resp, sizeof(resp), &resp_len,
                      err, errlen) != 0) {
        return -1;
    }
    if (resp_len < 2 || resp[0] != 0x67 || resp[1] != 0x02) {
        set_error(err, errlen, "security key rejected");
        return -1;
    }
    return 0;
}

int kline_request_download(kline_ctx *ctx, char *err, size_t errlen)
{
    uint8_t req[] = {0x34};
    uint8_t resp[16];
    size_t resp_len = 0;

    if (kline_request(ctx, req, sizeof(req), resp, sizeof(resp), &resp_len,
                      err, errlen) != 0) {
        return -1;
    }
    if (resp_len < 1 || resp[0] != 0x74) {
        set_error(err, errlen, "RequestDownload rejected");
        return -1;
    }
    return 0;
}

int kline_transfer_block(kline_ctx *ctx, uint32_t addr,
                         const uint8_t data[128], char *err, size_t errlen)
{
    uint8_t req[4 + 128];
    uint8_t resp[16];
    size_t resp_len = 0;
    uint8_t sum = 0;
    int i;

    req[0] = 0x36;
    req[1] = (uint8_t)(addr >> 16);
    req[2] = (uint8_t)(addr >> 8);
    req[3] = (uint8_t)addr;
    memcpy(req + 4, data, 128);
    for (i = 0; i < 128; ++i) {
        sum = (uint8_t)(sum + data[i]);
    }
    if (request_retries(ctx, req, sizeof(req), resp, sizeof(resp), &resp_len,
                        1, err, errlen) != 0) {
        return -1;
    }
    if (resp_len < 2 || resp[0] != 0x76 || resp[1] != sum) {
        set_error(err, errlen, "TransferData rejected or bad sum");
        return -1;
    }
    return 0;
}
