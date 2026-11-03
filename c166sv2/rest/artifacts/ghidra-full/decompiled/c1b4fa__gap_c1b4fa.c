// c1b4fa gap_c1b4fa size=260 cc=unknown proto=undefined gap_c1b4fa(void)

void gap_c1b4fa(void)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  
  cVar3 = DAT_00c93c;
  if (cVar3 != '\x03') {
    sVar1 = DAT_00c936;
    if (sVar1 < sRamc06c3c) {
      uRamc0493f = uRamc06c42;
    }
    else {
      sVar1 = DAT_00c936;
      if (sVar1 < sRamc06c3e) {
        uRamc0493f = uRamc06c43;
      }
      else {
        uRamc0493f = uRamc06c3a;
      }
    }
  }
  cVar3 = DAT_00c93c;
  if ((cVar3 == '\x02') && (uVar5 = DAT_00c9d0, uRamc06c34 <= uVar5)) {
    UNK_00c93b = 2;
    bVar2 = UNK_00c938;
    bVar4 = UNK_00c93f;
    if (bVar4 <= bVar2) {
      UNK_00c943 = 1;
      UNK_00c93b = 1;
    }
  }
  else {
    UNK_00c943 = 0;
    UNK_00c93b = 0;
  }
  cVar3 = DAT_00c93c;
  if ((cVar3 == '\x02') && (uVar5 = DAT_00c9d0, uVar5 < 0xf1)) {
    UNK_00c944 = 1;
  }
  else {
    UNK_00c944 = 0;
  }
  cVar3 = DAT_00c93c;
  if ((cVar3 == '\x03') && (uVar5 = DAT_00c9d0, uVar5 <= uRamc06c36)) {
    UNK_00c948 = 1;
  }
  else {
    UNK_00c948 = 0;
  }
  cVar3 = DAT_00c93c;
  if ((cVar3 == '\x04') && (uVar5 = DAT_00c9d0, 0xf0 < uVar5)) {
    UNK_00c93e = 1;
  }
  else {
    UNK_00c93e = 0;
  }
  cVar3 = DAT_00c93c;
  if ((cVar3 == '\x01') && (uVar5 = DAT_00c9d0, 0xf0 < uVar5)) {
    UNK_00c939 = 1;
    return;
  }
  UNK_00c939 = 0;
  return;
}

