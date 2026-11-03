// c00e14 ssc0_rx_isr size=182 cc=unknown proto=undefined ssc0_rx_isr(void)

void ssc0_rx_isr(void)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined1 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  undefined2 uVar17;
  undefined2 uVar18;
  byte bVar19;
  
  DAT_00fc60 = &stack0x0000;
  uVar10 = DPP0;
  DPP0 = 0x300;
  uVar11 = DPP2;
  DPP2 = 0x302;
  uVar18 = DAT_00ffde;
  uVar12 = DAT_00fe5c;
  uVar13 = DAT_00fe5e;
  uVar17 = DAT_00ffdc;
  uVar16 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar14 = DAT_00ff08;
  uVar15 = DAT_00ff0a;
  uVar5 = DAT_00f000;
  uVar6 = DAT_00f002;
  uVar7 = DAT_00f004;
  uVar8 = DAT_00f006;
  uVar9 = SSCRB;
  uVar1 = DAT_00c098;
  *(undefined1 *)(uint3)uVar1 = uVar9;
  cVar2 = DAT_00c094;
  DAT_00c094 = cVar2 + -1;
  cVar2 = DAT_00c094;
  if (cVar2 == '\0') {
    uVar1 = P1H;
    P1H = uVar1 | 8;
    bVar19 = 0;
    do {
      uVar1 = (ushort)bVar19;
      bVar19 = bVar19 + 1;
      *(undefined1 *)(uint3)((short)&DAT_00c082 + uVar1) =
           *(undefined1 *)(uint3)((short)&DAT_00c078 + uVar1);
    } while (bVar19 < 7);
    DAT_00c094 = 7;
    DAT_00c096 = 0xc08c;
    DAT_00c098 = 0xc078;
  }
  else {
    sVar3 = DAT_00c096;
    DAT_00c096 = sVar3 + 1;
    sVar4 = DAT_00c098;
    DAT_00c098 = sVar4 + 1;
    ssc_send_byte(sVar3 + 1,uVar8,uVar7,uVar6,uVar5,uVar15,uVar14,uVar16,uVar17,uVar13,uVar12,uVar18
                  ,uVar11,uVar10);
  }
  DAT_00f006 = uVar8;
  uVar8 = DAT_00f006;
  uVar8 = DAT_00f006;
  uVar8 = DAT_00f006;
  DAT_00f004 = uVar7;
  uVar7 = DAT_00f004;
  uVar7 = DAT_00f004;
  uVar7 = DAT_00f004;
  DAT_00f002 = uVar6;
  uVar6 = DAT_00f002;
  uVar6 = DAT_00f002;
  uVar6 = DAT_00f002;
  DAT_00f000 = uVar5;
  uVar5 = DAT_00f000;
  uVar5 = DAT_00f000;
  uVar5 = DAT_00f000;
  DAT_00ff0a = uVar15;
  uVar5 = DAT_00ff0a;
  uVar5 = DAT_00ff0a;
  uVar5 = DAT_00ff0a;
  DAT_00ff08 = uVar14;
  uVar5 = DAT_00ff08;
  uVar5 = DAT_00ff08;
  uVar5 = DAT_00ff08;
  DAT_00ffda = uVar16;
  uVar5 = DAT_00ffda;
  uVar5 = DAT_00ffda;
  uVar5 = DAT_00ffda;
  DAT_00ffdc = uVar17;
  uVar5 = DAT_00ffdc;
  uVar5 = DAT_00ffdc;
  uVar5 = DAT_00ffdc;
  DAT_00fe5e = uVar13;
  uVar5 = DAT_00fe5e;
  uVar5 = DAT_00fe5e;
  uVar5 = DAT_00fe5e;
  DAT_00fe5c = uVar12;
  uVar5 = DAT_00fe5c;
  uVar5 = DAT_00fe5c;
  uVar5 = DAT_00fe5c;
  DAT_00ffde = uVar18;
  uVar5 = DAT_00ffde;
  uVar5 = DAT_00ffde;
  uVar5 = DAT_00ffde;
  DPP2 = uVar11;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar10;
  uVar5 = DPP0;
  uVar5 = DPP0;
  uVar5 = DPP0;
  return;
}

