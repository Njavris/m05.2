// c12c0a gap_c12c0a size=40 cc=unknown proto=undefined gap_c12c0a(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12c0a(char param_1)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  
  UNK_00c594 = param_1;
  cVar8 = UNK_00c594;
  if (((cVar8 == -0x10) || (cVar8 == -0xf)) || (cVar8 == -0x3f)) {
    cVar8 = UNK_00c578;
    if (cVar8 == '\0') {
      DAT_00c574 = 3;
    }
    else {
      gap_c1296e();
    }
  }
  else {
    gap_c126d2();
  }
  while( true ) {
    cVar6 = DAT_00c58c;
    cVar8 = DAT_00c56f;
    if (cVar6 == cVar8) {
      bVar7 = false;
    }
    else {
      bVar4 = DAT_00c56f;
      *(undefined1 *)ZEXT23(&param_1) = *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4);
      bVar4 = DAT_00c56f;
      cVar8 = DAT_00c56f;
      DAT_00c56f = cVar8 + '\x01';
      *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4) = 0;
      cVar8 = DAT_00c56f;
      if (cVar8 == '=') {
        DAT_00c56f = 0;
      }
      bVar7 = true;
    }
    if ((!bVar7) || (sVar1 = DAT_00c584, sVar1 != 7)) break;
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5be = 0;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      DAT_00c5b0 = 0;
    }
    cVar8 = UNK_00c5a1;
    UNK_00c5a1 = cVar8 + param_1;
    uVar5 = DAT_00c574;
    if (uVar5 < 6) {
                    /* WARNING: Could not emulate address calculation at 0xc12b42 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar5 * 2 + 0x7184 & 0x3fff) | 0xc10000))();
      return;
    }
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 1) && (uVar5 = DAT_00c5be, 2 < uVar5)) {
    gap_c126d2();
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 0) && (uVar5 = DAT_00c5b0, 9 < uVar5)) {
    gap_c126d2(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
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
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
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

