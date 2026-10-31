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

typedef struct {
    const char *port;
    unsigned timeout_ms;
    int trace;
} options;

static serial_port *g_port;
static kline_ctx g_ctx;
static int g_trace;

static void clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H");
#endif
    fflush(stdout);
}

static int read_line(const char *prompt, char *buf, size_t len)
{
    size_t n;
    printf("%s", prompt);
    fflush(stdout);
    if (!fgets(buf, (int)len, stdin)) {
        return 0;
    }
    n = strlen(buf);
    while (n > 0 && (buf[n - 1] == '\n' || buf[n - 1] == '\r')) {
        buf[--n] = '\0';
    }
    return 1;
}

static uint32_t parse_u32(const char *text, uint32_t fallback)
{
    char *end = NULL;
    unsigned long value;
    if (!text || !*text) {
        return fallback;
    }
    errno = 0;
    value = strtoul(text, &end, 0);
    if (errno != 0 || !end || *end != '\0' || value > 0xFFFFFFFFul) {
        return fallback;
    }
    return (uint32_t)value;
}

static void show_error(const char *what, const char *err)
{
    printf("\n%s: %s\n", what, err);
    printf("Press Enter to continue...");
    fflush(stdout);
    (void)getchar();
}

static int request_show(const uint8_t *req, size_t req_len, const char *label)
{
    uint8_t resp[256];
    size_t resp_len = 0;
    char err[256];
    size_t i;

    if (kline_request(&g_ctx, req, req_len, resp, sizeof(resp),
                      &resp_len, err, sizeof(err)) != 0) {
        printf("%-12s %s\n", label, err);
        return -1;
    }
    printf("%-12s", label);
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

static void decode_dtc(uint8_t hi, uint8_t lo)
{
    static const char systems[] = "PCBU";
    int sys = (hi >> 6) & 3;
    int d1 = (hi >> 4) & 3;
    int d2 = hi & 0x0F;
    int d3 = (lo >> 4) & 0x0F;
    int d4 = lo & 0x0F;
    printf("  %c%d%X%X%X\n", systems[sys], d1, d2, d3, d4);
}

static void read_dtcs(int pending)
{
    uint8_t req[1];
    uint8_t resp[256];
    size_t resp_len = 0;
    char err[256];
    size_t i;

    req[0] = pending ? 0x07 : 0x03;
    if (kline_request(&g_ctx, req, 1, resp, sizeof(resp),
                      &resp_len, err, sizeof(err)) != 0) {
        show_error(pending ? "Read pending DTCs" : "Read DTCs", err);
        return;
    }
    printf("\nOBD response:");
    for (i = 0; i < resp_len; ++i) {
        printf(" %02X", resp[i]);
    }
    printf("\n");
    if (resp_len >= 2 && (resp[0] == 0x43 || resp[0] == 0x47)) {
        for (i = 1; i + 1 < resp_len; i += 2) {
            if (resp[i] == 0 && resp[i + 1] == 0) {
                continue;
            }
            decode_dtc(resp[i], resp[i + 1]);
        }
    } else if (resp_len >= 3 && resp[0] == 0x7F) {
        printf("ECU rejected the request (NRC 0x%02X).\n", resp[2]);
    }
    printf("Press Enter to continue...");
    fflush(stdout);
    (void)getchar();
}

static void clear_dtcs(void)
{
    uint8_t req[] = {0x04};
    uint8_t resp[32];
    size_t resp_len = 0;
    char err[256];
    char answer[16];

    if (!read_line("Clear DTCs? [y/N] ", answer, sizeof(answer)) ||
        (answer[0] != 'y' && answer[0] != 'Y')) {
        return;
    }
    if (kline_request(&g_ctx, req, 1, resp, sizeof(resp),
                      &resp_len, err, sizeof(err)) != 0) {
        show_error("Clear DTCs", err);
        return;
    }
    printf("Response:");
    for (size_t i = 0; i < resp_len; ++i) {
        printf(" %02X", resp[i]);
    }
    printf("\nPress Enter to continue...");
    fflush(stdout);
    (void)getchar();
}

static void ecu_info(void)
{
    uint8_t cal[10];
    char err[256];

    clear_screen();
    printf("ECU information\n===============\n");
    request_show((const uint8_t[]){0x21, 0x03}, 2, "21 03 HW");
    request_show((const uint8_t[]){0x21, 0x04}, 2, "21 04 SW");
    request_show((const uint8_t[]){0x21, 0xFF}, 2, "21 FF IGN");
    if (kline_read_memory(&g_ctx, 0xC05000, cal, sizeof(cal),
                          err, sizeof(err)) == 0) {
        printf("CALIBVER     ");
        for (size_t i = 0; i < sizeof(cal); ++i) {
            printf("%c", cal[i] >= 32 && cal[i] < 127 ? cal[i] : '.');
        }
        printf("\n");
    } else {
        printf("CALIBVER     %s\n", err);
    }
    printf("\nPress Enter to continue...");
    fflush(stdout);
    (void)getchar();
}

static void live_dashboard(void)
{
    char line[32];
    uint32_t count;
    uint32_t interval;
    uint8_t data[100];
    char err[256];
    uint32_t i;
    int failures = 0;

    if (!read_line("Samples [20]: ", line, sizeof(line))) {
        return;
    }
    count = parse_u32(line, 20);
    if (count == 0) {
        count = 20;
    }
    if (!read_line("Interval ms [250]: ", line, sizeof(line))) {
        return;
    }
    interval = parse_u32(line, 250);
    if (interval == 0) {
        interval = 250;
    }
    clear_screen();
    printf("Live data: %u samples, %u ms interval\n\n", count, interval);
    for (i = 0; i < count; ++i) {
        if (kline_read_live(&g_ctx, data, err, sizeof(err)) != 0) {
            printf("live: %s\n", err);
            if (++failures >= 3) {
                break;
            }
        } else {
            failures = 0;
            live_print(data, 0);
        }
        fflush(stdout);
        serial_sleep_ms(interval);
    }
    printf("\nPress Enter to continue...");
    fflush(stdout);
    (void)getchar();
}

static void service_reset(void)
{
    uint8_t req[] = {0x30, 0x8B, 0x00};
    uint8_t resp[32];
    size_t resp_len = 0;
    char err[256];
    char answer[16];

    clear_screen();
    printf("Service reset / EEPROM reset\n");
    printf("Command: 30 8B 00 (experimental)\n");
    if (!read_line("This may reset learned values. Continue? [y/N] ",
                   answer, sizeof(answer)) ||
        (answer[0] != 'y' && answer[0] != 'Y')) {
        return;
    }
    if (kline_request(&g_ctx, req, sizeof(req), resp, sizeof(resp),
                      &resp_len, err, sizeof(err)) != 0) {
        show_error("Service reset", err);
        return;
    }
    printf("Response:");
    for (size_t i = 0; i < resp_len; ++i) {
        printf(" %02X", resp[i]);
    }
    printf("\nPress Enter to continue...");
    fflush(stdout);
    (void)getchar();
}

static void read_memory(void)
{
    char line[64];
    uint32_t addr;
    uint32_t len;
    uint8_t *data;
    char err[256];
    size_t i;

    if (!read_line("Address (hex) [0xC05000]: ", line, sizeof(line))) {
        return;
    }
    addr = parse_u32(line, 0xC05000);
    if (!read_line("Length (decimal/hex) [16]: ", line, sizeof(line))) {
        return;
    }
    len = parse_u32(line, 16);
    if (len == 0) {
        len = 16;
    }
    data = (uint8_t *)malloc(len);
    if (!data) {
        printf("Out of memory.\n");
        return;
    }
    if (kline_read_memory(&g_ctx, addr, data, len, err, sizeof(err)) != 0) {
        free(data);
        show_error("Read memory", err);
        return;
    }
    printf("\n");
    for (i = 0; i < len; i += 16) {
        size_t j;
        printf("%06X: ", (unsigned)(addr + i));
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
            printf("%c", c >= 32 && c < 127 ? c : '.');
        }
        printf("\n");
    }
    free(data);
    printf("\nPress Enter to continue...");
    fflush(stdout);
    (void)getchar();
}

