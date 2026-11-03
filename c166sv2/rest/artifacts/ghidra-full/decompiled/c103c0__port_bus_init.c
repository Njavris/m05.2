// c103c0 port_bus_init size=260 cc=unknown proto=undefined port_bus_init(void)

void port_bus_init(void)

{
  ushort uVar1;
  
  PICON = 0x80;
  P0H = 0;
  POCON0H = 0;
  DP0H = 0;
  P0L = 0;
  POCON0L = 0;
  DP0L = 0;
  P1H = 4;
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
  DP3 = 0x8040;
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
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 & 0xffdf;
  BUSCON3 = 0;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 0x10;
  DAT_00ffb4 = 0;
  POCON20 = 0;
  DAT_00ffb6 = 0;
  uVar1 = P5;
  if ((uVar1 & 0x80) == 0) {
    POCON0H = 0x3333;
    P0H = 0;
    DP0H = 0xff;
    POCON0L = 0x3333;
    P0L = 0;
    DP0L = 0xff;
    uVar1 = P1H;
    P1H = uVar1 & 0x3f;
    uVar1 = DP1H;
    DP1H = uVar1 | 0xc0;
    uVar1 = P3;
    P3 = uVar1 & 0x6fff;
    uVar1 = DP3;
    DP3 = uVar1 | 0x9000;
    POCON4 = 0x3333;
    P4 = 0;
    DP4 = 0xff;
    POCON20 = 0x3333;
    DAT_00ffb4 = 0;
    DAT_00ffb6 = 0xffff;
  }
  return;
}

