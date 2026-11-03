// c19d0a gap_c19d0a size=36 cc=unknown proto=undefined gap_c19d0a(void)

void gap_c19d0a(void)

{
  short sVar1;
  char cVar2;
  
  cVar2 = DAT_00c93c;
  if (cVar2 == '\x03') {
    UNK_00c8a2 = 1;
  }
  cVar2 = UNK_00c8a2;
  if ((cVar2 != '\0') && (sVar1 = Ram00c8a0, sVar1 != -1)) {
    sVar1 = Ram00c8a0;
    Ram00c8a0 = sVar1 + 1;
  }
  return;
}

