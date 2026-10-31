/* c0d516 event_reset */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reset event scheduler state. */

void event_reset(void)

{
  _event_var_c378 = 0;
  _event_var_c37e = 0;
  _event_var_c374 = 0;
  event_var_c370 = 0;
  return;
}


