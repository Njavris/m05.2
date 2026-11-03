/* c01252 asc0_state3 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line state 3: receive/validate. */

void asc0_state3(void)

{
  ushort uVar1;
  
  if (kline_tx_phase == '\0') {
    kline_frame_retry = 0;
    kline_tx_phase = '\x01';
    goto LAB_c012ba;
  }
  if (kline_tx_phase != '\x01') {
    kline_tx_phase = '\0';
    goto LAB_c012ba;
  }
  uVar1 = S0RIC;
  if ((uVar1 & 0x80) == 0) {
    if ((kline_frame_flag == '\x01') && (kline_init_mode < kline_frame_retry)) {
      kline_state_machine = 5;
      goto LAB_c01292;
    }
    if ((kline_frame_flag == '\0') && (kwp_routine_active == '\x01')) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else {
    kline_state_machine = 4;
LAB_c01292:
    kline_tx_phase = '\0';
  }
  kline_frame_retry = kline_frame_retry + 1;
LAB_c012ba:
  _kline_rx_retry = _kline_rx_retry + 1;
  if (_kline_init_timer < _kline_rx_retry) {
    _kline_rx_retry = 0;
    kline_state_machine = 2;
    kline_rx_index = 0;
    uVar1 = DAT_00f0c6;
    DAT_00f0c6 = uVar1 & 0xfffd | 2;
    uVar1 = S0CON;
    S0CON = uVar1 | 0x10;
  }
  return;
}


