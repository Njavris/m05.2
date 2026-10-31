#include "checksum.h"
#include "kline.h"
#include "live.h"
#include "serial.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLASH_BASE 0xC00000u
#define FLASH_SIZE 0x00040000u
#define CAL_OFFSET 0x00005000u
#define CAL_SIZE 0x00006000u
#define CAL_CHECKSUM_OFFSET 0x00005FFEu

typedef struct {
    const char *port;
    unsigned baud;
    unsigned timeout_ms;
    int verbose;
    const char *command;
    const char *out;
    int out_set;
    const char *file;
    uint32_t addr;
    size_t len;
    unsigned interval_ms;
    int count;
    int csv;
    int status;
    int i_understand;
} options;

static void usage(const char *argv0)
{
    fprintf(stderr,
        "Usage: %s [options] <command> [command options]\n"
        "\n"
        "Commands:\n"
        "  live                 Poll 21 01 and print live data\n"
        "  dump                 Read the complete 256 KB flash to a BIN file\n"
        "  read                 Read a memory range (needs --addr and --len)\n"
        "  ids                  Read 21 03 / 21 04 / 21 FF and calibration ID\n"
        "  write-cal            Experimental calibration-block write (0x36)\n"
        "  selftest             Run offline frame/parser/checksum tests\n"
        "\n"
        "Options:\n"
        "  --port PATH          Serial port (default /dev/ttyUSB0 or COM3)\n"
        "  --baud N             Baud rate (default 10400)\n"
        "  --timeout MS         Per-response timeout (default 1000)\n"
        "  --verbose            Print TX/RX frames\n"
        "  --out FILE           Output for dump/read\n"
        "  --addr 0x...         Address for read\n"
        "  --len N              Length for read\n"
        "  --file FILE          Full 256 KB image or 24 KB calibration block\n"
        "  --interval MS        Live polling interval (default 250)\n"
        "  --count N            Stop after N live samples\n"
        "  --csv                CSV output for live\n"
        "  --status             Print decoded status bits\n"
        "  --i-understand       Required for write-cal\n"
        "  -h, --help           This help\n",
        argv0);
}

static int parse_u32(const char *text, uint32_t *out)
{
    char *end = NULL;
    unsigned long value;

    if (!text || !*text) {
        return -1;
    }
    errno = 0;
    value = strtoul(text, &end, 0);
    if (errno != 0 || !end || *end != '\0' || value > 0xFFFFFFFFul) {
        return -1;
    }
    *out = (uint32_t)value;
    return 0;
}

static int parse_size(const char *text, size_t *out)
{
    uint32_t value;
    if (parse_u32(text, &value) != 0) {
        return -1;
    }
    *out = (size_t)value;
    return 0;
}

