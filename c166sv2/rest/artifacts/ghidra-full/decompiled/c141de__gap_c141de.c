// c141de gap_c141de size=30 cc=unknown proto=undefined gap_c141de(void)

void gap_c141de(ushort param_1)

{
  DAT_00c406 = (ushort)((uint)param_1 * 1000) >> 6 | (short)((uint)param_1 * 1000 >> 0x10) << 10;
  return;
}

