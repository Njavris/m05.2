// c124e0 gap_c124e0 size=240 cc=unknown proto=undefined gap_c124e0(void)

void gap_c124e0(short param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  
  cVar5 = '\x01';
  cVar3 = UNK_00c55d;
  if (cVar3 != '\0') {
    bVar6 = UNK_00c55a;
    bVar7 = UNK_00c55d;
    if (bVar6 < bVar7) {
      param_1 = 3;
      uVar2 = UNK_00cb46;
      UNK_00f640 = uVar2;
      cVar5 = UNK_00c55a;
      UNK_00c55a = cVar5 + '\x01';
      uVar2 = UNK_00c55a;
      bVar6 = 5;
      UNK_00f641 = uVar2;
      cVar5 = UNK_00cb46;
      if (cVar5 == '\x04') {
        bVar7 = 0;
        do {
          bVar4 = UNK_00c55e;
          if (bVar4 < 8) {
            cVar5 = UNK_00c55e;
            UNK_00c55e = cVar5 + '\x01';
            param_1 = (0xa51e < bVar4) + 0xc0;
            uVar1 = (ushort)bVar6;
            bVar6 = bVar6 + 1;
            *(undefined1 *)(uint3)((short)&UNK_00f63d + uVar1) =
                 *(undefined1 *)(uint3)(bVar4 + 0x5ae1);
          }
          else {
            bVar4 = UNK_00c55e;
            if (bVar4 < 0x10) {
              cVar5 = UNK_00c55e;
              UNK_00c55e = cVar5 + '\x01';
              uVar1 = (ushort)bVar6;
              bVar6 = bVar6 + 1;
              *(undefined1 *)(uint3)((short)&UNK_00f63d + uVar1) = 0;
            }
          }
          bVar7 = bVar7 + 1;
        } while (bVar7 < 4);
        cVar5 = UNK_00c55e;
        if (cVar5 == '\x10') {
          cVar5 = UNK_00c55f;
          UNK_00c55f = cVar5 + '\x01';
          UNK_00c55e = 0;
        }
      }
      else if (cVar5 == '\x06') {
        UNK_00c55f = 0;
      }
      cVar5 = bVar6 - 2;
      goto LAB_c125a4;
    }
  }
  UNK_00c55d = 0;
  UNK_00c55a = 0;
  DAT_00c5b6 = 0;
LAB_c125a4:
  cVar3 = UNK_00cb46;
  if (cVar3 == '\x06') {
    DAT_00c5b6 = 1;
    UNK_00cb58 = 0;
    return;
  }
  bVar6 = UNK_00c55a;
  bVar7 = UNK_00c55d;
  if (bVar7 <= bVar6) {
    DAT_00c5b6 = 0;
  }
  gap_c12910(cVar5,param_1);
  return;
}

