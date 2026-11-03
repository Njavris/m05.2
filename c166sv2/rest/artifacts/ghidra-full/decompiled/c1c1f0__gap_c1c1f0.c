// c1c1f0 gap_c1c1f0 size=104 cc=unknown proto=undefined gap_c1c1f0(void)

void gap_c1c1f0(void)

{
  short sVar1;
  undefined2 uVar2;
  char cVar3;
  byte bVar4;
  undefined1 uVar5;
  short sVar6;
  
  cVar3 = UNK_00c1b6;
  if (cVar3 != '\0') {
    cVar3 = UNK_00c068;
    if (cVar3 == '\0') {
      Ram00c070 = 0;
      UNK_00c076 = 0;
      Ram00c074 = 0;
    }
    else {
      cVar3 = UNK_00c076;
      UNK_00c076 = cVar3 + '\x01';
      bVar4 = UNK_00c076;
      if (0x3b < bVar4) {
        sVar1 = Ram00c070;
        Ram00c070 = sVar1 + 1;
        sVar1 = Ram00c070;
        if (sVar1 == -1) {
          Ram00c070 = 0xffff;
        }
        UNK_00c076 = 0;
      }
      sVar1 = Ram00c062;
      sVar6 = Ram00c9a0;
      if ((sVar1 != sVar6) && (sVar1 = Ram00c074, sVar1 != -1)) {
        sVar1 = Ram00c074;
        Ram00c074 = sVar1 + 1;
      }
    }
  }
  uVar2 = Ram00c062;
  Ram00c9a0 = uVar2;
  uVar5 = UNK_00c1b6;
  UNK_00c068 = uVar5;
  return;
}

