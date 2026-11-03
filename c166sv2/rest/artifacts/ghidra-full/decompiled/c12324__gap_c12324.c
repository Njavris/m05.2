// c12324 gap_c12324 size=116 cc=unknown proto=undefined gap_c12324(void)

/* WARNING: Removing unreachable block (ram,0xc124bc) */
/* WARNING: Removing unreachable block (ram,0xc124c6) */
/* WARNING: Removing unreachable block (ram,0xc124cc) */
/* WARNING: Removing unreachable block (ram,0xc124ae) */
/* WARNING: Removing unreachable block (ram,0xc124b8) */
/* WARNING: Removing unreachable block (ram,0xc124ba) */
/* WARNING: Removing unreachable block (ram,0xc124b6) */
/* WARNING: Removing unreachable block (ram,0xc124c4) */

void gap_c12324(void)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  
  UNK_00c55d = 0;
  UNK_00c55f = 0;
  UNK_00c55e = 0;
  UNK_00c55b = 0;
  UNK_00c55a = 0;
  UNK_00cb58 = 0;
  sVar3 = Ram00c5c2;
  if ((sVar3 == 0) && (cVar1 = UNK_00c578, cVar1 == '\x02')) {
    bVar2 = UNK_00f63e;
    UNK_00cb46 = bVar2;
    if (bVar2 < 9) {
      sVar3 = 3;
      UNK_00f640 = bVar2;
      bVar2 = UNK_00cb46;
      if (bVar2 < 7) {
                    /* WARNING: Could not emulate address calculation at 0xc12394 */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((uint3)*(ushort *)((ushort)bVar2 * 2 + 0x70b4 & 0x3fff) | 0xc10000))();
        return;
      }
    }
  }
  func_0xc128ec(0x12,sVar3);
  return;
}

