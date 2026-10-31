/* c0d6f0 event_start_fixed */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Loads fixed event parameters and starts the CC16/CC17 scheduler. */

void event_start_fixed(void)

{
  _event_var_c384 = 0x1194;
  _event_var_c386 = 0;
  _event_var_c388 = 0x1194;
  _event_var_c38a = 0;
  event_start();
  return;
}


