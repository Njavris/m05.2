// c102dc gap_c102dc size=102 cc=unknown proto=undefined gap_c102dc(void)

void gap_c102dc(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  
  cVar1 = DAT_00c4aa;
  DAT_00c4aa = cVar1 + '\x01';
  bVar2 = DAT_00c4aa;
  if ((bVar2 & 0xf) == 1) {
    uVar3 = P1L;
    P1L = uVar3 & 0xffbf;
    DAT_00c4b4 = 1;
  }
  if ((bVar2 & 0xf) == 5) {
    uVar3 = Ram00c4a4;
    if ((uVar3 & 0x800) == 0) {
      uVar3 = Ram00c4a4;
      Ram00c4a4 = uVar3 & 0xf7ff;
      uVar3 = DAT_00c4ba;
      DAT_00c4ba = uVar3 | 0x200;
    }
    else {
      cVar1 = DAT_00c49e;
      DAT_00c49e = cVar1 + '\x01';
    }
  }
  cVar1 = DAT_00c4aa;
  if (cVar1 == '\x7f') {
    DAT_00c4aa = 0xff;
    bVar2 = DAT_00c49e;
    if (6 < bVar2) {
      uVar3 = DP1L;
      DP1L = uVar3 & 0xffbf;
      uVar3 = P1L;
      P1L = uVar3 | 0x40;
      DAT_00c4b4 = 0x55;
      return;
    }
    DAT_00c4b4 = 0;
  }
  return;
}

