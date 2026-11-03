// c288c2 gap_c288c2 size=56 cc=unknown proto=undefined gap_c288c2(void)

undefined4 gap_c288c2(ushort param_1,short param_2,ushort param_3,short param_4)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  uVar2 = param_1 - param_3;
  sVar3 = (param_2 - param_4) - (ushort)(param_1 < param_3);
  if (param_4 == 0 && param_3 == 0 || param_4 < 0) {
    if ((short)((sVar3 - param_2) - (ushort)(uVar2 < param_1)) < 0 !=
        (SBORROW2(sVar3,param_2) != SBORROW2(sVar3 - param_2,(ushort)(uVar2 < param_1)))) {
      uVar2 = 0xffff;
      sVar3 = 0x7fff;
    }
  }
  else {
    uVar1 = (ushort)(uVar2 < param_1);
    if ((sVar3 - param_2 != uVar1 || uVar2 != param_1) &&
        (short)((sVar3 - param_2) - uVar1) < 0 ==
        (SBORROW2(sVar3,param_2) != SBORROW2(sVar3 - param_2,(ushort)(uVar2 < param_1)))) {
      uVar2 = 0;
      sVar3 = -0x8000;
    }
  }
  return CONCAT22(sVar3,uVar2);
}

