/* ============================================================================
 * Delphi MT05.2 semantic reconstruction: application firmware part
 * Generated from Ghidra decompiler output; not compilable source.
 * Functions are grouped by area and sorted by address.
 * ========================================================================== */

/* ============================== Startup / runtime ============================== */

/* ----------------------------------------------------------------------------
 * app_clear_flag
 * Address: 0xC0BFD2
 * Area:    application/00-startup-runtime
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c0bfd2 app_clear_flag */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clear application flag. */

void app_clear_flag(void)

{
  _app_flag = 0;
  return;
}


/* ----------------------------------------------------------------------------
 * app_run
 * Address: 0xC0BFE2
 * Area:    application/00-startup-runtime
 * Size:    16 bytes
 * -------------------------------------------------------------------------- */
/* c0bfe2 app_run */

/* Application run entry. */

void app_run(short param_1)

{
  if ((param_1 != 0) && (param_1 != 1)) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  app_main_init();
  return;
}


/* ----------------------------------------------------------------------------
 * app_main
 * Address: 0xC0FFDE
 * Area:    application/00-startup-runtime
 * Size:    16 bytes
 * -------------------------------------------------------------------------- */
/* c0ffde app_main */

/* Application main entry. */

void app_main(void)

{
  input_latch();
  app_hw_init();
  app_run(0);
  return;
}


/* ----------------------------------------------------------------------------
 * app_entry
 * Address: 0xC10000
 * Area:    application/00-startup-runtime
 * Size:    4 bytes
 * -------------------------------------------------------------------------- */
/* c10000 app_entry */

/* WARNING: This function may have set the stack pointer */
/* Application far-call entry trampoline; jumps to app_cstart. */

void app_entry(void)

{
  bool bVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  __disable_watchdog();
  ADDRSEL1 = 0x17;
  ADDRSEL2 = 0x8fbb;
  DAT_00ffdc = 0;
  P8 = 0;
  DAT_00ffaa = 0;
  DAT_00fefa = 0x8000;
  SYSCON = 0xc1;
  __atomic(3);
  SP = 0xfc00;
  STKOV = 0xfada;
  STKUN = 0xfc00;
  uVar3 = (ushort)&boot_iram_fill_start;
  do {
    *(undefined2 *)(uint3)uVar3 = 0x165;
    bVar1 = uVar3 != (ushort)&UNK_00fbfe;
    uVar3 = uVar3 + 2;
  } while (bVar1);
  uVar2 = DPP0;
  DPP0 = 3;
  uVar3 = 0x2ca;
  do {
    *(undefined2 *)(uint3)uVar3 = 0x167;
    bVar1 = uVar3 != 0x368;
    uVar3 = uVar3 + 2;
  } while (bVar1);
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  DPP1 = 0x302;
  DPP2 = 0x303;
  app_cinit();
  app_main(0,0,0);
  do {
    __idle();
  } while( true );
}


/* ----------------------------------------------------------------------------
 * timeout_counter_tick
 * Address: 0xC108B4
 * Area:    application/00-startup-runtime
 * Size:    26 bytes
 * -------------------------------------------------------------------------- */
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


/* ----------------------------------------------------------------------------
 * app_cinit
 * Address: 0xC1192C
 * Area:    application/00-startup-runtime
 * Size:    372 bytes
 * -------------------------------------------------------------------------- */
/* c1192c app_cinit */

/* Application C runtime init table walker. */

void app_cinit(void)

{
  bool bVar1;
  undefined1 *puVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  short sVar8;
  short sVar9;
  
  uVar4 = (ushort)&stack_guard_fdfe;
  do {
    if ((uVar4 != (ushort)&UNK_00fcc2) && (uVar4 != (ushort)&UNK_00fcc0)) {
      *(undefined2 *)(uint3)uVar4 = 0;
    }
    bVar1 = uVar4 != (ushort)&input_status_flags;
    uVar4 = uVar4 - 2;
  } while (bVar1);
  uVar4 = (ushort)&app_init_table;
  do {
    DPP0 = 0x302;
    while( true ) {
      while( true ) {
        uVar6 = uVar4 + 2;
        sVar8 = *(short *)(uint3)uVar4;
        if (sVar8 != 1) break;
        uVar4 = uVar4 + 0xe;
      }
      if (sVar8 == 5) break;
      if (sVar8 == 6) {
        uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
        DPP1 = *(undefined2 *)(uint3)(uVar4 + 4);
        uVar7 = *(ushort *)(uint3)(uVar4 + 6) & 0xbfff | 0x8000;
        DPP2 = *(undefined2 *)(uint3)(uVar4 + 8);
        uVar6 = uVar4 + 10;
        uVar4 = uVar4 + 0xc;
        sVar8 = *(short *)(uint3)uVar6;
        while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
          puVar2 = (undefined1 *)(uint3)uVar7;
          uVar7 = uVar7 + 1;
          *(undefined1 *)(uint3)uVar5 = *puVar2;
          bVar1 = uVar5 == 0x7fff;
          uVar5 = uVar5 + 1;
          if (bVar1) {
            uVar5 = 0x4000;
            sVar9 = DPP1;
            DPP1 = sVar9 + 1;
          }
        }
        DPP1 = 0x302;
        DPP2 = 0x303;
      }
      else {
        if (sVar8 != 7) {
          uVar4 = 0;
          do {
            DPP0 = 0x303;
            while( true ) {
              uVar6 = uVar4 + 2;
              sVar8 = *(short *)(uint3)uVar4;
              if (sVar8 == 5) break;
              if (sVar8 == 6) {
                uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
                DPP1 = *(undefined2 *)(uint3)(uVar4 + 4);
                uVar6 = uVar4 + 6;
                uVar4 = uVar4 + 8;
                sVar8 = *(short *)(uint3)uVar6;
                while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
                  *(undefined1 *)(uint3)uVar5 = 0;
                  uVar5 = uVar5 + 1;
                }
                DPP1 = 0x302;
              }
              else {
                if (sVar8 != 7) {
                  DPP0 = 0x301;
                  return;
                }
                DPP1 = (*(ushort *)(uint3)(uVar4 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar6 >> 0xe;
                uVar6 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
                uVar5 = uVar4 + 8;
                sVar8 = *(short *)(uint3)(uVar4 + 6);
                uVar4 = uVar4 + 10;
                sVar9 = *(short *)(uint3)uVar5;
                while ((bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1 ||
                       (bVar1 = sVar9 != 0, sVar9 = sVar9 + -1, bVar1))) {
                  *(undefined1 *)(uint3)uVar6 = 0;
                  bVar1 = uVar6 == 0x7fff;
                  uVar6 = uVar6 + 1;
                  if (bVar1) {
                    uVar6 = 0x4000;
                    sVar3 = DPP1;
                    DPP1 = sVar3 + 1;
                  }
                }
                DPP1 = 0x302;
              }
            }
            uVar5 = uVar4 + 4;
            uVar6 = *(ushort *)(uint3)uVar6;
            uVar4 = uVar4 + 6;
            sVar8 = *(short *)(uint3)uVar5;
            DPP0 = 0x301;
            while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
              *(undefined1 *)(uint3)uVar6 = 0;
              uVar6 = uVar6 + 1;
            }
          } while( true );
        }
        DPP1 = (*(ushort *)(uint3)(uVar4 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar6 >> 0xe;
        uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
        DPP2 = (*(ushort *)(uint3)(uVar4 + 8) & 0xff) << 2 | *(ushort *)(uint3)(uVar4 + 6) >> 0xe;
        uVar6 = *(ushort *)(uint3)(uVar4 + 6) & 0xbfff | 0x8000;
        uVar7 = uVar4 + 0xc;
        sVar8 = *(short *)(uint3)(uVar4 + 10);
        uVar4 = uVar4 + 0xe;
        sVar9 = *(short *)(uint3)uVar7;
        while ((bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1 ||
               (bVar1 = sVar9 != 0, sVar9 = sVar9 + -1, bVar1))) {
          *(undefined1 *)(uint3)uVar5 = *(undefined1 *)(uint3)uVar6;
          bVar1 = uVar5 == 0x7fff;
          uVar5 = uVar5 + 1;
          if (bVar1) {
            uVar5 = 0x4000;
            sVar3 = DPP1;
            DPP1 = sVar3 + 1;
          }
          bVar1 = uVar6 == 0xbfff;
          uVar6 = uVar6 + 1;
          if (bVar1) {
            uVar6 = 0x8000;
            sVar3 = DPP2;
            DPP2 = sVar3 + 1;
          }
        }
        DPP1 = 0x302;
        DPP2 = 0x303;
      }
    }
    uVar6 = *(ushort *)(uint3)uVar6;
    uVar7 = uVar4 + 6;
    uVar5 = *(ushort *)(uint3)(uVar4 + 4);
    uVar4 = uVar4 + 8;
    sVar8 = *(short *)(uint3)uVar7;
    DPP0 = 0x301;
    while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
      puVar2 = (undefined1 *)(uint3)uVar5;
      uVar5 = uVar5 + 1;
      *(undefined1 *)(uint3)uVar6 = *puVar2;
      uVar6 = uVar6 + 1;
    }
  } while( true );
}


/* ----------------------------------------------------------------------------
 * app_cstart
 * Address: 0xC11AA0
 * Area:    application/00-startup-runtime
 * Size:    138 bytes
 * -------------------------------------------------------------------------- */
/* c11aa0 app_cstart */

/* WARNING: This function may have set the stack pointer */
/* Application C runtime startup; copies init data then calls app_main. */

void app_cstart(void)

{
  bool bVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  __disable_watchdog();
  ADDRSEL1 = 0x17;
  ADDRSEL2 = 0x8fbb;
  DAT_00ffdc = 0;
  P8 = 0;
  DAT_00ffaa = 0;
  DAT_00fefa = 0x8000;
  SYSCON = 0xc1;
  __atomic(3);
  SP = 0xfc00;
  STKOV = 0xfada;
  STKUN = 0xfc00;
  uVar3 = (ushort)&boot_iram_fill_start;
  do {
    *(undefined2 *)(uint3)uVar3 = 0x165;
    bVar1 = uVar3 != (ushort)&UNK_00fbfe;
    uVar3 = uVar3 + 2;
  } while (bVar1);
  uVar2 = DPP0;
  DPP0 = 3;
  uVar3 = 0x2ca;
  do {
    *(undefined2 *)(uint3)uVar3 = 0x167;
    bVar1 = uVar3 != 0x368;
    uVar3 = uVar3 + 2;
  } while (bVar1);
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  DPP1 = 0x302;
  DPP2 = 0x303;
  app_cinit();
  app_main(0,0,0);
  do {
    __idle();
  } while( true );
}


/* ----------------------------------------------------------------------------
 * app_hw_init
 * Address: 0xC11BF4
 * Area:    application/00-startup-runtime
 * Size:    102 bytes
 * -------------------------------------------------------------------------- */
/* c11bf4 app_hw_init */

/* WARNING: Control flow encountered bad instruction data */
/* Application hardware initialization sequence. */

void app_hw_init(void)

{
  ushort uVar1;
  
  can_bus_config();
  uVar1 = DAT_00f0fe;
  DAT_00f0fe = uVar1 | 1;
  P7 = 0x7f13;
  port_bus_init();
  adc_calibrate();
  adc_start();
  asc0_init_app();
  ssc0_init_app();
  ssc_rx_queue_init();
  pwm_init();
  timer8_init();
  capcom_start();
  timer5_init();
  app_clear_flag();
  capture_init();
  config_sensor_setup();
  timer6_start();
  angle_init();
  event_init();
  timer4_init();
  ssc_init();
  set_can_flag();
  cal_checksum();
  can_bus_config();
  WDTCON = 0xbc01;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ----------------------------------------------------------------------------
 * app_main_init
 * Address: 0xC11C62
 * Area:    application/00-startup-runtime
 * Size:    76 bytes
 * -------------------------------------------------------------------------- */
/* c11c62 app_main_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Application main initialization; enters scheduler. */

void app_main_init(void)

{
  ushort *puVar1;
  ushort uVar2;
  byte bVar3;
  
  if ((_scheduler_ext_1 | _scheduler_ext_0) != 0) {
    empty_stub_0(_scheduler_ext_1 | _scheduler_ext_0);
  }
  bVar3 = 0;
  do {
    puVar1 = (ushort *)((short)&scheduler_counter_table + (ushort)bVar3 * 6);
    uVar2 = (ushort)bVar3;
    bVar3 = bVar3 + 1;
    *(undefined1 *)(uint3)((short)&scheduler_counter + uVar2 * 2) =
         *(undefined1 *)(uint3)*(ushort *)ZEXT23(puVar1);
    *(undefined1 *)(uint3)(uVar2 * 2 + 0xc54d) = *(undefined1 *)(uint3)*puVar1;
  } while (bVar3 < 2);
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  uVar2 = P1H;
  P1H = uVar2 | 4;
  app_scheduler();
  return;
}


/* ----------------------------------------------------------------------------
 * app_idle_wait
 * Address: 0xC11CAE
 * Area:    application/00-startup-runtime
 * Size:    238 bytes
 * -------------------------------------------------------------------------- */
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


/* ----------------------------------------------------------------------------
 * app_scheduler
 * Address: 0xC11EB4
 * Area:    application/00-startup-runtime
 * Size:    18 bytes
 * -------------------------------------------------------------------------- */
/* c11eb4 app_scheduler */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Application scheduler entry. */

void app_scheduler(void)

{
  byte *pbVar1;
  char *pcVar2;
  ushort uVar3;
  short sVar4;
  byte bVar5;
  
  while( true ) {
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
    uVar3 = scheduler_event_flag;
    if ((uVar3 & 4) == 0) break;
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
    if (_kline_state - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((short)&scheduler_task_table + (_kline_state - 4U) * 2 & 0x3fff)
                | 0xc10000))();
      return;
    }
    diag_status_build();
  }
  app_scheduler();
  return;
}


/* ----------------------------------------------------------------------------
 * app_scheduler_path
 * Address: 0xC11EC6
 * Area:    application/00-startup-runtime
 * Size:    38 bytes
 * -------------------------------------------------------------------------- */
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


/* ----------------------------------------------------------------------------
 * scheduler_tick
 * Address: 0xC11EEC
 * Area:    application/00-startup-runtime
 * Size:    24 bytes
 * -------------------------------------------------------------------------- */
/* c11eec scheduler_tick */

/* Increments the scheduler counter and dispatches command 3. */

void scheduler_tick(void)

{
  scheduler_counter = scheduler_counter + 1;
  if (scheduler_counter_reload < scheduler_counter) {
    scheduler_counter = 0;
  }
  command_dispatch_index3();
  return;
}


/* ----------------------------------------------------------------------------
 * command_dispatch_index3
 * Address: 0xC147C6
 * Area:    application/00-startup-runtime
 * Size:    8 bytes
 * -------------------------------------------------------------------------- */
/* c147c6 command_dispatch_index3 */

/* Calls command_dispatch with index 3. */

void command_dispatch_index3(void)

{
  command_dispatch(3);
  return;
}


/* ----------------------------------------------------------------------------
 * command_dispatch
 * Address: 0xC19A2C
 * Area:    application/00-startup-runtime
 * Size:    20 bytes
 * -------------------------------------------------------------------------- */
/* c19a2c command_dispatch */

/* Dispatches command index 0..6 through the external-RAM table at 0x7666. */

void command_dispatch(byte param_1)

{
  if (6 < param_1) {
    return;
  }
                    /* WARNING: Could not emulate address calculation at 0xc19a3a */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((short)&command_handler_table + (ushort)param_1 * 2 & 0x3fff) |
            0xc10000))();
  return;
}


/* ============================== Drivers / CAN ============================== */

/* ----------------------------------------------------------------------------
 * can_twincan_init
 * Address: 0xC00434
 * Area:    application/01-drivers/can
 * Size:    608 bytes
 * -------------------------------------------------------------------------- */
/* c00434 can_twincan_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* TwinCAN initialization; message object 0 ID 0x7E0/0x7E4 (diagnostic). */

void can_twincan_init(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  
  _can_rx_flag = 0;
  _DAT_200200 = 0;
  _DAT_200210 = 0;
  _DAT_200222 = 0x60;
  uVar2 = DAT_00ff38;
  DAT_00ff38 = uVar2 | 8;
  uVar2 = BUSCON3;
  BUSCON3 = uVar2 & 0xfff7 | 8;
  uVar2 = DAT_00ff3a;
  DAT_00ff3a = uVar2 | 8;
  _DAT_20020c = 0x2387;
  _DAT_20020e = 0;
  _DAT_200214 = 0;
  _DAT_200216 = 0;
  _DAT_200314 = 0x80;
  _DAT_200316 = _DAT_200516 & 0xfff8;
  _DAT_20030c = 0xffff;
  _DAT_20030e = 0xffff;
  _DAT_200308 = 0;
  _DAT_20030a = 0x1f80;
  _DAT_200300 = 0;
  _DAT_200302 = 0;
  _DAT_200304 = 0;
  _DAT_200306 = 0;
  _DAT_200318 = 0;
  _DAT_20031a = _DAT_20031a & 0xffe0;
  _DAT_200310 = 0x1599;
  _DAT_200312 = 0;
  _DAT_200514 = 0x88;
  _DAT_200516 = _DAT_200356 & 0xfff8 | 2;
  _DAT_20050c = 0xffff;
  _DAT_20050e = 0xffff;
  _DAT_200508 = 0;
  _DAT_20050a = 0x1f90;
  _DAT_200500 = 0;
  _DAT_200502 = 0;
  _DAT_200504 = 0;
  _DAT_200506 = 0;
  _DAT_200518 = 0x200f;
  _DAT_20051a = 0x210;
  _DAT_200510 = 0x1595;
  _DAT_200512 = 0;
  bVar3 = 0;
  do {
    sVar1 = (ushort)bVar3 * 0x20;
    *(undefined2 *)((uint3)(sVar1 + 0x534) + 0x200000) = 8;
    *(undefined2 *)((uint3)(sVar1 + 0x536) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x52c) + 0x200000) = 0xffff;
    *(undefined2 *)((uint3)(sVar1 + 0x52e) + 0x200000) = 0xffff;
    *(undefined2 *)((uint3)(sVar1 + 0x528) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x52a) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x520) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x522) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x524) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x526) + 0x200000) = 0;
    *(undefined2 *)((uint3)(sVar1 + 0x538) + 0x200000) = 0x200f;
    *(undefined2 *)((uint3)(sVar1 + 0x53a) + 0x200000) = 0x310;
    *(undefined2 *)((uint3)(sVar1 + 0x530) + 0x200000) = 0x1595;
    *(undefined2 *)((uint3)(sVar1 + 0x532) + 0x200000) = 0;
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0xf);
  uVar2 = XP2IC;
  XP2IC = uVar2 | 8;
  uVar2 = CC15IC;
  CC15IC = uVar2 | 0x40;
  ram_var_c000 = 0x10;
  _DAT_200004 = 0xb;
  _DAT_200200 = _DAT_200200 & 0xffbe;
  return;
}


/* ----------------------------------------------------------------------------
 * can0_isr
 * Address: 0xC00694
 * Area:    application/01-drivers/can
 * Size:    232 bytes
 * -------------------------------------------------------------------------- */
/* c00694 can0_isr */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAN0 interrupt handler; processes message object 0 and calls can_rx_process. */

void can0_isr(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  byte bVar15;
  
  isr_save_fc00 = &stack0x0000;
  uVar5 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DPP0 = 0x300;
  uVar6 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP2 = 0x302;
  uVar14 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar8 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar9 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar13 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar12 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar10 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar11 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DPP3;
  uVar7 = DPP3;
  uVar7 = DPP3;
  can_rx_process(uVar4,uVar3,uVar2,uVar1,uVar11,uVar10,uVar12,uVar13,uVar9,uVar8,uVar14,uVar6,uVar5)
  ;
  while ((_DAT_200284 & 1) != 0) {
    if ((_DAT_200310 & 3) == 2) {
      if ((((_DAT_200284 & 1) != 0) && ((_DAT_200310 & 0x300) == 0x200)) &&
         ((_DAT_200310 & 0xc00) != 0x800)) {
        bVar15 = 0;
        do {
          bVar15 = bVar15 + 1;
        } while (bVar15 < 8);
        _can_rx_flag = 1;
      }
      _DAT_200310 = 0xfffd;
    }
  }
  DAT_00f006 = uVar4;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  DAT_00f004 = uVar3;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  DAT_00f002 = uVar2;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DAT_00ff0a = uVar11;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  DAT_00ff08 = uVar10;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  DAT_00ffda = uVar12;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  DAT_00ffdc = uVar13;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  DAT_00fe5e = uVar9;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  DAT_00fe5c = uVar8;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  DAT_00ffde = uVar14;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  DPP2 = uVar6;
  uVar1 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP0 = uVar5;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}


/* ----------------------------------------------------------------------------
 * set_can_flag
 * Address: 0xC0BA9E
 * Area:    application/01-drivers/can
 * Size:    22 bytes
 * -------------------------------------------------------------------------- */
/* c0ba9e set_can_flag */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Set CAN/application flag. */

void set_can_flag(void)

