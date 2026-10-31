/* c2826e tbl2d_interp */

/* 2D 8-bit map lookup with bilinear interpolation. */

ushort tbl2d_interp(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  bool bVar1;
  ushort uVar2;
  short extraout_r1;
  ushort uVar3;
  short extraout_r1_00;
  ushort extraout_r2;
  short extraout_r3;
  short sVar4;
  short sVar5;
  short sVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  int iVar10;
  
  sVar6 = 8 - (ushort)*(byte *)((uint3)(param_1 + 2) +
                               (uint3)(param_2 + (0xfffd < param_1)) * 0x10000);
  uVar2 = (ushort)*(byte *)((uint3)param_1 + (uint3)param_2 * 0x10000);
  uVar9 = (param_4 >> 8) * uVar2 + (param_3 >> 8);
  uVar7 = param_1 + 3 + uVar9;
  uVar8 = param_2 + (0xfffc < param_1) + (ushort)CARRY2(param_1 + 3,uVar9);
  uVar9 = (ushort)*(byte *)((uint3)uVar7 + (uint3)uVar8 * 0x10000);
  sVar5 = sVar6;
  while (bVar1 = sVar5 != 0, sVar5 = sVar5 + -1, bVar1) {
    uVar9 = uVar9 * 2;
  }
  if ((param_3 & 0xff) == 0) {
    sVar5 = 0;
  }
  else {
    iVar10 = mul32();
    sVar5 = extraout_r1;
    if (iVar10 < 0) {
      uVar3 = -(short)iVar10;
      sVar5 = -((short)((uint)iVar10 >> 0x10) + (ushort)((short)iVar10 != 0));
      sVar4 = extraout_r1;
      while (bVar1 = sVar4 != 0, sVar4 = sVar4 + -1, bVar1) {
        uVar3 = uVar3 >> 1 | sVar5 << 0xf;
        sVar5 = sVar5 >> 1;
      }
      sVar4 = -uVar3;
    }
    else {
      while( true ) {
        sVar4 = (short)iVar10;
        bVar1 = sVar5 == 0;
        sVar5 = sVar5 + -1;
        if (bVar1) break;
        iVar10 = iVar10 >> 1;
      }
    }
    uVar9 = uVar9 + sVar4;
    sVar5 = extraout_r3;
  }
  if ((param_4 & 0xff) != 0) {
    uVar8 = uVar8 + CARRY2(uVar7,uVar2);
    do {
      bVar1 = sVar6 != 0;
      sVar6 = sVar6 + -1;
    } while (bVar1);
    if (sVar5 != 0) {
      sVar5 = mul32(*(undefined1 *)((uint3)(uVar7 + uVar2) + (uint3)uVar8 * 0x10000),0);
      sVar6 = extraout_r1_00;
      uVar8 = extraout_r2;
      if (sVar5 < 0) {
        do {
          bVar1 = sVar6 != 0;
          sVar6 = sVar6 + -1;
        } while (bVar1);
      }
      else {
        do {
          bVar1 = sVar6 != 0;
          sVar6 = sVar6 + -1;
        } while (bVar1);
      }
    }
    iVar10 = mul32(uVar8);
    if (iVar10 < 0) {
      uVar7 = -(short)iVar10;
      sVar5 = -((short)((uint)iVar10 >> 0x10) + (ushort)((short)iVar10 != 0));
      sVar6 = 8;
      while (bVar1 = sVar6 != 0, sVar6 = sVar6 + -1, bVar1) {
        uVar7 = uVar7 >> 1 | sVar5 << 0xf;
        sVar5 = sVar5 >> 1;
      }
      sVar6 = -uVar7;
    }
    else {
      sVar5 = 8;
      while( true ) {
        sVar6 = (short)iVar10;
        bVar1 = sVar5 == 0;
        sVar5 = sVar5 + -1;
        if (bVar1) break;
        iVar10 = iVar10 >> 1;
      }
    }
    uVar9 = uVar9 + sVar6;
  }
  return uVar9;
}


