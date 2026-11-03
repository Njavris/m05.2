/* c00e08 ssc_send_byte */

/* Write one byte to SSC transmit buffer. */

void ssc_send_byte(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = SSCTIC;
  SSCTIC = uVar1 & 0xff7f;
  SSCTB = (ushort)*(byte *)(uint3)param_1;
  return;
}


