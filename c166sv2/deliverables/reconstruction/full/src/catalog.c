#include "mt05/catalog.h"

#include <string.h>

const mt05_function_t *mt05_function_at(uint32_t address)
{
    for (size_t i = 0; i < mt05_function_count; ++i) {
        if (mt05_functions[i].address == address) {
            return &mt05_functions[i];
        }
    }
    return NULL;
}

const mt05_function_t *mt05_function_by_name(const char *name)
{
    if (name == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < mt05_function_count; ++i) {
        if (strcmp(mt05_functions[i].name, name) == 0) {
            return &mt05_functions[i];
        }
    }
    return NULL;
}

const mt05_variable_t *mt05_variable_at(uint32_t address)
{
    for (size_t i = 0; i < mt05_variable_count; ++i) {
        if (mt05_variables[i].address == address) {
            return &mt05_variables[i];
        }
    }
    return NULL;
}

const mt05_structure_t *mt05_structure_by_name(const char *name)
{
    if (name == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < mt05_structure_count; ++i) {
        if (strcmp(mt05_structures[i].name, name) == 0) {
            return &mt05_structures[i];
        }
    }
    return NULL;
}
