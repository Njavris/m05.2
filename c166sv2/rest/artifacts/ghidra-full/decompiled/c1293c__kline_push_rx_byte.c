// c1293c kline_push_rx_byte size=50 cc=unknown proto=undefined kline_push_rx_byte(void)

void kline_push_rx_byte(undefined1 param_1)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  
  bVar2 = DAT_00c58c;
  cVar3 = DAT_00c58c;
  DAT_00c58c = cVar3 + '\x01';
  *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar2) = param_1;
  sVar1 = DAT_00c584;
  if ((sVar1 == 6) && (cVar3 = DAT_00f600, cVar3 != '\0')) {
    kline_rx_state_7();
  }
  cVar3 = DAT_00c58c;
  if (cVar3 == '=') {
    DAT_00c58c = 0;
  }
  return;
}

