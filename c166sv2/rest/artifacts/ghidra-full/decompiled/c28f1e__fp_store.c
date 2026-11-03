// c28f1e fp_store size=64 cc=unknown proto=undefined fp_store(void)

void fp_store(void)

{
  ushort in_r1;
  short in_r4;
  undefined2 in_r5;
  ushort unaff_r7;
  undefined2 unaff_r8;
  undefined2 unaff_r9;
  ushort in_r10;
  
  *(undefined2 *)(uint3)(in_r10 + 6) = in_r5;
  *(undefined2 *)(uint3)(in_r10 + 4) = unaff_r9;
  *(undefined2 *)(uint3)(in_r10 + 2) = unaff_r8;
  *(ushort *)(uint3)in_r10 = unaff_r7 & 0xf | (in_r1 & 0x7ff) << 4 | in_r4 << 0xf;
  return;
}

