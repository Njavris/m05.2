// c0dc8a event_schedule size=428 cc=unknown proto=undefined event_schedule(void)

void event_schedule(byte param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort *puVar4;
  short *psVar5;
  ushort uVar6;
  short sVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  short sVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  
  sVar7 = (ushort)param_1 * 0x12;
  uVar3 = (short)&UNK_00c41c + sVar7;
  puVar4 = (ushort *)((short)&UNK_00c41e + sVar7);
  uVar10 = (ushort)*(byte *)(uint3)(ushort)((short)&UNK_00c41d + sVar7);
  *(byte *)(uint3)uVar3 = *(byte *)(uint3)uVar3 & 0xe3;
  uVar2 = DAT_00c3fc;
  uVar13 = *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar4);
  uVar1 = *(undefined2 *)(uint3)uVar2;
  cc_compare_mode_set(param_1);
  uVar12 = uVar13;
  if (((*(byte *)(uint3)uVar3 & 1) == 0) ||
     (((*(byte *)(uint3)uVar3 & 4) == 0 &&
      (uVar12 = uVar1, (**(ushort **)(uint3)(ushort)((short)&UNK_00c420 + sVar7) & 0x80) == 0)))) {
    *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar4) = uVar1;
    uVar13 = uVar12;
  }
  uVar2 = *(ushort *)(uint3)(ushort)((short)&UNK_00c420 + sVar7);
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xff7f;
  *(byte *)(uint3)uVar3 = *(byte *)(uint3)uVar3 | 0x20;
  if ((*(byte *)(uint3)uVar3 & 1) == 0) {
    if ((*(byte *)(uint3)uVar3 & 2) == 0) {
      event_schedule_duration(param_1);
    }
    else {
      uVar2 = DAT_00c3fc;
      psVar5 = (short *)((short)&UNK_00c41a + sVar7);
      uVar3 = (*(short *)(uint3)uVar2 - *psVar5) + 10;
      uVar6 = DAT_00c406;
      uVar8 = DAT_00c406;
      if (uVar3 == uVar8 || uVar3 < uVar6) {
        sVar7 = DAT_00c406;
        *(short *)(uint3)*(ushort *)ZEXT23(puVar4) = *(short *)ZEXT23(psVar5) + sVar7;
      }
      else {
        *(short *)(uint3)*(ushort *)ZEXT23(puVar4) = *(short *)(uint3)uVar2 + 10;
      }
      uVar3 = DAT_00c402;
      sVar7 = (uVar10 & 0xf) << 2;
      *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & ~(0xf << sVar7);
      uVar3 = DAT_00c402;
      *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 | 4 << sVar7;
      cc_irq_enable_bit(uVar10);
    }
  }
  else {
    event_accum(param_1,uVar13);
    uVar2 = (short)&UNK_00c412 + sVar7;
    *(byte *)(uint3)uVar3 = *(byte *)(uint3)uVar3 & 0xfe;
    uVar6 = *(ushort *)(uint3)uVar2 | *(ushort *)(uint3)(ushort)((short)&UNK_00c414 + sVar7);
    if (uVar6 == 0) {
      event_idle(param_1);
    }
    else {
      sVar11 = t7_timestamp_extended(uVar6);
      uVar2 = *(ushort *)(uint3)uVar2;
      uVar9 = DAT_00c408;
      uVar6 = uVar2 + uVar9;
      uVar8 = DAT_00c406;
      if ((uVar6 + uVar8 >> 8 |
          (*(short *)(uint3)(ushort)((short)&UNK_00c414 + sVar7) + (ushort)CARRY2(uVar2,uVar9) +
          (ushort)CARRY2(uVar6,uVar8)) * 0x100) <
          (ushort)(*(short *)(uint3)(ushort)((short)&UNK_00c410 + sVar7) - sVar11)) {
        uVar2 = DAT_00c3fc;
        sVar7 = DAT_00c406;
        *(short *)(uint3)*puVar4 = *(short *)(uint3)uVar2 + sVar7;
        uVar2 = DAT_00c402;
        sVar7 = (uVar10 & 0xf) << 2;
        *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & ~(0xf << sVar7);
        uVar2 = DAT_00c402;
        *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 | 4 << sVar7;
        cc_irq_enable_bit(uVar10,0);
        *(byte *)(uint3)uVar3 = *(byte *)(uint3)uVar3 | 2;
      }
      else {
        event_force(param_1);
        *(byte *)(uint3)uVar3 = *(byte *)(uint3)uVar3 | 0x40;
      }
    }
  }
  return;
}

