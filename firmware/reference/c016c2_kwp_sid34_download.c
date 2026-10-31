/* c016c2 kwp_sid34_download */

/* KWP service 0x34 request download. */

void kwp_sid34_download(void)

{
  if (security_unlocked != '\x01') {
    kline_response_length = 3;
    kline_response_payload = 0x7f;
    kline_response_payload_1 = 0x10;
    kline_response_payload_2 = 0x33;
    return;
  }
  kline_response_frame = 0x82;
  kline_response_length = 2;
  kline_response_payload = 0x74;
  kline_response_payload_1 = 0xfb;
  return;
}


