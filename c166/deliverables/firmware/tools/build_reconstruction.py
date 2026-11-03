#!/usr/bin/env python3
"""Build the human navigation tree of semantic decompiled functions.

Output: <project>/reconstruction/
  README.md, INDEX.csv
  01-bootloader/        bootloader.c, bootloader.asm, README.md
  02-calibration/       calibration_tables.csv, README.md
  application/       application.c, application.asm, README.md
  04-adaptation-log/    eeprom_records.csv, dump_differences.csv, README.md
  99-shared/            constants.h, firmware_types.h, README.md

The C and ASM files are consolidated per firmware part, not one file per
function. They are Ghidra decompiler output, not compilable source.
"""
import csv
import os
import re
import shutil

ROOT = os.path.normpath(os.path.join(os.path.dirname(__file__), "..", "..", "..", ".."))
FW = os.path.join(ROOT, "c166", "deliverables", "firmware")
SHARED = os.path.join(ROOT, "c166sv2", "deliverables", "artifacts")
REF = os.path.join(FW, "reference")
OUT = os.path.join(ROOT, "c166", "deliverables", "reconstruction")
INDEX_CSV = os.path.join(FW, "SEMANTIC_INDEX.csv")
CAL_CSV = os.path.join(SHARED, "calibration_tables.csv")
TYPES_H = os.path.join(FW, "include", "firmware_types.h")
C166_H = os.path.join(FW, "include", "c166.h")
EEPROM_CSV = os.path.join(SHARED, "eeprom_records.csv")
DIFF_CSV = os.path.join(SHARED, "dump_differences.csv")

BOOT_AREA = "bootloader"
AREAS = [
    ("application/00-startup-runtime", "Startup / runtime",
     "Application startup, scheduler, command dispatch"),
    ("application/01-drivers/can", "Drivers / CAN",
     "TwinCAN driver and message objects"),
    ("application/01-drivers/kline-asc0", "Drivers / K-line ASC0",
     "ASC0/K-line UART driver"),
    ("application/01-drivers/ssc", "Drivers / SSC",
     "Synchronous serial frame engine"),
    ("application/01-drivers/timers", "Drivers / timers",
     "CAPCOM/timer time base"),
    ("application/01-drivers/adc", "Drivers / ADC",
     "ADC conversion/calibration"),
    ("application/01-drivers/io", "Drivers / IO",
     "Ports, input sampling, capture"),
    ("application/01-drivers/pwm", "Drivers / PWM",
     "PWM setup and calculation"),
    ("application/01-drivers/clock", "Drivers / clock",
     "Clock/PLL"),
    ("application/02-diagnostics/kwp", "Diagnostics / KWP2000",
     "KWP2000 services"),
    ("application/02-diagnostics/kline-transport", "Diagnostics / K-line transport",
     "K-line transport state machine"),
    ("application/02-diagnostics/can-transport", "Diagnostics / CAN transport",
     "CAN/ISO-TP diagnostic transport"),
    ("application/02-diagnostics/status", "Diagnostics / status",
     "Diagnostic status packing"),
    ("application/02-diagnostics/test-commands", "Diagnostics / test commands",
     "Actuator/test command dispatch"),
    ("application/03-calibration/accessors", "Calibration / accessors",
     "Axis/table/map accessors"),
    ("application/03-calibration/checksum", "Calibration / checksum",
     "Calibration block checksum"),
    ("application/04-engine-control/events", "Engine control / events",
     "CC16/CC17 normal event scheduler"),
    ("application/04-engine-control/outputs-cc22-23", "Engine control / CC22-23 outputs",
     "CC22/CC23 actuator/test outputs"),
    ("application/04-engine-control/speed", "Engine control / speed",
     "Speed timing conversion"),
    ("application/04-engine-control/load", "Engine control / load",
     "Load/base calculation"),
    ("application/04-engine-control/limits", "Engine control / limits",
     "Limit calculations"),
    ("application/04-engine-control/sensor", "Engine control / sensor",
     "Sensor/config setup"),
    ("application/05-runtime-lib", "Runtime library",
     "Fixed-point/software-float and memory helpers"),
]

AREA_TITLE = {a: t for a, t, _ in AREAS}
AREA_SCOPE = {a: s for a, _, s in AREAS}
AREA_TITLE[BOOT_AREA] = "Bootloader"
AREA_SCOPE[BOOT_AREA] = "Reset, integrity checks, bootloader, traps"

