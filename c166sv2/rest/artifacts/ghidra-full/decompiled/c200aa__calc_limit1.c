// c200aa calc_limit1 size=260 cc=unknown proto=undefined calc_limit1(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void calc_limit1(void)

{
  ushort uVar1;
  char cVar2;
  undefined2 uVar3;
  
  cVar2 = DAT_00c93c;
  if ((cVar2 == '\x04') || (cVar2 == '\x01')) {
    calc_limit3();
  }
  else if (DAT_e0085b == '\0') {
    cVar2 = DAT_00c93c;
    if (cVar2 == '\x03') {
      DAT_00c886 = 1;
      uVar1 = DAT_00c86e;
      if ((_DAT_e008a6 <= uVar1) && ((0x80 < _DAT_e008a0 || (0x80 < _DAT_e008ac)))) {
        DAT_00c886 = 0;
        DAT_00c86e = 0;
        _DAT_e008a0 = (ushort)((uint)_DAT_e008a0 * (uint)DAT_c078e0 >> 0x10);
        if (_DAT_e008a0 < 0x81) {
          _DAT_e008a0 = 0;
        }
        if ((DAT_e00822 != '\0') &&
           (_DAT_e008ac = (ushort)((uint)_DAT_e008ac * (uint)_DAT_e008a4 >> 0x10),
           _DAT_e008ac < 0x81)) {
          _DAT_e008ac = 0;
        }
        uVar3 = DAT_00c97c;
        _DAT_e008a6 = tbl16_interp(0x7912,0xc0,uVar3);
      }
    }
  }
  else {
    _DAT_e008ac = 0x8000;
  }
  if (_DAT_e008a0 < _DAT_e008ac) {
    _DAT_e008ac = _DAT_e008a0;
  }
  return;
}

