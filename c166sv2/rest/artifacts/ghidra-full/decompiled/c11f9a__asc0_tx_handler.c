// c11f9a asc0_tx_handler size=98 cc=unknown proto=undefined asc0_tx_handler(void)

void asc0_tx_handler(void)

{
  short sVar1;
  char cVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  DAT_00fce0 = &stack0x0000;
  uVar3 = DPP0;
  DPP0 = 0x301;
  uVar4 = DPP2;
  DPP2 = 0x303;
  sVar1 = DAT_00c57a;
  if (sVar1 == 6) {
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5ac = 0;
      cVar2 = DAT_00c57d;
      if (cVar2 == '\0') {
        kline_state_reset(5);
      }
      else {
        cVar2 = DAT_00c5b6;
        if (cVar2 != '\0') {
          kline_rx_state_8(uVar4,uVar3);
        }
      }
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      kline_prepare_frame(0);
    }
  }
  DPP2 = uVar4;
  uVar4 = DPP2;
  uVar4 = DPP2;
  uVar4 = DPP2;
  DPP0 = uVar3;
  uVar3 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  return;
}

