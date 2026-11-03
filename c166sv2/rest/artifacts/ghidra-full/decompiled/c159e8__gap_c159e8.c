// c159e8 gap_c159e8 size=42 cc=unknown proto=undefined gap_c159e8(void)

void gap_c159e8(short param_1,short param_2,ushort param_3)

{
  ushort uVar1;
  ushort uVar2;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    if ((*(char *)(uint3)(param_2 + uVar2) != '\0') &&
       (uVar1 = param_1 + uVar2 * 2, *(short *)(uint3)uVar1 != 0)) {
      *(short *)(uint3)uVar1 = *(short *)(uint3)uVar1 + -1;
    }
  }
  return;
}

