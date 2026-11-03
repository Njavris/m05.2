// c126bc kline_state_reset size=22 cc=unknown proto=undefined kline_state_reset(void)

void kline_state_reset(undefined1 param_1)

{
  ushort uVar1;
  
  DAT_00c582 = param_1;
  DAT_00c57d = 0;
  uVar1 = S0CON;
  S0CON = uVar1 & 0xffef;
  DAT_00c588 = 0;
  DAT_00c584 = 0;
  return;
}

