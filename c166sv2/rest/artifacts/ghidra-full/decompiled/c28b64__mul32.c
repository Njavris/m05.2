// c28b64 mul32 size=36 cc=unknown proto=undefined mul32(void)

undefined4 mul32(void)

{
  ushort in_r4;
  short in_r5;
  ushort in_r10;
  short in_r11;
  
  __atomic(2);
  __atomic(2);
  __atomic(2);
  return CONCAT22(in_r5 * in_r10 + in_r4 * in_r11 + (short)((uint)in_r4 * (uint)in_r10 >> 0x10),
                  (short)((uint)in_r4 * (uint)in_r10));
}

