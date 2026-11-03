// c13f88 gap_c13f88 size=18 cc=unknown proto=undefined gap_c13f88(void)

void gap_c13f88(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd10;
  if (((uVar1 & 4) == 0) && (DAT_c05064 == 0)) {
    uVar1 = DAT_00fd1a;
    DAT_00fd1a = uVar1 | 0x20;
  }
  return;
}

