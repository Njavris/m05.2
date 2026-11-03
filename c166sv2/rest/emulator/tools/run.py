#!/usr/bin/env python3
"""Command-line driver for the MT05.2 C166 emulator."""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from emulator.c166.cpu import C166CPU
from emulator.c166.loader import load_dump
from emulator.c166.memory import Memory
from emulator.c166.peripherals import Peripherals
from emulator.tools.trace import Trace, load_function_names


REPO = Path(__file__).resolve().parents[4]
DEFAULT_DUMP = REPO / "dumps" / "mash_dump.bin"
DEFAULT_SYMBOLS = REPO / "c166sv2" / "rest" / "artifacts" / "ghidra-full" / "functions.csv"
DEFAULT_STOPS = {0xC11EB4}  # app_scheduler


def parse_int(text: str) -> int:
    return int(text, 0)


def build(args) -> tuple[C166CPU, Trace | None, object]:
    dump, info = load_dump(args.dump, verify=not args.no_verify)
    external_image = None
    if args.external_image:
        external_image = Path(args.external_image).read_bytes()
    memory = Memory(fill=args.fill, external_image=external_image)
    memory.load_flash(dump)
    periph = Peripherals()
    for spec in args.adc:
        channel, _, value = spec.partition("=")
        if not _:
            raise SystemExit(f"bad --adc {spec!r}; expected CHANNEL=VALUE")
        periph.set_adc(int(channel, 0), int(value, 0))
    cpu = C166CPU(memory, periph)
    cpu.reset()
    for spec in args.set_physical:
        address, _, value = spec.partition("=")
        if not _:
            raise SystemExit(f"bad --set-physical {spec!r}; expected ADDR=VALUE")
        memory.write16(int(address, 0) & 0xFFFFFF, int(value, 0) & 0xFFFF)
    for spec in args.set_logical:
        address, _, value = spec.partition("=")
        if not _:
            raise SystemExit(f"bad --set-logical {spec!r}; expected ADDR=VALUE")
        logical = int(address, 0) & 0xFFFF
        physical = cpu.physical(logical)
        memory.write16(physical, int(value, 0) & 0xFFFF)

    names = load_function_names(args.symbols) if args.symbols else {}
    tracer = None
    if not args.no_trace:
        tracer = Trace(args.out, limit=args.trace_limit, functions=names)
        cpu.tracer = tracer
        memory.track_writes = True
        memory.write_trace = tracer.on_write
        memory.window_read_trace = tracer.on_read
        if args.trace_reads:
            memory.read_trace = tracer.on_read
            memory.track_reads = True
    cpu.watch_logical = {parse_int(x) & 0xFFFF for x in args.watch}
    cpu.watch_physical = {parse_int(x) & 0xFFFFFF for x in args.watch_phys}
    if tracer is not None:
        cpu.watch_cb = tracer.on_watch

    injections = {}
    for logical, specs in ((False, args.inject_physical),
                           (True, args.inject_logical)):
        for spec in specs:
            try:
                at, _, rest = spec.partition(":")
                address, _, value = rest.partition("=")
                step = parse_int(at)
                addr = parse_int(address)
                val = parse_int(value)
            except ValueError:
                raise SystemExit(
                    f"bad injection {spec!r}; expected STEP:ADDR=VALUE")
            injections.setdefault(step, []).append((logical, addr, val))
    if injections:
        def pre_step(cpu):
            for logical, addr, val in injections.get(cpu.steps, ()):
                phys = cpu.physical(addr & 0xFFFF) if logical else (addr & 0xFFFFFF)
                cpu.memory.write16(phys, val & 0xFFFF)
        cpu.pre_step_hook = pre_step
    return cpu, tracer, info


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(
        description="Offline C166SV2 emulator for the Delphi MT05.2 dump",
    )
    parser.add_argument("--dump", default=str(DEFAULT_DUMP))
    parser.add_argument("--out", default=str(REPO / "c166sv2" / "rest" / "emulator" / "out" / "run"))
    parser.add_argument("--reset", action="store_true",
                        help="start from the reset vector (default)")
    parser.add_argument("--stop-after", type=parse_int, default=3_000_000,
                        help="maximum instructions to execute")
    parser.add_argument("--trace-limit", type=int, default=200_000,
                        help="maximum rows written to trace.csv")
    parser.add_argument("--stop-at", action="append", default=[],
                        help="stop when PC reaches this address (hex or decimal)")
    parser.add_argument("--no-default-stops", action="store_true",
                        help="do not stop automatically at app_scheduler")
    parser.add_argument("--tick-every", type=int, default=0,
                        help="inject N timer ticks every N instructions")
    parser.add_argument("--tick-amount", type=int, default=1)
    parser.add_argument("--fill", type=lambda x: int(x, 0), default=0,
                        help="fill byte for RAM/external memory (default 0)")
    parser.add_argument("--external-image",
                        help="optional image for physical 0x000000..0x007FFF")
    parser.add_argument("--adc", action="append", default=[],
                        help="virtual ADC channel=value, e.g. --adc 0=512")
    parser.add_argument("--set-physical", action="append", default=[],
                        help="preload a physical RAM word: ADDR=VALUE")
    parser.add_argument("--set-logical", action="append", default=[],
                        help="preload a DPP-translated logical RAM word: ADDR=VALUE")
    parser.add_argument("--inject-physical", action="append", default=[],
                        help="timed physical RAM write: STEP:ADDR=VALUE")
    parser.add_argument("--inject-logical", action="append", default=[],
                        help="timed logical RAM write: STEP:ADDR=VALUE")
    parser.add_argument("--watch", action="append", default=[],
                        help="watch a logical data address (hex or decimal)")
    parser.add_argument("--watch-phys", action="append", default=[],
                        help="watch a physical data address")
    parser.add_argument("--trace-reads", action="store_true",
                        help="also trace memory reads to external_ram.csv")
    parser.add_argument("--no-trace", action="store_true")
    parser.add_argument("--no-verify", action="store_true",
                        help="skip dump SHA/checksum validation")
    parser.add_argument("--symbols", default=str(DEFAULT_SYMBOLS))
    parser.add_argument("--stop-on-idle", action="store_true")
    parser.add_argument("--loop-after", type=int, default=0,
                        help="stop after one PC executes this many times")
    parser.add_argument("--compare-static", action="store_true",
                        help="compare dynamic PCs with the 1,277-function list")
    parser.add_argument("--json", action="store_true", help="print summary JSON")
    parser.add_argument("--quiet", action="store_true")
    args = parser.parse_args(argv)

    cpu, tracer, info = build(args)
    stops = set()
    if not args.no_default_stops:
        stops |= DEFAULT_STOPS
    stops |= {parse_int(value) for value in args.stop_at}

    reason = cpu.run(
        max_steps=args.stop_after,
        stop_pcs=stops,
        stop_on_idle=args.stop_on_idle,
        stop_on_loop_after=args.loop_after,
        tick_every=args.tick_every,
        tick_amount=args.tick_amount,
    )
    if tracer:
        tracer.stop(cpu, reason)
        summary = tracer.write()
    else:
        summary = {"stop": {"reason": reason, "pc": f"0x{cpu.pc:06X}"}}

    if not args.quiet:
        st = summary.get("stop", {})
        print(f"dump:      {info.path}")
        print(f"sha256:    {info.sha256}")
        print(f"checksums: " + ", ".join(
            f"{name}={computed:04X}/{stored:04X}"
            for name, (computed, stored) in info.checksums.items()))
        print(f"stop:      {st.get('reason')} at {st.get('pc')} "
              f"after {cpu.steps} steps")
        if st.get("detail"):
            print(f"detail:    {st['detail']}")
        if tracer:
            print(f"outputs:   {tracer.outdir}")
            print(f"trace sha: {summary.get('trace_sha256')}")
            print(f"unique PC: {len(tracer.coverage_pcs())}")
        for address in sorted(tracer.coverage_pcs()) if tracer else []:
            if address in (0xC00200, 0xC0037E, 0xC0FFDE, 0xC10000,
                           0xC11AA0, 0xC11EB4, 0xC11CAE):
                print(f"reached:   0x{address:06X}")

    if args.compare_static and tracer:
        static = load_function_names(args.symbols)
        dynamic = tracer.coverage_pcs()
        reached_entries = sorted(set(static) & dynamic)
        # Count a function as dynamically touched when any executed PC falls
        # inside its static body range.  This is more robust than exact-entry
        # matching because tail calls and switch entries do not always align
        # with CSV entry points.
        functions = []
        with open(args.symbols, newline="", encoding="utf-8") as fh:
            import csv
            for row in csv.DictReader(fh):
                try:
                    address = int(row["address"], 16)
                    size = int(row["size"])
                except (KeyError, ValueError):
                    continue
                functions.append((address, max(size, 2), row["name"]))
        touched = []
        for address, size, name in functions:
            hits = [pc for pc in dynamic if address <= pc < address + size]
            if hits:
                touched.append({"address": f"0x{address:06X}",
                                "name": name, "hits": len(hits)})
        missed = sorted(set(static) - set(reached_entries))
        print(f"static functions: {len(static)}")
        print(f"dynamic PCs:      {len(dynamic)}")
        print(f"static reached:   {len(reached_entries)}")
        print(f"functions touched:{len(touched)}")
        result = {
            "static_functions": len(static),
            "static_rows": len(functions),
            "dynamic_pcs": len(dynamic),
            "static_entries_reached": len(reached_entries),
            "static_functions_touched": len(touched),
            "static_functions_not_touched": len(functions) - len(touched),
            "reached_examples": [f"0x{x:06X}" for x in reached_entries[:100]],
            "touched": touched,
        }
        out = Path(args.out) / "static_compare.json"
        out.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n")

    if args.json:
        print(json.dumps(summary, indent=2, sort_keys=True))
    return 0 if reason in ("stop_address", "idle", "step_limit",
                           "software_reset", "infinite_loop") else 1


if __name__ == "__main__":
    raise SystemExit(main())
