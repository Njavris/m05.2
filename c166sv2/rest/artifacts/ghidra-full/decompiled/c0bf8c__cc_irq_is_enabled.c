// c0bf8c cc_irq_is_enabled size=36 cc=unknown proto=undefined cc_irq_is_enabled(void)

undefined2 cc_irq_is_enabled(ushort param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  
  uVar2 = DAT_00c3c4;
  uVar1 = 1 << (param_1 >> 1 & 0xf);
  if (((*(ushort *)(uint3)uVar2 & uVar1) == 0) || (uVar1 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

