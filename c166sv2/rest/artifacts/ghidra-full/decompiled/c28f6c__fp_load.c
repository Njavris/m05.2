// c28f6c fp_load size=24 cc=unknown proto=undefined fp_load(void)

void fp_load(void)

{
  ushort in_r4;
  undefined1 auStack_8 [2];
  undefined1 auStack_6 [2];
  undefined1 auStack_4 [2];
  undefined1 auStack_2 [2];
  
  *(undefined2 *)ZEXT23(auStack_8) = *(undefined2 *)(uint3)in_r4;
  *(undefined2 *)ZEXT23(auStack_6) = *(undefined2 *)(uint3)(in_r4 + 2);
  *(undefined2 *)ZEXT23(auStack_4) = *(undefined2 *)(uint3)(in_r4 + 4);
  *(undefined2 *)ZEXT23(auStack_2) = *(undefined2 *)(uint3)(in_r4 + 6);
  return;
}

