// c276ba FUN_c276ba size=54 cc=unknown proto=undefined FUN_c276ba(void)

short FUN_c276ba(ushort param_1,ushort param_2)

{
  short sVar1;
  short sVar2;
  
  sVar2 = param_1 + param_2;
  sVar1 = ((short)param_2 >> 0xf) + (ushort)CARRY2(param_1,param_2);
  if (sVar1 < (short)(ushort)(sVar2 != -1)) {
    if (sVar1 == 0 && sVar2 == 0 || sVar1 < 0) {
      sVar2 = 0;
    }
  }
  else {
    sVar2 = -1;
  }
  return sVar2;
}

