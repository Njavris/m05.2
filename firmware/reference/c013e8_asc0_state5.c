/* c013e8 asc0_state5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line state 5: finish. */

void asc0_state5(void)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = '\0';
  if (kline_tx_phase == '\0') {
    _kline_tx_index = 0;
    kline_response_frame = 0x80;
    kline_response_target = 0xf1;
    kline_response_source = 0x11;
    _kline_frame_total = kline_response_length + 4;
    for (uVar2 = 0; uVar2 < _kline_frame_total; uVar2 = uVar2 + 1) {
      cVar1 = cVar1 + *(char *)(uint3)((short)&kline_response_frame + uVar2);
    }
    *(char *)(uint3)((short)&kline_response_payload + (ushort)kline_response_length) = cVar1;
    kline_tx_phase = '\x01';
    uVar2 = S0CON;
    S0CON = uVar2 & 0xffef;
  }
  else if (kline_tx_phase == '\x01') {
    uVar2 = (short)&kline_response_frame + _kline_tx_index;
    _kline_tx_index = _kline_tx_index + 1;
    asc0_tx_byte(*(undefined1 *)(uint3)uVar2);
    if (_kline_frame_total < _kline_tx_index) {
      kline_tx_phase = '\x02';
    }
  }
  else {
    if (kline_tx_phase == '\x02') {
      uVar2 = S0CON;
      S0CON = uVar2 | 0x10;
      kline_state_machine = 3;
      kline_frame_flag = 0;
    }
    kline_tx_phase = '\0';
  }
  kline_frame_retry = kline_frame_retry + '\x01';
  _kline_rx_retry = 0;
  return;
}


