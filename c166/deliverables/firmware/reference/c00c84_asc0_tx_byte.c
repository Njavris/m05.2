/* c00c84 asc0_tx_byte */

/* Writes one byte to the ASC0 transmit buffer S0TBUF. */

void asc0_tx_byte(undefined2 param_1)

{
  S0TBUF = param_1;
  return;
}


