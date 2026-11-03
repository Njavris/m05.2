// c10f90 gap_c10f90 size=88 cc=unknown proto=undefined gap_c10f90(void)

ushort gap_c10f90(short param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  
  uVar2 = param_1 + 0x10;
  *(ushort *)(uint3)(param_1 + 0x12) =
       *(short *)(uint3)(param_1 + 0x12) + (ushort)(0xfffe < *(ushort *)(uint3)uVar2);
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 + 1;
  for (uVar6 = 0; uVar6 < 4; uVar6 = uVar6 + 1) {
    uVar5 = *(ushort *)(uint3)uVar2;
    sVar3 = *(short *)(uint3)(param_1 + 0x12);
    sVar4 = uVar6 << 3;
    while (bVar1 = sVar4 != 0, sVar4 = sVar4 + -1, bVar1) {
      uVar5 = uVar5 >> 1 | sVar3 << 0xf;
      sVar3 = sVar3 >> 1;
    }
    *(char *)(uint3)(param_2 + uVar6) = (char)uVar5;
  }
  return uVar6;
}

