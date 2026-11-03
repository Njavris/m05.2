// c0bdc8 FUN_c0bdc8 size=126 cc=unknown proto=undefined FUN_c0bdc8(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c0bdc8(void)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  ushort uVar7;
  ushort uVar8;
  
  DAT_00fa80 = &stack0x0000;
  uVar4 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  DPP2 = 0x303;
  T4 = 0xff83;
  sVar1 = DAT_00cb60;
  if (sVar1 == DAT_c07d76) {
    DAT_00c3a0 = 1;
  }
  sVar1 = DAT_00c3a0;
  if (sVar1 == 1) {
    DAT_00c3a4 = 0;
  }
  else {
    cVar2 = DAT_00c3a2;
    DAT_00c3a2 = cVar2 + '\x01';
    bVar3 = DAT_00c3a2;
    if (100 < bVar3) {
      DAT_00c3a2 = 0;
      FUN_c14824(uVar5,uVar4);
    }
    bVar3 = DAT_00c3a2;
    if ((ushort)bVar3 < (ushort)(_DAT_e008ca * 2)) {
      uVar6 = BUSCON2;
      uVar7 = BUSCON2;
      uVar8 = BUSCON2;
      BUSCON2 = uVar8 & 0xfffd | ((uVar7 & 2) >> 1 ^ 1) << 1;
      goto LAB_c0be38;
    }
  }
  uVar7 = BUSCON2;
  BUSCON2 = uVar7 & 0xfffd;
LAB_c0be38:
  DPP2 = uVar5;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar4;
  uVar4 = DPP0;
  uVar4 = DPP0;
  uVar4 = DPP0;
  return;
}

