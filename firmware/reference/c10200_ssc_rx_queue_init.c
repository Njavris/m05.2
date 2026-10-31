/* c10200 ssc_rx_queue_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SSC receive queue initialization. */

void ssc_rx_queue_init(void)

{
  ushort uVar1;
  
  _ssc_var_c4a8 = 0xffff;
  uVar1 = P1H;
  P1H = uVar1 | 8;
  ssc_var_c4be = 0x40;
  ssc_var_c4bd = 0;
  ssc_var_c4bc = 0;
  ssc_var_c4bb = 0x1f;
  ssc_control_flags = 0xfc;
  ssc_var_c4b9 = 0;
  ssc_var_c4b8 = 0;
  ssc_rx_start();
  ssc_var_c4aa = 0;
  ssc_var_c49e = 0;
  ssc_var_c4b4 = 0;
  return;
}


