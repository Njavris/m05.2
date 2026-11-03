/* c27fca tbl8_interp */

/* 8-bit table lookup with 8.8 fixed-point interpolation. */

ushort tbl8_interp(ushort param_1,short param_2,ushort param_3)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  ushort uVar6;
  short sVar7;
  int iVar8;
  
  sVar7 = 8 - (ushort)*(byte *)((uint3)(param_1 + 1) +
                               (uint3)(param_2 + (ushort)(0xfffe < param_1)) * 0x10000);
  uVar6 = param_1 + 2 + (param_3 >> 8);
  uVar2 = param_2 + (ushort)(0xfffd < param_1) + (ushort)CARRY2(param_1 + 2,param_3 >> 8);
  uVar3 = (ushort)*(byte *)((uint3)uVar6 + (uint3)uVar2 * 0x10000);
  uVar4 = uVar3;
  sVar5 = sVar7;
  while (bVar1 = sVar5 != 0, sVar5 = sVar5 + -1, bVar1) {
    uVar4 = uVar4 * 2;
  }
  if ((param_3 & 0xff) != 0) {
    sVar7 = 8 - sVar7;
    uVar6 = (ushort)*(byte *)((uint3)(uVar6 + 1) + (uint3)(uVar2 + (0xfffe < uVar6)) * 0x10000);
    iVar8 = mul32(uVar6 - uVar3,-(ushort)(uVar6 < uVar3));
    if (iVar8 < 0) {
      uVar6 = -(short)iVar8;
      sVar5 = -((short)((uint)iVar8 >> 0x10) + (ushort)((short)iVar8 != 0));
      while (bVar1 = sVar7 != 0, sVar7 = sVar7 + -1, bVar1) {
        uVar6 = uVar6 >> 1 | sVar5 << 0xf;
        sVar5 = sVar5 >> 1;
      }
      sVar5 = -uVar6;
    }
    else {
      while( true ) {
        sVar5 = (short)iVar8;
        bVar1 = sVar7 == 0;
        sVar7 = sVar7 + -1;
        if (bVar1) break;
        iVar8 = iVar8 >> 1;
      }
    }
    uVar4 = uVar4 + sVar5;
  }
  return uVar4;
}


