// c12910 gap_c12910 size=44 cc=unknown proto=undefined gap_c12910(void)

void gap_c12910(char param_1)

{
  byte bVar1;
  byte bVar2;
  
  if (param_1 == '\0') {
    kline_prepare_frame(0);
    return;
  }
  bVar1 = DAT_00c5c4;
  bVar2 = UNK_00c5c7;
  *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar2) =
       *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar1) + '@';
  gap_c12856(param_1);
  return;
}

