/* c01048 pll_isr */

/* PLL/oscillator watchdog interrupt; performs software reset. */

void pll_isr(void)

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
  
  uVar12 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar6 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar7 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar11 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar10 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar8 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar9 = DAT_00ff0a;
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
  uVar4 = DPP3;
  uVar5 = DPP3;
  uVar5 = DPP3;
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
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DAT_00ff0a = uVar9;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  DAT_00ff08 = uVar8;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  DAT_00ffda = uVar10;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  DAT_00ffdc = uVar11;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  DAT_00fe5e = uVar7;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  DAT_00fe5c = uVar6;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  DAT_00ffde = uVar12;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  return;
}


