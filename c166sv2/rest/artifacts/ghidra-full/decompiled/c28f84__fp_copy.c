// c28f84 fp_copy size=16 cc=unknown proto=undefined fp_copy(void)

void fp_copy(void)

{
  ushort in_r4;
  ushort in_r10;
  
  *(undefined2 *)(uint3)in_r4 = *(undefined2 *)(uint3)in_r10;
  *(undefined2 *)(uint3)(in_r4 + 2) = *(undefined2 *)(uint3)(in_r10 + 2);
  *(undefined2 *)(uint3)(in_r4 + 4) = *(undefined2 *)(uint3)(in_r10 + 4);
  *(undefined2 *)(uint3)(in_r4 + 6) = *(undefined2 *)(uint3)(in_r10 + 6);
  return;
}

