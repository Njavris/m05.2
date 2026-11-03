// c0e1b6 event_idle size=128 cc=unknown proto=undefined event_idle(void)

void event_idle(byte param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  
  sVar3 = (ushort)param_1 * 0x12;
  bVar1 = *(byte *)(uint3)(ushort)((short)&UNK_00c41d + sVar3);
  cc_compare_mode_set(param_1);
  uVar2 = (short)&UNK_00c41c + sVar3;
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xdf;
  uVar5 = DAT_00c3fc;
  *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar3) =
       *(short *)(uint3)uVar5 + 0x7000;
  uVar5 = DAT_00c402;
  sVar4 = (bVar1 & 0xf) << 2;
  *(ushort *)(uint3)uVar5 = *(ushort *)(uint3)uVar5 & ~(0xf << sVar4);
  uVar5 = DAT_00c402;
  *(ushort *)(uint3)uVar5 = *(ushort *)(uint3)uVar5 | 4 << sVar4;
  cc_irq_enable_bit(bVar1);
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 4;
  uVar2 = *(ushort *)(uint3)(ushort)((short)&UNK_00c420 + sVar3);
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xff7f;
  return;
}

