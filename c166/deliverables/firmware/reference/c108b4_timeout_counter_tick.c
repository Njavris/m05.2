/* c108b4 timeout_counter_tick */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Increments timeout_counter and clears timeout_value_0/1 at 0x81. */

void timeout_counter_tick(void)

{
  if (timeout_counter < 0x81) {
    timeout_counter = timeout_counter + 1;
    return;
  }
  _timeout_value_0 = 0;
  _timeout_value_1 = 0;
  return;
}


