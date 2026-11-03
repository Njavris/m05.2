// c24c72 gap_c24c72 size=66 cc=unknown proto=undefined gap_c24c72(void)

void gap_c24c72(short param_1,undefined2 param_2,byte param_3)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = 0;
  while( true ) {
    if (param_3 <= bVar2) {
      return;
    }
    cVar1 = func_0xc24286(*(undefined2 *)(uint3)(param_1 + (ushort)bVar2 * 2));
    if (cVar1 == '\0') break;
    gap_c247e6(param_2);
    bVar2 = bVar2 + 1;
  }
  gap_c24802(param_2);
  return;
}

