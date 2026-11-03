// c28acc gap_c28acc size=132 cc=unknown proto=undefined gap_c28acc(void)

ushort gap_c28acc(ushort param_1,ushort param_2,short param_3,short param_4)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  
  sVar3 = 0;
  while (bVar1 = param_3 != 0, param_3 = param_3 + -1, bVar1) {
    bVar1 = CARRY2(param_2,param_2);
    param_2 = param_2 * 2;
    sVar3 = sVar3 * 2 + (ushort)bVar1;
  }
  uVar5 = param_1 - param_2;
  sVar3 = -(ushort)(param_1 < param_2) - sVar3;
  if (sVar3 < 0) {
    uVar4 = -uVar5;
    uVar2 = -(sVar3 + (ushort)(uVar5 != 0));
    while (bVar1 = param_4 != 0, param_4 = param_4 + -1, bVar1) {
      uVar4 = uVar4 >> 1 | uVar2 << 0xf;
      uVar2 = uVar2 >> 1;
    }
    uVar5 = -uVar4;
    sVar3 = -(uVar2 + (uVar4 != 0));
  }
  else {
    while (bVar1 = param_4 != 0, param_4 = param_4 + -1, bVar1) {
      uVar5 = uVar5 >> 1 | sVar3 << 0xf;
      sVar3 = sVar3 >> 1;
    }
  }
  if (sVar3 < (short)(ushort)(uVar5 < 0x7fff)) {
    uVar2 = (ushort)(uVar5 < 0x8000);
    if (sVar3 + 1U == uVar2 && uVar5 == 0x8000 ||
        (short)((sVar3 + 1U) - uVar2) < 0 !=
        (SBORROW2(sVar3,-1) != SBORROW2(sVar3 + 1,(ushort)(uVar5 < 0x8000)))) {
      uVar5 = 0x8000;
    }
  }
  else {
    uVar5 = 0x7fff;
  }
  return uVar5;
}