static void dump_flash(void)
{
    char line[256];
    char out[256] = "flash_dump.bin";
    uint8_t *image;
    size_t offset;
    char err[256];
    FILE *f;

    if (!read_line("Output file [flash_dump.bin]: ", line, sizeof(line))) {
        return;
    }
    if (line[0]) {
        snprintf(out, sizeof(out), "%s", line);
    }
    image = (uint8_t *)malloc(FLASH_SIZE);
    if (!image) {
        printf("Out of memory.\n");
        return;
    }
    clear_screen();
    printf("Dumping 256 KB flash to %s\n\n", out);
    for (offset = 0; offset < FLASH_SIZE; offset += 0x4000) {
        size_t chunk = FLASH_SIZE - offset;
        if (chunk > 0x4000) {
            chunk = 0x4000;
        }
        printf("\r0x%06X / 0x%06X",
               (unsigned)(FLASH_BASE + offset),
               (unsigned)(FLASH_BASE + FLASH_SIZE));
        fflush(stdout);
        if (kline_read_memory(&g_ctx, FLASH_BASE + (uint32_t)offset,
                              image + offset, chunk, err, sizeof(err)) != 0) {
            printf("\nDump failed: %s\n", err);
            free(image);
            printf("Press Enter to continue...");
            fflush(stdout);
            (void)getchar();
            return;
        }
    }
    printf("\n");
    f = fopen(out, "wb");
    if (!f) {
        printf("Cannot write %s: %s\n", out, strerror(errno));
        free(image);
        printf("Press Enter to continue...");
        fflush(stdout);
        (void)getchar();
        return;
    }
    if (fwrite(image, 1, FLASH_SIZE, f) != FLASH_SIZE) {
        printf("Short write.\n");
    }
    fclose(f);
    printf("Wrote %s\n", out);
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
        for (i = 0; i < sizeof(blocks) / sizeof(blocks[0]); ++i) {
            uint16_t computed = checksum16_be(image + blocks[i].start,
                                              blocks[i].length);
            uint16_t stored = (uint16_t)(image[blocks[i].stored] |
                                         (image[blocks[i].stored + 1] << 8));
            printf("%-12s 0x%04X / 0x%04X %s\n", blocks[i].name,
                   computed, stored, computed == stored ? "ok" : "MISMATCH");
        }
    }
    free(image);
    printf("\nPress Enter to continue...");
    fflush(stdout);
    (void)getchar();
}

