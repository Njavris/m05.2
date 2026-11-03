/* c11f1c asc0_init_app */

/* Application ASC0/K-line initialization. */

void asc0_init_app(void)

{
  ushort uVar1;
  
  DAT_00feb6 = 0x1a2;
  S0BG = 0x9c;
  S0CON = 0x811;
  DAT_00f0c6 = 0x807;
  DAT_00f0c4 = 0x107;
  uVar1 = CCM6;
  CCM6 = uVar1 | 0x400;
  uVar1 = P3;
  P3 = uVar1 & 0xfbff | 0x400;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfbff | 0x400;
  uVar1 = S0RIC;
  S0RIC = uVar1 | 0x49;
  uVar1 = S0TIC;
  S0TIC = uVar1 | 0x4a;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x8000;
  return;
}


