"""Deterministic peripheral stubs for the XC164CS.

These are not silicon models.  They provide the observable register state the
firmware needs, plus a small injectable stimulus API.  Every behaviour that is
an assumption is marked as such in the README/FINDINGS files.
"""

from __future__ import annotations


class Peripherals:
    # XC164CS SFR / ESFR addresses used by the firmware.
    DPP0 = 0xFE00
    DPP3 = 0xFE06
    CSP = 0xFE08
    MDH = 0xFE0C
    MDL = 0xFE0E
    CP = 0xFE10
    SP = 0xFE12
    STKOV = 0xFE14
    STKUN = 0xFE16
    PSW = 0xFF10
    MDC = 0xFF0E
    ZEROS = 0xFF1C
    ONES = 0xFF1E
    SYSCON = 0xFF12
    WDTCON = 0xFFAE
    ADCIC = 0xFF98
    ADEIC = 0xFF9A
    ADCON = 0xFFBE
    ADDAT = 0xFEA0
    P5DIDIS = 0xFFA4
    T7 = 0xF050
    T8 = 0xF052
    T7REL = 0xF054
    T8REL = 0xF056
    T7IC = 0xF17A

    # Firmware scheduler flag (logical 0xFD14, physical 0x00FD14).
    SCHED_FLAG = 0x00FD14

    def __init__(self):
        self.cpu = None
        # Generic SFR bytes.  Only addresses in the SFR/ESFR window are used.
        self.sfr = bytearray(0x10000)
        self.can = bytearray(0x800)
        self.watchdog_enabled = True
        self.watchdog_serviced = 0
        self.watchdog_resets = 0
        self.watchdog_initialised = False
        self.watchdog_disabled = False
        self.adc_values: dict[int, int] = {}
        self.adc_channel = 0
        self.adc_starts = 0
        self.adc_ready = False
        self.timer_ticks = 0
        self.timer7_period = 1
        self.timer7_counter = 0
        self.timer7_running = False
        self.timer7_reload = 0
        self.timer7_requests = 0
        self.scheduler_flag_writes = 0
        self.asc0_tx: list[int] = []
        self.asc0_rx: list[int] = []
        self.ssc_tx: list[int] = []
        self.ssc_rx: list[int] = []
        self.can_tx: list[tuple[int, bytes]] = []
        self.can_rx: list[tuple[int, bytes]] = []
        self.port_writes: list[tuple[int, int, int]] = []
        self.sfr_writes: list[tuple[int, int, int]] = []
        self.unknown_sfr_writes: list[tuple[int, int]] = []
        self.stub_notes: list[str] = []
        self._set_adc_defaults()
        # Power-on/self-calibration complete flag consumed by adc_calibrate().
        # The real bit is produced by the ADC state machine; offline it is an
        # explicit deterministic stub.
        self.sfr[0xF110] = 0x00
        self.sfr[0xF111] = 0x80

    # ------------------------------------------------------------------
    def _set_adc_defaults(self) -> None:
        # 0x200 (512 of 1023) makes every boot ADC threshold test take the
        # "normal application" branch.  This is an explicitly documented
        # assumption, not data from the dump.
        for channel in range(16):
            self.adc_values[channel] = 0x200

    def set_adc(self, channel: int, value10: int) -> None:
        if not 0 <= channel <= 15:
            raise ValueError("ADC channel 0..15")
        self.adc_values[channel] = max(0, min(0x3FF, value10))

    # ------------------------------------------------------------------
    def _cpu_reg_get(self, address: int) -> int:
        cpu = self.cpu
        if address in (self.DPP0, self.DPP0 + 2, self.DPP0 + 4, self.DPP0 + 6):
            return cpu.dpp[(address - self.DPP0) // 2]
        if address == self.CSP:
            return cpu.csp
        if address == self.MDH:
            return (cpu.md >> 16) & 0xFFFF
        if address == self.MDL:
            return cpu.md & 0xFFFF
        if address == self.MDC:
            return cpu.mdc
        if address == self.CP:
            return cpu.cp
        if address == self.SP:
            return cpu.sp
        if address == self.PSW:
            return cpu.psw
        return None

    def _cpu_reg_set(self, address: int, value: int) -> bool:
        cpu = self.cpu
        if address in (self.DPP0, self.DPP0 + 2, self.DPP0 + 4, self.DPP0 + 6):
            cpu.dpp[(address - self.DPP0) // 2] = value & 0x3FF
            return True
        if address == self.CSP:
            cpu.csp = value & 0xFF
            return True
        if address == self.MDH:
            cpu.md = (cpu.md & 0x0000FFFF) | ((value & 0xFFFF) << 16)
            return True
        if address == self.MDL:
            cpu.md = (cpu.md & 0xFFFF0000) | (value & 0xFFFF)
            return True
        if address == self.MDC:
            cpu.mdc = value & 0xFFFF
            return True
        if address == self.CP:
            cpu.cp = value & 0xFFFF
            return True
        if address == self.SP:
            cpu.sp = value & 0xFFFF
            return True
        if address == self.PSW:
            cpu.psw = value & 0xFFFF
            return True
        return False

    # ------------------------------------------------------------------
    def read8(self, address: int) -> int:
        if address >= 0x200000:
            offset = address - 0x200000
            return self.can[offset] if 0 <= offset < len(self.can) else 0
        address &= 0xFFFF
        if address == self.ZEROS:
            return 0
        if address == self.ONES:
            return 0xFF
        if address in (self.MDH, self.MDL, self.MDC, self.CP, self.SP,
                       self.PSW, self.DPP0, self.DPP0 + 2, self.DPP0 + 4,
                       self.DPP0 + 6, self.CSP):
            value = self._cpu_reg_get(address)
            return (value >> (8 * (address & 1))) & 0xFF
        if address & 1:
            # High byte of an SFR word.  Read the low-byte storage's sibling.
            low_addr = address & ~1
            return self._sfr_read16(low_addr) >> 8
        return self._sfr_read16(address) & 0xFF

    def read16(self, address: int) -> int:
        if address >= 0x200000:
            offset = address - 0x200000
            if 0 <= offset + 1 < len(self.can):
                return self.can[offset] | (self.can[offset + 1] << 8)
            return 0
        address &= 0xFFFE
        if address == self.ZEROS:
            return 0
        if address == self.ONES:
            return 0xFFFF
        if address == self.ADDAT:
            return (self.adc_values.get(self.adc_channel, 0) & 0x3FF) << 2
        if address == self.ADCIC:
            value = self.sfr[address] | (self.sfr[address + 1] << 8)
            if self.adc_ready:
                value |= 0x0080
            return value & 0xFFFF
        if address == self.ADCON:
            value = self.sfr[address] | (self.sfr[address + 1] << 8)
            return value & ~0x0080 & 0xFFFF
        if address in (self.MDH, self.MDL, self.MDC, self.CP, self.SP,
                       self.PSW, self.DPP0, self.DPP0 + 2, self.DPP0 + 4,
                       self.DPP0 + 6, self.CSP):
            return self._cpu_reg_get(address) & 0xFFFF
        if address == self.T7:
            return self.timer7_counter & 0xFFFF
        return self._sfr_read16(address)

    def _sfr_read16(self, address: int) -> int:
        if 0x200000 <= address:
            return self._can_read16(address)
        return self.sfr[address] | (self.sfr[address + 1] << 8)

    # ------------------------------------------------------------------
    def write8(self, address: int, value: int) -> None:
        if address >= 0x200000:
            offset = address - 0x200000
            if 0 <= offset < len(self.can):
                self.can[offset] = value & 0xFF
            return
        address &= 0xFFFF
        value &= 0xFF
        if address in (self.ZEROS, self.ONES):
            return
        if address in (self.MDH, self.MDL, self.MDC, self.CP, self.SP,
                       self.PSW, self.DPP0, self.DPP0 + 2, self.DPP0 + 4,
                       self.DPP0 + 6, self.CSP):
            old = self._cpu_reg_get(address)
            self._cpu_reg_set(address, (old & 0xFF00) | value)
            return
        low_addr = address & ~1
        old = self._sfr_read16(low_addr)
        if address & 1:
            new = (old & 0x00FF) | (value << 8)
        else:
            new = (old & 0xFF00) | value
        self.write16(low_addr, new)

    def write16(self, address: int, value: int) -> None:
        if address >= 0x200000:
            offset = address - 0x200000
            if 0 <= offset + 1 < len(self.can):
                self.can[offset] = value & 0xFF
                self.can[offset + 1] = (value >> 8) & 0xFF
            return
        address &= 0xFFFE
        value &= 0xFFFF
        if address in (self.ZEROS, self.ONES):
            return
        if address in (self.MDH, self.MDL, self.MDC, self.CP, self.SP,
                       self.PSW, self.DPP0, self.DPP0 + 2, self.DPP0 + 4,
                       self.DPP0 + 6, self.CSP):
            self._cpu_reg_set(address, value)
            return
        if address == self.ADCON:
            self.sfr[address] = value & 0xFF
            self.sfr[address + 1] = (value >> 8) & 0xFF
            if value & 0x80:
                self.start_adc(value & 0x0F)
            return
        if address == self.ADCIC:
            self.sfr[address] = value & 0xFF
            self.sfr[address + 1] = (value >> 8) & 0xFF
            if not (value & 0x0080):
                self.adc_ready = False
            return
        if address == self.WDTCON:
            self.sfr[address] = value & 0xFF
            self.sfr[address + 1] = (value >> 8) & 0xFF
            self.watchdog_initialised = True
            return
        if address == self.T7:
            self.timer7_counter = value
            self.sfr[address] = value & 0xFF
            self.sfr[address + 1] = (value >> 8) & 0xFF
            return
        if address == self.T7REL:
            self.timer7_reload = value
            self.sfr[address] = value & 0xFF
            self.sfr[address + 1] = (value >> 8) & 0xFF
            return
        if address == self.ADDAT:
            self.sfr[address] = value & 0xFF
            self.sfr[address + 1] = (value >> 8) & 0xFF
            return
        if address >= 0xFF00:
            # Ports and generic SFRs: record the write for analysis.
            self.port_writes.append((address, value, self.cpu.pc if self.cpu else 0))
            self.sfr[address] = value & 0xFF
            self.sfr[address + 1] = (value >> 8) & 0xFF
            return
        if 0x200000 <= address:
            self._can_write16(address, value)
            return
        self.sfr[address] = value & 0xFF
        self.sfr[address + 1] = (value >> 8) & 0xFF

    # ------------------------------------------------------------------
    def start_adc(self, channel: int) -> None:
        self.adc_channel = channel & 0x0F
        self.adc_starts += 1
        # Conversion completes immediately in the model.
        self.adc_ready = True

    def service_watchdog(self) -> None:
        self.watchdog_serviced += 1

    def disable_watchdog(self) -> None:
        if not self.watchdog_initialised or self.watchdog_disabled:
            self.watchdog_disabled = True
        self.watchdog_enabled = False

    def init_watchdog(self) -> None:
        self.watchdog_enabled = not self.watchdog_disabled

    def timer_tick(self, count: int = 1) -> None:
        """Advance the stub 1 ms timer and request the scheduler flag.

        The real flag is set by an application interrupt handler, not by
        Timer 7 itself.  For a deterministic offline run the same observable
        effect is produced here.
        """
        for _ in range(count):
            self.timer_ticks += 1
            self.timer7_counter = (self.timer7_counter + 1) & 0xFFFF
            self.timer7_requests += 1
            if self.cpu is not None:
                address = self.SCHED_FLAG
                self.cpu.memory.data[address] |= 0x04
                self.scheduler_flag_writes += 1

    # ------------------------------------------------------------------
    def _can_read16(self, address: int) -> int:
        # Minimal TwinCAN register file: store written values and expose zero
        # for message objects until a CAN frame is injected.
        offset = address - 0x200000
        if 0 <= offset + 1 < len(self.sfr):
            return self.sfr[offset] | (self.sfr[offset + 1] << 8)
        return 0

    def _can_write16(self, address: int, value: int) -> None:
        offset = address - 0x200000
        if 0 <= offset + 1 < len(self.sfr):
            self.sfr[offset] = value & 0xFF
            self.sfr[offset + 1] = (value >> 8) & 0xFF

    # ------------------------------------------------------------------
    def summary(self) -> dict:
        return {
            "watchdog_serviced": self.watchdog_serviced,
            "watchdog_resets": self.watchdog_resets,
            "watchdog_enabled": self.watchdog_enabled,
            "adc_starts": self.adc_starts,
            "timer_ticks": self.timer_ticks,
            "timer7_requests": self.timer7_requests,
            "scheduler_flag_writes": self.scheduler_flag_writes,
            "port_writes": len(self.port_writes),
            "can_tx_frames": len(self.can_tx),
            "asc0_tx_bytes": len(self.asc0_tx),
            "ssc_tx_bytes": len(self.ssc_tx),
            "stub_notes": list(self.stub_notes),
        }
