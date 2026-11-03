/* c01edc mem_write_word */

/* Write two words through a 16:16 pointer. */

void mem_write_word(void)

{
  ushort in_r4;
  ushort in_r5;
  undefined2 in_r10;
  undefined2 in_r11;
  
  *(undefined2 *)((uint3)in_r4 + (uint3)in_r5 * 0x10000) = in_r10;
  *(undefined2 *)((uint3)(in_r4 + 2) + (uint3)(in_r5 + (0xfffd < in_r4)) * 0x10000) = in_r11;
  return;
}


