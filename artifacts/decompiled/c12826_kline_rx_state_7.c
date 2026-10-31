/* c12826 kline_rx_state_7 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line receive/transport state 7. */

void kline_rx_state_7(void)

{
  if (_kline_flag_c5a2 == 1) {
    _kline_var_c5be = 0;
  }
  if (_kline_flag_c5a2 == 0) {
    _kline_var_c5b0 = 0;
  }
  _kline_var_c574 = 0;
  _kline_state = 7;
  return;
}


