// c277b2 gap_c277b2 size=80 cc=unknown proto=undefined gap_c277b2(void)

ushort gap_c277b2(ushort param_1,ushort param_2,short param_3)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  
  sVar4 = 0;
  while (bVar1 = param_3 != 0, param_3 = param_3 + -1, bVar1) {
    bVar1 = CARRY2(param_1,param_1);
    param_1 = param_1 * 2;
    sVar4 = sVar4 * 2 + (ushort)bVar1;
  }
  uVar3 = param_1 + param_2;
  sVar4 = sVar4 + ((short)param_2 >> 0xf) + (ushort)CARRY2(param_1,param_2);
  if (sVar4 < (short)(ushort)(uVar3 < 0x7fff)) {
    uVar2 = (ushort)(uVar3 < 0x8000);
    if (sVar4 + 1U == uVar2 && uVar3 == 0x8000 ||
        (short)((sVar4 + 1U) - uVar2) < 0 !=
        (SBORROW2(sVar4,-1) != SBORROW2(sVar4 + 1,(ushort)(uVar3 < 0x8000)))) {
      uVar3 = 0x8000;
    }
  }
  else {
    uVar3 = 0x7fff;
  }
  return uVar3;
}

