// c28450 gap_c28450 size=76 cc=unknown proto=undefined gap_c28450(void)

ushort gap_c28450(void)

{
  ushort uVar1;
  ushort extraout_r1;
  short extraout_r2;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  undefined4 uVar6;
  
  uVar4 = 0x8000;
  sVar5 = -1;
  uVar6 = mul32();
  sVar3 = (short)((uint)uVar6 >> 0x10);
  uVar2 = (ushort)uVar6;
  if ((short)((sVar3 - extraout_r2) - (ushort)(uVar2 < extraout_r1)) < 0 ==
      (SBORROW2(sVar3,extraout_r2) != SBORROW2(sVar3 - extraout_r2,(ushort)(uVar2 < extraout_r1))))
  {
    uVar2 = 0x7fff;
  }
  else {
    uVar1 = (ushort)(uVar2 < uVar4);
    if (sVar3 - sVar5 == uVar1 && uVar2 == uVar4 ||
        (short)((sVar3 - sVar5) - uVar1) < 0 !=
        (SBORROW2(sVar3,sVar5) != SBORROW2(sVar3 - sVar5,(ushort)(uVar2 < uVar4)))) {
      uVar2 = 0x8000;
    }
  }
  return uVar2;
}

