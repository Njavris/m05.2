// c1b5fe gap_c1b5fe size=96 cc=unknown proto=undefined gap_c1b5fe(void)

void gap_c1b5fe(void)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = DAT_00c954;
  if ((cVar1 == '\0') && (uVar2 = Ram00c946, uVar2 < uRamc06c40)) {
    UNK_00c941 = 1;
  }
  else {
    cVar1 = DAT_00c954;
    if ((cVar1 == '\0') && (uVar2 = Ram00c946, uRamc06c40 <= uVar2)) {
      UNK_00c940 = 1;
      UNK_00c941 = 0;
    }
    else {
      UNK_00c940 = 0;
      UNK_00c941 = 0;
      Ram00c946 = 0;
    }
  }
  cVar1 = UNK_00c940;
  if ((cVar1 != '\0') && (cVar1 = UNK_00c9e6, cVar1 != '\0')) {
    gap_c1c410();
    UNK_00c94a = 1;
  }
  return;
}

