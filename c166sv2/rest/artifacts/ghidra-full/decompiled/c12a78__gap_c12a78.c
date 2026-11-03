// c12a78 gap_c12a78 size=98 cc=unknown proto=undefined gap_c12a78(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12a78(void)

{
  ushort uVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  byte bVar6;
  bool bVar7;
  char cVar8;
  ushort extraout_r10;
  ushort extraout_r10_00;
  short extraout_r11;
  short extraout_r11_00;
  short sVar9;
  
  gap_c28c54();
  if ((extraout_r11 + 0x9bb0U == (ushort)(extraout_r10 < 0x8625) && extraout_r10 == 0x8625) ||
     (gap_c28c54(),
     extraout_r11_00 + 0x79cdU == (ushort)(extraout_r10_00 < 0x6450) && extraout_r10_00 == 0x6450))
  {
    __disable_watchdog();
    uVar1 = PSW;
    PSW = uVar1 & 0xf7ff;
    __software_reset();
  }
  else {
    cVar8 = DAT_00c5a9;
    if (cVar8 == '\0') {
      sVar9 = DAT_00c5b4;
    }
    else {
      sVar9 = 2;
    }
    if (sVar9 == -1) {
      sVar9 = DAT_00c59e;
      if (sVar9 != -1) {
        sVar9 = DAT_00c59e;
        DAT_00c59e = sVar9 + 1;
      }
    }
    else {
      uVar1 = sVar9 + 1;
      uVar4 = DAT_00c59e;
      uVar5 = DAT_00c59e;
      if (uVar1 != uVar5 && uVar4 <= uVar1) {
        sVar9 = DAT_00c59e;
        DAT_00c59e = sVar9 + 1;
      }
      uVar4 = DAT_00c59e;
      uVar5 = DAT_00c59e;
      if (uVar1 == uVar5 || uVar1 < uVar4) {
        kline_state_reset(0);
      }
    }
  }
  sVar9 = DAT_00c56a;
  if (sVar9 != 0) {
    sVar9 = DAT_00c56a;
    DAT_00c56a = sVar9 + -1;
  }
  sVar9 = DAT_00c584;
  if (((sVar9 != 0xd) && (sVar9 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar1 = PSW;
    PSW = uVar1 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar9 = DAT_00c584, sVar9 == 0xd || (sVar9 == 10)))) {
    sVar9 = DAT_00c584;
    if (sVar9 == 9) {
      bVar6 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar6)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}

