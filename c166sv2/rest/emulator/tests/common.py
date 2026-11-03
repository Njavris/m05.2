"""Shared test helpers."""

from __future__ import annotations

from pathlib import Path

from emulator.c166.cpu import C166CPU
from emulator.c166.loader import load_dump
from emulator.c166.memory import Memory
from emulator.c166.peripherals import Peripherals

REPO = Path(__file__).resolve().parents[2]
DUMP = REPO / "dumps" / "mash_dump.bin"

_BOOT_CACHE = None


def fresh_cpu(*, load_flash: bool = True):
    raw, info = load_dump(DUMP)
    memory = Memory(fill=0)
    if load_flash:
        memory.load_flash(raw)
    periph = Peripherals()
    cpu = C166CPU(memory, periph)
    cpu.reset()
    return cpu, memory, periph, raw, info


def call_subroutine(cpu: C166CPU, csp: int, ip: int,
                    return_csp: int = 0xC1, return_ip: int = 0x1EB4) -> None:
    """Enter a routine as a CALLS would, returning to a sentinel address."""
    cpu.csp = return_csp
    cpu.ip = return_ip
    cpu.push16(cpu.csp)
    cpu.push16(cpu.ip)
    cpu.csp = csp
    cpu.ip = ip


def boot_to_scheduler():
    """Run the image from reset to app_scheduler once per process.

    Returns an immutable-ish snapshot: fresh CPU primed with the same memory
    contents and architectural registers.  Shared by boot/scheduler tests so
    the 2.2M-step boot checksum is not repeated.
    """
    global _BOOT_CACHE
    if _BOOT_CACHE is None:
        cpu, memory, periph, raw, info = fresh_cpu()
        reason = cpu.run(max_steps=3_000_000, stop_pcs={0xC11EB4})
        if reason != "stop_address":
            raise AssertionError(
                f"boot did not reach app_scheduler: {reason} "
                f"{cpu.stop_detail} at 0x{cpu.pc:06X}"
            )
        pcs = set(cpu._pc_hits)
        pcs.add(cpu.pc)
        _BOOT_CACHE = (bytes(memory.data), cpu.register_dump(), pcs, info)
    data, regs, pcs, info = _BOOT_CACHE
    memory = Memory(fill=0)
    memory.data[:] = data
    periph = Peripherals()
    cpu = C166CPU(memory, periph)
    cpu.reset()
    for attr in ("psw", "cp", "sp", "csp", "ip", "md", "mdc"):
        setattr(cpu, attr, regs[attr])
    cpu.dpp[:] = regs["dpp"]
    cpu._boot_pcs = pcs
    return cpu, memory, periph, info
