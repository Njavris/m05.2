// c108ce pwm_init size=160 cc=unknown proto=undefined pwm_init(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pwm_init(void)

{
  ushort uVar1;
  
  _DAT_00e892 = 0xf423;
  _DAT_00e8ac = 0x805;
  _DAT_00e8ae = 0x20;
  _DAT_00e8a0 = 0x5780;
  _DAT_00e8a2 = 0x4b00;
  _DAT_00e8a4 = 0;
  _DAT_00e894 = 1;
  _DAT_00e8c6 = 0x110;
  _DAT_00e8a8 = 0;
  _DAT_00e8c4 = 0;
  _DAT_00e8c0 = 0x8014;
  _DAT_00e8ca = 0;
  _DAT_00e8ce = 0;
  _DAT_00e8c2 = 0;
  uVar1 = CC19IC;
  CC19IC = uVar1 | 0x5c;
  uVar1 = CC20IC;
  CC20IC = uVar1 | 0x5d;
  uVar1 = CC18IC;
  CC18IC = uVar1 | 0x5e;
  if (DAT_c05081 == '\x02') {
    uVar1 = DAT_00f130;
    DAT_00f130 = uVar1 | 0x10;
    uVar1 = P1L;
    P1L = uVar1 & 0xffef | 0x10;
    uVar1 = DP1L;
    DP1L = uVar1 & 0xffef | 0x10;
  }
  _DAT_00e8a6 = 0x202;
  return;
}

