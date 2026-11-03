/* c13f9a capture_input_select */

/* Writes the low bits of 0xFD1A (capture input selection). */

void capture_input_select(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = capture_input_select;
  capture_input_select = uVar1 & 0xfc | param_1 & 0xff;
  return;
}


