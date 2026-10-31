/* c00c36 asc0_init */

/* ASC0 (UART/K-line) initialization; S0BG, S0CON, port setup. */

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
  uVar1 = CCM6;
  CCM6 = uVar1 | 0x400;
  uVar1 = P3;
  P3 = uVar1 & 0xfbff | 0x400;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfbff | 0x400;
  uVar1 = T0IC;
  T0IC = uVar1 | 0x80;
  uVar1 = S0TIC;
  S0TIC = uVar1 | 0x80;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x8000;
  return;
}


