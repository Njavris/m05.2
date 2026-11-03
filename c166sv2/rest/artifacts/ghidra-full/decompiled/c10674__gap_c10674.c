// c10674 gap_c10674 size=36 cc=unknown proto=undefined gap_c10674(void)

short gap_c10674(void)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = T7IC;
  if ((uVar2 & 0x80) == 0) {
    uVar2 = T7;
    sVar1 = DAT_00c4c8;
    return (uVar2 >> 3) + sVar1;
  }
  uVar2 = T7;
  sVar1 = DAT_00c4c8;
  return (uVar2 >> 3) + sVar1 + 0x2000;
}

