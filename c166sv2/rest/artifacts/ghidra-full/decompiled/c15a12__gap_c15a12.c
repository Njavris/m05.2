// c15a12 gap_c15a12 size=40 cc=unknown proto=undefined gap_c15a12(void)

void gap_c15a12(short param_1,short param_2,ushort param_3)

{
  ushort uVar1;
  ushort uVar2;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    if ((*(char *)(uint3)(param_2 + uVar2) != '\0') &&
       (uVar1 = param_1 + uVar2, *(char *)(uint3)uVar1 != -1)) {
      *(char *)(uint3)uVar1 = *(char *)(uint3)uVar1 + '\x01';
    }
  }
  return;
}

