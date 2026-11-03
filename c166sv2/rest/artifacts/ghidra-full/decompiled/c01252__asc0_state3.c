// c01252 asc0_state3 size=148 cc=unknown proto=undefined asc0_state3(void)

/* WARNING: Control flow encountered bad instruction data */

void asc0_state3(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  ushort uVar7;
  byte bVar8;
  
  cVar1 = DAT_00c1d0;
  if (cVar1 == '\0') {
    DAT_00c140 = 0;
    DAT_00c1d0 = 1;
    goto LAB_c012ba;
  }
  if (cVar1 != '\x01') {
    DAT_00c1d0 = 0;
    goto LAB_c012ba;
  }
  uVar4 = S0RIC;
  if ((uVar4 & 0x80) == 0) {
    cVar1 = DAT_00c13c;
    if (cVar1 == '\x01') {
      bVar8 = DAT_00c140;
      bVar2 = DAT_00c09e;
      bVar3 = DAT_00c09e;
      if (bVar8 != bVar3 && bVar2 <= bVar8) {
        DAT_00c0af = 5;
        goto LAB_c01292;
      }
    }
    cVar1 = DAT_00c13c;
    if ((cVar1 == '\0') && (cVar1 = DAT_00c09b, cVar1 == '\x01')) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else {
    DAT_00c0af = 4;
LAB_c01292:
    DAT_00c1d0 = 0;
  }
  cVar1 = DAT_00c140;
  DAT_00c140 = cVar1 + '\x01';
LAB_c012ba:
  sVar6 = DAT_00c13e;
  DAT_00c13e = sVar6 + 1;
  uVar7 = DAT_00c13e;
  uVar4 = DAT_00c0a0;
  uVar5 = DAT_00c0a0;
  if (uVar7 != uVar5 && uVar4 <= uVar7) {
    DAT_00c13e = 0;
    DAT_00c0af = 2;
    DAT_00c0ae = 0;
    uVar4 = DAT_00f0c6;
    DAT_00f0c6 = uVar4 & 0xfffd | 2;
    uVar4 = S0CON;
    S0CON = uVar4 | 0x10;
  }
  return;
}

