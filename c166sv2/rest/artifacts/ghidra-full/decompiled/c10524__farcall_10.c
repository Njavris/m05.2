// c10524 farcall_10 size=100 cc=unknown proto=undefined farcall_10(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void farcall_10(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  DAT_00fc40 = &stack0x0000;
  uVar2 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  DPP0 = 0x301;
  uVar3 = DPP2;
  uVar4 = DPP2;
  uVar4 = DPP2;
  DPP2 = 0x303;
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  __disable_watchdog();
  uVar5 = TFR;
  uVar1 = DAT_00fdfe;
  DAT_00fdfe = uVar1 | uVar5;
  uVar1 = TFR;
  if ((uVar1 & 0x80) != 0) {
    uVar1 = TFR;
    TFR = uVar1 & 0xff7f;
  }
  uVar1 = TFR;
  if ((uVar1 & 0x10) != 0) {
    uVar1 = TFR;
    TFR = uVar1 & 0xffef;
    _DAT_fffdfc = _DAT_fffdfc | _DAT_fff000;
    FUN_c10588(uVar3,uVar2);
  }
  uVar1 = TFR;
  if ((uVar1 & 8) != 0) {
    uVar1 = TFR;
    TFR = uVar1 & 0xfff7;
  }
  uVar1 = TFR;
  if ((uVar1 & 4) != 0) {
    uVar1 = TFR;
    TFR = uVar1 & 0xfffb;
  }
  __software_reset();
  DPP2 = uVar3;
  uVar3 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}

