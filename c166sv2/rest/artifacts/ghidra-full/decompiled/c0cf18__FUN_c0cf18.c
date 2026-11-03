// c0cf18 FUN_c0cf18 size=48 cc=unknown proto=undefined FUN_c0cf18(void)

void FUN_c0cf18(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  
  DAT_00fa00 = &stack0x0000;
  uVar1 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x303;
  uVar4 = PSW;
  PSW = uVar4 | 0x800;
  FUN_c11f10(uVar2,uVar1);
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}

