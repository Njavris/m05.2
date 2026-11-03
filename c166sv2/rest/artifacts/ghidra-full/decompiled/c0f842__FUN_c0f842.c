// c0f842 FUN_c0f842 size=156 cc=unknown proto=undefined FUN_c0f842(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c0f842(void)

{
  undefined2 uVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  short sVar6;
  
  DAT_00fc00 = &stack0x0000;
  uVar4 = DPP0;
  uVar5 = DPP0;
  uVar5 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP2 = 0x303;
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  uVar3 = CC7IC;
  CC7IC = uVar3 & 0xffbf;
  uVar3 = DAT_00fe2a;
  DAT_00fe2a = uVar3 & 0xff7f;
  uVar3 = CC7IC;
  CC7IC = uVar3 | 0x40;
  sVar6 = cc_irq_is_enabled(_DAT_007046,uVar5,uVar4);
  if (sVar6 == 1) {
    sVar6 = FUN_c0faa2(0);
    if (sVar6 != 1) {
      uVar3 = DAT_00fd08;
      DAT_00fd08 = uVar3 | 0x10;
      uVar1 = DAT_00c3d2;
      DAT_00c3ce = uVar1;
      uVar3 = DAT_00fd08;
      if (((uVar3 & 1) == 0) ||
         ((uVar3 = DAT_00fd08, (uVar3 & 0x1000) == 0 && (uVar3 = DAT_00fd08, (uVar3 & 2) == 0)))) {
        sVar6 = DAT_00c3ce;
        sVar2 = DAT_00c472;
        FUN_c0fa2a(sVar6 + sVar2,0);
        uVar3 = DAT_00fd08;
        DAT_00fd08 = uVar3 | 0x20;
      }
      else {
        sVar2 = DAT_00c3d4;
        sVar6 = DAT_00c3cc;
        FUN_c0fa2a(sVar2 + sVar6,0);
      }
    }
  }
  else {
    sVar6 = FUN_c0faf8(0);
    if (sVar6 != 1) {
      uVar1 = DAT_00c3d2;
      DAT_00c3d0 = uVar1;
      FUN_c0f55a(0);
    }
  }
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
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

