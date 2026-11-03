/* c201ae calc_limit2 */

/* WARNING: Removing unreachable block (ram,0xc201fa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calibration-based limit calculation (tables 0x7860/0x784C). */

void calc_limit2(void)

{
  undefined2 uVar1;
  
  if (DAT_e0085b != '\0') {
    _limit_value_5 = 0;
    _limit_value_1 = 0;
    return;
  }
  if (engine_state == '\x03') {
    limit_flag_1 = 1;
    if ((0x80 < _limit_value_1) && (cal_limit_count <= _limit_counter_b)) {
      limit_flag_1 = 0;
      _limit_counter_b = 0;
      _limit_value_1 = (ushort)((uint)_limit_value_1 * (uint)cal_limit_multiplier >> 0x10);
      if (_limit_value_1 < 0x81) {
        _limit_value_1 = 0;
      }
    }
  }
  else {
    limit_flag_1 = 0;
    _limit_counter_b = 0;
    _limit_value_1 = tbl8_interp(0x7860,0xc0,_calc_input_correction);
  }
  if (engine_state != '\x03') {
    _limit_counter_a = 0;
    _limit_value_5 = 0;
    return;
  }
  if ((_engine_speed_input < cal_speed_limit_threshold) ||
     (limit_flag_0 = 1, _limit_counter_a < cal_limit_counter_threshold)) {
    speed_limit_active = '\0';
  }
  else {
    limit_flag_0 = 0;
    speed_limit_active = '\x01';
  }
  uVar1 = _calc_input_x;
  if (speed_limit_active == '\0') {
    uVar1 = cal_limit_fallback_speed;
  }
  uVar1 = axis16_unsigned((short)&axis_limit_2,uVar1);
  _limit_value_5 = tbl8_interp(0x784c,0xc0,uVar1);
  return;
}


