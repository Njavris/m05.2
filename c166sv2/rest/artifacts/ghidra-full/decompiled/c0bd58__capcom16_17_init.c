// c0bd58 capcom16_17_init size=70 cc=unknown proto=undefined capcom16_17_init(void)

void capcom16_17_init(void)

{
  ushort uVar1;
  
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 1;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 2;
  DAT_00c390 = 0x10;
  DAT_00c392 = 0xfe60;
  DAT_00c394 = 0xff22;
  DAT_00c396 = 0xf160;
  DAT_00c398 = 0x11;
  DAT_00c39a = 0xfe62;
  DAT_00c39c = 0xff22;
  DAT_00c39e = 0xf162;
  return;
}

