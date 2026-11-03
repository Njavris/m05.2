// c003f0 bootloader_entry size=56 cc=unknown proto=undefined bootloader_entry(void)

void bootloader_entry(void)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar1 = P1L;
  P1L = uVar1 & 0xffdf;
  uVar1 = BUSCON2;
  BUSCON2 = uVar1 & 0xffef;
  uVar1 = P1L;
  P1L = uVar1 & 0xffbf;
  delay_ticks(1);
  ssc_start_frame();
  delay_ticks(1);
  ssc_start_frame();
  uVar1 = DP1L;
  DP1L = uVar1 & 0xffbf;
  do {
    do {
      delay_ticks(500);
      uVar1 = DAT_00c078;
    } while ((uVar1 & 0x10) != 0);
    uVar1 = DP1L;
    DP1L = uVar1 | 0x40;
    uVar2 = P1L;
    uVar1 = P1L;
    uVar3 = P1L;
    P1L = uVar3 & 0xffbf | ((uVar1 & 0x40) >> 6 ^ 1) << 6;
  } while( true );
}

