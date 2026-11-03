// c28f0e fp_round size=16 cc=unknown proto=undefined fp_round(void)

void fp_round(void)

{
  bool bVar1;
  bool bVar2;
  ushort in_r1;
  ushort in_r3;
  short in_r4;
  ushort in_r5;
  ushort unaff_r7;
  ushort unaff_r8;
  ushort unaff_r9;
  ushort in_r10;
  
  if ((in_r3 & 0x8000) != 0) {
    bVar1 = 0xfffe < in_r5;
    in_r5 = in_r5 + 1;
    bVar2 = CARRY2(unaff_r9,(ushort)bVar1);
    unaff_r9 = unaff_r9 + bVar1;
    bVar1 = CARRY2(unaff_r8,(ushort)bVar2);
    unaff_r8 = unaff_r8 + bVar2;
    unaff_r7 = unaff_r7 + bVar1;
    if ((unaff_r7 & 0x20) != 0) {
      fp_store();
      return;
    }
  }
  *(ushort *)(uint3)(in_r10 + 6) = in_r5;
  *(ushort *)(uint3)(in_r10 + 4) = unaff_r9;
  *(ushort *)(uint3)(in_r10 + 2) = unaff_r8;
  *(ushort *)(uint3)in_r10 = unaff_r7 & 0xf | (in_r1 & 0x7ff) << 4 | in_r4 << 0xf;
  return;
}

