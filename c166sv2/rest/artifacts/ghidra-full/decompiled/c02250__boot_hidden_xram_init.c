// c02250 boot_hidden_xram_init size=172 cc=unknown proto=undefined boot_hidden_xram_init(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void boot_hidden_xram_init(void)

{
  ushort uVar1;
  
  _DAT_00e892 = 0xf423;
  _DAT_00e8b2 = 0xf423;
  _DAT_00e8ac = 0x909;
  _DAT_00e8ae = 0x20;
  _DAT_00e8a0 = 0x5780;
  _DAT_00e8a2 = 0x4b00;
  _DAT_00e8a4 = 0x6a40;
  _DAT_00e8b6 = 0x28a0;
  _DAT_00e894 = 1;
  _DAT_00e8c6 = 0x10;
  _DAT_00e8a8 = 0;
  _DAT_00e8c4 = 0;
  _DAT_00e8c0 = 4;
  _DAT_00e8ca = 0;
  _DAT_00e8a6 = 0x40;
  _DAT_00e8ce = 0;
  _DAT_00e8c2 = 0;
  uVar1 = DAT_00f130;
  DAT_00f130 = uVar1 & 0xfffb | 4;
  uVar1 = P1L;
  P1L = uVar1 & 0xfffb | 4;
  uVar1 = DP1L;
  DP1L = uVar1 & 0xfffb | 4;
  uVar1 = P1L;
  P1L = uVar1 & 0xffef;
  uVar1 = DP1L;
  DP1L = uVar1 & 0xffef | 0x10;
  return;
}

