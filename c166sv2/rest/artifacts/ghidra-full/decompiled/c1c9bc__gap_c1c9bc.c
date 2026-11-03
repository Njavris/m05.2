// c1c9bc gap_c1c9bc size=96 cc=unknown proto=undefined gap_c1c9bc(void)

char gap_c1c9bc(char param_1,ushort param_2)

{
  ushort uVar1;
  short sVar2;
  
  uVar1 = param_2 + 1;
  if ((*(byte *)(uint3)uVar1 & 0x7f) == 1) {
    if ((*(byte *)(uint3)uVar1 & 0x80) == 0) {
      param_1 = *(char *)(uint3)param_2;
    }
    else {
      param_1 = -*(char *)(uint3)param_2;
    }
  }
  else if ((*(byte *)(uint3)uVar1 & 0x7f) == 2) {
    if ((*(byte *)(uint3)uVar1 & 0x80) == 0) {
      sVar2 = (short)param_1 + (short)*(char *)(uint3)param_2;
    }
    else {
      sVar2 = (short)param_1 - (short)*(char *)(uint3)param_2;
    }
    if (sVar2 < 0x80) {
      if (sVar2 < -0x80) {
        param_1 = -0x80;
      }
      else {
        param_1 = (char)sVar2;
      }
    }
    else {
      param_1 = '\x7f';
    }
  }
  return param_1;
}

