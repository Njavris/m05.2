// c202ee calc_limit3 size=170 cc=unknown proto=undefined calc_limit3(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void calc_limit3(void)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar1 = DAT_00c936;
  uVar1 = axis16_signed(0x7552,uVar1);
  _DAT_e008a6 = tbl16_interp(0x7912,0xc0,uVar1);
  _DAT_e008a4 = tbl8_interp(0x78e2,0xc0,uVar1);
  uVar2 = tbl8_interp(0x7874,0xc0,uVar1);
  uVar1 = DAT_00c06a;
  uVar1 = axis16_unsigned(0x750a,uVar1);
  uVar3 = tbl8_interp(0x78d8,0xc0,uVar1);
  _DAT_e008ac = (ushort)((uint)uVar2 * (uint)uVar3) >> 0xd |
                (short)((uint)uVar2 * (uint)uVar3 >> 0x10) << 3;
  if (0x8000 < _DAT_e008ac) {
    _DAT_e008ac = 0x8000;
  }
  _DAT_e008a0 = _DAT_e008ac;
  return;
}

