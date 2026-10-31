/* c13d5e test_command_dispatch */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Dispatches 0xFD18 actuator/test command bits. */

void test_command_dispatch(void)

{
  bool bVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  
  bVar3 = test_command._0_1_;
  if ((bVar3 & 0x7f) == 0) {
    _test_command_timer_0 = 0;
    _test_command_timer_1 = 0;
    return;
  }
  sVar2 = _test_command_timer_1 - (ushort)(_test_command_timer_0 < 1000);
  if (_test_command_timer_1 == 0 && _test_command_timer_0 < 1000) {
    bVar1 = _test_command_timer_0 != 0xffff;
    _test_command_timer_0 = _test_command_timer_0 + 1;
    _test_command_timer_1 = (_test_command_timer_1 + 1) - (ushort)bVar1;
    uVar4 = test_command;
    if ((uVar4 & 1) != 0) {
      cc22_23_start_once(sVar2);
      return;
    }
    uVar4 = test_command;
    if ((uVar4 & 2) != 0) {
      event_start_fixed();
      return;
    }
    uVar4 = test_command;
    if ((uVar4 & 4) != 0) {
      pwm_output_enable();
      pwm_period_duty_calc(0xfa,0);
      return;
    }
  }
  else {
    bVar3 = test_command._0_1_;
    test_command._0_1_ = bVar3 & 0x80;
  }
  return;
}


