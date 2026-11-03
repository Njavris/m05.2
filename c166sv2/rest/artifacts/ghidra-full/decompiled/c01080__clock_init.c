// c01080 clock_init size=176 cc=unknown proto=undefined clock_init(void)

void clock_init(void)

{
  ushort uVar1;
  
  PICON = 0;
  P0H = 0;
  POCON0H = 0;
  DP0H = 0;
  P0L = 0;
  POCON0L = 0;
  DP0L = 0;
  P1H = 8;
  DAT_00f120 = 0;
  POCON1H = 0;
  DP1H = 0x2e;
  P1L = 0;
  DAT_00f130 = 0;
  POCON1L = 0;
  DP1L = 0x71;
  uVar1 = DP1L;
  DP1L = uVar1 | 10;
  uVar1 = DP1L;
  DP1L = uVar1 | 0x40;
  ODP3 = 0;
  P3 = 0;
  DAT_00f126 = 0;
  DAT_00f128 = 0;
  POCON3 = 0;
  DP3 = 0x2240;
  ODP4 = 0;
  P4 = 0;
  DAT_00f12a = 0;
  DAT_00f136 = 0;
  POCON4 = 0;
  DP4 = 0;
  BUSCON4 = 0;
  BUSCON2 = 0;
  DAT_00f138 = 0;
  DAT_00f13a = 3;
  DAT_00f094 = 0;
  BUSCON3 = 0x10;
  DAT_00ffb4 = 0;
  POCON20 = 0;
  DAT_00ffb6 = 0;
  return;
}

