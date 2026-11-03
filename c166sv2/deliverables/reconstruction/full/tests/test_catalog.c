#include "mt05/catalog.h"
#include "mt05/live_data.h"

#include <stdio.h>
#include <string.h>

static int failures;

#define CHECK(cond, msg) do { \
    if (!(cond)) { fprintf(stderr, "FAIL: %s\n", msg); ++failures; } \
} while (0)

int main(void)
{
    CHECK(mt05_function_count == 902, "function count");
    CHECK(mt05_variable_count == 491, "variable count");
    CHECK(mt05_structure_count == 34, "structure count");
    CHECK(mt05_hud_command_count == 6, "HUD command count");
    CHECK(mt05_live_field_count == 60, "HUD field count");
    CHECK(mt05_live_bit_count == 40, "HUD status bit count");
    CHECK(mt05_slew_count == 13, "HUD slew count");

    const mt05_function_t *f = mt05_function_at(0xC1DA6Eu);
    CHECK(f != NULL, "calc_map_70f6 lookup");
    CHECK(f != NULL && strcmp(f->name, "calc_map_70f6") == 0, "calc_map_70f6 name");

    const mt05_function_t *boot = mt05_function_at(0xC00200u);
    CHECK(boot != NULL && strcmp(boot->name, "boot_main") == 0, "boot_main name");

    const mt05_variable_t *v = mt05_variable_at(0x00C9D0u);
    CHECK(v != NULL, "engine speed variable lookup");

    const mt05_structure_t *s = mt05_structure_by_name("diag_status_t");
    CHECK(s != NULL, "diag_status_t structure");

    const mt05_live_field_t *l = mt05_live_field_by_uid("VRPM");
    CHECK(l != NULL && l->offset == 0x58u, "VRPM live field");
    CHECK(l != NULL && l->bytes == 2u, "VRPM field size");

    const mt05_live_bit_t *b = mt05_live_bit_by_uid("B_FUELCOFF");
    CHECK(b != NULL && b->offset == 0x37u && b->bit == 0u, "fuel cutoff bit");
    CHECK(b != NULL && strcmp(b->firmware_alias, "diag_flag_c9f0") == 0, "fuel cutoff alias");

    size_t high = 0, medium = 0, low = 0;
    for (size_t i = 0; i < mt05_function_count; ++i) {
        CHECK(mt05_functions[i].name[0] != '\0', "function has name");
        CHECK(mt05_functions[i].confidence[0] != '\0', "function has confidence");
        CHECK(mt05_functions[i].evidence[0] != '\0', "function has evidence");
        if (strcmp(mt05_functions[i].confidence, "high") == 0) ++high;
        else if (strcmp(mt05_functions[i].confidence, "medium") == 0) ++medium;
        else ++low;
        for (size_t j = i + 1; j < mt05_function_count; ++j) {
            CHECK(strcmp(mt05_functions[i].name, mt05_functions[j].name) != 0,
                  "function names are unique");
        }
    }
    CHECK(high == 220 && medium == 340 && low == 342, "confidence distribution");

    if (failures != 0) {
        fprintf(stderr, "%d test(s) failed\n", failures);
        return 1;
    }
    printf("catalog tests passed: %zu functions, %zu variables, %zu structures, %zu HUD fields\n",
           mt05_function_count, mt05_variable_count, mt05_structure_count,
           mt05_live_field_count);
    return 0;
}
