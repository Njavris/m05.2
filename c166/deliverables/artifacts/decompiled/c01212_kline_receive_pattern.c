/* c01212 kline_receive_pattern */

/* Receives the 5-byte K-line wake-up pattern and advances state. */

void kline_receive_pattern(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 uVar3;
  
  while( true ) {
    uVar1 = S0RIC;
    if ((uVar1 & 0x80) == 0) {
      return;
    }
    uVar3 = asc0_read_rx_clear();
    uVar2 = (ushort)kline_rx_index;
    uVar1 = (short)&kline_rx_buffer + uVar2;
    *(undefined1 *)(uint3)uVar1 = uVar3;
    if (*(char *)(uint3)uVar1 != *(char *)(uint3)((short)&kline_wakeup_pattern + uVar2)) break;
    if (kline_rx_index == 4) {
      kline_state_machine = kline_state_machine + '\x01';
      kwp_request_pending = 1;
      kline_receive_pattern();
      return;
    }
    kline_rx_index = kline_rx_index + 1;
  }
  kline_state_machine = 1;
  kline_receive_pattern();
  return;
}


