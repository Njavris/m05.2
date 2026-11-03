// c12d28 gap_c12d28 size=438 cc=unknown proto=undefined gap_c12d28(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12d28(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  bool bVar7;
  char cVar8;
  
  cVar8 = DAT_00c57d;
  if ((cVar8 == '\0') &&
     (bVar6 = DAT_00c5c4, *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar6) != -0x7f)) {
LAB_c12ed6:
    kline_state_reset(1);
  }
  else {
    bVar6 = DAT_00c5c4;
    DAT_00c5ac = 1;
    cVar8 = *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar6);
    if (cVar8 == -0x7f) {
      cVar8 = UNK_00c578;
      if ((cVar8 == '\x01') && (uVar1 = Ram00fd16, (uVar1 & 1) == 0)) {
        bVar6 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar6) = 0xef;
        *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar6) = 0x8f;
        gap_c12910(3);
        DAT_00c57d = 1;
        uVar1 = Ram00fd16;
        Ram00fd16 = uVar1 | 2;
        goto LAB_c12f6e;
      }
      cVar8 = DAT_00c57d;
      if (cVar8 == '\0') goto LAB_c12ed6;
    }
    else if (cVar8 == -0x7e) {
      cVar8 = UNK_00c578;
      if (cVar8 == '\x01') {
        gap_c12910(1);
        DAT_00c57d = 0;
        goto LAB_c12f6e;
      }
    }
    else {
      if (cVar8 != -0x7d) {
        UNK_00c58a = 0;
        DAT_00c584 = 9;
        goto LAB_c12f6e;
      }
      bVar6 = DAT_00c5c4;
      uVar1 = (short)&UNK_00f63e + (ushort)bVar6;
      cVar8 = *(char *)(uint3)uVar1;
      if (cVar8 == '\0') {
        cVar8 = UNK_00c578;
        if (cVar8 == '\x02') {
          bVar6 = UNK_00c5c7;
          uVar2 = (ushort)bVar6;
          *(undefined1 *)(uint3)((short)&UNK_00f63e + uVar2) = *(undefined1 *)(uint3)uVar1;
          *(undefined1 *)(uint3)((short)&UNK_00f63f + uVar2) = 0;
          *(undefined1 *)(uint3)((short)&UNK_00f640 + uVar2) = 0xff;
          *(undefined1 *)(uint3)((short)&UNK_00f641 + uVar2) = 0;
          *(undefined1 *)(uint3)((short)&UNK_00f642 + uVar2) = 0xff;
          *(undefined1 *)(uint3)((short)&UNK_00f643 + uVar2) = 0;
LAB_c12e64:
          gap_c12910(7);
          goto LAB_c12f6e;
        }
      }
      else if (cVar8 == '\x01') {
        cVar8 = UNK_00c578;
        if (cVar8 == '\x02') {
          DAT_00c599 = 0x46;
          DAT_00c57f = 2;
          DAT_00c598 = 0;
          DAT_00c580 = 0x14;
          DAT_00c592 = 0;
LAB_c12ea2:
          DAT_00c5a0 = 1;
LAB_c12ea8:
          bVar6 = DAT_00c5c4;
          bVar5 = UNK_00c5c7;
          *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar5) =
               *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar6);
          gap_c12910(2);
          goto LAB_c12f6e;
        }
      }
      else if (cVar8 == '\x02') {
        cVar8 = UNK_00c578;
        if (cVar8 == '\x02') {
          bVar6 = UNK_00c5c7;
          uVar2 = (ushort)bVar6;
          *(undefined1 *)(uint3)((short)&UNK_00f63e + uVar2) = *(undefined1 *)(uint3)uVar1;
          uVar4 = DAT_00c57c;
          *(undefined1 *)(uint3)((short)&UNK_00f63f + uVar2) = uVar4;
          uVar4 = DAT_00c5a5;
          *(undefined1 *)(uint3)((short)&UNK_00f640 + uVar2) = uVar4;
          uVar4 = DAT_00c57e;
          *(undefined1 *)(uint3)((short)&UNK_00f641 + uVar2) = uVar4;
          uVar4 = DAT_00c5a8;
          *(undefined1 *)(uint3)((short)&UNK_00f642 + uVar2) = uVar4;
          uVar4 = DAT_00c577;
          *(undefined1 *)(uint3)((short)&UNK_00f643 + uVar2) = uVar4;
          goto LAB_c12e64;
        }
      }
      else if (cVar8 == '\x03') {
        cVar8 = UNK_00c578;
        if (cVar8 == '\a') {
          bVar6 = DAT_00c5c4;
          uVar1 = (ushort)bVar6;
          DAT_00c599 = *(undefined1 *)(uint3)((short)&UNK_00f63f + uVar1);
          DAT_00c57f = *(undefined1 *)(uint3)((short)&UNK_00f640 + uVar1);
          DAT_00c598 = *(undefined1 *)(uint3)((short)&UNK_00f641 + uVar1);
          DAT_00c580 = *(undefined1 *)(uint3)((short)&UNK_00f642 + uVar1);
          DAT_00c592 = *(undefined1 *)(uint3)((short)&UNK_00f643 + uVar1);
          goto LAB_c12ea2;
        }
        goto LAB_c12ea8;
      }
    }
    func_0xc128ec(0x12);
  }
LAB_c12f6e:
  sVar3 = DAT_00c56a;
  if (sVar3 != 0) {
    sVar3 = DAT_00c56a;
    DAT_00c56a = sVar3 + -1;
  }
  sVar3 = DAT_00c584;
  if (((sVar3 != 0xd) && (sVar3 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
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
     ((sVar3 = DAT_00c584, sVar3 == 0xd || (sVar3 == 10)))) {
    sVar3 = DAT_00c584;
    if (sVar3 == 9) {
      bVar6 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar5 = DAT_00c56c, bVar5 <= DAT_007162) {
        bVar5 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar5 * 10 + 0x70c2) ==
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
    uVar4 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}

