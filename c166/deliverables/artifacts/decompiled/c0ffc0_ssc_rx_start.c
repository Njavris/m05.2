/* c0ffc0 ssc_rx_start */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Start SSC receive engine. */

void ssc_rx_start(void)

{
  ushort uVar1;
  
  uVar1 = P1H;
  P1H = uVar1 & 0xfff7;
  ssc_var_c492 = 7;
  _ssc_var_c494 = SUB32(&ssc_var_c4b8,0);
  _ssc_var_c496 = 0xc4a0;
  ssc_send();
  return;
}


