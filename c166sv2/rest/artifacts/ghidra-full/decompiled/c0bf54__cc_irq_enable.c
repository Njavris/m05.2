// c0bf54 cc_irq_enable size=56 cc=unknown proto=undefined cc_irq_enable(void)

void cc_irq_enable(ushort param_1,short param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_2 == 0) {
    uVar1 = DAT_00c3c4;
    *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & ~(1 << (param_1 >> 1 & 0xf));
    return;
  }
  uVar2 = DAT_00c3c4;
  uVar1 = 1 << (param_1 >> 1 & 0xf);
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & ~uVar1 | uVar1;
  return;
}

