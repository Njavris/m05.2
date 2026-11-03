// c269f6 gap_c269f6 size=68 cc=unknown proto=undefined gap_c269f6(void)

void gap_c269f6(void)

{
  ushort uVar1;
  char cVar2;
  
  cVar2 = UNK_00cc7e;
  if (((cVar2 == '\0') && (cVar2 = gap_c2699e(), cVar2 == '\x01')) &&
     (cVar2 = UNK_00cc80, cVar2 == '\0')) {
    uVar1 = Ram00cc78;
    if (uRamc07e24 <= uVar1) {
      UNK_00cc84 = 0;
      UNK_00cc83 = 1;
      return;
    }
    UNK_00cc84 = 1;
  }
  else {
    UNK_00cc84 = 0;
    Ram00cc78 = 0;
  }
  UNK_00cc83 = 0;
  return;
}

