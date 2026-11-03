/* c0119e asc0_state1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line state 1: wake-up / 5-baud handling. */

void asc0_state1(void)

{
  ushort uVar1;
  
  uVar1 = P3;
  if ((uVar1 & 0x800) == 0) {
    _kline_rx_timeout = _kline_rx_timeout + 1;
    return;
  }
  if ((0x14 < _kline_rx_timeout) && (_kline_rx_timeout < 0x1c)) {
    kline_state_machine = 2;
    kline_rx_index = 0;
    uVar1 = DAT_00f0c6;
    DAT_00f0c6 = uVar1 & 0xfffd | 2;
    uVar1 = S0CON;
    S0CON = uVar1 | 0x10;
  }
  _kline_rx_timeout = 0;
  return;
}


