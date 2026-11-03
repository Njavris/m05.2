// c0e236 event_accum size=70 cc=unknown proto=undefined event_accum(void)

void event_accum(ushort param_1,short param_2)

{
  ushort uVar1;
  short *psVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  
  sVar6 = (param_1 & 0xff) * 0x12;
  psVar2 = (short *)((short)&UNK_00c41a + sVar6);
  uVar5 = param_2 - *psVar2;
  if (uVar5 < 0x7f01) {
    uVar3 = (short)&DAT_00c416 + sVar6;
    uVar1 = *(ushort *)(uint3)uVar3;
    *(ushort *)(uint3)(ushort)((short)&DAT_00c418 + sVar6) =
         *(short *)(uint3)(ushort)((short)&DAT_00c418 + sVar6) + (ushort)CARRY2(uVar1,uVar5);
    uVar4 = (short)&UNK_00c41c + sVar6;
    *(ushort *)(uint3)uVar3 = uVar1 + uVar5;
    *(short *)ZEXT23(psVar2) = param_2;
    *(byte *)(uint3)uVar4 = *(byte *)(uint3)uVar4 & 0x7f;
  }
  return;
}

