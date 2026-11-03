/* c0bf8c cc_irq_is_enabled */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Tests a per-channel CC interrupt-enable bit in 0xFF2C. */

undefined2 cc_irq_is_enabled(ushort param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  
  uVar1 = 1 << (param_1 >> 1 & 0xf);
  if (((*(ushort *)(uint3)_cc_control_ptr & uVar1) == 0) || (uVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


