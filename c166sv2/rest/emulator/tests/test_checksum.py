import unittest

from emulator.c166.cpu import C166CPU
from emulator.c166.loader import checksum16_be
from emulator.tests.common import call_subroutine, fresh_cpu


class ChecksumTests(unittest.TestCase):
    def _run_checksum(self, start, end):
        cpu, memory, periph, raw, info = fresh_cpu()
        cpu.sp = 0xFC00
        cpu.write_word_gpr(12, start & 0xFFFF)
        cpu.write_word_gpr(13, (start >> 16) & 0xFF)
        cpu.write_word_gpr(14, end & 0xFFFF)
        cpu.write_word_gpr(15, (end >> 16) & 0xFF)
        call_subroutine(cpu, 0xC0, 0x037E)
        while cpu.pc != 0xC11EB4 and cpu.stop_reason is None:
            cpu.step()
        self.assertIsNone(cpu.stop_reason, cpu.stop_detail)
        return cpu.read_word_gpr(4), info

    def test_checksum16_be_boot_block(self):
        result, info = self._run_checksum(0xC00000, 0xC01FFD)
        computed, stored = info.checksums["boot"]
        self.assertEqual(result, stored)
        self.assertEqual(computed, stored)

    def test_checksum16_be_calibration_block(self):
        result, info = self._run_checksum(0xC05000, 0xC0AFFD)
        computed, stored = info.checksums["calibration"]
        self.assertEqual(result, stored)
        self.assertEqual(computed, stored)

    def test_python_checksum_matches_all_blocks(self):
        cpu, memory, periph, raw, info = fresh_cpu(load_flash=False)
        for name, (computed, stored) in info.checksums.items():
            self.assertEqual(computed, stored, name)
        self.assertTrue(info.passes)

    def test_checksum_algorithm_is_byte_swapped_sum(self):
        data = bytes([0x12, 0x34, 0xAB, 0xCD])
        self.assertEqual(checksum16_be(data, 0, 4), (0x1234 + 0xABCD) & 0xFFFF)


if __name__ == "__main__":
    unittest.main()
