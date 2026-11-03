// c1305e gap_c1305e size=84 cc=unknown proto=undefined gap_c1305e(void)

void gap_c1305e(char param_1,ushort param_2,ushort param_3,char param_4)

{
  char cVar1;
  
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
  cVar1 = func_0xc13a84();
  *(char *)(uint3)param_3 = cVar1 * param_4;
  return;
}

