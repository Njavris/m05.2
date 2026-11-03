// c142da gap_c142da size=38 cc=unknown proto=undefined gap_c142da(void)

bool gap_c142da(void)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = gap_c10398(10);
  if (0x2cb < uVar2 >> 6) {
    Ram00c5fe = 1;
  }
  if (uVar2 >> 6 < 0x200) {
    Ram00c5fe = 0;
  }
  sVar1 = Ram00c5fe;
  return sVar1 != 0;
}

