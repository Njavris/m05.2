#ifndef MT05_CATALOG_H
#define MT05_CATALOG_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t address;
    const char *name;
    const char *category;
    const char *area;
    uint16_t size;
    const char *confidence;
    const char *evidence;
    const char *tables;
    const char *variables;
    const char *reference_c;
} mt05_function_t;

typedef struct {
    uint32_t address;
    const char *name;
    const char *category;
    const char *kind;
    uint16_t width;
    const char *confidence;
    const char *evidence;
    const char *hud_uid;
    const char *hud_name;
} mt05_variable_t;

typedef struct {
    const char *name;
    const char *category;
    uint16_t fields;
    const char *confidence;
    const char *evidence;
} mt05_structure_t;

extern const mt05_function_t mt05_functions[];
extern const size_t mt05_function_count;
extern const mt05_variable_t mt05_variables[];
extern const size_t mt05_variable_count;
extern const mt05_structure_t mt05_structures[];
extern const size_t mt05_structure_count;

const mt05_function_t *mt05_function_at(uint32_t address);
const mt05_function_t *mt05_function_by_name(const char *name);
const mt05_variable_t *mt05_variable_at(uint32_t address);
const mt05_structure_t *mt05_structure_by_name(const char *name);

#endif
