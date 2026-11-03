// c0fca6 FUN_c0fca6 size=220 cc=unknown proto=undefined FUN_c0fca6(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c0fca6(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  short sVar5;
  
  DAT_00fa20 = &stack0x0000;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar3 = DPP2;
  DPP2 = 0x303;
  uVar4 = PSW;
  PSW = uVar4 & 0xf7ff;
  if ((DAT_c06b69 == '\0') && (cVar1 = DAT_00fd0a._0_1_, cVar1 != '\x03')) goto LAB_c0fd72;
  sVar5 = cc_irq_is_enabled(_DAT_007046,uVar3,uVar2);
  if ((sVar5 == 1) && (sVar5 = cc_irq_is_enabled(_DAT_007048,uVar3,uVar2), sVar5 == 1)) {
    sVar5 = DAT_00c47e;
    if (sVar5 == 0) {
      FUN_c0fc42(0);
      FUN_c0fc42(1);
      ssc_state_reset();
      DAT_00c47e = 1;
      goto LAB_c0fd72;
    }
    sVar5 = DAT_00c47e;
    if (sVar5 != 3) goto LAB_c0fd72;
    cVar1 = DAT_00c47a;
    DAT_00c47a = cVar1 + '\x01';
    FUN_c0fc42(0);
  }
  else {
    sVar5 = DAT_00c47e;
    if (sVar5 == 0) {
      sVar5 = cc_irq_is_enabled(_DAT_007046,uVar3,uVar2);
      if (sVar5 == 1) {
        cVar1 = DAT_00fd12;
        DAT_00fd12 = cVar1 + '\x01';
        FUN_c0fc42(0);
      }
      sVar5 = cc_irq_is_enabled(_DAT_007048,uVar3,uVar2);
      if (sVar5 != 1) goto LAB_c0fd72;
      cVar1 = DAT_00fd0e;
      DAT_00fd0e = cVar1 + '\x01';
    }
    else {
      sVar5 = DAT_00c47e;
      if (sVar5 == 2) {
        cVar1 = DAT_00c480;
        DAT_00c480 = cVar1 + '\x01';
        FUN_c0fc42(0);
      }
      sVar5 = DAT_00c47e;
      if (sVar5 != 1) goto LAB_c0fd72;
      cVar1 = DAT_00c47b;
      DAT_00c47b = cVar1 + '\x01';
    }
  }
  FUN_c0fc42(1);
LAB_c0fd72:
  uVar4 = PSW;
  PSW = uVar4 | 0x800;
  DPP2 = uVar3;
  uVar3 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}

