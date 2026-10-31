/* c0ba9e set_can_flag */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Set CAN/application flag. */

void set_can_flag(void)

{
  ushort uVar1;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  _can_callback_ptr = 0xbab4;
  _can_callback_ptr_hi = 0xc0;
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


