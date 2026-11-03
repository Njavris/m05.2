/* c11ec6 app_scheduler_path */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Scheduler alternate path. */

void app_scheduler_path(void)

{
  ushort uVar1;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  __disable_watchdog();
  if (_scheduler_ext_3 != 0 || _scheduler_ext_2 != 0) {
    empty_stub_0();
  }
  uVar1 = P1H;
  P1H = uVar1 & 0xfffb;
  __software_reset();
  return;
}


