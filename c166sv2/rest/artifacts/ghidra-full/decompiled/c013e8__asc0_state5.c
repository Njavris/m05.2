// c013e8 asc0_state5 size=154 cc=unknown proto=undefined asc0_state5(void)

void asc0_state5(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  char cVar6;
  char cVar7;
  ushort uVar8;
  
  cVar7 = '\0';
  cVar6 = DAT_00c1d0;
  if (cVar6 == '\0') {
    DAT_00c138 = 0;
    DAT_00c0b2 = 0x80;
    DAT_00c0b3 = 0xf1;
    DAT_00c0b4 = 0x11;
    bVar1 = DAT_00c0b5;
    DAT_00c142 = bVar1 + 4;
    for (uVar8 = 0; uVar4 = DAT_00c142, uVar8 < uVar4; uVar8 = uVar8 + 1) {
      cVar7 = cVar7 + *(char *)(uint3)((short)&DAT_00c0b2 + uVar8);
    }
    sVar2 = DAT_00c142;
    *(char *)(uint3)(ushort)((short)&DAT_00c0b2 + sVar2) = cVar7;
    DAT_00c1d0 = 1;
    uVar8 = S0CON;
    S0CON = uVar8 & 0xffef;
  }
  else if (cVar6 == '\x01') {
    sVar2 = DAT_00c138;
    sVar3 = DAT_00c138;
    DAT_00c138 = sVar3 + 1;
    asc0_tx_byte(*(undefined1 *)(uint3)(ushort)((short)&DAT_00c0b2 + sVar2));
    uVar8 = DAT_00c138;
    uVar4 = DAT_00c142;
    uVar5 = DAT_00c142;
    if (uVar8 != uVar5 && uVar4 <= uVar8) {
      DAT_00c1d0 = 2;
    }
  }
  else {
    if (cVar6 == '\x02') {
      uVar8 = S0CON;
      S0CON = uVar8 | 0x10;
      DAT_00c0af = 3;
      DAT_00c13c = 0;
    }
    DAT_00c1d0 = 0;
  }
  cVar7 = DAT_00c140;
  DAT_00c140 = cVar7 + '\x01';
  DAT_00c13e = 0;
  return;
}

