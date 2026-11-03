// c0e760 cc22_23_hysteresis_b size=106 cc=unknown proto=undefined cc22_23_hysteresis_b(void)

void cc22_23_hysteresis_b(ushort param_1)

{
  short sVar1;
  
  sVar1 = DAT_00c454;
  if (sVar1 == 0) {
    if (0x1c00 < param_1) {
      DAT_00c454 = 1;
    }
  }
  else if (sVar1 == 1) {
    if (param_1 < 0x1800) {
      DAT_00c454 = 0;
    }
    if ((0x5f00 < param_1) || (sVar1 = DAT_00c450, sVar1 != 0)) {
LAB_c0e7ba:
      DAT_00c454 = 2;
      return;
    }
  }
  else if (sVar1 == 2) {
    if ((param_1 < 0x5a00) && (sVar1 = DAT_00c450, sVar1 == 0)) {
      DAT_00c454 = 1;
    }
    if (0x8400 < param_1) {
      DAT_00c454 = 3;
      return;
    }
  }
  else if ((sVar1 == 3) && (param_1 < 0x8000)) goto LAB_c0e7ba;
  return;
}

