/* c10342 ssc_task */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Periodic SSC task: start transfer, timeout, sample port. */

void ssc_task(void)

{
  ssc_rx_start();
  if (ssc_timeout == '\0') {
    _ssc_control_flags = _ssc_control_flags | 0x200;
    ssc_rx_start();
    empty_stub_3();
    ssc_timeout = 'P';
  }
  else {
    ssc_timeout = ssc_timeout + -1;
  }
  input_debounce_sample();
  return;
}


