#include "live.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned offset;
    unsigned bytes;
    int is_signed;
    double scale;
    const char *name;
    const char *unit;
} live_field_t;

static const live_field_t fields[] = {
    {0x58, 2, 0, 1.0 / 4.0, "Engine speed", "rpm"},
    {0x4E, 2, 0, 1.0 / 256.0, "MAP", "kPa"},
    {0x5A, 2, 0, 1.0 / 327.68, "Throttle", "%"},
    {0x44, 2, 1, 1.0 / 128.0, "Coolant", "degC"},
    {0x4A, 2, 1, 1.0 / 128.0, "Inlet air", "degC"},
    {0x4C, 2, 0, 1.0 / 2048.0, "Ignition", "V"},
    {0x56, 2, 0, 1.0 / 64.0, "O2 cyl 1", "mV"},
    {0x1A, 2, 0, 1.0 / 64.0, "Injector 1", "ms"},
    {0x35, 2, 0, 1.0 / 64.0, "Dwell", "ms"},
    {0x2F, 2, 1, 1.0 / 128.0, "Spark advance", "degCA"},
    {0x1E, 2, 0, 1.0 / 327.68, "Volume efficiency", "%"},
    {0x02, 2, 0, 1.0 / 2048.0, "AFR measured", ""},
    {0x25, 2, 0, 1.0 / 4.0, "Idle target", "rpm"},
    {0x3E, 2, 1, 1.0 / 128.0, "Vehicle speed", "km/h"},
    {0x18, 2, 0, 1.0 / 327.68, "Fuel pump duty", "%"},
    {0x40, 2, 0, 1.0 / 327.68, "Purge", "%"},
    {0x2D, 2, 0, 1.0, "Runtime", "s"},
};

static const char *status_names[5][8] = {
    {
        "Fuel Cut Off Enable", "Clear Flood Enable", "DFCO Met",
        "DFCO Enter", "DFCO Exit", "Speed Limiter",
        "Roll Over Enabled", "C/L Reset Cyl 2"
    },
    {
        "C/L Enabled Cyl 1", "Prime Pulse Disable", "Fuel Pump On",
        "Acc Enrich Enter", "Dec Enlean Enter", "Acc Enrich Exit",
        "Dec Enlean Exit", "C/L Enabled Cyl 2"
    },
    {
        "O2 Sensor Rich Cyl 1", "C/L Reset Cyl 1", "O2 Sensor Heater Enable",
        "O2 Sensor Ready Cyl 1", "IACV Correction on", "IACV Lost Step",
        "IACV Move Inhibit", "Ignition On"
    },
    {
        "MAP CID Enable", "MAP CID Succeed", "Idle Mode",
        "Power Enrichment Enable", "PE Protection Enable",
        "Clutch / Neutral Switch", "Diagnostic Mode", "MIL Fault Light on"
    },
    {
        "Airflow Correction Met", "Baro Update Met", "Seq. Spark Enable",
        "Spark Tip-In Enable", "Cat Light Off Enable", "Engine Running",
        "Stable Warm Idle", "O2 Sensor Ready Cyl 2"
    }
};

static unsigned read_u16(const uint8_t *data, unsigned offset)
{
    return ((unsigned)data[offset] << 8) | data[offset + 1];
}

static double field_value(const live_field_t *field, const uint8_t *data)
{
    unsigned raw = read_u16(data, field->offset);
    if (field->is_signed && field->bytes == 2 && raw >= 0x8000u) {
        return ((double)(int)(int16_t)raw) * field->scale;
    }
    return (double)raw * field->scale;
}

void live_print_header(int csv)
{
    size_t i;

    if (csv) {
        for (i = 0; i < sizeof(fields) / sizeof(fields[0]); ++i) {
            printf("%s%s", i ? "," : "", fields[i].name);
        }
        printf(",status37,status38,status39,status3A,status3B\n");
    }
}

void live_print(const uint8_t data[100], int csv)
{
    size_t i;

    if (csv) {
        for (i = 0; i < sizeof(fields) / sizeof(fields[0]); ++i) {
            printf("%s%.3f", i ? "," : "", field_value(&fields[i], data));
        }
        printf(",%02X,%02X,%02X,%02X,%02X\n",
               data[0x37], data[0x38], data[0x39], data[0x3A], data[0x3B]);
        return;
    }
    printf("rpm=%7.0f map=%5.1f tps=%5.1f clt=%5.1f iat=%5.1f "
           "bat=%5.2f o2=%6.0f ve=%5.1f inj=%5.2f dwell=%4.2f adv=%5.1f "
           "st=%02X%02X%02X%02X%02X\n",
           field_value(&fields[0], data), field_value(&fields[1], data),
           field_value(&fields[2], data), field_value(&fields[3], data),
           field_value(&fields[4], data), field_value(&fields[5], data),
           field_value(&fields[6], data), field_value(&fields[10], data),
           field_value(&fields[7], data), field_value(&fields[8], data),
           field_value(&fields[9], data), data[0x37], data[0x38],
           data[0x39], data[0x3A], data[0x3B]);
}

void live_print_status(const uint8_t data[100])
{
    int byte_index;
    int bit;

    for (byte_index = 0; byte_index < 5; ++byte_index) {
        unsigned value = data[0x37 + byte_index];
        printf("0x%02X = 0x%02X", 0x37 + byte_index, value);
        if (!value) {
            printf(" (none)");
        }
        printf("\n");
        for (bit = 0; bit < 8; ++bit) {
            if (value & (1u << bit)) {
                printf("  bit %d: %s\n", bit, status_names[byte_index][bit]);
            }
        }
    }
}

int live_selftest(void)
{
    uint8_t data[100];
    unsigned raw;

    memset(data, 0, sizeof(data));
    raw = (unsigned)(1801.0 * 4.0 + 0.5);
    data[0x58] = (uint8_t)(raw >> 8);
    data[0x59] = (uint8_t)raw;
    raw = (unsigned)(45.0 * 256.0 + 0.5);
    data[0x4E] = (uint8_t)(raw >> 8);
    data[0x4F] = (uint8_t)raw;
    data[0x37] = 0x8D;
    if (field_value(&fields[0], data) < 1800.0 ||
        field_value(&fields[0], data) > 1802.0) {
        return -1;
    }
    if (field_value(&fields[1], data) < 44.9 ||
        field_value(&fields[1], data) > 45.1) {
        return -1;
    }
    if (data[0x37] != 0x8D) {
        return -1;
    }
    return 0;
}
