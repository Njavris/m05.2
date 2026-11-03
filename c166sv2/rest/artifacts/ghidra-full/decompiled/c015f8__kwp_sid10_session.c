// c015f8 kwp_sid10_session size=114 cc=unknown proto=undefined kwp_sid10_session(void)

void kwp_sid10_session(void)

{
  char cVar1;
  
  cVar1 = DAT_00c149;
  if (cVar1 == -0x7f) {
    DAT_00c0b5 = 2;
    DAT_00c0b6 = 0x50;
    DAT_00c0b7 = 0x81;
  }
  else if (cVar1 == -0x7b) {
    cVar1 = DAT_00c09a;
    if (cVar1 == '\x01') {
      DAT_00c0b5 = 2;
      DAT_00c0b6 = 0x50;
      DAT_00c0b7 = 0x85;
    }
    else {
      DAT_00c0b5 = 3;
      DAT_00c0b6 = 0x7f;
      DAT_00c0b7 = 0x10;
      DAT_00c0b8 = 0x85;
    }
  }
  DAT_00c0b2 = 0x80;
  return;
}

