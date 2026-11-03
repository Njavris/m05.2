#include "adaptation.h"
#include "boot.h"
#include "calibration.h"
#include "checksum.h"
#include "kwp.h"
#include "mem.h"
#include "vectors.h"

#include <stdio.h>
#include <string.h>

static int g_failures;

static void check(int condition, const char *message)
{
    if (condition) {
        printf("  ok   %s\n", message);
    } else {
        printf("  FAIL %s\n", message);
        g_failures++;
    }
}

static void print_hex(const u8 *data, int len)
{
    int i;
    for (i = 0; i < len; ++i) {
        printf("%02X", data[i]);
        if (i + 1 < len) {
            putchar(' ');
        }
    }
}

static void kwp_set_request(kwp_ctx_t *ctx, const u8 *req, int len)
{
    ctx->req_len = len;
    memcpy(ctx->req, req, (size_t)len);
}

static void print_active_vectors(void)
{
    vector_t vectors[128];
    int count = vector_decode_all(vectors, 128);
    int i;

    printf("\nActive vectors:\n");
    for (i = 0; i < count; ++i) {
        if (vectors[i].active) {
            printf("  0x%06X  %-12s -> 0x%06X\n",
                   vectors[i].address,
                   vectors[i].source,
                   vectors[i].target);
        }
    }
}

