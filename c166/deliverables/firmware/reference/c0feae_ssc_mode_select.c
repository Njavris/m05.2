/* c0feae ssc_mode_select */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Select SSC mode from calibration byte 0xC05036. */

void ssc_mode_select(void)

{
  ssc_var_c484 = 4;
  _ssc_var_c48c = 0;
  if (cal_flag_6b68 == '\0') {
    _ssc_var_c48a = 1;
    if (cal_config_selector == '\x01') {
      _ssc_var_c48a = 0;
      _ssc_var_c48c = 1;
      return;
    }
    if (cal_config_selector == '\x02') {
      ssc_var_c484 = 10;
      return;
    }
    if (cal_config_selector == '\x03') {
      ssc_var_c484 = 8;
      return;
    }
  }
  else {
    _ssc_var_c48a = 0;
  }
  return;
}


