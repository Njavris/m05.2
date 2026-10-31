/* c1293c kline_push_rx_byte */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Stores a received K-line byte into the IRAM ring at 0xF600. */

void kline_push_rx_byte(undefined1 param_1)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = (ushort)kline_var_c58c;
  kline_var_c58c = kline_var_c58c + 1;
  *(undefined1 *)(uint3)((short)&kline_rx_ring + uVar1) = param_1;
  if ((_kline_state == 6) && (cVar2 = kline_rx_ring, cVar2 != '\0')) {
    kline_rx_state_7();
  }
  if (kline_var_c58c == '=') {
    kline_var_c58c = '\0';
  }
  return;
}


