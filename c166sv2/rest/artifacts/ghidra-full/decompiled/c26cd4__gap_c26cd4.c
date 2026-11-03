// c26cd4 gap_c26cd4 size=102 cc=unknown proto=undefined gap_c26cd4(void)

void gap_c26cd4(void)

{
  byte bVar1;
  
  bVar1 = DAT_00c277;
  if (uRame008f2 < bVar1) {
    bVar1 = DAT_00c277;
    uRame008f2 = (ushort)bVar1;
  }
  func_0xc26d9c();
  func_0xc26ed6();
  func_0xc26f24();
  gap_c24d9a(0x1a,uRame008ed,uRame008f5,(short)&UNK_00cc8a);
  bVar1 = DAT_00c280;
  if (0x32 < bVar1) {
    DAT_00c280 = 0;
    DAT_00c277 = 0;
    DAT_00c264 = 0;
    DAT_00c272 = 0;
    uRame008f2 = 0;
  }
  return;
}

