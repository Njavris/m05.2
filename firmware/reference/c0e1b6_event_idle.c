/* c0e1b6 event_idle */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Set channel to idle. */

void event_idle(byte param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  
  sVar3 = (ushort)param_1 * 0x12;
  bVar1 = *(byte *)(uint3)(sVar3 + 0xc41d);
  cc_compare_mode_set(param_1);
  uVar2 = sVar3 + 0xc41c;
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xdf;
  *(short *)(uint3)*(ushort *)(uint3)(sVar3 + 0xc41e) = *(short *)(uint3)_t7_snapshot + 0x7000;
  sVar4 = (bVar1 & 0xf) << 2;
  *(ushort *)(uint3)_cc_compare_mode_shadow =
       *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar4);
  *(ushort *)(uint3)_cc_compare_mode_shadow = *(ushort *)(uint3)_cc_compare_mode_shadow | 4 << sVar4
  ;
  cc_irq_enable_bit(bVar1);
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 4;
  *(ushort *)(uint3)*(ushort *)(uint3)(sVar3 + 0xc420) =
       *(ushort *)(uint3)*(ushort *)(uint3)(sVar3 + 0xc420) & 0xff7f;
  return;
}


