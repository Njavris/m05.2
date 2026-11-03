// c23554 gap_c23554 size=104 cc=unknown proto=undefined gap_c23554(void)

undefined1 gap_c23554(char param_1,ushort param_2)

{
  if (param_1 == '\0') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76c8);
  }
  if (param_1 == '\x01') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76cc);
  }
  if (param_1 == '\x02') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76d0);
  }
  if (param_1 == '\x03') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76d4);
  }
  if (param_1 == '\x04') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76d8);
  }
  if (param_1 == '\x05') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76dc);
  }
  if (param_1 == '\x06') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76e4);
  }
  if (param_1 != '\a') {
    return 0;
  }
  return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76e0);
}

