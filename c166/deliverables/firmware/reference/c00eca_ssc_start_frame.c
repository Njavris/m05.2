/* c00eca ssc_start_frame */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Start SSC transfer with 7-byte buffer. */

void ssc_start_frame(void)

{
  ushort uVar1;
  
  uVar1 = P1H;
  P1H = uVar1 & 0xfff7;
  ssc_frame_bytes = 7;
  _ssc_rx_ptr = SUB32(&boot_port_cfg_c08c,0);
  _ssc_tx_ptr = SUB32(&ssc_rx_frame,0);
  ssc_send_byte();
  return;
}


