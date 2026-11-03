// c00eca ssc_start_frame size=30 cc=unknown proto=undefined ssc_start_frame(void)

void ssc_start_frame(void)

{
  ushort uVar1;
  
  uVar1 = P1H;
  P1H = uVar1 & 0xfff7;
  DAT_00c094 = 7;
  DAT_00c096 = 0xc08c;
  DAT_00c098 = 0xc078;
  ssc_send_byte();
  return;
}

