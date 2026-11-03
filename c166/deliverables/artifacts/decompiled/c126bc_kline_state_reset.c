/* c126bc kline_state_reset */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clears K-line state to 0. */

void kline_state_reset(undefined1 param_1)

{
  ushort uVar1;
  
  kline_mode = param_1;
  kline_flag_c57d = 0;
  uVar1 = S0CON;
  S0CON = uVar1 & 0xffef;
  kline_flag_c588 = 0;
  _kline_state = 0;
  return;
}


