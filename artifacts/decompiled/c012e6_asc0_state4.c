/* c012e6 asc0_state4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line state 4: transmit response. */

void asc0_state4(void)

{
  undefined1 uVar1;
  ushort uVar2;
  
  if (kline_tx_phase == '\0') {
    kline_rx_index = 0;
    kwp_request = 4;
    kline_tx_phase = '\x01';
    _kline_rx_timeout_counter = 0;
  }
  else if (kline_tx_phase != '\x01') {
    if (kline_tx_phase == '\x02') {
      for (; (uVar2 = S0RIC, (uVar2 & 0x80) != 0 && ((ushort)kline_rx_index <= kwp_request + 4));
          kline_rx_index = kline_rx_index + 1) {
        uVar1 = asc0_read_rx_clear(0);
        *(undefined1 *)(uint3)((short)&kline_rx_buffer + (ushort)kline_rx_index) = uVar1;
        _kline_rx_timeout_counter = 0;
      }
      _kline_rx_timeout_counter = _kline_rx_timeout_counter + 1;
      _kline_frame_total = kwp_request + 4;
      if (_kline_frame_total < kline_rx_index) {
        for (uVar2 = 0; uVar2 < _kline_frame_total; uVar2 = uVar2 + 1) {
        }
        kline_state_machine = 3;
        kline_tx_phase = '\0';
        kwp_request_pending = 1;
      }
      else if (kline_rx_timeout_limit < _kline_rx_timeout_counter) {
        kline_state_machine = 3;
        kline_tx_phase = '\0';
        kline_rx_buffer = 0;
      }
    }
    else {
      kline_tx_phase = '\0';
    }
    goto LAB_c013e2;
  }
  for (; (uVar2 = S0RIC, (uVar2 & 0x80) != 0 && (kline_rx_index < 3));
      kline_rx_index = kline_rx_index + 1) {
    uVar1 = asc0_read_rx_clear();
    uVar2 = (short)&kline_rx_buffer + (ushort)kline_rx_index;
    *(undefined1 *)(uint3)uVar2 = uVar1;
    if ((ushort)*(byte *)(uint3)uVar2 !=
        *(ushort *)(uint3)((short)&kline_header_pattern + (ushort)kline_rx_index * 2)) {
      kline_state_machine = 3;
      kline_tx_phase = '\0';
    }
  }
  if (kline_rx_index == 3) {
    kline_tx_phase = '\x02';
  }
LAB_c013e2:
  _kline_rx_retry = _kline_rx_retry + 1;
  return;
}


