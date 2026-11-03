/* c017ea kwp_sid38 */

/* KWP service 0x38 handler. */

void kwp_sid38(void)

{
  if (security_unlocked != '\x01') {
    kline_response_length = 3;
    kline_response_payload = 0x7f;
    kline_response_payload_1 = 0x31;
    kline_response_payload_2 = 0xbd;
    return;
  }
  kwp_routine_active = 1;
  kline_response_length = 4;
  kline_response_payload = 0x78;
  kline_response_payload_1 = ram_var_c149;
  kline_response_payload_2 = kwp_request_addr_hi;
  kline_response_payload_3 = kwp_request_addr_mid;
  return;
}


