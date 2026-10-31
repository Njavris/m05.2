/* c00d34 timer7_isr */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Timer7 interrupt: ASC0 state machine + KWP dispatcher, 1 ms tick. */

void timer7_isr(void)

{
  bool bVar1;
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
  undefined2 uVar15;
  
  isr_save_fc40 = &stack0x0000;
  uVar6 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x300;
  uVar7 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP2 = 0x302;
  uVar15 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  uVar9 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  uVar10 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  uVar14 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  uVar13 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar11 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  uVar12 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00f000;
  uVar3 = DAT_00f000;
  uVar3 = DAT_00f000;
  uVar3 = DAT_00f002;
  uVar4 = DAT_00f002;
  uVar4 = DAT_00f002;
  uVar4 = DAT_00f004;
  uVar5 = DAT_00f004;
  uVar5 = DAT_00f004;
  uVar5 = DPP3;
  uVar8 = DPP3;
  uVar8 = DPP3;
  asc0_state_dispatch(uVar5,uVar4,uVar3,uVar2,uVar12,uVar11,uVar13,uVar14,uVar10,uVar9,uVar15,uVar7,
                      uVar6);
  kwp_dispatch();
  bVar1 = 1000 < _timer7_tick;
  _timer7_tick = _timer7_tick + 1;
  if (bVar1) {
    _timer7_tick = 0;
  }
  DAT_00f006 = uVar5;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  DAT_00f004 = uVar4;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  DAT_00f002 = uVar3;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DAT_00ff0a = uVar12;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  uVar2 = DAT_00ff0a;
  DAT_00ff08 = uVar11;
  uVar2 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  uVar2 = DAT_00ff08;
  DAT_00ffda = uVar13;
  uVar2 = DAT_00ffda;
  uVar2 = DAT_00ffda;
  uVar2 = DAT_00ffda;
  DAT_00ffdc = uVar14;
  uVar2 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  uVar2 = DAT_00ffdc;
  DAT_00fe5e = uVar10;
  uVar2 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  uVar2 = DAT_00fe5e;
  DAT_00fe5c = uVar9;
  uVar2 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  uVar2 = DAT_00fe5c;
  DAT_00ffde = uVar15;
  uVar2 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  uVar2 = DAT_00ffde;
  DPP2 = uVar7;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar6;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}


