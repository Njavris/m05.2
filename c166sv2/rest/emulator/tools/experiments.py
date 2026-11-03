#!/usr/bin/env python3
"""Deterministic dynamic experiments for the MT05.2 image.

Examples:
  python -m emulator.tools.experiments boot
  python -m emulator.tools.experiments checksums
  python -m emulator.tools.experiments engine-state --steps 4000000
  python -m emulator.tools.experiments limit2
  python -m emulator.tools.experiments scheduler-table
  python -m emulator.tools.experiments tables
"""

from __future__ import annotations

import argparse
import csv
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from emulator.c166.cpu import C166CPU
from emulator.c166.loader import load_dump
from emulator.c166.memory import Memory
from emulator.c166.peripherals import Peripherals


REPO = Path(__file__).resolve().parents[4]
DUMP = REPO / "dumps" / "mash_dump.bin"
FUNCTIONS = REPO / "c166sv2" / "rest" / "artifacts" / "ghidra-full" / "functions.csv"


def make_cpu():
    raw, info = load_dump(DUMP)
    memory = Memory(fill=0)
    memory.load_flash(raw)
    periph = Peripherals()
    cpu = C166CPU(memory, periph)
    cpu.reset()
    return cpu, memory, periph, info


def boot_snapshot(max_steps=3_000_000):
    cpu, memory, periph, info = make_cpu()
    reason = cpu.run(max_steps=max_steps, stop_pcs={0xC11EB4})
    if reason != "stop_address":
        raise SystemExit(f"boot failed: {reason} {cpu.stop_detail} at 0x{cpu.pc:06X}")
    return bytes(memory.data), cpu.register_dump(), set(cpu._pc_hits) | {cpu.pc}, info


def restore(data, regs):
    memory = Memory(fill=0)
    memory.data[:] = data
    periph = Peripherals()
    cpu = C166CPU(memory, periph)
    cpu.reset()
    for attr in ("psw", "cp", "sp", "csp", "ip", "md", "mdc"):
        setattr(cpu, attr, regs[attr])
    cpu.dpp[:] = regs["dpp"]
    return cpu, memory, periph


