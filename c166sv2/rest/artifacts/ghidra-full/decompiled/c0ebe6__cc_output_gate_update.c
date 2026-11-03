// c0ebe6 cc_output_gate_update size=38 cc=unknown proto=undefined cc_output_gate_update(void)

void cc_output_gate_update(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd10;
  if (((uVar1 & 4) == 0) && (uVar1 = DAT_00fd1a, (uVar1 & 0x20) != 0)) {
    uVar1 = DAT_00fd08;
    DAT_00fd08 = uVar1 | 0x8000;
  }
  else {
    uVar1 = DAT_00fd08;
    DAT_00fd08 = uVar1 & 0x7fff;
  }
  uVar1 = DAT_00fd0c;
  if (((uVar1 & 4) == 0) && (uVar1 = DAT_00fd1a, (uVar1 & 0x10) != 0)) {
    uVar1 = DAT_00fd06;
    DAT_00fd06 = uVar1 | 0x8000;
    return;
  }
  uVar1 = DAT_00fd06;
  DAT_00fd06 = uVar1 & 0x7fff;
  return;
}

