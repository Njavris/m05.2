#!/usr/bin/env python3
"""Write the evidence-based post-195 function and symbol tables.

Reads firmware/AUTO_NAMES.csv and firmware/AUTO_VARIABLES.csv and writes the
generated C views into reconstruction/03-data/. Run after
build_reconstruction.py because that script recreates the reconstruction tree.
"""
import csv
import os

ROOT = os.path.normpath(os.path.join(os.path.dirname(__file__), "..", "..", "..", ".."))
FW = os.path.join(ROOT, "c166", "deliverables", "firmware")
OUT = os.path.join(ROOT, "c166", "deliverables", "reconstruction", "03-data")
AUTO_NAMES = os.path.join(FW, "AUTO_NAMES.csv")
AUTO_VARS = os.path.join(FW, "AUTO_VARIABLES.csv")



def cstr(value):
    if value is None:
        value = ""
    return '"' + value.replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n") + '"'


def read_rows(path, fields):
    if not os.path.exists(path):
        return []
    with open(path, newline="") as f:
        return [{k: row.get(k, "") for k in fields} for row in csv.DictReader(f)]


def write_functions():
    rows = read_rows(AUTO_NAMES, ["address", "old_name", "auto_name", "size",
                                  "evidence", "confidence"])
    h = '''#ifndef MT05_AUTO_FUNCTIONS_H
#define MT05_AUTO_FUNCTIONS_H

#include "c166.h"
#include <stddef.h>

/*
 * Evidence-based auto-named functions recovered after the curated 195-function
 * map. Names are mechanical or role-derived; see AUTO_NAMES.csv and
 * ../../docs/16-auto-naming.md for evidence and confidence.
 *
 * This table is separate from mt05_functions[] because these functions do not
 * yet have a reviewed semantic description. It is documentation, not a claim
 * that every entry is a real function: some low-confidence gap blocks may be
 * switch tables or data that decoded as C166 instructions.
 */
typedef struct {
    u32 address;
    const char *old_name;
    const char *name;
    u16 size;
    const char *evidence;
    const char *confidence;
} mt05_auto_function_t;

extern const mt05_auto_function_t mt05_auto_functions[];
extern const size_t mt05_auto_function_count;

#endif
'''
    with open(os.path.join(OUT, "auto_functions.h"), "w") as f:
        f.write(h)
    with open(os.path.join(OUT, "auto_functions.c"), "w") as f:
        f.write('#include "auto_functions.h"\n\n')
        f.write("const mt05_auto_function_t mt05_auto_functions[] = {\n")
        for r in rows:
            f.write('    { 0x%s, %s, %s, %s, %s, %s },\n' % (
                r["address"].upper(), cstr(r["old_name"]), cstr(r["auto_name"]),
                r["size"], cstr(r["evidence"]), cstr(r["confidence"])))
        f.write("};\n")
        f.write("const size_t mt05_auto_function_count = "
                "sizeof(mt05_auto_functions) / sizeof(mt05_auto_functions[0]);\n")


def write_symbols():
    rows = read_rows(AUTO_VARS, ["address", "name", "type", "kind", "width",
                                 "evidence", "confidence"])
    h = '''#ifndef MT05_AUTO_SYMBOLS_H
#define MT05_AUTO_SYMBOLS_H

#include "c166.h"
#include <stddef.h>

/*
 * Evidence-based variables/calibration objects named after the whole-image
 * pass. This is separate from the curated variable table in SEMANTIC_INDEX.csv.
 * "kind" is ram, xram, external, table, or calibration. Width is bytes where
 * known; logical structures are documented in firmware_types.h.
 */
typedef struct {
    u32 address;
    const char *name;
    const char *type;
    const char *kind;
    u16 width;
    const char *evidence;
    const char *confidence;
} mt05_auto_symbol_t;

extern const mt05_auto_symbol_t mt05_auto_symbols[];
extern const size_t mt05_auto_symbol_count;

#endif
'''
    with open(os.path.join(OUT, "auto_symbols.h"), "w") as f:
        f.write(h)
    with open(os.path.join(OUT, "auto_symbols.c"), "w") as f:
        f.write('#include "auto_symbols.h"\n\n')
        f.write("const mt05_auto_symbol_t mt05_auto_symbols[] = {\n")
        for r in rows:
            f.write('    { 0x%s, %s, %s, %s, %s, %s, %s },\n' % (
                r["address"].upper(), cstr(r["name"]), cstr(r["type"]),
                cstr(r["kind"]), r["width"], cstr(r["evidence"]),
                cstr(r["confidence"])))
        f.write("};\n")
        f.write("const size_t mt05_auto_symbol_count = "
                "sizeof(mt05_auto_symbols) / sizeof(mt05_auto_symbols[0]);\n")



