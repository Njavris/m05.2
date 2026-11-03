// c017a8 kwp_sid31_routine size=66 cc=unknown proto=undefined kwp_sid31_routine(void)

void kwp_sid31_routine(void)

{
  char cVar1;
  
  cVar1 = DAT_00c09a;
  if (cVar1 != '\x01') {
    DAT_00c0b5 = 3;
    DAT_00c0b6 = 0x7f;
    DAT_00c0b7 = 0x31;
    DAT_00c0b8 = 0xbd;
    return;
  }
  DAT_00c09b = 1;
  DAT_00c0b5 = 2;
  DAT_00c0b6 = 0x71;
  DAT_00c0b7 = 2;
  return;
}

