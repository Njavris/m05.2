/* c1064c t7_timestamp */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Returns a short T7 timestamp with overflow extension. */

short t7_timestamp(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  uVar1 = T7;
  if ((uVar1 < 0x8001) && (uVar2 = T7IC, (uVar2 & 0x80) != 0)) {
    sVar3 = (uVar1 >> 3) + _t7_offset_short + 0x2000;
  }
  else {
    sVar3 = (uVar1 >> 3) + _t7_offset_short;
  }
  return sVar3;
}


