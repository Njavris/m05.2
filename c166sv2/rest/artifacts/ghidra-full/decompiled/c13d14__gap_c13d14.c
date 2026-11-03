// c13d14 gap_c13d14 size=54 cc=unknown proto=undefined gap_c13d14(void)

void gap_c13d14(void)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = UNK_00c578;
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      bVar2 = DAT_00c5c4;
      if (*(char *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) == '\x01') goto LAB_c13d2c;
      bVar2 = DAT_00c5c4;
      if (*(char *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) == '\x02') {
        DAT_00c59e = 0;
        return;
      }
    }
    func_0xc128ec(0x12);
    return;
  }
LAB_c13d2c:
  gap_c12910(1);
  return;
}

