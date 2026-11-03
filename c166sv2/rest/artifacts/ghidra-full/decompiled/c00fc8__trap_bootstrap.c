// c00fc8 trap_bootstrap size=128 cc=unknown proto=undefined trap_bootstrap(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trap_bootstrap(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  ushort uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  
  DAT_00fc80 = &stack0x0000;
  uVar7 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DPP0 = 0x300;
  uVar8 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP2 = 0x302;
  uVar16 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar9 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar10 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar15 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar14 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar11 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar12 = DAT_00ff0a;
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
  uVar6 = PSW;
  PSW = uVar6 & 0xf7ff;
  uVar13 = TFR;
  uVar6 = DAT_00fdfe;
  DAT_00fdfe = uVar6 | uVar13;
  uVar6 = TFR;
  if ((uVar6 & 0x80) != 0) {
    uVar6 = TFR;
    TFR = uVar6 & 0xff7f;
  }
  uVar6 = TFR;
  if ((uVar6 & 0x10) != 0) {
    uVar6 = TFR;
    TFR = uVar6 & 0xffef;
    _DAT_fffdfc = _DAT_fffdfc | _DAT_fff000;
  }
  uVar6 = TFR;
  if ((uVar6 & 8) != 0) {
    uVar6 = TFR;
    TFR = uVar6 & 0xfff7;
  }
  uVar6 = TFR;
  if ((uVar6 & 4) != 0) {
    uVar6 = TFR;
    TFR = uVar6 & 0xfffb;
  }
  __software_reset();
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
  DAT_00ff0a = uVar12;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  DAT_00ff08 = uVar11;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  DAT_00ffda = uVar14;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  DAT_00ffdc = uVar15;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  DAT_00fe5e = uVar10;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  DAT_00fe5c = uVar9;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  DAT_00ffde = uVar16;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  DPP2 = uVar8;
  uVar1 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP0 = uVar7;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}

