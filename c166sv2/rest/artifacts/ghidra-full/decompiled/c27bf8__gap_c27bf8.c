// c27bf8 gap_c27bf8 size=172 cc=unknown proto=undefined gap_c27bf8(void)

ushort gap_c27bf8(short param_1,ushort param_2)

{
  bool bVar1;
  short sVar2;
  short extraout_r1;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  
  uVar6 = param_1 + 2 + (param_2 >> 8) * 2;
  uVar5 = *(ushort *)(uint3)uVar6;
  if ((param_2 & 0xff) != 0) {
    uVar6 = *(ushort *)(uVar6 + 2);
    sVar3 = uVar6 - uVar5;
    sVar2 = (((short)uVar6 >> 0xf) - ((short)uVar5 >> 0xf)) - (ushort)(uVar6 < uVar5);
    sVar4 = sVar2;
    if (sVar2 < 0) {
      bVar1 = sVar3 != 0;
      sVar3 = -sVar3;
      sVar4 = -(sVar2 + (ushort)bVar1);
    }
    uVar7 = mul32(sVar3,sVar4,8);
    sVar3 = extraout_r1;
    while( true ) {
      sVar4 = (short)uVar7;
      bVar1 = sVar3 == 0;
      sVar3 = sVar3 + -1;
      if (bVar1) break;
      uVar7 = uVar7 >> 1;
    }
    if (sVar2 < 0) {
      sVar4 = -sVar4;
    }
    uVar5 = uVar5 + sVar4;
  }
  return uVar5;
}

