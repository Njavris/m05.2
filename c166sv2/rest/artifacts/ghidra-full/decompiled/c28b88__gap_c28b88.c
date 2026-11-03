// c28b88 gap_c28b88 size=42 cc=unknown proto=undefined gap_c28b88(void)

short gap_c28b88(void)

{
  ushort extraout_r1;
  short sVar1;
  undefined4 uVar2;
  
  uVar2 = div32u();
  sVar1 = (short)((uint)uVar2 >> 0x10);
  if ((extraout_r1 & 0x8000) != 0) {
    sVar1 = -(ushort)((short)uVar2 != 0) - sVar1;
  }
  return sVar1;
}

