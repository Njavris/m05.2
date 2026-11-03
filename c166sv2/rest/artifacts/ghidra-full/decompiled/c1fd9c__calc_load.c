// c1fd9c calc_load size=322 cc=unknown proto=undefined calc_load(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void calc_load(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  ushort uVar5;
  
  if ((DAT_e0089e == '\x02') || (cVar1 = DAT_00ca37, cVar1 != '\0')) {
    _DAT_e008a8 = 0;
  }
  else {
    if (DAT_e0081b == '\0') {
      uVar3 = DAT_00c9d0;
      uVar2 = axis16_unsigned(0x7564,uVar3);
      uVar3 = DAT_00ca2a;
      uVar3 = axis16_unsigned(0x755e,uVar3);
      uVar4 = tbl2d_interp(0x794a,0xc0,uVar2,uVar3);
      uVar3 = DAT_00c97c;
      uVar5 = tbl8_interp(0x79b6,0xc0,uVar3);
      _DAT_e008b2 = (ushort)((uint)uVar4 * (uint)uVar5) >> 0xf |
                    (short)((uint)uVar4 * (uint)uVar5 >> 0x10) << 1;
    }
    else {
      _DAT_e008b2 = 0;
    }
    if (_DAT_e008a8 < _DAT_e008b2) {
      uVar3 = DAT_00ca2a;
      uVar3 = axis16_unsigned(0x755e,uVar3);
      uVar3 = tbl8_interp(0x79aa,0xc0,uVar3);
      _DAT_e008a8 = rate_limit(_DAT_e008a8,_DAT_e008b2,uVar3);
    }
    else {
      cVar1 = DAT_00c604;
      if ((cVar1 != '\0') || (uVar3 = DAT_c079ca, DAT_c0507a != '\x01')) {
        uVar3 = DAT_00c9d0;
        uVar3 = axis16_unsigned(0x7564,uVar3);
        uVar3 = tbl8_interp(0x799e,0xc0,uVar3);
      }
    }
    if (_DAT_e008b2 <= _DAT_e008a8) {
      _DAT_e008a8 = rate_limit(_DAT_e008b2,uVar3);
    }
  }
  return;
}

