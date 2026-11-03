/* c0bca4 capcom_event_config */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configure one CAPCOM event channel. */

void capcom_event_config(ushort param_1,byte param_2,short param_3)

{
  ushort *puVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  
  uVar4 = PSW;
  PSW = uVar4 & 0xf7ff;
  if (param_3 != 0) {
    event_var_c40e = 1;
  }
  sVar2 = (param_1 & 0xff) * 0x12;
  sVar3 = (param_1 & 0xff) * 8;
  puVar1 = (ushort *)((short)&ram_var_c394 + sVar3);
  *(byte *)(uint3)(sVar2 + 0xc41d) = param_2;
  *(undefined2 *)(uint3)*puVar1 = *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar1);
  *(undefined2 *)(uint3)(sVar2 + 0xc41e) =
       *(undefined2 *)(uint3)(ushort)((short)&ram_var_c392 + sVar3);
  _cc16_irq_ptr = (ushort)&DAT_00fe28;
  _cc17_irq_ptr = SUB32(&DAT_00fe2a,0);
  _cc_compare_mode_ptr = SUB32(&DAT_00ff2c,0);
  _cc_compare_mode_shadow = SUB32(&CCM4,0);
  puVar1 = (ushort *)((short)&ram_var_c396 + sVar3);
  _t7_snapshot = SUB32(&T7,0);
  *(undefined2 *)(uint3)(sVar2 + 0xc420) = *(undefined2 *)ZEXT23(puVar1);
  *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) =
       *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) | 0x30 | param_1 & 0xff;
  *(ushort *)(uint3)_cc16_irq_ptr = *(ushort *)(uint3)_cc16_irq_ptr | 1 << (param_2 & 0xf);
  event_cancel(param_1 & 0xff,param_1);
  *(ushort *)(uint3)*puVar1 = *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) | 0x40;
  uVar4 = PSW;
  PSW = uVar4 | 0x800;
  return;
}


