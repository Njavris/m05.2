// c14300 gap_c14300 size=62 cc=unknown proto=undefined gap_c14300(void)

bool gap_c14300(void)

{
  short sVar1;
  ushort uVar2;
  
  if (DAT_c0506a == 1) {
    uVar2 = gap_c10398(0xe);
    if (0x265 < uVar2 >> 6) {
      Ram00c600 = 1;
    }
    if (uVar2 >> 6 < 0x200) {
      Ram00c600 = 0;
    }
  }
  else {
    uVar2 = P5;
    Ram00c600 = (uVar2 & 0x4000) >> 0xe;
  }
  sVar1 = Ram00c600;
  return sVar1 != 0;
}

