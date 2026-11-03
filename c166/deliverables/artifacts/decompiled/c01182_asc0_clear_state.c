/* c01182 asc0_clear_state */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clear ASC0/K-line state. */

void asc0_clear_state(void)

{
  _kline_rx_retry = 0;
  return;
}


