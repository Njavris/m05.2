/* c0e27c event_schedule_duration */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Schedules a CC16/CC17 event using the 32-bit duration fields. */

void event_schedule_duration(byte param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  short sVar6;
  ushort uVar7;
  ushort uVar8;
  
  sVar5 = (ushort)param_1 * 0x12;
  bVar1 = *(byte *)(uint3)(sVar5 + 0xc41dU);
  uVar2 = *(ushort *)(uint3)(sVar5 + 0xc412U) | *(ushort *)(uint3)(sVar5 + 0xc414);
  if (uVar2 == 0) {
    event_idle(param_1);
  }
  else {
    sVar6 = t7_timestamp_extended(uVar2);
    uVar4 = *(short *)(uint3)(ushort)((short)&cc16_17_channels + sVar5) - sVar6;
    uVar2 = *(ushort *)(uint3)(sVar5 + 0xc412U);
    uVar7 = uVar2 + _event_offset_2;
    uVar8 = *(short *)(uint3)(sVar5 + 0xc414) + (ushort)CARRY2(uVar2,_event_offset_2);
    uVar2 = sVar5 + 0xc41c;
    if ((*(byte *)(uint3)uVar2 & 8) == 0) {
      uVar3 = uVar7 >> 8 | uVar8 * 0x100;
      uVar7 = _event_offset_3 + uVar3;
      uVar8 = (uVar8 >> 8) + (ushort)CARRY2(_event_offset_3,uVar3);
    }
    else {
      uVar3 = (uVar8 - *(short *)(uint3)(sVar5 + 0xc418)) -
              (ushort)(uVar7 < *(ushort *)(uint3)(sVar5 + 0xc416));
      uVar8 = uVar7 - *(ushort *)(uint3)(sVar5 + 0xc416) >> 8 | uVar3 * 0x100;
      uVar7 = _event_offset_0 + uVar8;
      uVar8 = (uVar3 >> 8) + (ushort)CARRY2(_event_offset_0,uVar8);
    }
    if ((uVar8 != (uVar7 != 0xffff) || uVar7 != 0xffff) && (uVar8 != 0 || uVar7 == 0xffff)) {
      uVar7 = 0xffff;
      uVar8 = 0;
    }
    if (uVar7 < uVar4) {
      uVar4 = uVar4 - uVar7;
      if (0x7f < uVar4) {
        *(short *)(uint3)*(ushort *)(uint3)(sVar5 + 0xc41e) = *(short *)(uint3)_t7_snapshot + 0x7000
        ;
        sVar5 = (bVar1 & 0xf) << 2;
        *(ushort *)(uint3)_cc_compare_mode_shadow =
             *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar5);
        *(ushort *)(uint3)_cc_compare_mode_shadow =
             *(ushort *)(uint3)_cc_compare_mode_shadow | 4 << sVar5;
        cc_irq_enable_bit(bVar1);
        *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 4;
        return;
      }
      bVar1 = *(byte *)(uint3)(sVar5 + 0xc41dU);
      *(ushort *)(uint3)*(ushort *)(uint3)(sVar5 + 0xc41e) =
           *(short *)(uint3)_t7_snapshot + uVar4 * 0x100;
      sVar5 = (bVar1 & 0xf) << 2;
      *(ushort *)(uint3)_cc_compare_mode_shadow =
           *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar5);
      *(ushort *)(uint3)_cc_compare_mode_shadow =
           *(ushort *)(uint3)_cc_compare_mode_shadow | 5 << sVar5;
      cc_irq_enable_bit(bVar1);
    }
    else {
      event_force(param_1,uVar8);
    }
    *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xfb;
  }
  return;
}


