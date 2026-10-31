/* c13d50 test_command_clear */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clears the 0xFD18 command and its counters. */

void test_command_clear(void)

{
  test_command._0_1_ = 0;
  _test_command_timer_0 = 0;
  _test_command_timer_1 = 0;
  return;
}


