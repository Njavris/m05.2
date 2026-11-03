// c166a2 gap_c166a2 size=44 cc=unknown proto=undefined gap_c166a2(void)

void gap_c166a2(ushort param_1,short param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  sVar3 = func_0xc14740();
  sVar2 = Ram00c000;
  sVar1 = *(short *)(uint3)param_1;
  *(short *)(uint3)param_1 = param_2;
  Ram00c000 = (sVar2 + sVar1) - param_2;
  func_0xc14750(sVar3 >> 0xf);
  return;
}

