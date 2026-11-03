// c0ff28 ssc_send size=12 cc=unknown proto=undefined ssc_send(void)

void ssc_send(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = SSCTIC;
  SSCTIC = uVar1 & 0xff7f;
  SSCTB = (ushort)*(byte *)(uint3)param_1;
  return;
}