def write_init_table():
    rows = read_rows(os.path.join(FW, "APP_INIT_TABLE.csv"),
                     ["dest", "source", "length", "initial_hex",
                      "initial_value", "name", "evidence", "confidence"])
    h = """#ifndef MT05_APP_INIT_TABLE_H
#define MT05_APP_INIT_TABLE_H

#include "c166.h"
#include <stddef.h>

/* Type-6 records from the application init table at 0xC0BB56. */
typedef struct {
    u16 dest;
    u16 source;
    u16 length;
    u16 initial_value;
    const char *name;
    const char *evidence;
    const char *confidence;
} mt05_app_init_copy_t;

extern const mt05_app_init_copy_t mt05_app_init_copies[];
extern const size_t mt05_app_init_copy_count;

#endif
"""
    with open(os.path.join(OUT, "app_init_table.h"), "w") as f:
        f.write(h)
    with open(os.path.join(OUT, "app_init_table.c"), "w") as f:
        f.write('#include "app_init_table.h"\n\n')
        f.write("const mt05_app_init_copy_t mt05_app_init_copies[] = {\n")
        for r in rows:
            f.write('    { 0x%s, 0x%s, %s, %s, %s, %s, %s },\n' % (
                r["dest"], r["source"], r["length"], r["initial_value"],
                cstr(r["name"]), cstr(r["evidence"]), cstr(r["confidence"])))
        f.write("};\n")
        f.write("const size_t mt05_app_init_copy_count = "
                "sizeof(mt05_app_init_copies) / sizeof(mt05_app_init_copies[0]);\n")

def patch_data_header():
    path = os.path.join(OUT, "data.h")
    if not os.path.exists(path):
        return
    text = open(path).read()
    for inc in ('#include "auto_functions.h"', '#include "auto_symbols.h"',
                '#include "app_init_table.h"'):
        if inc not in text:
            text = text.replace('#include "c166.h"', '#include "c166.h"\n' + inc, 1)
    open(path, "w").write(text)


def append_data_readme():
    path = os.path.join(OUT, "README.md")
    if not os.path.exists(path):
        return
    text = open(path).read()
    if "auto_functions.c" in text:
        return
    text += """

## Auto-named post-195 recovery

`auto_functions.c` / `.h` contain `mt05_auto_functions[]`, the evidence-based
names for the post-195 functions (`../../firmware/AUTO_NAMES.csv`).
`auto_symbols.c` / `.h` contain the corresponding new variables and calibration
objects (`../../firmware/AUTO_VARIABLES.csv`). `app_init_table.c` / `.h`
contain the nine type-6 copies from the application init table at `0xC0BB56`
(`../../firmware/APP_INIT_TABLE.csv`). Methodology and confidence rules are in
`../../docs/16-auto-naming.md`.
"""
    open(path, "w").write(text)


def main():
    os.makedirs(OUT, exist_ok=True)
    write_functions()
    write_symbols()
    write_init_table()
    patch_data_header()
    append_data_readme()
    print("wrote auto_functions.{c,h}, auto_symbols.{c,h}, app_init_table.{c,h}")


if __name__ == "__main__":
    raise SystemExit(main())
