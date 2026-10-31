/* c00c8a asc0_read_rx_clear */

/* Clears the ASC0 receive flag and returns one S0RBUF byte. */

undefined2 asc0_read_rx_clear(void)

{
  undefined2 uVar1;
  ushort uVar2;
  
  uVar2 = S0RIC;
  S0RIC = uVar2 & 0xff7f;
  uVar1 = Ram00feb2;
  return uVar1;
}