static void print_map(void)
{
    int row;
    int col;

    printf("\nCalibration 2D map at 0xC0794A (raw cell / scaled value):\n");
    for (row = 0; row < 9; ++row) {
        printf("  row %d: ", row);
        for (col = 0; col < 9; ++col) {
            u8 raw = mem_read8(0xC0794Au + 3u + (u32)(row * 9 + col));
            u16 scaled = tbl2d_interp(0xC0794Au,
                                      (u16)(col * 256),
                                      (u16)(row * 256));
            printf("%02X/%04X", raw, scaled);
            if (col != 8) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

static void print_calibration_curves(void)
{
    int i;

    printf("\n8-bit correction curve at 0xC079B6 (byte value):\n  ");
    for (i = 0; i < 17; ++i) {
        printf("%02X ", tbl8_interp(0xC079B6u, (u16)(i * 256)) >> 8);
    }
    printf("\n");

    printf("\n16-bit table at 0xC07912 (first 10 points):\n  ");
    for (i = 0; i < 10; ++i) {
        printf("%04X ", tbl16_interp(0xC07912u, (u16)(i * 256)));
    }
    printf("\n");
}

static void print_adaptation(void)
{
    adapt_record_t records[ADAPT_MAX_RECORDS];
    int count = adaptation_scan(records, ADAPT_MAX_RECORDS);
    int i;

    printf("\nAdaptation records:\n");
    for (i = 0; i < count; ++i) {
        printf("  0x%06X  seq=0x%04X  tail=0x%04X  signature=%s\n",
               records[i].offset,
               records[i].sequence,
               records[i].tail,
               records[i].has_signature ? "yes" : "no");
    }
}

static int run_tests(const char *dump_path)
{
    vector_t vectors[128];
    kwp_ctx_t ctx;
    kwp_ctx_t frame_ctx;
    u8 req[1 + 3 + 0x80];
    u8 frame[300];
    u8 payload[2];
    adapt_record_t records[ADAPT_MAX_RECORDS];
    int i;
    int count;
    int active = 0;
    int len;
    u16 got;
    u16 expected;
    axis16_t axis = { 9, 0, 10000 };

    g_failures = 0;

    printf("Loading %s\n", dump_path);
    if (mem_load_dump(dump_path) != 0) {
        printf("FAIL: cannot load dump\n");
        return 1;
    }

    printf("\n[checksums]\n");
    check(checksum16_be(0xC00000u, 0xC01FFEu) == 0xEE88u,
          "boot checksum = 0xEE88");
    check(checksum16_be(0xC05000u, 0xC0AFFEu) == 0x8D79u,
          "calibration checksum = 0x8D79");
    check(checksum16_be(0xC0B000u, 0xC3FFFCu) == 0x25C2u,
          "application checksum = 0x25C2");
    check(mem_read16(0xC01FFEu) == 0xEE88u, "stored boot checksum");
    check(mem_read16(0xC0AFFEu) == 0x8D79u, "stored calibration checksum");
    check(mem_read16(0xC3FFFEu) == 0x25C2u, "stored application checksum");

    printf("\n[boot]\n");
    check(boot_validate() == BOOT_APP, "boot validation selects application");
    check(boot_select_mode(0, 0, 0, 0, 0) == BOOT_APP,
          "ADC all-low selects application");
    check(boot_select_mode(0x3FF, 0x3FF, 0, 0, 0) == BOOT_MINIMAL,
          "ADC pattern selects minimal mode");
    check(boot_select_mode(0, 0, 0x3FF, 0, 0x3FF) == BOOT_BOOTLOADER,
          "ADC pattern selects bootloader");

    {
        u16 saved_boot = mem_read16(0xC01FFEu);
        u16 saved_app = mem_read16(0xC3FFFEu);
        u16 saved_magic = mem_read16(0xC3FFFCu);

        mem_write16(0xC01FFEu, (u16)(saved_boot ^ 0xFFFFu));
        check(boot_validate() == BOOT_BOOTLOADER,
              "corrupt boot checksum selects bootloader");
        mem_write16(0xC01FFEu, saved_boot);

        mem_write16(0xC3FFFEu, (u16)(saved_app ^ 0xFFFFu));
        check(boot_validate() == BOOT_BOOTLOADER,
              "corrupt application checksum selects bootloader");
        mem_write16(0xC3FFFEu, saved_app);

        mem_write16(0xC3FFFCu, 0xAA00u);
        mem_write16(0xC01FFEu, (u16)(saved_boot ^ 0xFFFFu));
        check(boot_validate() == BOOT_APP,
              "magic 0xAA00 skips checksum validation");
        mem_write16(0xC01FFEu, saved_boot);
        mem_write16(0xC3FFFCu, saved_magic);
    }

    printf("\n[vector table]\n");
    count = vector_decode_all(vectors, 128);
    check(count == 128, "vector table has 128 slots");
    for (i = 0; i < count; ++i) {
        if (vectors[i].active) {
            active++;
        }
    }
    check(active == 8, "exactly eight active vectors");
    check(vectors[0].target == 0xC00A78u, "reset vector -> 0xC00A78");
    for (i = 0; i < count; ++i) {
        if (vectors[i].address == 0xC00150u) {
            check(vectors[i].target == 0xC00694u,
                  "CAN0 vector -> 0xC00694");
        }
    }

    printf("\n[KWP2000]\n");
    kwp_ctx_init(&ctx);

    kwp_set_request(&ctx, (const u8[]){ 0x27, 0x01 }, 2);
    kwp_dispatch(&ctx);
    check(ctx.resp_len == 4 &&
          ctx.resp[0] == 0x67 && ctx.resp[1] == 0x01 &&
          ctx.resp[2] == 0x12 && ctx.resp[3] == 0x34,
          "security seed = 67 01 12 34");
    check(!ctx.security_unlocked, "security starts locked");

    kwp_set_request(&ctx, (const u8[]){ 0x27, 0x02, 0x00, 0x00 }, 4);
    kwp_dispatch(&ctx);
    check(ctx.resp_len == 3 &&
          ctx.resp[0] == 0x7F && ctx.resp[1] == 0x27 && ctx.resp[2] == 0x35,
          "wrong key -> 7F 27 35");
    check(!ctx.security_unlocked, "wrong key does not unlock");

    kwp_set_request(&ctx, (const u8[]){ 0x27, 0x02, 0x84, 0x74 }, 4);
    kwp_dispatch(&ctx);
    check(ctx.resp_len == 3 &&
          ctx.resp[0] == 0x67 && ctx.resp[1] == 0x02 && ctx.resp[2] == 0x34,
          "correct key -> 67 02 34");
    check(ctx.security_unlocked, "correct key unlocks security");

    kwp_set_request(&ctx, (const u8[]){ 0x10, 0x81 }, 2);
    kwp_dispatch(&ctx);
    check(ctx.resp_len == 2 && ctx.resp[0] == 0x50 && ctx.resp[1] == 0x81,
          "session 0x81 -> 50 81");

    kwp_set_request(&ctx, (const u8[]){ 0x23, 0xC0, 0x50, 0x00, 0x10 }, 5);
    kwp_dispatch(&ctx);
    check(ctx.resp_len == 17 && ctx.resp[0] == 0x63 && ctx.resp[1] == 'D',
          "read 0xC05000 returns D000101...");

    memset(req, 0, sizeof(req));
    req[0] = 0x36;
    req[1] = 0x00;
    req[2] = 0xC1;
    req[3] = 0x00;
    for (i = 0; i < 0x80; ++i) {
        req[4 + i] = 0xAA;
    }
    kwp_set_request(&ctx, req, (int)sizeof(req));
    kwp_dispatch(&ctx);
    check(ctx.resp_len == 2 && ctx.resp[0] == 0x76,
          "transfer data -> 76 <checksum>");
    check(mem_read8(0x00C100u) == 0xAAu,
          "transfer data wrote external RAM");

    kwp_set_request(&ctx, (const u8[]){ 0x3D, 0x00, 0xC1, 0x10, 0x04,
                                        0x11, 0x22, 0x33, 0x44 }, 9);
    kwp_dispatch(&ctx);
    check(ctx.resp_len == 4 && ctx.resp[0] == 0x7D,
          "write memory -> 7D <address>");
    check(mem_read8(0x00C110u) == 0x11u, "write memory wrote external RAM");

    printf("\n[K-line frame]\n");
    payload[0] = 0x27;
    payload[1] = 0x01;
    frame[0] = 0x80;   /* format */
    frame[1] = 0x11;   /* ECU */
    frame[2] = 0xF1;   /* tester */
    frame[3] = 2;
    memcpy(frame + 4, payload, 2);
    frame[6] = 0;
    for (i = 0; i < 6; ++i) {
        frame[6] = (u8)(frame[6] + frame[i]);
    }
    kwp_ctx_init(&frame_ctx);
    check(kwp_parse_kline_frame(frame, 7, &frame_ctx) == 2,
          "parse K-line request");
    kwp_dispatch(&frame_ctx);
    len = kwp_build_kline_frame(&frame_ctx, frame, (int)sizeof(frame));
    check(len == 9, "build K-line response length");
    check(len == 9 && frame[0] == 0x80 && frame[1] == 0xF1 &&
          frame[2] == 0x11 && frame[3] == 4 &&
          frame[4] == 0x67 && frame[5] == 0x01 &&
          frame[6] == 0x12 && frame[7] == 0x34,
          "K-line seed response payload");

    printf("\n[calibration]\n");
    check(axis16_unsigned(&axis, 0) == 0, "axis value 0 -> index 0");
    check(axis16_unsigned(&axis, 5000) == 1024, "axis value 5000 -> 4.0");
    check(axis16_unsigned(&axis, 10000) == 2048, "axis max -> 8.0");
    check(tbl8_interp(0xC079B6u, 0) == 0xB400u,
          "8-bit curve point 0 = 0xB4");
    check(tbl8_interp(0xC079B6u, 16 * 256) == 0x8000u,
          "8-bit curve point 16 = 0x80");
    check(tbl16_interp(0xC07912u, 0) == 0x015Bu,
          "16-bit table point 0 = 0x015B");
    check(tbl2d_interp(0xC0794Au, 0, 0) == 0,
          "2D map cell 0,0 = 0");
    check((tbl2d_interp(0xC0794Au, 8 * 256, 8 * 256) >> 7) == 0xF2u,
          "2D map cell 8,8 = 0xF2");

    mem_write16(0x007000u, 9);
    mem_write16(0x007002u, 0);
    mem_write16(0x007004u, 10000);
    mem_write16(0x007006u, 9);
    mem_write16(0x007008u, 0);
    mem_write16(0x00700Au, 10000);

    got = calc_load(0x007000u, 0x007006u, 0xC0794Au, 0xC079B6u,
                    5000, 5000, 0);
    expected = (u16)14400u;
    check(got == expected, "calc_load(5000,5000,corr=0) = 14400");

    printf("\n[adaptation log]\n");
    count = adaptation_scan(records, ADAPT_MAX_RECORDS);
    check(count == 7, "seven adaptation records");
    check(records[3].offset == 0xC04600u &&
          records[3].sequence == 0x0448u &&
          records[3].tail == 0x2B03u &&
          records[3].has_signature,
          "record 0x4600: seq 0x0448, tail 0x2B03");
    check(records[6].offset == 0xC04C00u &&
          records[6].sequence == 0x0001u &&
          records[6].tail == 0x52ADu &&
          records[6].has_signature,
          "record 0x4C00: seq 0x0001, tail 0x52AD");

    printf("\n%s\n", g_failures == 0 ? "ALL TESTS PASSED" : "TESTS FAILED");
    return g_failures == 0 ? 0 : 1;
}

static int run_demo(const char *dump_path)
{
    kwp_ctx_t ctx;
    adapt_record_t records[ADAPT_MAX_RECORDS];
    int count;
    int i;
    u16 value;

    if (mem_load_dump(dump_path) != 0) {
        return 1;
    }

    printf("Delphi MT05.2 host model\n");
    printf("Dump: %s\n", dump_path);
    printf("Boot checksum: stored=0x%04X computed=0x%04X\n",
           mem_read16(0xC01FFEu), checksum16_be(0xC00000u, 0xC01FFEu));
    printf("Calibration checksum: stored=0x%04X computed=0x%04X\n",
           mem_read16(0xC0AFFEu), checksum16_be(0xC05000u, 0xC0AFFEu));
    printf("Application checksum: stored=0x%04X computed=0x%04X\n",
           mem_read16(0xC3FFFEu), checksum16_be(0xC0B000u, 0xC3FFFCu));
    printf("Boot decision: %s\n", boot_mode_name(boot_validate()));

    print_active_vectors();

    printf("\nKWP2000 demo:\n");
    kwp_ctx_init(&ctx);
    kwp_set_request(&ctx, (const u8[]){ 0x27, 0x01 }, 2);
    kwp_dispatch(&ctx);
    printf("  seed: ");
    print_hex(ctx.resp, ctx.resp_len);
    printf("\n");
    kwp_set_request(&ctx, (const u8[]){ 0x27, 0x02, 0x84, 0x74 }, 4);
    kwp_dispatch(&ctx);
    printf("  key:  ");
    print_hex(ctx.resp, ctx.resp_len);
    printf("  unlocked=%d\n", ctx.security_unlocked);

    kwp_set_request(&ctx, (const u8[]){ 0x23, 0xC0, 0x50, 0x00, 0x10 }, 5);
    kwp_dispatch(&ctx);
    printf("  read 0xC05000: ");
    print_hex(ctx.resp, ctx.resp_len);
    printf("\n");

    print_calibration_curves();
    print_map();

    printf("\nAxis demo with synthetic descriptor {count=9,min=0,max=10000}:\n");
    for (i = 0; i < 5; ++i) {
        u16 input = (u16)(i * 2500);
        axis16_t axis = { 9, 0, 10000 };
        printf("  input %5u -> index 0x%04X\n",
               input, axis16_unsigned(&axis, input));
    }

    mem_write16(0x007000u, 9);
    mem_write16(0x007002u, 0);
    mem_write16(0x007004u, 10000);
    mem_write16(0x007006u, 9);
    mem_write16(0x007008u, 0);
    mem_write16(0x00700Au, 10000);
    value = calc_load(0x007000u, 0x007006u, 0xC0794Au, 0xC079B6u,
                      5000, 5000, 0);
    printf("  calc_load(5000,5000,corr=0) = 0x%04X (%u)\n", value, value);

    print_adaptation();

    count = adaptation_scan(records, ADAPT_MAX_RECORDS);
    printf("\nTotal adaptation records: %d\n", count);
    return 0;
}

int main(int argc, char **argv)
{
    const char *dump_path = "../mash_dump.bin";

    if (argc >= 2 && strcmp(argv[1], "--test") == 0) {
        if (argc >= 3) {
            dump_path = argv[2];
        }
        return run_tests(dump_path);
    }
    if (argc >= 2) {
        dump_path = argv[1];
    }
    return run_demo(dump_path);
}
