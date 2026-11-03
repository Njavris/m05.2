// c0d040 FUN_c0d040 size=54 cc=unknown proto=undefined FUN_c0d040(void)

void FUN_c0d040(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  DAT_00fa40 = &stack0x0000;
  uVar2 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  DPP0 = 0x301;
  uVar3 = DPP2;
  uVar4 = DPP2;
  uVar4 = DPP2;
  DPP2 = 0x303;
  uVar1 = DAT_00fd18;
  if ((uVar1 & 0x80) == 0) {
    FUN_c0c6f2(uVar3,uVar2);
  }
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

