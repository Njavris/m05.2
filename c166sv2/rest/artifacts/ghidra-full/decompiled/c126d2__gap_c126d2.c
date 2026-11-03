// c126d2 gap_c126d2 size=8 cc=unknown proto=undefined gap_c126d2(void)

void gap_c126d2(void)

{
  ushort uVar1;
  
  uVar1 = S0CON;
  S0CON = uVar1 & 0xffef;
  func_0xc1297a();
  return;
}

