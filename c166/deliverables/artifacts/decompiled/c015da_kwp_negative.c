/* c015da kwp_negative */

/* KWP negative response / unsupported service. */

void kwp_negative(void)

{
  kline_response_length = 3;
  kline_response_payload = 0x7f;
  kline_response_payload_1 = 0x10;
  kline_response_payload_2 = 1;
  return;
}


