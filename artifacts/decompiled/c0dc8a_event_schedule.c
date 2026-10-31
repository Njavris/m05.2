/* c0dc8a event_schedule */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Schedule CAPCOM event (dwell/pulse) for a channel. */

void event_schedule(byte param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  ushort uVar7;
  short sVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  
  sVar6 = (ushort)param_1 * 0x12;
  uVar2 = sVar6 + 0xc41c;
  puVar3 = (ushort *)(sVar6 + 0xc41e);
  uVar7 = (ushort)*(byte *)(uint3)(sVar6 + 0xc41d);
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xe3;
  uVar10 = *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar3);
  uVar1 = *(undefined2 *)(uint3)_t7_snapshot;
  cc_compare_mode_set(param_1);
  uVar9 = uVar10;
  if (((*(byte *)(uint3)uVar2 & 1) == 0) ||
     (((*(byte *)(uint3)uVar2 & 4) == 0 &&
      (uVar9 = uVar1, (**(ushort **)(uint3)(sVar6 + 0xc420) & 0x80) == 0)))) {
    *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar3) = uVar1;
    uVar10 = uVar9;
  }
  *(ushort *)(uint3)*(ushort *)(uint3)(sVar6 + 0xc420) =
       *(ushort *)(uint3)*(ushort *)(uint3)(sVar6 + 0xc420) & 0xff7f;
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 0x20;
  if ((*(byte *)(uint3)uVar2 & 1) == 0) {
    if ((*(byte *)(uint3)uVar2 & 2) == 0) {
      event_schedule_duration(param_1);
    }
    else {
      if (_event_offset_1 < (*(short *)(uint3)_t7_snapshot - *(short *)(sVar6 + -0x3be6)) + 10U) {
        *(short *)(uint3)*(ushort *)ZEXT23(puVar3) = *(short *)(uint3)_t7_snapshot + 10;
      }
      else {
        *(ushort *)(uint3)*(ushort *)ZEXT23(puVar3) =
             *(short *)ZEXT23((short *)(sVar6 + -0x3be6)) + _event_offset_1;
      }
      sVar6 = (uVar7 & 0xf) << 2;
      *(ushort *)(uint3)_cc_compare_mode_shadow =
           *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar6);
      *(ushort *)(uint3)_cc_compare_mode_shadow =
           *(ushort *)(uint3)_cc_compare_mode_shadow | 4 << sVar6;
      cc_irq_enable_bit(uVar7);
    }
  }
  else {
    event_accum(param_1,uVar10);
    *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xfe;
    uVar5 = *(ushort *)(uint3)(sVar6 + 0xc412U) | *(ushort *)(uint3)(sVar6 + 0xc414);
    if (uVar5 == 0) {
      event_idle(param_1);
    }
    else {
      sVar8 = t7_timestamp_extended(uVar5);
      uVar5 = *(ushort *)(uint3)(sVar6 + 0xc412U);
      uVar4 = uVar5 + _event_offset_2;
      if ((uVar4 + _event_offset_1 >> 8 |
          (*(short *)(uint3)(sVar6 + 0xc414) + (ushort)CARRY2(uVar5,_event_offset_2) +
          (ushort)CARRY2(uVar4,_event_offset_1)) * 0x100) <
          (ushort)(*(short *)(uint3)(ushort)((short)&cc16_17_channels + sVar6) - sVar8)) {
        *(ushort *)(uint3)*puVar3 = *(short *)(uint3)_t7_snapshot + _event_offset_1;
        sVar6 = (uVar7 & 0xf) << 2;
        *(ushort *)(uint3)_cc_compare_mode_shadow =
             *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar6);
        *(ushort *)(uint3)_cc_compare_mode_shadow =
             *(ushort *)(uint3)_cc_compare_mode_shadow | 4 << sVar6;
        cc_irq_enable_bit(uVar7,0);
        *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 2;
      }
      else {
        event_force(param_1);
        *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 0x40;
      }
    }
  }
  return;
}


