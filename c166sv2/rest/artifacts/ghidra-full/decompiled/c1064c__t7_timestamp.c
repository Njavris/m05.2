// c1064c t7_timestamp size=40 cc=unknown proto=undefined t7_timestamp(void)

short t7_timestamp(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  uVar1 = T7;
  if ((uVar1 < 0x8001) && (uVar2 = T7IC, (uVar2 & 0x80) != 0)) {
    sVar3 = DAT_00c4c8;
    sVar3 = (uVar1 >> 3) + sVar3 + 0x2000;
  }
  else {
    sVar3 = DAT_00c4c8;
    sVar3 = (uVar1 >> 3) + sVar3;
  }
  return sVar3;
}

