// c0dc62 event_cancel size=40 cc=unknown proto=undefined event_cancel(void)

void event_cancel(byte param_1)

{
  short sVar1;
  
  sVar1 = (ushort)param_1 * 0x12;
  *(undefined2 *)(uint3)(ushort)((short)&DAT_00c416 + sVar1) = 0;
  *(undefined2 *)(uint3)(ushort)((short)&DAT_00c418 + sVar1) = 0;
  *(undefined1 *)(uint3)(ushort)((short)&UNK_00c41c + sVar1) = 0;
  event_idle(param_1);
  return;
}

