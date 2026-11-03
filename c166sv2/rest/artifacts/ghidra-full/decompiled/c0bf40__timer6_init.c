// c0bf40 timer6_init size=20 cc=unknown proto=undefined timer6_init(void)

void timer6_init(void)

{
  ushort uVar1;
  
  T6CON = 0x800a;
  T6 = 0xffff;
  CAPREL = 0xffff;
  uVar1 = T6IC;
  T6IC = uVar1 | 0x7a;
  uVar1 = T6CON;
  T6CON = uVar1 | 0x40;
  return;
}