def load_functions():
    rows = []
    with open(FUNCTIONS, newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            try:
                rows.append((int(row["address"], 16), max(int(row["size"]), 2),
                             row["name"]))
            except (KeyError, ValueError):
                pass
    return rows


def containing(functions, pc):
    best = None
    for address, size, name in functions:
        if address <= pc < address + size:
            best = (address, name)
        elif address > pc:
            break
    return best


def cmd_boot(args):
    data, regs, pcs, info = boot_snapshot(args.max_steps)
    functions = load_functions()
    touched = sum(1 for address, size, name in functions
                  if any(address <= pc < address + size for pc in pcs))
    result = {
        "sha256": info.sha256,
        "checksums": {name: {"computed": c, "stored": s}
                      for name, (c, s) in info.checksums.items()},
        "stop_pc": f"0x{regs['pc']:06X}",
        "steps": regs["steps"],
        "dynamic_unique_pcs": len(pcs),
        "static_rows": len(functions),
        "static_functions_touched": touched,
        "known_pcs": {
            "boot_reset": "0xC00A78",
            "boot_main": "0xC00200",
            "app_entry": "0xC10000",
            "app_cstart": "0xC11AA0",
            "app_main": "0xC0FFDE",
            "app_scheduler": "0xC11EB4",
        },
    }
    print(json.dumps(result, indent=2, sort_keys=True))


def call_checksum(start, end, max_steps=2_000_000):
    cpu, memory, periph, info = make_cpu()
    cpu.sp = 0xFC00
    cpu.write_word_gpr(12, start & 0xFFFF)
    cpu.write_word_gpr(13, (start >> 16) & 0xFF)
    cpu.write_word_gpr(14, end & 0xFFFF)
    cpu.write_word_gpr(15, (end >> 16) & 0xFF)
    cpu.csp = 0xC1
    cpu.ip = 0x1EB4
    cpu.push16(cpu.csp)
    cpu.push16(cpu.ip)
    cpu.csp = 0xC0
    cpu.ip = 0x037E
    while cpu.pc != 0xC11EB4 and cpu.stop_reason is None and cpu.steps < max_steps:
        cpu.step()
    return cpu, info


def cmd_checksums(args):
    result = {}
    for name, start, end, key in (
        ("boot", 0xC00000, 0xC01FFD, "boot"),
        ("calibration", 0xC05000, 0xC0AFFD, "calibration"),
        ("application", 0xC0B000, 0xC3FFFB, "application"),
    ):
        cpu, info = call_checksum(start, end)
        computed, stored = info.checksums[key]
        result[name] = {
            "routine_result": f"0x{cpu.read_word_gpr(4):04X}",
            "python_computed": f"0x{computed:04X}",
            "stored": f"0x{stored:04X}",
            "match": cpu.read_word_gpr(4) == stored == computed,
            "steps": cpu.steps,
            "stop": cpu.stop_reason,
        }
    print(json.dumps(result, indent=2, sort_keys=True))


def cmd_engine_state(args):
    cpu, memory, periph, info = make_cpu()
    watches = {
        0x00C93C, 0x00C962, 0x00CB60, 0x00C584,
        0xC0B05E, 0xC0B09C, 0xC0B500, 0xC0B50A, 0xC0B510,
        0xC0B552, 0xC0B55E, 0xC0B564, 0xC0B666,
    }
    cpu.watch_physical = watches
    events = []
    cpu.watch_cb = lambda access, logical, physical, width, value, source, step, pc: events.append(
        (step, access, logical, physical, width, value, pc))
    while cpu.steps < args.steps:
        if args.tick_every and cpu.steps and cpu.steps % args.tick_every == 0:
            periph.timer_tick(args.tick_amount)
        cpu.step()
        if cpu.stop_reason:
            break
    functions = load_functions()
    writes = defaultdict(Counter)
    reads = defaultdict(Counter)
    for step, access, logical, physical, width, value, pc in events:
        if access == "write":
            writes[physical][(pc, width, value)] += 1
        else:
            reads[physical][pc] += 1
    result = {
        "stop": {"reason": cpu.stop_reason, "pc": f"0x{cpu.pc:06X}",
                 "steps": cpu.steps},
        "writes": {},
        "read_pcs": {},
    }
    for physical in sorted(writes):
        rows = []
        for (pc, width, value), count in writes[physical].most_common(8):
            rows.append({"pc": f"0x{pc:06X}", "width": width,
                         "value": f"0x{value:0{width * 2}X}", "count": count,
                         "function": containing(functions, pc)})
        result["writes"][f"0x{physical:06X}"] = rows
    for physical in sorted(reads):
        rows = []
        for pc, count in reads[physical].most_common(8):
            rows.append({"pc": f"0x{pc:06X}", "count": count,
                         "function": containing(functions, pc)})
        result["read_pcs"][f"0x{physical:06X}"] = rows
    print(json.dumps(result, indent=2, sort_keys=True))


def run_limit2(cpu, memory, engine_state, counter, c9d0):
    memory.write8(0x00C93C, engine_state)
    memory.write8(0x00C885, 0)
    memory.write8(0x00C886, 0)
    memory.write16(0x00C86A, counter)
    memory.write16(0x00C86C, 0)
    memory.write16(0x00C9D0, c9d0)
    memory.write16(0xE008AA, 0)
    memory.write16(0xE008B0, 0)
    memory.write8(0xE008A2, 0)
    cpu.csp = 0xC1
    cpu.ip = 0x1EB4
    cpu.push16(cpu.csp)
    cpu.push16(cpu.ip)
    cpu.csp = 0xC2
    cpu.ip = 0x01AE
    seen = set()
    start = cpu.steps
    while cpu.steps < start + 300_000 and cpu.stop_reason is None:
        if cpu.pc == 0xC11EB4:
            break
        seen.add(cpu.pc)
        cpu.step()
    return {
        "engine_state": engine_state,
        "counter_c86a": counter,
        "c9d0": f"0x{c9d0:04X}",
        "steps": cpu.steps - start,
        "stop": cpu.stop_reason,
        "unique_pcs": len(seen),
        "c885": f"0x{memory.read8(0x00C885):02X}",
        "xram_8a2": f"0x{memory.read8(0xE008A2):02X}",
        "xram_8aa": f"0x{memory.read16(0xE008AA):04X}",
        "xram_8b0": f"0x{memory.read16(0xE008B0):04X}",
    }


def cmd_limit2(args):
    data, regs, pcs, info = boot_snapshot()
    cases = []
    for state, counter, c9d0 in (
        (1, 0, 0x1450),
        (3, 159, 0x1450),
        (3, 160, 0x1000),
        (3, 160, 0x1450),
        (4, 160, 0x1450),
    ):
        cpu, memory, periph = restore(data, regs)
        cases.append(run_limit2(cpu, memory, state, counter, c9d0))
    print(json.dumps({
        "thresholds_from_flash": {
            "c07832": "0x00A0 (160)",
            "c07834": "0x0006 (6)",
            "c0781e": "0x1450",
        },
        "cases": cases,
    }, indent=2, sort_keys=True))


def cmd_scheduler_table(args):
    data, regs, pcs, info = boot_snapshot()
    cpu, memory, periph = restore(data, regs)
    memory.write16(0x00C584, 4)
    memory.data[0x00FD14] |= 0x04
    cpu.csp = 0xC1
    cpu.ip = 0x1CAE
    seen = set()
    start = cpu.steps
    while cpu.steps < start + 100_000 and cpu.stop_reason is None:
        if cpu.pc == 0xC11E94:
            break
        seen.add(cpu.pc)
        cpu.step()
    print(json.dumps({
        "table_logical": "0x705E",
        "table_physical": "0xC0B05E",
        "table_word": f"0x{memory.read16(0xC0B05E):04X}",
        "dispatched_pc": f"0x{cpu.pc:06X}",
        "steps": cpu.steps - start,
        "unique_pcs": len(seen),
        "stop": cpu.stop_reason,
    }, indent=2, sort_keys=True))


def cmd_tables(args):
    raw, info = load_dump(DUMP)
    mapping = {
        "0x7000": 0xC0B000,
        "0x705E": 0xC0B05E,
        "0x7084": 0xC0B084,
        "0x7086": 0xC0B086,
        "0x7088": 0xC0B088,
        "0x7090": 0xC0B090,
        "0x7092": 0xC0B092,
        "0x7094": 0xC0B094,
        "0x7096": 0xC0B096,
        "0x7098": 0xC0B098,
        "0x709A": 0xC0B09A,
        "0x709C": 0xC0B09C,
        "0x709E": 0xC0B09E,
        "0x7500": 0xC0B500,
        "0x750A": 0xC0B50A,
        "0x7510": 0xC0B510,
        "0x7552": 0xC0B552,
        "0x755E": 0xC0B55E,
        "0x7564": 0xC0B564,
        "0x7666": 0xC0B666,
    }
    result = {}
    for logical, physical in mapping.items():
        offset = physical - 0xC00000
        result[logical] = {
            "physical": f"0x{physical:06X}",
            "bytes": raw[offset:offset + 8].hex(),
            "first_word": f"0x{int.from_bytes(raw[offset:offset + 2], 'little'):04X}",
            "dpp_mapping": "DPP1=0x302 maps logical 0x4000..0x7FFF to 0xC08000..0xC0BFFF",
        }
    print(json.dumps(result, indent=2, sort_keys=True))


def main(argv=None):
    parser = argparse.ArgumentParser()
    sub = parser.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("boot")
    p.add_argument("--max-steps", type=int, default=3_000_000)
    p.set_defaults(func=cmd_boot)
    p = sub.add_parser("checksums")
    p.set_defaults(func=cmd_checksums)
    p = sub.add_parser("engine-state")
    p.add_argument("--steps", type=int, default=4_000_000)
    p.add_argument("--tick-every", type=int, default=1000)
    p.add_argument("--tick-amount", type=int, default=1)
    p.set_defaults(func=cmd_engine_state)
    p = sub.add_parser("limit2")
    p.set_defaults(func=cmd_limit2)
    p = sub.add_parser("scheduler-table")
    p.set_defaults(func=cmd_scheduler_table)
    p = sub.add_parser("tables")
    p.set_defaults(func=cmd_tables)
    args = parser.parse_args(argv)
    args.func(args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
