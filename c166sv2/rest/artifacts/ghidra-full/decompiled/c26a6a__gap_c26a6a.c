// c26a6a gap_c26a6a size=52 cc=unknown proto=undefined gap_c26a6a(void)

void gap_c26a6a(void)

{
  char cVar1;
  
  cVar1 = UNK_00cc83;
  if (cVar1 != '\x01') {
    uRame008ea = 0;
    return;
  }
  uRame008ea = rate_limit(uRame008ea,uRame00890,uRamc07e1c);
  return;
}