static int parse_hex_payload(const char *text, uint8_t *out, size_t cap,
                             size_t *out_len)
{
    size_t count = 0;
    const char *p = text;
    while (*p && count < cap) {
        char *end = NULL;
        unsigned long value;
        while (*p == ' ' || *p == '\t' || *p == ',') {
            ++p;
        }
        if (!*p) {
            break;
        }
        value = strtoul(p, &end, 16);
        if (end == p || value > 0xFF) {
            return -1;
        }
        out[count++] = (uint8_t)value;
        p = end;
    }
    *out_len = count;
    return count ? 0 : -1;
}

static void manual_command(void)
{
    char line[512];
    uint8_t req[256];
    uint8_t resp[256];
    size_t req_len = 0;
    size_t resp_len = 0;
    char err[256];
    size_t i;

    if (!read_line("Payload hex (e.g. 21 01): ", line, sizeof(line))) {
        return;
    }
    if (parse_hex_payload(line, req, sizeof(req), &req_len) != 0) {
        printf("Invalid hex payload.\n");
        return;
    }
    clear_screen();
    printf("Payload:");
    for (i = 0; i < req_len; ++i) {
        printf(" %02X", req[i]);
    }
    printf("\n");
    if (kline_request(&g_ctx, req, req_len, resp, sizeof(resp),
                      &resp_len, err, sizeof(err)) != 0) {
        show_error("Command", err);
        return;
    }
    printf("Response:");
    for (i = 0; i < resp_len; ++i) {
        printf(" %02X", resp[i]);
    }
    printf("\nPress Enter to continue...");
    fflush(stdout);
    (void)getchar();
}

