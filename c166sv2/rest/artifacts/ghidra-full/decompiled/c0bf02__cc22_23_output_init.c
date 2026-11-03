// c0bf02 cc22_23_output_init size=62 cc=unknown proto=undefined cc22_23_output_init(void)

void cc22_23_output_init(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fe28;
  DAT_00fe28 = uVar1 | 0xc0;
  uVar1 = CCM5;
  CCM5 = uVar1 | 0x5500;
  uVar1 = DAT_00f130;
  DAT_00f130 = uVar1 | 0x80;
  uVar1 = DAT_00f120;
  DAT_00f120 = uVar1 | 1;
  uVar1 = DP1L;
  DP1L = uVar1 | 0x80;
  uVar1 = DP1H;
  DP1H = uVar1 | 1;
  uVar1 = CC22IC;
  CC22IC = uVar1 | 0x34;
  uVar1 = CC23IC;
  CC23IC = uVar1 | 0x35;
  DAT_00c3c6 = 0xfe6e;
  DAT_00c3e0 = 0xfe6c;
  DAT_00c3c8 = 0xf16e;
  DAT_00c3e2 = 0xf16c;
  return;
}