BOOT = {
    "boot_main", "boot_periph_init", "boot_bus_mode", "checksum16_be",
    "delay_loop", "delay_ticks", "boot_minimal_main", "bootloader_entry",
    "boot_cinit", "boot_reset", "boot_port_adc_init", "boot_extint_init",
    "can_bootloader_wait", "trap_stack_overflow", "trap_stack_underflow",
    "trap_bootstrap",
}
STARTUP = {
    "app_entry", "app_cstart", "app_cinit", "app_main", "app_hw_init",
    "app_run", "app_main_init", "app_scheduler", "app_scheduler_path",
    "app_idle_wait", "scheduler_tick", "command_dispatch",
    "command_dispatch_index3", "app_clear_flag", "timeout_counter_tick",
}
DRV_CAN = {"can_twincan_init", "can0_isr", "can_bus_config", "set_can_flag"}
DIAG_CAN = {
    "can_diag_object_init", "can_rx_process", "can_rx_dispatch", "can_rx_cmd",
    "can_isotp_send", "can_tx_frame", "can_tx_confirm",
}
DRV_TIMERS = {
    "capcom_timer_init", "timer7_isr", "timer4_init", "timer6_init",
    "timer6_start", "timer8_init", "timer5_init", "capcom_start",
    "t7_timestamp", "t7_timestamp_extended",
}
DRV_IO = {
    "input_debounce_sample", "input_latch", "port_bus_init", "p1l1_set",
    "watchdog_pin", "capture_control", "capture_input_select", "capture_init",
}
DRV_PWM = {"pwm_init", "pwm_period_duty_calc", "pwm_output_enable"}
DRV_CLOCK = {"clock_init", "pll_isr"}
DRV_ADC = {"adc_start", "adc_calibrate"}
DRV_SSC = {
    "ssc_send_byte", "ssc0_rx_isr", "ssc_start_frame", "ssc_init",
    "ssc_state_reset", "ssc_pin_config", "ssc_mode_select", "ssc0_init_app",
    "ssc_send", "ssc_rx_start", "ssc_rx_queue_init", "ssc_task",
    "cc26_ptr_init",
}
DIAG_KWP = {
    "kwp_dispatch", "kwp_sid81", "kwp_sid27_security", "kwp_negative",
    "kwp_sid10_session", "kwp_sid83", "kwp_sid34_download",
    "kwp_sid36_transfer", "kwp_sid31_routine", "kwp_sid38",
    "kwp_sid23_read_mem", "kwp_sid3D_write_mem",
}
DIAG_KLINE = {
    "kline_receive_pattern", "kline_get_status", "kline_start_timeout",
    "kline_state_reset", "kline_prepare_frame", "kline_rx_state_7",
    "kline_rx_state_8", "kline_push_rx_byte", "kline_transport_task",
}
DIAG_STATUS = {"diag_status_build"}
DIAG_TEST = {"test_command_clear", "test_command_dispatch"}
CAL_ACCESS = {"axis16_signed", "axis16_unsigned", "tbl8_interp", "tbl16_interp", "tbl2d_interp"}
CAL_CHECK = {"cal_checksum"}
ENG_EVENTS = {
    "event_init", "event_start", "event_reset", "event_force", "event_cancel",
    "event_schedule", "event_schedule_duration", "event_idle", "event_accum",
    "capcom_event_config", "capcom_event_config2", "capcom16_17_init",
    "cc_irq_enable", "cc_irq_is_enabled", "cc_irq_enable_bit",
    "cc_compare_mode_set", "cc_control_ptr_init",
}
ENG_OUT = {
    "cc22_23_output_disable", "cc22_23_schedule", "cc22_23_output_init",
    "cc22_23_hysteresis_a", "cc22_23_hysteresis_b", "cc22_23_task",
    "cc22_23_start_pair", "cc22_23_start_once", "cc_event_timeout_tick",
    "cc_output_gate_update",
}
ENG_SPEED = {"speed_timing_calc", "angle_init"}
ENG_LOAD = {"calc_load"}
ENG_LIMITS = {"calc_limit1", "calc_limit2", "calc_limit3", "rate_limit"}
ENG_SENSOR = {"config_sensor_setup"}
RUNTIME = {
    "div32u", "mul32", "store32", "div32_checked", "mul_div32",
    "fp_div_signed", "fp_div_unsigned", "fp_to_int", "fp_neg", "fp_compare",
    "fp_pack", "fp_pack_zero", "fp_round", "fp_store", "fp_store_zero",
    "fp_load", "fp_copy", "memcpy_wdt", "mem_read_word", "mem_write_word",
    "seg_to_ptr", "ret_stub", "empty_stub_0", "empty_stub_1", "empty_stub_2",
    "empty_stub_3",
}


def classify(name):
    if name in BOOT or name.startswith(("boot_", "trap_", "delay_")):
        return BOOT_AREA
    if name in STARTUP or name.startswith("app_"):
        return "application/00-startup-runtime"
    if name in DRV_CAN:
        return "application/01-drivers/can"
    if name in DIAG_CAN:
        return "application/02-diagnostics/can-transport"
    if name in DRV_TIMERS:
        return "application/01-drivers/timers"
    if name in DRV_IO:
        return "application/01-drivers/io"
    if name in DRV_PWM:
        return "application/01-drivers/pwm"
    if name in DRV_CLOCK:
        return "application/01-drivers/clock"
    if name in DRV_ADC:
        return "application/01-drivers/adc"
    if name in DRV_SSC:
        return "application/01-drivers/ssc"
    if name in DIAG_KWP:
        return "application/02-diagnostics/kwp"
    if name in DIAG_KLINE:
        return "application/02-diagnostics/kline-transport"
    if name in DIAG_STATUS:
        return "application/02-diagnostics/status"
    if name in DIAG_TEST:
        return "application/02-diagnostics/test-commands"
    if name in CAL_ACCESS:
        return "application/03-calibration/accessors"
    if name in CAL_CHECK:
        return "application/03-calibration/checksum"
    if name in ENG_EVENTS:
        return "application/04-engine-control/events"
    if name in ENG_OUT:
        return "application/04-engine-control/outputs-cc22-23"
    if name in ENG_SPEED:
        return "application/04-engine-control/speed"
    if name in ENG_LOAD:
        return "application/04-engine-control/load"
    if name in ENG_LIMITS:
        return "application/04-engine-control/limits"
    if name in ENG_SENSOR:
        return "application/04-engine-control/sensor"
    if name in RUNTIME:
        return "application/05-runtime-lib"
    if name.startswith("asc0_"):
        return "application/01-drivers/kline-asc0"
    if name.startswith("ssc_"):
        return "application/01-drivers/ssc"
    if name.startswith("can_"):
        return "application/02-diagnostics/can-transport"
    if name.startswith("kwp_"):
        return "application/02-diagnostics/kwp"
    if name.startswith("kline_"):
        return "application/02-diagnostics/kline-transport"
    if name.startswith("cc22_23_"):
        return "application/04-engine-control/outputs-cc22-23"
    if name.startswith("event_") or name.startswith("cc_"):
        return "application/04-engine-control/events"
    if name.startswith("pwm_"):
        return "application/01-drivers/pwm"
    if name.startswith("fp_"):
        return "application/05-runtime-lib"
    return "99-uncategorized"


def load_desc():
    desc = {}
    conf = {}
    if os.path.exists(INDEX_CSV):
        for r in csv.DictReader(open(INDEX_CSV)):
            if r.get("kind") == "function":
                desc[r["name"]] = r.get("evidence", "") or "—"
                conf[r["name"]] = r.get("confidence", "")
    return desc, conf


def part_for(area):
    return "bootloader" if area == BOOT_AREA else "application"


