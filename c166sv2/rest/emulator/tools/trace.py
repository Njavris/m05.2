"""Machine-readable trace writers."""

from __future__ import annotations

import csv
import hashlib
import json
import os
from dataclasses import dataclass, field
from pathlib import Path


def _sha256_text(lines: list[str]) -> str:
    digest = hashlib.sha256()
    for line in lines:
        digest.update(line.encode("utf-8"))
        digest.update(b"\n")
    return digest.hexdigest()


@dataclass
class TraceStats:
    steps: int = 0
    writes: int = 0
    reads: int = 0
    calls: int = 0
    coverage: int = 0
    trace_truncated: bool = False


class Trace:
    """Collects bounded CSV traces.

    ``limit`` bounds the number of instruction rows written to trace.csv.  The
    run is stopped by the caller when the bound is reached, so all outputs end
    at the same point.
    """

    def __init__(self, outdir: str | Path, limit: int = 200_000, functions=None):
        self.outdir = Path(outdir)
        self.outdir.mkdir(parents=True, exist_ok=True)
        self.limit = int(limit)
        self.functions = functions or {}
        self.stats = TraceStats()
        self._trace_rows: list[list[str]] = []
        self._coverage: dict[int, list[int]] = {}
        self._calls: list[list[str]] = []
        self._writes: list[list[str]] = []
        self._external: list[list[str]] = []
        self._watch: list[list[str]] = []
        self._stop: dict | None = None
        self._trace_truncated = False
        self._external_reads = False
        self.current_step = 0
        self.current_pc = 0

    # ------------------------------------------------------------------
    def on_step(self, info, cpu) -> None:
        self.stats.steps += 1
        self.current_step = info.step
        self.current_pc = info.pc
        pc = info.pc
        if pc not in self._coverage:
            length = max(2, cpu.instr_words * 2)
            try:
                raw = cpu.memory.flash_bytes(pc, pc + length).hex()
            except Exception:
                raw = ""
            self._coverage[pc] = [0, info.opcode, raw]
        self._coverage[pc][0] += 1
        if len(self._trace_rows) < self.limit:
            flags = (
                f"N{info.psw & 1}C{(info.psw >> 1) & 1}"
                f"V{(info.psw >> 2) & 1}Z{(info.psw >> 3) & 1}"
                f"E{(info.psw >> 4) & 1}"
            )
            d = info.dpp
            self._trace_rows.append([
                str(info.step),
                f"0x{info.pc:06X}",
                f"0x{info.opcode:04X}",
                info.mnemonic,
                f"0x{info.sp:04X}",
                f"0x{d[0]:04X}",
                f"0x{d[1]:04X}",
                f"0x{d[2]:04X}",
                f"0x{d[3]:04X}",
                flags,
            ])
        elif not self._trace_truncated:
            self._trace_truncated = True
            self.stats.trace_truncated = True

    def on_call(self, caller: int, kind: str, target: int, indirect: bool, cpu) -> None:
        self.stats.calls += 1
        name = self.functions.get(target, "")
        self._calls.append([
            str(cpu.steps),
            f"0x{caller:06X}",
            kind + ("*" if indirect else ""),
            f"0x{target:06X}",
            name,
        ])

    def on_write(self, address: int, width: int, value: int, source: str) -> None:
        self.stats.writes += 1
        step = self.current_step
        pc = self.current_pc
        if len(self._writes) < self.limit * 4:
            self._writes.append([
                str(step),
                f"0x{address:06X}",
                str(width),
                f"0x{value:0{width * 2}X}",
                f"0x{pc:06X}",
                source,
            ])
        if (0x000000 <= address < 0x008000
                or 0x00C000 <= address < 0x00D000
                or 0x00E000 <= address < 0x00E800
                or 0xE00000 <= address < 0xE10000):
            if len(self._external) < self.limit * 2:
                self._external.append([
                    str(step),
                    "write",
                    f"0x{address:06X}",
                    str(width),
                    f"0x{value:0{width * 2}X}",
                    f"0x{pc:06X}",
                ])

    def on_watch(self, access: str, logical, physical: int, width: int,
                 value: int, source: str, step: int, pc: int) -> None:
        self._watch.append([
            str(step),
            access,
            "" if logical is None else f"0x{logical:04X}",
            f"0x{physical:06X}",
            str(width),
            f"0x{value:0{width * 2}X}",
            f"0x{pc:06X}",
            source,
        ])

    def on_read(self, address: int, width: int, value: int, source: str) -> None:
        self.stats.reads += 1
        if (0x000000 <= address < 0x008000
                or 0x00C000 <= address < 0x00D000
                or 0x00E000 <= address < 0x00E800
                or 0xE00000 <= address < 0xE10000):
            if len(self._external) < self.limit * 2:
                self._external.append([
                    str(self.current_step),
                    "read",
                    f"0x{address:06X}",
                    str(width),
                    f"0x{value:0{width * 2}X}",
                    f"0x{self.current_pc:06X}",
                ])

    # ------------------------------------------------------------------
    def stop(self, cpu, reason: str | None = None, detail: str = "") -> None:
        self._stop = {
            "reason": reason or cpu.stop_reason or "unknown",
            "detail": detail or cpu.stop_detail,
            "pc": f"0x{cpu.pc:06X}",
            "steps": cpu.steps,
            "registers": cpu.register_dump(),
            "trace_rows": len(self._trace_rows),
            "trace_limit": self.limit,
            "coverage_unique": len(self._coverage),
            "peripheral_summary": (
                cpu.peripherals.summary() if cpu.peripherals is not None else {}
            ),
        }

    # ------------------------------------------------------------------
    def write(self) -> dict:
        # trace.csv
        with open(self.outdir / "trace.csv", "w", newline="", encoding="utf-8") as fh:
            writer = csv.writer(fh)
            writer.writerow(["step", "pc", "opcode", "mnemonic", "sp",
                             "dpp0", "dpp1", "dpp2", "dpp3", "flags"])
            writer.writerows(self._trace_rows)

        # coverage.csv
        with open(self.outdir / "coverage.csv", "w", newline="", encoding="utf-8") as fh:
            writer = csv.writer(fh)
            writer.writerow(["pc", "exec_count", "opcode", "bytes"])
            for pc in sorted(self._coverage):
                count, opcode, raw = self._coverage[pc]
                writer.writerow([f"0x{pc:06X}", count, f"0x{opcode:04X}", raw])

        # calls.csv
        with open(self.outdir / "calls.csv", "w", newline="", encoding="utf-8") as fh:
            writer = csv.writer(fh)
            writer.writerow(["step", "caller_pc", "call_type", "target_pc", "name"])
            writer.writerows(self._calls)

        # mem_writes.csv
        with open(self.outdir / "mem_writes.csv", "w", newline="", encoding="utf-8") as fh:
            writer = csv.writer(fh)
            writer.writerow(["step", "address", "width", "value", "pc", "kind"])
            writer.writerows(self._writes)

        # external_ram.csv
        with open(self.outdir / "external_ram.csv", "w", newline="", encoding="utf-8") as fh:
            writer = csv.writer(fh)
            writer.writerow(["step", "access", "address", "width", "value", "pc"])
            writer.writerows(self._external)

        # watch.csv
        with open(self.outdir / "watch.csv", "w", newline="", encoding="utf-8") as fh:
            writer = csv.writer(fh)
            writer.writerow(["step", "access", "logical", "physical", "width",
                             "value", "pc", "kind"])
            writer.writerows(self._watch)

        # stops.json
        stop = self._stop or {}
        with open(self.outdir / "stops.json", "w", encoding="utf-8") as fh:
            json.dump(stop, fh, indent=2, sort_keys=True)
            fh.write("\n")

        # Deterministic digest over the trace rows (independent of CSV header).
        trace_hash = _sha256_text([",".join(row) for row in self._trace_rows])
        summary = {
            "stats": {
                "steps": self.stats.steps,
                "writes": self.stats.writes,
                "calls": self.stats.calls,
                "coverage_unique": len(self._coverage),
                "trace_rows": len(self._trace_rows),
                "trace_limit": self.limit,
                "trace_truncated": self._trace_truncated,
            },
            "trace_sha256": trace_hash,
            "stop": stop,
            "outputs": [
                "trace.csv", "coverage.csv", "calls.csv",
                "mem_writes.csv", "external_ram.csv", "watch.csv", "stops.json",
            ],
        }
        with open(self.outdir / "summary.json", "w", encoding="utf-8") as fh:
            json.dump(summary, fh, indent=2, sort_keys=True)
            fh.write("\n")
        return summary

    # ------------------------------------------------------------------
    def coverage_pcs(self) -> set[int]:
        return set(self._coverage)


def load_function_names(path: str | Path) -> dict[int, str]:
    """Load a Ghidra-style functions CSV (address,name,...)."""
    names: dict[int, str] = {}
    path = Path(path)
    if not path.exists():
        return names
    with open(path, newline="", encoding="utf-8") as fh:
        reader = csv.reader(fh)
        for row in reader:
            if not row or not row[0]:
                continue
            try:
                address = int(row[0], 16)
            except ValueError:
                try:
                    address = int(row[0], 0)
                except ValueError:
                    continue
            if len(row) > 1 and row[1]:
                names[address] = row[1]
    return names
