// c0e606 FUN_c0e606 size=38 cc=unknown proto=undefined FUN_c0e606(void)

ushort FUN_c0e606(ushort param_1)

{
  return (ushort)((uint)param_1 * (uint)DAT_c05060) >> 7 |
         (short)((uint)param_1 * (uint)DAT_c05060 >> 0x10) << 9;
}

