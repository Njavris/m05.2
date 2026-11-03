/* c11f66 asc0_rx_handler */

/* ASC0 receive handler: reads S0RBUF and pushes the byte into the K-line ring. */

void asc0_rx_handler(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  
  SRCP0 = &stack0x0000;
  uVar1 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x303;
  uVar4 = asc0_read_rx_raw(uVar2,uVar1);
  kline_push_rx_byte(uVar4);
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}


