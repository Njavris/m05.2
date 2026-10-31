/* c0dc62 event_cancel */

/* Cancel/initialize one event channel. */

void event_cancel(byte param_1)

{
  short sVar1;
  
  sVar1 = (ushort)param_1 * 0x12;
  *(undefined2 *)(uint3)(sVar1 + 0xc416) = 0;
  *(undefined2 *)(uint3)(sVar1 + 0xc418) = 0;
  *(undefined1 *)(uint3)(sVar1 + 0xc41c) = 0;
  event_idle(param_1);
  return;
}


