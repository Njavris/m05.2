// c0e722 cc22_23_hysteresis_a size=62 cc=unknown proto=undefined cc22_23_hysteresis_a(void)

void cc22_23_hysteresis_a(ushort param_1)

{
  short sVar1;
  
  sVar1 = DAT_00c450;
  if (sVar1 == 0) {
    if (param_1 < 0x6901) {
      return;
    }
  }
  else {
    if (sVar1 == 1) {
      if (param_1 < 0x6400) {
        DAT_00c450 = 0;
      }
      if (param_1 < 0xa401) {
        return;
      }
      DAT_00c450 = 2;
      return;
    }
    if (sVar1 != 2) {
      return;
    }
    if (0x9fff < param_1) {
      return;
    }
  }
  DAT_00c450 = 1;
  return;
}