def header_lines(part, kind):
    if kind == "c":
        return [
            "/* ============================================================================",
            f" * Delphi MT05.2 semantic reconstruction: {part} firmware part",
            " * Generated from Ghidra decompiler output; not compilable source.",
            " * Functions are grouped by area and sorted by address.",
            " * ========================================================================== */",
            "",
        ]
    return [
        "; ============================================================================",
        f"; Delphi MT05.2 semantic reconstruction: {part} firmware part",
        "; Generated from Ghidra decompiler output; not compilable source.",
        "; Functions are grouped by area and sorted by address.",
        "; ============================================================================",
        "",
    ]


def func_header(kind, name, entry, area, size):
    if kind == "c":
        return [
            "/* ----------------------------------------------------------------------------",
            f" * {name}",
            f" * Address: 0x{int(entry, 16):06X}",
            f" * Area:    {area}",
            f" * Size:    {size} bytes",
            " * -------------------------------------------------------------------------- */",
        ]
    return [
        "; ----------------------------------------------------------------------------",
        f"; {name}",
        f"; Address: 0x{int(entry, 16):06X}",
        f"; Area:    {area}",
        f"; Size:    {size} bytes",
        "; --------------------------------------------------------------------------",
    ]


def append_function(lines, kind, item, c_path, asm_path):
    header = func_header(kind, item["name"], item["entry"], item["area"], item["size"])
    start_line = len(lines) + 1
    lines.extend(header)
    path = c_path if kind == "c" else asm_path
    body = open(path).read().rstrip("\n")
    if body:
        lines.extend(body.splitlines())
    lines.extend(["", ""])
    return start_line


def build_part(part, items, c_rel, asm_rel):
    c_lines = header_lines(part, "c")
    asm_lines = header_lines(part, "asm")
    area_first = {}
    for area in [BOOT_AREA] + [a for a, _, _ in AREAS]:
        area_items = [x for x in items if x["area"] == area]
        if not area_items:
            continue
        area_items.sort(key=lambda x: int(x["entry"], 16))
        c_title = AREA_TITLE[area]
        c_lines.extend([f"/* ============================== {c_title} ============================== */", ""])
        asm_lines.extend([f"; ============================== {c_title} ==============================", ""])
        area_first[area] = {}
        for item in area_items:
            item["c_line"] = append_function(
                c_lines, "c", item,
                os.path.join(REF, os.path.basename(item["c_src"])),
                os.path.join(REF, os.path.basename(item["asm_src"])),
            )
            item["asm_line"] = append_function(
                asm_lines, "asm", item,
                os.path.join(REF, os.path.basename(item["c_src"])),
                os.path.join(REF, os.path.basename(item["asm_src"])),
            )
            item["c_file"] = c_rel
            item["asm_file"] = asm_rel
        area_first[area]["c"] = min(x["c_line"] for x in area_items)
        area_first[area]["asm"] = min(x["asm_line"] for x in area_items)
    open(os.path.join(OUT, c_rel), "w").write("\n".join(c_lines))
    open(os.path.join(OUT, asm_rel), "w").write("\n".join(asm_lines))
    return area_first


def table_rows(items, base):
    lines = [
        "| Address | Function | Size | Description | C | ASM |",
        "|---|---|---:|---|---|---|",
    ]
    for item in sorted(items, key=lambda x: int(x["entry"], 16)):
        d = item["desc"].replace("|", "\\|")
        cpath = os.path.relpath(item["c_file"], base)
        apath = os.path.relpath(item["asm_file"], base)
        lines.append(
            f"| 0x{int(item['entry'], 16):06X} | `{item['name']}` | {item['size']} | {d} | "
            f"[C]({cpath}#L{item['c_line']}) | "
            f"[ASM]({apath}#L{item['asm_line']}) |"
        )
    return lines


DUMP = os.path.join(ROOT, "dumps", "mash_dump.bin")
CAL_BIN = os.path.join(SHARED, "calibration_block.bin")
ADAPT_BIN = os.path.join(SHARED, "adaptation_log.bin")
LIVE_FIELDS_CSV = os.path.join(SHARED, "live_21_01_fields.csv")
LIVE_BITS_CSV = os.path.join(SHARED, "live_21_01_bits.csv")
LIVE_SLEW_CSV = os.path.join(SHARED, "live_30_slew.csv")
LIVE_MAP_CSV = os.path.join(SHARED, "live_firmware_map.csv")
DEBUG_CH_CSV = os.path.join(SHARED, "debug_channels.csv")

CAL_TABLE_DEFS = [
    ("cal_limit_curve_0", 0x784C, "tbl8"),
    ("cal_limit_curve_1", 0x7860, "tbl8"),
    ("cal_limit_curve_2", 0x7874, "tbl8"),
    ("cal_limit_curve_3", 0x78D8, "tbl8"),
    ("cal_limit_multiplier", 0x78E2, "tbl8"),
    ("cal_limit_table16", 0x7912, "tbl16"),
    ("cal_load_map", 0x794A, "tbl2d"),
    ("cal_constant_curve_0", 0x799E, "tbl8"),
    ("cal_constant_curve_1", 0x79AA, "tbl8"),
    ("cal_correction_curve", 0x79B6, "tbl8"),
]


def cstr(value):
    text = " ".join((value or "").split())
    if not text:
        return "NULL"
    return '"' + text.replace("\\", "\\\\").replace('"', '\\"') + '"'


def c_array(values, width=1, per=16):
    lines = []
    for start in range(0, len(values), per):
        chunk = values[start:start + per]
        if width == 1:
            lines.append("    " + ", ".join("0x%02X" % v for v in chunk) + ",")
        else:
            lines.append("    " + ", ".join("0x%04X" % v for v in chunk) + ",")
    return "\n".join(lines)


def parse_int(value, default=0):
    value = (value or "").strip()
    if not value:
        return default
    if value.lower().startswith("0x"):
        return int(value, 16)
    try:
        return int(value, 10)
    except ValueError:
        return int(value, 16)


def parse_hex(value, default=-1):
    value = (value or "").strip()
    if not value:
        return default
    return int(value, 16)


