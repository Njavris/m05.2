// c1c718 gap_c1c718 size=332 cc=unknown proto=undefined gap_c1c718(void)

void gap_c1c718(void)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  byte bVar4;
  
  func_0xc159bc((short)&UNK_00c9d4,(short)&UNK_00c9b2,5);
  cVar2 = UNK_00c9bc;
  if (cVar2 == '\0') {
    UNK_00c9b2 = 1;
    uVar1 = DAT_00fd02;
    if ((uVar1 & 0x200) != 0) {
      UNK_00c9b5 = 1;
    }
    uVar1 = DAT_00fd02;
    if ((uVar1 & 0x100) != 0) {
      UNK_00c9b6 = 1;
    }
    uVar1 = Ram00c9dc;
    if (0x80 < uVar1) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfeff;
      UNK_00c9b6 = 0;
      Ram00c9dc = 0;
    }
    uVar1 = Ram00c9d4;
    if (uRamc06c5e < uVar1) {
      DAT_00c9d0 = 0;
      Ram00c9d2 = 0xffff;
      bVar4 = 0;
      do {
        uVar1 = (ushort)bVar4;
        bVar4 = bVar4 + 1;
        *(undefined2 *)(uint3)((short)&UNK_00c9c0 + uVar1 * 2) = 0xffff;
      } while (bVar4 < 4);
      UNK_00c9bb = 0;
    }
    uVar1 = Ram00c9da;
    if (uRamc06c60 < uVar1) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfdff;
      UNK_00c9b5 = 0;
      Ram00c9da = 0;
    }
  }
  else {
    UNK_00c9bc = 0;
    UNK_00c9b2 = 0;
    Ram00c9d4 = 0;
    uVar1 = DAT_00fd02;
    if ((uVar1 & 0x200) != 0) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfdff;
      UNK_00c9b5 = 0;
      Ram00c9da = 0;
    }
    uVar1 = DAT_00fd02;
    if ((uVar1 & 0x100) != 0) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfeff;
      UNK_00c9b6 = 0;
      Ram00c9dc = 0;
    }
  }
  sVar3 = DAT_00c9d0;
  if (sVar3 != 0) {
    UNK_00c9c8 = 1;
    Ram00c9d8 = 0;
    UNK_00c9b4 = 0;
  }
  uVar1 = DAT_00fd02;
  if ((((uVar1 & 0x800) == 0) && (sVar3 = DAT_00c9d0, sVar3 == 0)) ||
     (sVar3 = DAT_00c9d0, sVar3 != 0)) {
    UNK_00c9b3 = 0;
    Ram00c9d6 = 0;
  }
  else {
    cVar2 = UNK_00c9c8;
    if (cVar2 != '\0') {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfbff;
      UNK_00c9c8 = 0;
    }
    uVar1 = Ram00c9d6;
    if (uRamc06c62 < uVar1) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xf7ff;
      Ram00c9d6 = 0;
      UNK_00c9b3 = 0;
    }
    else {
      UNK_00c9b3 = 1;
    }
    uVar1 = DAT_00fd02;
    if ((uVar1 & 0x200) != 0) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfdff;
      UNK_00c9b5 = 0;
      Ram00c9da = 0;
    }
  }
  uVar1 = DAT_00fd02;
  if ((((uVar1 & 0x400) != 0) || (sVar3 = DAT_00c9d0, sVar3 != 0)) &&
     (sVar3 = DAT_00c9d0, sVar3 == 0)) {
    uVar1 = Ram00c9d8;
    if (uVar1 < 0x2b3) {
      UNK_00c9b4 = 1;
      return;
    }
    uVar1 = DAT_00fd02;
    DAT_00fd02 = uVar1 & 0xfbff;
  }
  UNK_00c9b4 = 0;
  Ram00c9d8 = 0;
  return;
}

