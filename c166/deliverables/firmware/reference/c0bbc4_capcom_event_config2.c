/* c0bbc4 capcom_event_config2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configure one CAPCOM event channel (second form). */

void capcom_event_config2
               (byte param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 unaff_00000000,undefined2 unaff_00000002)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  sVar1 = (ushort)param_1 * 0x12;
  *(undefined2 *)(uint3)(sVar1 + 0xc412) = param_2;
  *(undefined2 *)(uint3)(sVar1 + 0xc414) = param_3;
  *(undefined2 *)(uint3)(ushort)((short)&cc16_17_channels + sVar1) = param_4;
  _event_offset_3 = unaff_00000000;
  _event_offset_0 = unaff_00000002;
  event_schedule(param_1);
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return;
}


