// c25732 gap_c25732 size=46 cc=unknown proto=undefined gap_c25732(void)

void gap_c25732(void)

{
  char cVar1;
  ushort uVar2;
  
  func_0xc25414();
  uVar2 = 0;
  do {
    cVar1 = func_0xc24286(uVar2);
    if ((cVar1 != '\0') && (cVar1 = func_0xc2465c(uVar2), cVar1 == '\x01')) {
      func_0xc246de(uVar2);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x27);
  return;
}