def parse_cal_tables():
    data = open(DUMP, "rb").read()
    meta = {}
    if os.path.exists(CAL_CSV):
        for row in csv.DictReader(open(CAL_CSV)):
            meta[parse_int(row.get("physical_address"))] = row.get("referenced_by", "")
    tables = []
    for name, offset, kind in CAL_TABLE_DEFS:
        address = 0xC00000 + offset
        if kind == "tbl8":
            count = data[offset]
            shift = data[offset + 1]
            values = list(data[offset + 2:offset + 2 + count])
            tables.append({
                "name": name, "address": address, "kind": 0, "cols": 0,
                "rows": 0, "shift": shift, "count": count, "values": values,
                "width": 1, "used_by": meta.get(address, ""),
            })
        elif kind == "tbl16":
            count = data[offset] | (data[offset + 1] << 8)
            values = [
                data[offset + 2 + 2 * i] | (data[offset + 3 + 2 * i] << 8)
                for i in range(count)
            ]
            tables.append({
                "name": name, "address": address, "kind": 1, "cols": 0,
                "rows": 0, "shift": 0, "count": count, "values": values,
                "width": 2, "used_by": meta.get(address, ""),
            })
        else:
            cols = data[offset]
            rows = data[offset + 1]
            shift = data[offset + 2]
            values = list(data[offset + 3:offset + 3 + cols * rows])
            tables.append({
                "name": name, "address": address, "kind": 2, "cols": cols,
                "rows": rows, "shift": shift, "count": len(values),
                "values": values, "width": 1, "used_by": meta.get(address, ""),
            })
    return tables


