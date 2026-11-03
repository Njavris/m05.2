// c12982 kline_transport_task size=84 cc=unknown proto=undefined kline_transport_task(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kline_transport_task(short param_1,undefined2 param_2)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  byte bVar5;
  bool bVar6;
  char cVar7;
  
  if (param_1 == 0) {
    kline_state_reset(6);
    uVar4 = S0CON;
    S0CON = uVar4 & 0xffef;
    kline_start_timeout();
    DAT_00c5ab = 0;
    DAT_00c568 = 0;
    empty_stub_2();
    store32();
    test_command_clear();
  }
  else if (param_1 == 1) {
    uVar4 = DAT_00c584;
    if (uVar4 < 0x10) {
                    /* WARNING: Could not emulate address calculation at 0xc129d2 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar4 * 2 + 0x7164 & 0x3fff) | 0xc10000))();
      return;
    }
    sVar1 = DAT_00c56a;
    if (sVar1 != 0) {
      sVar1 = DAT_00c56a;
      DAT_00c56a = sVar1 + -1;
    }
    sVar1 = DAT_00c584;
    if ((sVar1 != 0xd) && (sVar1 != 10)) {
      cVar7 = DAT_00c5ab;
      if (cVar7 != '\0') {
        DAT_00c5ab = 0;
        uVar4 = PSW;
        PSW = uVar4 & 0xf7ff;
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      param_2 = 0;
    }
    cVar7 = DAT_00c57d;
    if (cVar7 == '\0') {
      DAT_00c568 = 0;
    }
    else {
      cVar7 = DAT_00c568;
      if (cVar7 == '\0') {
        DAT_00c568 = 1;
        empty_stub_1(param_2);
      }
    }
    cVar7 = DAT_00c5b6;
    if ((((cVar7 == '\0') && (cVar7 = kline_get_status(), cVar7 == '\0')) ||
        (sVar1 = DAT_00c584, sVar1 == 0xd)) || (sVar1 == 10)) {
      sVar1 = DAT_00c584;
      if (sVar1 == 9) {
        bVar5 = DAT_00c5c4;
        bVar6 = false;
        DAT_00c56c = 0;
        while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
          bVar3 = DAT_00c56c;
          if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
              *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar5)) {
            empty_stub_0();
            bVar6 = true;
            break;
          }
          cVar7 = DAT_00c56c;
          DAT_00c56c = cVar7 + '\x01';
        }
        if (!bVar6) {
          empty_stub_0();
        }
      }
    }
    else {
      uVar2 = DAT_00c56c;
      empty_stub_0();
    }
  }
  return;
}

