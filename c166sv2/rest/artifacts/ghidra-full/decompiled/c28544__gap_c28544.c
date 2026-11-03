// c28544 gap_c28544 size=390 cc=unknown proto=undefined gap_c28544(void)

short gap_c28544(ushort param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  short *psVar3;
  short sVar4;
  short *psVar5;
  short sVar6;
  ushort uVar7;
  undefined1 auStack_2 [2];
  
  uVar2 = param_1 + 2;
  sVar4 = *(short *)(uint3)param_1;
  sVar6 = sVar4 + -7;
  if ((sVar6 < 1) || (*(ushort *)(uint3)(uVar2 + sVar6 * 2) <= *(ushort *)ZEXT23(auStack_2))) {
    if (sVar6 < 1) {
      if (*(ushort *)ZEXT23(auStack_2) <= *(ushort *)(uint3)uVar2) {
        return 0;
      }
      sVar6 = (short)&UNK_00fffa + sVar4;
    }
    if (*(ushort *)(uint3)(uVar2 + (sVar4 + -1) * 2) <= *(ushort *)ZEXT23(auStack_2)) {
      return (sVar4 + -1) * 0x100;
    }
    uVar7 = sVar6 + 4;
  }
  else if (*(ushort *)ZEXT23(auStack_2) < *(ushort *)(param_1 + 0xe)) {
    if (*(ushort *)ZEXT23(auStack_2) <= *(ushort *)(uint3)uVar2) {
      return 0;
    }
    uVar7 = 2;
  }
  else if (*(ushort *)ZEXT23(auStack_2) < *(ushort *)(uint3)(uVar2 + (sVar4 >> 1) * 2)) {
    uVar7 = 8;
    while (*(ushort *)(uint3)(uVar2 + (uVar7 + 3) * 2) <= *(ushort *)ZEXT23(auStack_2)) {
      uVar7 = uVar7 + 5;
    }
  }
  else {
    uVar7 = sVar4 - 9;
    while (*(ushort *)ZEXT23(auStack_2) < *(ushort *)(uint3)(uVar2 + (uVar7 - 3) * 2)) {
      uVar7 = uVar7 - 5;
    }
  }
  psVar5 = (short *)(uVar2 + uVar7 * 2);
  sVar4 = param_2 + (ushort)(0xfffd < param_1) +
          ((short)uVar7 >> 0xf) * 2 + (ushort)CARRY2(uVar7,uVar7) + (ushort)CARRY2(uVar2,uVar7 * 2);
  psVar3 = psVar5;
  uVar2 = uVar7;
  if (*(ushort *)ZEXT23(auStack_2) < *(ushort *)ZEXT23(psVar5)) {
    do {
      uVar7 = uVar7 - 1;
      bVar1 = psVar5 < (short *)0x2;
      psVar5 = psVar5 + -1;
      sVar4 = sVar4 - (ushort)bVar1;
    } while (*(ushort *)ZEXT23(auStack_2) < *(ushort *)ZEXT23(psVar5));
  }
  else {
    do {
      uVar7 = uVar2;
      psVar5 = psVar3;
      psVar3 = psVar5 + 1;
      sVar4 = sVar4 + (ushort)((short *)&UNK_00fffd < psVar5);
      uVar2 = uVar7 + 1;
    } while (*(ushort *)ZEXT23(psVar3) <= *(ushort *)ZEXT23(auStack_2));
    sVar4 = sVar4 - (ushort)(psVar3 < (short *)0x2);
  }
  if (*(short *)ZEXT23(auStack_2) == *(short *)ZEXT23(psVar5)) {
    sVar4 = 0;
  }
  else {
    sVar4 = div32u(sVar4,psVar5[1] - *psVar5);
  }
  return uVar7 * 0x100 + sVar4;
}

