// c20e96 gap_c20e96 size=198 cc=unknown proto=undefined gap_c20e96(void)

void gap_c20e96(void)

{
  ushort uVar1;
  undefined2 *puVar2;
  char cVar3;
  short sVar4;
  char cVar5;
  
  gap_c18ed0();
  UNK_00ca94 = 0;
  UNK_00ca9c = 0;
  while( true ) {
    cVar3 = UNK_00ca9c;
    cVar5 = UNK_00ca9c;
    if ((char)('#' - cVar5) < '\0' != SBORROW1('#',cVar3)) break;
    cVar3 = UNK_00c702;
    if (cVar3 == '\x01') {
      cVar3 = UNK_00ca9c;
      *(undefined2 *)(uint3)(ushort)((short)&DAT_00c016 + cVar3 * 2) = 0x8000;
    }
    else {
      sVar4 = DAT_00c936;
      if (sVar4 < sRamc05b8a) {
        cVar3 = UNK_00ca9c;
        uVar1 = (short)&DAT_00c016 + cVar3 * 2;
        puVar2 = (undefined2 *)(cVar3 * 2 + 0x5bd4);
        if (*(ushort *)(uint3)uVar1 < *(ushort *)ZEXT23(puVar2)) {
          *(undefined2 *)(uint3)uVar1 = *puVar2;
        }
      }
      else {
        cVar3 = UNK_00ca9c;
        uVar1 = (short)&DAT_00c016 + cVar3 * 2;
        puVar2 = (undefined2 *)(cVar3 * 2 + 0x5b8c);
        if (*(ushort *)(uint3)uVar1 < *(ushort *)ZEXT23(puVar2)) {
          *(undefined2 *)(uint3)uVar1 = *puVar2;
        }
      }
    }
    cVar3 = UNK_00ca9c;
    UNK_00ca9c = cVar3 + '\x01';
  }
  UNK_00ca98 = 0;
  UNK_00c7ff = 0;
  UNK_00c800 = 0;
  Ram00c7d0 = 0;
  Ram00c7d2 = 0;
  UNK_00ca8c = 0;
  UNK_00ca9b = 0;
  UNK_00ca9a = 0;
  Ram00c862 = 0x20;
  return;
}

