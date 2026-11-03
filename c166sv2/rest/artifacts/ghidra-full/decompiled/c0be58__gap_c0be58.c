// c0be58 gap_c0be58 size=18 cc=unknown proto=undefined gap_c0be58(void)

void gap_c0be58(short param_1)

{
  ushort uVar1;
  
  if (param_1 != 0) {
    uVar1 = CCM5;
    CCM5 = uVar1 & 0xf8ff | 0x500;
    return;
  }
  uVar1 = CCM5;
  CCM5 = uVar1 & 0x8fff | 0x5000;
  return;
}

