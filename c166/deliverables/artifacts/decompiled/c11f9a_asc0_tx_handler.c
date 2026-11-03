/* c11f9a asc0_tx_handler */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* ASC0 transmit/status handler for the K-line transport. */

void asc0_tx_handler(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  SRCP0 = &stack0x0000;
  uVar1 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  DPP2 = 0x303;
  if (_kline_var_c57a == 6) {
    if (_kline_flag_c5a2 == 1) {
      _kline_var_c5ac = 0;
      if (kline_flag_c57d == '\0') {
        kline_state_reset(5);
      }
      else if (kline_var_c5b6 != '\0') {
        kline_rx_state_8(uVar2,uVar1);
      }
    }
    if (_kline_flag_c5a2 == 0) {
      kline_prepare_frame(0);
    }
  }
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}


