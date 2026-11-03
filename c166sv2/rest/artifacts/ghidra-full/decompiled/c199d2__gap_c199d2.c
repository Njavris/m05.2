// c199d2 gap_c199d2 size=28 cc=unknown proto=undefined gap_c199d2(void)

void gap_c199d2(void)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  
  gap_c19ab2();
  gap_c19ae6();
  bVar2 = UNK_00c898;
  if (7 < bVar2) {
    UNK_00c898 = 0xff;
    cVar3 = UNK_00c898;
    UNK_00c898 = cVar3 + '\x01';
    func_0xc1984a(1);
    uVar1 = UNK_00c897;
    func_0xc1984c(uVar1);
    return;
  }
                    /* WARNING: Could not emulate address calculation at 0xc199ea */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((ushort)bVar2 * 2 + 0x7656 & 0x3fff) | 0xc10000))();
  return;
}

