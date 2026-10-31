/* c13f6c capture_control */

/* Capture input control. */

void capture_control(void)

{
  ushort uVar1;
  
  uVar1 = capture_status_1;
  if (((uVar1 & 4) == 0) && (cal_capture_config == 0)) {
    uVar1 = capture_input_select;
    capture_input_select = uVar1 | 0x20;
  }
  uVar1 = capture_status_0;
  if ((uVar1 & 4) == 0) {
    uVar1 = capture_input_select;
    capture_input_select = uVar1 | 0x10;
  }
  return;
}


