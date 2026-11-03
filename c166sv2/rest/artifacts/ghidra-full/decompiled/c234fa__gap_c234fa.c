// c234fa gap_c234fa size=90 cc=unknown proto=undefined gap_c234fa(void)

short gap_c234fa(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  
  uVar2 = 0;
  sVar3 = 0;
  do {
    cVar1 = func_0xc24286(uVar2);
    sVar4 = sVar3;
    if ((((cVar1 == '\b') || (cVar1 = func_0xc24286(uVar2), cVar1 == '\x04')) ||
        (cVar1 = func_0xc24286(uVar2), cVar1 == '\x02')) &&
       ((cVar1 = func_0xc2465c(uVar2), cVar1 != '\0' && (sVar4 = sVar3 + 1, sVar3 + 1 == 0)))) {
      sVar4 = sVar3;
    }
    uVar2 = uVar2 + 1;
    sVar3 = sVar4;
  } while (uVar2 < 0x27);
  return sVar4;
}

