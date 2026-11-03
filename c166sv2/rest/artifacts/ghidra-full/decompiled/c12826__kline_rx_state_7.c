// c12826 kline_rx_state_7 size=34 cc=unknown proto=undefined kline_rx_state_7(void)

void kline_rx_state_7(void)

{
  short sVar1;
  
  sVar1 = DAT_00c5a2;
  if (sVar1 == 1) {
    DAT_00c5be = 0;
  }
  sVar1 = DAT_00c5a2;
  if (sVar1 == 0) {
    DAT_00c5b0 = 0;
  }
  DAT_00c574 = 0;
  DAT_00c584 = 7;
  return;
}

