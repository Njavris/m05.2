/* c14298 capture_init */

/* Capture input initialization. */

void capture_init(void)

{
  capture_control();
  capture_input_select(0);
  return;
}


