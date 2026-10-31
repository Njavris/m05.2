/* c103c0 port_bus_init */

/* Application port and external-bus initialization. */

void port_bus_init(void)

{
  ushort uVar1;
  
  P3 = 0x80;
  P0H = 0;
  DAT_00f082 = 0;
  P0H = 0;
  P0L = 0;
  DAT_00f080 = 0;
  P0L = 0;
  P1H = 4;
  DAT_00f120 = 0;
  DAT_00f086 = 0;
  P1H = 0x2e;
  P1L = 0;
  DAT_00f130 = 0;
  DAT_00f084 = 0;
  DP1L = 0x71;
  uVar1 = P1L;
  P1L = uVar1 | 10;
  uVar1 = DP1L;
  DP1L = uVar1 | 0x40;
  DP3 = 0;
  P3 = 0;
  DAT_00f126 = 0;
  DAT_00f128 = 0;
  CC5 = 0;
  DP3 = 0x8040;
  DP4 = 0;
  P4 = 0;
  DAT_00f12a = 0;
  DAT_00f136 = 0;
  CC6 = 0;
  DP4 = 0;
  BUSCON4 = 0;
  BUSCON2 = 0;
  DAT_00f138 = 0;
  DAT_00f13a = 3;
  CC10 = 0;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 & 0xffdf;
  BUSCON3 = 0;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 0x10;
  DAT_00ffb4 = 0;
  DAT_00feaa = 0;
  DAT_00ffb6 = 0;
  uVar1 = P5;
  if ((uVar1 & 0x80) == 0) {
    CC1 = 0x3333;
    P0H = 0;
    DP0H = 0xff;
    CC0 = 0x3333;
    P0L = 0;
    P0L = 0xff;
    uVar1 = P1H;
    P1H = uVar1 & 0x3f;
    uVar1 = P1H;
    P1H = uVar1 | 0xc0;
    uVar1 = P3;
    P3 = uVar1 & 0x6fff;
    uVar1 = DP3;
    DP3 = uVar1 | 0x9000;
    CC6 = 0x3333;
    P4 = 0;
    DP4 = 0xff;
    DAT_00feaa = 0x3333;
    DAT_00ffb4 = 0;
    DAT_00ffb6 = 0xffff;
  }
  return;
}


