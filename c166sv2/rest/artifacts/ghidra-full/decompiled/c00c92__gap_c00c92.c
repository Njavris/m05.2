// c00c92 gap_c00c92 size=14 cc=unknown proto=undefined gap_c00c92(void)

bool gap_c00c92(void)

{
  bool bVar1;
  ushort uVar2;
  
  uVar2 = S0TIC;
  bVar1 = (uVar2 & 0x80) != 0;
  if (bVar1) {
    uVar2 = S0TIC;
    S0TIC = uVar2 & 0xff7f;
  }
  return bVar1;
}

