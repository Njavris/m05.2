// c19860 gap_c19860 size=114 cc=unknown proto=undefined gap_c19860(void)

void gap_c19860(void)

{
  byte bVar1;
  char cVar2;
  
  func_0xc19848(0);
  bVar1 = UNK_00c896;
  if ((bVar1 & 1) == 1) {
    func_0xc19ada();
    bVar1 = UNK_00c896;
    if ((bVar1 & 3) == 1) {
      func_0xc19af8();
      bVar1 = UNK_00c896;
      if ((bVar1 & 7) == 1) {
        func_0xc19b16();
        bVar1 = UNK_00c896;
        if ((bVar1 & 0x1f) == 1) {
          func_0xc19b76();
        }
        bVar1 = UNK_00c896;
        if ((bVar1 & 0x1f) == 0x11) {
          func_0xc19b78();
        }
      }
    }
  }
  else {
    func_0xc19ad8();
  }
  func_0xc1984a(0);
  bVar1 = UNK_00c896;
  func_0xc1984e(bVar1 & 3);
  cVar2 = UNK_00c896;
  UNK_00c896 = cVar2 + '\x02';
  return;
}

