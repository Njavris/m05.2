"""C166 DPP / EXTP / EXTS address translation."""

from __future__ import annotations


class AddressSpace:
    """Translate 16-bit C166 logical addresses to 24-bit physical addresses.

    Two override mechanisms exist:

    * ``EXTP #page`` replaces the DPP page.  The resulting address is
      ``(page << 14) | (logical & 0x3FFF)``.  With a register form the low
      16 bits of the GPR are the page source.
    * ``EXTS #seg`` concatenates an 8-bit segment with the complete 16-bit
      logical address: ``(seg << 16) | logical``.

    Both overrides are active for a bounded number of following instructions,
    managed by the CPU.
    """

    def __init__(self):
        # After reset DPP0..3 = 0,1,2,3, which maps logical 0x0000..0xFFFF
        # one-to-one onto physical 0x000000..0x00FFFF.
        self.dpp = [0x0000, 0x0001, 0x0002, 0x0003]

    def set_dpp(self, index: int, value: int) -> None:
        self.dpp[index] = value & 0x3FF

    def get_dpp(self, index: int) -> int:
        return self.dpp[index]

    def translate(
        self,
        logical: int,
        *,
        extp: int | None = None,
        exts: int | None = None,
    ) -> int:
        logical &= 0xFFFF
        if exts is not None:
            return ((exts & 0xFF) << 16) | logical
        if extp is not None:
            return ((extp & 0x3FF) << 14) | (logical & 0x3FFF)
        page = self.dpp[(logical >> 14) & 3]
        return ((page & 0x3FF) << 14) | (logical & 0x3FFF)
