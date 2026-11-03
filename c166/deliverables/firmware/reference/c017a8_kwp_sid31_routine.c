/* c017a8 kwp_sid31_routine */

/* KWP service 0x31 start routine. */

void kwp_sid31_routine(void)

{
  if (security_unlocked != '\x01') {
    kline_response_length = 3;
    kline_response_payload = 0x7f;
    kline_response_payload_1 = 0x31;
    kline_response_payload_2 = 0xbd;
    return;
  }
  kwp_routine_active = 1;
  kline_response_length = 2;
  kline_response_payload = 0x71;
  kline_response_payload_1 = 2;
  return;
}


