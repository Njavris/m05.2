// c270da gap_c270da size=94 cc=unknown proto=undefined gap_c270da(void)

void gap_c270da(void)

{
  ushort uVar1;
  char cVar2;
  
  cVar2 = DAT_00c81c;
  if ((((cVar2 == '\0') || (cVar2 = DAT_00cad6, cVar2 == '\0')) ||
      (cVar2 = FUN_c243a8(0xe), cVar2 != '\0')) ||
     ((cVar2 = FUN_c243a8(0xf), cVar2 != '\0' || (uVar1 = Ram00c99a, uRamc07e4e <= uVar1)))) {
    uRame008f6 = 0;
    Ram00cc9e = 0;
  }
  else {
    uVar1 = Ram00cc9e;
    if (uVar1 < uRamc07e54) {
      uRame008f6 = 0;
      UNK_00cca2 = 1;
    }
    else {
      uRame008f6 = 1;
      UNK_00cca2 = 0;
    }
  }
  return;
}

