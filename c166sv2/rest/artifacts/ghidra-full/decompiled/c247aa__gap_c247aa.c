// c247aa gap_c247aa size=60 cc=unknown proto=undefined gap_c247aa(void)

void gap_c247aa(ushort param_1)

{
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  uStack_4 = *(ushort *)(uint3)param_1;
  uStack_2 = *(ushort *)(uint3)(param_1 + 2);
  while( true ) {
    if ((uStack_4 | uStack_2) == 0) break;
    empty_stub_0(uStack_4 | uStack_2);
    uStack_4 = *(ushort *)(uint3)(param_1 + 4);
    uStack_2 = *(ushort *)(uint3)(param_1 + 6);
    param_1 = param_1 + 4;
  }
  return;
}

