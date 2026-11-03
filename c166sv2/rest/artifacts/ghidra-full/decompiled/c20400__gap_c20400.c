// c20400 gap_c20400 size=26 cc=unknown proto=undefined gap_c20400(void)

void gap_c20400(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  if (cRame00830 == '\0') {
    sVar3 = DAT_00c936;
    sVar1 = Ram00c0ba;
    sVar2 = Ram00c0ba;
    if (sVar3 != sVar2 && sVar3 - sVar2 < 0 == SBORROW2(sVar3,sVar1)) {
      Ram00c0ba = sVar3;
    }
  }
  return;
}

