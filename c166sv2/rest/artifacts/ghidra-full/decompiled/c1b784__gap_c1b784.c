// c1b784 gap_c1b784 size=50 cc=unknown proto=undefined gap_c1b784(void)

void gap_c1b784(void)

{
  short sVar1;
  char cVar2;
  
  cVar2 = DAT_00c93c;
  if (cVar2 == '\x03') {
    sVar1 = Ram00c072;
    if (sVar1 != -1) {
      sVar1 = Ram00c072;
      Ram00c072 = sVar1 + 1;
      UNK_00c93d = 1;
    }
    gap_c20450();
    return;
  }
  sVar1 = Ram00c072;
  if (sVar1 != 0) {
    Ram00c06c = sVar1;
  }
  Ram00c072 = 0;
  return;
}

