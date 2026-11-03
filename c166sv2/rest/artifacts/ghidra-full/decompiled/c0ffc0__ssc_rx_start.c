// c0ffc0 ssc_rx_start size=30 cc=unknown proto=undefined ssc_rx_start(void)

void ssc_rx_start(void)

{
  ushort uVar1;
  
  uVar1 = P1H;
  P1H = uVar1 & 0xfff7;
  DAT_00c492 = 7;
  DAT_00c494 = 0xc4b8;
  DAT_00c496 = 0xc4a0;
  ssc_send();
  return;
}

