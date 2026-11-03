// c11e3c FUN_c11e3c size=60 cc=unknown proto=undefined FUN_c11e3c(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c11e3c(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  short sVar6;
  byte bVar7;
  
  do {
    uVar5 = Ram00f0ba;
    if (6 < (uVar5 & 0x3f00) >> 8) {
LAB_c11e78:
      sVar6 = DAT_00c5a2;
      if (sVar6 == 0) {
        DAT_00c5be = 0;
      }
      while( true ) {
        diag_status_build();
        sVar6 = empty_stub_0();
        if (sVar6 != 0) {
          uVar5 = PSW;
          PSW = uVar5 & 0xf7ff;
          __disable_watchdog();
          if (_DAT_007096 != 0 || _DAT_007094 != 0) {
            empty_stub_0();
          }
          uVar5 = P1H;
          P1H = uVar5 & 0xfffb;
          __software_reset();
          return;
        }
        uVar5 = DAT_00fd14;
        if ((uVar5 & 4) == 0) break;
        __service_watchdog();
        uVar5 = DAT_00fd14;
        DAT_00fd14 = uVar5 & 0xfffb;
        cVar3 = DAT_00c54a;
        DAT_00c54a = cVar3 + '\x01';
        cc22_23_task();
        ssc_task();
        timeout_counter_tick();
        bVar7 = DAT_00c54a;
        if ((bVar7 & 1) != 0) {
          speed_timing_calc();
          uVar5 = DAT_00c962;
          if ((((uVar5 < 0x5800) || (0x6800 < uVar5)) || (sVar6 = DAT_00cb60, sVar6 != 0)) ||
             (cVar3 = DAT_00c280, cVar3 != '\0')) {
            DAT_00c5e6 = 0;
            bVar7 = DAT_00fd18._0_1_;
            DAT_00fd18._0_1_ = bVar7 & 0x80;
            DAT_00c5e8 = 0;
            DAT_00c5ea = 0;
          }
          else {
            DAT_00c5e6 = 1;
            test_command_dispatch(0);
          }
        }
        scheduler_tick();
        bVar7 = 0;
        do {
          pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar7 * 2);
          if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar7 * 2) != *pcVar2) {
            *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
            pbVar1 = *(byte **)(uint3)((ushort)bVar7 * 6 + 0x7088);
            if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
              *(undefined1 *)ZEXT23(pcVar2) = 0;
            }
            empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
          }
          bVar7 = bVar7 + 1;
        } while (bVar7 < 2);
        uVar5 = DAT_00fd14;
        if ((uVar5 & 4) == 0) {
          empty_stub_0();
        }
        else {
          uVar5 = DAT_00fd14;
          DAT_00fd14 = uVar5 | 0x10;
        }
        kline_transport_task(1);
        sVar6 = DAT_00c584;
        if (sVar6 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)((uint3)*(ushort *)((sVar6 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
          return;
        }
      }
      app_scheduler();
      return;
    }
    bVar7 = UNK_00c576;
    bVar4 = UNK_00c593;
    if (bVar4 <= bVar7) {
      DAT_00c57a = 5;
      goto LAB_c11e78;
    }
    bVar4 = UNK_00c5c7;
    bVar7 = UNK_00c576;
    UNK_00c5b3 = *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar4 + (ushort)bVar7);
    gap_c127a2();
    cVar3 = UNK_00c576;
    UNK_00c576 = cVar3 + '\x01';
  } while( true );
}

