// c12602 gap_c12602 size=118 cc=unknown proto=undefined gap_c12602(void)

undefined2 gap_c12602(ushort param_1,ushort param_2,ushort param_3)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  short in_r4;
  undefined1 uVar5;
  
  if (param_2 == 0 && param_1 < 0xc000) {
LAB_c1262a:
    if (param_2 != 0 || 0xf5ff < param_1) {
      uVar3 = (param_3 & 0xff) - 1;
      uVar1 = param_1 + uVar3;
      sVar2 = param_2 + ((short)uVar3 >> 0xf) + (ushort)CARRY2(param_1,uVar3);
      in_r4 = sVar2 - (ushort)(uVar1 < 0xfdff);
      if (in_r4 == 0 && uVar1 == 0xfdff || sVar2 == 0 && uVar1 < 0xfdff) goto LAB_c12672;
    }
    uVar5 = (undefined1)((ushort)in_r4 >> 8);
    uVar4 = 0;
    if (param_2 < 0xc0 || param_2 == 0xc0 && param_1 < (ushort)&DAT_005000) goto LAB_c12674;
    uVar3 = (param_3 & 0xff) - 1;
    uVar1 = param_1 + uVar3;
    uVar3 = param_2 + ((short)uVar3 >> 0xf) + (ushort)CARRY2(param_1,uVar3);
    uVar4 = 0;
    if (((short)&T2CON + uVar3 != (ushort)(uVar1 < 0xafff) || uVar1 != 0xafff) &&
        (0xbf < uVar3 && (uVar3 != 0xc0 || uVar1 >= 0xafff))) goto LAB_c12674;
  }
  else {
    uVar3 = (param_3 & 0xff) - 1;
    uVar1 = param_1 + uVar3;
    sVar2 = param_2 + ((short)uVar3 >> 0xf) + (ushort)CARRY2(param_1,uVar3);
    in_r4 = sVar2 - (ushort)(uVar1 < 0xcfff);
    if ((in_r4 != 0 || uVar1 != 0xcfff) && (sVar2 != 0 || uVar1 >= 0xcfff)) goto LAB_c1262a;
  }
LAB_c12672:
  uVar5 = (undefined1)((ushort)in_r4 >> 8);
  uVar4 = 1;
LAB_c12674:
  return CONCAT11(uVar5,uVar4);
}

