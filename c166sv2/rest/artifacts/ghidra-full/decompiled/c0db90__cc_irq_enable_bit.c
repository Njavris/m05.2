// c0db90 cc_irq_enable_bit size=22 cc=unknown proto=undefined cc_irq_enable_bit(void)

void cc_irq_enable_bit(char param_1)

{
  ushort uVar1;
  
  if (param_1 != '\x10') {
    uVar1 = DAT_00fe2a;
    DAT_00fe2a = uVar1 | 2;
    return;
  }
  uVar1 = DAT_00fe2a;
  DAT_00fe2a = uVar1 | 1;
  return;
}

