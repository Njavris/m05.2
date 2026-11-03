// c03cb8 boot_hidden_i2c_a size=24 cc=unknown proto=undefined boot_hidden_i2c_a(void)

undefined4 boot_hidden_i2c_a(void)

{
  ushort in_r4;
  short in_r5;
  ushort in_r10;
  short in_r11;
  
  return CONCAT22(in_r5 * in_r10 + in_r4 * in_r11 + (short)((uint)in_r4 * (uint)in_r10 >> 0x10),
                  (short)((uint)in_r4 * (uint)in_r10));
}

