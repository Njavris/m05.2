"""C166SV2 instruction interpreter.

The decoder follows the Infineon C166 instruction-set manual (V2.0, 2001-03)
and the encoding table in that manual.  It intentionally implements the full
set of instructions the MT05.2 image actually executes, plus a handful of
neighbouring forms needed for tests.

Semantics are functional, not cycle-accurate.  The important architectural
details are:

* 16-bit GPRs, addressed relative to the Context Pointer (CP, SFR 0xFE10).
* Byte GPR aliases RL0..RH7.
* DPP0..DPP3 translate 16-bit logical data addresses.
* EXTP / EXTS override the DPP for a bounded instruction sequence.
* EXTR selects the extended SFR area 0xF000..0xF1FF for the same sequence.
* The hardware system stack pointer is SFR 0xFE12 (not R0).
* PSW flags are N=bit0, C=bit1, V=bit2, Z=bit3, E=bit4.
"""

from __future__ import annotations

from dataclasses import dataclass, field

from .dpp import AddressSpace
from .memory import Memory, MemoryFault


WORD = 0xFFFF
BYTE = 0xFF


class CpuFault(Exception):
    pass


class StopExecution(Exception):
    def __init__(self, reason: str, detail: str = ""):
        self.reason = reason
        self.detail = detail
        super().__init__(reason)


# Condition-code encoding from manual table 5.
CC_NAMES = {
    0x0: "cc_UC",
    0x1: "cc_NET",
    0x2: "cc_EQ",
    0x3: "cc_NE",
    0x4: "cc_V",
    0x5: "cc_NV",
    0x6: "cc_N",
    0x7: "cc_NN",
    0x8: "cc_C",
    0x9: "cc_NC",
    0xA: "cc_SGT",
    0xB: "cc_SLE",
    0xC: "cc_SLT",
    0xD: "cc_SGE",
    0xE: "cc_UGT",
    0xF: "cc_ULE",
}

# 16-bit opcode high byte (first byte when fetched little-endian).
MNEMONICS = {
    0x00: "add", 0x01: "addb", 0x02: "add", 0x03: "addb", 0x04: "add",
    0x05: "addb", 0x06: "add", 0x07: "addb", 0x08: "add", 0x09: "addb",
    0x0A: "bfldl", 0x0B: "mul", 0x0C: "rol", 0x0E: "bclr", 0x0F: "bset",
    0x10: "addc", 0x11: "addcb", 0x12: "addc", 0x13: "addcb", 0x14: "addc",
    0x15: "addcb", 0x16: "addc", 0x17: "addcb", 0x18: "addc", 0x19: "addcb",
    0x1A: "bfldh", 0x1B: "mulu", 0x1C: "rol",
    0x20: "sub", 0x21: "subb", 0x22: "sub", 0x23: "subb", 0x24: "sub",
    0x25: "subb", 0x26: "sub", 0x27: "subb", 0x28: "sub", 0x29: "subb",
    0x2A: "bcmp", 0x2B: "prior", 0x2C: "ror",
    0x30: "subc", 0x31: "subcb", 0x32: "subc", 0x33: "subcb", 0x34: "subc",
    0x35: "subcb", 0x36: "subc", 0x37: "subcb", 0x38: "subc", 0x39: "subcb",
    0x3A: "bmovn", 0x3C: "ror",
    0x40: "cmp", 0x41: "cmpb", 0x42: "cmp", 0x43: "cmpb", 0x46: "cmp",
    0x47: "cmpb", 0x48: "cmp", 0x49: "cmpb", 0x4A: "bmov", 0x4B: "div",
    0x4C: "shl", 0x4E: "bclr", 0x4F: "bset",
    0x50: "xor", 0x51: "xorb", 0x52: "xor", 0x53: "xorb", 0x54: "xor",
    0x55: "xorb", 0x56: "xor", 0x57: "xorb", 0x58: "xor", 0x59: "xorb",
    0x5A: "bor", 0x5B: "divu", 0x5C: "shl", 0x5E: "bclr", 0x5F: "bset",
    0x60: "and", 0x61: "andb", 0x62: "and", 0x63: "andb", 0x64: "and",
    0x65: "andb", 0x66: "and", 0x67: "andb", 0x68: "and", 0x69: "andb",
    0x6A: "band", 0x6B: "divl", 0x6C: "shr", 0x6E: "bclr", 0x6F: "bset",
    0x70: "or", 0x71: "orb", 0x72: "or", 0x73: "orb", 0x74: "or",
    0x75: "orb", 0x76: "or", 0x77: "orb", 0x78: "or", 0x79: "orb",
    0x7A: "bxor", 0x7B: "divlu", 0x7C: "shr", 0x7E: "bclr", 0x7F: "bset",
    0x80: "cmpi1", 0x81: "neg", 0x82: "cmpi1", 0x84: "mov", 0x86: "cmpi1",
    0x87: "idle", 0x88: "mov", 0x89: "movb", 0x8A: "jb", 0x8E: "bclr",
    0x8F: "bset", 0x90: "cmpi2", 0x91: "cpl", 0x92: "cmpi2", 0x94: "mov",
    0x96: "cmpi2", 0x98: "mov", 0x99: "movb", 0x9A: "jnb", 0x9B: "trap",
    0x9C: "jmpi", 0x9E: "bclr", 0x9F: "bset",
    0xA0: "cmpd1", 0xA1: "negb", 0xA2: "cmpd1", 0xA4: "movb", 0xA5: "diswdt",
    0xA6: "cmpd1", 0xA7: "srvwdt", 0xA8: "mov", 0xA9: "movb", 0xAA: "jbc",
    0xAB: "calli", 0xAC: "ashr", 0xAE: "bclr", 0xAF: "bset",
    0xB0: "cmpd2", 0xB1: "cplb", 0xB2: "cmpd2", 0xB4: "movb", 0xB5: "einit",
    0xB6: "cmpd2", 0xB7: "srst", 0xB8: "mov", 0xB9: "movb", 0xBA: "jnbs",
    0xBB: "callr", 0xBC: "ashr", 0xBE: "bclr", 0xBF: "bset",
    0xC0: "movbz", 0xC2: "movbz", 0xC4: "mov", 0xC5: "movbz", 0xC6: "scxt",
    0xC8: "mov", 0xC9: "movb", 0xCA: "calla", 0xCB: "ret", 0xCC: "nop",
    0xCE: "bclr", 0xCF: "bset",
    0xD0: "movbs", 0xD2: "movbs", 0xD4: "mov", 0xD5: "movbs", 0xD6: "scxt",
    0xD7: "extp", 0xD8: "mov", 0xD9: "movb", 0xDA: "calls", 0xDB: "rets",
    0xDC: "extp", 0xDE: "bclr", 0xDF: "bset",
    0xE0: "mov", 0xE1: "movb", 0xE2: "pcall", 0xE4: "movb", 0xE6: "mov",
    0xE7: "movb", 0xE8: "mov", 0xE9: "movb", 0xEA: "jmpa", 0xEB: "retp",
    0xEC: "push", 0xEE: "bclr", 0xEF: "bset",
    0x0D: "jmpr", 0x1D: "jmpr", 0x2D: "jmpr", 0x3D: "jmpr",
    0x4D: "jmpr", 0x5D: "jmpr", 0x6D: "jmpr", 0x7D: "jmpr",
    0x8D: "jmpr", 0x9D: "jmpr", 0xAD: "jmpr", 0xBD: "jmpr",
    0xCD: "jmpr", 0xDD: "jmpr", 0xED: "jmpr", 0xFD: "jmpr",
    0xD1: "atomic", 0xDC: "extp", 0xD7: "extp",
    0xF0: "mov", 0xF1: "movb", 0xF2: "mov", 0xF3: "movb", 0xF4: "movb",
    0xF6: "mov", 0xF7: "movb", 0xFA: "jmps", 0xFB: "reti", 0xFC: "pop",
    0xFE: "bclr", 0xFF: "bset",
}

