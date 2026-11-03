// c13f9a capture_input_select size=24 cc=unknown proto=undefined capture_input_select(void)

void capture_input_select(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd1a;
  DAT_00fd1a = uVar1 & 0xfc | param_1 & 0xff;
  return;
}

