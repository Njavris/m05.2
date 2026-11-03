// c10d18 FUN_c10d18 size=24 cc=unknown proto=undefined FUN_c10d18(void)

ushort FUN_c10d18(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  uVar1 = DAT_00f000;
  if ((uVar1 & 0x40) != 0) {
    uVar2 = 0x40;
  }
  if ((uVar1 & 0x80) != 0) {
    uVar2 = uVar2 | 0x80;
  }
  return uVar2;
}

