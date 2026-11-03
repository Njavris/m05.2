// c02000 boot_hidden_main size=192 cc=unknown proto=undefined boot_hidden_main(void)

void boot_hidden_main(void)

{
  ushort uVar1;
  undefined4 uVar2;
  
  LAB_e00000 = 0xff;
  DAT_00f800 = 0;
  uVar1 = P1H;
  P1H = uVar1 & 0xfffb | 4;
  boot_hidden_periph();
  uVar1 = P1H;
  P1H = uVar1 & 0xfff7 | 8;
  boot_hidden_xram_init();
  boot_hidden_xram2();
  boot_hidden_xram3();
  uVar1 = P5;
  if ((uVar1 & 0x800) != 0) {
    uVar2 = boot_hidden_store32(4,0x4000,0xc0);
    uVar2 = boot_hidden_store32((short)uVar2,(short)((uint)uVar2 >> 0x10));
    boot_hidden_memcpy((short)uVar2,(short)((uint)uVar2 >> 0x10));
    boot_hidden_delay();
  }
  do {
    if (LAB_e00000 != 0xff) {
      if (LAB_e00000 < 0x1a) {
        boot_hidden_delay();
      }
      LAB_e00000 = 0xff;
    }
    __service_watchdog();
  } while( true );
}

