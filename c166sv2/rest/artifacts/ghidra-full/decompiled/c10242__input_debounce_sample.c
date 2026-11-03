// c10242 input_debounce_sample size=154 cc=unknown proto=undefined input_debounce_sample(void)

void input_debounce_sample(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = 1;
  do {
    __service_watchdog();
    uVar1 = DAT_00c49a;
    if ((uVar2 & uVar1) == 0) {
      uVar1 = DAT_00c49c;
      DAT_00c49c = uVar1 | uVar2;
    }
    else {
      uVar1 = DAT_00c4b6;
      DAT_00c4b6 = uVar1 | uVar2;
    }
    if (uVar2 == 8) {
      uVar1 = P1L;
      if ((uVar1 & 0x40) == 0) {
        uVar1 = DAT_00c49a;
        DAT_00c49a = uVar1 & 0xfff7;
      }
      else {
        uVar1 = DAT_00c49a;
        DAT_00c49a = uVar1 | 8;
      }
    }
    else if (uVar2 == 0x80) {
      uVar1 = P1L;
      if ((uVar1 & 1) == 0) {
        uVar1 = DAT_00c49a;
        DAT_00c49a = uVar1 & 0xff7f;
      }
      else {
        uVar1 = DAT_00c49a;
        DAT_00c49a = uVar1 | 0x80;
      }
    }
    else if (uVar2 == 0x20) {
      uVar1 = P1L;
      if ((uVar1 & 4) == 0) {
        uVar1 = DAT_00c49a;
        DAT_00c49a = uVar1 & 0xffdf;
      }
      else {
        uVar1 = DAT_00c49a;
        DAT_00c49a = uVar1 | 0x20;
      }
    }
    else if (uVar2 == 0x10) {
      uVar1 = P1L;
      if ((uVar1 & 0x20) == 0) {
        uVar1 = DAT_00c49a;
        DAT_00c49a = uVar1 & 0xffef;
      }
      else {
        uVar1 = DAT_00c49a;
        DAT_00c49a = uVar1 | 0x10;
      }
    }
    uVar2 = uVar2 * 2;
  } while (uVar2 < 0x81);
  return;
}

