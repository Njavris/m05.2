// c0e3da FUN_c0e3da size=230 cc=unknown proto=undefined FUN_c0e3da(void)

void FUN_c0e3da(ushort param_1,ushort param_2,ushort param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort *puVar3;
  short sVar4;
  short sVar5;
  short *psVar6;
  
  sVar4 = (param_1 & 0xff) * 0x12;
  uVar2 = (short)&UNK_00c41d + sVar4;
  bVar1 = *(byte *)(uint3)uVar2;
  if (param_3 == param_2 < 0x7f00 && param_2 == 0x7f00 || param_3 == 0 && param_2 < 0x7f00) {
    bVar1 = *(byte *)(uint3)uVar2;
    puVar3 = (ushort *)((short)&UNK_00c41e + sVar4);
    psVar6 = (short *)DAT_00c3fc;
    if ((((short)&UNK_00fff6 + **(short **)ZEXT23(puVar3) + param_2) - *psVar6 & 0x8000) == 0) {
      *(ushort *)(uint3)*puVar3 = **(short **)ZEXT23(puVar3) + param_2;
    }
    else {
      uVar2 = DAT_00c3fc;
      *(short *)(uint3)*puVar3 = *(short *)(uint3)uVar2 + 10;
    }
    uVar2 = DAT_00c402;
    sVar5 = (bVar1 & 0xf) << 2;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & ~(0xf << sVar5);
    uVar2 = DAT_00c402;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 | 5 << sVar5;
    cc_irq_enable_bit(bVar1);
    uVar2 = (short)&UNK_00c41c + sVar4;
    *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xfb;
  }
  else {
    puVar3 = (ushort *)((short)&UNK_00c41e + sVar4);
    *(short *)(uint3)*puVar3 = **(short **)ZEXT23(puVar3) + 0x7000;
    uVar2 = DAT_00c402;
    sVar5 = (bVar1 & 0xf) << 2;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & ~(0xf << sVar5);
    uVar2 = DAT_00c402;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 | 4 << sVar5;
    cc_irq_enable_bit(bVar1);
    uVar2 = (short)&UNK_00c41c + sVar4;
    *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 4;
  }
  return;
}

