/* c01188 asc0_state0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line state 0: idle / start. */

void asc0_state0(void)

{
  ushort uVar1;
  
  kline_state_machine = 1;
  _kline_rx_timeout = 0;
  asc0_clear_state();
  _kline_var_c13a = 0;
  uVar1 = S0CON;
  S0CON = uVar1 & 0xffef;
  return;
}


