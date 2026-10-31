/* c126b0 kline_start_timeout */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Loads the K-line timeout 0xC56A with 0x0500. */

void kline_start_timeout(void)

{
  _kline_timeout = 0x500;
  return;
}


