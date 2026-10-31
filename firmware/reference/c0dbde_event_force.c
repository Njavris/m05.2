/* c0dbde event_force */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Force event at fixed offset. */

void event_force(ushort param_1)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  
  sVar3 = (param_1 & 0xff) * 0x12;
  bVar1 = *(byte *)(uint3)(sVar3 + 0xc41d);
  bVar2 = bVar1 & 0xf;
  if (((*(ushort *)(uint3)_cc_compare_mode_ptr & 1 << bVar2) != 0) == (event_var_c40e == '\0')) {
    *(short *)(uint3)*(ushort *)(uint3)(sVar3 + 0xc41e) = *(short *)(uint3)_t7_snapshot + 10;
  }
  sVar3 = (ushort)bVar2 << 2;
  *(ushort *)(uint3)_cc_compare_mode_shadow =
       *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar3);
  *(ushort *)(uint3)_cc_compare_mode_shadow = *(ushort *)(uint3)_cc_compare_mode_shadow | 5 << sVar3
  ;
  cc_irq_enable_bit(bVar1);
  return;
}


