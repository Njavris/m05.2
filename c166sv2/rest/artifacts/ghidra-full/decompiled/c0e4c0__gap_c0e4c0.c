// c0e4c0 gap_c0e4c0 size=38 cc=unknown proto=undefined gap_c0e4c0(void)

undefined2 gap_c0e4c0(ushort param_1)

{
  short sVar1;
  undefined2 uVar2;
  
  uVar2 = 0;
  sVar1 = Ram00c3fa;
  if ((sVar1 != -0x6010) &&
     ((*(byte *)(uint3)((short)&UNK_00c41c + (param_1 & 0xff) * 0x12) & 8) != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}

