/* c27ca4 tbl16_interp */

/* 16-bit table lookup with 8.8 fixed-point interpolation. */

ushort tbl16_interp(ushort param_1,short param_2,ushort param_3)

{
  bool bVar1;
  short sVar2;
  short extraout_r1;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  
  uVar5 = param_3 >> 8;
  uVar6 = param_1 + 2 + uVar5 * 2;
  uVar5 = *(ushort *)
           ((uint3)uVar6 +
           (uint3)(param_2 + (ushort)(0xfffd < param_1) + (ushort)CARRY2(uVar5,uVar5) +
                  (ushort)CARRY2(param_1 + 2,uVar5 * 2)) * 0x10000);
  if ((param_3 & 0xff) != 0) {
    uVar6 = *(ushort *)(uVar6 + 2);
    sVar3 = uVar6 - uVar5;
    sVar2 = -(ushort)(uVar6 < uVar5);
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


