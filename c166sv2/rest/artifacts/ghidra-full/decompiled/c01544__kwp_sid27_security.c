// c01544 kwp_sid27_security size=150 cc=unknown proto=undefined kwp_sid27_security(void)

void kwp_sid27_security(void)

{
  char cVar1;
  
  cVar1 = DAT_00c149;
  if (cVar1 == '\x01') {
    DAT_00c0b2 = 0x80;
    DAT_00c0b5 = 4;
    DAT_00c0b6 = 0x67;
    DAT_00c0b7 = 1;
    DAT_00c0b8 = 0x12;
    DAT_00c0b9 = 0x34;
    return;
  }
  if (cVar1 == '\x02') {
    DAT_00c0b5 = 3;
    DAT_00c0b2 = 0x80;
    cVar1 = DAT_00c14a;
    if ((cVar1 == -0x7c) && (cVar1 = DAT_00c14b, cVar1 == 't')) {
      DAT_00c09a = 1;
      DAT_00c0b6 = 0x67;
      DAT_00c0b7 = 2;
      DAT_00c0b8 = 0x34;
      return;
    }
    DAT_00c0b6 = 0x7f;
    DAT_00c0b7 = 0x27;
    DAT_00c0b8 = 0x35;
  }
  return;
}

