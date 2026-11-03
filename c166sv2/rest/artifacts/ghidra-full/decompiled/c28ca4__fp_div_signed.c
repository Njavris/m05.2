// c28ca4 fp_div_signed size=28 cc=unknown proto=undefined fp_div_signed(void)

void fp_div_signed(ushort param_1,ushort param_2,ushort param_3)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  ushort extraout_r1;
  ushort uVar6;
  ushort extraout_r2;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort unaff_r6;
  ushort uVar10;
  ushort unaff_r7;
  ushort uVar11;
  ushort unaff_r8;
  ushort unaff_r9;
  ushort uVar12;
  ushort in_r11;
  undefined4 uVar13;
  
  *(ushort *)(uint3)in_r11 =
       *(ushort *)(uint3)in_r11 & 0x7fff | (*(ushort *)(uint3)in_r11 >> 0xf ^ 1) << 0xf;
  uVar13 = fp_pack();
  uVar4 = (uint)uVar13 >> 0x10;
  if ((extraout_r2 != 0) && (extraout_r1 != 0)) {
    uVar6 = extraout_r1;
    uVar7 = extraout_r2;
    uVar10 = unaff_r6;
    uVar11 = unaff_r8;
    uVar12 = unaff_r9;
    if (extraout_r1 < extraout_r2) {
      uVar13 = CONCAT22(param_3,((ushort)uVar13 & 0xfffb | ((ushort)uVar13 & 1) << 2) >> 1);
      uVar6 = extraout_r2;
      uVar7 = extraout_r1;
      uVar10 = unaff_r7;
      unaff_r7 = unaff_r6;
      uVar11 = param_1;
      uVar12 = param_2;
      param_1 = unaff_r8;
      param_2 = unaff_r9;
      param_3 = (ushort)uVar4;
    }
    uVar9 = (ushort)((uint)uVar13 >> 0x10);
    uVar8 = 0;
    sVar3 = uVar7 - uVar6;
    if (sVar3 != 0) {
      uVar6 = -sVar3;
      uVar7 = uVar10;
      uVar10 = param_1;
      param_1 = param_2;
      if (sVar3 != -0x35 && 0x34 < (ushort)-sVar3) goto LAB_c28c92;
      while (param_2 = param_1, param_1 = uVar10, uVar10 = uVar7, 0xf < (short)uVar6) {
        uVar6 = uVar6 - 0x10;
        uVar8 = param_3;
        uVar7 = 0;
        param_3 = param_2;
      }
      if (uVar6 != 0) {
        uVar8 = uVar8 >> uVar6 | param_3 << -uVar6;
        param_3 = param_3 >> uVar6 | param_2 << -uVar6;
        param_2 = param_2 >> uVar6 | param_1 << -uVar6;
        param_1 = param_1 >> uVar6 | uVar10 << -uVar6;
        uVar10 = uVar10 >> uVar6;
      }
    }
    if (!(bool)((byte)(((ushort)uVar13 & 2) >> 1) ^ (byte)uVar13 & 1)) {
      fp_round();
      return;
    }
    uVar5 = -uVar8;
    bVar1 = uVar9 < param_3 || uVar9 == param_3 && uVar8 != 0;
    uVar8 = (uVar9 - param_3) - (ushort)(uVar8 != 0);
    bVar2 = uVar12 < param_2 || uVar12 == param_2 && bVar1;
    uVar6 = (uVar12 - param_2) - (ushort)bVar1;
    bVar1 = uVar11 < param_1 || uVar11 == param_1 && bVar2;
    uVar7 = (uVar11 - param_1) - (ushort)bVar2;
    uVar11 = (unaff_r7 - uVar10) - (ushort)bVar1;
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0)))) {
      fp_store_zero();
      return;
    }
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0))) ||
        (unaff_r7 < uVar10 || unaff_r7 == uVar10 && bVar1)) {
      uVar9 = ~uVar7;
      uVar10 = (ushort)(0xfffe < ~uVar5);
      uVar7 = (ushort)CARRY2(~uVar8,uVar10);
      uVar12 = (ushort)CARRY2(~uVar6,uVar7);
      uVar6 = ~uVar6 + uVar7;
      uVar7 = uVar9 + uVar12;
      uVar11 = ~uVar11 + (ushort)CARRY2(uVar9,uVar12);
      uVar5 = ~uVar5 + 1;
      uVar8 = ~uVar8 + uVar10;
    }
    while( true ) {
      while (uVar10 = uVar8, uVar8 = uVar5, uVar11 == 0 && uVar7 == 0) {
        uVar5 = 0;
        uVar7 = uVar6;
        uVar6 = uVar10;
      }
      if ((uVar11 & 0x10) != 0) break;
      uVar12 = (ushort)(CARRY2(uVar10,uVar10) || CARRY2(uVar10 * 2,(ushort)CARRY2(uVar8,uVar8)));
      uVar9 = (ushort)(CARRY2(uVar6,uVar6) || CARRY2(uVar6 * 2,uVar12));
      uVar6 = uVar6 * 2 + uVar12;
      uVar12 = uVar7 * 2;
      bVar1 = CARRY2(uVar7,uVar7);
      uVar7 = uVar7 * 2 + uVar9;
      uVar11 = uVar11 * 2 + (ushort)(bVar1 || CARRY2(uVar12,uVar9));
      uVar5 = uVar8 * 2;
      uVar8 = uVar10 * 2 + (ushort)CARRY2(uVar8,uVar8);
    }
    fp_round();
    return;
  }
LAB_c28c92:
  fp_store();
  return;
}

