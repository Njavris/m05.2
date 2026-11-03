// c10ade gap_c10ade size=10 cc=unknown proto=undefined gap_c10ade(void)

void gap_c10ade(void)

{
  ushort uVar1;
  
  uVar1 = CCM4;
  CCM4 = uVar1 & 0xfff;
  uVar1 = CCM4;
  CCM4 = uVar1 | 0xc000;
  return;
}

