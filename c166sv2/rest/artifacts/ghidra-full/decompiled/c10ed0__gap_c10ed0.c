// c10ed0 gap_c10ed0 size=54 cc=unknown proto=undefined gap_c10ed0(void)

undefined4 gap_c10ed0(short param_1,ushort param_2)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  
  uVar2 = 0xaa55;
  sVar3 = 0;
  for (uVar4 = 0; uVar4 < param_2; uVar4 = uVar4 + 1) {
    bVar1 = CARRY2(uVar2,(ushort)*(byte *)(uint3)(param_1 + uVar4));
    uVar2 = uVar2 + *(byte *)(uint3)(param_1 + uVar4);
    sVar3 = sVar3 + (ushort)bVar1;
  }
  return CONCAT22(sVar3,uVar2);
}

