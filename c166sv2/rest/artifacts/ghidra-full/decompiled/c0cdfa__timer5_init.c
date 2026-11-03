// c0cdfa timer5_init size=168 cc=unknown proto=undefined timer5_init(void)

void timer5_init(void)

{
  ushort uVar1;
  byte bVar2;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xffbf;
  T5 = 0;
  uVar1 = CC24IC;
  CC24IC = uVar1 & 0xffbf;
  DAT_00c274 = 0x200;
  DAT_00c26e = 0;
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  bVar2 = 0;
  do {
    uVar1 = (ushort)bVar2;
    bVar2 = bVar2 + 1;
    *(undefined2 *)(uint3)((short)&DAT_00c282 + uVar1 * 2) = 0;
  } while (bVar2 < 0x18);
  DAT_00fd00 = 0x8100;
  DAT_00c2b2 = 0;
  DAT_00c280 = 0;
  DAT_00c277 = 0;
  DAT_00c264 = 0;
  DAT_00c272 = 0;
  uVar1 = DAT_00fd00;
  DAT_00fd00 = uVar1 & 0xffbf;
  DAT_00c2b4 = 0xffff;
  DAT_00c26a = 0xffff;
  DAT_00c26c = 0xffff;
  DAT_00c268 = 0xff;
  DAT_00c25c = 0;
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  DAT_00c244 = 0xc8e2;
  DAT_00c246 = 0xc0;
  DAT_00c240 = 0xc914;
  DAT_00c242 = 0xc0;
  uVar1 = DAT_00c2aa;
  DAT_00c2aa = uVar1 | 1;
  uVar1 = DAT_00c28a;
  DAT_00c28a = uVar1 | 2;
  uVar1 = DAT_00c2a2;
  DAT_00c2a2 = uVar1 | 2;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xffbf;
  T5 = 0;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xff7f;
  uVar1 = CC24IC;
  CC24IC = uVar1 | 0x40;
  watchdog_pin();
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}

