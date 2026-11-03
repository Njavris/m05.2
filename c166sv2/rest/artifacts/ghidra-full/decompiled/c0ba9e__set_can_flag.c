// c0ba9e set_can_flag size=22 cc=unknown proto=undefined set_can_flag(void)

void set_can_flag(void)

{
  ushort uVar1;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  DAT_00c210 = 0xbab4;
  DAT_00c212 = 0xc0;
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}

