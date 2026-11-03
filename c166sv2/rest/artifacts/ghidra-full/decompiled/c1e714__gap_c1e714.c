// c1e714 gap_c1e714 size=188 cc=unknown proto=undefined gap_c1e714(void)

void gap_c1e714(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  if (((cRamc07468 == '\0') || (cVar1 = DAT_00c93c, cVar1 != '\x03')) ||
     (cVar1 = DAT_00c786, cVar1 != '\0')) {
    Ram00ca48 = 0;
  }
  else if (DAT_e0081a == '\0') {
    cVar1 = DAT_00c81c;
    if (cVar1 == '\0') {
      uVar3 = DAT_00c9d0;
      uVar2 = gap_c28544(0x5122,0xc0,uVar3);
      uVar3 = Ram00ca1c;
      uVar3 = gap_c28544(0x51da,0xc0,uVar3);
      uVar3 = func_0xc28080(0x7296,0xc0,uVar2,uVar3);
      Ram00ca48 = uVar3;
    }
    else {
      uVar3 = DAT_00c9d0;
      uVar3 = gap_c28544(0x5122,0xc0,uVar3);
      uVar3 = gap_c27f0e(0x7282,0xc0,uVar3);
      Ram00ca48 = uVar3;
    }
  }
  else {
    uVar3 = DAT_00c936;
    uVar3 = gap_c286ca(0x522e,0xc0,uVar3);
    uVar3 = gap_c27f0e(0x726e,0xc0,uVar3);
    Ram00ca48 = uVar3;
  }
  return;
}

