// c20450 gap_c20450 size=28 cc=unknown proto=undefined gap_c20450(void)

void gap_c20450(void)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  
  cVar2 = DAT_00c0b6;
  DAT_00c0b6 = cVar2 + '\x01';
  bVar3 = DAT_00c0b6;
  if (0xe0 < bVar3) {
    sVar1 = Ram00c00c;
    Ram00c00c = sVar1 + 1;
    sVar1 = DAT_00c0a8;
    DAT_00c0a8 = sVar1 + 1;
    DAT_00c0b6 = 0;
  }
  return;
}

