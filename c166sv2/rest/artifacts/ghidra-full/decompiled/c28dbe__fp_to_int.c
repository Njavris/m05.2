// c28dbe fp_to_int size=50 cc=unknown proto=undefined fp_to_int(void)

ushort fp_to_int(void)

{
  short sVar1;
  ushort extraout_r1;
  ushort uVar2;
  short unaff_r7;
  ushort unaff_r8;
  
  uVar2 = fp_pack_zero();
  if (((uVar2 & 1) == 0) && (0x3fe < extraout_r1)) {
    sVar1 = (short)&UNK_00fbf2 + extraout_r1;
    if (sVar1 == 0 || extraout_r1 < 0x40e) {
      uVar2 = (unaff_r7 << 0xb | unaff_r8 >> 5) >> -sVar1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

