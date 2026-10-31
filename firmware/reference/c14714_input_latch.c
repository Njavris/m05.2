/* c14714 input_latch */

/* Latch input port bits into 0xFD1C. */

void input_latch(void)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar1 = input_status;
  uVar2 = status_flag_fd1c;
  uVar3 = status_flag_fd1c;
  status_flag_fd1c = uVar3 & 0xfffe | uVar1 >> 2 & 1;
  uVar1 = input_status;
  uVar2 = status_flag_fd1c;
  uVar3 = status_flag_fd1c;
  status_flag_fd1c = uVar3 & 0xfffd | (uVar1 >> 1 & 1) << 1;
  uVar1 = input_status;
  uVar2 = status_flag_fd1c;
  uVar3 = status_flag_fd1c;
  status_flag_fd1c = uVar3 & 0xfffb | (uVar1 & 1) << 2;
  return;
}


