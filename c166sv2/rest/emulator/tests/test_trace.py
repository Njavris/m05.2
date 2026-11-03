import json
import tempfile
import unittest
from pathlib import Path

from emulator.c166.cpu import C166CPU
from emulator.c166.memory import Memory
from emulator.c166.peripherals import Peripherals
from emulator.tools.trace import Trace
from emulator.tests.common import boot_to_scheduler, fresh_cpu


class TraceTests(unittest.TestCase):
    def test_stop_after_and_trace_limit(self):
        cpu, memory, periph, raw, info = fresh_cpu()
        with tempfile.TemporaryDirectory() as tmp:
            trace = Trace(tmp, limit=25)
            cpu.tracer = trace
            memory.track_writes = True
            memory.write_trace = trace.on_write
            reason = cpu.run(max_steps=100)
            trace.stop(cpu, reason)
            summary = trace.write()
            self.assertEqual(reason, "step_limit")
            self.assertEqual(cpu.steps, 100)
            rows = list(csv_rows(Path(tmp) / "trace.csv"))
            self.assertEqual(len(rows), 1 + 25)
            self.assertTrue(summary["stats"]["trace_truncated"])

    def test_deterministic_trace_hash(self):
        hashes = []
        for _ in range(2):
            cpu, memory, periph, raw, info = fresh_cpu()
            with tempfile.TemporaryDirectory() as tmp:
                trace = Trace(tmp, limit=500)
                cpu.tracer = trace
                reason = cpu.run(max_steps=300)
                trace.stop(cpu, reason)
                summary = trace.write()
                hashes.append(summary["trace_sha256"])
        self.assertEqual(hashes[0], hashes[1])

    def test_invalid_pc_stops_cleanly(self):
        cpu, memory, periph, raw, info = fresh_cpu()
        cpu.csp = 0x40
        cpu.ip = 0x0000
        cpu.step()
        self.assertEqual(cpu.stop_reason, "memory_fault")
        self.assertIn("unmapped", cpu.stop_detail)

    def test_scheduler_tick_dispatch(self):
        cpu, memory, periph, info = boot_to_scheduler()
        # Force the K-line state into the task-table range and request a tick.
        memory.write16(0x00C584, 4)
        memory.data[0x00FD14] |= 0x04
        cpu.csp = 0xC1
        cpu.ip = 0x1CAE
        seen = set()
        for _ in range(100_000):
            if cpu.pc == 0xC11E94:
                break
            seen.add(cpu.pc)
            cpu.step()
            if cpu.stop_reason:
                break
        self.assertIsNone(cpu.stop_reason, cpu.stop_detail)
        self.assertEqual(cpu.pc, 0xC11E94)
        self.assertEqual(memory.read16(0xC0B05E), 0x1E94)


def csv_rows(path: Path):
    import csv
    with open(path, newline="", encoding="utf-8") as fh:
        yield from csv.reader(fh)


if __name__ == "__main__":
    unittest.main()
