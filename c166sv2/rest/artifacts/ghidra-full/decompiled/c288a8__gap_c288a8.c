// c288a8 gap_c288a8 size=26 cc=unknown proto=undefined gap_c288a8(void)

undefined4 gap_c288a8(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  short sVar1;
  short sVar2;
  
  if (param_4 < param_2 || param_4 == param_2 && param_3 < param_1) {
    sVar1 = param_1 - param_3;
    sVar2 = (param_2 - param_4) - (ushort)(param_1 < param_3);
  }
  else {
    sVar1 = 0;
    sVar2 = 0;
  }
  return CONCAT22(sVar2,sVar1);
}

