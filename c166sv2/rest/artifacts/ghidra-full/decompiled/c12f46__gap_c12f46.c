// c12f46 gap_c12f46 size=280 cc=unknown proto=undefined gap_c12f46(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12f46(void)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  bool bVar6;
  char cVar7;
  
  uVar5 = S0CON;
  S0CON = uVar5 & 0xffef;
  uVar5 = P3;
  if ((uVar5 & 0x800) == 0) {
    DAT_00c588 = 0;
    DAT_00c582 = 0;
    func_0xc1281a();
  }
  else {
    cVar7 = DAT_00c588;
    DAT_00c588 = cVar7 + '\x01';
    bVar3 = DAT_00c588;
    bVar4 = DAT_00c582;
    if (bVar4 <= bVar3) {
      DAT_00c584 = 1;
    }
  }
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