# JMPR condition codes are encoded in bits 4..7, with low nibble 0xD.
JMPR_CC = {
    0x0D: 0x0, 0x1D: 0x1, 0x2D: 0x2, 0x3D: 0x3,
    0x4D: 0x4, 0x5D: 0x5, 0x6D: 0x6, 0x7D: 0x7,
    0x8D: 0x8, 0x9D: 0x9, 0xAD: 0xA, 0xBD: 0xB,
    0xCD: 0xC, 0xDD: 0xD, 0xED: 0xE, 0xFD: 0xF,
}


@dataclass
class StepInfo:
    step: int
    pc: int
    opcode: int
    mnemonic: str
    sp: int
    dpp: tuple[int, int, int, int]
    psw: int


class C166CPU:
    def __init__(self, memory: Memory, peripherals=None):
        self.memory = memory
        self.peripherals = peripherals
        if peripherals is not None:
            peripherals.cpu = self
            memory.peripherals = peripherals
        self.space = AddressSpace()
        self.dpp = self.space.dpp

        self.psw = 0x0000
        self.cp = 0x0000
        self.sp = 0xFC00
        self.csp = 0xC0
        self.ip = 0x0000
        self.md = 0
        self.mdc = 0

        # Extension state: applies to the current instruction.
        self.extr = False
        self.extp: int | None = None
        self.exts: int | None = None
        self.ext_count = 0
        self._ext_just_set = False

        self.steps = 0
        self.insn_start = 0
        self.instr_words = 0
        self.last_pc = 0
        self.last_info: StepInfo | None = None
        self.history: list[StepInfo] = []
        self.stop_reason: str | None = None
        self.stop_detail = ""
        self.srst_count = 0
        self.idle_count = 0

        self.tracer = None
        self.pre_step_hook = None
        self.watch_logical: set[int] = set()
        self.watch_physical: set[int] = set()
        self.watch_cb = None
        self._pc_hits: dict[int, int] = {}

    # ------------------------------------------------------------------
    # Basic state helpers
    # ------------------------------------------------------------------
    @property
    def pc(self) -> int:
        return ((self.csp & 0xFF) << 16) | (self.ip & 0xFFFF)

    @pc.setter
    def pc(self, value: int) -> None:
        self.csp = (value >> 16) & 0xFF
        self.ip = value & 0xFFFF

    def reset(self) -> None:
        self.psw = 0
        self.cp = 0
        self.sp = 0xFC00
        self.csp = 0xC0
        self.ip = 0
        self.md = 0
        self.mdc = 0
        self.extr = False
        self.extp = None
        self.exts = None
        self.ext_count = 0
        self.space.dpp[:] = [0, 1, 2, 3]
        self.steps = 0
        self.stop_reason = None
        self.history.clear()
        self._pc_hits.clear()

    # PSW bit positions per the C166 manual / Ghidra processor spec.
    @property
    def flag_n(self) -> int:
        return self.psw & 1

    @property
    def flag_c(self) -> int:
        return (self.psw >> 1) & 1

    @property
    def flag_v(self) -> int:
        return (self.psw >> 2) & 1

    @property
    def flag_z(self) -> int:
        return (self.psw >> 3) & 1

    @property
    def flag_e(self) -> int:
        return (self.psw >> 4) & 1

    def _set_flag(self, mask: int, value: bool) -> None:
        if value:
            self.psw |= mask
        else:
            self.psw &= ~mask & WORD

    def set_nz(self, result: int, bits: int = 16) -> None:
        sign = 1 << (bits - 1)
        self._set_flag(0x1, bool(result & sign))
        self._set_flag(0x8, (result & ((1 << bits) - 1)) == 0)

    def set_e(self, value: int, bits: int = 16) -> None:
        self._set_flag(0x10, (value & ((1 << bits) - 1)) == (1 << (bits - 1)))

    def set_cv(self, carry: bool, overflow: bool) -> None:
        self._set_flag(0x2, carry)
        self._set_flag(0x4, overflow)

    # ------------------------------------------------------------------
    # Register addressing
    # ------------------------------------------------------------------
    def _gpr_word_addr(self, index: int) -> int:
        return (self.cp + 2 * index) & 0xFFFF

    def _gpr_byte_addr(self, index: int) -> int:
        return (self.cp + index) & 0xFFFF

    def read_word_gpr(self, index: int) -> int:
        return self.memory.read16(self._gpr_word_addr(index), "gpr")

    def write_word_gpr(self, index: int, value: int) -> None:
        self.memory.write16(self._gpr_word_addr(index), value & WORD, "gpr")

    def read_byte_gpr(self, index: int) -> int:
        return self.memory.read8(self._gpr_byte_addr(index), "gpr")

    def write_byte_gpr(self, index: int, value: int) -> None:
        self.memory.write8(self._gpr_byte_addr(index), value & BYTE, "gpr")

    def _reg_base(self) -> int:
        return 0xF000 if self.extr else 0xFE00

    def read_reg_word(self, reg: int) -> int:
        if (reg & 0xF0) == 0xF0:
            return self.read_word_gpr(reg & 0x0F)
        return self.memory.read16((self._reg_base() + 2 * reg) & 0xFFFF, "reg")

    def write_reg_word(self, reg: int, value: int) -> None:
        if (reg & 0xF0) == 0xF0:
            self.write_word_gpr(reg & 0x0F, value)
        else:
            self.memory.write16((self._reg_base() + 2 * reg) & 0xFFFF,
                                value & WORD, "reg")

    def read_reg_byte(self, reg: int) -> int:
        if (reg & 0xF0) == 0xF0:
            return self.read_byte_gpr(reg & 0x0F)
        return self.memory.read8((self._reg_base() + 2 * reg) & 0xFFFF, "reg")

    def write_reg_byte(self, reg: int, value: int) -> None:
        if (reg & 0xF0) == 0xF0:
            self.write_byte_gpr(reg & 0x0F, value)
        else:
            self.memory.write8((self._reg_base() + 2 * reg) & 0xFFFF,
                               value & BYTE, "reg")

    # ------------------------------------------------------------------
    # Long / indirect addressing
    # ------------------------------------------------------------------
    def physical(self, logical: int) -> int:
        return self.space.translate(logical, extp=self.extp, exts=self.exts)

    def _watch(self, access: str, logical: int | None, physical: int,
               width: int, value: int, source: str) -> None:
        if self.watch_cb is None:
            return
        if ((logical is not None and logical in self.watch_logical)
                or physical in self.watch_physical):
            self.watch_cb(access, logical, physical, width, value, source,
                          self.steps, self.insn_start)

    def read_long_word(self, logical: int) -> int:
        physical = self.physical(logical)
        value = self.memory.read16(physical, "mem")
        self._watch("read", logical, physical, 2, value, "mem")
        return value

    def write_long_word(self, logical: int, value: int) -> None:
        physical = self.physical(logical)
        self.memory.write16(physical, value & WORD, "mem")
        self._watch("write", logical, physical, 2, value & WORD, "mem")

    def read_long_byte(self, logical: int) -> int:
        physical = self.physical(logical)
        value = self.memory.read8(physical, "mem")
        self._watch("read", logical, physical, 1, value, "mem")
        return value

    def write_long_byte(self, logical: int, value: int) -> None:
        physical = self.physical(logical)
        self.memory.write8(physical, value & BYTE, "mem")
        self._watch("write", logical, physical, 1, value & BYTE, "mem")

    def read_indirect_word(self, ptr_reg: int) -> int:
        return self.read_long_word(self.read_word_gpr(ptr_reg))

    def write_indirect_word(self, ptr_reg: int, value: int) -> None:
        self.write_long_word(self.read_word_gpr(ptr_reg), value)

    def read_indirect_byte(self, ptr_reg: int) -> int:
        return self.read_long_byte(self.read_word_gpr(ptr_reg))

    def write_indirect_byte(self, ptr_reg: int, value: int) -> None:
        self.write_long_byte(self.read_word_gpr(ptr_reg), value)

    # ------------------------------------------------------------------
    # Stack
    # ------------------------------------------------------------------
    def push16(self, value: int) -> None:
        self.sp = (self.sp - 2) & 0xFFFF
        self.memory.write16(self.sp, value & WORD, "stack")

    def pop16(self) -> int:
        value = self.memory.read16(self.sp, "stack")
        self.sp = (self.sp + 2) & 0xFFFF
        return value

    # ------------------------------------------------------------------
    # Instruction fetch
    # ------------------------------------------------------------------
    def fetch16(self) -> int:
        address = self.pc
        value = self.memory.read16(address, "fetch")
        self.ip = (self.ip + 2) & 0xFFFF
        self.instr_words += 1
        return value

    # ------------------------------------------------------------------
    # Flags and arithmetic
    # ------------------------------------------------------------------
    def _cc_true(self, cc: int) -> bool:
        if cc == 0x0:
            return True
        if cc == 0x1:
            return not (self.flag_z or self.flag_e)
        if cc in (0x2,):
            return bool(self.flag_z)
        if cc in (0x3,):
            return not self.flag_z
        if cc == 0x4:
            return bool(self.flag_v)
        if cc == 0x5:
            return not self.flag_v
        if cc == 0x6:
            return bool(self.flag_n)
        if cc == 0x7:
            return not self.flag_n
        if cc in (0x8,):
            return bool(self.flag_c)
        if cc in (0x9,):
            return not self.flag_c
        nv = bool(self.flag_n) ^ bool(self.flag_v)
        if cc == 0xA:
            return not (self.flag_z or nv)
        if cc == 0xB:
            return bool(self.flag_z or nv)
        if cc == 0xC:
            return nv
        if cc == 0xD:
            return not nv
        if cc == 0xE:
            return not (self.flag_z or self.flag_c)
        if cc == 0xF:
            return bool(self.flag_z or self.flag_c)
        raise CpuFault(f"bad condition code {cc:#x}")

    def _add(self, a: int, b: int, bits: int, carry_in: int = 0) -> int:
        mask = (1 << bits) - 1
        sign = 1 << (bits - 1)
        self.set_e(b, bits)
        a &= mask
        b &= mask
        full = a + b + carry_in
        result = full & mask
        carry = full > mask
        overflow = bool((~(a ^ b) & (a ^ result) & sign))
        self.set_cv(carry, overflow)
        self.set_nz(result, bits)
        return result

    def _sub(self, a: int, b: int, bits: int, carry_in: int = 0) -> int:
        mask = (1 << bits) - 1
        sign = 1 << (bits - 1)
        self.set_e(b, bits)
        a &= mask
        b &= mask
        result = (a - b - carry_in) & mask
        borrow = (a < b) or (a == b and carry_in != 0)
        overflow = bool(((a ^ b) & (a ^ result) & sign))
        self.set_cv(borrow, overflow)
        self.set_nz(result, bits)
        return result

    def _logic(self, a: int, op: str, b: int, bits: int) -> int:
        mask = (1 << bits) - 1
        self.set_e(b, bits)
        self.set_cv(False, False)
        if op == "and":
            result = (a & b) & mask
        elif op == "or":
            result = (a | b) & mask
        else:
            result = (a ^ b) & mask
        self.set_nz(result, bits)
        return result

    def _compare(self, a: int, b: int, bits: int) -> None:
        mask = (1 << bits) - 1
        sign = 1 << (bits - 1)
        self.set_e(b, bits)
        result = (a - b) & mask
        borrow = (a & mask) < (b & mask)
        overflow = bool(((a ^ b) & (a ^ result) & sign))
        self.set_cv(borrow, overflow)
        self.set_nz(result, bits)

    # ------------------------------------------------------------------
    # Bit addressing
    # ------------------------------------------------------------------
    def _bit_word(self, offset: int) -> int:
        if offset < 0x80:
            return 0xFD00 + 2 * offset
        if offset < 0xF0:
            base = 0xF100 if self.extr else 0xFF00
            return base + 2 * (offset & 0x7F)
        return (self.cp + 2 * (offset & 0x0F)) & 0xFFFF

    def read_bit(self, offset: int, bit: int) -> int:
        word = self.memory.read16(self._bit_word(offset), "bit")
        return (word >> bit) & 1

    def write_bit(self, offset: int, bit: int, value: int) -> None:
        address = self._bit_word(offset)
        word = self.memory.read16(address, "bit")
        if value:
            word |= 1 << bit
        else:
            word &= ~(1 << bit)
        self.memory.write16(address, word & WORD, "bit")

    def _set_bit_clear_flags(self, old: int) -> None:
        self._set_flag(0x1, bool(old))
        self._set_flag(0x8, not old)
        self.set_cv(False, False)
        self._set_flag(0x10, False)

    def _set_bitwise_flags(self, z_bit: int, q_bit: int) -> None:
        self._set_flag(0x1, bool(z_bit ^ q_bit))
        self._set_flag(0x2, bool(z_bit & q_bit))
        self._set_flag(0x4, bool(z_bit | q_bit))
        self._set_flag(0x8, not (z_bit | q_bit))
        self._set_flag(0x10, False)

    # ------------------------------------------------------------------
    # Tracing / stop
    # ------------------------------------------------------------------
    def _trace_step(self, pc: int, opcode: int, mnemonic: str) -> None:
        info = StepInfo(
            step=self.steps,
            pc=pc,
            opcode=opcode,
            mnemonic=mnemonic,
            sp=self.sp,
            dpp=tuple(self.dpp),
            psw=self.psw,
        )
        self.last_info = info
        self.history.append(info)
        if len(self.history) > 32:
            del self.history[0]
        if self.tracer is not None:
            self.tracer.on_step(info, self)

    def _trace_call(self, caller: int, kind: str, target: int, indirect: bool = False) -> None:
        if self.tracer is not None:
            self.tracer.on_call(caller, kind, target, indirect, self)

    # ------------------------------------------------------------------
    # Extension state
    # ------------------------------------------------------------------
    def _begin_extension(self, mode: str, count: int, value: int) -> None:
        self.ext_count = max(1, min(4, count))
        self._ext_just_set = True
        if mode == "extr":
            self.extr = True
        elif mode == "extp":
            self.extp = value
        elif mode == "exts":
            self.exts = value

    def _end_instruction_extension(self) -> None:
        if self._ext_just_set:
            self._ext_just_set = False
            return
        if self.ext_count > 0:
            self.ext_count -= 1
            if self.ext_count == 0:
                self.extr = False
                self.extp = None
                self.exts = None

    # ------------------------------------------------------------------
    # Main step
    # ------------------------------------------------------------------
    def step(self) -> None:
        if self.stop_reason is not None:
            return
        start_pc = self.pc
        self.insn_start = start_pc
        self.instr_words = 0
        try:
            opcode = self.fetch16()
            first = opcode & 0xFF
            mnemonic = MNEMONICS.get(first, "???")
            self._trace_step(start_pc, opcode, mnemonic)
            self._pc_hits[start_pc] = self._pc_hits.get(start_pc, 0) + 1
            self._execute(opcode, start_pc)
            self.steps += 1
            self.last_pc = start_pc
            self._end_instruction_extension()
        except StopExecution as exc:
            self.stop_reason = exc.reason
            self.stop_detail = exc.detail
        except MemoryFault as exc:
            self.stop_reason = "memory_fault"
            self.stop_detail = str(exc)
        except CpuFault as exc:
            self.stop_reason = "cpu_fault"
            self.stop_detail = str(exc)

    # ------------------------------------------------------------------
    # Decoder / executor
    # ------------------------------------------------------------------
    def _execute(self, opcode: int, start_pc: int) -> None:
        op = opcode & 0xFF
        second = (opcode >> 8) & 0xFF
        n = (second >> 4) & 0x0F
        m = second & 0x0F

        # ---------------- ADD / ADDC / SUB / SUBC / CMP ----------------
        if op in (0x00, 0x10, 0x20, 0x30, 0x40):
            a = self.read_word_gpr(n)
            b = self.read_word_gpr(m)
            if op == 0x00:
                self.write_word_gpr(n, self._add(a, b, 16))
            elif op == 0x10:
                self.write_word_gpr(n, self._add(a, b, 16, self.flag_c))
            elif op == 0x20:
                self.write_word_gpr(n, self._sub(a, b, 16))
            elif op == 0x30:
                self.write_word_gpr(n, self._sub(a, b, 16, self.flag_c))
            else:
                self._compare(a, b, 16)
            return

        if op in (0x01, 0x11, 0x21, 0x31, 0x41):
            a = self.read_byte_gpr(n)
            b = self.read_byte_gpr(m)
            if op == 0x01:
                self.write_byte_gpr(n, self._add(a, b, 8))
            elif op == 0x11:
                self.write_byte_gpr(n, self._add(a, b, 8, self.flag_c))
            elif op == 0x21:
                self.write_byte_gpr(n, self._sub(a, b, 8))
            elif op == 0x31:
                self.write_byte_gpr(n, self._sub(a, b, 8, self.flag_c))
            else:
                self._compare(a, b, 8)
            return

        if op in (0x50, 0x60, 0x70):
            a = self.read_word_gpr(n)
            b = self.read_word_gpr(m)
            result = self._logic(a, {0x50: "xor", 0x60: "and", 0x70: "or"}[op], b, 16)
            self.write_word_gpr(n, result)
            return
        if op in (0x51, 0x61, 0x71):
            a = self.read_byte_gpr(n)
            b = self.read_byte_gpr(m)
            result = self._logic(a, {0x51: "xor", 0x61: "and", 0x71: "or"}[op], b, 8)
            self.write_byte_gpr(n, result)
            return

        # register, immediate / memory variants
        if op in (0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                  0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                  0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
                  0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
                  0x42, 0x43, 0x46, 0x47,
                  0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
                  0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
                  0x52, 0x53, 0x54, 0x55, 0x56, 0x57):
            self._arith_mem(op, second)
            return

        # extended 2-byte arithmetic with [R0..R3] / #data3
        if op in (0x08, 0x09, 0x18, 0x19, 0x28, 0x29, 0x38, 0x39,
                  0x48, 0x49, 0x58, 0x59, 0x68, 0x69, 0x78, 0x79):
            self._arith_ext(op, second)
            return

        if op in (0x0B, 0x1B):
            a = self.read_word_gpr(n)
            b = self.read_word_gpr(m)
            if op == 0x0B:
                product = (self._s16(a) * self._s16(b)) & 0xFFFFFFFF
            else:
                product = (a * b) & 0xFFFFFFFF
            self.md = product
            self._set_flag(0x10, False)
            self._set_flag(0x2, False)
            self._set_flag(0x1, bool(product & 0x80000000))
            self._set_flag(0x8, product == 0)
            # V: result not representable in a word.  Signed MUL needs a
            # sign-extended low word; unsigned MULU needs a zero high word.
            word = product & 0xFFFF
            if op == 0x0B:
                fits = (product & 0xFFFFFFFF) == (
                    word | (0xFFFF0000 if (word & 0x8000) else 0))
            else:
                fits = (product >> 16) == 0
            self._set_flag(0x4, not fits)
            return

        if op in (0x4B, 0x5B, 0x6B, 0x7B):
            self._divide(op, m)
            return

        if op == 0x2B:  # PRIOR
            source = self.read_word_gpr(m)
            count = 0
            tmp = source
            while count != 15 and tmp != 0 and not (tmp & 0x8000):
                tmp = (tmp << 1) & WORD
                count += 1
            if source == 0:
                self.write_word_gpr(n, 0)
                self._set_flag(0x8, True)
            else:
                self.write_word_gpr(n, count)
                self._set_flag(0x8, False)
            self.set_cv(False, False)
            self._set_flag(0x1, False)
            self._set_flag(0x10, False)
            return

        # ---------------- shifts / rotates ----------------
        if op in (0x0C, 0x1C, 0x2C, 0x3C, 0x4C, 0x5C, 0x6C, 0x7C,
                  0xAC, 0xBC):
            if op in (0x1C, 0x3C, 0x5C, 0x7C, 0xBC):
                reg = m
                count = n
            else:
                reg = n
                count = self.read_word_gpr(m) & 0x0F
            self._shift(op, reg, count)
            return

        # ---------------- MOV family ----------------
        if op == 0xF0:
            self._move(self.read_word_gpr(m), self.write_word_gpr, n)
            return
        if op == 0xF1:
            self._move(self.read_byte_gpr(m), self.write_byte_gpr, n, bits=8)
            return
        if op == 0xE0:
            self._move(n, self.write_word_gpr, m)
            return
        if op == 0xE1:
            self._move(n, self.write_byte_gpr, m, bits=8)
            return
        if op == 0xE6:
            value = self.fetch16()
            self._move(value, self.write_reg_word, second)
            return
        if op == 0xE7:
            value = self.fetch16() & 0xFF
            self._move(value, self.write_reg_byte, second, bits=8)
            return
        if op in (0xA8, 0x98):
            value = self.read_indirect_word(m)
            if op == 0x98:
                self.write_word_gpr(m, (self.read_word_gpr(m) + 2) & WORD)
            self._move(value, self.write_word_gpr, n)
            return
        if op in (0xB8, 0x88):
            value = self.read_word_gpr(n)
            if op == 0x88:
                self.write_word_gpr(m, (self.read_word_gpr(m) - 2) & WORD)
            self.write_indirect_word(m, value)
            self._set_move_flags(value)
            return
        if op in (0xC8, 0xD8, 0xE8):
            value = self.read_indirect_word(m)
            if op == 0xE8:
                self.write_word_gpr(m, (self.read_word_gpr(m) + 2) & WORD)
            self.write_indirect_word(n, value)
            if op == 0xD8:
                self.write_word_gpr(n, (self.read_word_gpr(n) + 2) & WORD)
            self._set_move_flags(value)
            return
        if op == 0xA9:
            value = self.read_indirect_byte(m)
            self._move(value, self.write_byte_gpr, n, bits=8)
            return
        if op == 0x99:
            value = self.read_indirect_byte(m)
            self.write_byte_gpr(m, (self.read_byte_gpr(m) + 1) & BYTE)
            self._move(value, self.write_byte_gpr, n, bits=8)
            return
        if op in (0xB9, 0x89):
            value = self.read_byte_gpr(n)
            if op == 0x89:
                self.write_byte_gpr(m, (self.read_byte_gpr(m) - 1) & BYTE)
            self.write_indirect_byte(m, value)
            self._set_move_flags(value, bits=8)
            return
        if op in (0xC9, 0xD9, 0xE9):
            value = self.read_indirect_byte(m)
            if op == 0xE9:
                self.write_byte_gpr(m, (self.read_byte_gpr(m) + 1) & BYTE)
            self.write_indirect_byte(n, value)
            if op == 0xD9:
                self.write_byte_gpr(n, (self.read_byte_gpr(n) + 1) & BYTE)
            self._set_move_flags(value, bits=8)
            return
        if op in (0xD4, 0xC4):
            offset = self.fetch16()
            value = self.read_long_word((self.read_word_gpr(m) + offset) & WORD)
            if op == 0xD4:
                self._move(value, self.write_word_gpr, n)
            else:
                self.write_long_word((self.read_word_gpr(m) + offset) & WORD, self.read_word_gpr(n))
                self._set_move_flags(self.read_word_gpr(n))
            return
        if op in (0xF4, 0xE4):
            offset = self.fetch16()
            if op == 0xF4:
                value = self.read_long_byte((self.read_word_gpr(m) + offset) & WORD)
                self._move(value, self.write_byte_gpr, n, bits=8)
            else:
                value = self.read_byte_gpr(n)
                self.write_long_byte((self.read_word_gpr(m) + offset) & WORD, value)
                self._set_move_flags(value, bits=8)
            return
        if op in (0x84, 0x94, 0xA4, 0xB4):
            address = self.fetch16()
            ptr = second & 0x0F
            if op in (0x84, 0xA4):
                if op == 0x84:
                    value = self.read_long_word(address)
                    self.write_indirect_word(ptr, value)
                    self._set_move_flags(value)
                else:
                    value = self.read_long_byte(address)
                    self.write_indirect_byte(ptr, value)
                    self._set_move_flags(value, bits=8)
            else:
                if op == 0x94:
                    value = self.read_indirect_word(ptr)
                    self.write_long_word(address, value)
                    self._set_move_flags(value)
                else:
                    value = self.read_indirect_byte(ptr)
                    self.write_long_byte(address, value)
                    self._set_move_flags(value, bits=8)
            return
        if op in (0xF2, 0xF6, 0xF3, 0xF7):
            address = self.fetch16()
            if op == 0xF2:
                self._move(self.read_long_word(address), self.write_reg_word, second)
            elif op == 0xF6:
                value = self.read_reg_word(second)
                self.write_long_word(address, value)
                self._set_move_flags(value)
            elif op == 0xF3:
                self._move(self.read_long_byte(address), self.write_reg_byte, second, bits=8)
            else:
                value = self.read_reg_byte(second)
                self.write_long_byte(address, value)
                self._set_move_flags(value, bits=8)
            return
        if op in (0xC0, 0xD0):
            value = self.read_byte_gpr(n)
            if op == 0xC0:
                self._move(value, self.write_word_gpr, m)
                self._set_flag(0x1, False)
            else:
                value = value - 0x100 if value & 0x80 else value
                self._move(value & WORD, self.write_word_gpr, m)
            self._set_flag(0x10, False)
            return
        if op in (0xC2, 0xD2):
            address = self.fetch16()
            value = self.read_long_byte(address)
            if op == 0xC2:
                self._move(value, self.write_reg_word, second)
                self._set_flag(0x1, False)
            else:
                value = value - 0x100 if value & 0x80 else value
                self._move(value & WORD, self.write_reg_word, second)
            self._set_flag(0x10, False)
            return
        if op in (0xC5, 0xD5):
            address = self.fetch16()
            value = self.read_reg_byte(second)
            if op == 0xC5:
                self.write_long_word(address, value)
                self._set_move_flags(value, bits=8)
                self._set_flag(0x1, False)
            else:
                value = value - 0x100 if value & 0x80 else value
                self.write_long_word(address, value & WORD)
                self._set_move_flags(value & WORD)
            self._set_flag(0x10, False)
            return

        # ---------------- CMPI / CMPD ----------------
        if op in (0x80, 0x82, 0x86, 0x90, 0x92, 0x96,
                  0xA0, 0xA2, 0xA6, 0xB0, 0xB2, 0xB6):
            self._cmpi_cmpd(op, second)
            return

        # ---------------- NEG / CPL ----------------
        if op == 0x81:
            a = self.read_word_gpr(n)
            self.set_e(a, 16)
            result = (-a) & WORD
            self.set_cv(a != 0, a == 0x8000)
            self.set_nz(result, 16)
            self.write_word_gpr(n, result)
            return
        if op == 0xA1:
            a = self.read_byte_gpr(n)
            self.set_e(a, 8)
            result = (-a) & BYTE
            self.set_cv(a != 0, a == 0x80)
            self.set_nz(result, 8)
            self.write_byte_gpr(n, result)
            return
        if op == 0x91:
            a = self.read_word_gpr(n)
            self.set_e(a, 16)
            result = (~a) & WORD
            self.set_cv(False, False)
            self.set_nz(result, 16)
            self.write_word_gpr(n, result)
            return
        if op == 0xB1:
            a = self.read_byte_gpr(n)
            self.set_e(a, 8)
            result = (~a) & BYTE
            self.set_cv(False, False)
            self.set_nz(result, 8)
            self.write_byte_gpr(n, result)
            return

        # ---------------- bit instructions ----------------
        if (op & 0x0F) in (0x0E, 0x0F):
            bit = (op >> 4) & 0x0F
            offset = second
            old = self.read_bit(offset, bit)
            self._set_bit_clear_flags(old)
            self.write_bit(offset, bit, 1 if (op & 0x0F) == 0x0F else 0)
            return

        if op in (0x0A, 0x1A):
            offset = second
            packed = self.fetch16()
            data = packed & 0xFF
            mask = (packed >> 8) & 0xFF
            word = self.memory.read16(self._bit_word(offset), "bitfield")
            shift = 8 if op == 0x1A else 0
            word = (word & ~(mask << shift)) | (data << shift)
            self.memory.write16(self._bit_word(offset), word & WORD, "bitfield")
            self._set_flag(0x10, False)
            self.set_cv(False, False)
            self.set_nz(word, 16)
            return

        if op in (0x2A, 0x3A, 0x4A, 0x5A, 0x6A, 0x7A):
            qq = second
            packed = self.fetch16()
            zz = packed & 0xFF
            qz = (packed >> 8) & 0xFF
            q = (qz >> 4) & 0x0F
            z = qz & 0x0F
            q_bit = self.read_bit(qq, q)
            z_bit = self.read_bit(zz, z)
            if op == 0x2A:
                self._set_bitwise_flags(z_bit, q_bit)
            elif op == 0x3A:
                self._set_bit_clear_flags(z_bit)
                self.write_bit(zz, z, q_bit ^ 1)
            elif op == 0x4A:
                self._set_bit_clear_flags(z_bit)
                self.write_bit(zz, z, q_bit)
            elif op == 0x5A:
                self._set_bitwise_flags(z_bit, q_bit)
                self.write_bit(zz, z, z_bit | q_bit)
            elif op == 0x6A:
                self._set_bitwise_flags(z_bit, q_bit)
                self.write_bit(zz, z, z_bit & q_bit)
            else:
                self._set_bitwise_flags(z_bit, q_bit)
                self.write_bit(zz, z, z_bit ^ q_bit)
            return

        if op in (0x8A, 0x9A, 0xAA, 0xBA):
            offset = second
            packed = self.fetch16()
            rel = packed & 0xFF
            q0 = (packed >> 8) & 0xFF
            q = (q0 >> 4) & 0x0F
            bit = self.read_bit(offset, q)
            if op == 0x8A:
                if bit:
                    self._branch_rel(rel)
            elif op == 0x9A:
                if not bit:
                    self._branch_rel(rel)
            elif op == 0xAA:
                if bit:
                    self.read_bit(offset, q)
                    self._set_bit_clear_flags(bit)
                    self.write_bit(offset, q, 0)
                    self._branch_rel(rel)
            else:
                if not bit:
                    self._set_bit_clear_flags(bit)
                    self.write_bit(offset, q, 1)
                    self._branch_rel(rel)
            return

        # ---------------- jumps / calls ----------------
        if op in JMPR_CC:
            if self._cc_true(JMPR_CC[op]):
                self._branch_rel(second)
            return

        if op == 0xEA:
            target = self.fetch16()
            cc = (second >> 4) & 0x0F
            if self._cc_true(cc):
                self.ip = target
                self._trace_call(start_pc, "jmpa", self.pc)
            return
        if op == 0xFA:
            seg = second
            target = self.fetch16()
            new_pc = ((seg & 0xFF) << 16) | target
            self.csp = seg & 0xFF
            self.ip = target
            self._trace_call(start_pc, "jmps", new_pc)
            return
        if op == 0xCA:
            target = self.fetch16()
            cc = (second >> 4) & 0x0F
            if self._cc_true(cc):
                self.push16(self.ip)
                self.ip = target
                self._trace_call(start_pc, "calla", self.pc)
            return
        if op == 0xDA:
            seg = second
            target = self.fetch16()
            self.push16(self.csp)
            self.push16(self.ip)
            self.csp = seg & 0xFF
            self.ip = target
            self._trace_call(start_pc, "calls", self.pc)
            return
        if op == 0xBB:
            self.push16(self.ip)
            self._branch_rel(second)
            self._trace_call(start_pc, "callr", self.pc)
            return
        if op == 0xAB:
            cc = (second >> 4) & 0x0F
            if self._cc_true(cc):
                target = self.read_word_gpr(m)
                self.push16(self.ip)
                self.ip = target
                self._trace_call(start_pc, "calli", self.pc, True)
            return
        if op == 0x9C:
            cc = (second >> 4) & 0x0F
            if self._cc_true(cc):
                target = self.read_word_gpr(m)
                self.ip = target
                self._trace_call(start_pc, "jmpi", self.pc, True)
            return
        if op == 0xE2:
            addr = self.fetch16()
            value = self.read_reg_word(second)
            self.push16(value)
            self.ip = addr
            self._trace_call(start_pc, "pcall", self.pc)
            return

        if op == 0xDB:  # RETS
            self.ip = self.pop16()
            self.csp = self.pop16() & 0xFF
            return
        if op == 0xCB:  # RET
            self.ip = self.pop16()
            return
        if op == 0xFB:  # RETI
            self.ip = self.pop16()
            self.csp = self.pop16() & 0xFF
            self.psw = self.pop16()
            return
        if op == 0xEB:  # RETP
            self.ip = self.pop16()
            value = self.pop16()
            self.write_reg_word(second, value)
            self._set_move_flags(value)
            return

        if op == 0xEC:  # PUSH
            self.push16(self.read_reg_word(second))
            return
        if op == 0xFC:  # POP
            value = self.pop16()
            self.write_reg_word(second, value)
            self._set_move_flags(value)
            return
        if op in (0xC6, 0xD6):  # SCXT
            old = self.read_reg_word(second)
            self.push16(old)
            if op == 0xC6:
                value = self.fetch16()
            else:
                value = self.read_long_word(self.fetch16())
            self.write_reg_word(second, value)
            return

        # ---------------- extension opcodes ----------------
        if op == 0xD1:
            mode = (second >> 6) & 3
            irang = ((second >> 4) & 3) + 1
            if mode == 0:
                self._begin_extension("atomic", irang, 0)
            elif mode == 2:
                self._begin_extension("extr", irang, 0)
            else:
                raise CpuFault(f"unsupported EXT opcode D1 {second:02X}")
            return
        if op == 0xD7:
            mode = (second >> 6) & 3
            irang = ((second >> 4) & 3) + 1
            value = self.fetch16()
            if mode == 1:
                self._begin_extension("extp", irang, value & 0x3FF)
            elif mode == 0:
                self._begin_extension("exts", irang, value & 0xFF)
            elif mode == 2:
                self.extr = True
                self._begin_extension("exts", irang, value & 0xFF)
                self.extr = True
            else:
                self.extr = True
                self._begin_extension("extp", irang, value & 0x3FF)
                self.extr = True
            return
        if op == 0xDC:
            mode = (second >> 6) & 3
            irang = ((second >> 4) & 3) + 1
            reg = second & 0x0F
            value = self.read_word_gpr(reg)
            if mode == 1:
                self._begin_extension("extp", irang, value & 0x3FF)
            elif mode == 0:
                self._begin_extension("exts", irang, value & 0xFF)
            elif mode == 2:
                self.extr = True
                self._begin_extension("exts", irang, value & 0xFF)
                self.extr = True
            else:
                self.extr = True
                self._begin_extension("extp", irang, value & 0x3FF)
                self.extr = True
            return

        # ---------------- system ----------------
        if op == 0xA5:
            self._consume_word()
            if self.peripherals:
                self.peripherals.disable_watchdog()
            return
        if op == 0xA7:
            self._consume_word()
            if self.peripherals:
                self.peripherals.service_watchdog()
            return
        if op == 0xB5:
            self._consume_word()
            if self.peripherals:
                self.peripherals.init_watchdog()
            return
        if op == 0xB7:
            self._consume_word()
            self.srst_count += 1
            raise StopExecution("software_reset", "SRST executed")
        if op == 0x87:
            self._consume_word()
            self.idle_count += 1
            raise StopExecution("idle", "IDLE executed")
        if op == 0xCC:
            return
        if op == 0x85:
            # C166SV2 MAC-unit opcode.  The only occurrence in this image is
            # a pair of no-effect words before the checksum epilogue; model it
            # as a 4-byte MAC NOP until the MAC register file is needed.
            self._consume_word()
            return
        if op == 0x9B:
            trap = (opcode >> 9) & 0x7F
            self._enter_vector(4 * trap, "trap")
            return

        raise CpuFault(f"unimplemented opcode {op:02X} at 0x{start_pc:06X}")

    # ------------------------------------------------------------------
    # Helpers used by the decoder
    # ------------------------------------------------------------------
    def _consume_word(self) -> None:
        # Protected system instructions are four bytes; the trailing word is
        # a fixed confirmation pattern and carries no operands.
        self.fetch16()

    @staticmethod
    def _s16(value: int) -> int:
        return value - 0x10000 if value & 0x8000 else value

    def _set_move_flags(self, value: int, bits: int = 16) -> None:
        self.set_e(value, bits)
        self.set_nz(value & ((1 << bits) - 1), bits)

    def _move(self, value: int, writer, reg: int, bits: int = 16) -> None:
        writer(reg, value & ((1 << bits) - 1))
        self._set_move_flags(value, bits)

    def _branch_rel(self, rel: int) -> None:
        offset = rel - 0x100 if rel & 0x80 else rel
        self.ip = (self.ip + 2 * offset) & 0xFFFF

    def _arith_ext(self, op: int, second: int) -> None:
        n = (second >> 4) & 0x0F
        low = second & 0x0F
        is_byte = op in (0x09, 0x19, 0x29, 0x39, 0x49, 0x59, 0x69, 0x79)
        base = op & 0xF0
        if low & 0x8:
            ptr = low & 0x3
            if is_byte:
                value = self.read_indirect_byte(ptr)
            else:
                value = self.read_indirect_word(ptr)
            if low & 0x4:
                if is_byte:
                    self.write_word_gpr(ptr, (self.read_word_gpr(ptr) + 1) & WORD)
                else:
                    self.write_word_gpr(ptr, (self.read_word_gpr(ptr) + 2) & WORD)
        else:
            value = low & 0x7
        if is_byte:
            a = self.read_byte_gpr(n)
            if base == 0x00:
                res = self._add(a, value, 8)
            elif base == 0x10:
                res = self._add(a, value, 8, self.flag_c)
            elif base == 0x20:
                res = self._sub(a, value, 8)
            elif base == 0x30:
                res = self._sub(a, value, 8, self.flag_c)
            elif base == 0x40:
                self._compare(a, value, 8)
                return
            elif base == 0x60:
                res = self._logic(a, "and", value, 8)
            elif base == 0x70:
                res = self._logic(a, "or", value, 8)
            else:
                res = self._logic(a, "xor", value, 8)
            self.write_byte_gpr(n, res)
        else:
            a = self.read_word_gpr(n)
            if base == 0x00:
                res = self._add(a, value, 16)
            elif base == 0x10:
                res = self._add(a, value, 16, self.flag_c)
            elif base == 0x20:
                res = self._sub(a, value, 16)
            elif base == 0x30:
                res = self._sub(a, value, 16, self.flag_c)
            elif base == 0x40:
                self._compare(a, value, 16)
                return
            elif base == 0x60:
                res = self._logic(a, "and", value, 16)
            elif base == 0x70:
                res = self._logic(a, "or", value, 16)
            else:
                res = self._logic(a, "xor", value, 16)
            self.write_word_gpr(n, res)

    def _arith_mem(self, op: int, second: int) -> None:
        is_byte = op in (0x03, 0x05, 0x07, 0x13, 0x15, 0x17,
                         0x23, 0x25, 0x27, 0x33, 0x35, 0x37,
                         0x43, 0x47, 0x63, 0x65, 0x67, 0x73, 0x75, 0x77,
                         0x53, 0x55, 0x57)
        is_imm = op in (0x06, 0x07, 0x16, 0x17, 0x26, 0x27,
                        0x36, 0x37, 0x46, 0x47, 0x66, 0x67,
                        0x76, 0x77, 0x56, 0x57)
        base = op & 0xF0
        if is_imm:
            value = self.fetch16()
            if is_byte:
                value &= 0xFF
        else:
            address = self.fetch16()
            value = self.read_long_byte(address) if is_byte else self.read_long_word(address)
        if op in (0x04, 0x05, 0x14, 0x15, 0x24, 0x25, 0x34, 0x35,
                  0x64, 0x65, 0x74, 0x75, 0x54, 0x55):
            # mem, reg forms
            if is_byte:
                a = self.read_long_byte(address)
                b = self.read_reg_byte(second)
                if base == 0x00:
                    res = self._add(a, b, 8)
                elif base == 0x10:
                    res = self._add(a, b, 8, self.flag_c)
                elif base == 0x20:
                    res = self._sub(a, b, 8)
                elif base == 0x30:
                    res = self._sub(a, b, 8, self.flag_c)
                elif base == 0x60:
                    res = self._logic(a, "and", b, 8)
                elif base == 0x70:
                    res = self._logic(a, "or", b, 8)
                else:
                    res = self._logic(a, "xor", b, 8)
                self.write_long_byte(address, res)
            else:
                a = self.read_long_word(address)
                b = self.read_reg_word(second)
                if base == 0x00:
                    res = self._add(a, b, 16)
                elif base == 0x10:
                    res = self._add(a, b, 16, self.flag_c)
                elif base == 0x20:
                    res = self._sub(a, b, 16)
                elif base == 0x30:
                    res = self._sub(a, b, 16, self.flag_c)
                elif base == 0x60:
                    res = self._logic(a, "and", b, 16)
                elif base == 0x70:
                    res = self._logic(a, "or", b, 16)
                else:
                    res = self._logic(a, "xor", b, 16)
                self.write_long_word(address, res)
            return
        # reg forms
        if is_byte:
            a = self.read_reg_byte(second)
            if base == 0x00:
                res = self._add(a, value, 8)
            elif base == 0x10:
                res = self._add(a, value, 8, self.flag_c)
            elif base == 0x20:
                res = self._sub(a, value, 8)
            elif base == 0x30:
                res = self._sub(a, value, 8, self.flag_c)
            elif base == 0x40:
                self._compare(a, value, 8)
                return
            elif base == 0x60:
                res = self._logic(a, "and", value, 8)
            elif base == 0x70:
                res = self._logic(a, "or", value, 8)
            else:
                res = self._logic(a, "xor", value, 8)
            self.write_reg_byte(second, res)
        else:
            a = self.read_reg_word(second)
            if base == 0x00:
                res = self._add(a, value, 16)
            elif base == 0x10:
                res = self._add(a, value, 16, self.flag_c)
            elif base == 0x20:
                res = self._sub(a, value, 16)
            elif base == 0x30:
                res = self._sub(a, value, 16, self.flag_c)
            elif base == 0x40:
                self._compare(a, value, 16)
                return
            elif base == 0x60:
                res = self._logic(a, "and", value, 16)
            elif base == 0x70:
                res = self._logic(a, "or", value, 16)
            else:
                res = self._logic(a, "xor", value, 16)
            self.write_reg_word(second, res)

    def _cmpi_cmpd(self, op: int, second: int) -> None:
        n = (second >> 4) & 0x0F
        m = second & 0x0F
        short_form = op in (0x80, 0x90, 0xA0, 0xB0)
        reg = m if short_form else (second & 0x0F)
        if short_form:
            value = n
        else:
            value = self.fetch16()
        a = self.read_word_gpr(reg)
        self._compare(a, value, 16)
        if op in (0x80, 0x82, 0x86):
            self.write_word_gpr(reg, (a + 1) & WORD)
        elif op in (0x90, 0x92, 0x96):
            self.write_word_gpr(reg, (a + 2) & WORD)
        elif op in (0xA0, 0xA2, 0xA6):
            self.write_word_gpr(reg, (a - 1) & WORD)
        else:
            self.write_word_gpr(reg, (a - 2) & WORD)

    def _divide(self, op: int, reg: int) -> None:
        divisor = self.read_word_gpr(reg)
        self._set_flag(0x10, False)
        self._set_flag(0x2, False)
        if divisor == 0:
            self._set_flag(0x4, True)
            self._set_flag(0x8, False)
            self._set_flag(0x1, False)
            return
        if op == 0x4B:  # DIV signed 16/16
            dividend = self._s16(self.md & 0xFFFF)
            div = self._s16(divisor)
            quot = int(dividend / div) if div else 0
            rem = dividend - quot * div
            self.md = ((rem & 0xFFFF) << 16) | (quot & 0xFFFF)
            self._set_flag(0x4, False)
            self.set_nz(quot & WORD, 16)
            return
        if op == 0x5B:  # DIVU
            dividend = self.md & 0xFFFF
            quot = dividend // divisor
            rem = dividend % divisor
            self.md = ((rem & 0xFFFF) << 16) | (quot & 0xFFFF)
            self._set_flag(0x4, False)
            self.set_nz(quot & WORD, 16)
            return
        if op == 0x6B:  # DIVL signed 32/16
            dividend = self.md & 0xFFFFFFFF
            if dividend & 0x80000000:
                dividend -= 1 << 32
            div = self._s16(divisor)
            quot = int(dividend / div)
            rem = dividend - quot * div
            overflow = not (-0x8000 <= quot <= 0x7FFF)
            self.md = ((rem & 0xFFFF) << 16) | (quot & 0xFFFF)
            self._set_flag(0x4, overflow)
            self.set_nz(quot & WORD, 16)
            return
        # DIVLU signedness: unsigned 32/16
        dividend = self.md & 0xFFFFFFFF
        quot = dividend // divisor
        rem = dividend % divisor
        overflow = quot > 0xFFFF
        self.md = ((rem & 0xFFFF) << 16) | (quot & 0xFFFF)
        self._set_flag(0x4, overflow)
        self.set_nz(quot & WORD, 16)

    def _shift(self, op: int, reg: int, count: int) -> None:
        count &= 0x0F
        value = self.read_word_gpr(reg)
        if op in (0x4C, 0x5C):  # SHL
            if count:
                carry = (value >> (16 - count)) & 1
                result = (value << count) & WORD
            else:
                carry = 0
                result = value
            self.set_cv(bool(carry), False)
            self._set_flag(0x10, False)
            self.set_nz(result, 16)
        elif op in (0x6C, 0x7C):  # SHR
            if count:
                carry = (value >> (count - 1)) & 1
                lost = value & ((1 << count) - 1)
            else:
                carry = 0
                lost = 0
            result = value >> count
            self.set_cv(bool(carry), bool(lost))
            self._set_flag(0x10, False)
            self.set_nz(result, 16)
        elif op in (0xAC, 0xBC):  # ASHR
            signed = self._s16(value)
            if count:
                carry = (value >> (count - 1)) & 1
            else:
                carry = 0
            result = (signed >> count) & WORD
            self.set_cv(bool(carry), ((signed >> count) << count) != signed)
            self._set_flag(0x10, False)
            self.set_nz(result, 16)
        elif op in (0x0C, 0x1C):  # ROL
            if count:
                carry = (value >> (16 - count)) & 1
                result = ((value << count) | (value >> (16 - count))) & WORD
            else:
                carry = 0
                result = value
            self.set_cv(bool(carry), False)
            self._set_flag(0x10, False)
            self.set_nz(result, 16)
        else:  # ROR
            if count:
                carry = (value >> (count - 1)) & 1
                result = ((value >> count) | (value << (16 - count))) & WORD
            else:
                carry = 0
                result = value
            self.set_cv(bool(carry), False)
            self._set_flag(0x10, False)
            self.set_nz(result, 16)
        self.write_word_gpr(reg, result)

    # ------------------------------------------------------------------
    # Interrupts
    # ------------------------------------------------------------------
    def _enter_vector(self, offset: int, kind: str = "interrupt") -> None:
        interrupted_pc = self.pc
        self.push16(self.psw)
        self.push16(self.csp)
        self.push16(self.ip)
        self.csp = 0xC0
        self.ip = offset & 0xFFFF
        self._trace_call(interrupted_pc, kind, self.pc, True)

    def inject_interrupt(self, vector_offset: int, kind: str = "interrupt") -> None:
        if self.stop_reason is not None:
            return
        self._enter_vector(vector_offset, kind)

    # ------------------------------------------------------------------
    def run(
        self,
        *,
        max_steps: int = 200_000,
        stop_pcs: set[int] | None = None,
        stop_on_idle: bool = False,
        stop_on_loop_after: int = 0,
        tick_every: int = 0,
        tick_amount: int = 1,
    ) -> str:
        stop_pcs = stop_pcs or set()
        while self.steps < max_steps and self.stop_reason is None:
            if tick_every and self.steps and self.steps % tick_every == 0:
                if self.peripherals:
                    self.peripherals.timer_tick(tick_amount)
            if self.pre_step_hook is not None:
                self.pre_step_hook(self)
            pc = self.pc
            if pc in stop_pcs:
                self.stop_reason = "stop_address"
                self.stop_detail = f"reached 0x{pc:06X}"
                break
            self.step()
            if stop_on_idle and self.stop_reason == "idle":
                break
            if self.stop_reason is None and stop_on_loop_after:
                if self._pc_hits.get(self.last_pc, 0) > stop_on_loop_after:
                    self.stop_reason = "infinite_loop"
                    self.stop_detail = (
                        f"PC 0x{self.last_pc:06X} executed "
                        f"{self._pc_hits[self.last_pc]} times"
                    )
                    break
        if self.stop_reason is None and self.steps >= max_steps:
            self.stop_reason = "step_limit"
            self.stop_detail = f"stopped after {max_steps} steps"
        return self.stop_reason or "running"

    # ------------------------------------------------------------------
    def register_dump(self) -> dict:
        return {
            "pc": self.pc,
            "csp": self.csp,
            "ip": self.ip,
            "sp": self.sp,
            "cp": self.cp,
            "psw": self.psw,
            "flags": {
                "N": self.flag_n,
                "C": self.flag_c,
                "V": self.flag_v,
                "Z": self.flag_z,
                "E": self.flag_e,
            },
            "dpp": list(self.dpp),
            "r0_r15": [
                self.memory.read16((self.cp + 2 * i) & 0xFFFF) for i in range(16)
            ],
            "md": self.md,
            "mdc": self.mdc,
            "steps": self.steps,
            "last_32": [
                {
                    "step": info.step,
                    "pc": info.pc,
                    "opcode": info.opcode,
                    "mnemonic": info.mnemonic,
                    "sp": info.sp,
                    "dpp": list(info.dpp),
                    "psw": info.psw,
                }
                for info in self.history
            ],
        }
