// c255cc gap_c255cc size=52 cc=unknown proto=undefined gap_c255cc(void)

void gap_c255cc(void)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = UNK_00c702;
  if (cVar1 == '\0') {
    uVar2 = 0;
    do {
      gap_c243ea(uVar2);
      gap_c2444c(uVar2);
      func_0xc24722(uVar2);
      func_0xc24572(uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x27);
  }
  else {
    func_0xc25414();
  }
  return;
}

