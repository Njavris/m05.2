// c0e62c FUN_c0e62c size=38 cc=unknown proto=undefined FUN_c0e62c(void)

ushort FUN_c0e62c(ushort param_1)

{
  return (ushort)((uint)param_1 * (uint)DAT_c05061) >> 7 |
         (short)((uint)param_1 * (uint)DAT_c05061 >> 0x10) << 9;
}

