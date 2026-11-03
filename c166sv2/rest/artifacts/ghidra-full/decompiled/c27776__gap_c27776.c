// c27776 gap_c27776 size=60 cc=unknown proto=undefined gap_c27776(void)

undefined4 gap_c27776(ushort param_1,short param_2,ushort param_3,short param_4)

{
  short sVar1;
  short sVar2;
  
  sVar1 = param_1 + param_3;
  sVar2 = param_2 + param_4 + (ushort)CARRY2(param_1,param_3);
  if (((-1 < sVar2) && (param_4 < 0)) && (param_2 < 0)) {
    sVar1 = 0;
    sVar2 = -0x8000;
  }
  if (((sVar2 < 0) && (-1 < param_4)) && (-1 < param_2)) {
    sVar1 = -1;
    sVar2 = 0x7fff;
  }
  return CONCAT22(sVar2,sVar1);
}

