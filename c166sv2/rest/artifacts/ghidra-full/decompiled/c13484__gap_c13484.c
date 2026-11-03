// c13484 gap_c13484 size=456 cc=unknown proto=undefined gap_c13484(void)

void gap_c13484(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  undefined1 uVar6;
  short sVar7;
  char cVar8;
  char cVar9;
  ushort uVar10;
  byte bStack_8;
  
  bVar1 = UNK_00c5c7;
  uVar6 = UNK_00c5d0;
  *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) = uVar6;
  do {
    bVar1 = UNK_00c5cc;
    if (uRam00735a <= bVar1) {
LAB_c13608:
      bVar1 = UNK_00c5cb;
      if (bVar1 < 2) {
        gap_c12910(0);
      }
      else {
        gap_c12910(bVar1);
      }
      bVar1 = UNK_00c5cc;
      if ((bVar1 < uRam00735a) && (bVar1 = UNK_00c5cb, 0x85 < bVar1)) {
        UNK_00c5cb = 1;
        DAT_00c5b6 = 1;
      }
      else {
        DAT_00c5b6 = 0;
      }
      return;
    }
    cVar9 = UNK_00c5cd;
    bVar1 = UNK_00c5cc;
    Ram00c5d4 = 0;
    UNK_00c5d7 = 0;
    UNK_00c5d8 = 0;
    uVar10 = func_0xc2425c(bVar1);
    cVar8 = func_0xc24286(bVar1);
    if ((cVar8 != '\0') && (uVar3 = Ram00c5d2, uVar3 <= uVar10)) {
      uVar3 = Ram00c5ce;
      uVar4 = Ram00c5ce;
      if ((uVar10 == uVar4 || uVar10 < uVar3) &&
         ((cVar9 == '\x01' ||
          ((cVar9 == '\0' &&
           ((cVar9 = func_0xc24530(bVar1), cVar9 != '\0' ||
            (((byte)((ushort)*(undefined2 *)(uint3)((short)&UNK_00c168 + (ushort)bVar1 * 2) >> 0xb)
             & 1) != 0)))))))) {
        cVar9 = func_0xc245fa(bVar1);
        bVar2 = cVar9 << 7;
        cVar9 = func_0xc24530(bVar1);
        if (cVar9 == '\0') {
          cVar9 = func_0xc2465c(bVar1);
          if (cVar9 != '\0') {
            bVar2 = bStack_8 & 0x50 | bVar2 | 0x60;
          }
        }
        else {
          cVar9 = func_0xc2465c(bVar1);
          if (cVar9 == '\0') {
            bVar2 = bStack_8 & 0x30 | bVar2 | 0x60;
          }
          else {
            bVar2 = bVar2 | 0x60;
          }
        }
        cVar9 = func_0xc2446c(bVar1);
        if ((cVar9 == '\0') || (cVar9 = gap_c244ce(bVar1), cVar9 != '\0')) {
          bStack_8 = bVar2 & 0xef;
        }
        else {
          bStack_8 = bVar2 & 0xef | 0x10;
        }
        Ram00c5d4 = uVar10;
        UNK_00c5d7 = bStack_8;
        UNK_00c5d8 = 1;
      }
    }
    cVar9 = UNK_00c5d8;
    if (cVar9 != '\0') {
      cVar9 = UNK_00c5ca;
      UNK_00c5ca = cVar9 + '\x01';
      bVar2 = UNK_00c5cb;
      bVar1 = UNK_00c5c7;
      uVar6 = UNK_00c5d4;
      cVar9 = UNK_00c5cb;
      UNK_00c5cb = cVar9 + '\x01';
      *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar1 + (ushort)bVar2) = uVar6;
      bVar2 = UNK_00c5cb;
      bVar1 = UNK_00c5c7;
      uVar6 = UNK_00c5d5;
      cVar9 = UNK_00c5cb;
      UNK_00c5cb = cVar9 + '\x01';
      *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar1 + (ushort)bVar2) = uVar6;
      bVar2 = UNK_00c5cb;
      bVar1 = UNK_00c5c7;
      uVar6 = UNK_00c5d7;
      cVar9 = UNK_00c5cb;
      UNK_00c5cb = cVar9 + '\x01';
      *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar1 + (ushort)bVar2) = uVar6;
      sVar7 = Ram00c5d2;
      sVar5 = Ram00c5ce;
      if ((sVar7 == sVar5) || (bVar1 = UNK_00c5cb, 0x85 < bVar1)) {
        cVar9 = UNK_00c5cc;
        UNK_00c5cc = cVar9 + '\x01';
        goto LAB_c13608;
      }
    }
    cVar9 = UNK_00c5cc;
    UNK_00c5cc = cVar9 + '\x01';
  } while( true );
}

