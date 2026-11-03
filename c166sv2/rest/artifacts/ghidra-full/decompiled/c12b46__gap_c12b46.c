// c12b46 gap_c12b46 size=74 cc=unknown proto=undefined gap_c12b46(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12b46(char param_1)

{
  byte bVar1;
  short sVar2;
  undefined1 uVar3;
  byte bVar4;
  ushort uVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  
  UNK_00c5ae = param_1;
  bVar1 = UNK_00c5ae;
  UNK_00c5a1 = bVar1;
  UNK_00c56e = 0;
  UNK_00c578 = bVar1 & 0x3f;
  bVar1 = UNK_00c5ae;
  bVar1 = bVar1 & 0xc0;
  if ((bVar1 == 0x80) || (bVar1 == 0xc0)) {
    DAT_00c574 = 1;
  }
  else {
    if (bVar1 == 0) {
      cVar8 = DAT_00c57d;
      if (cVar8 != '\0') {
        cVar8 = UNK_00c578;
        if (cVar8 == '\0') {
          DAT_00c574 = 3;
        }
        else {
          gap_c1296e();
        }
        goto LAB_c12cb0;
      }
    }
    else if (bVar1 != 0x40) goto LAB_c12cb0;
    gap_c126d2();
  }
LAB_c12cb0:
  while( true ) {
    cVar6 = DAT_00c58c;
    cVar8 = DAT_00c56f;
    if (cVar6 == cVar8) {
      bVar7 = false;
    }
    else {
      bVar1 = DAT_00c56f;
      *(undefined1 *)ZEXT23(&param_1) = *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar1);
      bVar1 = DAT_00c56f;
      cVar8 = DAT_00c56f;
      DAT_00c56f = cVar8 + '\x01';
      *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar1) = 0;
      cVar8 = DAT_00c56f;
      if (cVar8 == '=') {
        DAT_00c56f = 0;
      }
      bVar7 = true;
    }
    if ((!bVar7) || (sVar2 = DAT_00c584, sVar2 != 7)) break;
    sVar2 = DAT_00c5a2;
    if (sVar2 == 1) {
      DAT_00c5be = 0;
    }
    sVar2 = DAT_00c5a2;
    if (sVar2 == 0) {
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
  sVar2 = DAT_00c5a2;
  if ((sVar2 == 1) && (uVar5 = DAT_00c5be, 2 < uVar5)) {
    gap_c126d2();
  }
  sVar2 = DAT_00c5a2;
  if ((sVar2 == 0) && (uVar5 = DAT_00c5b0, 9 < uVar5)) {
    gap_c126d2(0);
  }
  sVar2 = DAT_00c56a;
  if (sVar2 != 0) {
    sVar2 = DAT_00c56a;
    DAT_00c56a = sVar2 + -1;
  }
  sVar2 = DAT_00c584;
  if (((sVar2 != 0xd) && (sVar2 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
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
     ((sVar2 = DAT_00c584, sVar2 == 0xd || (sVar2 == 10)))) {
    sVar2 = DAT_00c584;
    if (sVar2 == 9) {
      bVar1 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar4 = DAT_00c56c, bVar4 <= DAT_007162) {
        bVar4 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar4 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar1)) {
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
    uVar3 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}

