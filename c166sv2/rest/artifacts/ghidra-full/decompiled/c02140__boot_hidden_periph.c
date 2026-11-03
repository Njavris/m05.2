// c02140 boot_hidden_periph size=158 cc=unknown proto=undefined boot_hidden_periph(void)

void boot_hidden_periph(void)

{
  undefined2 uVar1;
  ushort uVar2;
  
  PICON = 0x80;
  POCON1L = 0x4444;
  POCON1H = 0x4444;
  DAT_00f120 = 0;
  DP1L = 0xfb;
  DP1H = 0x2f;
  uVar2 = P3;
  P3 = uVar2 & 0xdfff;
  uVar1 = DAT_00f126;
  uVar2 = DAT_00f126;
  DAT_00f126 = uVar2 | 0x2200;
  uVar1 = DAT_00f128;
  uVar1 = ODP3;
  uVar2 = DP3;
  DP3 = uVar2 | 0xa240;
  uVar2 = P3;
  P3 = uVar2 | 0xa200;
  uVar2 = P5DIDIS;
  P5DIDIS = uVar2 | 0x80ff;
  DAT_00f138 = 8;
  DAT_00f13a = 8;
  uVar1 = BUSCON4;
  uVar2 = BUSCON3;
  BUSCON3 = uVar2 | 0x1b;
  uVar2 = P1H;
  P1H = uVar2 & 0xfffb | 4;
  return;
}

