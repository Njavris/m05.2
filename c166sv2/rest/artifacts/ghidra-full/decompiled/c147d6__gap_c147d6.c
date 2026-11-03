// c147d6 gap_c147d6 size=78 cc=unknown proto=undefined gap_c147d6(void)

void gap_c147d6(void)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xbfff;
  command_dispatch(6);
  func_0xc0e4e6();
  cVar3 = DAT_00c92f;
  if (cVar3 == '\0') {
    DAT_00c208 = 0xd70a;
    DAT_00c20a = 0xc0;
    if ((DAT_c05036 == '\x02') || (DAT_c05036 == '\x03')) {
      uVar1 = Ram00c288;
      Ram00c288 = uVar1 | 0x8000;
    }
  }
  return;
}

