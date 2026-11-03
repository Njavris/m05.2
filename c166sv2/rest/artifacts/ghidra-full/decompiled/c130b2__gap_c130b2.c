// c130b2 gap_c130b2 size=82 cc=unknown proto=undefined gap_c130b2(void)

void gap_c130b2(char param_1,ushort param_2,ushort param_3,short param_4)

{
  short sVar1;
  
  if (param_1 == '\0') {
    *(undefined1 *)(uint3)param_2 = 0;
    return;
  }
  if (param_1 == '\a') {
    *(undefined1 *)(uint3)param_2 = 1;
  }
  else if (param_1 == -0x80) {
    *(undefined1 *)(uint3)param_2 = 2;
  }
  else {
    if (param_1 != -0x7f) {
      func_0xc13a92(1);
      return;
    }
    *(undefined1 *)(uint3)param_2 = 0x82;
  }
  sVar1 = func_0xc13a84();
  *(short *)(uint3)param_3 = sVar1 * param_4;
  return;
}

