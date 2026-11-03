// c10200 ssc_rx_queue_init size=64 cc=unknown proto=undefined ssc_rx_queue_init(void)

void ssc_rx_queue_init(void)

{
  ushort uVar1;
  
  DAT_00c4a8 = 0xffff;
  uVar1 = P1H;
  P1H = uVar1 | 8;
  DAT_00c4be = 0x40;
  DAT_00c4bd = 0;
  DAT_00c4bc = 0;
  DAT_00c4ba._1_1_ = 0x1f;
  DAT_00c4ba._0_1_ = 0xfc;
  DAT_00c4b9 = 0;
  DAT_00c4b8 = 0;
  ssc_rx_start();
  DAT_00c4aa = 0;
  DAT_00c49e = 0;
  DAT_00c4b4 = 0;
  return;
}

