// c016c2 kwp_sid34_download size=72 cc=unknown proto=undefined kwp_sid34_download(void)

void kwp_sid34_download(void)

{
  char cVar1;
  
  cVar1 = DAT_00c09a;
  if (cVar1 != '\x01') {
    DAT_00c0b5 = 3;
    DAT_00c0b6 = 0x7f;
    DAT_00c0b7 = 0x10;
    DAT_00c0b8 = 0x33;
    return;
  }
  DAT_00c0b2 = 0x82;
  DAT_00c0b5 = 2;
  DAT_00c0b6 = 0x74;
  DAT_00c0b7 = 0xfb;
  return;
}

