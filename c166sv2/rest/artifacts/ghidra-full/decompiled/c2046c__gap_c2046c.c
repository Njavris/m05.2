// c2046c gap_c2046c size=364 cc=unknown proto=undefined gap_c2046c(void)

void gap_c2046c(void)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  
  gap_c1fede();
  cVar2 = UNK_00ca86;
  if (cVar2 == '\0') {
    cVar2 = DAT_00c0b0._1_1_;
    DAT_00c0b0._1_1_ = cVar2 + '\x01';
    bVar3 = DAT_00c0b0._1_1_;
    if (0xe0 < bVar3) {
      sVar1 = Ram00c0b4;
      Ram00c0b4 = sVar1 + 1;
      DAT_00c0b0._1_1_ = 0;
    }
  }
  else {
    cVar2 = UNK_00ca86;
    if (cVar2 == '\x01') {
      cVar2 = UNK_00c09f;
      UNK_00c09f = cVar2 + '\x01';
      bVar3 = UNK_00c09f;
      if (0xe0 < bVar3) {
        sVar1 = Ram00c0a6;
        Ram00c0a6 = sVar1 + 1;
        UNK_00c09f = 0;
      }
    }
    else {
      cVar2 = UNK_00ca86;
      if (cVar2 == '\x02') {
        cVar2 = UNK_00c0a4;
        UNK_00c0a4 = cVar2 + '\x01';
        bVar3 = UNK_00c0a4;
        if (0xe0 < bVar3) {
          sVar1 = Ram00c0aa;
          Ram00c0aa = sVar1 + 1;
          UNK_00c0a4 = 0;
        }
      }
    }
  }
  cVar2 = DAT_00c93c;
  if (cVar2 == '\x03') {
    uVar4 = DAT_00c9d0;
    if (uRamc079d0 < uVar4) {
      uVar4 = DAT_00c9d0;
      if ((uRamc079d0 < uVar4) && (uVar4 <= uRamc079d2)) {
        cRame008b4 = '\x01';
      }
      else {
        uVar4 = DAT_00c9d0;
        if ((uRamc079d2 < uVar4) && (uVar4 <= uRamc079d4)) {
          cRame008b4 = '\x02';
        }
        else {
          cRame008b4 = '\x03';
        }
      }
    }
    else {
      cRame008b4 = '\0';
    }
  }
  else {
    cRame008b4 = '\x04';
  }
  if (cRame008b4 == '\0') {
    cVar2 = DAT_00c0b0._0_1_;
    DAT_00c0b0._0_1_ = cVar2 + '\x01';
    bVar3 = DAT_00c0b0._0_1_;
    if (0xe0 < bVar3) {
      sVar1 = Ram00c0a2;
      Ram00c0a2 = sVar1 + 1;
      DAT_00c0b0._0_1_ = 0;
      return;
    }
  }
  else if (cRame008b4 == '\x01') {
    cVar2 = UNK_00c0be;
    UNK_00c0be = cVar2 + '\x01';
    bVar3 = UNK_00c0be;
    if (0xe0 < bVar3) {
      sVar1 = Ram00c0ac;
      Ram00c0ac = sVar1 + 1;
      UNK_00c0be = 0;
      return;
    }
  }
  else if (cRame008b4 == '\x02') {
    cVar2 = DAT_00c09e;
    DAT_00c09e = cVar2 + '\x01';
    bVar3 = DAT_00c09e;
    if (0xe0 < bVar3) {
      sVar1 = Ram00c0b2;
      Ram00c0b2 = sVar1 + 1;
      DAT_00c09e = 0;
      return;
    }
  }
  else if (cRame008b4 == '\x03') {
    cVar2 = DAT_00c0a0._0_1_;
    DAT_00c0a0._0_1_ = cVar2 + '\x01';
    bVar3 = DAT_00c0a0._0_1_;
    if (0xe0 < bVar3) {
      sVar1 = DAT_00c09c;
      DAT_00c09c = sVar1 + 1;
      DAT_00c0a0._0_1_ = 0;
    }
  }
  return;
}

