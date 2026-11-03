// c12ede gap_c12ede size=50 cc=unknown proto=undefined gap_c12ede(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12ede(void)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  byte bVar6;
  bool bVar7;
  char cVar8;
  ushort uVar9;
  
  uVar4 = DAT_00c5ac;
  uVar9 = DAT_00c5a6;
  if (uVar4 < uVar9) {
    sVar1 = DAT_00c5ac;
    DAT_00c5ac = sVar1 + 1;
  }
  uVar9 = DAT_00c59c;
  if (uVar9 == 0xffff) {
    uVar9 = 0xfffe;
  }
  uVar4 = DAT_00c5ba;
  uVar5 = DAT_00c5ba;
  if (uVar9 != uVar5 && uVar4 <= uVar9) {
    sVar1 = DAT_00c5ba;
    DAT_00c5ba = sVar1 + 1;
  }
  uVar4 = DAT_00c5ba;
  uVar5 = DAT_00c5ba;
  if (uVar9 == uVar5 || uVar9 < uVar4) {
    kline_prepare_frame(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar9 = PSW;
    PSW = uVar9 & 0xf7ff;
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

