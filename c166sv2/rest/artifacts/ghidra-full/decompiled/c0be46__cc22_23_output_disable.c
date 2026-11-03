// c0be46 cc22_23_output_disable size=18 cc=unknown proto=undefined cc22_23_output_disable(void)

void cc22_23_output_disable(short param_1)

{
  ushort uVar1;
  
  if (param_1 != 0) {
    uVar1 = CCM5;
    CCM5 = uVar1 & 0xf8ff;
    return;
  }
  uVar1 = CCM5;
  CCM5 = uVar1 & 0x8fff;
  return;
}