static void show_menu(void)
{
    printf("ECU diagnostic console\n");
    printf("======================\n");
    printf("Port: %s   Trace: %s\n\n", g_port ? "open" : "?",
           g_trace ? "on" : "off");
    printf("1. Live data dashboard\n");
    printf("2. ECU information\n");
    printf("3. Read DTCs (OBD mode 03)\n");
    printf("4. Read pending DTCs (OBD mode 07)\n");
    printf("5. Clear DTCs (OBD mode 04)\n");
    printf("6. Service reset (30 8B 00, experimental)\n");
    printf("7. Read memory\n");
    printf("8. Dump flash\n");
    printf("9. Manual KWP command\n");
    printf("T. Toggle frame trace\n");
    printf("0. Exit\n\n");
}

int main(int argc, char **argv)
{
    options opt;
    char line[256];
    int port_given = 0;

    memset(&opt, 0, sizeof(opt));
#ifdef _WIN32
    opt.port = "COM3";
#else
    opt.port = "/dev/ttyUSB0";
#endif
    opt.timeout_ms = 1000;
    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "--port") && i + 1 < argc) {
            opt.port = argv[++i];
            port_given = 1;
        } else if (!strcmp(argv[i], "--timeout") && i + 1 < argc) {
            opt.timeout_ms = parse_u32(argv[++i], 1000);
        } else if (!strcmp(argv[i], "--trace")) {
            opt.trace = 1;
        } else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            printf("Usage: %s [--port PATH] [--timeout MS] [--trace]\n", argv[0]);
            return 0;
        }
    }
    if (!port_given) {
        char portbuf[256];
        printf("ECU diagnostic console\nPort [%s]: ", opt.port);
        fflush(stdout);
        if (fgets(portbuf, sizeof(portbuf), stdin)) {
            size_t n = strlen(portbuf);
            while (n > 0 && (portbuf[n - 1] == '\n' || portbuf[n - 1] == '\r')) {
                portbuf[--n] = '\0';
            }
            if (portbuf[0]) {
                snprintf(line, sizeof(line), "%s", portbuf);
                opt.port = line;
            }
        }
    }
    g_port = serial_open(opt.port, 10400, line, sizeof(line));
    if (!g_port) {
        printf("Cannot open %s: %s\n", opt.port, line);
        return 1;
    }
    if (kline_connect(&g_ctx, g_port, opt.timeout_ms, opt.trace,
                      line, sizeof(line)) != 0) {
        printf("Connection failed: %s\n", line);
        serial_close(g_port);
        return 1;
    }
    g_trace = opt.trace;
    g_ctx.verbose = g_trace;
    for (;;) {
        clear_screen();
        show_menu();
        if (!read_line("Select: ", line, sizeof(line))) {
            break;
        }
        switch (line[0]) {
        case '1': live_dashboard(); break;
        case '2': ecu_info(); break;
        case '3': read_dtcs(0); break;
        case '4': read_dtcs(1); break;
        case '5': clear_dtcs(); break;
        case '6': service_reset(); break;
        case '7': read_memory(); break;
        case '8': dump_flash(); break;
        case '9': manual_command(); break;
        case 't': case 'T':
            g_trace = !g_trace;
            g_ctx.verbose = g_trace;
            break;
        case '0': goto done;
        default: break;
        }
    }
done:
    serial_close(g_port);
    g_port = NULL;
    return 0;
}
