// c25b38 gap_c25b38 size=110 cc=unknown proto=undefined gap_c25b38(void)

void gap_c25b38(void)

{
  ushort uVar1;
  
  if ((cRame008d3 == '\x01') && (uVar1 = DAT_00c962, uVar1 < uRamc07d2c)) {
    uRame008d2 = 0;
    uRame008d4 = 1;
    return;
  }
  if ((cRame008d3 == '\x01') && (uVar1 = DAT_00c962, uRamc07d2e < uVar1)) {
    uRame008d4 = 0;
    uRame008d2 = 1;
    return;
  }
  uRame008d2 = 0;
  uRame008d4 = 0;
  return;
}

