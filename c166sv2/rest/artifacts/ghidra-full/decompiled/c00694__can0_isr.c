// c00694 can0_isr size=232 cc=unknown proto=undefined can0_isr(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can0_isr(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  byte bVar15;
  
  DAT_00fc00 = &stack0x0000;
  uVar6 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DPP0 = 0x300;
  uVar7 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP2 = 0x302;
  uVar14 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar8 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar9 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar13 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar12 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar10 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar11 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  can_rx_process(uVar4,uVar3,uVar2,uVar1,uVar11,uVar10,uVar12,uVar13,uVar9,uVar8,uVar14,uVar7,uVar6)
  ;
  while ((_DAT_200284 & 1) != 0) {
    if ((_DAT_200310 & 3) == 2) {
      if ((((_DAT_200284 & 1) != 0) && ((_DAT_200310 & 0x300) == 0x200)) &&
         ((_DAT_200310 & 0xc00) != 0x800)) {
        bVar15 = 0;
        do {
          bVar15 = bVar15 + 1;
        } while (bVar15 < 8);
        DAT_00c016 = 1;
      }
      _DAT_200310 = 0xfffd;
    }
  }
  DAT_00f006 = uVar4;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  DAT_00f004 = uVar3;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  DAT_00f002 = uVar2;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  DAT_00f000 = uVar1;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  DAT_00ff0a = uVar11;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  DAT_00ff08 = uVar10;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  DAT_00ffda = uVar12;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  DAT_00ffdc = uVar13;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  DAT_00fe5e = uVar9;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  DAT_00fe5c = uVar8;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  DAT_00ffde = uVar14;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  DPP2 = uVar7;
  uVar1 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP0 = uVar6;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}

