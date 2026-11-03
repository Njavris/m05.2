// c00dda gap_c00dda size=2 cc=unknown proto=undefined gap_c00dda(void)

void gap_c00dda(void)

{
  ushort uVar1;
  
  uVar1 = SSCCON;
  SSCCON = uVar1 & 0x7fff;
  SSCBR = 1;
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
  SSCRIC = uVar1 | 0x10;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x40;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x80;
  uVar1 = SSCTIC;
  SSCTIC = uVar1 | 0x80;
  return;
}

