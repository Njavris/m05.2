// c0bca4 capcom_event_config size=176 cc=unknown proto=undefined capcom_event_config(void)

void capcom_event_config(ushort param_1,byte param_2,short param_3)

{
  ushort *puVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  
  uVar4 = PSW;
  PSW = uVar4 & 0xf7ff;
  if (param_3 != 0) {
    DAT_00c40e = 1;
  }
  sVar2 = (param_1 & 0xff) * 0x12;
  sVar3 = (param_1 & 0xff) * 8;
  puVar1 = (ushort *)((short)&DAT_00c394 + sVar3);
  *(byte *)(uint3)(ushort)((short)&UNK_00c41d + sVar2) = param_2;
  *(undefined2 *)(uint3)*puVar1 = *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar1);
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c41e + sVar2) =
       *(undefined2 *)(uint3)(ushort)((short)&DAT_00c392 + sVar3);
  DAT_00c3fe = 0xfe28;
  DAT_00c404 = 0xfe2a;
  DAT_00c40a = 0xff2c;
  DAT_00c402 = 0xff22;
  puVar1 = (ushort *)((short)&DAT_00c396 + sVar3);
  DAT_00c3fc = 0xf050;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c420 + sVar2) = *(undefined2 *)ZEXT23(puVar1);
  *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) =
       *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) | 0x30 | param_1 & 0xff;
  uVar4 = DAT_00c3fe;
  *(ushort *)(uint3)uVar4 = *(ushort *)(uint3)uVar4 | 1 << (param_2 & 0xf);
  event_cancel(param_1 & 0xff,param_1);
  *(ushort *)(uint3)*puVar1 = *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) | 0x40;
  uVar4 = PSW;
  PSW = uVar4 | 0x800;
  return;
}

