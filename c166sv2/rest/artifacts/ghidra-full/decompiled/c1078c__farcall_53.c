// c1078c farcall_53 size=296 cc=unknown proto=undefined farcall_53(void)

void farcall_53(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  ushort uVar8;
  ushort uVar9;
  short sVar10;
  short sVar11;
  byte local_12;
  
  DAT_00fc80 = &stack0x0000;
  uVar5 = DPP0;
  DPP0 = 0x301;
  uVar6 = DPP2;
  DPP2 = 0x303;
  uVar9 = PSW;
  PSW = uVar9 & 0xf7ff;
  uVar8 = CC21;
  local_12 = DAT_00c4da;
  uVar9 = T8;
  uVar1 = T8IC;
  if (((uVar1 & 0x80) == 0) && (uVar9 < uVar8)) {
    local_12 = local_12 - 1;
  }
  uVar9 = (ushort)local_12;
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  if ((DAT_c05068 != 0) && (DAT_c05068 != 4)) goto LAB_c108a4;
  DAT_00c4cc = 0;
  uVar1 = BUSCON2;
  if ((uVar1 & 0x20) == 0) {
    DAT_00c4ce = uVar8;
    DAT_00c4d0 = uVar9;
    goto LAB_c108a4;
  }
  uVar1 = BUSCON2;
  if ((uVar1 & 0x20) == 0) goto LAB_c108a4;
  uVar1 = DAT_00c4d6;
  uVar2 = DAT_00c4d8;
  if (uVar9 - uVar2 == (ushort)(uVar8 < uVar1) && uVar8 == uVar1 ||
      (uVar9 < uVar2 || uVar9 == uVar2 && uVar8 < uVar1)) {
    sVar11 = DAT_00c4d6;
    uVar1 = -sVar11 - 1;
    sVar11 = DAT_00c4d8;
    DAT_00c4d2 = uVar8 + uVar1;
    DAT_00c4d4 = uVar9 + (0xff - sVar11) + (ushort)CARRY2(uVar8,uVar1);
    uVar2 = DAT_00c4ce;
    uVar3 = DAT_00c4d0;
    if (uVar9 < uVar3 || uVar9 == uVar3 && uVar8 < uVar2) goto LAB_c10860;
    uVar2 = DAT_00c4ce;
    sVar10 = uVar1 + uVar2;
    sVar4 = DAT_00c4d0;
    sVar11 = (0xff - sVar11) + sVar4 + (ushort)CARRY2(uVar1,uVar2);
  }
  else {
    uVar1 = DAT_00c4d6;
    sVar11 = DAT_00c4d8;
    DAT_00c4d2 = uVar8 - uVar1;
    DAT_00c4d4 = (uVar9 - sVar11) - (ushort)(uVar8 < uVar1);
LAB_c10860:
    uVar1 = DAT_00c4ce;
    sVar11 = DAT_00c4d0;
    uVar2 = DAT_00c4d6;
    sVar10 = uVar1 - uVar2;
    sVar4 = DAT_00c4d8;
    sVar11 = (sVar11 - sVar4) - (ushort)(uVar1 < uVar2);
  }
  mul32(sVar10,sVar11,uVar6,uVar5);
  uVar7 = DAT_00c4d2;
  uVar7 = DAT_00c4d4;
  uVar7 = div32u();
  DAT_00c4dc = uVar7;
  DAT_00c4d6 = uVar8;
  DAT_00c4d8 = uVar9;
LAB_c108a4:
  DPP2 = uVar6;
  uVar6 = DPP2;
  uVar6 = DPP2;
  uVar6 = DPP2;
  DPP0 = uVar5;
  uVar5 = DPP0;
  uVar5 = DPP0;
  uVar5 = DPP0;
  return;
}

