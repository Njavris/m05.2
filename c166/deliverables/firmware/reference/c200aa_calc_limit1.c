/* c200aa calc_limit1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calibration-based limit calculation (table 0x7912). */

void calc_limit1(void)

{
  if ((engine_state == '\x04') || (engine_state == '\x01')) {
    calc_limit3();
  }
  else if (DAT_e0085b == '\0') {
    if (((engine_state == '\x03') && (limit_flag_2 = 1, _limit_value_4 <= _limit_counter_c)) &&
       ((0x80 < _limit_value_0 || (0x80 < _limit_value_2)))) {
      limit_flag_2 = 0;
      _limit_counter_c = 0;
      _limit_value_0 = (ushort)((uint)_limit_value_0 * (uint)cal_pwm_scale >> 0x10);
      if (_limit_value_0 < 0x81) {
        _limit_value_0 = 0;
      }
      if ((DAT_e00822 != '\0') &&
         (_limit_value_2 = (ushort)((uint)_limit_value_2 * (uint)_limit_value_3 >> 0x10),
         _limit_value_2 < 0x81)) {
        _limit_value_2 = 0;
      }
      _limit_value_4 = tbl16_interp(0x7912,0xc0,_calc_input_correction);
    }
  }
  else {
    _limit_value_2 = 0x8000;
  }
  if (_limit_value_0 < _limit_value_2) {
    _limit_value_2 = _limit_value_0;
  }
  return;
}


