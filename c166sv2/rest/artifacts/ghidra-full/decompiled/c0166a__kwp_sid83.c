// c0166a kwp_sid83 size=88 cc=unknown proto=undefined kwp_sid83(void)

void kwp_sid83(void)

{
  char cVar1;
  
  cVar1 = DAT_00c149;
  if (cVar1 == '\0') {
    DAT_00c0b2 = 0x87;
    DAT_00c0b5 = 7;
    DAT_00c0b6 = 0xc3;
    DAT_00c0b7 = 0;
    DAT_00c0b8 = 0;
    DAT_00c0b9 = 0xff;
    DAT_00c0ba = 0;
    DAT_00c0bb = 0xff;
    DAT_00c0bc = 0;
  }
  else if (cVar1 == '\x03') {
    DAT_00c0b2 = 0x82;
    DAT_00c0b5 = 2;
    DAT_00c0b6 = 0xc3;
    DAT_00c0b7 = 3;
    return;
  }
  return;
}

