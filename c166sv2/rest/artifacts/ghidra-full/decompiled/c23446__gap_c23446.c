// c23446 gap_c23446 size=120 cc=unknown proto=undefined gap_c23446(void)

undefined1 * gap_c23446(short param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  while ((*(short *)(sRam007340 + (ushort)bVar1 * 2) != 0xb &&
         (*(short *)(sRam007340 + (ushort)bVar1 * 2) != param_1))) {
    bVar1 = bVar1 + 1;
  }
  return &stack0x0000;
}

