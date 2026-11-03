// c0ff00 ssc0_init_app size=40 cc=unknown proto=undefined ssc0_init_app(void)

void ssc0_init_app(void)

{
  ushort uVar1;
  
  uVar1 = SSCCON;
  SSCCON = uVar1 & 0x7fff;
  SSCBR = 3;
  uVar1 = P3;
  P3 = uVar1 & 0xdfff;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 | 0x2000;
  SSCCON = 0xc037;
  uVar1 = P3;
  P3 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfeff;
  uVar1 = P3;
  P3 = uVar1 | 0x200;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x200;
  uVar1 = DP3;
  DP3 = uVar1 | 0x200;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0xd0;
  uVar1 = SSCTIC;
  SSCTIC = uVar1 | 0x80;
  return;
}

