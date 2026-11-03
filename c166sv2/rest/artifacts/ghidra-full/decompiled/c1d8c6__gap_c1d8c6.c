// c1d8c6 gap_c1d8c6 size=68 cc=unknown proto=undefined gap_c1d8c6(void)

void gap_c1d8c6(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00c06a;
  uVar1 = axis16_unsigned(0x7546,uVar1);
  uVar1 = tbl16_interp(0x6c7a,0xc0,uVar1);
  DAT_00ca04 = uVar1;
  Ram00ca16 = uVar1;
  DAT_00c9f8 = 0;
  Ram00ca0e = 0x2d00;
  Ram00c9fe = 0x2d00;
  func_0xc1d87a();
  uVar1 = DAT_00ca04;
  Ram00ca1c = uVar1;
  func_0xc1d8b2();
  return;
}

