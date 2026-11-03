// c24d9a gap_c24d9a size=54 cc=unknown proto=undefined gap_c24d9a(void)

void gap_c24d9a(char param_1,char param_2,ushort param_3)

{
  if (param_1 != '\0') {
    if ((param_2 == '\0') || (*(char *)(uint3)param_3 == '\x02')) {
      if ((param_2 == '\0') && (*(char *)(uint3)param_3 != '\x01')) {
        func_0xc2572c();
        *(undefined1 *)(uint3)param_3 = 1;
      }
    }
    else {
      func_0xc25710();
      *(undefined1 *)(uint3)param_3 = 2;
    }
  }
  return;
}

