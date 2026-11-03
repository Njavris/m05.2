/* c015f8 kwp_sid10_session */

/* KWP service 0x10 start diagnostic session. */

void kwp_sid10_session(void)

{
  if (ram_var_c149 == -0x7f) {
    kline_response_length = 2;
    kline_response_payload = 0x50;
    kline_response_payload_1 = 0x81;
  }
  else if (ram_var_c149 == -0x7b) {
    if (security_unlocked == '\x01') {
      kline_response_length = 2;
      kline_response_payload = 0x50;
      kline_response_payload_1 = 0x85;
    }
    else {
      kline_response_length = 3;
      kline_response_payload = 0x7f;
      kline_response_payload_1 = 0x10;
      kline_response_payload_2 = 0x85;
    }
  }
  kline_response_frame = 0x80;
  return;
}


