import unittest

from emulator.tests.common import boot_to_scheduler


class BootTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.cpu, cls.memory, cls.periph, cls.info = boot_to_scheduler()

    def test_dump_identity_and_checksums(self):
        self.assertTrue(self.info.passes)
        self.assertEqual(self.info.checksums["boot"], (0xEE88, 0xEE88))
        self.assertEqual(self.info.checksums["calibration"], (0x8D79, 0x8D79))
        self.assertEqual(self.info.checksums["application"], (0x25C2, 0x25C2))

    def test_boot_reaches_application_scheduler(self):
        self.assertEqual(self.cpu.pc, 0xC11EB4)

    def test_known_boot_chain_reached(self):
        # The coverage was produced by the boot run; reconstruct it from the
        # cached snapshot's CPU, which has no history after restore.  The
        # register dump's last-32 window ends at app_scheduler.
        for pc in (0xC00A78, 0xC00200, 0xC10000, 0xC11AA0,
                   0xC0FFDE, 0xC11EB4):
            self.assertIn(pc, self.cpu._boot_pcs)

    def test_scheduler_reads_application_table(self):
        # Logical 0x709C is mapped by DPP1=0x302 to physical 0xC0B09C.
        self.assertEqual(self.memory.read16(0xC0B09C), 0x47AE)
        self.assertEqual(self.memory.read16(0xC0B09E), 0x00C1)


if __name__ == "__main__":
    unittest.main()
