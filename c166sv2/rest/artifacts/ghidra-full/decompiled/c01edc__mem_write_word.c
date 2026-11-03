// c01edc mem_write_word size=14 cc=unknown proto=undefined mem_write_word(void)

short mem_write_word(void)

{
  ushort in_r4;
  short in_r5;
  undefined2 in_r10;
  undefined2 in_r11;
  
  *(undefined2 *)(uint3)in_r4 = in_r10;
  *(undefined2 *)(uint3)(in_r4 + 2) = in_r11;
  return in_r5 + (ushort)(0xfffd < in_r4);
}

