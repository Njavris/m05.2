// c2042a gap_c2042a size=22 cc=unknown proto=undefined gap_c2042a(void)

void gap_c2042a(void)

{
  short sVar1;
  short sVar2;
  char cVar3;
  short sVar4;
  
  cVar3 = UNK_00c94c;
  if (cVar3 == '\0') {
    sVar4 = Ram00c94e;
    sVar1 = Ram00c0ae;
    sVar2 = Ram00c0ae;
    if (sVar4 != sVar2 && sVar4 - sVar2 < 0 == SBORROW2(sVar4,sVar1)) {
      Ram00c0ae = sVar4;
    }
  }
  return;
}

