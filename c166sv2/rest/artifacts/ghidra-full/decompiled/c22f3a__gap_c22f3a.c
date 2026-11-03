// c22f3a gap_c22f3a size=200 cc=unknown proto=undefined gap_c22f3a(void)

void gap_c22f3a(void)

{
  short sVar1;
  char cVar2;
  undefined2 uVar3;
  
  if (cRamc0506c != '\x03') {
    return;
  }
  cVar2 = DAT_00c93c;
  if ((cVar2 == '\x03') && (cVar2 = DAT_00c954, cVar2 == '\x01')) {
    cVar2 = func_0xc24530(1);
    if ((cVar2 != '\0') ||
       (((cVar2 = func_0xc24530(2), cVar2 != '\0' || (cRame008cf == '\x01')) ||
        (sVar1 = DAT_00c936, sRamc07d08 < sVar1)))) {
      cRame008ce = '\x01';
      goto LAB_c22fb0;
    }
    sVar1 = DAT_00c936;
    if (sRamc07d0a < sVar1) goto LAB_c22fb0;
  }
  cRame008ce = '\0';
LAB_c22fb0:
  func_0xc14cec(6);
  if (cRame008ce == '\0') {
    uVar3 = func_0xc27b86(0,0x8000,0xf);
    Ram00c98c = uVar3;
  }
  else {
    uVar3 = func_0xc27b86(0xffff,0x8000,0xf);
    Ram00c98c = uVar3;
  }
  uVar3 = Ram00c98c;
  uVar3 = FUN_c28852(0x8000,uVar3);
  Ram00c98c = uVar3;
  func_0xc14c70(6,0x40,uVar3);
  return;
}

