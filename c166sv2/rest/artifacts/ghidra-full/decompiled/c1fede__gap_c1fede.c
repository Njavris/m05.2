// c1fede gap_c1fede size=76 cc=unknown proto=undefined gap_c1fede(void)

void gap_c1fede(void)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = DAT_00c93c;
  if (cVar1 != '\x03') {
    UNK_00ca86 = 3;
    return;
  }
  uVar2 = DAT_00ca2a;
  if (uVar2 <= uRamc079d6) {
    UNK_00ca86 = 0;
    return;
  }
  uVar2 = DAT_00ca2a;
  if ((uRamc079d6 < uVar2) && (uVar2 <= uRamc079d8)) {
    UNK_00ca86 = 1;
    return;
  }
  UNK_00ca86 = 2;
  return;
}

