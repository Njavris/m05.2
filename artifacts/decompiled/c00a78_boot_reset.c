/* c00a78 boot_reset */

/* WARNING: This function may have set the stack pointer */
/* Reset vector: watchdog, stack, DPPs, self-test, then boot_main. */

void boot_reset(void)

{
  ushort uVar1;
  
  WDTCON = 0xcf01;
  ADDRSEL1 = 0x17;
  ADDRSEL2 = 0x8fbb;
  DAT_00ffdc = 0;
  P8 = 0;
  DAT_00ffaa = 0;
  uVar1 = DP3;
  DP3 = uVar1 | 0x8000;
  uVar1 = P3;
  P3 = uVar1 | 0x8000;
  DAT_00fefa = 0x8000;
  SYSCON = 0xc0;
  __atomic(3);
  SP = 0xfc00;
  STKOV = 0xfa0c;
  STKUN = 0xfc00;
  DPP0 = 0x300;
  DPP1 = 0x301;
  DPP2 = 0x302;
  uVar1 = PSW;
  PSW = uVar1 & 0xfcff | 0x200;
  uVar1 = PSW;
  PSW = uVar1 & 0xfcff | 0x300;
  uVar1 = PSW;
  PSW = uVar1 & 0xfcff;
  __end_of_init();
  boot_cinit();
  delay_loop();
  DAT_00ffbe = 0x9000;
  DAT_00f09c = 0;
  P5DIDIS = 0x59;
  uVar1 = DAT_00ffbe;
  DAT_00ffbe = uVar1 | 0x80;
  do {
    uVar1 = ADCIC;
  } while ((uVar1 & 0x80) == 0);
  uVar1 = ADCIC;
  ADCIC = uVar1 & 0xff7f;
  uVar1 = ADEIC;
  ADEIC = uVar1 & 0xff7f;
  uVar1 = ADDAT;
  if (0x396 < (uVar1 & 0xfff) >> 2) {
    DAT_00ffbe = 0x9003;
    DAT_00f09c = 0;
    P5DIDIS = 0x59;
    uVar1 = DAT_00ffbe;
    DAT_00ffbe = uVar1 | 0x80;
    do {
      uVar1 = ADCIC;
    } while ((uVar1 & 0x80) == 0);
    uVar1 = ADCIC;
    ADCIC = uVar1 & 0xff7f;
    uVar1 = ADEIC;
    ADEIC = uVar1 & 0xff7f;
    uVar1 = ADDAT;
    if (0x396 < (uVar1 & 0xfff) >> 2) {
      DAT_00ffbe = 0x9004;
      DAT_00f09c = 0;
      P5DIDIS = 0x59;
      uVar1 = DAT_00ffbe;
      DAT_00ffbe = uVar1 | 0x80;
      do {
        uVar1 = ADCIC;
      } while ((uVar1 & 0x80) == 0);
      uVar1 = ADCIC;
      ADCIC = uVar1 & 0xff7f;
      uVar1 = ADEIC;
      ADEIC = uVar1 & 0xff7f;
      uVar1 = ADDAT;
      if ((uVar1 & 0xfff) >> 2 < 0x67) {
        DAT_00ffbe = 0x9006;
        DAT_00f09c = 0;
        P5DIDIS = 0x59;
        uVar1 = DAT_00ffbe;
        DAT_00ffbe = uVar1 | 0x80;
        do {
          uVar1 = ADCIC;
        } while ((uVar1 & 0x80) == 0);
        uVar1 = ADCIC;
        ADCIC = uVar1 & 0xff7f;
        uVar1 = ADEIC;
        ADEIC = uVar1 & 0xff7f;
        uVar1 = ADDAT;
        if ((uVar1 & 0xfff) >> 2 < 0x67) {
          __end_of_init();
          boot_periph_init(0,0,0);
          boot_minimal_main();
          return;
        }
      }
    }
  }
  DAT_00ffbe = 0x9006;
  DAT_00f09c = 0;
  P5DIDIS = 0x59;
  uVar1 = DAT_00ffbe;
  DAT_00ffbe = uVar1 | 0x80;
  do {
    uVar1 = ADCIC;
  } while ((uVar1 & 0x80) == 0);
  uVar1 = ADCIC;
  ADCIC = uVar1 & 0xff7f;
  uVar1 = ADEIC;
  ADEIC = uVar1 & 0xff7f;
  uVar1 = ADDAT;
  if (0x396 < (uVar1 & 0xfff) >> 2) {
    DAT_00ffbe = 0x9004;
    DAT_00f09c = 0;
    P5DIDIS = 0x59;
    uVar1 = DAT_00ffbe;
    DAT_00ffbe = uVar1 | 0x80;
    do {
      uVar1 = ADCIC;
    } while ((uVar1 & 0x80) == 0);
    uVar1 = ADCIC;
    ADCIC = uVar1 & 0xff7f;
    uVar1 = ADEIC;
    ADEIC = uVar1 & 0xff7f;
    uVar1 = ADDAT;
    if (0x396 < (uVar1 & 0xfff) >> 2) {
      DAT_00ffbe = 0x9005;
      DAT_00f09c = 0;
      P5DIDIS = 0x59;
      uVar1 = DAT_00ffbe;
      DAT_00ffbe = uVar1 | 0x80;
      do {
        uVar1 = ADCIC;
      } while ((uVar1 & 0x80) == 0);
      uVar1 = ADCIC;
      ADCIC = uVar1 & 0xff7f;
      uVar1 = ADEIC;
      ADEIC = uVar1 & 0xff7f;
      uVar1 = ADDAT;
      if ((uVar1 & 0xfff) >> 2 < 0x15) {
        __end_of_init();
        boot_periph_init(0,0,0);
        bootloader_entry();
        return;
      }
    }
  }
  __end_of_init();
  boot_main(0,0,0);
  return;
}


