/* c0f3d2 cc22_23_task */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Periodic task for the CC22/CC23 event pair; uses engine speed/timing input 0xC9D0. */

void cc22_23_task(void)

{
  undefined2 uVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  
  uVar4 = _engine_speed_input;
  if (0xc7fe < _engine_speed_input) {
    uVar4 = 0xc7ff;
  }
  cc22_23_hysteresis_a();
  cc22_23_hysteresis_b((short)(CONCAT22(uVar4 >> 0xb,uVar4 << 5) / 0x19));
  uVar4 = speed_status_flags;
  if (((uVar4 & 0x400) == 0) && (uVar4 = speed_status_flags, (uVar4 & 0x80) != 0)) {
    sVar3 = cc_irq_is_enabled(_cc22_23_input_0);
    if (sVar3 == 1) {
      cc22_23_output_disable(0);
      cc_irq_enable(_cc22_23_input_0,0);
      uVar4 = S0RIC;
      S0RIC = uVar4 & 0xffbf;
    }
    sVar3 = cc_irq_is_enabled(_cc22_23_input_1);
    if (sVar3 == 1) {
      cc22_23_output_disable(1);
      cc_irq_enable(_cc22_23_input_1,0);
      uVar4 = S0TIC;
      S0TIC = uVar4 & 0xffbf;
    }
  }
  uVar1 = speed_status_flags;
  uVar4 = speed_status_flags;
  uVar2 = speed_status_flags;
  speed_status_flags = uVar2 & 0xff7f | ((uVar4 & 0x400) >> 10) << 7;
  cc_event_timeout_tick();
  return;
}


