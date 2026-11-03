// c1ff2a gap_c1ff2a size=180 cc=unknown proto=undefined gap_c1ff2a(void)

void gap_c1ff2a(void)

{
  char cVar1;
  ushort uVar2;
  
  func_0xc159bc((short)&UNK_00ca8a,(short)&UNK_00ca88,1);
  cVar1 = DAT_00c93c;
  if (cVar1 == '\x01') {
    uVar2 = DAT_00fd18;
    if ((uVar2 & 8) != 0) {
      cVar1 = UNK_00c9e7;
      if ((cVar1 == cRamc06cfc) || (cVar1 == cRamc06cfd)) {
        UNK_00ca88 = 1;
      }
      else {
        UNK_00ca88 = 0;
      }
      uVar2 = Ram00ca8a;
      if (99 < uVar2) {
        uVar2 = Ram00ca8a;
        if (uVar2 < 0xa4) {
          cRame00855 = cRamc06cfd;
          return;
        }
        cRame00855 = cRamc06ce2;
        return;
      }
      cRame00855 = cRamc06cfc;
      return;
    }
    cVar1 = UNK_00c9e7;
    if (cVar1 != cRamc06ce2) {
      cRame00855 = cRamc06ce2;
    }
    UNK_00ca88 = 0;
    Ram00ca8a = 0;
  }
  return;
}

