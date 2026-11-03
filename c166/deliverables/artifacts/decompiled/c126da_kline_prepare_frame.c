/* c126da kline_prepare_frame */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Computes K-line timing fields and enters state 6. */

void kline_prepare_frame(undefined1 param_1)

{
  ushort uVar1;
  
  kline_flag_c5a9 = param_1;
  _kline_var_c59e = 0;
  if (kline_var_c5a0 != '\0') {
    _kline_var_c5a6 = (short)(kline_var_c599 + 0xf) >> 4;
    uVar1 = (ushort)kline_var_c57f;
    if (0xf0 < uVar1) {
      uVar1 = uVar1 * 0x100 + 0x1000;
    }
    _kline_var_c59c = (uVar1 << 5) / 10;
    kline_var_c5a5 = kline_var_c57f;
    kline_var_c57e = kline_var_c598;
    kline_var_c5a8 = kline_var_c580;
    kline_var_c577 = kline_var_c592;
    _kline_var_c5bc = (short)(kline_var_c598 + 0xf) >> 4;
    kline_var_c57c = kline_var_c599;
    if (kline_var_c580 == 0xff) {
      _kline_var_c5b4 = -1;
    }
    else {
      _kline_var_c5b4 = (ushort)kline_var_c580 << 5;
    }
    _kline_var_c586 = (short)(kline_var_c592 + 0xf) >> 4;
    kline_var_c5a0 = '\0';
  }
  _kline_state = 6;
  kline_var_c58c = 0;
  kline_var_c56f = 0;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x10;
  return;
}


