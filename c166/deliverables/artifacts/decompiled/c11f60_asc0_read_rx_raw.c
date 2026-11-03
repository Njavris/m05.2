/* c11f60 asc0_read_rx_raw */

/* Returns one S0RBUF byte without changing the receive flag. */

undefined1 asc0_read_rx_raw(void)

{
  undefined1 uVar1;
  
  uVar1 = S0RBUF;
  return uVar1;
}


