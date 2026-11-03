// c0cf48 FUN_c0cf48 size=200 cc=unknown proto=undefined FUN_c0cf48(void)

void FUN_c0cf48(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  DAT_00fa20 = &stack0x0000;
  uVar4 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  DPP2 = 0x303;
  uVar3 = DAT_00fd18;
  if ((uVar3 & 0x80) != 0) goto LAB_c0d002;
  uVar3 = P1H;
  if ((uVar3 & 0x10) != 0) {
    if (DAT_c05081 == '\x04') {
      uVar3 = P1L;
      P1L = uVar3 & 0xffef;
    }
    goto LAB_c0d002;
  }
  if (DAT_c05081 == '\x04') {
LAB_c0cfe8:
    uVar3 = P1L;
    P1L = uVar3 | 0x10;
  }
  else if (DAT_c05081 == '\x03') {
    bVar1 = DAT_00c1fc;
    if ((1 < bVar1) && (bVar1 < 0x11)) {
      cVar2 = DAT_00c1fc;
      DAT_00c1fc = cVar2 + '\x01';
      cVar2 = DAT_00c1fc;
      if ((cVar2 == '\b') || (cVar2 == '\x0e')) goto LAB_c0cfec;
      if ((cVar2 == '\t') || (cVar2 == '\x0f')) goto LAB_c0cfe8;
    }
  }
  else if ((DAT_c05081 == '\x05') && ((bVar1 = DAT_00c1fc, 1 < bVar1 && (bVar1 < 0x17)))) {
    cVar2 = DAT_00c1fc;
    DAT_00c1fc = cVar2 + '\x01';
    cVar2 = DAT_00c1fc;
    if ((cVar2 == '\x04') || (cVar2 == '\x10')) {
LAB_c0cfec:
      uVar3 = P1L;
      P1L = uVar3 & 0xffef;
    }
    else if ((cVar2 == '\n') || (cVar2 == '\x16')) goto LAB_c0cfe8;
  }
  FUN_c0cada(uVar5,uVar4);
LAB_c0d002:
  DPP2 = uVar5;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar4;
  uVar4 = DPP0;
  uVar4 = DPP0;
  uVar4 = DPP0;
  return;
}

