// c0da8c FUN_c0da8c size=166 cc=unknown proto=undefined FUN_c0da8c(void)

void FUN_c0da8c(void)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  short sVar6;
  undefined2 uVar7;
  char cVar8;
  
  DAT_00faa0 = &stack0x0000;
  uVar4 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  DPP2 = 0x303;
  sVar2 = DAT_00c3aa;
  if (sVar2 == 0) {
    FUN_c19aa6(uVar5,uVar4);
    cVar8 = FUN_c243a8(0x14);
    if ((cVar8 == '\0') && (cVar8 = FUN_c243a8(0x15), cVar8 == '\0')) {
      if (DAT_c05081 == '\x01') {
        uVar7 = P1L;
        uVar1 = P1L;
        uVar3 = P1L;
        P1L = uVar3 & 0xffef | ((uVar1 & 0x10) >> 4 ^ 1) << 4;
      }
    }
    else {
      uVar1 = P1L;
      P1L = uVar1 & 0xffef;
    }
  }
  else {
    uVar1 = DAT_00c3a6;
    uVar3 = DAT_00c3a8;
    if (uVar3 == uVar1 < 0xff00 && uVar1 == 0xff00 || uVar3 == 0 && uVar1 < 0xff00) {
      DAT_00c3aa = 0;
      sVar2 = DAT_00c3a6;
      sVar6 = CC24;
      uVar1 = DAT_00c48e;
      *(short *)(uint3)uVar1 = sVar2 + sVar6;
    }
    else {
      uVar1 = DAT_00c3a6;
      DAT_00c3a6 = uVar1 + 0x100;
      sVar2 = DAT_00c3a8;
      DAT_00c3a8 = sVar2 - (ushort)(uVar1 < 0xff00);
      DAT_00c3aa = 1;
      sVar2 = CC24;
      uVar1 = DAT_00c48e;
      *(short *)(uint3)uVar1 = sVar2 + -0x100;
    }
  }
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

