// c00c36 asc0_init size=78 cc=unknown proto=undefined asc0_init(void)

void asc0_init(char param_1)

{
  ushort uVar1;
  
  if (param_1 == '\x02') {
    DAT_00feb6 = 0x1ce;
    S0BG = 0x2e;
  }
  else {
    DAT_00feb6 = 0xcd;
    S0BG = 0x4c;
  }
  S0CON = 0x811;
  DAT_00f0c6 = 0x807;
  DAT_00f0c4 = 0x807;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x400;
  uVar1 = P3;
  P3 = uVar1 & 0xfbff | 0x400;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfbff | 0x400;
  uVar1 = S0TBIC;
  S0TBIC = uVar1 | 0x80;
  uVar1 = S0TIC;
  S0TIC = uVar1 | 0x80;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x8000;
  return;
}

