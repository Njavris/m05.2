// c0bbc4 capcom_event_config2 size=50 cc=unknown proto=undefined capcom_event_config2(void)

void capcom_event_config2
               (byte param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 unaff_00000000,undefined2 unaff_00000002)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  sVar1 = (ushort)param_1 * 0x12;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c412 + sVar1) = param_2;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c414 + sVar1) = param_3;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c410 + sVar1) = param_4;
  DAT_00c40c = unaff_00000000;
  DAT_00c400 = unaff_00000002;
  event_schedule(param_1);
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return;
}

