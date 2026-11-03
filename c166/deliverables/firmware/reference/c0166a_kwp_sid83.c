/* c0166a kwp_sid83 */

/* KWP service 0x83 handler (Delphi-specific). */

void kwp_sid83(void)

{
  if (ram_var_c149 == '\0') {
    kline_response_frame = 0x87;
    kline_response_length = 7;
    kline_response_payload = 0xc3;
    kline_response_payload_1 = 0;
    kline_response_payload_2 = 0;
    kline_response_payload_3 = 0xff;
    kline_response_payload_4 = 0;
    kline_response_payload_5 = 0xff;
    kline_response_payload_6 = 0;
  }
  else if (ram_var_c149 == '\x03') {
    kline_response_frame = 0x82;
    kline_response_length = 2;
    kline_response_payload = 0xc3;
    kline_response_payload_1 = 3;
    return;
  }
  return;
}


