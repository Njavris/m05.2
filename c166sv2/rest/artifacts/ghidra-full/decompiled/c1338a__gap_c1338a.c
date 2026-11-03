// c1338a gap_c1338a size=250 cc=unknown proto=undefined gap_c1338a(void)

/* WARNING: Removing unreachable block (ram,0xc13426) */
/* WARNING: Removing unreachable block (ram,0xc1342a) */

void gap_c1338a(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  char cVar5;
  char cVar6;
  ushort uVar7;
  byte bVar8;
  undefined2 uStack_8;
  
  bVar8 = DAT_00c5c4;
  uVar7 = (ushort)bVar8;
  uStack_8 = CONCAT11(*(undefined1 *)(uint3)((short)&UNK_00f640 + uVar7),
                      *(undefined1 *)(uint3)((short)&UNK_00f63f + uVar7));
  cVar5 = UNK_00c578;
  if (cVar5 == '\x04') {
    if (*(char *)(uint3)((short)&UNK_00f63e + uVar7) == '\0') {
      if (uStack_8 == 0) {
        Ram00c5d2 = 0;
        Ram00c5ce = 0x3fff;
      }
      else {
        Ram00c5d2 = uStack_8;
        Ram00c5ce = uStack_8;
      }
      UNK_00c5ca = 0;
      UNK_00c5cc = 0;
      UNK_00c5cd = 0;
      UNK_00c5cb = 2;
      cVar5 = '\0';
      for (bVar8 = 0; bVar8 < uRam00735a; bVar8 = bVar8 + 1) {
        uVar7 = func_0xc2425c(bVar8);
        cVar6 = func_0xc24286(bVar8);
        if ((cVar6 != '\0') && (uVar1 = Ram00c5d2, uVar1 <= uVar7)) {
          uVar1 = Ram00c5ce;
          uVar2 = Ram00c5ce;
          if ((uVar7 == uVar2 || uVar7 < uVar1) &&
             ((cVar6 = func_0xc24530(bVar8), cVar6 != '\0' ||
              (((byte)((ushort)*(undefined2 *)(uint3)((short)&UNK_00c168 + (ushort)bVar8 * 2) >> 0xb
                      ) & 1) != 0)))) {
            cVar5 = cVar5 + '\x01';
          }
        }
      }
      UNK_00c5d0 = cVar5;
      sVar4 = Ram00c5d2;
      sVar3 = Ram00c5ce;
      if ((sVar4 != sVar3) || (cVar5 != '\0')) {
        DAT_00c5b6 = 1;
        return;
      }
    }
    func_0xc128ec(0x31);
  }
  else {
    func_0xc128ec(0x12);
  }
  return;
}

