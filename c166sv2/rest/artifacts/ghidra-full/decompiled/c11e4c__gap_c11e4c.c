// c11e4c gap_c11e4c size=20 cc=unknown proto=undefined gap_c11e4c(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c11e4c(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  byte bVar6;
  
  DAT_00c57a = 6;
  sVar5 = DAT_00c5a2;
  if (sVar5 == 0) {
    DAT_00c5be = 0;
  }
  while( true ) {
    diag_status_build();
    sVar5 = empty_stub_0();
    if (sVar5 != 0) {
      uVar4 = PSW;
      PSW = uVar4 & 0xf7ff;
      __disable_watchdog();
      if (_DAT_007096 != 0 || _DAT_007094 != 0) {
        empty_stub_0();
      }
      uVar4 = P1H;
      P1H = uVar4 & 0xfffb;
      __software_reset();
      return;
    }
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) break;
    __service_watchdog();
    uVar4 = DAT_00fd14;
    DAT_00fd14 = uVar4 & 0xfffb;
    cVar3 = DAT_00c54a;
    DAT_00c54a = cVar3 + '\x01';
    cc22_23_task();
    ssc_task();
    timeout_counter_tick();
    bVar6 = DAT_00c54a;
    if ((bVar6 & 1) != 0) {
      speed_timing_calc();
      uVar4 = DAT_00c962;
      if ((((uVar4 < 0x5800) || (0x6800 < uVar4)) || (sVar5 = DAT_00cb60, sVar5 != 0)) ||
         (cVar3 = DAT_00c280, cVar3 != '\0')) {
        DAT_00c5e6 = 0;
        bVar6 = DAT_00fd18._0_1_;
        DAT_00fd18._0_1_ = bVar6 & 0x80;
        DAT_00c5e8 = 0;
        DAT_00c5ea = 0;
      }
      else {
        DAT_00c5e6 = 1;
        test_command_dispatch(0);
      }
    }
    scheduler_tick();
    bVar6 = 0;
    do {
      pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar6 * 2);
      if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar6 * 2) != *pcVar2) {
        *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
        pbVar1 = *(byte **)(uint3)((ushort)bVar6 * 6 + 0x7088);
        if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
          *(undefined1 *)ZEXT23(pcVar2) = 0;
        }
        empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
      }
      bVar6 = bVar6 + 1;
    } while (bVar6 < 2);
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) {
      empty_stub_0();
    }
    else {
      uVar4 = DAT_00fd14;
      DAT_00fd14 = uVar4 | 0x10;
    }
    kline_transport_task(1);
    sVar5 = DAT_00c584;
    if (sVar5 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((sVar5 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
      return;
    }
  }
  app_scheduler();
  return;
}

