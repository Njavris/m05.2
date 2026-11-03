/* c00200 boot_main */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boot-block main: checks magic/checksums, selects app or bootloader. */

void boot_main(void)

{
  ushort uVar1;
  short sVar2;
  ushort extraout_r10;
  ushort extraout_r10_00;
  short extraout_r11;
  short extraout_r11_00;
  
  uVar1 = input_status;
  if ((uVar1 & 2) != 0) {
    mem_read_word(0x7fc,0xe0);
    if (extraout_r11 + 0x9bb0U == (ushort)(extraout_r10 < 0x8625) && extraout_r10 == 0x8625) {
      boot_variant = '\x01';
    }
    mem_read_word();
    if (extraout_r11_00 + 0x79cdU == (ushort)(extraout_r10_00 < 0x6450) && extraout_r10_00 == 0x6450
       ) {
      boot_variant = '\x02';
    }
  }
  mem_write_word();
  boot_periph_init();
  if (_app_entry == 0) {
    bootloader_entry(0);
  }
  uVar1 = input_status;
  if ((uVar1 & 0x400) != 0) {
    bootloader_entry();
  }
  if ((boot_variant == '\x01') || (boot_variant == '\x02')) {
    asc0_state2_init(boot_variant);
    bootloader_entry();
  }
  if ((app_magic != -0x5600) &&
     ((sVar2 = checksum16_be(0,0xc0,0x1ffd,0xc0), sVar2 != boot_checksum ||
      (sVar2 = checksum16_be(0xb000,0xc0,0xfffb,0xc3), sVar2 != app_checksum)))) {
    bootloader_entry();
    return;
  }
  app_entry();
  return;
}