static int parse_options(int argc, char **argv, options *opt)
{
    int i;

    memset(opt, 0, sizeof(*opt));
#ifdef _WIN32
    opt->port = "COM3";
#else
    opt->port = "/dev/ttyUSB0";
#endif
    opt->baud = 10400;
    opt->timeout_ms = 1000;
    opt->interval_ms = 250;
    opt->out = "flash_dump.bin";

    for (i = 1; i < argc; ++i) {
        const char *arg = argv[i];
        if (!strcmp(arg, "-h") || !strcmp(arg, "--help")) {
            opt->command = "help";
        } else if (!strcmp(arg, "--port") && i + 1 < argc) {
            opt->port = argv[++i];
        } else if (!strcmp(arg, "--baud") && i + 1 < argc) {
            uint32_t v;
            if (parse_u32(argv[++i], &v) != 0) return -1;
            opt->baud = v;
        } else if (!strcmp(arg, "--timeout") && i + 1 < argc) {
            uint32_t v;
            if (parse_u32(argv[++i], &v) != 0) return -1;
            opt->timeout_ms = v;
        } else if (!strcmp(arg, "--verbose")) {
            opt->verbose = 1;
        } else if (!strcmp(arg, "--out") && i + 1 < argc) {
            opt->out = argv[++i];
            opt->out_set = 1;
        } else if (!strcmp(arg, "--file") && i + 1 < argc) {
            opt->file = argv[++i];
        } else if (!strcmp(arg, "--addr") && i + 1 < argc) {
            if (parse_u32(argv[++i], &opt->addr) != 0) return -1;
        } else if (!strcmp(arg, "--len") && i + 1 < argc) {
            if (parse_size(argv[++i], &opt->len) != 0) return -1;
        } else if (!strcmp(arg, "--interval") && i + 1 < argc) {
            uint32_t v;
            if (parse_u32(argv[++i], &v) != 0) return -1;
            opt->interval_ms = v;
        } else if (!strcmp(arg, "--count") && i + 1 < argc) {
            uint32_t v;
            if (parse_u32(argv[++i], &v) != 0) return -1;
            opt->count = (int)v;
        } else if (!strcmp(arg, "--csv")) {
            opt->csv = 1;
        } else if (!strcmp(arg, "--status")) {
            opt->status = 1;
        } else if (!strcmp(arg, "--i-understand")) {
            opt->i_understand = 1;
        } else if (arg[0] == '-') {
            fprintf(stderr, "unknown option: %s\n", arg);
            return -1;
        } else if (!opt->command) {
            opt->command = arg;
        } else {
            fprintf(stderr, "unexpected argument: %s\n", arg);
            return -1;
        }
    }
    if (!opt->command) {
        return -1;
    }
    return 0;
}

static int connect_ecu(const options *opt, serial_port **port,
                       kline_ctx *ctx, char *err, size_t errlen)
{
    *port = serial_open(opt->port, opt->baud, err, errlen);
    if (!*port) {
        return -1;
    }
    if (kline_connect(ctx, *port, opt->timeout_ms, opt->verbose,
                      err, errlen) != 0) {
        serial_close(*port);
        *port = NULL;
        return -1;
    }
    return 0;
}

static uint16_t stored_checksum(const uint8_t *image, size_t offset)
{
    return (uint16_t)(image[offset] | ((uint16_t)image[offset + 1] << 8));
}

static int verify_image(const uint8_t *image)
{
    struct {
        const char *name;
        size_t start;
        size_t length;
        size_t stored;
    } blocks[] = {
        {"boot", 0x00000, 0x01FFE, 0x01FFE},
        {"calibration", 0x05000, 0x05FFE, 0x0AFFE},
        {"application", 0x0B000, 0x34FFE, 0x3FFFE},
    };
    size_t i;
    int ok = 1;

    for (i = 0; i < sizeof(blocks) / sizeof(blocks[0]); ++i) {
        uint16_t computed = checksum16_be(image + blocks[i].start,
                                          blocks[i].length);
        uint16_t stored = stored_checksum(image, blocks[i].stored);
        printf("%-12s computed 0x%04X stored 0x%04X %s\n",
               blocks[i].name, computed, stored,
               computed == stored ? "ok" : "MISMATCH");
        if (computed != stored) {
            ok = 0;
        }
    }
    return ok ? 0 : -1;
}

static int write_file(const char *path, const uint8_t *data, size_t len)
{
    FILE *f = fopen(path, "wb");
    if (!f) {
        fprintf(stderr, "cannot write %s: %s\n", path, strerror(errno));
        return -1;
    }
    if (len && fwrite(data, 1, len, f) != len) {
        fprintf(stderr, "short write to %s\n", path);
        fclose(f);
        return -1;
    }
    fclose(f);
    return 0;
}

static uint8_t *read_file(const char *path, size_t *size)
{
    FILE *f;
    long length;
    uint8_t *data;

    f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "cannot open %s: %s\n", path, strerror(errno));
        return NULL;
    }
    if (fseek(f, 0, SEEK_END) != 0) {
        fclose(f);
        return NULL;
    }
    length = ftell(f);
    if (length < 0 || fseek(f, 0, SEEK_SET) != 0) {
        fclose(f);
        return NULL;
    }
    data = (uint8_t *)malloc((size_t)length ? (size_t)length : 1);
    if (!data) {
        fclose(f);
        return NULL;
    }
    if (length && fread(data, 1, (size_t)length, f) != (size_t)length) {
        free(data);
        fclose(f);
        return NULL;
    }
    fclose(f);
    *size = (size_t)length;
    return data;
}

