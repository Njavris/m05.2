"""Load and validate the MT05.2 flash image."""

from __future__ import annotations

import hashlib
from dataclasses import dataclass
from pathlib import Path


FLASH_BASE = 0xC00000
EXPECTED_SHA256 = "e413f54ffa1c2c53cedaa603dd9d572e4b5485310d83ab477332efbd933a37d2"

# (name, start, end_exclusive, checksum_address)
BLOCKS = (
    ("boot", 0xC00000, 0xC02000, 0xC01FFE),
    ("calibration", 0xC05000, 0xC0B000, 0xC0AFFE),
    ("application", 0xC0B000, 0xC40000, 0xC3FFFE),
)


class DumpError(Exception):
    pass


@dataclass
class DumpInfo:
    path: str
    size: int
    sha256: str
    checksums: dict[str, tuple[int, int]]

    @property
    def passes(self) -> bool:
        return all(stored == computed for computed, stored in self.checksums.values())


def checksum16_be(image: bytes | bytearray, start: int, end_exclusive: int) -> int:
    """Byte-swapped 16-bit word sum used by the boot and application blocks."""
    total = 0
    if start & 1:
        raise ValueError("checksum start must be even")
    for addr in range(start, end_exclusive, 2):
        lo = image[addr]
        hi = image[addr + 1] if addr + 1 < len(image) else 0
        total = (total + ((lo << 8) | hi)) & 0xFFFF
    return total


def load_dump(path: str | Path, *, verify: bool = True) -> tuple[bytes, DumpInfo]:
    raw = Path(path).read_bytes()
    if len(raw) != 0x40000:
        raise DumpError(f"expected 262144 bytes, got {len(raw)}")
    digest = hashlib.sha256(raw).hexdigest()
    offsets = {name: (start - FLASH_BASE, end - FLASH_BASE, csum - FLASH_BASE)
               for name, start, end, csum in BLOCKS}
    checksums: dict[str, tuple[int, int]] = {}
    for name, (start, end, csum) in offsets.items():
        computed = checksum16_be(raw, start, end - 2)
        stored = raw[csum] | (raw[csum + 1] << 8)
        checksums[name] = (computed, stored)
    info = DumpInfo(str(path), len(raw), digest, checksums)
    if verify:
        if digest != EXPECTED_SHA256:
            raise DumpError(
                f"dump SHA-256 mismatch: {digest} != {EXPECTED_SHA256}"
            )
        if not info.passes:
            details = ", ".join(
                f"{name}={computed:04X}/{stored:04X}"
                for name, (computed, stored) in checksums.items()
            )
            raise DumpError(f"stored checksum mismatch: {details}")
    return raw, info
