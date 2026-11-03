// c21158 gap_c21158 size=194 cc=unknown proto=undefined gap_c21158(void)

void gap_c21158(void)

{
  ushort uVar1;
  undefined2 *puVar2;
  char cVar3;
  short sVar4;
  char cVar5;
  
  gap_c18ed0();
  UNK_00ca95 = 0;
  UNK_00ca9e = 0;
  while( true ) {
    cVar3 = UNK_00ca9e;
    cVar5 = UNK_00ca9e;
    if ((char)('#' - cVar5) < '\0' != SBORROW1('#',cVar3)) break;
    cVar3 = UNK_00c702;
    if (cVar3 == '\x01') {
      cVar3 = UNK_00ca9e;
      *(undefined2 *)(uint3)(ushort)((short)&UNK_00c0c0 + cVar3 * 2) = 0x8000;
    }
    else {
      sVar4 = DAT_00c936;
      if (sVar4 < sRamc05b8a) {
        cVar3 = UNK_00ca9e;
        uVar1 = (short)&UNK_00c0c0 + cVar3 * 2;
        puVar2 = (undefined2 *)(cVar3 * 2 + 0x5bd4);
        if (*(ushort *)(uint3)uVar1 < *(ushort *)ZEXT23(puVar2)) {
          *(undefined2 *)(uint3)uVar1 = *puVar2;
        }
      }
      else {
        cVar3 = UNK_00ca9e;
        uVar1 = (short)&UNK_00c0c0 + cVar3 * 2;
        puVar2 = (undefined2 *)(cVar3 * 2 + 0x5b8c);
        if (*(ushort *)(uint3)uVar1 < *(ushort *)ZEXT23(puVar2)) {
          *(undefined2 *)(uint3)uVar1 = *puVar2;
        }
      }
    }
    cVar3 = UNK_00ca9e;
    UNK_00ca9e = cVar3 + '\x01';
  }
  UNK_00ca99 = 0;
  UNK_00c801 = 0;
  UNK_00c802 = 0;
  Ram00c7d4 = 0;
  Ram00c7d6 = 0;
  UNK_00ca8d = 0;
  UNK_00ca9b = 0;
  Ram00c862 = 0x20;
  return;
}

