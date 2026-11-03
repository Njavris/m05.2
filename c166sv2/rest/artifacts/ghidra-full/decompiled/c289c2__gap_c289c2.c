// c289c2 gap_c289c2 size=72 cc=unknown proto=undefined gap_c289c2(void)

ushort gap_c289c2(ushort param_1,ushort param_2,short param_3)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  
  sVar3 = 0;
  while (bVar1 = param_3 != 0, param_3 = param_3 + -1, bVar1) {
    bVar1 = CARRY2(param_2,param_2);
    param_2 = param_2 * 2;
    sVar3 = sVar3 * 2 + (ushort)bVar1;
  }
  uVar4 = param_1 - param_2;
  sVar3 = -(ushort)(param_1 < param_2) - sVar3;
  if (sVar3 < (short)(ushort)(uVar4 < 0x7fff)) {
    uVar2 = (ushort)(uVar4 < 0x8000);
    if (sVar3 + 1U == uVar2 && uVar4 == 0x8000 ||
        (short)((sVar3 + 1U) - uVar2) < 0 !=
        (SBORROW2(sVar3,-1) != SBORROW2(sVar3 + 1,(ushort)(uVar4 < 0x8000)))) {
      uVar4 = 0x8000;
    }
  }
  else {
    uVar4 = 0x7fff;
  }
  return uVar4;
}

