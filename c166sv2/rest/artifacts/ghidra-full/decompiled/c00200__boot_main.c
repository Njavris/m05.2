// c00200 boot_main size=220 cc=unknown proto=undefined boot_main(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void boot_main(void)

{
  char cVar1;
  undefined1 uVar2;
  ushort uVar3;
  short sVar4;
  ushort extraout_r10;
  ushort extraout_r10_00;
  short extraout_r11;
  short extraout_r11_00;
  
  uVar3 = input_status;
  if ((uVar3 & 2) != 0) {
    mem_read_word(0x7fc,0xe0);
    if (extraout_r11 + 0x9bb0U == (ushort)(extraout_r10 < 0x8625) && extraout_r10 == 0x8625) {
      DAT_00c020 = 1;
    }
    mem_read_word();
    if (extraout_r11_00 + 0x79cdU == (ushort)(extraout_r10_00 < 0x6450) && extraout_r10_00 == 0x6450
       ) {
      DAT_00c020 = 2;
    }
  }
  mem_write_word();
  boot_periph_init();
  if (_app_entry == 0) {
    bootloader_entry(0);
  }
  uVar3 = input_status;
  if ((uVar3 & 0x400) != 0) {
    bootloader_entry();
  }
  cVar1 = DAT_00c020;
  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    uVar2 = DAT_00c020;
    asc0_state2_init(uVar2);
    bootloader_entry();
  }
  if ((DAT_c3fffc != -0x5600) &&
     ((sVar4 = checksum16_be(0,0xc0,0x1ffd,0xc0), sVar4 != DAT_c01ffe ||
      (sVar4 = checksum16_be(0xb000,0xc0,0xfffb,0xc3), sVar4 != DAT_c3fffe)))) {
    bootloader_entry();
    return;
  }
  app_entry();
  return;
}