static void print_hex(const uint8_t *data, size_t len, uint32_t base)
{
    size_t i;
    for (i = 0; i < len; i += 16) {
        size_t j;
        printf("%06X: ", (unsigned)(base + i));
        for (j = 0; j < 16; ++j) {
            if (i + j < len) {
                printf("%02X ", data[i + j]);
            } else {
                printf("   ");
            }
        }
        printf(" ");
        for (j = 0; j < 16 && i + j < len; ++j) {
            uint8_t c = data[i + j];
            putchar(c >= 32 && c < 127 ? c : '.');
        }
        putchar('\n');
    }
}

static int cmd_live(const options *opt)
{
    serial_port *port = NULL;
    kline_ctx ctx;
    char err[256];
    uint8_t data[100];
    int samples = 0;
    int failures = 0;

    if (connect_ecu(opt, &port, &ctx, err, sizeof(err)) != 0) {
        fprintf(stderr, "connect: %s\n", err);
        return 1;
    }
    live_print_header(opt->csv);
    while (opt->count == 0 || samples < opt->count) {
        if (kline_read_live(&ctx, data, err, sizeof(err)) != 0) {
            fprintf(stderr, "live: %s\n", err);
            if (++failures >= 3) {
                serial_close(port);
                return 1;
            }
        } else {
            failures = 0;
            live_print(data, opt->csv);
            if (opt->status) {
                live_print_status(data);
            }
            fflush(stdout);
            ++samples;
        }
        serial_sleep_ms(opt->interval_ms);
    }
    serial_close(port);
    return 0;
}

static int cmd_dump(const options *opt)
{
    serial_port *port = NULL;
    kline_ctx ctx;
    char err[256];
    uint8_t *image;
    size_t offset;

    image = (uint8_t *)malloc(FLASH_SIZE);
    if (!image) {
        fprintf(stderr, "out of memory\n");
        return 1;
    }
    if (connect_ecu(opt, &port, &ctx, err, sizeof(err)) != 0) {
        fprintf(stderr, "connect: %s\n", err);
        free(image);
        return 1;
    }
    for (offset = 0; offset < FLASH_SIZE; offset += 0x4000) {
        size_t chunk = FLASH_SIZE - offset;
        if (chunk > 0x4000) {
            chunk = 0x4000;
        }
        fprintf(stderr, "\rreading 0x%06X / 0x%06X",
                (unsigned)(FLASH_BASE + offset), (unsigned)(FLASH_BASE + FLASH_SIZE));
        fflush(stderr);
        if (kline_read_memory(&ctx, FLASH_BASE + (uint32_t)offset,
                              image + offset, chunk, err, sizeof(err)) != 0) {
            fprintf(stderr, "\ndump failed at 0x%06X: %s\n",
                    (unsigned)(FLASH_BASE + offset), err);
            serial_close(port);
            free(image);
            return 1;
        }
    }
    fprintf(stderr, "\n");
    serial_close(port);
    if (write_file(opt->out, image, FLASH_SIZE) != 0) {
        free(image);
        return 1;
    }
    printf("wrote %s (%u bytes)\n", opt->out, FLASH_SIZE);
    if (verify_image(image) != 0) {
        fprintf(stderr, "warning: one or more flash checksums do not match\n");
        free(image);
        return 2;
    }
    free(image);
    return 0;
}

