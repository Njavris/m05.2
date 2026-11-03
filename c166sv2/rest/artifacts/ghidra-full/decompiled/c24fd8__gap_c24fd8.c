// c24fd8 gap_c24fd8 size=32 cc=unknown proto=undefined gap_c24fd8(void)

ushort gap_c24fd8(ushort param_1,ushort param_2,short param_3)

{
  short *psVar1;
  ushort uVar2;
  
  for (uVar2 = 0; (*(short *)(uint3)param_1 != 0xb && (uVar2 < param_2)); uVar2 = uVar2 + 1) {
    psVar1 = (short *)(uint3)param_1;
    param_1 = param_1 + 2;
    if (*psVar1 == param_3) {
      return uVar2;
    }
  }
  return 0xffff;
}

