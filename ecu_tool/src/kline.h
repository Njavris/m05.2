#ifndef ECU_TOOL_KLINE_H
#define ECU_TOOL_KLINE_H

#include "serial.h"

#include <stddef.h>
#include <stdint.h>

#define KLINE_ECU_ADDR 0x11u
#define KLINE_TESTER_ADDR 0xF1u
#define KLINE_MAX_PAYLOAD 255u

typedef struct {
    serial_port *port;
    unsigned timeout_ms;
    int verbose;
} kline_ctx;

int kline_connect(kline_ctx *ctx, serial_port *port,
                  unsigned timeout_ms, int verbose,
                  char *err, size_t errlen);
int kline_request(kline_ctx *ctx, const uint8_t *req, size_t req_len,
                  uint8_t *resp, size_t resp_cap, size_t *resp_len,
                  char *err, size_t errlen);
int kline_read_memory(kline_ctx *ctx, uint32_t addr, uint8_t *data, size_t len,
                      char *err, size_t errlen);
int kline_read_live(kline_ctx *ctx, uint8_t data[100],
                    char *err, size_t errlen);
int kline_security_unlock(kline_ctx *ctx, char *err, size_t errlen);
int kline_request_download(kline_ctx *ctx, char *err, size_t errlen);
int kline_transfer_block(kline_ctx *ctx, uint32_t addr,
                         const uint8_t data[128], char *err, size_t errlen);

#endif
