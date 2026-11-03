// c0fb8c cc_event_timeout_tick size=64 cc=unknown proto=undefined cc_event_timeout_tick(void)

void cc_event_timeout_tick(void)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  
  sVar1 = DAT_00c478;
  DAT_00c478 = sVar1 + 1;
  uVar2 = DAT_00c478;
  if (0xa00 < uVar2) {
    DAT_00c478 = 0;
    cVar3 = DAT_00fd12;
    if ((cVar3 != '\0') && (bVar4 = DAT_00fd12, bVar4 < 0x10)) {
      cVar3 = DAT_00fd12;
      DAT_00fd12 = cVar3 + -1;
    }
    cVar3 = DAT_00fd0e;
    if ((cVar3 != '\0') && (bVar4 = DAT_00fd0e, bVar4 < 0x10)) {
      cVar3 = DAT_00fd0e;
      DAT_00fd0e = cVar3 + -1;
    }
  }
  return;
}

