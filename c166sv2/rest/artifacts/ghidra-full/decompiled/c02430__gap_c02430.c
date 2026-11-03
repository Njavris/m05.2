// c02430 gap_c02430 size=30 cc=unknown proto=undefined gap_c02430(void)

void gap_c02430(void)

{
  ushort uVar1;
  
  func_0xc02386();
  uVar1 = P1H;
  P1H = uVar1 & 0xffdf | 0x20;
  uRame00020 = uRame00001;
  return;
}

