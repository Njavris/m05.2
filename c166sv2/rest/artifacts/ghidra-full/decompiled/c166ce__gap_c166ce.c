// c166ce gap_c166ce size=72 cc=unknown proto=undefined gap_c166ce(void)

void gap_c166ce(ushort param_1,undefined2 param_2,undefined2 param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  
  sVar4 = func_0xc14740();
  sVar3 = Ram00c000;
  sVar1 = *(short *)(uint3)param_1;
  sVar2 = *(short *)(uint3)(param_1 + 2);
  *(undefined2 *)(uint3)(param_1 + 2) = param_3;
  *(undefined2 *)(uint3)param_1 = param_2;
  Ram00c000 = ((sVar3 + sVar1 + sVar2) - *(short *)(uint3)param_1) - *(short *)(uint3)(param_1 + 2);
  func_0xc14750(sVar4 >> 0xf);
  return;
}

