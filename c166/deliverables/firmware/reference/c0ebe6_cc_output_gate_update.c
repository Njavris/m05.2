/* c0ebe6 cc_output_gate_update */

/* Updates the CC output gate bits in 0xFD08/0xFD06. */

void cc_output_gate_update(void)

{
  ushort uVar1;
  
  uVar1 = capture_status_1;
  if (((uVar1 & 4) == 0) && (uVar1 = capture_input_select, (uVar1 & 0x20) != 0)) {
    uVar1 = output_gate_0;
    output_gate_0 = uVar1 | 0x8000;
  }
  else {
    uVar1 = output_gate_0;
    output_gate_0 = uVar1 & 0x7fff;
  }
  uVar1 = capture_status_0;
  if (((uVar1 & 4) == 0) && (uVar1 = capture_input_select, (uVar1 & 0x10) != 0)) {
    uVar1 = output_gate_1;
    output_gate_1 = uVar1 | 0x8000;
    return;
  }
  uVar1 = output_gate_1;
  output_gate_1 = uVar1 & 0x7fff;
  return;
}


