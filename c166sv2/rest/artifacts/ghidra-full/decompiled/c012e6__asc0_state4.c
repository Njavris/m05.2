// c012e6 asc0_state4 size=258 cc=unknown proto=undefined asc0_state4(void)

void asc0_state4(void)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  byte bVar5;
  undefined1 uVar6;
  ushort uVar7;
  
  cVar3 = DAT_00c1d0;
  if (cVar3 == '\0') {
    DAT_00c0ae = 0;
    DAT_00c147 = 4;
    DAT_00c1d0 = 1;
    DAT_00c09c = 0;
  }
  else if (cVar3 != '\x01') {
    if (cVar3 == '\x02') {
      while (uVar7 = S0RIC, (uVar7 & 0x80) != 0) {
        bVar5 = DAT_00c147;
        bVar2 = DAT_00c0ae;
        if (bVar5 + 4 < (ushort)bVar2) break;
        uVar6 = asc0_read_rx_clear(0);
        bVar2 = DAT_00c0ae;
        *(undefined1 *)(uint3)((short)&DAT_00c144 + (ushort)bVar2) = uVar6;
        cVar3 = DAT_00c0ae;
        DAT_00c0ae = cVar3 + '\x01';
        DAT_00c09c = 0;
      }
      sVar1 = DAT_00c09c;
      DAT_00c09c = sVar1 + 1;
      bVar2 = DAT_00c147;
      DAT_00c142 = bVar2 + 4;
      bVar2 = DAT_00c0ae;
      uVar7 = DAT_00c142;
      uVar4 = DAT_00c142;
      if (bVar2 == uVar4 || bVar2 < uVar7) {
        bVar2 = DAT_00c0a2;
        uVar7 = DAT_00c09c;
        if (bVar2 < uVar7) {
          DAT_00c0af = 3;
          DAT_00c1d0 = 0;
          DAT_00c144 = 0;
        }
      }
      else {
        for (uVar7 = 0; uVar4 = DAT_00c142, uVar7 < uVar4; uVar7 = uVar7 + 1) {
        }
        DAT_00c0af = 3;
        DAT_00c1d0 = 0;
        DAT_00c1d1 = 1;
      }
    }
    else {
      DAT_00c1d0 = 0;
    }
    goto LAB_c013e2;
  }
  while ((uVar7 = S0RIC, (uVar7 & 0x80) != 0 && (bVar2 = DAT_00c0ae, bVar2 < 3))) {
    uVar6 = asc0_read_rx_clear();
    bVar2 = DAT_00c0ae;
    uVar7 = (short)&DAT_00c144 + (ushort)bVar2;
    *(undefined1 *)(uint3)uVar7 = uVar6;
    bVar2 = DAT_00c0ae;
    if ((ushort)*(byte *)(uint3)uVar7 != *(ushort *)(uint3)((short)&DAT_00c0a8 + (ushort)bVar2 * 2))
    {
      DAT_00c0af = 3;
      DAT_00c1d0 = 0;
    }
    cVar3 = DAT_00c0ae;
    DAT_00c0ae = cVar3 + '\x01';
  }
  cVar3 = DAT_00c0ae;
  if (cVar3 == '\x03') {
    DAT_00c1d0 = 2;
  }
LAB_c013e2:
  sVar1 = DAT_00c13e;
  DAT_00c13e = sVar1 + 1;
  return;
}

