/* c0fb6e timer6_start */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Start timer T6. */

void timer6_start(void)

{
  timer6_init();
  ssc_state_reset();
  cc_event_timeout_0 = 0;
  capture_status_1 = 0;
  cc_event_timeout_1 = 0;
  capture_status_0 = 0;
  _event_var_c478 = 0;
  return;
}