def write_data_part(items, tables):
    data_dir = os.path.join(OUT, "03-data")
    data_h = []
    data_c = ['#include "data.h"', "", '#include <stddef.h>', ""]
    func_rows = sorted(items, key=lambda x: int(x["entry"], 16))
    data_c.extend([
        "/* Function index: address, name, part, area, size, C/ASM line, description. */",
        "const mt05_function_t mt05_functions[] = {",
    ])
    for item in func_rows:
        data_c.append(
            '    { 0x%06X, %s, %s, %s, %d, %s, %d, %s, %d, %s, %s },'
            % (int(item["entry"], 16), cstr(item["name"]), cstr(item["part"]),
               cstr(item["area"]), int(item["size"]), cstr(item["c_file"]),
               item["c_line"], cstr(item["asm_file"]), item["asm_line"],
               cstr(item["desc"]), cstr(item["confidence"]))
        )
    data_c.extend(["};", "const size_t mt05_function_count = sizeof(mt05_functions) / sizeof(mt05_functions[0]);", ""])

    data_h.extend([
        "#ifndef MT05_RECON_DATA_H",
        "#define MT05_RECON_DATA_H",
        "",
        '#include "c166.h"',
        "#include <stddef.h>",
        "",
        "enum {",
        "    MT05_CAL_TBL8 = 0,",
        "    MT05_CAL_TBL16 = 1,",
        "    MT05_CAL_MAP2D = 2",
        "};",
        "",
        "typedef struct {",
        "    u32 address;",
        "    const char *name;",
        "    const char *part;",
        "    const char *area;",
        "    u16 size;",
        "    const char *c_file;",
        "    u16 c_line;",
        "    const char *asm_file;",
        "    u16 asm_line;",
        "    const char *description;",
        "    const char *confidence;",
        "} mt05_function_t;",
        "",
        "typedef struct {",
        "    const char *name;",
        "    u32 address;",
        "    u8 kind;",
        "    u8 cols;",
        "    u8 rows;",
        "    u8 shift;",
        "    u16 count;",
        "    const void *data;",
        "    const char *used_by;",
        "} mt05_cal_table_t;",
        "",
        "typedef struct {",
        "    const char *dump;",
        "    u16 offset;",
        "    u16 sequence;",
        "    u16 signature;",
        "    u16 tail;",
        "} mt05_adapt_record_t;",
        "",
        "typedef struct {",
        "    const char *dump;",
        "    u16 start;",
        "    u16 end;",
        "    u16 length;",
        "} mt05_diff_range_t;",
        "",
        "typedef struct {",
        "    s16 offset;",
        "    u8 bytes;",
        "    const char *type;",
        "    const char *uid;",
        "    const char *name;",
        "    const char *formula;",
        "    const char *unit;",
        "    u8 digits;",
        "    u8 bit_count;",
        "} mt05_live_field_t;",
        "",
        "typedef struct {",
        "    u8 offset;",
        "    u8 bit;",
        "    const char *uid;",
        "    const char *name;",
        "    u8 inverted;",
        "    const char *disp_vals;",
        "} mt05_live_bit_t;",
        "",
        "typedef struct {",
        "    u8 slew_id;",
        "    const char *uid;",
        "    const char *name;",
        "    const char *formula_set;",
        "    s16 min;",
        "    s16 max;",
        "} mt05_live_slew_t;",
        "",
        "typedef struct {",
        "    u32 firmware_address;",
        "    const char *firmware_name;",
        "    s16 firmware_bit;",
        "    s16 live_offset;",
        "    s16 live_bit;",
        "    const char *live_uid;",
        "    const char *live_name;",
        "    u8 inverted;",
        "    const char *firmware_alias;",
        "    const char *evidence;",
        "    const char *confidence;",
        "} mt05_live_fw_map_t;",
        "",
        "typedef struct {",
        "    u32 address;",
        "    const char *name;",
        "    const char *direction;",
        "    const char *producers;",
        "    const char *consumers;",
        "    const char *observed_role;",
        "    const char *candidate_meaning;",
        "    const char *confidence;",
        "} mt05_debug_channel_t;",
        "",
        "extern const u8 mt05_calibration_block[0x6000];",
        "extern const u8 mt05_adaptation_log[0xD00];",
    ])
    for table in tables:
        ctype = "u16" if table["width"] == 2 else "u8"
        data_h.append("extern const %s mt05_%s[%d];" % (ctype, table["name"], table["count"]))
    data_h.extend([
        "",
        "extern const mt05_function_t mt05_functions[];",
        "extern const size_t mt05_function_count;",
        "extern const mt05_cal_table_t mt05_cal_tables[];",
        "extern const size_t mt05_cal_table_count;",
        "extern const mt05_adapt_record_t mt05_adapt_records[];",
        "extern const size_t mt05_adapt_record_count;",
        "extern const mt05_diff_range_t mt05_diff_ranges[];",
        "extern const size_t mt05_diff_range_count;",
        "extern const mt05_live_field_t mt05_live_fields[];",
        "extern const size_t mt05_live_field_count;",
        "extern const mt05_live_bit_t mt05_live_bits[];",
        "extern const size_t mt05_live_bit_count;",
        "extern const mt05_live_slew_t mt05_live_slew[];",
        "extern const size_t mt05_live_slew_count;",
        "extern const mt05_live_fw_map_t mt05_live_fw_map[];",
        "extern const size_t mt05_live_fw_map_count;",
        "extern const mt05_debug_channel_t mt05_debug_channels[];",
        "extern const size_t mt05_debug_channel_count;",
        "",
        "#endif /* MT05_RECON_DATA_H */",
        "",
    ])

    cal_block = open(CAL_BIN, "rb").read() if os.path.exists(CAL_BIN) else bytes(0x6000)
    adapt_log = open(ADAPT_BIN, "rb").read() if os.path.exists(ADAPT_BIN) else bytes(0xD00)
    data_c.extend(["/* Raw calibration block 0xC05000-0xC0AFFF. */", "const u8 mt05_calibration_block[0x6000] = {"])
    data_c.append(c_array(list(cal_block), 1, 16))
    data_c.append("};")
    data_c.append("")
    data_c.extend(["/* Raw adaptation log 0xC04000-0xC04CFF. */", "const u8 mt05_adaptation_log[0xD00] = {"])
    data_c.append(c_array(list(adapt_log), 1, 16))
    data_c.append("};")
    data_c.append("")

    data_c.extend(["", "/* Calibration table arrays (indexed by mt05_cal_tables). */"])
    for table in tables:
        ctype = "u16" if table["width"] == 2 else "u8"
        data_c.append("const %s mt05_%s[%d] = {" % (ctype, table["name"], table["count"]))
        data_c.append(c_array(table["values"], table["width"], 16))
        data_c.append("};")
        data_c.append("")

    data_c.extend(["", "/* Calibration table descriptors. */", "const mt05_cal_table_t mt05_cal_tables[] = {"])
    for table in tables:
        data_c.append(
            '    { %s, 0x%06X, %d, %d, %d, %d, %d, (const void *)mt05_%s, %s },'
            % (cstr(table["name"]), table["address"], table["kind"],
               table["cols"], table["rows"], table["shift"], table["count"],
               table["name"], cstr(table["used_by"]))
        )
    data_c.extend(["};", "const size_t mt05_cal_table_count = sizeof(mt05_cal_tables) / sizeof(mt05_cal_tables[0]);", ""])

    adapt_rows = list(csv.DictReader(open(EEPROM_CSV))) if os.path.exists(EEPROM_CSV) else []
    data_c.extend(["", "/* Adaptation log record descriptors (all four dumps). */", "const mt05_adapt_record_t mt05_adapt_records[] = {"])
    for row in adapt_rows:
        data_c.append(
            '    { %s, 0x%04X, 0x%04X, 0x%04X, 0x%04X },'
            % (cstr(row.get("dump")), parse_int(row.get("offset")),
               parse_int(row.get("sequence")), parse_int(row.get("tail_signature")),
               parse_int(row.get("tail_value")))
        )
    data_c.extend(["};", "const size_t mt05_adapt_record_count = sizeof(mt05_adapt_records) / sizeof(mt05_adapt_records[0]);", ""])

    diff_rows = list(csv.DictReader(open(DIFF_CSV))) if os.path.exists(DIFF_CSV) else []
    data_c.extend(["", "/* Byte ranges that differ between dumps. */", "const mt05_diff_range_t mt05_diff_ranges[] = {"])
    for row in diff_rows:
        data_c.append(
            '    { %s, 0x%04X, 0x%04X, 0x%04X },'
            % (cstr(row.get("dump")), parse_int(row.get("start_offset")),
               parse_int(row.get("end_offset_inclusive")), parse_int(row.get("length")))
        )
    data_c.extend(["};", "const size_t mt05_diff_range_count = sizeof(mt05_diff_ranges) / sizeof(mt05_diff_ranges[0]);", ""])

    field_rows = list(csv.DictReader(open(LIVE_FIELDS_CSV))) if os.path.exists(LIVE_FIELDS_CSV) else []
    data_c.extend(["", "/* live-data MT05/MT05.2 21 01 live-data fields. */", "const mt05_live_field_t mt05_live_fields[] = {"])
    for row in field_rows:
        data_c.append(
            '    { %d, %d, %s, %s, %s, %s, %s, %d, %d },'
            % (parse_hex(row.get("offset")), parse_int(row.get("bytes")),
               cstr(row.get("type")), cstr(row.get("uid")), cstr(row.get("name")),
               cstr(row.get("formula")), cstr(row.get("unit")),
               parse_int(row.get("digits")), parse_int(row.get("bit_count")))
        )
    data_c.extend(["};", "const size_t mt05_live_field_count = sizeof(mt05_live_fields) / sizeof(mt05_live_fields[0]);", ""])

    bit_rows = list(csv.DictReader(open(LIVE_BITS_CSV))) if os.path.exists(LIVE_BITS_CSV) else []
    data_c.extend(["", "/* live-data 21 01 status-bit names (bytes 0x37..0x3B). */", "const mt05_live_bit_t mt05_live_bits[] = {"])
    for row in bit_rows:
        inv = 1 if (row.get("inverted") or "").strip().lower() in ("yes", "true", "1", "inverted") else 0
        data_c.append(
            '    { 0x%02X, %d, %s, %s, %d, %s },'
            % (parse_hex(row.get("offset")), parse_int(row.get("bit")),
               cstr(row.get("uid")), cstr(row.get("name")), inv, cstr(row.get("disp_vals")))
        )
    data_c.extend(["};", "const size_t mt05_live_bit_count = sizeof(mt05_live_bits) / sizeof(mt05_live_bits[0]);", ""])

    slew_rows = list(csv.DictReader(open(LIVE_SLEW_CSV))) if os.path.exists(LIVE_SLEW_CSV) else []
    data_c.extend(["", "/* live-data 0x30 data-slewing channels. */", "const mt05_live_slew_t mt05_live_slew[] = {"])
    for row in slew_rows:
        data_c.append(
            '    { 0x%02X, %s, %s, %s, %d, %d },'
            % (parse_int(row.get("slew_id")), cstr(row.get("uid")), cstr(row.get("name")),
               cstr(row.get("formula_set")), parse_int(row.get("min")), parse_int(row.get("max")))
        )
    data_c.extend(["};", "const size_t mt05_live_slew_count = sizeof(mt05_live_slew) / sizeof(mt05_live_slew[0]);", ""])

    map_rows = list(csv.DictReader(open(LIVE_MAP_CSV))) if os.path.exists(LIVE_MAP_CSV) else []
    data_c.extend(["", "/* Firmware byte/bit to live-data field/status-bit aliases. */", "const mt05_live_fw_map_t mt05_live_fw_map[] = {"])
    for row in map_rows:
        inv = 1 if (row.get("inverted") or "").strip().lower() in ("yes", "true", "1", "inverted") else 0
        data_c.append(
            '    { 0x%06X, %s, %d, %d, %d, %s, %s, %d, %s, %s, %s },'
            % (parse_int(row.get("firmware_address")), cstr(row.get("firmware_name")),
               parse_int(row.get("firmware_bit"), -1), parse_hex(row.get("live_offset"), -1),
               parse_int(row.get("live_bit"), -1), cstr(row.get("live_uid")),
               cstr(row.get("live_name")), inv, cstr(row.get("firmware_alias")),
               cstr(row.get("evidence")), cstr(row.get("confidence")))
        )
    data_c.extend(["};", "const size_t mt05_live_fw_map_count = sizeof(mt05_live_fw_map) / sizeof(mt05_live_fw_map[0]);", ""])

    debug_rows = list(csv.DictReader(open(DEBUG_CH_CSV))) if os.path.exists(DEBUG_CH_CSV) else []
    data_c.extend(["", "/* Candidate live-data/debug channels in the firmware. */", "const mt05_debug_channel_t mt05_debug_channels[] = {"])
    for row in debug_rows:
        data_c.append(
            '    { 0x%06X, %s, %s, %s, %s, %s, %s, %s },'
            % (parse_int(row.get("address")), cstr(row.get("name")),
               cstr(row.get("direction")), cstr(row.get("producers")),
               cstr(row.get("consumers")), cstr(row.get("observed_role")),
               cstr(row.get("candidate_meaning")), cstr(row.get("confidence")))
        )
    data_c.extend(["};", "const size_t mt05_debug_channel_count = sizeof(mt05_debug_channels) / sizeof(mt05_debug_channels[0]);", ""])


    open(os.path.join(data_dir, "data.h"), "w").write("\n".join(data_h))
    open(os.path.join(data_dir, "data.c"), "w").write("\n".join(data_c))
    return data_dir


