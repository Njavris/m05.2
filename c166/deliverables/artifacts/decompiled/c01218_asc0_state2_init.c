/* c01218 asc0_state2_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initialize K-line receive frame. */

void asc0_state2_init(char param_1)

{
  ushort uVar1;
  
  asc0_clear_state();
  if (param_1 == '\x02') {
    kline_init_mode = 0x5e;
    _kline_init_timer = 0x49fb;
    kline_rx_timeout_limit = 0x79;
  }
  kline_state_machine = 3;
  kline_tx_phase = 0;
  security_unlocked = 1;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x10;
  return;
}