static int cmd_read(const options *opt)
{
    serial_port *port = NULL;
    kline_ctx ctx;
    char err[256];
    uint8_t *data;

    if (opt->len == 0) {
        fprintf(stderr, "read needs --len\n");
        return 1;
    }
    data = (uint8_t *)malloc(opt->len);
    if (!data) {
        fprintf(stderr, "out of memory\n");
        return 1;
    }
    if (connect_ecu(opt, &port, &ctx, err, sizeof(err)) != 0) {
        fprintf(stderr, "connect: %s\n", err);
        free(data);
        return 1;
    }
    if (kline_read_memory(&ctx, opt->addr, data, opt->len, err, sizeof(err)) != 0) {
        fprintf(stderr, "read: %s\n", err);
        serial_close(port);
        free(data);
        return 1;
    }
    serial_close(port);
    if (opt->out_set) {
        if (write_file(opt->out, data, opt->len) != 0) {
            free(data);
            return 1;
        }
        printf("wrote %s (%zu bytes)\n", opt->out, opt->len);
    } else {
        print_hex(data, opt->len, opt->addr);
    }
    free(data);
    return 0;
}

static int request_and_print(kline_ctx *ctx, const uint8_t *req, size_t req_len,
                             const char *label)
{
    uint8_t resp[256];
    size_t resp_len = 0;
    char err[256];
    size_t i;

    if (kline_request(ctx, req, req_len, resp, sizeof(resp),
                      &resp_len, err, sizeof(err)) != 0) {
        fprintf(stderr, "%s: %s\n", label, err);
        return -1;
    }
    printf("%-10s", label);
    for (i = 0; i < resp_len; ++i) {
        printf(" %02X", resp[i]);
    }
    printf("  |");
    for (i = 0; i < resp_len; ++i) {
        printf("%c", resp[i] >= 32 && resp[i] < 127 ? resp[i] : '.');
    }
    printf("|\n");
    return 0;
}

static int cmd_ids(const options *opt)
{
    serial_port *port = NULL;
    kline_ctx ctx;
    char err[256];
    uint8_t cal[10];
    uint8_t req[2];

    if (connect_ecu(opt, &port, &ctx, err, sizeof(err)) != 0) {
        fprintf(stderr, "connect: %s\n", err);
        return 1;
    }
    req[0] = 0x21; req[1] = 0x03;
    request_and_print(&ctx, req, 2, "21 03");
    req[0] = 0x21; req[1] = 0x04;
    request_and_print(&ctx, req, 2, "21 04");
    req[0] = 0x21; req[1] = 0xFF;
    request_and_print(&ctx, req, 2, "21 FF");
    if (kline_read_memory(&ctx, 0xC05000, cal, sizeof(cal), err, sizeof(err)) == 0) {
        printf("%-10s ", "CALIBVER");
        fwrite(cal, 1, sizeof(cal), stdout);
        printf("\n");
    } else {
        fprintf(stderr, "CALIBVER: %s\n", err);
    }
    serial_close(port);
    return 0;
}

