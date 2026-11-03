// c28b50 gap_c28b50 size=20 cc=unknown proto=undefined gap_c28b50(void)

void gap_c28b50(ushort param_1,ushort param_2,short param_3)

{
  undefined2 *puVar1;
  
  if (param_3 == 0) {
    return;
  }
  do {
    puVar1 = (undefined2 *)(uint3)param_2;
    param_2 = param_2 + 2;
    *(undefined2 *)(uint3)param_1 = *puVar1;
    param_1 = param_1 + 2;
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return;
}