def main():
    rows = list(csv.DictReader(open(os.path.join(REF, "function_map.csv"))))
    desc, conf = load_desc()
    items = []
    for row in rows:
        name = row["name"]
        area = classify(name)
        items.append({
            "entry": row["entry"],
            "name": name,
            "area": area,
            "part": part_for(area),
            "size": row["size_bytes"],
            "c_src": row["c_file"],
            "asm_src": row["asm_file"],
            "desc": desc.get(name, "—"),
            "confidence": conf.get(name, ""),
        })

    unc = [x for x in items if x["area"] == "99-uncategorized"]
    if unc:
        print("UNCATEGORIZED:", ", ".join(x["name"] for x in unc))
        return 1

    if os.path.isdir(OUT):
        shutil.rmtree(OUT)
    for folder in ("01-bootloader", "02-application", "03-data"):
        os.makedirs(os.path.join(OUT, folder), exist_ok=True)

    boot_items = [x for x in items if x["part"] == "bootloader"]
    app_items = [x for x in items if x["part"] == "application"]
    boot_areas = build_part(
        "bootloader", boot_items,
        "01-bootloader/bootloader.c", "01-bootloader/bootloader.asm",
    )
    app_areas = build_part(
        "application", app_items,
        "02-application/application.c", "02-application/application.asm",
    )

    boot_count = len(boot_items)
    app_count = len(app_items)
    total = boot_count + app_count
    by_area = {a: [x for x in app_items if x["area"] == a] for a, _, _ in AREAS}
    tables = parse_cal_tables()
    data_dir = write_data_part(items, tables)

    def entry_link(name):
        item = next(x for x in items if x["name"] == name)
        return f"[{name}]({item['c_file']}#L{item['c_line']})"

    lines = [
        "# Semantic reconstruction",
        "",
        "This directory is a C-developer navigation tree for the recovered firmware.",
        "It has exactly three parts: **01-bootloader**, **02-application** and",
        "**03-data**. Functions are consolidated into one C and one ASM file per",
        "executable part; all tables, records and maps are C arrays/structs in",
        "`03-data/`, not CSV files.",
        "",
        "The decompiled C/ASM files are Ghidra output, not original source and not",
        "a compilable translation unit. The buildable host model is in",
        "`../firmware/src/`.",
        "",
        "## Parts",
        "",
        "| Part | Address | Size | Functions | Files |",
        "|---|---|---:|---:|---|",
        f"| [`01-bootloader/`](01-bootloader/README.md) | `0xC00000–0xC01FFF` | 8 KB | {boot_count} | [C](01-bootloader/bootloader.c) · [ASM](01-bootloader/bootloader.asm) |",
        f"| [`02-application/`](02-application/README.md) | `0xC0B000–0xC3FFFF` | 212 KB | {app_count} | [C](02-application/application.c) · [ASM](02-application/application.asm) |",
        "| [`03-data/`](03-data/README.md) | `0xC05000–0xC0AFFF` + log | 24 KB + 3.25 KB | 0 | [data.c](03-data/data.c) · [data.h](03-data/data.h) · headers |",
        "",
        "`03-data` holds the calibration block/tables, adaptation-log records and",
        "dump deltas, the live-data map, the function index, and the shared",
        "headers. Generated C-only views of the whole-image names and the",
        "0xC0BB56 RAM-init table are added by `build_auto_names.py`.",
        "",
        "## Start here",
        "",
        f"1. [`01-bootloader/README.md`](01-bootloader/README.md) — {boot_count} functions in [`bootloader.c`](01-bootloader/bootloader.c).",
        f"2. [`02-application/README.md`](02-application/README.md) — {app_count} functions in [`application.c`](02-application/application.c), grouped by area.",
        "3. [`03-data/README.md`](03-data/README.md) — calibration tables, adaptation log, live-data map, function index and headers.",
        "4. [`03-data/data.c`](03-data/data.c) — the C function index and all data arrays/structs.",
        "",
        "## Function counts by application area",
        "",
        "| Area | Functions | C section | ASM section |",
        "|---|---:|---|---|",
    ]
    for area, title, _ in AREAS:
        n = len(by_area[area])
        lines.append(
            f"| {title} | {n} | "
            f"[line {app_areas[area]['c']}](02-application/application.c#L{app_areas[area]['c']}) | "
            f"[line {app_areas[area]['asm']}](02-application/application.asm#L{app_areas[area]['asm']}) |"
        )
    lines += [
        f"| **application total** | **{app_count}** | | |",
        "",
        "## Key entry points",
        "",
        f"- Boot/reset: {entry_link('boot_reset')}, {entry_link('boot_main')}, {entry_link('checksum16_be')}",
        f"- Application start: {entry_link('app_cstart')}, {entry_link('app_main')}, {entry_link('app_scheduler')}",
        f"- KWP2000: {entry_link('kwp_dispatch')}",
        f"- Calibration accessors: {entry_link('axis16_unsigned')}, {entry_link('tbl8_interp')}, {entry_link('tbl2d_interp')}",
        f"- Engine load/limits: {entry_link('calc_load')}, {entry_link('calc_limit1')}, {entry_link('calc_limit2')}, {entry_link('calc_limit3')}",
        "",
        "## Caveats",
        "",
        "- Decompiler artifacts (`undefined2`, `halt_baddata`, `extraout_*`) remain.",
        "- Some names are mechanical (`*_var_*`, `diag_flag_*`, `isr_save_*`); see",
        "  `../firmware/SEMANTIC_NAMES.md` for evidence and confidence.",
        "- The 9x9 map at `0xC0794A` is most likely a volume-efficiency map; live-data",
        "  live-data fields and logs support that, but the axis descriptors are external RAM.",
        "- The CC16/17 pair is most likely injection + ignition; live-data separates injector",
        "  time, dwell and spark advance. The exact channel assignment remains open.",
        "- The application `0x21`/`0x30` live-data handlers and the axis/task tables",
        "  are in external RAM (`0x7164`, `0x750A..0x7564`, `0x705E`) and are not in the dump.",
        "",
        "## Related documents",
        "",
        "- `../docs/00-INDEX.md` — full analysis report",
        "- `../docs/12-debug-channels.md` — live-data packet and status bits",
        "- `../docs/13-live-data-inferences.md` — revised firmware interpretation",
        "- `../firmware/SEMANTIC_NAMES.md` — naming evidence",
        "- `../firmware/ALGORITHMS.md` — algorithm cross-index",
        "",
    ]
    open(os.path.join(OUT, "README.md"), "w").write("\n".join(lines))

    boot_lines = [
        "# Bootloader",
        "",
        "Firmware part: bootloader, `0xC00000–0xC01FFF`, 8 KB.",
        "",
        f"{boot_count} functions in [`bootloader.c`](bootloader.c) and [`bootloader.asm`](bootloader.asm).",
        "",
        "[Back to reconstruction index](../README.md) · [Function index](../03-data/data.c)",
        "",
    ]
    boot_lines += table_rows(boot_items, "01-bootloader")
    boot_lines += [
        "",
        "Files are Ghidra decompiler output; they are not a compilable translation unit.",
        "",
    ]
    open(os.path.join(OUT, "01-bootloader", "README.md"), "w").write("\n".join(boot_lines))

    app_lines = [
        "# Application",
        "",
        "Firmware part: application, `0xC0B000–0xC3FFFF`, 212 KB.",
        "",
        f"{app_count} functions in [`application.c`](application.c) and [`application.asm`](application.asm).",
        "Calibration access code is application code; the calibration block itself is",
        "data in `../03-data/`.",
        "",
        "[Back to reconstruction index](../README.md) · [Function index](../03-data/data.c)",
        "",
        "| Area | Functions |",
        "|---|---:|",
    ]
    for area, title, _ in AREAS:
        app_lines.append(f"| {title} | {len(by_area[area])} |")
    app_lines.append(f"| **total** | **{app_count}** |")
    app_lines.append("")
    for area, title, scope in AREAS:
        app_lines += [
            f"## {title}",
            "",
            f"{scope}.",
            "",
        ]
        app_lines += table_rows(by_area[area], "02-application")
        app_lines.append("")
    app_lines += [
        "Files are Ghidra decompiler output; they are not a compilable translation unit.",
        "",
    ]
    open(os.path.join(OUT, "02-application", "README.md"), "w").write("\n".join(app_lines))

    data_readme = f"""# Data

Firmware data part: calibration block and tables, adaptation log and dump deltas,
live-data map, function index, constants and recovered structures.

[Back to reconstruction index](../README.md) · [Function index](data.c)

## Files

| File | Contents |
|---|---|
| `data.c` | C arrays/structs for all data below |
| `data.h` | struct definitions and extern declarations |
| `constants.h` | flash block boundaries, checksums, calibration selectors and table bases |
| `firmware_types.h` | recovered firmware structures |
| `c166.h` | fixed-width C166 types and flash macros |

## Function index

`data.c` contains `mt05_functions[]` ({total} entries) with address, name, part,
area, size, C/ASM file, line number, description and confidence. Use it instead
of a CSV index.

## Calibration data

`data.c` contains:

* `mt05_calibration_block[0x6000]` — raw `0xC05000–0xC0AFFF` block
* `mt05_cal_tables[]` — {len(tables)} table descriptors (address, kind, shape, used-by)
* per-table C arrays:
  * 8-bit tables: `mt05_cal_limit_curve_0[]` … `mt05_cal_correction_curve[]`
  * 16-bit table: `mt05_cal_limit_table16[]`
  * 9×9 map: `mt05_cal_load_map[81]`

Table formats:

* 8-bit: `{{u8 count, u8 shift, u8 data[]}}`
* 16-bit: `{{u16 count, u16 data[]}}`
* 2D: `{{u8 cols, u8 rows, u8 shift, u8 data[]}}`

The 9×9 map is most likely a volume-efficiency map; see `../docs/06-calibration.md`
and `../docs/13-live-data-inferences.md`.

## Adaptation log

`data.c` contains:

* `mt05_adaptation_log[0xD00]` — raw log
* `mt05_adapt_records[]` — record sequence/tail descriptors
* `mt05_diff_ranges[]` — byte ranges that differ between dumps

The log is a `0x200`-byte record ring with `5A A5` signatures; see
`../docs/08-adaptive-data.md`.

## live-data map

`data.c` contains the C form of the live-data MT05/MT05.2 profile:

* `mt05_live_fields[]` — `21 01` 100-byte packet fields/formulas/units
* `mt05_live_bits[]` — 40 status-bit names
* `mt05_live_slew[]` — `0x30` data-slewing channels
* `mt05_live_fw_map[]` — firmware byte/bit to live-data field/status aliases
* `mt05_debug_channels[]` — candidate live-data/debug variables

See `../docs/12-debug-channels.md` and `../docs/13-live-data-inferences.md`.

## No CSV files

All data previously exported as CSV in this tree is now C. The source analysis
CSVs remain in `../../artifacts/`; this reconstruction is self-contained C.
"""
    open(os.path.join(data_dir, "README.md"), "w").write(data_readme)

    if os.path.exists(TYPES_H):
        shutil.copy2(TYPES_H, os.path.join(data_dir, "firmware_types.h"))
    if os.path.exists(C166_H):
        shutil.copy2(C166_H, os.path.join(data_dir, "c166.h"))
    constants_h = r'''#ifndef MT05_CONSTANTS_H
#define MT05_CONSTANTS_H

/* Delphi MT05.2 / Infineon XC164CS-32 flash and calibration constants.
 * These are addresses and fixed values observed in the firmware. */

#define FLASH_BASE                 0xC00000u
#define FLASH_SIZE                 0x00040000u

#define BOOT_BLOCK_START           0xC00000u
#define BOOT_BLOCK_END             0xC02000u
#define BOOT_CHECKSUM_ADDR         0xC01FFEu

#define ADAPTATION_LOG_START       0xC04000u
#define ADAPTATION_LOG_END         0xC04D00u

#define CAL_BLOCK_START            0xC05000u
#define CAL_BLOCK_END              0xC0B000u
#define CAL_CHECKSUM_ADDR          0xC0AFFEu
#define CAL_ID_ADDR                0xC05000u

#define APP_BLOCK_START            0xC0B000u
#define APP_BLOCK_END              0xC40000u
#define APP_CHECKSUM_ADDR          0xC3FFFEu
#define APP_MAGIC_ADDR             0xC3FFFCu

/* Calibration configuration selectors */
#define CAL_CONFIG_SELECTOR_ADDR   0xC05036u
#define CAL_CAPTURE_CONFIG_ADDR    0xC05064u
#define CAL_TIMER_CONFIG_ADDR      0xC05068u
#define CAL_ADC_CONFIG_ADDR        0xC0506Au
#define CAL_CALC_VARIANT_ADDR      0xC0507Au
#define CAL_CC22_CONFIG_ADDR       0xC05080u
#define CAL_PWM_CONFIG_ADDR        0xC05081u

/* Limit/load scalars */
#define CAL_SPEED_LIMIT_THRESHOLD  0xC0781Eu
#define CAL_LIMIT_MULTIPLIER       0xC07830u
#define CAL_LIMIT_COUNTER_THRESHOLD 0xC07832u
#define CAL_LIMIT_COUNT            0xC07834u
#define CAL_LIMIT_FALLBACK_SPEED   0xC0783Cu
#define CAL_PWM_SCALE              0xC078E0u
#define CAL_LIMIT_FLAG             0xC079CAu
#define CAL_CC_START_OFFSET        0xC079DAu

/* Table bases (see data.c) */
#define CAL_LIMIT_CURVE_0          0xC0784Cu
#define CAL_LIMIT_CURVE_1          0xC07860u
#define CAL_LIMIT_CURVE_2          0xC07874u
#define CAL_LIMIT_CURVE_3          0xC078D8u
#define CAL_LIMIT_MULTIPLIER_CURVE 0xC078E2u
#define CAL_LIMIT_TABLE16          0xC07912u
#define CAL_LOAD_MAP               0xC0794Au
#define CAL_CONSTANT_CURVE_0       0xC0799Eu
#define CAL_CONSTANT_CURVE_1       0xC079AAu
#define CAL_CORRECTION_CURVE       0xC079B6u

#endif /* MT05_CONSTANTS_H */
'''
    open(os.path.join(data_dir, "constants.h"), "w").write(constants_h)

    cmake = """cmake_minimum_required(VERSION 3.16)
project(mt05_curated_reconstruction C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(mt05_curated_data STATIC 03-data/data.c)
target_include_directories(mt05_curated_data PUBLIC 03-data)
if (MSVC)
    target_compile_options(mt05_curated_data PRIVATE /W4)
else()
    target_compile_options(mt05_curated_data PRIVATE -Wall -Wextra -Wpedantic)
endif()

enable_testing()
add_test(NAME curated_compile COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target mt05_curated_data)
"""
    makefile = """.PHONY: all test clean

all:
	cmake -S . -B build
	cmake --build build

test: all
	ctest --test-dir build --output-on-failure

clean:
	rm -rf build
"""
    open(os.path.join(OUT, "CMakeLists.txt"), "w").write(cmake)
    open(os.path.join(OUT, "Makefile"), "w").write(makefile)

    print(f"wrote {OUT}: {total} functions in 2 C/ASM pairs; data part {len(tables)} tables")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