{
  ushort uVar1;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  _can_callback_ptr = 0xbab4;
  _can_callback_ptr_hi = 0xc0;
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


/* ----------------------------------------------------------------------------
 * can_bus_config
 * Address: 0xC11B2A
 * Area:    application/01-drivers/can
 * Size:    112 bytes
 * -------------------------------------------------------------------------- */
/* c11b2a can_bus_config */

/* CAN bus pin/mode configuration. */

void can_bus_config(void)

{
  ushort uVar1;
  undefined2 uVar2;
  
  uVar1 = DAT_00f0c2;
  if ((uVar1 & 0x1800) == 0x800) {
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x8e00;
  }
  uVar1 = DAT_00f0c2;
  if ((uVar1 & 0x1800) == 0x1800) {
    DAT_00f0c0 = 0xaaaa;
    PECC0 = 0x5554;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x9600;
    PECC0 = 0x800;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x8e00;
  }
  return;
}


/* ============================== Drivers / K-line ASC0 ============================== */

/* ----------------------------------------------------------------------------
 * asc0_init
 * Address: 0xC00C36
 * Area:    application/01-drivers/kline-asc0
 * Size:    78 bytes
 * -------------------------------------------------------------------------- */
/* c00c36 asc0_init */

/* ASC0 (UART/K-line) initialization; S0BG, S0CON, port setup. */

void asc0_init(char param_1)

{
  ushort uVar1;
  
  if (param_1 == '\x02') {
    DAT_00feb6 = 0x1ce;
    S0BG = 0x2e;
  }
  else {
    DAT_00feb6 = 0xcd;
    S0BG = 0x4c;
  }
  S0CON = 0x811;
  DAT_00f0c6 = 0x807;
  DAT_00f0c4 = 0x807;
  uVar1 = CCM6;
  CCM6 = uVar1 | 0x400;
  uVar1 = P3;
  P3 = uVar1 & 0xfbff | 0x400;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfbff | 0x400;
  uVar1 = T0IC;
  T0IC = uVar1 | 0x80;
  uVar1 = S0TIC;
  S0TIC = uVar1 | 0x80;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x8000;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_tx_byte
 * Address: 0xC00C84
 * Area:    application/01-drivers/kline-asc0
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c00c84 asc0_tx_byte */

/* Writes one byte to the ASC0 transmit buffer S0TBUF. */

void asc0_tx_byte(undefined2 param_1)

{
  S0TBUF = param_1;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_read_rx_clear
 * Address: 0xC00C8A
 * Area:    application/01-drivers/kline-asc0
 * Size:    8 bytes
 * -------------------------------------------------------------------------- */
/* c00c8a asc0_read_rx_clear */

/* Clears the ASC0 receive flag and returns one S0RBUF byte. */

undefined2 asc0_read_rx_clear(void)

{
  undefined2 uVar1;
  ushort uVar2;
  
  uVar2 = S0RIC;
  S0RIC = uVar2 & 0xff7f;
  uVar1 = Ram00feb2;
  return uVar1;
}


/* ----------------------------------------------------------------------------
 * asc0_pin_init
 * Address: 0xC00DDC
 * Area:    application/01-drivers/kline-asc0
 * Size:    44 bytes
 * -------------------------------------------------------------------------- */
/* c00ddc asc0_pin_init */

/* ASC0 alternate-function pin setup. */

void asc0_pin_init(void)

{
  ushort uVar1;
  
  uVar1 = SSCCON;
  SSCCON = uVar1 & 0x7fff;
  S0BG = 1;
  uVar1 = P3;
  P3 = uVar1 & 0xdfff;
  uVar1 = CCM6;
  CCM6 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 | 0x2000;
  SSCCON = 0xc037;
  uVar1 = P3;
  P3 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfeff;
  uVar1 = P3;
  P3 = uVar1 | 0x200;
  uVar1 = CCM6;
  CCM6 = uVar1 | 0x200;
  uVar1 = DP3;
  DP3 = uVar1 | 0x200;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x10;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x40;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x80;
  uVar1 = SSCTIC;
  SSCTIC = uVar1 | 0x80;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_state_dispatch
 * Address: 0xC01144
 * Area:    application/01-drivers/kline-asc0
 * Size:    26 bytes
 * -------------------------------------------------------------------------- */
/* c01144 asc0_state_dispatch */

/* Dispatch ASC0 K-line state 0..5 through table at 0xC00428. */

void asc0_state_dispatch(void)

{
  if (5 < kline_state_machine) {
    kline_state_machine = 0;
    return;
  }
                    /* WARNING: Could not emulate address calculation at 0xc01154 */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((ushort)kline_state_machine * 2 + 0x428) | 0xc00000))();
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_task0
 * Address: 0xC01158
 * Area:    application/01-drivers/kline-asc0
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c01158 asc0_task0 */

/* K-line state 0 wrapper. */

void asc0_task0(void)

{
  asc0_state0();
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_task1
 * Address: 0xC0115E
 * Area:    application/01-drivers/kline-asc0
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c0115e asc0_task1 */

/* K-line state 1 wrapper. */

void asc0_task1(void)

{
  asc0_state1();
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_task2
 * Address: 0xC01164
 * Area:    application/01-drivers/kline-asc0
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c01164 asc0_task2 */

/* K-line state 2 wrapper. */

void asc0_task2(void)

{
  asc0_state2();
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_task3
 * Address: 0xC0116A
 * Area:    application/01-drivers/kline-asc0
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c0116a asc0_task3 */

/* K-line state 3 wrapper. */

void asc0_task3(void)

{
  asc0_state3();
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_task4
 * Address: 0xC01170
 * Area:    application/01-drivers/kline-asc0
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c01170 asc0_task4 */

/* K-line state 4 wrapper. */

void asc0_task4(void)

{
  asc0_state4();
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_task5
 * Address: 0xC01176
 * Area:    application/01-drivers/kline-asc0
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c01176 asc0_task5 */

/* K-line state 5 wrapper. */

void asc0_task5(void)

{
  asc0_state5();
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_clear_state
 * Address: 0xC01182
 * Area:    application/01-drivers/kline-asc0
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c01182 asc0_clear_state */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clear ASC0/K-line state. */

void asc0_clear_state(void)

{
  _kline_rx_retry = 0;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_state0
 * Address: 0xC01188
 * Area:    application/01-drivers/kline-asc0
 * Size:    22 bytes
 * -------------------------------------------------------------------------- */
/* c01188 asc0_state0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line state 0: idle / start. */

void asc0_state0(void)

{
  ushort uVar1;
  
  kline_state_machine = 1;
  _kline_rx_timeout = 0;
  asc0_clear_state();
  _kline_var_c13a = 0;
  uVar1 = S0CON;
  S0CON = uVar1 & 0xffef;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_state1
 * Address: 0xC0119E
 * Area:    application/01-drivers/kline-asc0
 * Size:    56 bytes
 * -------------------------------------------------------------------------- */
/* c0119e asc0_state1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line state 1: wake-up / 5-baud handling. */

void asc0_state1(void)

{
  ushort uVar1;
  
  uVar1 = P3;
  if ((uVar1 & 0x800) == 0) {
    _kline_rx_timeout = _kline_rx_timeout + 1;
    return;
  }
  if ((0x14 < _kline_rx_timeout) && (_kline_rx_timeout < 0x1c)) {
    kline_state_machine = 2;
    kline_rx_index = 0;
    uVar1 = DAT_00f0c6;
    DAT_00f0c6 = uVar1 & 0xfffd | 2;
    uVar1 = S0CON;
    S0CON = uVar1 | 0x10;
  }
  _kline_rx_timeout = 0;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_state2
 * Address: 0xC011D6
 * Area:    application/01-drivers/kline-asc0
 * Size:    60 bytes
 * -------------------------------------------------------------------------- */
/* c011d6 asc0_state2 */

/* K-line state 2: receive frame bytes. */

void asc0_state2(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 uVar3;
  
  while( true ) {
    uVar1 = S0RIC;
    if ((uVar1 & 0x80) == 0) {
      return;
    }
    uVar3 = asc0_read_rx_clear();
    uVar2 = (ushort)kline_rx_index;
    uVar1 = (short)&kline_rx_buffer + uVar2;
    *(undefined1 *)(uint3)uVar1 = uVar3;
    if (*(char *)(uint3)uVar1 != *(char *)(uint3)((short)&kline_wakeup_pattern + uVar2)) break;
    if (kline_rx_index == 4) {
      kline_state_machine = kline_state_machine + '\x01';
      kwp_request_pending = 1;
      kline_receive_pattern();
      return;
    }
    kline_rx_index = kline_rx_index + 1;
  }
  kline_state_machine = 1;
  kline_receive_pattern();
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_state2_init
 * Address: 0xC01218
 * Area:    application/01-drivers/kline-asc0
 * Size:    58 bytes
 * -------------------------------------------------------------------------- */
/* c01218 asc0_state2_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initialize K-line receive frame. */

void asc0_state2_init(char param_1)

{
  ushort uVar1;
  
  asc0_clear_state();
  if (param_1 == '\x02') {
    kline_init_mode = 0x5e;
    _kline_init_timer = 0x49fb;
    kline_rx_timeout_limit = 0x79;
  }
  kline_state_machine = 3;
  kline_tx_phase = 0;
  security_unlocked = 1;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x10;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_state3
 * Address: 0xC01252
 * Area:    application/01-drivers/kline-asc0
 * Size:    148 bytes
 * -------------------------------------------------------------------------- */
/* c01252 asc0_state3 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line state 3: receive/validate. */

void asc0_state3(void)

{
  ushort uVar1;
  
  if (kline_tx_phase == '\0') {
    kline_frame_retry = 0;
    kline_tx_phase = '\x01';
    goto LAB_c012ba;
  }
  if (kline_tx_phase != '\x01') {
    kline_tx_phase = '\0';
    goto LAB_c012ba;
  }
  uVar1 = S0RIC;
  if ((uVar1 & 0x80) == 0) {
    if ((kline_frame_flag == '\x01') && (kline_init_mode < kline_frame_retry)) {
      kline_state_machine = 5;
      goto LAB_c01292;
    }
    if ((kline_frame_flag == '\0') && (kwp_routine_active == '\x01')) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else {
    kline_state_machine = 4;
LAB_c01292:
    kline_tx_phase = '\0';
  }
  kline_frame_retry = kline_frame_retry + 1;
LAB_c012ba:
  _kline_rx_retry = _kline_rx_retry + 1;
  if (_kline_init_timer < _kline_rx_retry) {
    _kline_rx_retry = 0;
    kline_state_machine = 2;
    kline_rx_index = 0;
    uVar1 = DAT_00f0c6;
    DAT_00f0c6 = uVar1 & 0xfffd | 2;
    uVar1 = S0CON;
    S0CON = uVar1 | 0x10;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_state4
 * Address: 0xC012E6
 * Area:    application/01-drivers/kline-asc0
 * Size:    258 bytes
 * -------------------------------------------------------------------------- */
/* c012e6 asc0_state4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line state 4: transmit response. */

void asc0_state4(void)

{
  undefined1 uVar1;
  ushort uVar2;
  
  if (kline_tx_phase == '\0') {
    kline_rx_index = 0;
    kwp_request = 4;
    kline_tx_phase = '\x01';
    _kline_rx_timeout_counter = 0;
  }
  else if (kline_tx_phase != '\x01') {
    if (kline_tx_phase == '\x02') {
      for (; (uVar2 = S0RIC, (uVar2 & 0x80) != 0 && ((ushort)kline_rx_index <= kwp_request + 4));
          kline_rx_index = kline_rx_index + 1) {
        uVar1 = asc0_read_rx_clear(0);
        *(undefined1 *)(uint3)((short)&kline_rx_buffer + (ushort)kline_rx_index) = uVar1;
        _kline_rx_timeout_counter = 0;
      }
      _kline_rx_timeout_counter = _kline_rx_timeout_counter + 1;
      _kline_frame_total = kwp_request + 4;
      if (_kline_frame_total < kline_rx_index) {
        for (uVar2 = 0; uVar2 < _kline_frame_total; uVar2 = uVar2 + 1) {
        }
        kline_state_machine = 3;
        kline_tx_phase = '\0';
        kwp_request_pending = 1;
      }
      else if (kline_rx_timeout_limit < _kline_rx_timeout_counter) {
        kline_state_machine = 3;
        kline_tx_phase = '\0';
        kline_rx_buffer = 0;
      }
    }
    else {
      kline_tx_phase = '\0';
    }
    goto LAB_c013e2;
  }
  for (; (uVar2 = S0RIC, (uVar2 & 0x80) != 0 && (kline_rx_index < 3));
      kline_rx_index = kline_rx_index + 1) {
    uVar1 = asc0_read_rx_clear();
    uVar2 = (short)&kline_rx_buffer + (ushort)kline_rx_index;
    *(undefined1 *)(uint3)uVar2 = uVar1;
    if ((ushort)*(byte *)(uint3)uVar2 !=
        *(ushort *)(uint3)((short)&kline_header_pattern + (ushort)kline_rx_index * 2)) {
      kline_state_machine = 3;
      kline_tx_phase = '\0';
    }
  }
  if (kline_rx_index == 3) {
    kline_tx_phase = '\x02';
  }
LAB_c013e2:
  _kline_rx_retry = _kline_rx_retry + 1;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_state5
 * Address: 0xC013E8
 * Area:    application/01-drivers/kline-asc0
 * Size:    154 bytes
 * -------------------------------------------------------------------------- */
/* c013e8 asc0_state5 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line state 5: finish. */

void asc0_state5(void)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = '\0';
  if (kline_tx_phase == '\0') {
    _kline_tx_index = 0;
    kline_response_frame = 0x80;
    kline_response_target = 0xf1;
    kline_response_source = 0x11;
    _kline_frame_total = kline_response_length + 4;
    for (uVar2 = 0; uVar2 < _kline_frame_total; uVar2 = uVar2 + 1) {
      cVar1 = cVar1 + *(char *)(uint3)((short)&kline_response_frame + uVar2);
    }
    *(char *)(uint3)((short)&kline_response_payload + (ushort)kline_response_length) = cVar1;
    kline_tx_phase = '\x01';
    uVar2 = S0CON;
    S0CON = uVar2 & 0xffef;
  }
  else if (kline_tx_phase == '\x01') {
    uVar2 = (short)&kline_response_frame + _kline_tx_index;
    _kline_tx_index = _kline_tx_index + 1;
    asc0_tx_byte(*(undefined1 *)(uint3)uVar2);
    if (_kline_frame_total < _kline_tx_index) {
      kline_tx_phase = '\x02';
    }
  }
  else {
    if (kline_tx_phase == '\x02') {
      uVar2 = S0CON;
      S0CON = uVar2 | 0x10;
      kline_state_machine = 3;
      kline_frame_flag = 0;
    }
    kline_tx_phase = '\0';
  }
  kline_frame_retry = kline_frame_retry + '\x01';
  _kline_rx_retry = 0;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_init_app
 * Address: 0xC11F1C
 * Area:    application/01-drivers/kline-asc0
 * Size:    62 bytes
 * -------------------------------------------------------------------------- */
/* c11f1c asc0_init_app */

/* Application ASC0/K-line initialization. */

void asc0_init_app(void)

{
  ushort uVar1;
  
  DAT_00feb6 = 0x1a2;
  S0BG = 0x9c;
  S0CON = 0x811;
  DAT_00f0c6 = 0x807;
  DAT_00f0c4 = 0x107;
  uVar1 = CCM6;
  CCM6 = uVar1 | 0x400;
  uVar1 = P3;
  P3 = uVar1 & 0xfbff | 0x400;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfbff | 0x400;
  uVar1 = S0RIC;
  S0RIC = uVar1 | 0x49;
  uVar1 = S0TIC;
  S0TIC = uVar1 | 0x4a;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x8000;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_read_rx_raw
 * Address: 0xC11F60
 * Area:    application/01-drivers/kline-asc0
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c11f60 asc0_read_rx_raw */

/* Returns one S0RBUF byte without changing the receive flag. */

undefined1 asc0_read_rx_raw(void)

{
  undefined1 uVar1;
  
  uVar1 = S0RBUF;
  return uVar1;
}


/* ----------------------------------------------------------------------------
 * asc0_rx_handler
 * Address: 0xC11F66
 * Area:    application/01-drivers/kline-asc0
 * Size:    52 bytes
 * -------------------------------------------------------------------------- */
/* c11f66 asc0_rx_handler */

/* ASC0 receive handler: reads S0RBUF and pushes the byte into the K-line ring. */

void asc0_rx_handler(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  
  SRCP0 = &stack0x0000;
  uVar1 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x303;
  uVar4 = asc0_read_rx_raw(uVar2,uVar1);
  kline_push_rx_byte(uVar4);
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}


/* ----------------------------------------------------------------------------
 * asc0_tx_handler
 * Address: 0xC11F9A
 * Area:    application/01-drivers/kline-asc0
 * Size:    98 bytes
 * -------------------------------------------------------------------------- */
/* c11f9a asc0_tx_handler */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* ASC0 transmit/status handler for the K-line transport. */

void asc0_tx_handler(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  SRCP0 = &stack0x0000;
  uVar1 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  DPP2 = 0x303;
  if (_kline_var_c57a == 6) {
    if (_kline_flag_c5a2 == 1) {
      _kline_var_c5ac = 0;
      if (kline_flag_c57d == '\0') {
        kline_state_reset(5);
      }
      else if (kline_var_c5b6 != '\0') {
        kline_rx_state_8(uVar2,uVar1);
      }
    }
    if (_kline_flag_c5a2 == 0) {
      kline_prepare_frame(0);
    }
  }
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}


/* ============================== Drivers / SSC ============================== */

/* ----------------------------------------------------------------------------
 * ssc_send_byte
 * Address: 0xC00E08
 * Area:    application/01-drivers/ssc
 * Size:    12 bytes
 * -------------------------------------------------------------------------- */
/* c00e08 ssc_send_byte */

/* Write one byte to SSC transmit buffer. */

void ssc_send_byte(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = SSCTIC;
  SSCTIC = uVar1 & 0xff7f;
  SSCTB = (ushort)*(byte *)(uint3)param_1;
  return;
}


/* ----------------------------------------------------------------------------
 * ssc0_rx_isr
 * Address: 0xC00E14
 * Area:    application/01-drivers/ssc
 * Size:    182 bytes
 * -------------------------------------------------------------------------- */
/* c00e14 ssc0_rx_isr */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SSC0 receive interrupt; 7-byte frame engine. */

void ssc0_rx_isr(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  byte bVar16;
  
  isr_save_fc60 = &stack0x0000;
  uVar7 = DPP0;
  DPP0 = 0x300;
  uVar8 = DPP2;
  DPP2 = 0x302;
  uVar15 = DAT_00ffde;
  uVar9 = DAT_00fe5c;
  uVar10 = DAT_00fe5e;
  uVar14 = DAT_00ffdc;
  uVar13 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar11 = DAT_00ff08;
  uVar12 = DAT_00ff0a;
  uVar2 = DAT_00f000;
  uVar3 = DAT_00f002;
  uVar4 = DAT_00f004;
  uVar5 = DPP3;
  uVar6 = SSCRB;
  *(undefined1 *)(uint3)_ssc_tx_ptr = uVar6;
  ssc_frame_bytes = ssc_frame_bytes + -1;
  if (ssc_frame_bytes == '\0') {
    uVar1 = P1H;
    P1H = uVar1 | 8;
    bVar16 = 0;
    do {
      uVar1 = (ushort)bVar16;
      bVar16 = bVar16 + 1;
      *(undefined1 *)(uint3)(uVar1 + 0xc082) = *(undefined1 *)(uint3)((short)&ssc_rx_frame + uVar1);
    } while (bVar16 < 7);
    ssc_frame_bytes = '\a';
    _ssc_rx_ptr = (short)&boot_port_cfg_c08c;
    _ssc_tx_ptr = (ushort)&ssc_rx_frame;
  }
  else {
    _ssc_rx_ptr = _ssc_rx_ptr + 1;
    _ssc_tx_ptr = _ssc_tx_ptr + 1;
    ssc_send_byte(_ssc_rx_ptr,uVar5,uVar4,uVar3,uVar2,uVar12,uVar11,uVar13,uVar14,uVar10,uVar9,
                  uVar15,uVar8,uVar7);
  }
  DAT_00f006 = uVar5;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  DAT_00f004 = uVar4;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  DAT_00f002 = uVar3;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DAT_00ff0a = uVar12;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  DAT_00ff08 = uVar11;
  uVar2 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  DAT_00ffda = uVar13;
  uVar2 = DAT_00ffda;
  uVar2 = DAT_00ffda;
  uVar2 = DAT_00ffda;
  DAT_00ffdc = uVar14;
  uVar2 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  DAT_00fe5e = uVar10;
  uVar2 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  DAT_00fe5c = uVar9;
  uVar2 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  DAT_00ffde = uVar15;
  uVar2 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  DPP2 = uVar8;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar7;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}


/* ----------------------------------------------------------------------------
 * ssc_start_frame
 * Address: 0xC00ECA
 * Area:    application/01-drivers/ssc
 * Size:    30 bytes
 * -------------------------------------------------------------------------- */
/* c00eca ssc_start_frame */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Start SSC transfer with 7-byte buffer. */

void ssc_start_frame(void)

{
  ushort uVar1;
  
  uVar1 = P1H;
  P1H = uVar1 & 0xfff7;
  ssc_frame_bytes = 7;
  _ssc_rx_ptr = SUB32(&boot_port_cfg_c08c,0);
  _ssc_tx_ptr = SUB32(&ssc_rx_frame,0);
  ssc_send_byte();
  return;
}


/* ----------------------------------------------------------------------------
 * ssc_init
 * Address: 0xC0D9E4
 * Area:    application/01-drivers/ssc
 * Size:    126 bytes
 * -------------------------------------------------------------------------- */
/* c0d9e4 ssc_init */

/* WARNING: Removing unreachable block (ram,0xc0da4c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SSC/CC26 initialization; installs handlers at 0xC0D8FA and 0xC0D914. */

void ssc_init(void)

{
  ushort uVar1;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  _ssc_callback_ptr_1 = 0xd8fa;
  _ssc_callback_ptr_1_hi = 0xc0;
  _ssc_callback_ptr_2 = 0xd914;
  _ssc_callback_ptr_2_hi = 0xc0;
  cc26_ptr_init();
  *(ushort *)(uint3)_ssc_cc26_flags = *(ushort *)(uint3)_ssc_cc26_flags | 0x68;
  ssc_pin_config();
  if (_ssc_var_c48a != 0) {
    _ssc_callback_ptr_0 = 0xd8ce;
    _ssc_callback_ptr_0_hi = 0xc0;
  }
  if ((_ssc_var_c48c == 0) && (_ssc_var_c48a == 0)) {
    _ssc_var_c3ba = 1;
    _ssc_callback_ptr_0 = 0xd8ce;
    _ssc_callback_ptr_0_hi = 0xc0;
  }
  else {
    _ssc_var_c3ba = 0;
  }
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


/* ----------------------------------------------------------------------------
 * cc26_ptr_init
 * Address: 0xC0DA62
 * Area:    application/01-drivers/ssc
 * Size:    42 bytes
 * -------------------------------------------------------------------------- */
/* c0da62 cc26_ptr_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Stores CC26/CCM6/CC26IC pointers used by the SSC timing path. */

void cc26_ptr_init(void)

{
  _event_var_c48e = SUB32(&CC26,0);
  _ssc_var_c482 = SUB32(&CCM6,0);
  _ssc_cc26_flags = SUB32(&CC26IC,0);
  _ssc_var_c488 = SUB32(&DAT_00fe28,0);
  _event_var_c486 = SUB32(&DAT_00fe2a,0);
  return;
}


/* ----------------------------------------------------------------------------
 * ssc_state_reset
 * Address: 0xC0FC90
 * Area:    application/01-drivers/ssc
 * Size:    22 bytes
 * -------------------------------------------------------------------------- */
/* c0fc90 ssc_state_reset */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Reset SSC state. */

void ssc_state_reset(void)

{
  _ssc_var_c47e = 0;
  ssc_var_c47c = 0;
  ssc_var_c480 = 0;
  ssc_var_c47b = 0;
  ssc_var_c47a = 0;
  return;
}


/* ----------------------------------------------------------------------------
 * ssc_pin_config
 * Address: 0xC0FE7E
 * Area:    application/01-drivers/ssc
 * Size:    48 bytes
 * -------------------------------------------------------------------------- */
/* c0fe7e ssc_pin_config */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SSC/port configuration. */

void ssc_pin_config(void)

{
  ssc_mode_select();
  *(ushort *)(uint3)_ssc_var_c482 = *(ushort *)(uint3)_ssc_var_c482 & 0xf0ff;
  *(ushort *)(uint3)_ssc_var_c482 = *(ushort *)(uint3)_ssc_var_c482 | 0x400;
  *(ushort *)(uint3)_ssc_var_c488 = *(ushort *)(uint3)_ssc_var_c488 | 0x400;
  *(ushort *)(uint3)_ssc_cc26_flags = *(ushort *)(uint3)_ssc_cc26_flags & 0xff7f;
  return;
}


/* ----------------------------------------------------------------------------
 * ssc_mode_select
 * Address: 0xC0FEAE
 * Area:    application/01-drivers/ssc
 * Size:    82 bytes
 * -------------------------------------------------------------------------- */
/* c0feae ssc_mode_select */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Select SSC mode from calibration byte 0xC05036. */

void ssc_mode_select(void)

{
  ssc_var_c484 = 4;
  _ssc_var_c48c = 0;
  if (cal_flag_6b68 == '\0') {
    _ssc_var_c48a = 1;
    if (cal_config_selector == '\x01') {
      _ssc_var_c48a = 0;
      _ssc_var_c48c = 1;
      return;
    }
    if (cal_config_selector == '\x02') {
      ssc_var_c484 = 10;
      return;
    }
    if (cal_config_selector == '\x03') {
      ssc_var_c484 = 8;
      return;
    }
  }
  else {
    _ssc_var_c48a = 0;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * ssc0_init_app
 * Address: 0xC0FF00
 * Area:    application/01-drivers/ssc
 * Size:    40 bytes
 * -------------------------------------------------------------------------- */
/* c0ff00 ssc0_init_app */

/* Application SSC0 initialization. */

void ssc0_init_app(void)

{
  ushort uVar1;
  
  uVar1 = SSCCON;
  SSCCON = uVar1 & 0x7fff;
  S0BG = 3;
  uVar1 = P3;
  P3 = uVar1 & 0xdfff;
  uVar1 = CCM6;
  CCM6 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 | 0x2000;
  SSCCON = 0xc037;
  uVar1 = P3;
  P3 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfeff;
  uVar1 = P3;
  P3 = uVar1 | 0x200;
  uVar1 = CCM6;
  CCM6 = uVar1 | 0x200;
  uVar1 = DP3;
  DP3 = uVar1 | 0x200;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0xd0;
  uVar1 = SSCTIC;
  SSCTIC = uVar1 | 0x80;
  return;
}


/* ----------------------------------------------------------------------------
 * ssc_send
 * Address: 0xC0FF28
 * Area:    application/01-drivers/ssc
 * Size:    12 bytes
 * -------------------------------------------------------------------------- */
/* c0ff28 ssc_send */

/* Send one SSC byte. */

void ssc_send(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = SSCTIC;
  SSCTIC = uVar1 & 0xff7f;
  SSCTB = (ushort)*(byte *)(uint3)param_1;
  return;
}


/* ----------------------------------------------------------------------------
 * ssc_rx_start
 * Address: 0xC0FFC0
 * Area:    application/01-drivers/ssc
 * Size:    30 bytes
 * -------------------------------------------------------------------------- */
/* c0ffc0 ssc_rx_start */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Start SSC receive engine. */

void ssc_rx_start(void)

{
  ushort uVar1;
  
  uVar1 = P1H;
  P1H = uVar1 & 0xfff7;
  ssc_var_c492 = 7;
  _ssc_var_c494 = SUB32(&ssc_var_c4b8,0);
  _ssc_var_c496 = 0xc4a0;
  ssc_send();
  return;
}


/* ----------------------------------------------------------------------------
 * ssc_rx_queue_init
 * Address: 0xC10200
 * Area:    application/01-drivers/ssc
 * Size:    64 bytes
 * -------------------------------------------------------------------------- */
/* c10200 ssc_rx_queue_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* SSC receive queue initialization. */

void ssc_rx_queue_init(void)

{
  ushort uVar1;
  
  _ssc_var_c4a8 = 0xffff;
  uVar1 = P1H;
  P1H = uVar1 | 8;
  ssc_var_c4be = 0x40;
  ssc_var_c4bd = 0;
  ssc_var_c4bc = 0;
  ssc_var_c4bb = 0x1f;
  ssc_control_flags = 0xfc;
  ssc_var_c4b9 = 0;
  ssc_var_c4b8 = 0;
  ssc_rx_start();
  ssc_var_c4aa = 0;
  ssc_var_c49e = 0;
  ssc_var_c4b4 = 0;
  return;
}


/* ----------------------------------------------------------------------------
 * ssc_task
 * Address: 0xC10342
 * Area:    application/01-drivers/ssc
 * Size:    46 bytes
 * -------------------------------------------------------------------------- */
/* c10342 ssc_task */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Periodic SSC task: start transfer, timeout, sample port. */

void ssc_task(void)

{
  ssc_rx_start();
  if (ssc_timeout == '\0') {
    _ssc_control_flags = _ssc_control_flags | 0x200;
    ssc_rx_start();
    empty_stub_3();
    ssc_timeout = 'P';
  }
  else {
    ssc_timeout = ssc_timeout + -1;
  }
  input_debounce_sample();
  return;
}


/* ============================== Drivers / timers ============================== */

/* ----------------------------------------------------------------------------
 * capcom_timer_init
 * Address: 0xC00CA2
 * Area:    application/01-drivers/timers
 * Size:    146 bytes
 * -------------------------------------------------------------------------- */
/* c00ca2 capcom_timer_init */

/* CAPCOM/T0/T7/T8 timer initialization. */

void capcom_timer_init(char param_1)

{
  ushort uVar1;
  
  T78CON = 0;
  if (param_1 == '\x02') {
    T7 = 0xfbe0;
    T0REL = 0xfbe0;
  }
  else {
    T7 = 0xf060;
    T0REL = 0xf060;
  }
  T8 = 0xffff;
  T8REL = 0;
  CC1IC = 0x58;
  CC16 = 0;
  CC17 = 0;
  CC18 = 0;
  CC19 = 0;
  CC20 = 0;
  CC21 = 0;
  CC22 = 0;
  CC23 = 0;
  CC24 = 0;
  CC25 = 0;
  CC26 = 0;
  CC27 = 0;
  CC28 = 0;
  CC29 = 0;
  CC30 = 0;
  CC31 = 0;
  CCM4 = 0;
  CCM5 = 0;
  CCM6 = 0;
  CCM7 = 0;
  DAT_00ff2a = 0;
  DAT_00fe28 = 0;
  DAT_00fe2a = 0;
  DAT_00ff2c = 0;
  uVar1 = T78CON;
  T78CON = uVar1 | 0x40;
  return;
}


/* ----------------------------------------------------------------------------
 * timer7_isr
 * Address: 0xC00D34
 * Area:    application/01-drivers/timers
 * Size:    118 bytes
 * -------------------------------------------------------------------------- */
/* c00d34 timer7_isr */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Timer7 interrupt: ASC0 state machine + KWP dispatcher, 1 ms tick. */

void timer7_isr(void)

{
  bool bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  
  isr_save_fc40 = &stack0x0000;
  uVar6 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x300;
  uVar7 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP2 = 0x302;
  uVar15 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  uVar9 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  uVar10 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  uVar14 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  uVar13 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar11 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  uVar12 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00f000;
  uVar3 = DAT_00f000;
  uVar3 = DAT_00f000;
  uVar3 = DAT_00f002;
  uVar4 = DAT_00f002;
  uVar4 = DAT_00f002;
  uVar4 = DAT_00f004;
  uVar5 = DAT_00f004;
  uVar5 = DAT_00f004;
  uVar5 = DPP3;
  uVar8 = DPP3;
  uVar8 = DPP3;
  asc0_state_dispatch(uVar5,uVar4,uVar3,uVar2,uVar12,uVar11,uVar13,uVar14,uVar10,uVar9,uVar15,uVar7,
                      uVar6);
  kwp_dispatch();
  bVar1 = 1000 < _timer7_tick;
  _timer7_tick = _timer7_tick + 1;
  if (bVar1) {
    _timer7_tick = 0;
  }
  DAT_00f006 = uVar5;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  DAT_00f004 = uVar4;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  DAT_00f002 = uVar3;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DAT_00ff0a = uVar12;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  DAT_00ff08 = uVar11;
  uVar2 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  DAT_00ffda = uVar13;
  uVar2 = DAT_00ffda;
  uVar2 = DAT_00ffda;
  uVar2 = DAT_00ffda;
  DAT_00ffdc = uVar14;
  uVar2 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  DAT_00fe5e = uVar10;
  uVar2 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  DAT_00fe5c = uVar9;
  uVar2 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  DAT_00ffde = uVar15;
  uVar2 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  DPP2 = uVar7;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar6;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}


/* ----------------------------------------------------------------------------
 * timer4_init
 * Address: 0xC0BDA2
 * Area:    application/01-drivers/timers
 * Size:    38 bytes
 * -------------------------------------------------------------------------- */
/* c0bda2 timer4_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Timer T4 initialization. */

void timer4_init(void)

{
  ushort uVar1;
  
  if (cal_cc22_config == '\x01') {
    T4CON = 5;
    T4 = 0xff83;
    uVar1 = T4IC;
    T4IC = uVar1 | 0x61;
    uVar1 = DAT_00f138;
    DAT_00f138 = uVar1 & 0xfffd;
    uVar1 = DAT_00ff3a;
    DAT_00ff3a = uVar1 & 0xfffd;
    uVar1 = T4CON;
    T4CON = uVar1 | 0x40;
    _ram_var_c3a4 = 0;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * timer6_init
 * Address: 0xC0BF40
 * Area:    application/01-drivers/timers
 * Size:    20 bytes
 * -------------------------------------------------------------------------- */
/* c0bf40 timer6_init */

/* Timer T6 initialization. */

void timer6_init(void)

{
  ushort uVar1;
  
  T6CON = 0x800a;
  T6 = 0xffff;
  CAPREL = 0xffff;
  uVar1 = T6IC;
  T6IC = uVar1 | 0x7a;
  uVar1 = T6CON;
  T6CON = uVar1 | 0x40;
  return;
}


/* ----------------------------------------------------------------------------
 * timer5_init
 * Address: 0xC0CDFA
 * Area:    application/01-drivers/timers
 * Size:    168 bytes
 * -------------------------------------------------------------------------- */
/* c0cdfa timer5_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Timer T5/ASC0 error init. */

void timer5_init(void)

{
  ushort uVar1;
  byte bVar2;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xffbf;
  T5 = 0;
  uVar1 = S0EIC;
  S0EIC = uVar1 & 0xffbf;
  _speed_table_504c = 0x200;
  _speed_table_5038 = 0;
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  bVar2 = 0;
  do {
    uVar1 = (ushort)bVar2;
    bVar2 = bVar2 + 1;
    *(undefined2 *)(uint3)(uVar1 * 2 + 0xc282) = 0;
  } while (bVar2 < 0x18);
  input_status_flags = 0x8100;
  capture_state = 0;
  speed_input_ready = 0;
  capture_var_c277 = 0;
  capture_var_c264 = 0;
  capture_var_c272 = 0;
  uVar1 = input_status_flags;
  input_status_flags = uVar1 & 0xffbf;
  _capture_period_initial = 0xffff;
  _capture_period_a = 0xffff;
  _capture_period_b = 0xffff;
  speed_sample_counter = 0xff;
  _capture_overflow = 0;
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  _capture_callback_1 = 0xc8e2;
  _capture_callback_1_hi = 0xc0;
  _capture_callback_0 = 0xc914;
  _capture_callback_0_hi = 0xc0;
  _capture_enable = _capture_enable | 1;
  _capture_irq_mask = _capture_irq_mask | 2;
  _capture_irq_mask_2 = _capture_irq_mask_2 | 2;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xffbf;
  T5 = 0;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xff7f;
  uVar1 = S0EIC;
  S0EIC = uVar1 | 0x40;
  watchdog_pin();
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


/* ----------------------------------------------------------------------------
 * capcom_start
 * Address: 0xC0CEA2
 * Area:    application/01-drivers/timers
 * Size:    118 bytes
 * -------------------------------------------------------------------------- */
/* c0cea2 capcom_start */

/* Start CAPCOM/T7/T8 time base. */

void capcom_start(void)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = CC19;
  CC19 = uVar2 | 4;
  uVar2 = T78CON;
  T78CON = uVar2 | 5;
  T7 = 0;
  T7REL = 0;
  T8 = 0;
  T1REL = 0;
  bVar1 = 0;
  uVar2 = (ushort)&CC16;
  do {
    bVar1 = bVar1 + 1;
    *(undefined2 *)(uint3)uVar2 = 0;
    uVar2 = uVar2 + 2;
  } while (bVar1 < 0x10);
  CCM4 = 0;
  CCM7 = 0;
  CCM6 = 3;
  DAT_00ff2a = 0;
  DAT_00fe28 = 0;
  DAT_00fe2a = 0;
  DAT_00ff2c = 0;
  uVar2 = S0EIC;
  S0EIC = uVar2 | 0x38;
  uVar2 = T5CON;
  T5CON = uVar2 | 10;
  T5 = 0;
  CAPREL = 0;
  uVar2 = T5IC;
  T5IC = uVar2 | 0x24;
  uVar2 = CC1IC;
  CC1IC = uVar2 | 0x79;
  uVar2 = T5CON;
  T5CON = uVar2 | 0x40;
  uVar2 = T78CON;
  T78CON = uVar2 | 0x40;
  uVar2 = CC14IC;
  CC14IC = uVar2 | 0xcc;
  return;
}


/* ----------------------------------------------------------------------------
 * timer6_start
 * Address: 0xC0FB6E
 * Area:    application/01-drivers/timers
 * Size:    30 bytes
 * -------------------------------------------------------------------------- */
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


/* ----------------------------------------------------------------------------
 * t7_timestamp
 * Address: 0xC1064C
 * Area:    application/01-drivers/timers
 * Size:    40 bytes
 * -------------------------------------------------------------------------- */
/* c1064c t7_timestamp */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns a short T7 timestamp with overflow extension. */

short t7_timestamp(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  uVar1 = T7;
  if ((uVar1 < 0x8001) && (uVar2 = T7IC, (uVar2 & 0x80) != 0)) {
    sVar3 = (uVar1 >> 3) + _t7_offset_short + 0x2000;
  }
  else {
    sVar3 = (uVar1 >> 3) + _t7_offset_short;
  }
  return sVar3;
}


/* ----------------------------------------------------------------------------
 * t7_timestamp_extended
 * Address: 0xC106E6
 * Area:    application/01-drivers/timers
 * Size:    68 bytes
 * -------------------------------------------------------------------------- */
/* c106e6 t7_timestamp_extended */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns a T7 timestamp extended by the T7 overflow flag. */

short t7_timestamp_extended(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  uVar1 = PSW;
  uVar1 = (uVar1 & 0x800) >> 0xb;
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = T7;
  sVar3 = (uVar2 >> 8) + _t7_offset_extended;
  uVar2 = T7IC;
  if ((uVar2 & 0x80) != 0) {
    uVar2 = T7;
    sVar3 = _t7_offset_extended + 0x100 + (uVar2 >> 8);
  }
  if (uVar1 == 1) {
    uVar1 = PSW;
    PSW = uVar1 | 0x800;
  }
  else if (uVar1 == 0) {
    uVar1 = PSW;
    PSW = uVar1 & 0xf7ff;
  }
  return sVar3;
}


/* ----------------------------------------------------------------------------
 * timer8_init
 * Address: 0xC1072A
 * Area:    application/01-drivers/timers
 * Size:    76 bytes
 * -------------------------------------------------------------------------- */
/* c1072a timer8_init */

/* Timer T8/CAPCOM init. */

void timer8_init(void)

{
  ushort uVar1;
  
  uVar1 = T78CON;
  T78CON = uVar1 & 0xff | 0x500;
  T8 = 0;
  T8REL = 0;
  uVar1 = CC2IC;
  CC2IC = uVar1 | 0xe9;
  if ((cal_timer_config == 0) || (cal_timer_config == 4)) {
    CC21 = 0;
    uVar1 = CCM5;
    CCM5 = uVar1 & 0xff8f;
    uVar1 = CCM5;
    CCM5 = uVar1 | 0x30;
    uVar1 = CCM5;
    CCM5 = uVar1 | 0x80;
    uVar1 = CRIC;
    CRIC = uVar1 | 0xe0;
  }
  uVar1 = T78CON;
  T78CON = uVar1 | 0x4000;
  return;
}


/* ============================== Drivers / ADC ============================== */

/* ----------------------------------------------------------------------------
 * adc_start
 * Address: 0xC10370
 * Area:    application/01-drivers/adc
 * Size:    32 bytes
 * -------------------------------------------------------------------------- */
/* c10370 adc_start */

/* Start ADC conversion; selects pin mode from calibration. */

void adc_start(void)

{
  DAT_00ffbe = 0x9000;
  CC14 = 0;
  if (cal_adc_config != 0) {
    P5DIDIS = 0xc47f;
    return;
  }
  P5DIDIS = 0x847f;
  return;
}


/* ----------------------------------------------------------------------------
 * adc_calibrate
 * Address: 0xC105EC
 * Area:    application/01-drivers/adc
 * Size:    44 bytes
 * -------------------------------------------------------------------------- */
/* c105ec adc_calibrate */

/* ADC calibration/start. */

void adc_calibrate(void)

{
  ushort uVar1;
  
  can_bus_config();
  uVar1 = DAT_00ffbe;
  DAT_00ffbe = uVar1 & 0xbfff;
  do {
    uVar1 = DAT_00f110;
  } while ((uVar1 & 0x8000) == 0);
  DAT_00f110 = 0;
  DAT_00f0d2 = 0xfc31;
  DAT_00f0d0 = 0xfc31;
  uVar1 = ADCON;
  ADCON = uVar1 | 0x54;
  DAT_00f10c = 1;
  uVar1 = PSW;
  PSW = uVar1 | 1;
  return;
}


/* ============================== Drivers / IO ============================== */

/* ----------------------------------------------------------------------------
 * p1l1_set
 * Address: 0xC0BD54
 * Area:    application/01-drivers/io
 * Size:    4 bytes
 * -------------------------------------------------------------------------- */
/* c0bd54 p1l1_set */

/* Sets port P1L.1. */

void p1l1_set(void)

{
  ushort uVar1;
  
  uVar1 = P1L;
  P1L = uVar1 | 2;
  return;
}


/* ----------------------------------------------------------------------------
 * watchdog_pin
 * Address: 0xC0CAC2
 * Area:    application/01-drivers/io
 * Size:    24 bytes
 * -------------------------------------------------------------------------- */
/* c0cac2 watchdog_pin */

/* Watchdog/port pin control. */

void watchdog_pin(void)

{
  ushort uVar1;
  
  uVar1 = input_status;
  if (((uVar1 & 1) == 0) && (uVar1 = input_status, (uVar1 & 2) == 0)) {
    uVar1 = input_status_flags;
    input_status_flags = uVar1 & 0xffdf;
    return;
  }
  uVar1 = input_status_flags;
  input_status_flags = uVar1 | 0x20;
  return;
}


/* ----------------------------------------------------------------------------
 * input_debounce_sample
 * Address: 0xC10242
 * Area:    application/01-drivers/io
 * Size:    154 bytes
 * -------------------------------------------------------------------------- */
/* c10242 input_debounce_sample */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Samples P1L pins and updates input_state_bits/input_low_bits/input_high_bits. */

void input_debounce_sample(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = 1;
  do {
    __service_watchdog();
    if ((uVar2 & _input_state_bits) == 0) {
      _input_low_bits = _input_low_bits | uVar2;
    }
    else {
      _input_high_bits = _input_high_bits | uVar2;
    }
    if (uVar2 == 8) {
      uVar1 = P1L;
      if ((uVar1 & 0x40) == 0) {
        _input_state_bits = _input_state_bits & 0xfff7;
      }
      else {
        _input_state_bits = _input_state_bits | 8;
      }
    }
    else if (uVar2 == 0x80) {
      uVar1 = P1L;
      if ((uVar1 & 1) == 0) {
        _input_state_bits = _input_state_bits & 0xff7f;
      }
      else {
        _input_state_bits = _input_state_bits | 0x80;
      }
    }
    else if (uVar2 == 0x20) {
      uVar1 = P1L;
      if ((uVar1 & 4) == 0) {
        _input_state_bits = _input_state_bits & 0xffdf;
      }
      else {
        _input_state_bits = _input_state_bits | 0x20;
      }
    }
    else if (uVar2 == 0x10) {
      uVar1 = P1L;
      if ((uVar1 & 0x20) == 0) {
        _input_state_bits = _input_state_bits & 0xffef;
      }
      else {
        _input_state_bits = _input_state_bits | 0x10;
      }
    }
    uVar2 = uVar2 * 2;
  } while (uVar2 < 0x81);
  return;
}


/* ----------------------------------------------------------------------------
 * port_bus_init
 * Address: 0xC103C0
 * Area:    application/01-drivers/io
 * Size:    260 bytes
 * -------------------------------------------------------------------------- */
/* c103c0 port_bus_init */

/* Application port and external-bus initialization. */

void port_bus_init(void)

{
  ushort uVar1;
  
  P3 = 0x80;
  P0H = 0;
  DAT_00f082 = 0;
  P0H = 0;
  P0L = 0;
  DAT_00f080 = 0;
  P0L = 0;
  P1H = 4;
  DAT_00f120 = 0;
  DAT_00f086 = 0;
  P1H = 0x2e;
  P1L = 0;
  DAT_00f130 = 0;
  DAT_00f084 = 0;
  DP1L = 0x71;
  uVar1 = P1L;
  P1L = uVar1 | 10;
  uVar1 = DP1L;
  DP1L = uVar1 | 0x40;
  DP3 = 0;
  P3 = 0;
  DAT_00f126 = 0;
  DAT_00f128 = 0;
  CC5 = 0;
  DP3 = 0x8040;
  DP4 = 0;
  P4 = 0;
  DAT_00f12a = 0;
  DAT_00f136 = 0;
  CC6 = 0;
  DP4 = 0;
  BUSCON4 = 0;
  BUSCON2 = 0;
  DAT_00f138 = 0;
  DAT_00f13a = 3;
  CC10 = 0;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 & 0xffdf;
  BUSCON3 = 0;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 0x10;
  DAT_00ffb4 = 0;
  DAT_00feaa = 0;
  DAT_00ffb6 = 0;
  uVar1 = P5;
  if ((uVar1 & 0x80) == 0) {
    CC1 = 0x3333;
    P0H = 0;
    DP0H = 0xff;
    CC0 = 0x3333;
    P0L = 0;
    P0L = 0xff;
    uVar1 = P1H;
    P1H = uVar1 & 0x3f;
    uVar1 = P1H;
    P1H = uVar1 | 0xc0;
    uVar1 = P3;
    P3 = uVar1 & 0x6fff;
    uVar1 = DP3;
    DP3 = uVar1 | 0x9000;
    CC6 = 0x3333;
    P4 = 0;
    DP4 = 0xff;
    DAT_00feaa = 0x3333;
    DAT_00ffb4 = 0;
    DAT_00ffb6 = 0xffff;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * capture_control
 * Address: 0xC13F6C
 * Area:    application/01-drivers/io
 * Size:    24 bytes
 * -------------------------------------------------------------------------- */
/* c13f6c capture_control */

/* Capture input control. */

void capture_control(void)

{
  ushort uVar1;
  
  uVar1 = capture_status_1;
  if (((uVar1 & 4) == 0) && (cal_capture_config == 0)) {
    uVar1 = capture_input_select;
    capture_input_select = uVar1 | 0x20;
  }
  uVar1 = capture_status_0;
  if ((uVar1 & 4) == 0) {
    uVar1 = capture_input_select;
    capture_input_select = uVar1 | 0x10;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * capture_input_select
 * Address: 0xC13F9A
 * Area:    application/01-drivers/io
 * Size:    24 bytes
 * -------------------------------------------------------------------------- */
/* c13f9a capture_input_select */

/* Writes the low bits of 0xFD1A (capture input selection). */

void capture_input_select(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = capture_input_select;
  capture_input_select = uVar1 & 0xfc | param_1 & 0xff;
  return;
}


/* ----------------------------------------------------------------------------
 * capture_init
 * Address: 0xC14298
 * Area:    application/01-drivers/io
 * Size:    12 bytes
 * -------------------------------------------------------------------------- */
/* c14298 capture_init */

/* Capture input initialization. */

void capture_init(void)

{
  capture_control();
  capture_input_select(0);
  return;
}


/* ----------------------------------------------------------------------------
 * input_latch
 * Address: 0xC14714
 * Area:    application/01-drivers/io
 * Size:    36 bytes
 * -------------------------------------------------------------------------- */
/* c14714 input_latch */

/* Latch input port bits into 0xFD1C. */

void input_latch(void)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar1 = input_status;
  uVar2 = status_flag_fd1c;
  uVar3 = status_flag_fd1c;
  status_flag_fd1c = uVar3 & 0xfffe | uVar1 >> 2 & 1;
  uVar1 = input_status;
  uVar2 = status_flag_fd1c;
  uVar3 = status_flag_fd1c;
  status_flag_fd1c = uVar3 & 0xfffd | (uVar1 >> 1 & 1) << 1;
  uVar1 = input_status;
  uVar2 = status_flag_fd1c;
  uVar3 = status_flag_fd1c;
  status_flag_fd1c = uVar3 & 0xfffb | (uVar1 & 1) << 2;
  return;
}


/* ============================== Drivers / PWM ============================== */

/* ----------------------------------------------------------------------------
 * pwm_init
 * Address: 0xC108CE
 * Area:    application/01-drivers/pwm
 * Size:    160 bytes
 * -------------------------------------------------------------------------- */
/* c108ce pwm_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* PWM/CAPCOM6 initialization. */

void pwm_init(void)

{
  ushort uVar1;
  
  _pwm_period = 0xf423;
  _pwm_cfg_ac = 0x805;
  _pwm_cfg_ae = 0x20;
  _pwm_cfg_a0 = 0x5780;
  _pwm_duty = 0x4b00;
  _pwm_cfg_a4 = 0;
  _pwm_cfg_94 = 1;
  _pwm_cfg_c6 = 0x110;
  _pwm_cfg_a8 = 0;
  _pwm_cfg_c4 = 0;
  _pwm_cfg_c0 = 0x8014;
  _pwm_cfg_ca = 0;
  _pwm_cfg_ce = 0;
  _pwm_cfg_c2 = 0;
  uVar1 = CC19IC;
  CC19IC = uVar1 | 0x5c;
  uVar1 = CC20IC;
  CC20IC = uVar1 | 0x5d;
  uVar1 = T4IC;
  T4IC = uVar1 | 0x5e;
  if (cal_pwm_config == '\x02') {
    uVar1 = PWMCON0;
    PWMCON0 = uVar1 | 0x10;
    uVar1 = P1L;
    P1L = uVar1 & 0xffef | 0x10;
    uVar1 = DP1L;
    DP1L = uVar1 & 0xffef | 0x10;
  }
  _pwm_control = 0x202;
  return;
}


/* ----------------------------------------------------------------------------
 * pwm_period_duty_calc
 * Address: 0xC10A74
 * Area:    application/01-drivers/pwm
 * Size:    106 bytes
 * -------------------------------------------------------------------------- */
/* c10a74 pwm_period_duty_calc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Computes PWM period/duty from the 32-bit division result. */

void pwm_period_duty_calc(undefined2 param_1,undefined2 param_2)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  
  uVar2 = _pwm_cfg_ac & 0xf;
  uVar3 = 0x4800;
  sVar4 = 0x1e8;
  while (bVar1 = uVar2 != 0, uVar2 = uVar2 - 1, bVar1) {
    uVar3 = uVar3 >> 1 | sVar4 << 0xf;
    sVar4 = sVar4 >> 1;
  }
  _pwm_divisor = div32_checked(uVar3,sVar4,param_1);
  _pwm_duty_calc = mul_div32(_pwm_divisor,0,param_2);
  if (_pwm_divisor == _pwm_duty_calc) {
    _pwm_duty_calc = _pwm_duty_calc + 1;
  }
  _pwm_period = _pwm_divisor;
  _pwm_duty = _pwm_duty_calc;
  _pwm_control = _pwm_control | 0x40;
  return;
}


/* ----------------------------------------------------------------------------
 * pwm_output_enable
 * Address: 0xC10AFC
 * Area:    application/01-drivers/pwm
 * Size:    16 bytes
 * -------------------------------------------------------------------------- */
/* c10afc pwm_output_enable */

/* Enables the PWM output (PWMCON0 and P1L.4). */

void pwm_output_enable(void)

{
  ushort uVar1;
  
  __atomic(4);
  uVar1 = PWMCON0;
  PWMCON0 = uVar1 | 4;
  uVar1 = P1L;
  P1L = uVar1 | 4;
  __atomic(4);
  uVar1 = P1L;
  P1L = uVar1 | 4;
  return;
}


/* ============================== Drivers / clock ============================== */

/* ----------------------------------------------------------------------------
 * pll_isr
 * Address: 0xC01048
 * Area:    application/01-drivers/clock
 * Size:    56 bytes
 * -------------------------------------------------------------------------- */
/* c01048 pll_isr */

/* PLL/oscillator watchdog interrupt; performs software reset. */

void pll_isr(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  
  uVar12 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar6 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar7 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar11 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar10 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar8 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar9 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DPP3;
  uVar5 = DPP3;
  uVar5 = DPP3;
  __software_reset();
  DAT_00f006 = uVar4;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  DAT_00f004 = uVar3;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  DAT_00f002 = uVar2;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DAT_00ff0a = uVar9;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  DAT_00ff08 = uVar8;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  DAT_00ffda = uVar10;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  DAT_00ffdc = uVar11;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  DAT_00fe5e = uVar7;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  DAT_00fe5c = uVar6;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  DAT_00ffde = uVar12;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  return;
}


/* ----------------------------------------------------------------------------
 * clock_init
 * Address: 0xC01080
 * Area:    application/01-drivers/clock
 * Size:    176 bytes
 * -------------------------------------------------------------------------- */
/* c01080 clock_init */

/* Clock/PLL and port initialization. */

void clock_init(void)

{
  ushort uVar1;
  
  P3 = 0;
  P0H = 0;
  DAT_00f082 = 0;
  P0H = 0;
  P0L = 0;
  DAT_00f080 = 0;
  P0L = 0;
  P1H = 8;
  DAT_00f120 = 0;
  DAT_00f086 = 0;
  P1H = 0x2e;
  P1L = 0;
  DAT_00f130 = 0;
  DAT_00f084 = 0;
  DP1L = 0x71;
  uVar1 = P1L;
  P1L = uVar1 | 10;
  uVar1 = DP1L;
  DP1L = uVar1 | 0x40;
  DP3 = 0;
  P3 = 0;
  DAT_00f126 = 0;
  DAT_00f128 = 0;
  CC5 = 0;
  DP3 = 0x2240;
  DP4 = 0;
  P4 = 0;
  DAT_00f12a = 0;
  DAT_00f136 = 0;
  CC6 = 0;
  DP4 = 0;
  BUSCON4 = 0;
  BUSCON2 = 0;
  DAT_00f138 = 0;
  DAT_00f13a = 3;
  CC10 = 0;
  BUSCON3 = 0x10;
  DAT_00ffb4 = 0;
  DAT_00feaa = 0;
  DAT_00ffb6 = 0;
  return;
}


/* ============================== Diagnostics / KWP2000 ============================== */

/* ----------------------------------------------------------------------------
 * kwp_dispatch
 * Address: 0xC01482
 * Area:    application/02-diagnostics/kwp
 * Size:    154 bytes
 * -------------------------------------------------------------------------- */
/* c01482 kwp_dispatch */

/* KWP2000 service dispatcher (0x10/0x23/0x27/0x31/0x34/0x36/0x38/0x3D/0x83). */

void kwp_dispatch(void)

{
  if (kwp_request_pending == '\x01') {
    if (kwp_request == -0x7f) {
      kwp_sid81();
    }
    else if (ram_var_c148 == '\x10') {
      kwp_sid10_session();
    }
    else if (ram_var_c148 == -0x7d) {
      kwp_sid83();
    }
    else if (ram_var_c148 == '#') {
      kwp_sid23_read_mem();
    }
    else if (ram_var_c148 == '\'') {
      kwp_sid27_security();
    }
    else if (ram_var_c148 == '1') {
      kwp_sid31_routine();
    }
    else if (ram_var_c148 == '4') {
      kwp_sid34_download();
    }
    else if (ram_var_c148 == '6') {
      kwp_sid36_transfer();
    }
    else if (ram_var_c148 == '8') {
      kwp_sid38();
    }
    else if (ram_var_c148 == '=') {
      kwp_sid3D_write_mem();
    }
    else {
      kwp_negative();
    }
    kwp_request_pending = '\0';
    kline_frame_flag = 1;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * kwp_sid81
 * Address: 0xC0151C
 * Area:    application/02-diagnostics/kwp
 * Size:    40 bytes
 * -------------------------------------------------------------------------- */
/* c0151c kwp_sid81 */

/* KWP service 0x81 handler (start communication). */

void kwp_sid81(void)

{
  kline_response_frame = 0x80;
  kline_response_length = 3;
  kline_response_payload = 0xc1;
  kline_response_payload_1 = 0xef;
  kline_response_payload_2 = 0x8f;
  return;
}


/* ----------------------------------------------------------------------------
 * kwp_sid27_security
 * Address: 0xC01544
 * Area:    application/02-diagnostics/kwp
 * Size:    150 bytes
 * -------------------------------------------------------------------------- */
/* c01544 kwp_sid27_security */

/* KWP service 0x27 security access; fixed seed 0x1234, key 0x8474. */

void kwp_sid27_security(void)

{
  if (ram_var_c149 == '\x01') {
    kline_response_frame = 0x80;
    kline_response_length = 4;
    kline_response_payload = 0x67;
    kline_response_payload_1 = 1;
    kline_response_payload_2 = 0x12;
    kline_response_payload_3 = 0x34;
    return;
  }
  if (ram_var_c149 == '\x02') {
    kline_response_length = 3;
    kline_response_frame = 0x80;
    if ((kwp_request_addr_hi == -0x7c) && (kwp_request_addr_mid == 't')) {
      security_unlocked = 1;
      kline_response_payload = 0x67;
      kline_response_payload_1 = 2;
      kline_response_payload_2 = 0x34;
      return;
    }
    kline_response_payload = 0x7f;
    kline_response_payload_1 = 0x27;
    kline_response_payload_2 = 0x35;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * kwp_negative
 * Address: 0xC015DA
 * Area:    application/02-diagnostics/kwp
 * Size:    30 bytes
 * -------------------------------------------------------------------------- */
/* c015da kwp_negative */

/* KWP negative response / unsupported service. */

void kwp_negative(void)

{
  kline_response_length = 3;
  kline_response_payload = 0x7f;
  kline_response_payload_1 = 0x10;
  kline_response_payload_2 = 1;
  return;
}


/* ----------------------------------------------------------------------------
 * kwp_sid10_session
 * Address: 0xC015F8
 * Area:    application/02-diagnostics/kwp
 * Size:    114 bytes
 * -------------------------------------------------------------------------- */
/* c015f8 kwp_sid10_session */

/* KWP service 0x10 start diagnostic session. */

void kwp_sid10_session(void)

{
  if (ram_var_c149 == -0x7f) {
    kline_response_length = 2;
    kline_response_payload = 0x50;
    kline_response_payload_1 = 0x81;
  }
  else if (ram_var_c149 == -0x7b) {
    if (security_unlocked == '\x01') {
      kline_response_length = 2;
      kline_response_payload = 0x50;
      kline_response_payload_1 = 0x85;
    }
    else {
      kline_response_length = 3;
      kline_response_payload = 0x7f;
      kline_response_payload_1 = 0x10;
      kline_response_payload_2 = 0x85;
    }
  }
  kline_response_frame = 0x80;
  return;
}


/* ----------------------------------------------------------------------------
 * kwp_sid83
 * Address: 0xC0166A
 * Area:    application/02-diagnostics/kwp
 * Size:    88 bytes
 * -------------------------------------------------------------------------- */
/* c0166a kwp_sid83 */

/* KWP service 0x83 handler (Delphi-specific). */

void kwp_sid83(void)

{
  if (ram_var_c149 == '\0') {
    kline_response_frame = 0x87;
    kline_response_length = 7;
    kline_response_payload = 0xc3;
    kline_response_payload_1 = 0;
    kline_response_payload_2 = 0;
    kline_response_payload_3 = 0xff;
    kline_response_payload_4 = 0;
    kline_response_payload_5 = 0xff;
    kline_response_payload_6 = 0;
  }
  else if (ram_var_c149 == '\x03') {
    kline_response_frame = 0x82;
    kline_response_length = 2;
    kline_response_payload = 0xc3;
    kline_response_payload_1 = 3;
    return;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * kwp_sid34_download
 * Address: 0xC016C2
 * Area:    application/02-diagnostics/kwp
 * Size:    72 bytes
 * -------------------------------------------------------------------------- */
/* c016c2 kwp_sid34_download */

/* KWP service 0x34 request download. */

void kwp_sid34_download(void)

{
  if (security_unlocked != '\x01') {
    kline_response_length = 3;
    kline_response_payload = 0x7f;
    kline_response_payload_1 = 0x10;
    kline_response_payload_2 = 0x33;
    return;
  }
  kline_response_frame = 0x82;
  kline_response_length = 2;
  kline_response_payload = 0x74;
  kline_response_payload_1 = 0xfb;
  return;
}


/* ----------------------------------------------------------------------------
 * kwp_sid36_transfer
 * Address: 0xC0170A
 * Area:    application/02-diagnostics/kwp
 * Size:    158 bytes
 * -------------------------------------------------------------------------- */
/* c0170a kwp_sid36_transfer */

/* KWP service 0x36 transfer data (0x80-byte blocks to flash/RAM). */

void kwp_sid36_transfer(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  if (security_unlocked == '\x01') {
    uVar3 = (ushort)ram_var_c149;
    uVar4 = (ushort)kwp_request_addr_hi;
    uVar5 = (ushort)kwp_request_addr_mid;
    uVar1 = uVar4 * 0x100 + uVar5;
    kline_response_payload_1 = '\0';
    uVar6 = 0;
    uVar7 = uVar1 & 0x3fff;
    do {
      uVar2 = (short)&kwp_request_addr_lo + uVar6;
      *(undefined1 *)
       ((uint3)uVar7 +
       (uint3)((((ushort)CARRY2(uVar3 * 0x100,uVar4) * 0x100 | uVar3 * 0x100 + uVar4 >> 8) +
               (ushort)CARRY2(uVar4 * 0x100,uVar5)) * 4 | uVar1 >> 0xe) * 0x4000) =
           *(undefined1 *)(uint3)uVar2;
      kline_response_payload_1 = kline_response_payload_1 + *(char *)(uint3)uVar2;
      uVar6 = uVar6 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar6 < 0x80);
    kline_response_length = 2;
    kline_response_payload = 0x76;
    return;
  }
  kline_response_length = 3;
  kline_response_payload = 0x7f;
  kline_response_payload_1 = 0x36;
  kline_response_payload_2 = 0xbd;
  return;
}


/* ----------------------------------------------------------------------------
 * kwp_sid31_routine
 * Address: 0xC017A8
 * Area:    application/02-diagnostics/kwp
 * Size:    66 bytes
 * -------------------------------------------------------------------------- */
/* c017a8 kwp_sid31_routine */

/* KWP service 0x31 start routine. */

void kwp_sid31_routine(void)

{
  if (security_unlocked != '\x01') {
    kline_response_length = 3;
    kline_response_payload = 0x7f;
    kline_response_payload_1 = 0x31;
    kline_response_payload_2 = 0xbd;
    return;
  }
  kwp_routine_active = 1;
  kline_response_length = 2;
  kline_response_payload = 0x71;
  kline_response_payload_1 = 2;
  return;
}


/* ----------------------------------------------------------------------------
 * kwp_sid38
 * Address: 0xC017EA
 * Area:    application/02-diagnostics/kwp
 * Size:    86 bytes
 * -------------------------------------------------------------------------- */
/* c017ea kwp_sid38 */

/* KWP service 0x38 handler. */

void kwp_sid38(void)

{
  if (security_unlocked != '\x01') {
    kline_response_length = 3;
    kline_response_payload = 0x7f;
    kline_response_payload_1 = 0x31;
    kline_response_payload_2 = 0xbd;
    return;
  }
  kwp_routine_active = 1;
  kline_response_length = 4;
  kline_response_payload = 0x78;
  kline_response_payload_1 = ram_var_c149;
  kline_response_payload_2 = kwp_request_addr_hi;
  kline_response_payload_3 = kwp_request_addr_mid;
  return;
}


/* ----------------------------------------------------------------------------
 * kwp_sid23_read_mem
 * Address: 0xC01840
 * Area:    application/02-diagnostics/kwp
 * Size:    204 bytes
 * -------------------------------------------------------------------------- */
/* c01840 kwp_sid23_read_mem */

/* KWP service 0x23 read memory by address. */

short kwp_sid23_read_mem(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint3 uVar5;
  byte bVar6;
  short sVar7;
  ushort uVar8;
  ushort uVar9;
  
  bVar6 = kwp_request_addr_lo;
  uVar3 = (ushort)kwp_request_addr_lo;
  uVar4 = (ushort)kwp_request_addr_hi;
  uVar1 = uVar4 * 0x100 + (ushort)kwp_request_addr_mid;
  uVar4 = ((ushort)CARRY2((ushort)ram_var_c149 * 0x100,uVar4) * 0x100 |
          (ushort)ram_var_c149 * 0x100 + uVar4 >> 8) +
          (ushort)CARRY2(uVar4 * 0x100,(ushort)kwp_request_addr_mid);
  uVar9 = uVar1 & 0x3fff;
  sVar7 = (short)&T2CON + uVar4;
  if ((((0xbf < uVar4) &&
       (sVar7 = 0, uVar8 = uVar4 + CARRY2(uVar1,uVar3),
       uVar8 == 0xc4 && uVar1 + uVar3 == 0 || uVar8 < 0xc4)) ||
      ((0xdf < uVar4 &&
       (uVar8 = uVar1 + uVar3, uVar2 = uVar4 + CARRY2(uVar1,uVar3),
       (short)&T78CON + uVar2 == (ushort)(uVar8 < 0x1800) && uVar8 == 0x1800 ||
       (uVar2 < 0xe0 || uVar2 == 0xe0 && uVar8 < 0x1800))))) && (uVar3 < 0x81)) {
    for (uVar8 = 1; uVar8 <= uVar3; uVar8 = uVar8 + 1) {
      uVar5 = (uint3)uVar9;
      uVar9 = uVar9 + 1;
      *(undefined1 *)(uint3)((short)&kline_response_payload + uVar8) =
           *(undefined1 *)(uVar5 + (uint3)(uVar4 * 4 | uVar1 >> 0xe) * 0x4000);
    }
    kline_response_length = bVar6 + 1;
    kline_response_payload = 99;
    return sVar7;
  }
  kline_response_length = 3;
  kline_response_payload = 0x7f;
  kline_response_payload_1 = 0x23;
  kline_response_payload_2 = 0x12;
  return CONCAT11((char)((ushort)sVar7 >> 8),0x12);
}


/* ----------------------------------------------------------------------------
 * kwp_sid3D_write_mem
 * Address: 0xC0190C
 * Area:    application/02-diagnostics/kwp
 * Size:    200 bytes
 * -------------------------------------------------------------------------- */
/* c0190c kwp_sid3D_write_mem */

/* KWP service 0x3D write memory by address. */

void kwp_sid3D_write_mem(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar2 = (ushort)kwp_request_addr_lo;
  uVar3 = (ushort)kwp_request_addr_hi;
  uVar1 = uVar3 * 0x100 + (ushort)kwp_request_addr_mid;
  uVar3 = ((ushort)CARRY2((ushort)ram_var_c149 * 0x100,uVar3) * 0x100 |
          (ushort)ram_var_c149 * 0x100 + uVar3 >> 8) +
          (ushort)CARRY2(uVar3 * 0x100,(ushort)kwp_request_addr_mid);
  if (((0xdf < uVar3) &&
      (uVar4 = uVar1 + uVar2, uVar5 = uVar3 + CARRY2(uVar1,uVar2),
      (short)&T78CON + uVar5 == (ushort)(uVar4 < 0x1800) && uVar4 == 0x1800 ||
      (uVar5 < 0xe0 || uVar5 == 0xe0 && uVar4 < 0x1800))) && (uVar2 < 0x81)) {
    uVar5 = uVar1 & 0x3fff;
    for (uVar4 = 1; uVar4 <= uVar2; uVar4 = uVar4 + 1) {
      *(undefined1 *)((uint3)uVar5 + (uint3)(uVar3 * 4 | uVar1 >> 0xe) * 0x4000) =
           *(undefined1 *)(uint3)((short)&kwp_request_addr_lo + uVar4);
      uVar5 = uVar5 + 1;
    }
    kline_response_length = 4;
    kline_response_payload = 0x7d;
    kline_response_payload_1 = ram_var_c149;
    kline_response_payload_2 = kwp_request_addr_hi;
    kline_response_payload_3 = kwp_request_addr_mid;
    return;
  }
  kline_response_length = 3;
  kline_response_payload = 0x7f;
  kline_response_payload_1 = 0x3d;
  kline_response_payload_2 = 0x12;
  return;
}


/* ============================== Diagnostics / K-line transport ============================== */

/* ----------------------------------------------------------------------------
 * kline_receive_pattern
 * Address: 0xC01212
 * Area:    application/02-diagnostics/kline-transport
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c01212 kline_receive_pattern */

/* Receives the 5-byte K-line wake-up pattern and advances state. */

void kline_receive_pattern(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 uVar3;
  
  while( true ) {
    uVar1 = S0RIC;
    if ((uVar1 & 0x80) == 0) {
      return;
    }
    uVar3 = asc0_read_rx_clear();
    uVar2 = (ushort)kline_rx_index;
    uVar1 = (short)&kline_rx_buffer + uVar2;
    *(undefined1 *)(uint3)uVar1 = uVar3;
    if (*(char *)(uint3)uVar1 != *(char *)(uint3)((short)&kline_wakeup_pattern + uVar2)) break;
    if (kline_rx_index == 4) {
      kline_state_machine = kline_state_machine + '\x01';
      kwp_request_pending = 1;
      kline_receive_pattern();
      return;
    }
    kline_rx_index = kline_rx_index + 1;
  }
  kline_state_machine = 1;
  kline_receive_pattern();
  return;
}


/* ----------------------------------------------------------------------------
 * kline_get_status
 * Address: 0xC12696
 * Area:    application/02-diagnostics/kline-transport
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c12696 kline_get_status */

/* Returns the K-line status byte 0xC56D. */

undefined1 kline_get_status(void)

{
  return kline_status;
}


/* ----------------------------------------------------------------------------
 * kline_start_timeout
 * Address: 0xC126B0
 * Area:    application/02-diagnostics/kline-transport
 * Size:    10 bytes
 * -------------------------------------------------------------------------- */
/* c126b0 kline_start_timeout */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Loads the K-line timeout 0xC56A with 0x0500. */

void kline_start_timeout(void)

{
  _kline_timeout = 0x500;
  return;
}


/* ----------------------------------------------------------------------------
 * kline_state_reset
 * Address: 0xC126BC
 * Area:    application/02-diagnostics/kline-transport
 * Size:    22 bytes
 * -------------------------------------------------------------------------- */
/* c126bc kline_state_reset */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clears K-line state to 0. */

void kline_state_reset(undefined1 param_1)

{
  ushort uVar1;
  
  kline_mode = param_1;
  kline_flag_c57d = 0;
  uVar1 = S0CON;
  S0CON = uVar1 & 0xffef;
  kline_flag_c588 = 0;
  _kline_state = 0;
  return;
}


/* ----------------------------------------------------------------------------
 * kline_prepare_frame
 * Address: 0xC126DA
 * Area:    application/02-diagnostics/kline-transport
 * Size:    200 bytes
 * -------------------------------------------------------------------------- */
/* c126da kline_prepare_frame */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Computes K-line timing fields and enters state 6. */

void kline_prepare_frame(undefined1 param_1)

{
  ushort uVar1;
  
  kline_flag_c5a9 = param_1;
  _kline_var_c59e = 0;
  if (kline_var_c5a0 != '\0') {
    _kline_var_c5a6 = (short)(kline_var_c599 + 0xf) >> 4;
    uVar1 = (ushort)kline_var_c57f;
    if (0xf0 < uVar1) {
      uVar1 = uVar1 * 0x100 + 0x1000;
    }
    _kline_var_c59c = (uVar1 << 5) / 10;
    kline_var_c5a5 = kline_var_c57f;
    kline_var_c57e = kline_var_c598;
    kline_var_c5a8 = kline_var_c580;
    kline_var_c577 = kline_var_c592;
    _kline_var_c5bc = (short)(kline_var_c598 + 0xf) >> 4;
    kline_var_c57c = kline_var_c599;
    if (kline_var_c580 == 0xff) {
      _kline_var_c5b4 = -1;
    }
    else {
      _kline_var_c5b4 = (ushort)kline_var_c580 << 5;
    }
    _kline_var_c586 = (short)(kline_var_c592 + 0xf) >> 4;
    kline_var_c5a0 = '\0';
  }
  _kline_state = 6;
  kline_var_c58c = 0;
  kline_var_c56f = 0;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x10;
  return;
}


/* ----------------------------------------------------------------------------
 * kline_rx_state_7
 * Address: 0xC12826
 * Area:    application/02-diagnostics/kline-transport
 * Size:    34 bytes
 * -------------------------------------------------------------------------- */
/* c12826 kline_rx_state_7 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line receive/transport state 7. */

void kline_rx_state_7(void)

{
  if (_kline_flag_c5a2 == 1) {
    _kline_var_c5be = 0;
  }
  if (_kline_flag_c5a2 == 0) {
    _kline_var_c5b0 = 0;
  }
  _kline_var_c574 = 0;
  _kline_state = 7;
  return;
}


/* ----------------------------------------------------------------------------
 * kline_rx_state_8
 * Address: 0xC12848
 * Area:    application/02-diagnostics/kline-transport
 * Size:    14 bytes
 * -------------------------------------------------------------------------- */
/* c12848 kline_rx_state_8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line receive/transport state 8. */

void kline_rx_state_8(void)

{
  _kline_state = 8;
  _kline_var_c5ba = 2;
  return;
}


/* ----------------------------------------------------------------------------
 * kline_push_rx_byte
 * Address: 0xC1293C
 * Area:    application/02-diagnostics/kline-transport
 * Size:    50 bytes
 * -------------------------------------------------------------------------- */
/* c1293c kline_push_rx_byte */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Stores a received K-line byte into the IRAM ring at 0xF600. */

void kline_push_rx_byte(undefined1 param_1)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = (ushort)kline_var_c58c;
  kline_var_c58c = kline_var_c58c + 1;
  *(undefined1 *)(uint3)((short)&kline_rx_ring + uVar1) = param_1;
  if ((_kline_state == 6) && (cVar2 = kline_rx_ring, cVar2 != '\0')) {
    kline_rx_state_7();
  }
  if (kline_var_c58c == '=') {
    kline_var_c58c = '\0';
  }
  return;
}


/* ----------------------------------------------------------------------------
 * kline_transport_task
 * Address: 0xC12982
 * Area:    application/02-diagnostics/kline-transport
 * Size:    324 bytes
 * -------------------------------------------------------------------------- */
/* c12982 kline_transport_task */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* K-line transport state machine; state 0xC584 selects a handler table at 0x7164. */

void kline_transport_task(short param_1,undefined2 param_2)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  
  if (param_1 == 0) {
    kline_state_reset(6);
    uVar1 = S0CON;
    S0CON = uVar1 & 0xffef;
    kline_start_timeout();
    kline_var_c5ab = '\0';
    kline_var_c568 = '\0';
    empty_stub_2();
    store32();
    test_command_clear();
  }
  else if (param_1 == 1) {
    if (_kline_state < 0x10) {
                    /* WARNING: Could not emulate address calculation at 0xc129d2 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((short)&kline_handler_table + _kline_state * 2 & 0x3fff) |
                0xc10000))();
      return;
    }
    if (_kline_timeout != 0) {
      _kline_timeout = _kline_timeout + -1;
    }
    if ((_kline_state != 0xd) && (_kline_state != 10)) {
      if (kline_var_c5ab != '\0') {
        uVar1 = PSW;
        PSW = uVar1 & 0xf7ff;
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      param_2 = 0;
    }
    if (kline_flag_c57d == '\0') {
      kline_var_c568 = '\0';
    }
    else if (kline_var_c568 == '\0') {
      kline_var_c568 = '\x01';
      empty_stub_1(param_2);
    }
    if ((((kline_var_c5b6 == '\0') && (cVar3 = kline_get_status(), cVar3 == '\0')) ||
        (_kline_state == 0xd)) || (_kline_state == 10)) {
      if (_kline_state == 9) {
        bVar2 = false;
        for (kline_var_c56c = 0; kline_var_c56c <= kline_table_count;
            kline_var_c56c = kline_var_c56c + 1) {
          if (*(char *)(uint3)((ushort)kline_var_c56c * 10 + 0x70c2) ==
              *(char *)(uint3)((short)&UNK_00f63d + (ushort)kline_var_c5c4)) {
            empty_stub_0();
            bVar2 = true;
            break;
          }
        }
        if (!bVar2) {
          empty_stub_0();
        }
      }
    }
    else {
      empty_stub_0();
    }
  }
  return;
}


/* ============================== Diagnostics / CAN transport ============================== */

/* ----------------------------------------------------------------------------
 * can_diag_object_init
 * Address: 0xC019D6
 * Area:    application/02-diagnostics/can-transport
 * Size:    70 bytes
 * -------------------------------------------------------------------------- */
/* c019d6 can_diag_object_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initializes TwinCAN message objects 9/10 with IDs 0x7EE/0x7EF. */

void can_diag_object_init(void)

{
  _DAT_20044a = 0x1fb8;
  _DAT_200450 = 0x5599;
  _DAT_20044c = 0xffff;
  _DAT_20042a = 0x1fbc;
  _DAT_200430 = 0x5599;
  _DAT_20042c = 0xffff;
  _DAT_20042e = 0xffff;
  return;
}


/* ----------------------------------------------------------------------------
 * can_rx_process
 * Address: 0xC01A1C
 * Area:    application/02-diagnostics/can-transport
 * Size:    184 bytes
 * -------------------------------------------------------------------------- */
/* c01a1c can_rx_process */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* TwinCAN receive processing and message-object copy. */

void can_rx_process(void)

{
  byte bVar1;
  
  if ((_DAT_200284 & 0x400) == 0) {
    if ((_DAT_200284 & 0x200) == 0) {
      _can_rx_object = 0;
    }
    else if (((_DAT_200430 & 2) != 0) && (((byte)(_DAT_200430 >> 8) & 3) == 2)) {
      _can_rx_object = 9;
    }
  }
  else if (((_DAT_200450 & 2) != 0) && (((byte)(_DAT_200450 >> 8) & 3) == 2)) {
    _can_rx_object = 10;
  }
  __service_watchdog();
  if (_can_rx_object != 0) {
    bVar1 = 0;
    do {
      *(undefined1 *)((uint3)(bVar1 + 0x3740) + 0xc000) =
           *(undefined1 *)((uint3)((ushort)bVar1 + _can_rx_object * 0x20 + 0x300) + 0x200000);
      bVar1 = bVar1 + 1;
    } while (bVar1 < 8);
    can_rx_dispatch();
    _DAT_200450 = 0x5599;
    _DAT_200430 = 0x5599;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * can_rx_dispatch
 * Address: 0xC01B22
 * Area:    application/02-diagnostics/can-transport
 * Size:    194 bytes
 * -------------------------------------------------------------------------- */
/* c01b22 can_rx_dispatch */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Dispatch received CAN message to ISO-TP transport. */

void can_rx_dispatch(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  if (_can_rx_object == 10) {
    uVar1 = can_msg_f744;
    uVar2 = can_msg_f745;
    _can_tx_remaining = CONCAT11(uVar1,uVar2);
    uVar1 = can_diag_rx_buffer;
    uVar2 = can_msg_f741;
    uVar3 = can_msg_f742;
    _can_rx_word_01 = CONCAT11(uVar1,uVar2);
    uVar1 = can_msg_f743;
    _can_rx_word_23 = CONCAT11(uVar3,uVar1);
    _can_tx_ptr = _can_rx_word_23;
    _can_tx_ptr_hi = _can_rx_word_01;
    can_rx_cmd();
  }
  if (_can_rx_object == 9) {
    can_isotp_send();
  }
  return;
}


/* ----------------------------------------------------------------------------
 * can_rx_cmd
 * Address: 0xC01BE4
 * Area:    application/02-diagnostics/can-transport
 * Size:    138 bytes
 * -------------------------------------------------------------------------- */
/* c01be4 can_rx_cmd */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAN diagnostic receive command handling. */

void can_rx_cmd(void)

{
  bool bVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  
  cVar2 = can_msg_f746;
  if (cVar2 == -1) {
    can_tx_confirm();
    while (_can_tx_remaining != 0) {
      uVar3 = _can_tx_remaining;
      if (8 < _can_tx_remaining) {
        uVar3 = 8;
      }
      uVar4 = seg_to_ptr((short)&xram_var_f750,uVar3);
      memcpy_wdt((short)uVar4,(short)((uint)uVar4 >> 0x10),_can_tx_ptr,_can_tx_ptr_hi);
      can_tx_frame(uVar3);
      _can_tx_remaining = _can_tx_remaining - uVar3;
      bVar1 = CARRY2(_can_tx_ptr,uVar3);
      _can_tx_ptr = _can_tx_ptr + uVar3;
      _can_tx_ptr_hi = _can_tx_ptr_hi + (ushort)bVar1;
      __service_watchdog();
    }
  }
  else {
    cVar2 = can_msg_f746;
    if ((cVar2 == '\0') && (_can_tx_remaining != 0)) {
      can_tx_active = 1;
      can_tx_confirm();
    }
  }
  return;
}


/* ----------------------------------------------------------------------------
 * can_isotp_send
 * Address: 0xC01C6E
 * Area:    application/02-diagnostics/can-transport
 * Size:    90 bytes
 * -------------------------------------------------------------------------- */
/* c01c6e can_isotp_send */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Send up to 8 bytes over the diagnostic CAN message object. */

void can_isotp_send(void)

{
  bool bVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  if ((can_tx_active != '\0') && (_can_tx_remaining != 0)) {
    uVar2 = _can_tx_remaining;
    if (8 < _can_tx_remaining) {
      uVar2 = 8;
    }
    uVar3 = seg_to_ptr(_can_tx_ptr,_can_tx_ptr_hi,(short)&can_diag_rx_buffer,uVar2);
    memcpy_wdt((short)uVar3,(short)((uint)uVar3 >> 0x10));
    _can_tx_remaining = _can_tx_remaining - uVar2;
    bVar1 = CARRY2(_can_tx_ptr,uVar2);
    _can_tx_ptr = _can_tx_ptr + uVar2;
    _can_tx_ptr_hi = _can_tx_ptr_hi + (ushort)bVar1;
    if (_can_tx_remaining == 0) {
      can_tx_active = '\0';
    }
  }
  return;
}


/* ----------------------------------------------------------------------------
 * can_tx_frame
 * Address: 0xC01CC8
 * Area:    application/02-diagnostics/can-transport
 * Size:    210 bytes
 * -------------------------------------------------------------------------- */
/* c01cc8 can_tx_frame */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Load and transmit one 8-byte CAN frame. */

void can_tx_frame(ushort param_1)

{
  ushort uVar1;
  
  do {
  } while (((byte)(_DAT_200430 >> 0xc) & 3) == 2);
  _DAT_200430 = _DAT_200430 & 0xf0ff | 0x200;
  if (param_1 < 8) {
    _DAT_200434 = _DAT_200434 & 0xff0f | (param_1 & 0xf) << 4;
  }
  else {
    _DAT_200434 = _DAT_200434 & 0xff7f | 0xf0;
  }
  uVar1 = 0;
  do {
    *(undefined1 *)((uint3)(uVar1 + 0x420) + 0x200000) =
         *(undefined1 *)((uint3)(uVar1 + 0x3750) + 0xc000);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  _DAT_200430 = _DAT_200430 & 0xc3ff | 0x2400;
  do {
  } while (((byte)(_DAT_200430 >> 0xc) & 3) == 2);
  return;
}


/* ----------------------------------------------------------------------------
 * can_tx_confirm
 * Address: 0xC01DEC
 * Area:    application/02-diagnostics/can-transport
 * Size:    212 bytes
 * -------------------------------------------------------------------------- */
/* c01dec can_tx_confirm */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Set CAN message object transmission-request/confirm bits. */

void can_tx_confirm(void)

{
  if (can_tx_active == '\0') {
    _DAT_200434 = _DAT_200434 & 0xfff7 | 8;
    _DAT_200430 = _DAT_200430 & 0xbd | 0x59c0;
  }
  else {
    _DAT_200434 = _DAT_200434 & 0xfff7;
    _DAT_200430 = _DAT_200430 & 0xbd | 0x55c0;
  }
  _DAT_200430 = _DAT_200430 & 0xff7f | 0xc0;
  return;
}


/* ============================== Diagnostics / status ============================== */

/* ----------------------------------------------------------------------------
 * diag_status_build
 * Address: 0xC1482C
 * Area:    application/02-diagnostics/status
 * Size:    464 bytes
 * -------------------------------------------------------------------------- */
/* c1482c diag_status_build */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Builds the packed diagnostic status bytes 0xC60C..0xC610. */

void diag_status_build(void)

{
  diag_status_byte2 =
       diag_flag_c784 | diag_flag_c850 << 1 | diag_flag_c786 << 2 | diag_flag_c780 << 3 |
       diag_flag_c781 << 4 | diag_flag_c78d << 5 | DAT_e00844 << 6 | diag_flag_cac6 << 7;
  diag_status_byte4 =
       diag_flag_cad6 | diag_flag_c014 << 1 | diag_flag_c824 << 2 | diag_flag_c841 << 3 |
       diag_flag_c830 << 4 | diag_flag_c836 << 5 | diag_flag_c840 << 6 | diag_flag_cad7 << 7;
  diag_status_byte3 =
       _diag_flag_cad0 == 1 | diag_flag_cac5 << 1 | DAT_e00810 << 2 | diag_flag_caf8 << 3;
  if (DAT_e0089e == '\0') {
    diag_status_byte3 = diag_status_byte3 | 0x10;
  }
  diag_status_byte3 = diag_status_byte3 | DAT_e0085c << 5 | DAT_e00846 << 6 | diag_flag_c954 << 7;
  diag_status_byte1 =
       diag_flag_c92b | diag_flag_c934 << 1 | DAT_e0081a << 2 | diag_flag_c81c << 3 |
       diag_flag_c77e << 4;
  if (ram_var_c604 == '\0') {
    diag_status_byte1 = diag_status_byte1 | 0x20;
  }
  if (diag_flag_c603 == '\0') {
    diag_status_byte1 = diag_status_byte1 | 0x40;
  }
  diag_status_byte1 = diag_status_byte1 | (_DAT_e0083e == 1) << 7;
  diag_status_bytes =
       diag_flag_c9f0 | diag_flag_c91c << 1 | diag_flag_c92e << 2 | diag_flag_ca44 << 3 |
       diag_flag_c89e << 4;
  if (engine_state == '\x03') {
    diag_status_bytes = diag_status_bytes | 0x20;
  }
  diag_status_bytes = diag_status_bytes | DAT_e00894 << 6 | diag_flag_caf9 << 7;
  return;
}


/* ============================== Diagnostics / test commands ============================== */

/* ----------------------------------------------------------------------------
 * test_command_clear
 * Address: 0xC13D50
 * Area:    application/02-diagnostics/test-commands
 * Size:    14 bytes
 * -------------------------------------------------------------------------- */
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


/* ----------------------------------------------------------------------------
 * test_command_dispatch
 * Address: 0xC13D5E
 * Area:    application/02-diagnostics/test-commands
 * Size:    106 bytes
 * -------------------------------------------------------------------------- */
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


/* ============================== Calibration / accessors ============================== */

/* ----------------------------------------------------------------------------
 * tbl16_interp
 * Address: 0xC27CA4
 * Area:    application/03-calibration/accessors
 * Size:    168 bytes
 * -------------------------------------------------------------------------- */
/* c27ca4 tbl16_interp */

/* 16-bit table lookup with 8.8 fixed-point interpolation. */

ushort tbl16_interp(ushort param_1,short param_2,ushort param_3)

{
  bool bVar1;
  short sVar2;
  short extraout_r1;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  
  uVar5 = param_3 >> 8;
  uVar6 = param_1 + 2 + uVar5 * 2;
  uVar5 = *(ushort *)
           ((uint3)uVar6 +
           (uint3)(param_2 + (ushort)(0xfffd < param_1) + (ushort)CARRY2(uVar5,uVar5) +
                  (ushort)CARRY2(param_1 + 2,uVar5 * 2)) * 0x10000);
  if ((param_3 & 0xff) != 0) {
    uVar6 = *(ushort *)(uVar6 + 2);
    sVar3 = uVar6 - uVar5;
    sVar2 = -(ushort)(uVar6 < uVar5);
    sVar4 = sVar2;
    if (sVar2 < 0) {
      bVar1 = sVar3 != 0;
      sVar3 = -sVar3;
      sVar4 = -(sVar2 + (ushort)bVar1);
    }
    uVar7 = mul32(sVar3,sVar4,8);
    sVar3 = extraout_r1;
    while( true ) {
      sVar4 = (short)uVar7;
      bVar1 = sVar3 == 0;
      sVar3 = sVar3 + -1;
      if (bVar1) break;
      uVar7 = uVar7 >> 1;
    }
    if (sVar2 < 0) {
      sVar4 = -sVar4;
    }
    uVar5 = uVar5 + sVar4;
  }
  return uVar5;
}


/* ----------------------------------------------------------------------------
 * tbl8_interp
 * Address: 0xC27FCA
 * Area:    application/03-calibration/accessors
 * Size:    182 bytes
 * -------------------------------------------------------------------------- */
/* c27fca tbl8_interp */

/* 8-bit table lookup with 8.8 fixed-point interpolation. */

ushort tbl8_interp(ushort param_1,short param_2,ushort param_3)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  ushort uVar6;
  short sVar7;
  int iVar8;
  
  sVar7 = 8 - (ushort)*(byte *)((uint3)(param_1 + 1) +
                               (uint3)(param_2 + (ushort)(0xfffe < param_1)) * 0x10000);
  uVar6 = param_1 + 2 + (param_3 >> 8);
  uVar2 = param_2 + (ushort)(0xfffd < param_1) + (ushort)CARRY2(param_1 + 2,param_3 >> 8);
  uVar3 = (ushort)*(byte *)((uint3)uVar6 + (uint3)uVar2 * 0x10000);
  uVar4 = uVar3;
  sVar5 = sVar7;
  while (bVar1 = sVar5 != 0, sVar5 = sVar5 + -1, bVar1) {
    uVar4 = uVar4 * 2;
  }
  if ((param_3 & 0xff) != 0) {
    sVar7 = 8 - sVar7;
    uVar6 = (ushort)*(byte *)((uint3)(uVar6 + 1) + (uint3)(uVar2 + (0xfffe < uVar6)) * 0x10000);
    iVar8 = mul32(uVar6 - uVar3,-(ushort)(uVar6 < uVar3));
    if (iVar8 < 0) {
      uVar6 = -(short)iVar8;
      sVar5 = -((short)((uint)iVar8 >> 0x10) + (ushort)((short)iVar8 != 0));
      while (bVar1 = sVar7 != 0, sVar7 = sVar7 + -1, bVar1) {
        uVar6 = uVar6 >> 1 | sVar5 << 0xf;
        sVar5 = sVar5 >> 1;
      }
      sVar5 = -uVar6;
    }
    else {
      while( true ) {
        sVar5 = (short)iVar8;
        bVar1 = sVar7 == 0;
        sVar7 = sVar7 + -1;
        if (bVar1) break;
        iVar8 = iVar8 >> 1;
      }
    }
    uVar4 = uVar4 + sVar5;
  }
  return uVar4;
}


/* ----------------------------------------------------------------------------
 * tbl2d_interp
 * Address: 0xC2826E
 * Area:    application/03-calibration/accessors
 * Size:    482 bytes
 * -------------------------------------------------------------------------- */
/* c2826e tbl2d_interp */

/* 2D 8-bit map lookup with bilinear interpolation. */

ushort tbl2d_interp(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  bool bVar1;
  ushort uVar2;
  short extraout_r1;
  ushort uVar3;
  short extraout_r1_00;
  ushort extraout_r2;
  short extraout_r3;
  short sVar4;
  short sVar5;
  short sVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  int iVar10;
  
  sVar6 = 8 - (ushort)*(byte *)((uint3)(param_1 + 2) +
                               (uint3)(param_2 + (0xfffd < param_1)) * 0x10000);
  uVar2 = (ushort)*(byte *)((uint3)param_1 + (uint3)param_2 * 0x10000);
  uVar9 = (param_4 >> 8) * uVar2 + (param_3 >> 8);
  uVar7 = param_1 + 3 + uVar9;
  uVar8 = param_2 + (0xfffc < param_1) + (ushort)CARRY2(param_1 + 3,uVar9);
  uVar9 = (ushort)*(byte *)((uint3)uVar7 + (uint3)uVar8 * 0x10000);
  sVar5 = sVar6;
  while (bVar1 = sVar5 != 0, sVar5 = sVar5 + -1, bVar1) {
    uVar9 = uVar9 * 2;
  }
  if ((param_3 & 0xff) == 0) {
    sVar5 = 0;
  }
  else {
    iVar10 = mul32();
    sVar5 = extraout_r1;
    if (iVar10 < 0) {
      uVar3 = -(short)iVar10;
      sVar5 = -((short)((uint)iVar10 >> 0x10) + (ushort)((short)iVar10 != 0));
      sVar4 = extraout_r1;
      while (bVar1 = sVar4 != 0, sVar4 = sVar4 + -1, bVar1) {
        uVar3 = uVar3 >> 1 | sVar5 << 0xf;
        sVar5 = sVar5 >> 1;
      }
      sVar4 = -uVar3;
    }
    else {
      while( true ) {
        sVar4 = (short)iVar10;
        bVar1 = sVar5 == 0;
        sVar5 = sVar5 + -1;
        if (bVar1) break;
        iVar10 = iVar10 >> 1;
      }
    }
    uVar9 = uVar9 + sVar4;
    sVar5 = extraout_r3;
  }
  if ((param_4 & 0xff) != 0) {
    uVar8 = uVar8 + CARRY2(uVar7,uVar2);
    do {
      bVar1 = sVar6 != 0;
      sVar6 = sVar6 + -1;
    } while (bVar1);
    if (sVar5 != 0) {
      sVar5 = mul32(*(undefined1 *)((uint3)(uVar7 + uVar2) + (uint3)uVar8 * 0x10000),0);
      sVar6 = extraout_r1_00;
      uVar8 = extraout_r2;
      if (sVar5 < 0) {
        do {
          bVar1 = sVar6 != 0;
          sVar6 = sVar6 + -1;
        } while (bVar1);
      }
      else {
        do {
          bVar1 = sVar6 != 0;
          sVar6 = sVar6 + -1;
        } while (bVar1);
      }
    }
    iVar10 = mul32(uVar8);
    if (iVar10 < 0) {
      uVar7 = -(short)iVar10;
      sVar5 = -((short)((uint)iVar10 >> 0x10) + (ushort)((short)iVar10 != 0));
      sVar6 = 8;
      while (bVar1 = sVar6 != 0, sVar6 = sVar6 + -1, bVar1) {
        uVar7 = uVar7 >> 1 | sVar5 << 0xf;
        sVar5 = sVar5 >> 1;
      }
      sVar6 = -uVar7;
    }
    else {
      sVar5 = 8;
      while( true ) {
        sVar6 = (short)iVar10;
        bVar1 = sVar5 == 0;
        sVar5 = sVar5 + -1;
        if (bVar1) break;
        iVar10 = iVar10 >> 1;
      }
    }
    uVar9 = uVar9 + sVar6;
  }
  return uVar9;
}


/* ----------------------------------------------------------------------------
 * axis16_signed
 * Address: 0xC284D8
 * Area:    application/03-calibration/accessors
 * Size:    54 bytes
 * -------------------------------------------------------------------------- */
/* c284d8 axis16_signed */

/* Signed axis descriptor -> 8.8 fixed-point index. */

ushort axis16_signed(ushort param_1,short param_2)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 + 2);
  uVar2 = (*(short *)(uint3)param_1 + -1) * 0x100;
  if (sVar1 < param_2) {
    if (param_2 < *(short *)(uint3)(param_1 + 4)) {
      uVar2 = (ushort)(((uint)(ushort)(param_2 - sVar1) * (uint)uVar2) /
                      (uint)(ushort)(*(short *)(uint3)(param_1 + 4) - sVar1));
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* ----------------------------------------------------------------------------
 * axis16_unsigned
 * Address: 0xC2850E
 * Area:    application/03-calibration/accessors
 * Size:    54 bytes
 * -------------------------------------------------------------------------- */
/* c2850e axis16_unsigned */

/* Unsigned axis descriptor -> 8.8 fixed-point index. */

ushort axis16_unsigned(ushort param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *(ushort *)(uint3)(param_1 + 2);
  uVar2 = (*(short *)(uint3)param_1 + -1) * 0x100;
  if (uVar1 < param_2) {
    if (param_2 < *(ushort *)(uint3)(param_1 + 4)) {
      uVar2 = (ushort)(((uint)(param_2 - uVar1) * (uint)uVar2) /
                      (uint)(*(ushort *)(uint3)(param_1 + 4) - uVar1));
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* ============================== Calibration / checksum ============================== */

/* ----------------------------------------------------------------------------
 * cal_checksum
 * Address: 0xC11B9A
 * Area:    application/03-calibration/checksum
 * Size:    90 bytes
 * -------------------------------------------------------------------------- */
/* c11b9a cal_checksum */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Verify calibration block checksum 0xC05000-0xC0AFFD vs 0xC0AFFE. */

void cal_checksum(void)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar2 = 0x5000;
  _cal_checksum_accum = 0;
  for (uVar3 = 0xc0; uVar3 < 0xc0 || uVar3 == 0xc0 && uVar2 < 0xaffd; uVar3 = uVar3 + bVar1) {
    _cal_checksum_accum =
         _cal_checksum_accum + *(short *)((uint3)uVar2 + (uint3)uVar3 * 0x10000) * 0x100 +
         (*(ushort *)((uint3)uVar2 + (uint3)uVar3 * 0x10000) >> 8);
    bVar1 = 0xfffd < uVar2;
    uVar2 = uVar2 + 2;
  }
  _cal_checksum_valid = (ushort)(cal_checksum == _cal_checksum_accum);
  return;
}


/* ============================== Engine control / events ============================== */

/* ----------------------------------------------------------------------------
 * capcom_event_config2
 * Address: 0xC0BBC4
 * Area:    application/04-engine-control/events
 * Size:    50 bytes
 * -------------------------------------------------------------------------- */
/* c0bbc4 capcom_event_config2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configure one CAPCOM event channel (second form). */

void capcom_event_config2
               (byte param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 unaff_00000000,undefined2 unaff_00000002)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  sVar1 = (ushort)param_1 * 0x12;
  *(undefined2 *)(uint3)(sVar1 + 0xc412) = param_2;
  *(undefined2 *)(uint3)(sVar1 + 0xc414) = param_3;
  *(undefined2 *)(uint3)(ushort)((short)&cc16_17_channels + sVar1) = param_4;
  _event_offset_3 = unaff_00000000;
  _event_offset_0 = unaff_00000002;
  event_schedule(param_1);
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return;
}


/* ----------------------------------------------------------------------------
 * capcom_event_config
 * Address: 0xC0BCA4
 * Area:    application/04-engine-control/events
 * Size:    176 bytes
 * -------------------------------------------------------------------------- */
/* c0bca4 capcom_event_config */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Configure one CAPCOM event channel. */

void capcom_event_config(ushort param_1,byte param_2,short param_3)

{
  ushort *puVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  
  uVar4 = PSW;
  PSW = uVar4 & 0xf7ff;
  if (param_3 != 0) {
    event_var_c40e = 1;
  }
  sVar2 = (param_1 & 0xff) * 0x12;
  sVar3 = (param_1 & 0xff) * 8;
  puVar1 = (ushort *)((short)&ram_var_c394 + sVar3);
  *(byte *)(uint3)(sVar2 + 0xc41d) = param_2;
  *(undefined2 *)(uint3)*puVar1 = *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar1);
  *(undefined2 *)(uint3)(sVar2 + 0xc41e) =
       *(undefined2 *)(uint3)(ushort)((short)&ram_var_c392 + sVar3);
  _cc16_irq_ptr = (ushort)&DAT_00fe28;
  _cc17_irq_ptr = SUB32(&DAT_00fe2a,0);
  _cc_compare_mode_ptr = SUB32(&DAT_00ff2c,0);
  _cc_compare_mode_shadow = SUB32(&CCM4,0);
  puVar1 = (ushort *)((short)&ram_var_c396 + sVar3);
  _t7_snapshot = SUB32(&T7,0);
  *(undefined2 *)(uint3)(sVar2 + 0xc420) = *(undefined2 *)ZEXT23(puVar1);
  *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) =
       *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) | 0x30 | param_1 & 0xff;
  *(ushort *)(uint3)_cc16_irq_ptr = *(ushort *)(uint3)_cc16_irq_ptr | 1 << (param_2 & 0xf);
  event_cancel(param_1 & 0xff,param_1);
  *(ushort *)(uint3)*puVar1 = *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) | 0x40;
  uVar4 = PSW;
  PSW = uVar4 | 0x800;
  return;
}


/* ----------------------------------------------------------------------------
 * capcom16_17_init
 * Address: 0xC0BD58
 * Area:    application/04-engine-control/events
 * Size:    70 bytes
 * -------------------------------------------------------------------------- */
/* c0bd58 capcom16_17_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAPCOM CC16/CC17 channel setup. */

void capcom16_17_init(void)

{
  ushort uVar1;
  
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 1;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 2;
  event_var_c390 = 0x10;
  _ram_var_c392 = SUB32(&CC16,0);
  _ram_var_c394 = SUB32(&CCM4,0);
  _ram_var_c396 = SUB32(&CC16IC,0);
  event_var_c398 = 0x11;
  _ram_var_c39a = SUB32(&CC17,0);
  _ram_var_c39c = SUB32(&CCM4,0);
  _ram_var_c39e = SUB32(&CC17IC,0);
  return;
}


/* ----------------------------------------------------------------------------
 * cc_control_ptr_init
 * Address: 0xC0BEF0
 * Area:    application/04-engine-control/events
 * Size:    18 bytes
 * -------------------------------------------------------------------------- */
/* c0bef0 cc_control_ptr_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Caches pointers to 0xFF2C and 0xFE2A. */

void cc_control_ptr_init(void)

{
  _cc_control_ptr = SUB32(&DAT_00ff2c,0);
  _cc_irq_ptr = SUB32(&DAT_00fe2a,0);
  return;
}


/* ----------------------------------------------------------------------------
 * cc_irq_enable
 * Address: 0xC0BF54
 * Area:    application/04-engine-control/events
 * Size:    56 bytes
 * -------------------------------------------------------------------------- */
/* c0bf54 cc_irq_enable */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Sets or clears a per-channel CC interrupt-enable bit. */

void cc_irq_enable(ushort param_1,short param_2)

{
  ushort uVar1;
  
  if (param_2 == 0) {
    *(ushort *)(uint3)_cc_control_ptr =
         *(ushort *)(uint3)_cc_control_ptr & ~(1 << (param_1 >> 1 & 0xf));
    return;
  }
  uVar1 = 1 << (param_1 >> 1 & 0xf);
  *(ushort *)(uint3)_cc_control_ptr = *(ushort *)(uint3)_cc_control_ptr & ~uVar1 | uVar1;
  return;
}


/* ----------------------------------------------------------------------------
 * cc_irq_is_enabled
 * Address: 0xC0BF8C
 * Area:    application/04-engine-control/events
 * Size:    36 bytes
 * -------------------------------------------------------------------------- */
/* c0bf8c cc_irq_is_enabled */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Tests a per-channel CC interrupt-enable bit in 0xFF2C. */

undefined2 cc_irq_is_enabled(ushort param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  
  uVar1 = 1 << (param_1 >> 1 & 0xf);
  if (((*(ushort *)(uint3)_cc_control_ptr & uVar1) == 0) || (uVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* ----------------------------------------------------------------------------
 * event_start
 * Address: 0xC0D39E
 * Area:    application/04-engine-control/events
 * Size:    88 bytes
 * -------------------------------------------------------------------------- */
/* c0d39e event_start */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Start event scheduler channels. */

void event_start(void)

{
  short sVar1;
  byte bVar2;
  
  sVar1 = t7_timestamp_extended();
  bVar2 = 0;
  do {
    capcom_event_config2
              (bVar2,*(undefined2 *)(uint3)((short)&event_var_c384 + (ushort)bVar2 * 4),
               *(undefined2 *)(uint3)((short)&event_var_c386 + (ushort)bVar2 * 4),sVar1 + 4,
               _event_var_c37e,_event_var_c374);
    *(undefined2 *)(uint3)((ushort)bVar2 * 0x12 + 0xc416) = 0;
    *(undefined2 *)(uint3)((ushort)bVar2 * 0x12 + 0xc418) = 0;
    bVar2 = bVar2 + 1;
  } while (bVar2 < 2);
  _event_var_c36e = 0;
  return;
}


/* ----------------------------------------------------------------------------
 * event_reset
 * Address: 0xC0D516
 * Area:    application/04-engine-control/events
 * Size:    18 bytes
 * -------------------------------------------------------------------------- */
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


/* ----------------------------------------------------------------------------
 * event_init
 * Address: 0xC0D528
 * Area:    application/04-engine-control/events
 * Size:    58 bytes
 * -------------------------------------------------------------------------- */
/* c0d528 event_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initialize event scheduler channels. */

void event_init(void)

{
  ushort uVar1;
  byte bVar2;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  capcom16_17_init();
  bVar2 = 0;
  do {
    capcom_event_config(bVar2,*(undefined1 *)(uint3)((short)&event_var_c390 + (ushort)bVar2 * 8),1);
    bVar2 = bVar2 + 1;
  } while (bVar2 < 2);
  event_var_c370 = 0;
  if (_event_var_c372 == 0) {
    event_start();
  }
  event_reset();
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


/* ----------------------------------------------------------------------------
 * event_start_fixed
 * Address: 0xC0D6F0
 * Area:    application/04-engine-control/events
 * Size:    26 bytes
 * -------------------------------------------------------------------------- */
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


/* ----------------------------------------------------------------------------
 * cc_irq_enable_bit
 * Address: 0xC0DB90
 * Area:    application/04-engine-control/events
 * Size:    22 bytes
 * -------------------------------------------------------------------------- */
/* c0db90 cc_irq_enable_bit */

/* Enables the CC16/CC17 interrupt bit for a channel ID. */

void cc_irq_enable_bit(char param_1)

{
  ushort uVar1;
  
  if (param_1 != '\x10') {
    uVar1 = DAT_00fe2a;
    DAT_00fe2a = uVar1 | 2;
    return;
  }
  uVar1 = DAT_00fe2a;
  DAT_00fe2a = uVar1 | 1;
  return;
}


/* ----------------------------------------------------------------------------
 * cc_compare_mode_set
 * Address: 0xC0DBA6
 * Area:    application/04-engine-control/events
 * Size:    56 bytes
 * -------------------------------------------------------------------------- */
/* c0dba6 cc_compare_mode_set */

/* Sets the CC16/CC17 compare-mode bit for a channel ID. */

void cc_compare_mode_set(ushort param_1)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = *(char *)(uint3)((param_1 & 0xff) * 0x12 + 0xc41d);
  if (event_var_c40e != '\0') {
    if (cVar1 != '\x10') {
      uVar2 = DAT_00ff2c;
      DAT_00ff2c = uVar2 & 0xfffd;
      return;
    }
    uVar2 = DAT_00ff2c;
    DAT_00ff2c = uVar2 & 0xfffe;
    return;
  }
  if (cVar1 != '\x10') {
    uVar2 = DAT_00ff2c;
    DAT_00ff2c = uVar2 | 2;
    return;
  }
  uVar2 = DAT_00ff2c;
  DAT_00ff2c = uVar2 | 1;
  return;
}


/* ----------------------------------------------------------------------------
 * event_force
 * Address: 0xC0DBDE
 * Area:    application/04-engine-control/events
 * Size:    132 bytes
 * -------------------------------------------------------------------------- */
/* c0dbde event_force */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Force event at fixed offset. */

void event_force(ushort param_1)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  
  sVar3 = (param_1 & 0xff) * 0x12;
  bVar1 = *(byte *)(uint3)(sVar3 + 0xc41d);
  bVar2 = bVar1 & 0xf;
  if (((*(ushort *)(uint3)_cc_compare_mode_ptr & 1 << bVar2) != 0) == (event_var_c40e == '\0')) {
    *(short *)(uint3)*(ushort *)(uint3)(sVar3 + 0xc41e) = *(short *)(uint3)_t7_snapshot + 10;
  }
  sVar3 = (ushort)bVar2 << 2;
  *(ushort *)(uint3)_cc_compare_mode_shadow =
       *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar3);
  *(ushort *)(uint3)_cc_compare_mode_shadow = *(ushort *)(uint3)_cc_compare_mode_shadow | 5 << sVar3
  ;
  cc_irq_enable_bit(bVar1);
  return;
}


/* ----------------------------------------------------------------------------
 * event_cancel
 * Address: 0xC0DC62
 * Area:    application/04-engine-control/events
 * Size:    40 bytes
 * -------------------------------------------------------------------------- */
/* c0dc62 event_cancel */

/* Cancel/initialize one event channel. */

void event_cancel(byte param_1)

{
  short sVar1;
  
  sVar1 = (ushort)param_1 * 0x12;
  *(undefined2 *)(uint3)(sVar1 + 0xc416) = 0;
  *(undefined2 *)(uint3)(sVar1 + 0xc418) = 0;
  *(undefined1 *)(uint3)(sVar1 + 0xc41c) = 0;
  event_idle(param_1);
  return;
}


/* ----------------------------------------------------------------------------
 * event_schedule
 * Address: 0xC0DC8A
 * Area:    application/04-engine-control/events
 * Size:    428 bytes
 * -------------------------------------------------------------------------- */
/* c0dc8a event_schedule */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Schedule CAPCOM event (dwell/pulse) for a channel. */

void event_schedule(byte param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  ushort uVar7;
  short sVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  
  sVar6 = (ushort)param_1 * 0x12;
  uVar2 = sVar6 + 0xc41c;
  puVar3 = (ushort *)(sVar6 + 0xc41e);
  uVar7 = (ushort)*(byte *)(uint3)(sVar6 + 0xc41d);
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xe3;
  uVar10 = *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar3);
  uVar1 = *(undefined2 *)(uint3)_t7_snapshot;
  cc_compare_mode_set(param_1);
  uVar9 = uVar10;
  if (((*(byte *)(uint3)uVar2 & 1) == 0) ||
     (((*(byte *)(uint3)uVar2 & 4) == 0 &&
      (uVar9 = uVar1, (**(ushort **)(uint3)(sVar6 + 0xc420) & 0x80) == 0)))) {
    *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar3) = uVar1;
    uVar10 = uVar9;
  }
  *(ushort *)(uint3)*(ushort *)(uint3)(sVar6 + 0xc420) =
       *(ushort *)(uint3)*(ushort *)(uint3)(sVar6 + 0xc420) & 0xff7f;
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 0x20;
  if ((*(byte *)(uint3)uVar2 & 1) == 0) {
    if ((*(byte *)(uint3)uVar2 & 2) == 0) {
      event_schedule_duration(param_1);
    }
    else {
      if (_event_offset_1 < (*(short *)(uint3)_t7_snapshot - *(short *)(sVar6 + -0x3be6)) + 10U) {
        *(short *)(uint3)*(ushort *)ZEXT23(puVar3) = *(short *)(uint3)_t7_snapshot + 10;
      }
      else {
        *(ushort *)(uint3)*(ushort *)ZEXT23(puVar3) =
             *(short *)ZEXT23((short *)(sVar6 + -0x3be6)) + _event_offset_1;
      }
      sVar6 = (uVar7 & 0xf) << 2;
      *(ushort *)(uint3)_cc_compare_mode_shadow =
           *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar6);
      *(ushort *)(uint3)_cc_compare_mode_shadow =
           *(ushort *)(uint3)_cc_compare_mode_shadow | 4 << sVar6;
      cc_irq_enable_bit(uVar7);
    }
  }
  else {
    event_accum(param_1,uVar10);
    *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xfe;
    uVar5 = *(ushort *)(uint3)(sVar6 + 0xc412U) | *(ushort *)(uint3)(sVar6 + 0xc414);
    if (uVar5 == 0) {
      event_idle(param_1);
    }
    else {
      sVar8 = t7_timestamp_extended(uVar5);
      uVar5 = *(ushort *)(uint3)(sVar6 + 0xc412U);
      uVar4 = uVar5 + _event_offset_2;
      if ((uVar4 + _event_offset_1 >> 8 |
          (*(short *)(uint3)(sVar6 + 0xc414) + (ushort)CARRY2(uVar5,_event_offset_2) +
          (ushort)CARRY2(uVar4,_event_offset_1)) * 0x100) <
          (ushort)(*(short *)(uint3)(ushort)((short)&cc16_17_channels + sVar6) - sVar8)) {
        *(ushort *)(uint3)*puVar3 = *(short *)(uint3)_t7_snapshot + _event_offset_1;
        sVar6 = (uVar7 & 0xf) << 2;
        *(ushort *)(uint3)_cc_compare_mode_shadow =
             *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar6);
        *(ushort *)(uint3)_cc_compare_mode_shadow =
             *(ushort *)(uint3)_cc_compare_mode_shadow | 4 << sVar6;
        cc_irq_enable_bit(uVar7,0);
        *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 2;
      }
      else {
        event_force(param_1);
        *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 0x40;
      }
    }
  }
  return;
}


/* ----------------------------------------------------------------------------
 * event_idle
 * Address: 0xC0E1B6
 * Area:    application/04-engine-control/events
 * Size:    128 bytes
 * -------------------------------------------------------------------------- */
/* c0e1b6 event_idle */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Set channel to idle. */

void event_idle(byte param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  
  sVar3 = (ushort)param_1 * 0x12;
  bVar1 = *(byte *)(uint3)(sVar3 + 0xc41d);
  cc_compare_mode_set(param_1);
  uVar2 = sVar3 + 0xc41c;
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xdf;
  *(short *)(uint3)*(ushort *)(uint3)(sVar3 + 0xc41e) = *(short *)(uint3)_t7_snapshot + 0x7000;
  sVar4 = (bVar1 & 0xf) << 2;
  *(ushort *)(uint3)_cc_compare_mode_shadow =
       *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar4);
  *(ushort *)(uint3)_cc_compare_mode_shadow = *(ushort *)(uint3)_cc_compare_mode_shadow | 4 << sVar4
  ;
  cc_irq_enable_bit(bVar1);
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 4;
  *(ushort *)(uint3)*(ushort *)(uint3)(sVar3 + 0xc420) =
       *(ushort *)(uint3)*(ushort *)(uint3)(sVar3 + 0xc420) & 0xff7f;
  return;
}


/* ----------------------------------------------------------------------------
 * event_accum
 * Address: 0xC0E236
 * Area:    application/04-engine-control/events
 * Size:    70 bytes
 * -------------------------------------------------------------------------- */
/* c0e236 event_accum */

/* Accumulate event time. */

void event_accum(ushort param_1,short param_2)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  sVar3 = (param_1 & 0xff) * 0x12;
  uVar2 = param_2 - *(short *)(sVar3 + -0x3be6);
  if (uVar2 < 0x7f01) {
    uVar1 = *(ushort *)(uint3)(sVar3 + 0xc416U);
    *(ushort *)(uint3)(sVar3 + 0xc418) =
         *(short *)(uint3)(sVar3 + 0xc418) + (ushort)CARRY2(uVar1,uVar2);
    *(ushort *)(uint3)(sVar3 + 0xc416U) = uVar1 + uVar2;
    *(short *)ZEXT23((short *)(sVar3 + -0x3be6)) = param_2;
    *(byte *)(uint3)(sVar3 + 0xc41cU) = *(byte *)(uint3)(sVar3 + 0xc41cU) & 0x7f;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * event_schedule_duration
 * Address: 0xC0E27C
 * Area:    application/04-engine-control/events
 * Size:    350 bytes
 * -------------------------------------------------------------------------- */
/* c0e27c event_schedule_duration */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Schedules a CC16/CC17 event using the 32-bit duration fields. */

void event_schedule_duration(byte param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  short sVar6;
  ushort uVar7;
  ushort uVar8;
  
  sVar5 = (ushort)param_1 * 0x12;
  bVar1 = *(byte *)(uint3)(sVar5 + 0xc41dU);
  uVar2 = *(ushort *)(uint3)(sVar5 + 0xc412U) | *(ushort *)(uint3)(sVar5 + 0xc414);
  if (uVar2 == 0) {
    event_idle(param_1);
  }
  else {
    sVar6 = t7_timestamp_extended(uVar2);
    uVar4 = *(short *)(uint3)(ushort)((short)&cc16_17_channels + sVar5) - sVar6;
    uVar2 = *(ushort *)(uint3)(sVar5 + 0xc412U);
    uVar7 = uVar2 + _event_offset_2;
    uVar8 = *(short *)(uint3)(sVar5 + 0xc414) + (ushort)CARRY2(uVar2,_event_offset_2);
    uVar2 = sVar5 + 0xc41c;
    if ((*(byte *)(uint3)uVar2 & 8) == 0) {
      uVar3 = uVar7 >> 8 | uVar8 * 0x100;
      uVar7 = _event_offset_3 + uVar3;
      uVar8 = (uVar8 >> 8) + (ushort)CARRY2(_event_offset_3,uVar3);
    }
    else {
      uVar3 = (uVar8 - *(short *)(uint3)(sVar5 + 0xc418)) -
              (ushort)(uVar7 < *(ushort *)(uint3)(sVar5 + 0xc416));
      uVar8 = uVar7 - *(ushort *)(uint3)(sVar5 + 0xc416) >> 8 | uVar3 * 0x100;
      uVar7 = _event_offset_0 + uVar8;
      uVar8 = (uVar3 >> 8) + (ushort)CARRY2(_event_offset_0,uVar8);
    }
    if ((uVar8 != (uVar7 != 0xffff) || uVar7 != 0xffff) && (uVar8 != 0 || uVar7 == 0xffff)) {
      uVar7 = 0xffff;
      uVar8 = 0;
    }
    if (uVar7 < uVar4) {
      uVar4 = uVar4 - uVar7;
      if (0x7f < uVar4) {
        *(short *)(uint3)*(ushort *)(uint3)(sVar5 + 0xc41e) = *(short *)(uint3)_t7_snapshot + 0x7000
        ;
        sVar5 = (bVar1 & 0xf) << 2;
        *(ushort *)(uint3)_cc_compare_mode_shadow =
             *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar5);
        *(ushort *)(uint3)_cc_compare_mode_shadow =
             *(ushort *)(uint3)_cc_compare_mode_shadow | 4 << sVar5;
        cc_irq_enable_bit(bVar1);
        *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 4;
        return;
      }
      bVar1 = *(byte *)(uint3)(sVar5 + 0xc41dU);
      *(ushort *)(uint3)*(ushort *)(uint3)(sVar5 + 0xc41e) =
           *(short *)(uint3)_t7_snapshot + uVar4 * 0x100;
      sVar5 = (bVar1 & 0xf) << 2;
      *(ushort *)(uint3)_cc_compare_mode_shadow =
           *(ushort *)(uint3)_cc_compare_mode_shadow & ~(0xf << sVar5);
      *(ushort *)(uint3)_cc_compare_mode_shadow =
           *(ushort *)(uint3)_cc_compare_mode_shadow | 5 << sVar5;
      cc_irq_enable_bit(bVar1);
    }
    else {
      event_force(param_1,uVar8);
    }
    *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xfb;
  }
  return;
}


/* ============================== Engine control / CC22-23 outputs ============================== */

/* ----------------------------------------------------------------------------
 * cc22_23_output_disable
 * Address: 0xC0BE46
 * Area:    application/04-engine-control/outputs-cc22-23
 * Size:    18 bytes
 * -------------------------------------------------------------------------- */
/* c0be46 cc22_23_output_disable */

/* Clears the CC22/CC23 output-enable bits in CCM5. */

void cc22_23_output_disable(short param_1)

{
  ushort uVar1;
  
  if (param_1 != 0) {
    uVar1 = CCM5;
    CCM5 = uVar1 & 0xf8ff;
    return;
  }
  uVar1 = CCM5;
  CCM5 = uVar1 & 0x8fff;
  return;
}


/* ----------------------------------------------------------------------------
 * cc22_23_schedule
 * Address: 0xC0BE6A
 * Area:    application/04-engine-control/outputs-cc22-23
 * Size:    134 bytes
 * -------------------------------------------------------------------------- */
/* c0be6a cc22_23_schedule */

/* Programs the CC22/CC23 compare values from a T7 timestamp. */

void cc22_23_schedule(short param_1,short param_2)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  
  sVar3 = t7_timestamp();
  if (((ushort)(param_2 - sVar3) < 3) || (0x1fff < (ushort)(param_2 - sVar3))) {
    sVar1 = T7;
    if (param_1 == 0) {
      __atomic(2);
      CC23 = sVar1 + 7;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x80;
    }
    else {
      __atomic(2);
      CC22 = sVar1 + 7;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x40;
    }
    *(short *)(uint3)(ushort)((short)&cc22_23_channels + param_1 * 0x1a) = sVar3;
  }
  else {
    if (param_1 == 0) {
      __atomic(2);
      CC23 = param_2 << 3;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x80;
    }
    else {
      __atomic(2);
      CC22 = param_2 << 3;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x40;
    }
    *(short *)(uint3)(ushort)((short)&cc22_23_channels + param_1 * 0x1a) = param_2;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * cc22_23_output_init
 * Address: 0xC0BF02
 * Area:    application/04-engine-control/outputs-cc22-23
 * Size:    62 bytes
 * -------------------------------------------------------------------------- */
/* c0bf02 cc22_23_output_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initializes CC22/CC23 interrupt/port/compare pointers. */

void cc22_23_output_init(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fe28;
  DAT_00fe28 = uVar1 | 0xc0;
  uVar1 = CCM5;
  CCM5 = uVar1 | 0x5500;
  uVar1 = DAT_00f130;
  DAT_00f130 = uVar1 | 0x80;
  uVar1 = DAT_00f120;
  DAT_00f120 = uVar1 | 1;
  uVar1 = DP1L;
  DP1L = uVar1 | 0x80;
  uVar1 = P1H;
  P1H = uVar1 | 1;
  uVar1 = CC22IC;
  CC22IC = uVar1 | 0x34;
  uVar1 = S0RIC;
  S0RIC = uVar1 | 0x35;
  _cc23_compare_ptr = SUB32(&CC23,0);
  _cc22_compare_ptr = SUB32(&CC22,0);
  _cc23_irq_ptr = SUB32(&CC23IC,0);
  _cc22_irq_ptr = SUB32(&CC22IC,0);
  return;
}


/* ----------------------------------------------------------------------------
 * cc22_23_hysteresis_a
 * Address: 0xC0E722
 * Area:    application/04-engine-control/outputs-cc22-23
 * Size:    62 bytes
 * -------------------------------------------------------------------------- */
/* c0e722 cc22_23_hysteresis_a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Hysteresis thresholds for the first CC22/CC23 input; state in cc22_23_state_machine_a. */

void cc22_23_hysteresis_a(ushort param_1)

{
  if (_cc22_23_state_machine_a == 0) {
    if (param_1 < 0x6901) {
      return;
    }
  }
  else {
    if (_cc22_23_state_machine_a == 1) {
      if (param_1 < 0x6400) {
        _cc22_23_state_machine_a = 0;
      }
      if (param_1 < 0xa401) {
        return;
      }
      _cc22_23_state_machine_a = 2;
      return;
    }
    if (_cc22_23_state_machine_a != 2) {
      return;
    }
    if (0x9fff < param_1) {
      return;
    }
  }
  _cc22_23_state_machine_a = 1;
  return;
}


/* ----------------------------------------------------------------------------
 * cc22_23_hysteresis_b
 * Address: 0xC0E760
 * Area:    application/04-engine-control/outputs-cc22-23
 * Size:    106 bytes
 * -------------------------------------------------------------------------- */
/* c0e760 cc22_23_hysteresis_b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Hysteresis thresholds for the second CC22/CC23 input; state in cc22_23_state_machine_b. */

void cc22_23_hysteresis_b(ushort param_1)

{
  if (_cc22_23_state_machine_b == 0) {
    if (0x1c00 < param_1) {
      _cc22_23_state_machine_b = 1;
    }
  }
  else if (_cc22_23_state_machine_b == 1) {
    if (param_1 < 0x1800) {
      _cc22_23_state_machine_b = 0;
    }
    if ((0x5f00 < param_1) || (_cc22_23_state_machine_a != 0)) {
      _cc22_23_state_machine_b = 2;
      return;
    }
  }
  else if (_cc22_23_state_machine_b == 2) {
    if ((param_1 < 0x5a00) && (_cc22_23_state_machine_a == 0)) {
      _cc22_23_state_machine_b = 1;
    }
    if (0x8400 < param_1) {
      _cc22_23_state_machine_b = 3;
      return;
    }
  }
  else if ((_cc22_23_state_machine_b == 3) && (param_1 < 0x8000)) {
    _cc22_23_state_machine_b = 2;
    return;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * cc_output_gate_update
 * Address: 0xC0EBE6
 * Area:    application/04-engine-control/outputs-cc22-23
 * Size:    38 bytes
 * -------------------------------------------------------------------------- */
/* c0ebe6 cc_output_gate_update */

/* Updates the CC output gate bits in 0xFD08/0xFD06. */

void cc_output_gate_update(void)

{
  ushort uVar1;
  
  uVar1 = capture_status_1;
  if (((uVar1 & 4) == 0) && (uVar1 = capture_input_select, (uVar1 & 0x20) != 0)) {
    uVar1 = output_gate_0;
    output_gate_0 = uVar1 | 0x8000;
  }
  else {
    uVar1 = output_gate_0;
    output_gate_0 = uVar1 & 0x7fff;
  }
  uVar1 = capture_status_0;
  if (((uVar1 & 4) == 0) && (uVar1 = capture_input_select, (uVar1 & 0x10) != 0)) {
    uVar1 = output_gate_1;
    output_gate_1 = uVar1 | 0x8000;
    return;
  }
  uVar1 = output_gate_1;
  output_gate_1 = uVar1 & 0x7fff;
  return;
}


/* ----------------------------------------------------------------------------
 * cc22_23_task
 * Address: 0xC0F3D2
 * Area:    application/04-engine-control/outputs-cc22-23
 * Size:    164 bytes
 * -------------------------------------------------------------------------- */
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


/* ----------------------------------------------------------------------------
 * cc22_23_start_pair
 * Address: 0xC0FACE
 * Area:    application/04-engine-control/outputs-cc22-23
 * Size:    42 bytes
 * -------------------------------------------------------------------------- */
/* c0face cc22_23_start_pair */

/* Starts both CC22/CC23 channels at a common timestamp. */

void cc22_23_start_pair(short param_1,undefined2 param_2)

{
  ushort uVar1;
  
  cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&cc22_23_input_0 + param_1 * 2),param_1,
                   param_2);
  if (param_1 == 0) {
    uVar1 = S0RIC;
    S0RIC = uVar1 | 0x40;
    return;
  }
  if (param_1 == 1) {
    uVar1 = S0TIC;
    S0TIC = uVar1 | 0x40;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * cc22_23_start_once
 * Address: 0xC0FB36
 * Area:    application/04-engine-control/outputs-cc22-23
 * Size:    56 bytes
 * -------------------------------------------------------------------------- */
/* c0fb36 cc22_23_start_once */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* One-shot start of the CC22/CC23 pair. */

void cc22_23_start_once(void)

{
  short sVar1;
  
  if (cc22_23_started == '\0') {
    cc22_23_started = '\x01';
    p1l1_set();
    sVar1 = t7_timestamp();
    cc22_23_start_pair(0,sVar1);
    cc22_23_start_pair(1,sVar1);
    _cc22_23_start_time = sVar1 + cal_cc_start_offset;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * cc_event_timeout_tick
 * Address: 0xC0FB8C
 * Area:    application/04-engine-control/outputs-cc22-23
 * Size:    64 bytes
 * -------------------------------------------------------------------------- */
/* c0fb8c cc_event_timeout_tick */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Decrements the CC event timeout counters. */

void cc_event_timeout_tick(void)

{
  char cVar1;
  byte bVar2;
  
  _event_var_c478 = _event_var_c478 + 1;
  if (0xa00 < _event_var_c478) {
    _event_var_c478 = 0;
    cVar1 = cc_event_timeout_0;
    if ((cVar1 != '\0') && (bVar2 = cc_event_timeout_0, bVar2 < 0x10)) {
      cVar1 = cc_event_timeout_0;
      cc_event_timeout_0 = cVar1 + -1;
    }
    cVar1 = cc_event_timeout_1;
    if ((cVar1 != '\0') && (bVar2 = cc_event_timeout_1, bVar2 < 0x10)) {
      cVar1 = cc_event_timeout_1;
      cc_event_timeout_1 = cVar1 + -1;
    }
  }
  return;
}


/* ============================== Engine control / speed ============================== */

/* ----------------------------------------------------------------------------
 * speed_timing_calc
 * Address: 0xC0CD24
 * Area:    application/04-engine-control/speed
 * Size:    214 bytes
 * -------------------------------------------------------------------------- */
/* c0cd24 speed_timing_calc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Maps engine speed input 0xC9D0 through axis 0x7000 and tables 0x504C/0x5038. */

void speed_timing_calc(void)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  bVar1 = (byte)(speed_sample_counter + 1) < speed_sample_counter;
  speed_sample_counter = speed_sample_counter + 1;
  if (bVar1) {
    speed_sample_counter = 0xff;
  }
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = input_status_flags;
  uVar3 = input_status_flags;
  input_status_flags = uVar3 & 0xffbf;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = speed_status_flags;
  speed_status_flags = uVar3 & 0xbfff | (uVar2 >> 6 & 1) << 0xe;
  uVar2 = speed_status_flags;
  if ((uVar2 & 0x4000) != 0) {
    uVar2 = speed_status_flags;
    speed_status_flags = uVar2 | 0x8000;
  }
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = input_status_flags;
  uVar3 = input_status_flags;
  input_status_flags = uVar3 & 0xf7ff;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = speed_status_flags;
  speed_status_flags = uVar3 & 0xdfff | (uVar2 >> 0xb & 1) << 0xd;
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = input_status_flags;
  uVar3 = input_status_flags;
  input_status_flags = uVar3 & 0xfdff;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = speed_status_flags;
  speed_status_flags = uVar3 & 0xefff | (uVar2 >> 9 & 1) << 0xc;
  uVar2 = speed_status_flags;
  if ((uVar2 & 0x1000) != 0) {
    uVar2 = speed_status_flags;
    speed_status_flags = uVar2 & 0xf3ff | 0xc00;
  }
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  _speed_axis_index = axis16_unsigned(0x7000,_engine_speed_input);
  _speed_table_504c = tbl16_interp(0x504c,0xc0,_speed_axis_index);
  _speed_table_5038 = tbl16_interp(0x5038,0xc0,_speed_axis_index);
  return;
}


/* ----------------------------------------------------------------------------
 * angle_init
 * Address: 0xC0D562
 * Area:    application/04-engine-control/speed
 * Size:    104 bytes
 * -------------------------------------------------------------------------- */
/* c0d562 angle_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initialize angle/time conversion from calibration. */

void angle_init(void)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  _sensor_var_c224 = 0xd076;
  _sensor_var_c226 = 0xc0;
  bVar3 = 0;
  do {
    uVar1 = (ushort)bVar3;
    uVar2 = (ushort)bVar3;
    bVar3 = bVar3 + 1;
    bVar4 = (char)(*(ushort *)
                    ((uint3)(uVar1 * 2 + 0x5032) + (uint3)((0xafcd < uVar1 * 2) + 0xc0) * 0x10000) /
                  0x3c0) + 4;
    if (0x18 < bVar4) {
      bVar4 = bVar4 % 0x18;
    }
    *(byte *)(uint3)(uVar2 + 0xc382) = bVar4;
  } while (bVar3 < 2);
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


/* ============================== Engine control / load ============================== */

/* ----------------------------------------------------------------------------
 * calc_load
 * Address: 0xC1FD9C
 * Area:    application/04-engine-control/load
 * Size:    322 bytes
 * -------------------------------------------------------------------------- */
/* c1fd9c calc_load */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calibration-based load calculation; uses tables 0x7564/0x794A/0x79B6. */

void calc_load(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  
  if ((DAT_e0089e == '\x02') || (ram_var_ca37 != '\0')) {
    _DAT_e008a8 = 0;
  }
  else {
    if (DAT_e0081b == '\0') {
      uVar1 = axis16_unsigned((short)&axis_engine_speed,_engine_speed_input);
      uVar2 = axis16_unsigned((short)&axis_load,_calc_input_y);
      uVar3 = tbl2d_interp(0x794a,0xc0,uVar1,uVar2);
      uVar4 = tbl8_interp(0x79b6,0xc0,_calc_input_correction);
      _load_calc_result =
           (ushort)((uint)uVar3 * (uint)uVar4) >> 0xf |
           (short)((uint)uVar3 * (uint)uVar4 >> 0x10) << 1;
    }
    else {
      _load_calc_result = 0;
    }
    if (_DAT_e008a8 < _load_calc_result) {
      uVar1 = axis16_unsigned((short)&axis_load,_calc_input_y);
      uVar1 = tbl8_interp(0x79aa,0xc0,uVar1);
      _DAT_e008a8 = rate_limit(_DAT_e008a8,_load_calc_result,uVar1);
    }
    else if ((ram_var_c604 != '\0') || (uVar1 = cal_limit_flag, cal_calc_variant != '\x01')) {
      uVar1 = axis16_unsigned((short)&axis_engine_speed,_engine_speed_input);
      uVar1 = tbl8_interp(0x799e,0xc0,uVar1);
    }
    if (_load_calc_result <= _DAT_e008a8) {
      _DAT_e008a8 = rate_limit(_load_calc_result,uVar1);
    }
  }
  return;
}


/* ============================== Engine control / limits ============================== */

/* ----------------------------------------------------------------------------
 * rate_limit
 * Address: 0xC1596E
 * Area:    application/04-engine-control/limits
 * Size:    78 bytes
 * -------------------------------------------------------------------------- */
/* c1596e rate_limit */

/* Rate limiter / slew helper. */

ushort rate_limit(ushort param_1,ushort param_2,ushort param_3)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = param_1;
  if ((param_2 != param_1) && (param_3 != 0)) {
    if (param_1 < param_2) {
      sVar1 = (short)((uint)(param_2 - param_1) * (uint)param_3 >> 0x10);
    }
    else {
      sVar1 = -(short)((uint)(param_1 - param_2) * (uint)param_3 >> 0x10);
    }
    uVar2 = param_1 + sVar1;
    if (uVar2 == param_1) {
      if (param_1 < param_2) {
        uVar2 = uVar2 + 1;
      }
      else {
        uVar2 = uVar2 - 1;
      }
    }
  }
  return uVar2;
}


/* ----------------------------------------------------------------------------
 * calc_limit1
 * Address: 0xC200AA
 * Area:    application/04-engine-control/limits
 * Size:    260 bytes
 * -------------------------------------------------------------------------- */
/* c200aa calc_limit1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calibration-based limit calculation (table 0x7912). */

void calc_limit1(void)

{
  if ((engine_state == '\x04') || (engine_state == '\x01')) {
    calc_limit3();
  }
  else if (DAT_e0085b == '\0') {
    if (((engine_state == '\x03') && (limit_flag_2 = 1, _limit_value_4 <= _limit_counter_c)) &&
       ((0x80 < _limit_value_0 || (0x80 < _limit_value_2)))) {
      limit_flag_2 = 0;
      _limit_counter_c = 0;
      _limit_value_0 = (ushort)((uint)_limit_value_0 * (uint)cal_pwm_scale >> 0x10);
      if (_limit_value_0 < 0x81) {
        _limit_value_0 = 0;
      }
      if ((DAT_e00822 != '\0') &&
         (_limit_value_2 = (ushort)((uint)_limit_value_2 * (uint)_limit_value_3 >> 0x10),
         _limit_value_2 < 0x81)) {
        _limit_value_2 = 0;
      }
      _limit_value_4 = tbl16_interp(0x7912,0xc0,_calc_input_correction);
    }
  }
  else {
    _limit_value_2 = 0x8000;
  }
  if (_limit_value_0 < _limit_value_2) {
    _limit_value_2 = _limit_value_0;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * calc_limit2
 * Address: 0xC201AE
 * Area:    application/04-engine-control/limits
 * Size:    320 bytes
 * -------------------------------------------------------------------------- */
/* c201ae calc_limit2 */

/* WARNING: Removing unreachable block (ram,0xc201fa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calibration-based limit calculation (tables 0x7860/0x784C). */

void calc_limit2(void)

{
  undefined2 uVar1;
  
  if (DAT_e0085b != '\0') {
    _limit_value_5 = 0;
    _limit_value_1 = 0;
    return;
  }
  if (engine_state == '\x03') {
    limit_flag_1 = 1;
    if ((0x80 < _limit_value_1) && (cal_limit_count <= _limit_counter_b)) {
      limit_flag_1 = 0;
      _limit_counter_b = 0;
      _limit_value_1 = (ushort)((uint)_limit_value_1 * (uint)cal_limit_multiplier >> 0x10);
      if (_limit_value_1 < 0x81) {
        _limit_value_1 = 0;
      }
    }
  }
  else {
    limit_flag_1 = 0;
    _limit_counter_b = 0;
    _limit_value_1 = tbl8_interp(0x7860,0xc0,_calc_input_correction);
  }
  if (engine_state != '\x03') {
    _limit_counter_a = 0;
    _limit_value_5 = 0;
    return;
  }
  if ((_engine_speed_input < cal_speed_limit_threshold) ||
     (limit_flag_0 = 1, _limit_counter_a < cal_limit_counter_threshold)) {
    speed_limit_active = '\0';
  }
  else {
    limit_flag_0 = 0;
    speed_limit_active = '\x01';
  }
  uVar1 = _calc_input_x;
  if (speed_limit_active == '\0') {
    uVar1 = cal_limit_fallback_speed;
  }
  uVar1 = axis16_unsigned((short)&axis_limit_2,uVar1);
  _limit_value_5 = tbl8_interp(0x784c,0xc0,uVar1);
  return;
}


/* ----------------------------------------------------------------------------
 * calc_limit3
 * Address: 0xC202EE
 * Area:    application/04-engine-control/limits
 * Size:    170 bytes
 * -------------------------------------------------------------------------- */
/* c202ee calc_limit3 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calibration-based limit calculation (tables 0x7552/0x7912/0x78E2). */

void calc_limit3(void)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar1 = axis16_signed((short)&axis_limit_3,_calc_input_z);
  _limit_value_4 = tbl16_interp(0x7912,0xc0,uVar1);
  _limit_value_3 = tbl8_interp(0x78e2,0xc0,uVar1);
  uVar2 = tbl8_interp(0x7874,0xc0,uVar1);
  uVar1 = axis16_unsigned((short)&axis_limit_3_alt,_calc_input_w);
  uVar3 = tbl8_interp(0x78d8,0xc0,uVar1);
  _limit_value_2 =
       (ushort)((uint)uVar2 * (uint)uVar3) >> 0xd | (short)((uint)uVar2 * (uint)uVar3 >> 0x10) << 3;
  if (0x8000 < _limit_value_2) {
    _limit_value_2 = 0x8000;
  }
  _limit_value_0 = _limit_value_2;
  return;
}


/* ============================== Engine control / sensor ============================== */

/* ----------------------------------------------------------------------------
 * config_sensor_setup
 * Address: 0xC0F628
 * Area:    application/04-engine-control/sensor
 * Size:    532 bytes
 * -------------------------------------------------------------------------- */
/* c0f628 config_sensor_setup */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Selects sensor/ADC handler pointers from calibration config 0xC05036 and builds a float
   threshold. */

void config_sensor_setup(void)

{
  undefined2 in_r1;
  byte bVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  uVar3 = test_status;
  test_status = uVar3 & 0xfffe;
  uVar3 = test_status;
  test_status = uVar3 & 0xfffd;
  bVar1 = (byte)((ushort)in_r1 >> 8);
  if (cal_config_selector < 4) {
    _sensor_var_c23c = 0xd09a;
    _sensor_var_c23e = 0xc0;
    _sensor_var_c22c = 0xd07c;
    _sensor_var_c22e = 0xc0;
    _sensor_var_c234 = 0xd08e;
    _sensor_var_c236 = 0xc0;
    _sensor_setup = 0xd0b2;
    _sensor_var_c222 = 0xc0;
    sensor_channel_count = 2;
    _sensor_var_c238 = 0xd0a0;
    _sensor_var_c23a = 0xc0;
    _sensor_var_c228 = 0xd082;
    _sensor_var_c22a = 0xc0;
    _sensor_var_c230 = 0xd094;
    _sensor_var_c232 = 0xc0;
    if (cal_config_selector == 2) {
      uVar3 = CONCAT11(bVar1,0x5a);
      _sensor_cfg_flag_2 = _sensor_cfg_flag_2 | 0x200;
      sVar4 = (short)&sensor_coeff_table_2;
      _capture_irq_mask = _capture_irq_mask | 0x204;
    }
    else if (cal_config_selector == 3) {
      uVar3 = CONCAT11(bVar1,0x3c);
      _capture_enable = _capture_enable | 0x200;
      _sensor_cfg_flag_1 = _sensor_cfg_flag_1 | 0x200;
      sVar4 = (short)&sensor_coeff_table_1;
      _capture_irq_mask = _capture_irq_mask | 4;
    }
    else if (cal_config_selector == 0) {
      uVar3 = CONCAT11(bVar1,0xb4);
      _sensor_cfg_flag_3 = _sensor_cfg_flag_3 | 0x200;
      _sensor_cfg_flag_4 = _sensor_cfg_flag_4 | 0x200;
      sVar4 = (short)&sensor_coeff_table_3;
      _capture_irq_mask = _capture_irq_mask | 0x204;
    }
    else {
      uVar3 = (ushort)bVar1 << 8;
      sVar4 = (short)&sensor_coeff_table_0;
      _capture_irq_mask = _capture_irq_mask | 4;
    }
    _capture_irq_mask_2 = _capture_irq_mask_2 | 0x200;
    _sensor_setup_flag = 0;
    fp_load(CONCAT11((char)(uVar3 >> 8),(char)((uVar3 & 0xff) / 0xf)));
    fp_neg();
    sVar2 = fp_compare();
    if (sVar2 == -1) {
      fp_load();
      fp_neg();
      fp_div_signed();
      fp_copy();
    }
    else {
      fp_neg();
      fp_load();
      fp_div_unsigned();
      fp_copy();
    }
    uVar3 = fp_to_int();
    uVar3 = (uVar3 & 0xff) * 2 + 0xc282;
    bVar1 = 0;
    *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfff7 | 8;
    do {
      sVar2 = (ushort)bVar1 * 2;
      bVar1 = bVar1 + 1;
      *(undefined1 *)(uint3)(ushort)((short)&sensor_coefficients + sVar2) =
           *(undefined1 *)(uint3)(ushort)(sVar4 + sVar2);
      *(undefined1 *)(uint3)(sVar2 + 0xc469) = *(undefined1 *)(uint3)(ushort)(sVar4 + 1 + sVar2);
    } while (bVar1 < 5);
    for (bVar1 = 0; bVar1 < sensor_channel_count; bVar1 = bVar1 + 1) {
      *(undefined1 *)(uint3)((ushort)bVar1 * 0x1a + 0xc3da) = 0;
      *(undefined1 *)(uint3)((ushort)bVar1 * 0x1a + 0xc3d9) = 0;
    }
    cc22_23_output_init();
    cc_control_ptr_init();
  }
  output_gate_0 = 0x4800;
  output_gate_1 = 0x4800;
  cc_output_gate_update();
  cc22_23_started = 0;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  return;
}


/* ============================== Runtime library ============================== */

/* ----------------------------------------------------------------------------
 * memcpy_wdt
 * Address: 0xC01D9A
 * Area:    application/05-runtime-lib
 * Size:    40 bytes
 * -------------------------------------------------------------------------- */
/* c01d9a memcpy_wdt */

/* Byte copy with watchdog service. */

void memcpy_wdt(ushort param_1,ushort param_2,ushort param_3,ushort param_4,ushort unaff_00000000)

{
  bool bVar1;
  ushort uVar2;
  
  for (uVar2 = 0; uVar2 < unaff_00000000; uVar2 = uVar2 + 1) {
    *(undefined1 *)((uint3)param_1 + (uint3)param_2 * 0x10000) =
         *(undefined1 *)((uint3)param_3 + (uint3)param_4 * 0x10000);
    bVar1 = 0xfffe < param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + bVar1;
    bVar1 = 0xfffe < param_3;
    param_3 = param_3 + 1;
    param_4 = param_4 + bVar1;
    __service_watchdog();
  }
  return;
}


/* ----------------------------------------------------------------------------
 * ret_stub
 * Address: 0xC01EC8
 * Area:    application/05-runtime-lib
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c01ec8 ret_stub */

/* Empty function. */

void ret_stub(void)

{
  return;
}


/* ----------------------------------------------------------------------------
 * mem_read_word
 * Address: 0xC01ECE
 * Area:    application/05-runtime-lib
 * Size:    14 bytes
 * -------------------------------------------------------------------------- */
/* c01ece mem_read_word */

/* Read two words through a 16:16 pointer. */

void mem_read_word(void)

{
  return;
}


/* ----------------------------------------------------------------------------
 * mem_write_word
 * Address: 0xC01EDC
 * Area:    application/05-runtime-lib
 * Size:    14 bytes
 * -------------------------------------------------------------------------- */
/* c01edc mem_write_word */

/* Write two words through a 16:16 pointer. */

void mem_write_word(void)

{
  ushort in_r4;
  ushort in_r5;
  undefined2 in_r10;
  undefined2 in_r11;
  
  *(undefined2 *)((uint3)in_r4 + (uint3)in_r5 * 0x10000) = in_r10;
  *(undefined2 *)((uint3)(in_r4 + 2) + (uint3)(in_r5 + (0xfffd < in_r4)) * 0x10000) = in_r11;
  return;
}


/* ----------------------------------------------------------------------------
 * seg_to_ptr
 * Address: 0xC01EEA
 * Area:    application/05-runtime-lib
 * Size:    22 bytes
 * -------------------------------------------------------------------------- */
/* c01eea seg_to_ptr */

/* Convert 16-bit pointer/DPP offset into a 24-bit pointer. */

undefined4 seg_to_ptr(void)

{
  ushort uVar1;
  ushort in_r4;
  
  uVar1 = *(ushort *)(uint3)((in_r4 >> 0xe) * 2 - 0x200);
  return CONCAT22(uVar1 >> 2,in_r4 & 0x3fff | (uVar1 & 1) << 0xe | ((uVar1 & 2) >> 1) << 0xf);
}


/* ----------------------------------------------------------------------------
 * empty_stub_1
 * Address: 0xC0BFF4
 * Area:    application/05-runtime-lib
 * Size:    2 bytes
 * -------------------------------------------------------------------------- */
/* c0bff4 empty_stub_1 */

/* Empty function. */

void empty_stub_1(void)

{
  return;
}


/* ----------------------------------------------------------------------------
 * empty_stub_2
 * Address: 0xC0BFF6
 * Area:    application/05-runtime-lib
 * Size:    2 bytes
 * -------------------------------------------------------------------------- */
/* c0bff6 empty_stub_2 */

/* Empty function. */

void empty_stub_2(void)

{
  return;
}


/* ----------------------------------------------------------------------------
 * empty_stub_3
 * Address: 0xC10240
 * Area:    application/05-runtime-lib
 * Size:    2 bytes
 * -------------------------------------------------------------------------- */
/* c10240 empty_stub_3 */

/* Empty function. */

void empty_stub_3(void)

{
  return;
}


/* ----------------------------------------------------------------------------
 * div32_checked
 * Address: 0xC1096E
 * Area:    application/05-runtime-lib
 * Size:    52 bytes
 * -------------------------------------------------------------------------- */
/* c1096e div32_checked */

/* Checked 32-bit division; returns 0xFFFFFFFF on overflow/zero. */

undefined4 div32_checked(short param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != 0) &&
     (uVar2 = div32u(), sVar1 = (short)((uint)uVar2 >> 0x10),
     sVar1 == -1 && (sVar1 != -1 || (short)uVar2 == -1))) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


/* ----------------------------------------------------------------------------
 * mul_div32
 * Address: 0xC109A2
 * Area:    application/05-runtime-lib
 * Size:    24 bytes
 * -------------------------------------------------------------------------- */
/* c109a2 mul_div32 */

/* 32-bit multiply followed by checked division. */

void mul_div32(void)

{
  mul32();
  div32u();
  return;
}


/* ----------------------------------------------------------------------------
 * mul32
 * Address: 0xC28B64
 * Area:    application/05-runtime-lib
 * Size:    36 bytes
 * -------------------------------------------------------------------------- */
/* c28b64 mul32 */

/* 32x16/32-bit multiply helper. */

undefined4 mul32(void)

{
  ushort in_r4;
  short in_r5;
  ushort in_r10;
  short in_r11;
  
  __atomic(2);
  __atomic(2);
  __atomic(2);
  return CONCAT22(in_r5 * in_r10 + in_r4 * in_r11 + (short)((uint)in_r4 * (uint)in_r10 >> 0x10),
                  (short)((uint)in_r4 * (uint)in_r10));
}


/* ----------------------------------------------------------------------------
 * div32u
 * Address: 0xC28BB2
 * Area:    application/05-runtime-lib
 * Size:    148 bytes
 * -------------------------------------------------------------------------- */
/* c28bb2 div32u */

/* 32-bit unsigned division helper. */

uint div32u(void)

{
  uint uVar1;
  int iVar2;
  short sVar4;
  ushort in_r2;
  short sVar5;
  ushort in_r4;
  ushort uVar6;
  ushort in_r5;
  ushort uVar7;
  ushort in_r10;
  ushort in_r11;
  ushort uVar8;
  ushort uVar3;
  
  if (in_r11 != 0) {
    sVar5 = LZCOUNT(in_r11);
    if (sVar5 == 0) {
      uVar7 = 0;
      uVar6 = in_r5;
      uVar8 = in_r11;
    }
    else {
      sVar4 = -sVar5;
      uVar7 = in_r5 >> sVar4;
      uVar6 = in_r4 >> sVar4 | in_r5 << sVar5;
      uVar8 = in_r11 << sVar5 | in_r10 >> sVar4;
    }
    __atomic(4);
    uVar1 = CONCAT22(uVar7,uVar6) / (uint)uVar8;
    uVar6 = (ushort)uVar1;
    __atomic(2);
    __atomic(2);
    iVar2 = (uVar1 & 0xffff) * (uint)in_r10;
    uVar8 = (ushort)iVar2;
    uVar3 = (ushort)((uint)iVar2 >> 0x10);
    uVar7 = uVar6 * in_r11 + uVar3;
    if ((CARRY2(uVar6 * in_r11,uVar3)) ||
       ((uVar7 - in_r2 != (ushort)(uVar8 < in_r5) || uVar8 != in_r5) &&
        (in_r2 <= uVar7 && (uVar7 != in_r2 || uVar8 >= in_r5)))) {
      uVar6 = uVar6 - 1;
    }
    return (uint)uVar6;
  }
  __atomic(4);
  __atomic(4);
  return CONCAT22(in_r5 / in_r10,
                  (short)(((uint)in_r4 | (uint)in_r5 % (uint)in_r10 << 0x10) / (uint)in_r10));
}


/* ----------------------------------------------------------------------------
 * empty_stub_0
 * Address: 0xC28C4E
 * Area:    application/05-runtime-lib
 * Size:    6 bytes
 * -------------------------------------------------------------------------- */
/* c28c4e empty_stub_0 */

/* Empty function. */

void empty_stub_0(void)

{
  return;
}


/* ----------------------------------------------------------------------------
 * store32
 * Address: 0xC28C62
 * Area:    application/05-runtime-lib
 * Size:    14 bytes
 * -------------------------------------------------------------------------- */
/* c28c62 store32 */

/* Stores a 32-bit value as two 16-bit words. */

void store32(void)

{
  ushort in_r4;
  ushort in_r5;
  undefined2 in_r10;
  undefined2 in_r11;
  
  *(undefined2 *)((uint3)in_r4 + (uint3)in_r5 * 0x10000) = in_r10;
  *(undefined2 *)((uint3)(in_r4 + 2) + (uint3)(in_r5 + (0xfffd < in_r4)) * 0x10000) = in_r11;
  return;
}


/* ----------------------------------------------------------------------------
 * fp_div_signed
 * Address: 0xC28CA4
 * Area:    application/05-runtime-lib
 * Size:    28 bytes
 * -------------------------------------------------------------------------- */
/* c28ca4 fp_div_signed */

/* Software float division with sign handling. */

void fp_div_signed(ushort param_1,ushort param_2,ushort param_3)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  ushort extraout_r1;
  ushort uVar6;
  ushort extraout_r2;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort unaff_r6;
  ushort uVar10;
  ushort unaff_r7;
  ushort uVar11;
  ushort unaff_r8;
  ushort unaff_r9;
  ushort uVar12;
  ushort in_r11;
  undefined4 uVar13;
  
  *(ushort *)(uint3)in_r11 =
       *(ushort *)(uint3)in_r11 & 0x7fff | (*(ushort *)(uint3)in_r11 >> 0xf ^ 1) << 0xf;
  uVar13 = fp_pack();
  uVar4 = (uint)uVar13 >> 0x10;
  if ((extraout_r2 != 0) && (extraout_r1 != 0)) {
    uVar6 = extraout_r1;
    uVar7 = extraout_r2;
    uVar10 = unaff_r6;
    uVar11 = unaff_r8;
    uVar12 = unaff_r9;
    if (extraout_r1 < extraout_r2) {
      uVar13 = CONCAT22(param_3,((ushort)uVar13 & 0xfffb | ((ushort)uVar13 & 1) << 2) >> 1);
      uVar6 = extraout_r2;
      uVar7 = extraout_r1;
      uVar10 = unaff_r7;
      unaff_r7 = unaff_r6;
      uVar11 = param_1;
      uVar12 = param_2;
      param_1 = unaff_r8;
      param_2 = unaff_r9;
      param_3 = (ushort)uVar4;
    }
    uVar9 = (ushort)((uint)uVar13 >> 0x10);
    uVar8 = 0;
    sVar3 = uVar7 - uVar6;
    if (sVar3 != 0) {
      uVar6 = -sVar3;
      uVar7 = uVar10;
      uVar10 = param_1;
      param_1 = param_2;
      if (sVar3 != -0x35 && 0x34 < (ushort)-sVar3) goto LAB_c28c92;
      while (param_2 = param_1, param_1 = uVar10, uVar10 = uVar7, 0xf < (short)uVar6) {
        uVar6 = uVar6 - 0x10;
        uVar8 = param_3;
        uVar7 = 0;
        param_3 = param_2;
      }
      if (uVar6 != 0) {
        uVar8 = uVar8 >> uVar6 | param_3 << -uVar6;
        param_3 = param_3 >> uVar6 | param_2 << -uVar6;
        param_2 = param_2 >> uVar6 | param_1 << -uVar6;
        param_1 = param_1 >> uVar6 | uVar10 << -uVar6;
        uVar10 = uVar10 >> uVar6;
      }
    }
    if (!(bool)((byte)(((ushort)uVar13 & 2) >> 1) ^ (byte)uVar13 & 1)) {
      fp_round();
      return;
    }
    uVar5 = -uVar8;
    bVar1 = uVar9 < param_3 || uVar9 == param_3 && uVar8 != 0;
    uVar8 = (uVar9 - param_3) - (ushort)(uVar8 != 0);
    bVar2 = uVar12 < param_2 || uVar12 == param_2 && bVar1;
    uVar6 = (uVar12 - param_2) - (ushort)bVar1;
    bVar1 = uVar11 < param_1 || uVar11 == param_1 && bVar2;
    uVar7 = (uVar11 - param_1) - (ushort)bVar2;
    uVar11 = (unaff_r7 - uVar10) - (ushort)bVar1;
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0)))) {
      fp_store_zero();
      return;
    }
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0))) ||
        (unaff_r7 < uVar10 || unaff_r7 == uVar10 && bVar1)) {
      uVar9 = ~uVar7;
      uVar10 = (ushort)(0xfffe < ~uVar5);
      uVar7 = (ushort)CARRY2(~uVar8,uVar10);
      uVar12 = (ushort)CARRY2(~uVar6,uVar7);
      uVar6 = ~uVar6 + uVar7;
      uVar7 = uVar9 + uVar12;
      uVar11 = ~uVar11 + (ushort)CARRY2(uVar9,uVar12);
      uVar5 = ~uVar5 + 1;
      uVar8 = ~uVar8 + uVar10;
    }
    while( true ) {
      while (uVar10 = uVar8, uVar8 = uVar5, uVar11 == 0 && uVar7 == 0) {
        uVar5 = 0;
        uVar7 = uVar6;
        uVar6 = uVar10;
      }
      if ((uVar11 & 0x10) != 0) break;
      uVar12 = (ushort)(CARRY2(uVar10,uVar10) || CARRY2(uVar10 * 2,(ushort)CARRY2(uVar8,uVar8)));
      uVar9 = (ushort)(CARRY2(uVar6,uVar6) || CARRY2(uVar6 * 2,uVar12));
      uVar6 = uVar6 * 2 + uVar12;
      uVar12 = uVar7 * 2;
      bVar1 = CARRY2(uVar7,uVar7);
      uVar7 = uVar7 * 2 + uVar9;
      uVar11 = uVar11 * 2 + (ushort)(bVar1 || CARRY2(uVar12,uVar9));
      uVar5 = uVar8 * 2;
      uVar8 = uVar10 * 2 + (ushort)CARRY2(uVar8,uVar8);
    }
    fp_round();
    return;
  }
LAB_c28c92:
  fp_store();
  return;
}


/* ----------------------------------------------------------------------------
 * fp_div_unsigned
 * Address: 0xC28CAC
 * Area:    application/05-runtime-lib
 * Size:    274 bytes
 * -------------------------------------------------------------------------- */
/* c28cac fp_div_unsigned */

/* Software float division helper. */

void fp_div_unsigned(ushort param_1,ushort param_2,ushort param_3)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  ushort extraout_r1;
  ushort uVar6;
  ushort extraout_r2;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort unaff_r6;
  ushort uVar10;
  ushort unaff_r7;
  ushort uVar11;
  ushort unaff_r8;
  ushort unaff_r9;
  ushort uVar12;
  undefined4 uVar13;
  
  uVar13 = fp_pack();
  uVar4 = (uint)uVar13 >> 0x10;
  if ((extraout_r2 != 0) && (extraout_r1 != 0)) {
    uVar6 = extraout_r1;
    uVar7 = extraout_r2;
    uVar10 = unaff_r6;
    uVar11 = unaff_r8;
    uVar12 = unaff_r9;
    if (extraout_r1 < extraout_r2) {
      uVar13 = CONCAT22(param_3,((ushort)uVar13 & 0xfffb | ((ushort)uVar13 & 1) << 2) >> 1);
      uVar6 = extraout_r2;
      uVar7 = extraout_r1;
      uVar10 = unaff_r7;
      unaff_r7 = unaff_r6;
      uVar11 = param_1;
      uVar12 = param_2;
      param_1 = unaff_r8;
      param_2 = unaff_r9;
      param_3 = (ushort)uVar4;
    }
    uVar9 = (ushort)((uint)uVar13 >> 0x10);
    uVar8 = 0;
    sVar3 = uVar7 - uVar6;
    if (sVar3 != 0) {
      uVar6 = -sVar3;
      uVar7 = uVar10;
      uVar10 = param_1;
      param_1 = param_2;
      if (sVar3 != -0x35 && 0x34 < (ushort)-sVar3) goto LAB_c28c92;
      while (param_2 = param_1, param_1 = uVar10, uVar10 = uVar7, 0xf < (short)uVar6) {
        uVar6 = uVar6 - 0x10;
        uVar8 = param_3;
        uVar7 = 0;
        param_3 = param_2;
      }
      if (uVar6 != 0) {
        uVar8 = uVar8 >> uVar6 | param_3 << -uVar6;
        param_3 = param_3 >> uVar6 | param_2 << -uVar6;
        param_2 = param_2 >> uVar6 | param_1 << -uVar6;
        param_1 = param_1 >> uVar6 | uVar10 << -uVar6;
        uVar10 = uVar10 >> uVar6;
      }
    }
    if (!(bool)((byte)(((ushort)uVar13 & 2) >> 1) ^ (byte)uVar13 & 1)) {
      fp_round();
      return;
    }
    uVar5 = -uVar8;
    bVar1 = uVar9 < param_3 || uVar9 == param_3 && uVar8 != 0;
    uVar8 = (uVar9 - param_3) - (ushort)(uVar8 != 0);
    bVar2 = uVar12 < param_2 || uVar12 == param_2 && bVar1;
    uVar6 = (uVar12 - param_2) - (ushort)bVar1;
    bVar1 = uVar11 < param_1 || uVar11 == param_1 && bVar2;
    uVar7 = (uVar11 - param_1) - (ushort)bVar2;
    uVar11 = (unaff_r7 - uVar10) - (ushort)bVar1;
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0)))) {
      fp_store_zero();
      return;
    }
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0))) ||
        (unaff_r7 < uVar10 || unaff_r7 == uVar10 && bVar1)) {
      uVar9 = ~uVar7;
      uVar10 = (ushort)(0xfffe < ~uVar5);
      uVar7 = (ushort)CARRY2(~uVar8,uVar10);
      uVar12 = (ushort)CARRY2(~uVar6,uVar7);
      uVar6 = ~uVar6 + uVar7;
      uVar7 = uVar9 + uVar12;
      uVar11 = ~uVar11 + (ushort)CARRY2(uVar9,uVar12);
      uVar5 = ~uVar5 + 1;
      uVar8 = ~uVar8 + uVar10;
    }
    while( true ) {
      while (uVar10 = uVar8, uVar8 = uVar5, uVar11 == 0 && uVar7 == 0) {
        uVar5 = 0;
        uVar7 = uVar6;
        uVar6 = uVar10;
      }
      if ((uVar11 & 0x10) != 0) break;
      uVar12 = (ushort)(CARRY2(uVar10,uVar10) || CARRY2(uVar10 * 2,(ushort)CARRY2(uVar8,uVar8)));
      uVar9 = (ushort)(CARRY2(uVar6,uVar6) || CARRY2(uVar6 * 2,uVar12));
      uVar6 = uVar6 * 2 + uVar12;
      uVar12 = uVar7 * 2;
      bVar1 = CARRY2(uVar7,uVar7);
      uVar7 = uVar7 * 2 + uVar9;
      uVar11 = uVar11 * 2 + (ushort)(bVar1 || CARRY2(uVar12,uVar9));
      uVar5 = uVar8 * 2;
      uVar8 = uVar10 * 2 + (ushort)CARRY2(uVar8,uVar8);
    }
    fp_round();
    return;
  }
LAB_c28c92:
  fp_store();
  return;
}


/* ----------------------------------------------------------------------------
 * fp_to_int
 * Address: 0xC28DBE
 * Area:    application/05-runtime-lib
 * Size:    50 bytes
 * -------------------------------------------------------------------------- */
/* c28dbe fp_to_int */

/* Software float to integer conversion. */

ushort fp_to_int(void)

{
  short sVar1;
  ushort extraout_r1;
  ushort uVar2;
  short unaff_r7;
  ushort unaff_r8;
  
  uVar2 = fp_pack_zero();
  if (((uVar2 & 1) == 0) && (0x3fe < extraout_r1)) {
    sVar1 = (short)&UNK_00fbf2 + extraout_r1;
    if (sVar1 == 0 || extraout_r1 < 0x40e) {
      uVar2 = (unaff_r7 << 0xb | unaff_r8 >> 5) >> -sVar1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* ----------------------------------------------------------------------------
 * fp_neg
 * Address: 0xC28DEC
 * Area:    application/05-runtime-lib
 * Size:    82 bytes
 * -------------------------------------------------------------------------- */
/* c28dec fp_neg */

/* Software float negation/absolute-value helper. */

void fp_neg(void)

{
  short in_r4;
  undefined1 auStack_2 [2];
  
  *(short *)ZEXT23(auStack_2) = -(in_r4 >> 0xf);
  if (-(in_r4 >> 0xf) != 0) {
    in_r4 = -in_r4;
  }
  if (in_r4 == 0) {
    *(undefined2 *)ZEXT23(auStack_2) = 0;
    fp_store_zero();
  }
  else {
    *(undefined2 *)ZEXT23(auStack_2) = 0;
    fp_store();
  }
  return;
}


/* ----------------------------------------------------------------------------
 * fp_compare
 * Address: 0xC28E50
 * Area:    application/05-runtime-lib
 * Size:    68 bytes
 * -------------------------------------------------------------------------- */
/* c28e50 fp_compare */

/* Software float comparison. */

ushort fp_compare(void)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort in_r10;
  ushort in_r11;
  
  uVar2 = *(ushort *)(uint3)in_r10;
  uVar3 = *(ushort *)(uint3)in_r11;
  if (((uVar2 | uVar3) & 0x7ff0) == 0) {
    return 0;
  }
  uVar4 = (short)uVar2 >> 0xf | 1;
  if ((!(bool)(((byte)(uVar2 >> 8) & 0x80 ^ (byte)(uVar3 >> 8) & 0x80) >> 7)) && (uVar2 <= uVar3)) {
    if (uVar3 <= uVar2) {
      uVar2 = *(ushort *)(uint3)(in_r10 + 2);
      bVar1 = *(ushort *)(in_r11 + 2) <= uVar2;
      if (uVar2 != *(ushort *)(in_r11 + 2) && bVar1) {
        return uVar4;
      }
      if (bVar1) {
        uVar2 = *(ushort *)(uint3)(in_r10 + 4);
        bVar1 = *(ushort *)(in_r11 + 4) <= uVar2;
        if (uVar2 != *(ushort *)(in_r11 + 4) && bVar1) {
          return uVar4;
        }
        if (bVar1) {
          uVar2 = *(ushort *)(uint3)(in_r10 + 6);
          bVar1 = *(ushort *)(in_r11 + 6) <= uVar2;
          if (uVar2 != *(ushort *)(in_r11 + 6) && bVar1) {
            return uVar4;
          }
          if (bVar1) {
            return 0;
          }
        }
      }
    }
    uVar4 = -uVar4;
  }
  return uVar4;
}


/* ----------------------------------------------------------------------------
 * fp_pack
 * Address: 0xC28E94
 * Area:    application/05-runtime-lib
 * Size:    62 bytes
 * -------------------------------------------------------------------------- */
/* c28e94 fp_pack */

/* Packs a software float into four 16-bit words. */

undefined4 fp_pack(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort in_r4;
  undefined2 unaff_r6;
  undefined2 unaff_r7;
  undefined2 unaff_r8;
  undefined2 unaff_r9;
  ushort in_r10;
  ushort in_r11;
  
  *(undefined2 *)(uint3)(in_r11 + 6) = param_3;
  *(undefined2 *)(uint3)(in_r11 + 4) = param_2;
  *(undefined2 *)(uint3)(in_r11 + 2) = param_1;
  uVar1 = *(ushort *)(uint3)in_r11;
  *(undefined2 *)(uint3)in_r11 = unaff_r6;
  uVar3 = PSW;
  uVar3 = *(undefined2 *)(uint3)(in_r10 + 6);
  *(undefined2 *)(uint3)(in_r10 + 6) = 1;
  *(undefined2 *)(uint3)(in_r10 + 4) = unaff_r9;
  *(undefined2 *)(uint3)(in_r10 + 2) = unaff_r8;
  uVar2 = *(ushort *)(uint3)in_r10;
  *(undefined2 *)(uint3)in_r10 = unaff_r7;
  uVar4 = PSW;
  return CONCAT22(uVar3,in_r4 & 0xfffc | (uVar1 >> 0xf) << 1 | uVar2 >> 0xf);
}


/* ----------------------------------------------------------------------------
 * fp_pack_zero
 * Address: 0xC28ED2
 * Area:    application/05-runtime-lib
 * Size:    56 bytes
 * -------------------------------------------------------------------------- */
/* c28ed2 fp_pack_zero */

/* Packs a zero software float. */

undefined4 fp_pack_zero(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort in_r4;
  undefined2 unaff_r7;
  undefined2 unaff_r8;
  undefined2 unaff_r9;
  ushort in_r10;
  
  uVar2 = *(undefined2 *)(uint3)(in_r10 + 6);
  *(undefined2 *)(uint3)(in_r10 + 6) = 0;
  *(undefined2 *)(uint3)(in_r10 + 4) = unaff_r9;
  *(undefined2 *)(uint3)(in_r10 + 2) = unaff_r8;
  uVar1 = *(ushort *)(uint3)in_r10;
  *(undefined2 *)(uint3)in_r10 = unaff_r7;
  uVar3 = PSW;
  return CONCAT22(uVar2,in_r4 & 0xfffe | uVar1 >> 0xf);
}


/* ----------------------------------------------------------------------------
 * fp_round
 * Address: 0xC28F0E
 * Area:    application/05-runtime-lib
 * Size:    16 bytes
 * -------------------------------------------------------------------------- */
/* c28f0e fp_round */

/* Rounds and stores a software float. */

void fp_round(void)

{
  bool bVar1;
  bool bVar2;
  ushort in_r1;
  ushort in_r3;
  short in_r4;
  ushort in_r5;
  ushort unaff_r7;
  ushort unaff_r8;
  ushort unaff_r9;
  ushort in_r10;
  
  if ((in_r3 & 0x8000) != 0) {
    bVar1 = 0xfffe < in_r5;
    in_r5 = in_r5 + 1;
    bVar2 = CARRY2(unaff_r9,(ushort)bVar1);
    unaff_r9 = unaff_r9 + bVar1;
    bVar1 = CARRY2(unaff_r8,(ushort)bVar2);
    unaff_r8 = unaff_r8 + bVar2;
    unaff_r7 = unaff_r7 + bVar1;
    if ((unaff_r7 & 0x20) != 0) {
      fp_store();
      return;
    }
  }
  *(ushort *)(uint3)(in_r10 + 6) = in_r5;
  *(ushort *)(uint3)(in_r10 + 4) = unaff_r9;
  *(ushort *)(uint3)(in_r10 + 2) = unaff_r8;
  *(ushort *)(uint3)in_r10 = unaff_r7 & 0xf | (in_r1 & 0x7ff) << 4 | in_r4 << 0xf;
  return;
}


/* ----------------------------------------------------------------------------
 * fp_store
 * Address: 0xC28F1E
 * Area:    application/05-runtime-lib
 * Size:    64 bytes
 * -------------------------------------------------------------------------- */
/* c28f1e fp_store */

/* Stores four words of a software float. */

void fp_store(void)

{
  ushort in_r1;
  short in_r4;
  undefined2 in_r5;
  ushort unaff_r7;
  undefined2 unaff_r8;
  undefined2 unaff_r9;
  ushort in_r10;
  
  *(undefined2 *)(uint3)(in_r10 + 6) = in_r5;
  *(undefined2 *)(uint3)(in_r10 + 4) = unaff_r9;
  *(undefined2 *)(uint3)(in_r10 + 2) = unaff_r8;
  *(ushort *)(uint3)in_r10 = unaff_r7 & 0xf | (in_r1 & 0x7ff) << 4 | in_r4 << 0xf;
  return;
}


/* ----------------------------------------------------------------------------
 * fp_store_zero
 * Address: 0xC28F5E
 * Area:    application/05-runtime-lib
 * Size:    14 bytes
 * -------------------------------------------------------------------------- */
/* c28f5e fp_store_zero */

/* Stores a zero software float. */

void fp_store_zero(void)

{
  fp_store();
  return;
}


/* ----------------------------------------------------------------------------
 * fp_load
 * Address: 0xC28F6C
 * Area:    application/05-runtime-lib
 * Size:    24 bytes
 * -------------------------------------------------------------------------- */
/* c28f6c fp_load */

/* Loads four words of a software float. */

void fp_load(void)

{
  ushort in_r4;
  undefined1 auStack_8 [2];
  undefined1 auStack_6 [2];
  undefined1 auStack_4 [2];
  undefined1 auStack_2 [2];
  
  *(undefined2 *)ZEXT23(auStack_8) = *(undefined2 *)(uint3)in_r4;
  *(undefined2 *)ZEXT23(auStack_6) = *(undefined2 *)(uint3)(in_r4 + 2);
  *(undefined2 *)ZEXT23(auStack_4) = *(undefined2 *)(uint3)(in_r4 + 4);
  *(undefined2 *)ZEXT23(auStack_2) = *(undefined2 *)(uint3)(in_r4 + 6);
  return;
}


/* ----------------------------------------------------------------------------
 * fp_copy
 * Address: 0xC28F84
 * Area:    application/05-runtime-lib
 * Size:    16 bytes
 * -------------------------------------------------------------------------- */
/* c28f84 fp_copy */

/* Copies four words of a software float. */

void fp_copy(void)

{
  ushort in_r4;
  ushort in_r10;
  
  *(undefined2 *)(uint3)in_r4 = *(undefined2 *)(uint3)in_r10;
  *(undefined2 *)(uint3)(in_r4 + 2) = *(undefined2 *)(uint3)(in_r10 + 2);
  *(undefined2 *)(uint3)(in_r4 + 4) = *(undefined2 *)(uint3)(in_r10 + 4);
  *(undefined2 *)(uint3)(in_r4 + 6) = *(undefined2 *)(uint3)(in_r10 + 6);
  return;
}

