// c0e27c event_schedule_duration size=350 cc=unknown proto=undefined event_schedule_duration(void)

void event_schedule_duration(byte param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short sVar7;
  short sVar8;
  ushort uVar9;
  ushort uVar10;
  
  sVar7 = (ushort)param_1 * 0x12;
  uVar2 = (short)&UNK_00c412 + sVar7;
  uVar3 = (short)&UNK_00c41d + sVar7;
  bVar1 = *(byte *)(uint3)uVar3;
  uVar9 = *(ushort *)(uint3)uVar2 | *(ushort *)(uint3)(ushort)((short)&UNK_00c414 + sVar7);
  if (uVar9 == 0) {
    event_idle(param_1);
  }
  else {
    sVar8 = t7_timestamp_extended(uVar9);
    uVar5 = *(short *)(uint3)(ushort)((short)&UNK_00c410 + sVar7) - sVar8;
    uVar2 = *(ushort *)(uint3)uVar2;
    uVar10 = DAT_00c408;
    uVar9 = uVar2 + uVar10;
    uVar10 = *(short *)(uint3)(ushort)((short)&UNK_00c414 + sVar7) + (ushort)CARRY2(uVar2,uVar10);
    uVar2 = (short)&UNK_00c41c + sVar7;
    if ((*(byte *)(uint3)uVar2 & 8) == 0) {
      uVar4 = uVar9 >> 8 | uVar10 * 0x100;
      uVar6 = DAT_00c40c;
      uVar9 = uVar6 + uVar4;
      uVar10 = (uVar10 >> 8) + (ushort)CARRY2(uVar6,uVar4);
    }
    else {
      uVar4 = *(ushort *)(uint3)(ushort)((short)&DAT_00c416 + sVar7);
      uVar6 = (uVar10 - *(short *)(uint3)(ushort)((short)&DAT_00c418 + sVar7)) -
              (ushort)(uVar9 < uVar4);
      uVar10 = uVar9 - uVar4 >> 8 | uVar6 * 0x100;
      uVar4 = DAT_00c400;
      uVar9 = uVar4 + uVar10;
      uVar10 = (uVar6 >> 8) + (ushort)CARRY2(uVar4,uVar10);
    }
    if ((uVar10 != (uVar9 != 0xffff) || uVar9 != 0xffff) && (uVar10 != 0 || uVar9 == 0xffff)) {
      uVar9 = 0xffff;
      uVar10 = 0;
    }
    if (uVar9 < uVar5) {
      uVar5 = uVar5 - uVar9;
      if (0x7f < uVar5) {
        uVar3 = DAT_00c3fc;
        *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar7) =
             *(short *)(uint3)uVar3 + 0x7000;
        uVar3 = DAT_00c402;
        sVar7 = (bVar1 & 0xf) << 2;
        *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & ~(0xf << sVar7);
        uVar3 = DAT_00c402;
        *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 | 4 << sVar7;
        cc_irq_enable_bit(bVar1);
        *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 4;
        return;
      }
      bVar1 = *(byte *)(uint3)uVar3;
      uVar3 = DAT_00c3fc;
      *(ushort *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar7) =
           *(short *)(uint3)uVar3 + uVar5 * 0x100;
      uVar3 = DAT_00c402;
      sVar7 = (bVar1 & 0xf) << 2;
      *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & ~(0xf << sVar7);
      uVar3 = DAT_00c402;
      *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 | 5 << sVar7;
      cc_irq_enable_bit(bVar1);
    }
    else {
      event_force(param_1,uVar10);
    }
    *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xfb;
  }
  return;
}

