/* c11cae app_idle_wait */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Scheduler idle/wait path. */

void app_idle_wait(void)

{
  byte *pbVar1;
  char *pcVar2;
  ushort uVar3;
  short sVar4;
  byte bVar5;
  
  while( true ) {
    uVar3 = scheduler_event_flag;
    if ((uVar3 & 4) == 0) {
      app_scheduler();
      return;
    }
    __service_watchdog();
    uVar3 = scheduler_event_flag;
    scheduler_event_flag = uVar3 & 0xfffb;
    scheduler_tick = scheduler_tick + 1;
    cc22_23_task();
    ssc_task();
    timeout_counter_tick();
    if ((scheduler_tick & 1) != 0) {
      speed_timing_calc();
      if ((((_engine_state_962 < 0x5800) || (0x6800 < _engine_state_962)) ||
          (_engine_fault_cb60 != 0)) || (speed_input_ready != '\0')) {
        _engine_state_valid = 0;
        bVar5 = test_command._0_1_;
        test_command._0_1_ = bVar5 & 0x80;
        _test_command_timer_0 = 0;
        _test_command_timer_1 = 0;
      }
      else {
        _engine_state_valid = 1;
        test_command_dispatch(0);
      }
    }
    scheduler_tick();
    bVar5 = 0;
    do {
      pcVar2 = (char *)((ushort)bVar5 * 2 + -0x3ab3);
      if (*(char *)(uint3)((short)&scheduler_counter + (ushort)bVar5 * 2) != *pcVar2) {
        *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
        pbVar1 = *(byte **)(uint3)((short)&scheduler_counter_table + (ushort)bVar5 * 6);
        if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
          *(undefined1 *)ZEXT23(pcVar2) = 0;
        }
        empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
      }
      bVar5 = bVar5 + 1;
    } while (bVar5 < 2);
    uVar3 = scheduler_event_flag;
    if ((uVar3 & 4) == 0) {
      empty_stub_0();
    }
    else {
      uVar3 = scheduler_event_flag;
      scheduler_event_flag = uVar3 | 0x10;
    }
    kline_transport_task(1);
    if (_kline_state - 4U < 0xc) break;
    diag_status_build();
    sVar4 = empty_stub_0();
    if (sVar4 != 0) {
      uVar3 = PSW;
      PSW = uVar3 & 0xf7ff;
      __disable_watchdog();
      if (_scheduler_ext_3 != 0 || _scheduler_ext_2 != 0) {
        empty_stub_0();
      }
      uVar3 = P1H;
      P1H = uVar3 & 0xfffb;
      __software_reset();
      return;
    }
  }
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((short)&scheduler_task_table + (_kline_state - 4U) * 2 & 0x3fff) |
            0xc10000))();
  return;
}


