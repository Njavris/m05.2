"""Physical memory model for the Infineon XC164CS (C166SV2).

The C166 uses a 24-bit physical address space.  Firmware operands are 16-bit
*logical* addresses that are translated through the DPP registers; this module
only deals with physical addresses.  Translation lives in :mod:`dpp` and is
applied by the CPU before every memory access.

The model deliberately maps whole windows rather than modelling silicon at
cycle level.  Everything outside a mapped window raises :class:`MemoryFault`
so that a wild pointer stops the emulator cleanly instead of silently reading
zeroes.
"""

from __future__ import annotations

from dataclasses import dataclass


class MemoryFault(Exception):
    """Raised for an access outside a mapped window or a flash write."""

    def __init__(self, address: int, width: int, write: bool, reason: str):
        self.address = address
        self.width = width
        self.write = write
        self.reason = reason
        super().__init__(f"{reason} at 0x{address:06X} (width {width})")


@dataclass(frozen=True)
class Region:
    start: int
    end: int
    name: str
    writable: bool
    executable: bool = False


# Physical address windows used by this firmware / XC164CS.
REGIONS = (
    Region(0x000000, 0x008000, "external_ram", True),
    Region(0x008000, 0x010000, "internal_ram_sfr", True),
    Region(0x200000, 0x200800, "twincan", True),
    Region(0x200800, 0x400000, "external_io", True),
    # The boot code addresses RAM as segment 0xE0, offset 0x07FC with EXTS
    # (physical 0xE007FC).  The analysis docs call this XRAM; the exact
    # silicon mapping is an assumption documented in FINDINGS.md.
    Region(0xE00000, 0xE10000, "xram_seg_e0", True),
    Region(0xC00000, 0xC02000, "flash_boot", False, True),
    Region(0xC02000, 0xC04000, "flash_boot_unused", False, True),
    Region(0xC04000, 0xC05000, "flash_adaptation", False, True),
    Region(0xC05000, 0xC0B000, "flash_calibration", False, True),
    Region(0xC0B000, 0xC40000, "flash_application", False, True),
)

FLASH_START = 0xC00000
FLASH_END = 0xC40000


def region_for(address: int) -> Region | None:
    for region in REGIONS:
        if region.start <= address < region.end:
            return region
    return None


class Memory:
    """A 16 MiB byte array plus optional peripheral read/write hooks."""

    def __init__(self, fill: int = 0x00, external_image: bytes | None = None):
        if not 0 <= fill <= 0xFF:
            raise ValueError("fill byte must be 0..255")
        self.data = bytearray(b"\x00" * 0x1000000)
        self.fill = fill
        self._initialise(fill, external_image)
        # Optional object implementing read8/read16/read32/write8/write16.
        self.peripherals = None
        self.read_trace = None
        self.write_trace = None
        self.window_read_trace = None
        self.track_reads = False
        self.track_writes = False
        self.access_errors: list[str] = []

    # ------------------------------------------------------------------
    def _initialise(self, fill: int, external_image: bytes | None) -> None:
        for region in REGIONS:
            if region.name.startswith("flash"):
                continue
            start, end = region.start, region.end
            if region.name == "external_ram" and external_image is not None:
                size = min(end - start, len(external_image))
                self.data[start:start + size] = external_image[:size]
                self.data[start + size:end] = bytes([fill]) * (end - start - size)
            else:
                self.data[start:end] = bytes([fill]) * (end - start)

    # ------------------------------------------------------------------
    def load_flash(self, image: bytes, base: int = FLASH_START) -> None:
        if base < FLASH_START or base + len(image) > FLASH_END:
            raise ValueError("flash image outside flash window")
        self.data[base:base + len(image)] = image

    def flash_bytes(self, start: int = FLASH_START, end: int = FLASH_END) -> bytes:
        return bytes(self.data[start:end])

    # ------------------------------------------------------------------
    def _check(self, address: int, width: int, write: bool) -> Region:
        if address < 0 or address + width > 0x1000000:
            raise MemoryFault(address, width, write, "address outside 24-bit space")
        region = region_for(address)
        if region is None:
            raise MemoryFault(address, width, write, "unmapped physical address")
        if address + width > region.end:
            raise MemoryFault(address, width, write, "access crosses region boundary")
        if write and not region.writable:
            raise MemoryFault(address, width, write, "write to read-only region")
        return region

    @staticmethod
    def _is_data_window(address: int) -> bool:
        return (
            0x000000 <= address < 0x008000
            or 0x00C000 <= address < 0x00D000
            or 0x00E000 <= address < 0x00E800
            or 0xE00000 <= address < 0xE10000
        )

    def _is_peripheral(self, address: int) -> bool:
        return (
            0x00F000 <= address < 0x00F200
            or 0x00FE00 <= address < 0x010000
            or 0x200000 <= address < 0x200800
        )

    # ------------------------------------------------------------------
    def read8(self, address: int, source: str = "") -> int:
        address &= 0xFFFFFF
        self._check(address, 1, False)
        if self.peripherals is not None and self._is_peripheral(address):
            value = self.peripherals.read8(address)
        else:
            value = self.data[address]
        if self.track_reads and self.read_trace is not None:
            self.read_trace(address, 1, value, source)
        elif self.window_read_trace is not None and self._is_data_window(address):
            self.window_read_trace(address, 1, value, source)
        return value

    def read16(self, address: int, source: str = "") -> int:
        address &= 0xFFFFFF
        self._check(address, 2, False)
        if address & 1:
            raise MemoryFault(address, 2, False, "odd word access")
        if self.peripherals is not None and self._is_peripheral(address):
            value = self.peripherals.read16(address)
        else:
            value = self.data[address] | (self.data[address + 1] << 8)
        if self.track_reads and self.read_trace is not None:
            self.read_trace(address, 2, value, source)
        elif self.window_read_trace is not None and self._is_data_window(address):
            self.window_read_trace(address, 2, value, source)
        return value & 0xFFFF

    def write8(self, address: int, value: int, source: str = "") -> None:
        address &= 0xFFFFFF
        value &= 0xFF
        self._check(address, 1, True)
        if self.peripherals is not None and self._is_peripheral(address):
            self.peripherals.write8(address, value)
        else:
            self.data[address] = value
        if self.track_writes and self.write_trace is not None:
            self.write_trace(address, 1, value, source)

    def write16(self, address: int, value: int, source: str = "") -> None:
        address &= 0xFFFFFF
        value &= 0xFFFF
        self._check(address, 2, True)
        if address & 1:
            raise MemoryFault(address, 2, True, "odd word access")
        if self.peripherals is not None and self._is_peripheral(address):
            self.peripherals.write16(address, value)
        else:
            self.data[address] = value & 0xFF
            self.data[address + 1] = (value >> 8) & 0xFF
        if self.track_writes and self.write_trace is not None:
            self.write_trace(address, 2, value, source)

    # Raw access used only by the loader / tests.
    def poke16(self, address: int, value: int) -> None:
        self.data[address] = value & 0xFF
        self.data[address + 1] = (value >> 8) & 0xFF

    def peek16(self, address: int) -> int:
        return self.data[address] | (self.data[address + 1] << 8)
