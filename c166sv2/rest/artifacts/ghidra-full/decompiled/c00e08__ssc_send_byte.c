// c00e08 ssc_send_byte size=12 cc=unknown proto=undefined ssc_send_byte(void)

void ssc_send_byte(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = SSCTIC;
  SSCTIC = uVar1 & 0xff7f;
  SSCTB = (ushort)*(byte *)(uint3)param_1;
  return;
}

