/* c01544 kwp_sid27_security */

/* KWP service 0x27 security access; fixed seed 0x1234, key 0x8474. */

void kwp_sid27_security(void)

{
  if (ram_var_c149 == '\x01') {
    kline_response_frame = 0x80;
    kline_response_length = 4;
    kline_response_payload = 0x67;
    kline_response_payload_1 = 1;
    kline_response_payload_2 = 0x12;
    kline_response_payload_3 = 0x34;
    return;
  }
  if (ram_var_c149 == '\x02') {
    kline_response_length = 3;
    kline_response_frame = 0x80;
    if ((kwp_request_addr_hi == -0x7c) && (kwp_request_addr_mid == 't')) {
      security_unlocked = 1;
      kline_response_payload = 0x67;
      kline_response_payload_1 = 2;
      kline_response_payload_2 = 0x34;
      return;
    }
    kline_response_payload = 0x7f;
    kline_response_payload_1 = 0x27;
    kline_response_payload_2 = 0x35;
  }
  return;
}


