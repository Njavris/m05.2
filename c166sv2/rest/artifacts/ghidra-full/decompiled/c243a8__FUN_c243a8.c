// c243a8 FUN_c243a8 size=34 cc=unknown proto=undefined FUN_c243a8(void)

byte FUN_c243a8(short param_1)

{
  short sVar1;
  byte bVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 == -1) {
    bVar2 = 0;
  }
  else {
    bVar2 = (byte)(*(ushort *)(uint3)(ushort)((short)&UNK_00c168 + sVar1 * 2) >> 5) & 1;
  }
  return bVar2;
}

