// c00898 gap_c00898 size=104 cc=unknown proto=undefined gap_c00898(void)

void gap_c00898(void)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  char cVar4;
  char cVar5;
  short sVar6;
  undefined3 uVar7;
  short in_r1;
  ushort uVar8;
  ushort uVar9;
  short in_r3;
  ushort extraout_r3;
  ushort uVar10;
  ushort uVar11;
  short sVar12;
  short sVar13;
  
  cVar4 = DAT_00c000;
  cVar5 = DPP0._0_1_;
  DAT_00c000 = cVar4 + cVar5;
  cVar4 = UNK_00c074;
  cVar5 = DPP0._0_1_;
  UNK_00c074 = cVar4 + cVar5;
  cVar4 = DAT_00c096._0_1_;
  cVar5 = DPP0._0_1_;
  DAT_00c096._0_1_ = cVar4 + cVar5;
  sVar13 = DPP0;
  uVar8 = Ram00ff80;
  Ram00ff80 = uVar8 & 0xfbff;
  sVar12 = DPP1;
  sVar12 = ((short)uRam000005 + sVar13) - sVar12;
  uRam000005 = CONCAT12(uRam000005._2_1_,sVar12);
  uVar7 = uRam000005;
  sVar13 = DPP0;
  DPP0 = sVar13 + 0x20;
  cVar4 = DPP0._0_1_;
  DPP0._0_1_ = cVar4 + cRam0008b8;
  sVar13 = DPP0;
  DPP0 = sVar13 + 0x6e;
  cVar4 = DPP0._0_1_;
  DPP0._0_1_ = cVar4 + cRam000ca0;
  puVar3 = (undefined2 *)(CONCAT11((char)((ushort)in_r3 >> 8),(char)in_r3 * '\x02') + in_r3 * 2);
  sVar13 = DPP0;
  DPP0 = sVar13 + uRam000005._1_2_;
  cVar4 = DPP0._0_1_;
  DPP0._0_1_ = cVar4 + cRam000daa;
  cVar4 = DPP0._0_1_;
  uRam000005._1_1_ = (char)((ushort)sVar12 >> 8);
  DPP0._0_1_ = cVar4 + uRam000005._1_1_;
  uRam000003 = *puVar3;
  uRam000005 = uVar7;
  func_0x0d0300(*(undefined2 *)(uint3)(in_r1 + 0xc));
  sVar12 = DPP0;
  DPP0 = sVar12 + 0x9a;
  cVar4 = DPP0._0_1_;
  DPP0._0_1_ = cVar4 + cRam001130;
  sVar12 = DPP0;
  uRam000005 = CONCAT21(uRam000005._1_2_ + sVar12 +
                        (ushort)CARRY2(CONCAT11((char)((ushort)puVar3 >> 8),(char)puVar3 * '\x02'),
                                       extraout_r3),(undefined1)uRam000005);
  DPP1 = (short)(char)uRam000003;
  sVar12 = DPP0;
  DPP0 = sVar12 + sRam000000;
  uVar8 = (ushort)&DAT_00fdfe;
  do {
    if ((uVar8 != (ushort)&UNK_00fc22) && (uVar8 != (ushort)&DAT_00fc20)) {
      *(undefined2 *)(uint3)uVar8 = 0;
    }
    bVar1 = uVar8 != (ushort)&DAT_00fd00;
    uVar8 = uVar8 - 2;
  } while (bVar1);
  uVar8 = 0x8ba;
  do {
    DPP0 = 0x300;
    while( true ) {
      while( true ) {
        uVar10 = uVar8 + 2;
        sVar12 = *(short *)(uint3)uVar8;
        if (sVar12 != 1) break;
        uVar8 = uVar8 + 0xe;
      }
      if (sVar12 == 5) break;
      if (sVar12 == 6) {
        uVar9 = *(ushort *)(uint3)uVar10 & 0x7fff | 0x4000;
        DPP1 = *(undefined2 *)(uint3)(uVar8 + 4);
        uVar11 = *(ushort *)(uint3)(uVar8 + 6) & 0xbfff | 0x8000;
        DPP2 = *(undefined2 *)(uint3)(uVar8 + 8);
        uVar10 = uVar8 + 10;
        uVar8 = uVar8 + 0xc;
        sVar12 = *(short *)(uint3)uVar10;
        while (bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1) {
          puVar2 = (undefined1 *)(uint3)uVar11;
          uVar11 = uVar11 + 1;
          *(undefined1 *)(uint3)uVar9 = *puVar2;
          bVar1 = uVar9 == 0x7fff;
          uVar9 = uVar9 + 1;
          if (bVar1) {
            uVar9 = 0x4000;
            sVar13 = DPP1;
            DPP1 = sVar13 + 1;
          }
        }
        DPP1 = 0x301;
        DPP2 = 0x302;
      }
      else {
        if (sVar12 != 7) {
          uVar8 = 0x898;
          do {
            DPP0 = 0x300;
            while( true ) {
              uVar10 = uVar8 + 2;
              sVar12 = *(short *)(uint3)uVar8;
              if (sVar12 == 5) break;
              if (sVar12 == 6) {
                uVar9 = *(ushort *)(uint3)uVar10 & 0x7fff | 0x4000;
                DPP1 = *(undefined2 *)(uint3)(uVar8 + 4);
                uVar10 = uVar8 + 6;
                uVar8 = uVar8 + 8;
                sVar12 = *(short *)(uint3)uVar10;
                while (bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1) {
                  *(undefined1 *)(uint3)uVar9 = 0;
                  uVar9 = uVar9 + 1;
                }
                DPP1 = 0x301;
              }
              else {
                if (sVar12 != 7) {
                  DPP0 = 0x300;
                  return;
                }
                DPP1 = (*(ushort *)(uint3)(uVar8 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar10 >> 0xe
                ;
                uVar10 = *(ushort *)(uint3)uVar10 & 0x7fff | 0x4000;
                uVar9 = uVar8 + 8;
                sVar12 = *(short *)(uint3)(uVar8 + 6);
                uVar8 = uVar8 + 10;
                sVar13 = *(short *)(uint3)uVar9;
                while ((bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1 ||
                       (bVar1 = sVar13 != 0, sVar13 = sVar13 + -1, bVar1))) {
                  *(undefined1 *)(uint3)uVar10 = 0;
                  bVar1 = uVar10 == 0x7fff;
                  uVar10 = uVar10 + 1;
                  if (bVar1) {
                    uVar10 = 0x4000;
                    sVar6 = DPP1;
                    DPP1 = sVar6 + 1;
                  }
                }
                DPP1 = 0x301;
              }
            }
            uVar9 = uVar8 + 4;
            uVar10 = *(ushort *)(uint3)uVar10;
            uVar8 = uVar8 + 6;
            sVar12 = *(short *)(uint3)uVar9;
            DPP0 = 0x300;
            while (bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1) {
              *(undefined1 *)(uint3)uVar10 = 0;
              uVar10 = uVar10 + 1;
            }
          } while( true );
        }
        DPP1 = (*(ushort *)(uint3)(uVar8 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar10 >> 0xe;
        uVar9 = *(ushort *)(uint3)uVar10 & 0x7fff | 0x4000;
        DPP2 = (*(ushort *)(uint3)(uVar8 + 8) & 0xff) << 2 | *(ushort *)(uint3)(uVar8 + 6) >> 0xe;
        uVar10 = *(ushort *)(uint3)(uVar8 + 6) & 0xbfff | 0x8000;
        uVar11 = uVar8 + 0xc;
        sVar12 = *(short *)(uint3)(uVar8 + 10);
        uVar8 = uVar8 + 0xe;
        sVar13 = *(short *)(uint3)uVar11;
        while ((bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1 ||
               (bVar1 = sVar13 != 0, sVar13 = sVar13 + -1, bVar1))) {
          *(undefined1 *)(uint3)uVar9 = *(undefined1 *)(uint3)uVar10;
          bVar1 = uVar9 == 0x7fff;
          uVar9 = uVar9 + 1;
          if (bVar1) {
            uVar9 = 0x4000;
            sVar6 = DPP1;
            DPP1 = sVar6 + 1;
          }
          bVar1 = uVar10 == 0xbfff;
          uVar10 = uVar10 + 1;
          if (bVar1) {
            uVar10 = 0x8000;
            sVar6 = DPP2;
            DPP2 = sVar6 + 1;
          }
        }
        DPP1 = 0x301;
        DPP2 = 0x302;
      }
    }
    uVar10 = *(ushort *)(uint3)uVar10;
    uVar11 = uVar8 + 6;
    uVar9 = *(ushort *)(uint3)(uVar8 + 4);
    uVar8 = uVar8 + 8;
    sVar12 = *(short *)(uint3)uVar11;
    DPP0 = 0x300;
    while (bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1) {
      puVar2 = (undefined1 *)(uint3)uVar9;
      uVar9 = uVar9 + 1;
      *(undefined1 *)(uint3)uVar10 = *puVar2;
      uVar10 = uVar10 + 1;
    }
  } while( true );
}

