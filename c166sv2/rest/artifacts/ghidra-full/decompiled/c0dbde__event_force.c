// c0dbde event_force size=132 cc=unknown proto=undefined event_force(void)

void event_force(ushort param_1)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  char cVar5;
  
  sVar3 = (param_1 & 0xff) * 0x12;
  uVar4 = DAT_00c40a;
  bVar1 = *(byte *)(uint3)(ushort)((short)&UNK_00c41d + sVar3);
  bVar2 = bVar1 & 0xf;
  cVar5 = DAT_00c40e;
  if (((*(ushort *)(uint3)uVar4 & 1 << bVar2) != 0) == (cVar5 == '\0')) {
    uVar4 = DAT_00c3fc;
    *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar3) =
         *(short *)(uint3)uVar4 + 10;
  }
  uVar4 = DAT_00c402;
  sVar3 = (ushort)bVar2 << 2;
  *(ushort *)(uint3)uVar4 = *(ushort *)(uint3)uVar4 & ~(0xf << sVar3);
  uVar4 = DAT_00c402;
  *(ushort *)(uint3)uVar4 = *(ushort *)(uint3)uVar4 | 5 << sVar3;
  cc_irq_enable_bit(bVar1);
  return;
}

