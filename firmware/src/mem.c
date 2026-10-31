#include "mem.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static u8 *g_space;

static int ensure_space(void)
{
    if (g_space == NULL) {
        g_space = (u8 *)calloc(C166_SPACE_SIZE, 1);
    }
    return g_space != NULL;
}

u8 *mem_space(void)
{
    if (!ensure_space()) {
        return NULL;
    }
    return g_space;
}

int mem_load_dump(const char *path)
{
    FILE *fp;
    long size;
    size_t got;

    if (!ensure_space()) {
        return -1;
    }

    fp = fopen(path, "rb");
    if (fp == NULL) {
        fprintf(stderr, "cannot open dump: %s\n", path);
        return -1;
    }
    if (fseek(fp, 0, SEEK_END) != 0) {
        fclose(fp);
        return -1;
    }
    size = ftell(fp);
    if (size != (long)C166_FLASH_SIZE) {
        fprintf(stderr, "dump size is %ld, expected %u\n",
                size, (unsigned)C166_FLASH_SIZE);
        fclose(fp);
        return -1;
    }
    if (fseek(fp, 0, SEEK_SET) != 0) {
        fclose(fp);
        return -1;
    }
    got = fread(g_space + C166_FLASH_BASE, 1, C166_FLASH_SIZE, fp);
    fclose(fp);
    if (got != C166_FLASH_SIZE) {
        fprintf(stderr, "short read: %zu of %u bytes\n",
                got, (unsigned)C166_FLASH_SIZE);
        return -1;
    }
    return 0;
}

u8 mem_read8(u32 addr)
{
    if (!ensure_space()) {
        return 0;
    }
    if (addr >= C166_SPACE_SIZE) {
        return 0;
    }
    return g_space[addr];
}

u16 mem_read16(u32 addr)
{
    return (u16)((u16)mem_read8(addr) | ((u16)mem_read8(addr + 1) << 8));
}

u32 mem_read32(u32 addr)
{
    return (u32)mem_read8(addr) |
           ((u32)mem_read8(addr + 1) << 8) |
           ((u32)mem_read8(addr + 2) << 16) |
           ((u32)mem_read8(addr + 3) << 24);
}

void mem_write8(u32 addr, u8 value)
{
    if (!ensure_space()) {
        return;
    }
    if (addr < C166_SPACE_SIZE) {
        g_space[addr] = value;
    }
}

void mem_write16(u32 addr, u16 value)
{
    mem_write8(addr, (u8)(value & 0xFFu));
    mem_write8(addr + 1, (u8)(value >> 8));
}

void mem_write32(u32 addr, u32 value)
{
    mem_write8(addr, (u8)(value & 0xFFu));
    mem_write8(addr + 1, (u8)((value >> 8) & 0xFFu));
    mem_write8(addr + 2, (u8)((value >> 16) & 0xFFu));
    mem_write8(addr + 3, (u8)((value >> 24) & 0xFFu));
}

int mem_read_block(u32 addr, u8 *dst, u32 len)
{
    u32 i;
    for (i = 0; i < len; ++i) {
        if (addr + i >= C166_SPACE_SIZE) {
            return -1;
        }
        dst[i] = mem_read8(addr + i);
    }
    return 0;
}

int mem_write_block(u32 addr, const u8 *src, u32 len)
{
    u32 i;
    for (i = 0; i < len; ++i) {
        if (addr + i >= C166_SPACE_SIZE) {
            return -1;
        }
        mem_write8(addr + i, src[i]);
    }
    return 0;
}

int mem_range_ok(u32 addr, u32 len)
{
    if (addr >= C166_SPACE_SIZE) {
        return 0;
    }
    if (len > (C166_SPACE_SIZE - addr)) {
        return 0;
    }
    return 1;
}
