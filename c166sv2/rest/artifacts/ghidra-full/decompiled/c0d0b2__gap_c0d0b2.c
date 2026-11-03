// c0d0b2 gap_c0d0b2 size=46 cc=unknown proto=undefined gap_c0d0b2(void)

void gap_c0d0b2(void)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = DAT_00c3d9;
  cVar1 = DAT_00c256;
  if (*(char *)(uint3)((ushort)bVar2 * 2 + 0x700e) == cVar1) {
    FUN_c0f132(0);
  }
  bVar2 = DAT_00c3f3;
  cVar1 = DAT_00c256;
  if (*(char *)(uint3)((short)&DAT_00c468 + (ushort)bVar2 * 2) == cVar1) {
    FUN_c0f132(1);
  }
  return;
}

