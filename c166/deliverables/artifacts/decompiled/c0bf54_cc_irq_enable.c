/* c0bf54 cc_irq_enable */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Sets or clears a per-channel CC interrupt-enable bit. */

void cc_irq_enable(ushort param_1,short param_2)

{
  ushort uVar1;
  
  if (param_2 == 0) {
    *(ushort *)(uint3)_cc_control_ptr =
         *(ushort *)(uint3)_cc_control_ptr & ~(1 << (param_1 >> 1 & 0xf));
    return;
  }
  uVar1 = 1 << (param_1 >> 1 & 0xf);
  *(ushort *)(uint3)_cc_control_ptr = *(ushort *)(uint3)_cc_control_ptr & ~uVar1 | uVar1;
  return;
}


