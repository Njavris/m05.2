/* c202ee calc_limit3 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calibration-based limit calculation (tables 0x7552/0x7912/0x78E2). */

void calc_limit3(void)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar1 = axis16_signed((short)&axis_limit_3,_calc_input_z);
  _limit_value_4 = tbl16_interp(0x7912,0xc0,uVar1);
  _limit_value_3 = tbl8_interp(0x78e2,0xc0,uVar1);
  uVar2 = tbl8_interp(0x7874,0xc0,uVar1);
  uVar1 = axis16_unsigned((short)&axis_limit_3_alt,_calc_input_w);
  uVar3 = tbl8_interp(0x78d8,0xc0,uVar1);
  _limit_value_2 =
       (ushort)((uint)uVar2 * (uint)uVar3) >> 0xd | (short)((uint)uVar2 * (uint)uVar3 >> 0x10) << 3;
  if (0x8000 < _limit_value_2) {
    _limit_value_2 = 0x8000;
  }
  _limit_value_0 = _limit_value_2;
  return;
}


