/* c1fd9c calc_load */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calibration-based load calculation; uses tables 0x7564/0x794A/0x79B6. */

void calc_load(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  
  if ((DAT_e0089e == '\x02') || (ram_var_ca37 != '\0')) {
    _DAT_e008a8 = 0;
  }
  else {
    if (DAT_e0081b == '\0') {
      uVar1 = axis16_unsigned((short)&axis_engine_speed,_engine_speed_input);
      uVar2 = axis16_unsigned((short)&axis_load,_calc_input_y);
      uVar3 = tbl2d_interp(0x794a,0xc0,uVar1,uVar2);
      uVar4 = tbl8_interp(0x79b6,0xc0,_calc_input_correction);
      _load_calc_result =
           (ushort)((uint)uVar3 * (uint)uVar4) >> 0xf |
           (short)((uint)uVar3 * (uint)uVar4 >> 0x10) << 1;
    }
    else {
      _load_calc_result = 0;
    }
    if (_DAT_e008a8 < _load_calc_result) {
      uVar1 = axis16_unsigned((short)&axis_load,_calc_input_y);
      uVar1 = tbl8_interp(0x79aa,0xc0,uVar1);
      _DAT_e008a8 = rate_limit(_DAT_e008a8,_load_calc_result,uVar1);
    }
    else if ((ram_var_c604 != '\0') || (uVar1 = cal_limit_flag, cal_calc_variant != '\x01')) {
      uVar1 = axis16_unsigned((short)&axis_engine_speed,_engine_speed_input);
      uVar1 = tbl8_interp(0x799e,0xc0,uVar1);
    }
    if (_load_calc_result <= _DAT_e008a8) {
      _DAT_e008a8 = rate_limit(_load_calc_result,uVar1);
    }
  }
  return;
}


