/* c28c62 store32 */

/* Stores a 32-bit value as two 16-bit words. */

void store32(void)

{
  ushort in_r4;
  ushort in_r5;
  undefined2 in_r10;
  undefined2 in_r11;
  
  *(undefined2 *)((uint3)in_r4 + (uint3)in_r5 * 0x10000) = in_r10;
  *(undefined2 *)((uint3)(in_r4 + 2) + (uint3)(in_r5 + (0xfffd < in_r4)) * 0x10000) = in_r11;
  return;
}


