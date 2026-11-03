// c0119e asc0_state1 size=56 cc=unknown proto=undefined asc0_state1(void)

void asc0_state1(void)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = P3;
  if ((uVar2 & 0x800) == 0) {
    sVar1 = DAT_00c0b0;
    DAT_00c0b0 = sVar1 + 1;
    return;
  }
  uVar2 = DAT_00c0b0;
  if ((0x14 < uVar2) && (uVar2 < 0x1c)) {
    DAT_00c0af = 2;
    DAT_00c0ae = 0;
    uVar2 = DAT_00f0c6;
    DAT_00f0c6 = uVar2 & 0xfffd | 2;
    uVar2 = S0CON;
    S0CON = uVar2 | 0x10;
  }
  DAT_00c0b0 = 0;
  return;
}

