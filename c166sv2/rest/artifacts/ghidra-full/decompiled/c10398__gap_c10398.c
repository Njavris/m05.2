// c10398 gap_c10398 size=40 cc=unknown proto=undefined gap_c10398(void)

short gap_c10398(ushort param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  uVar1 = DAT_00ffbe;
  DAT_00ffbe = uVar1 & 0xf000 | param_1;
  uVar1 = DAT_00ffbe;
  DAT_00ffbe = uVar1 | 0x80;
  do {
    uVar1 = ADCIC;
  } while ((uVar1 & 0x80) == 0);
  uVar2 = func_0xc10390();
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return (uVar2 & 0xffc) << 4;
}

