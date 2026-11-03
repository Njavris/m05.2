// c0c5de FUN_c0c5de size=124 cc=unknown proto=undefined FUN_c0c5de(void)

undefined4 FUN_c0c5de(void)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short sVar7;
  
  uVar6 = PSW;
  PSW = uVar6 & 0xf7ff;
  uVar5 = CC24;
  uVar2 = DAT_00c4c8;
  uVar6 = uVar2 * 8 + uVar5;
  sVar7 = (uVar2 >> 0xd) + (ushort)CARRY2(uVar2 * 8,uVar5);
  uVar2 = T7;
  uVar4 = T7;
  if ((uVar5 == uVar4 || uVar5 < uVar2) || (uVar2 = T7IC, (uVar2 & 0x80) != 0)) {
    uVar2 = T7IC;
    if ((uVar2 & 0x80) != 0) {
      uVar2 = T7;
      uVar4 = T7;
      if (uVar5 == uVar4 || uVar5 < uVar2) {
        sVar3 = DAT_00c4c8;
        if (sVar3 == -0x2000) {
          sVar7 = 0;
          uVar6 = uVar5;
        }
        else {
          sVar7 = sVar7 + 1;
        }
      }
    }
  }
  else {
    sVar3 = DAT_00c4c8;
    if (sVar3 == 0) {
      sVar3 = DAT_00c4c8;
      bVar1 = CARRY2(uVar6,sVar3 * 8);
      uVar6 = uVar6 + sVar3 * 8;
      sVar7 = sVar7 + (sVar3 + 0xe000U >> 0xd) + (ushort)bVar1;
    }
    else {
      sVar7 = sVar7 + -1;
    }
  }
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return CONCAT22(sVar7,uVar6);
}

