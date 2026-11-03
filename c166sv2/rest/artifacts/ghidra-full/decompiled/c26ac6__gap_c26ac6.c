// c26ac6 gap_c26ac6 size=62 cc=unknown proto=undefined gap_c26ac6(void)

void gap_c26ac6(void)

{
  ushort uVar1;
  
  uVar1 = Ram00cc7a;
  if (uVar1 < uRamc07e2a) {
    uVar1 = Ram00cc7c;
    if (uVar1 < uRamc07e2c) {
      UNK_00cc82 = 0;
      return;
    }
    uRame008e8 = 0;
  }
  else {
    uRame008e8 = 1;
  }
  UNK_00cc82 = 1;
  return;
}

