/* c00ddc asc0_pin_init */

/* ASC0 alternate-function pin setup. */

void asc0_pin_init(void)

{
  ushort uVar1;
  
  uVar1 = SSCCON;
  SSCCON = uVar1 & 0x7fff;
  S0BG = 1;
  uVar1 = P3;
  P3 = uVar1 & 0xdfff;
  uVar1 = CCM6;
  CCM6 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 | 0x2000;
  SSCCON = 0xc037;
  uVar1 = P3;
  P3 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfeff;
  uVar1 = P3;
  P3 = uVar1 | 0x200;
  uVar1 = CCM6;
  CCM6 = uVar1 | 0x200;
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


