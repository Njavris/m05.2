// c25300 gap_c25300 size=144 cc=unknown proto=undefined gap_c25300(void)

void gap_c25300(void)

{
  undefined2 uVar1;
  bool bVar2;
  bool bVar3;
  ushort in_r1;
  ushort uVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  
  bVar6 = 0;
  uVar4 = in_r1 & 0xff00;
  do {
    bVar7 = 0;
    bVar2 = false;
    bVar3 = true;
    while (*(short *)(uint3)(*(short *)(uint3)((ushort)bVar6 * 2 + 0x7318) + (ushort)bVar7 * 2) != 0
          ) {
      uVar1 = *(undefined2 *)
               (uint3)(*(short *)(uint3)((ushort)bVar6 * 2 + 0x7318) + (ushort)bVar7 * 2);
      cVar5 = func_0xc2446c();
      if (cVar5 != '\0') {
        bVar2 = true;
      }
      cVar5 = func_0xc245fa(uVar1,uVar4);
      if (cVar5 == '\x01') {
        bVar3 = false;
      }
      bVar7 = bVar7 + 1;
    }
    if (((bVar2) && (bVar3)) && ((bRamc07d16 >> (ushort)bVar6 & 1) != 0)) {
      uVar4 = CONCAT11((char)(uVar4 >> 8),(byte)uVar4 | '\x01' << (ushort)bVar6);
    }
    bVar6 = bVar6 + 1;
  } while (bVar6 < 8);
  UNK_00cbe6 = (char)uVar4;
  return;
}

