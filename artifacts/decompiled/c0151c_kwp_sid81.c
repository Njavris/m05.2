/* c0151c kwp_sid81 */

/* KWP service 0x81 handler (start communication). */

void kwp_sid81(void)

{
  kline_response_frame = 0x80;
  kline_response_length = 3;
  kline_response_payload = 0xc1;
  kline_response_payload_1 = 0xef;
  kline_response_payload_2 = 0x8f;
  return;
}


