// c1105e gap_c1105e size=28 cc=unknown proto=undefined gap_c1105e(void)

void gap_c1105e(short param_1)

{
  short sVar1;
  short sVar2;
  
  sVar2 = *(short *)(uint3)(param_1 + 0x3a) * 8;
  sVar1 = *(short *)(uint3)(sVar2 + 0x7052);
  sVar2 = *(short *)(uint3)(sVar2 + 0x7054);
  *(short *)(uint3)(param_1 + 4) = sVar1 + -1;
  *(ushort *)(uint3)(param_1 + 6) = sVar2 - (ushort)(sVar1 == 0);
  return;
}

