// c27f0e gap_c27f0e size=188 cc=unknown proto=undefined gap_c27f0e(void)

ushort gap_c27f0e(short param_1,ushort param_2)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  
  sVar6 = 8 - (ushort)*(byte *)(uint3)(param_1 + 1);
  uVar5 = param_1 + 2 + (param_2 >> 8);
  uVar2 = (ushort)*(char *)(uint3)uVar5;
  uVar3 = uVar2;
  sVar4 = sVar6;
  while (bVar1 = sVar4 != 0, sVar4 = sVar4 + -1, bVar1) {
    uVar3 = uVar3 * 2;
  }
  if ((param_2 & 0xff) != 0) {
    sVar6 = 8 - sVar6;
    uVar5 = (ushort)*(char *)(uint3)(uVar5 + 1);
    iVar7 = mul32(uVar5 - uVar2,
                  (((short)uVar5 >> 0xf) - ((short)uVar2 >> 0xf)) - (ushort)(uVar5 < uVar2));
    if (iVar7 < 0) {
      uVar5 = -(short)iVar7;
      sVar4 = -((short)((uint)iVar7 >> 0x10) + (ushort)((short)iVar7 != 0));
      while (bVar1 = sVar6 != 0, sVar6 = sVar6 + -1, bVar1) {
        uVar5 = uVar5 >> 1 | sVar4 << 0xf;
        sVar4 = sVar4 >> 1;
      }
      sVar4 = -uVar5;
    }
    else {
      while( true ) {
        sVar4 = (short)iVar7;
        bVar1 = sVar6 == 0;
        sVar6 = sVar6 + -1;
        if (bVar1) break;
        iVar7 = iVar7 >> 1;
      }
    }
    uVar3 = uVar3 + sVar4;
  }
  return uVar3;
}

