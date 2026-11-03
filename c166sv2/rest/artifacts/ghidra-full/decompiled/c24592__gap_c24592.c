// c24592 gap_c24592 size=32 cc=unknown proto=undefined gap_c24592(void)

byte gap_c24592(short param_1)

{
  short sVar1;
  byte bVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 == -1) {
    bVar2 = 0;
  }
  else {
    bVar2 = (byte)*(undefined2 *)(uint3)(ushort)((short)&UNK_00c168 + sVar1 * 2) & 1;
  }
  return bVar2;
}