static int cmd_write_cal(const options *opt)
{
    serial_port *port = NULL;
    kline_ctx ctx;
    char err[256];
    uint8_t *input;
    uint8_t *block;
    uint8_t *verify;
    size_t input_size = 0;
    size_t offset;
    uint16_t sum;

    if (!opt->file) {
        fprintf(stderr, "write-cal needs --file\n");
        return 1;
    }
    if (!opt->i_understand) {
        fprintf(stderr,
            "refusing to write: this is experimental and can brick the ECU.\n"
            "Re-run with --i-understand only after reading ecu_tool/README.md.\n");
        return 1;
    }
    input = read_file(opt->file, &input_size);
    if (!input) {
        return 1;
    }
    if (input_size != FLASH_SIZE && input_size != CAL_SIZE) {
        fprintf(stderr, "file must be 0x40000 (full image) or 0x6000 (calibration block)\n");
        free(input);
        return 1;
    }
    block = (uint8_t *)malloc(CAL_SIZE);
    verify = (uint8_t *)malloc(CAL_SIZE);
    if (!block || !verify) {
        fprintf(stderr, "out of memory\n");
        free(input); free(block); free(verify);
        return 1;
    }
    memcpy(block, input + (input_size == FLASH_SIZE ? CAL_OFFSET : 0), CAL_SIZE);
    sum = checksum16_be(block, CAL_CHECKSUM_OFFSET);
    block[CAL_CHECKSUM_OFFSET] = (uint8_t)(sum & 0xFF);
    block[CAL_CHECKSUM_OFFSET + 1] = (uint8_t)(sum >> 8);
    free(input);
    printf("calibration checksum: 0x%04X\n", sum);

    if (connect_ecu(opt, &port, &ctx, err, sizeof(err)) != 0) {
        fprintf(stderr, "connect: %s\n", err);
        free(block); free(verify);
        return 1;
    }
    if (kline_security_unlock(&ctx, err, sizeof(err)) != 0 ||
        kline_request_download(&ctx, err, sizeof(err)) != 0) {
        fprintf(stderr, "programming session: %s\n", err);
        serial_close(port);
        free(block); free(verify);
        return 1;
    }
    for (offset = 0; offset < CAL_SIZE; offset += 0x80) {
        fprintf(stderr, "\rwriting 0x%06X / 0x%06X",
                (unsigned)(FLASH_BASE + CAL_OFFSET + offset),
                (unsigned)(FLASH_BASE + CAL_OFFSET + CAL_SIZE));
        fflush(stderr);
        if (kline_transfer_block(&ctx, FLASH_BASE + CAL_OFFSET + (uint32_t)offset,
                                 block + offset, err, sizeof(err)) != 0) {
            fprintf(stderr, "\nwrite failed at 0x%06X: %s\n",
                    (unsigned)(FLASH_BASE + CAL_OFFSET + offset), err);
            serial_close(port);
            free(block); free(verify);
            return 1;
        }
    }
    fprintf(stderr, "\n");
    if (kline_read_memory(&ctx, FLASH_BASE + CAL_OFFSET, verify, CAL_SIZE,
                          err, sizeof(err)) != 0) {
        fprintf(stderr, "readback failed: %s\n", err);
        serial_close(port);
        free(block); free(verify);
        return 1;
    }
    serial_close(port);
    if (memcmp(block, verify, CAL_SIZE) != 0) {
        size_t i;
        for (i = 0; i < CAL_SIZE; ++i) {
            if (block[i] != verify[i]) {
                fprintf(stderr, "verify mismatch at 0x%06X: wrote 0x%02X read 0x%02X\n",
                        (unsigned)(FLASH_BASE + CAL_OFFSET + i), block[i], verify[i]);
                break;
            }
        }
        free(block); free(verify);
        return 2;
    }
    printf("calibration write verified\n");
    free(block); free(verify);
    return 0;
}

static int cmd_selftest(void)
{
    if (checksum_selftest() != 0) {
        fprintf(stderr, "checksum selftest failed\n");
        return 1;
    }
    if (live_selftest() != 0) {
        fprintf(stderr, "live parser selftest failed\n");
        return 1;
    }
    printf("selftest passed\n");
    return 0;
}

int main(int argc, char **argv)
{
    options opt;

    if (parse_options(argc, argv, &opt) != 0) {
        usage(argv[0]);
        return 1;
    }
    if (!strcmp(opt.command, "help")) {
        usage(argv[0]);
        return 0;
    }
    if (!strcmp(opt.command, "live")) {
        return cmd_live(&opt);
    }
    if (!strcmp(opt.command, "dump")) {
        return cmd_dump(&opt);
    }
    if (!strcmp(opt.command, "read")) {
        return cmd_read(&opt);
    }
    if (!strcmp(opt.command, "ids")) {
        return cmd_ids(&opt);
    }
    if (!strcmp(opt.command, "write-cal")) {
        return cmd_write_cal(&opt);
    }
    if (!strcmp(opt.command, "selftest")) {
        return cmd_selftest();
    }
    fprintf(stderr, "unknown command: %s\n", opt.command);
    usage(argv[0]);
    return 1;
}
