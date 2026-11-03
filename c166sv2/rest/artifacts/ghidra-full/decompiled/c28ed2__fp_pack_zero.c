// c28ed2 fp_pack_zero size=56 cc=unknown proto=undefined fp_pack_zero(void)

undefined4 fp_pack_zero(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort in_r4;
  undefined2 unaff_r7;
  undefined2 unaff_r8;
  undefined2 unaff_r9;
  ushort in_r10;
  
  uVar2 = *(undefined2 *)(uint3)(in_r10 + 6);
  *(undefined2 *)(uint3)(in_r10 + 6) = 0;
  *(undefined2 *)(uint3)(in_r10 + 4) = unaff_r9;
  *(undefined2 *)(uint3)(in_r10 + 2) = unaff_r8;
  uVar1 = *(ushort *)(uint3)in_r10;
  *(undefined2 *)(uint3)in_r10 = unaff_r7;
  uVar3 = PSW;
  return CONCAT22(uVar2,in_r4 & 0xfffe | uVar1 >> 0xf);
}

