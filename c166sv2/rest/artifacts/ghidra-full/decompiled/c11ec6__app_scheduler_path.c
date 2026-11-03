// c11ec6 app_scheduler_path size=38 cc=unknown proto=undefined app_scheduler_path(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void app_scheduler_path(void)

{
  ushort uVar1;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  __disable_watchdog();
  if (_DAT_007096 != 0 || _DAT_007094 != 0) {
    empty_stub_0();
  }
  uVar1 = P1H;
  P1H = uVar1 & 0xfffb;
  __software_reset();
  return;
}

