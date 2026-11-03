// c00904 boot_cinit size=372 cc=unknown proto=undefined boot_cinit(void)

void boot_cinit(void)

{
  bool bVar1;
  undefined1 *puVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  short sVar8;
  short sVar9;
  
  uVar4 = (ushort)&DAT_00fdfe;
  do {
    if ((uVar4 != (ushort)&UNK_00fc22) && (uVar4 != (ushort)&DAT_00fc20)) {
      *(undefined2 *)(uint3)uVar4 = 0;
    }
    bVar1 = uVar4 != (ushort)&DAT_00fd00;
    uVar4 = uVar4 - 2;
  } while (bVar1);
  uVar4 = 0x8ba;
  do {
    DPP0 = 0x300;
    while( true ) {
      while( true ) {
        uVar6 = uVar4 + 2;
        sVar8 = *(short *)(uint3)uVar4;
        if (sVar8 != 1) break;
        uVar4 = uVar4 + 0xe;
      }
      if (sVar8 == 5) break;
      if (sVar8 == 6) {
        uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
        DPP1 = *(undefined2 *)(uint3)(uVar4 + 4);
        uVar7 = *(ushort *)(uint3)(uVar4 + 6) & 0xbfff | 0x8000;
        DPP2 = *(undefined2 *)(uint3)(uVar4 + 8);
        uVar6 = uVar4 + 10;
        uVar4 = uVar4 + 0xc;
        sVar8 = *(short *)(uint3)uVar6;
        while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
          puVar2 = (undefined1 *)(uint3)uVar7;
          uVar7 = uVar7 + 1;
          *(undefined1 *)(uint3)uVar5 = *puVar2;
          bVar1 = uVar5 == 0x7fff;
          uVar5 = uVar5 + 1;
          if (bVar1) {
            uVar5 = 0x4000;
            sVar9 = DPP1;
            DPP1 = sVar9 + 1;
          }
        }
        DPP1 = 0x301;
        DPP2 = 0x302;
      }
      else {
        if (sVar8 != 7) {
          uVar4 = 0x898;
          do {
            DPP0 = 0x300;
            while( true ) {
              uVar6 = uVar4 + 2;
              sVar8 = *(short *)(uint3)uVar4;
              if (sVar8 == 5) break;
              if (sVar8 == 6) {
                uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
                DPP1 = *(undefined2 *)(uint3)(uVar4 + 4);
                uVar6 = uVar4 + 6;
                uVar4 = uVar4 + 8;
                sVar8 = *(short *)(uint3)uVar6;
                while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
                  *(undefined1 *)(uint3)uVar5 = 0;
                  uVar5 = uVar5 + 1;
                }
                DPP1 = 0x301;
              }
              else {
                if (sVar8 != 7) {
                  DPP0 = 0x300;
                  return;
                }
                DPP1 = (*(ushort *)(uint3)(uVar4 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar6 >> 0xe;
                uVar6 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
                uVar5 = uVar4 + 8;
                sVar8 = *(short *)(uint3)(uVar4 + 6);
                uVar4 = uVar4 + 10;
                sVar9 = *(short *)(uint3)uVar5;
                while ((bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1 ||
                       (bVar1 = sVar9 != 0, sVar9 = sVar9 + -1, bVar1))) {
                  *(undefined1 *)(uint3)uVar6 = 0;
                  bVar1 = uVar6 == 0x7fff;
                  uVar6 = uVar6 + 1;
                  if (bVar1) {
                    uVar6 = 0x4000;
                    sVar3 = DPP1;
                    DPP1 = sVar3 + 1;
                  }
                }
                DPP1 = 0x301;
              }
            }
            uVar5 = uVar4 + 4;
            uVar6 = *(ushort *)(uint3)uVar6;
            uVar4 = uVar4 + 6;
            sVar8 = *(short *)(uint3)uVar5;
            DPP0 = 0x300;
            while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
              *(undefined1 *)(uint3)uVar6 = 0;
              uVar6 = uVar6 + 1;
            }
          } while( true );
        }
        DPP1 = (*(ushort *)(uint3)(uVar4 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar6 >> 0xe;
        uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
        DPP2 = (*(ushort *)(uint3)(uVar4 + 8) & 0xff) << 2 | *(ushort *)(uint3)(uVar4 + 6) >> 0xe;
        uVar6 = *(ushort *)(uint3)(uVar4 + 6) & 0xbfff | 0x8000;
        uVar7 = uVar4 + 0xc;
        sVar8 = *(short *)(uint3)(uVar4 + 10);
        uVar4 = uVar4 + 0xe;
        sVar9 = *(short *)(uint3)uVar7;
        while ((bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1 ||
               (bVar1 = sVar9 != 0, sVar9 = sVar9 + -1, bVar1))) {
          *(undefined1 *)(uint3)uVar5 = *(undefined1 *)(uint3)uVar6;
          bVar1 = uVar5 == 0x7fff;
          uVar5 = uVar5 + 1;
          if (bVar1) {
            uVar5 = 0x4000;
            sVar3 = DPP1;
            DPP1 = sVar3 + 1;
          }
          bVar1 = uVar6 == 0xbfff;
          uVar6 = uVar6 + 1;
          if (bVar1) {
            uVar6 = 0x8000;
            sVar3 = DPP2;
            DPP2 = sVar3 + 1;
          }
        }
        DPP1 = 0x301;
        DPP2 = 0x302;
      }
    }
    uVar6 = *(ushort *)(uint3)uVar6;
    uVar7 = uVar4 + 6;
    uVar5 = *(ushort *)(uint3)(uVar4 + 4);
    uVar4 = uVar4 + 8;
    sVar8 = *(short *)(uint3)uVar7;
    DPP0 = 0x300;
    while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
      puVar2 = (undefined1 *)(uint3)uVar5;
      uVar5 = uVar5 + 1;
      *(undefined1 *)(uint3)uVar6 = *puVar2;
      uVar6 = uVar6 + 1;
    }
  } while( true );
}

