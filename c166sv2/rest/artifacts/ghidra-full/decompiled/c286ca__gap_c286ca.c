// c286ca gap_c286ca size=392 cc=unknown proto=undefined gap_c286ca(void)

short gap_c286ca(ushort param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  undefined2 *puVar3;
  short sVar4;
  undefined2 *puVar5;
  short sVar6;
  ushort uVar7;
  undefined1 auStack_2 [2];
  
  uVar2 = param_1 + 2;
  sVar4 = *(short *)(uint3)param_1;
  sVar6 = sVar4 + -7;
  if ((sVar6 < 1) || (*(short *)(uint3)(uVar2 + sVar6 * 2) <= *(short *)ZEXT23(auStack_2))) {
    if (sVar6 < 1) {
      if (*(short *)ZEXT23(auStack_2) <= *(short *)(uint3)uVar2) {
        return 0;
      }
      sVar6 = (short)&UNK_00fffa + sVar4;
    }
    if (*(short *)(uint3)(uVar2 + (sVar4 + -1) * 2) <= *(short *)ZEXT23(auStack_2)) {
      return (sVar4 + -1) * 0x100;
    }
    uVar7 = sVar6 + 4;
  }
  else if (*(short *)ZEXT23(auStack_2) < *(short *)(param_1 + 0xe)) {
    if (*(short *)ZEXT23(auStack_2) <= *(short *)(uint3)uVar2) {
      return 0;
    }
    uVar7 = 2;
  }
  else if (*(short *)ZEXT23(auStack_2) < *(short *)(uint3)(uVar2 + (sVar4 >> 1) * 2)) {
    uVar7 = 8;
    while (*(short *)(uint3)(uVar2 + (uVar7 + 3) * 2) <= *(short *)ZEXT23(auStack_2)) {
      uVar7 = uVar7 + 5;
    }
  }
  else {
    uVar7 = sVar4 - 9;
    while (*(short *)ZEXT23(auStack_2) < *(short *)(uint3)(uVar2 + (uVar7 - 3) * 2)) {
      uVar7 = uVar7 - 5;
    }
  }
  puVar5 = (undefined2 *)(uVar2 + uVar7 * 2);
  sVar4 = param_2 + (ushort)(0xfffd < param_1) +
          ((short)uVar7 >> 0xf) * 2 + (ushort)CARRY2(uVar7,uVar7) + (ushort)CARRY2(uVar2,uVar7 * 2);
  puVar3 = puVar5;
  uVar2 = uVar7;
  if (*(short *)ZEXT23(auStack_2) < *(short *)ZEXT23(puVar5)) {
    do {
      uVar7 = uVar7 - 1;
      bVar1 = puVar5 < (undefined2 *)0x2;
      puVar5 = puVar5 + -1;
      sVar4 = sVar4 - (ushort)bVar1;
    } while (*(short *)ZEXT23(auStack_2) < *(short *)ZEXT23(puVar5));
  }
  else {
    do {
      uVar7 = uVar2;
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
      sVar4 = sVar4 + (ushort)((undefined2 *)&UNK_00fffd < puVar5);
      uVar2 = uVar7 + 1;
    } while (*(short *)ZEXT23(puVar3) <= *(short *)ZEXT23(auStack_2));
    sVar4 = sVar4 - (ushort)(puVar3 < (undefined2 *)0x2);
  }
  if (*(short *)ZEXT23(auStack_2) - *(short *)ZEXT23(puVar5) == 0) {
    sVar4 = 0;
  }
  else {
    sVar4 = div32u(*puVar5,sVar4,*(short *)ZEXT23(auStack_2) - *(short *)ZEXT23(puVar5));
  }
  return uVar7 * 0x100 + sVar4;
}

