// c129e2 gap_c129e2 size=52 cc=unknown proto=undefined gap_c129e2(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c129e2(void)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  bool bVar6;
  char cVar7;
  
  uVar5 = P3;
  if ((uVar5 & 0x800) == 0) {
    cVar7 = UNK_00c571;
    UNK_00c571 = cVar7 + '\x01';
  }
  else {
    bVar4 = UNK_00c571;
    if (1 < bVar4) {
      UNK_00c571 = 0;
      DAT_00c584 = 3;
      goto LAB_c12f6e;
    }
    kline_state_reset(0);
  }
  bVar4 = UNK_00c571;
  if (4 < bVar4) {
    kline_state_reset(0);
  }
LAB_c12f6e:
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar7 = DAT_00c5ab, cVar7 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar7 = DAT_00c57d;
  if (cVar7 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar7 = DAT_00c568;
    if (cVar7 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar7 = DAT_00c5b6;
  if (((cVar7 == '\0') && (cVar7 = kline_get_status(), cVar7 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar6 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
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
  return;
}

