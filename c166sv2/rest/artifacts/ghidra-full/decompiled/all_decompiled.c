
/* ===== c00000 boot_reset size=4 ===== */

/* WARNING: This function may have set the stack pointer */

void boot_reset(void)

{
  ushort uVar1;
  
  WDTCON = 0xcf01;
  ADDRSEL1 = 0x17;
  ADDRSEL2 = 0x8fbb;
  SYSCON1 = 0;
  SYSCON3 = 0;
  DAT_00ffaa = 0;
  uVar1 = DP3;
  DP3 = uVar1 | 0x8000;
  uVar1 = P3;
  P3 = uVar1 | 0x8000;
  DAT_00f0fa = 0x8000;
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



/* ===== c00200 boot_main size=220 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void boot_main(void)

{
  char cVar1;
  undefined1 uVar2;
  ushort uVar3;
  short sVar4;
  ushort extraout_r10;
  ushort extraout_r10_00;
  short extraout_r11;
  short extraout_r11_00;
  
  uVar3 = input_status;
  if ((uVar3 & 2) != 0) {
    mem_read_word(0x7fc,0xe0);
    if (extraout_r11 + 0x9bb0U == (ushort)(extraout_r10 < 0x8625) && extraout_r10 == 0x8625) {
      DAT_00c020 = 1;
    }
    mem_read_word();
    if (extraout_r11_00 + 0x79cdU == (ushort)(extraout_r10_00 < 0x6450) && extraout_r10_00 == 0x6450
       ) {
      DAT_00c020 = 2;
    }
  }
  mem_write_word();
  boot_periph_init();
  if (_app_entry == 0) {
    bootloader_entry(0);
  }
  uVar3 = input_status;
  if ((uVar3 & 0x400) != 0) {
    bootloader_entry();
  }
  cVar1 = DAT_00c020;
  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    uVar2 = DAT_00c020;
    asc0_state2_init(uVar2);
    bootloader_entry();
  }
  if ((DAT_c3fffc != -0x5600) &&
     ((sVar4 = checksum16_be(0,0xc0,0x1ffd,0xc0), sVar4 != DAT_c01ffe ||
      (sVar4 = checksum16_be(0xb000,0xc0,0xfffb,0xc3), sVar4 != DAT_c3fffe)))) {
    bootloader_entry();
    return;
  }
  app_entry();
  return;
}



/* ===== c002dc boot_periph_init size=50 ===== */

void boot_periph_init(void)

{
  undefined1 uVar1;
  ushort uVar2;
  
  boot_bus_mode();
  SYSCON2 = 0x7f13;
  clock_init();
  uVar1 = DAT_00c020;
  asc0_init(uVar1);
  uVar1 = DAT_00c020;
  capcom_timer_init(uVar1);
  boot_extint_init();
  asc0_pin_init();
  boot_port_adc_init();
  can_twincan_init();
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return;
}



/* ===== c0030e boot_bus_mode size=112 ===== */

void boot_bus_mode(void)

{
  ushort uVar1;
  undefined2 uVar2;
  
  uVar1 = DAT_00f0c2;
  if ((uVar1 & 0x1800) == 0x800) {
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x8e00;
  }
  uVar1 = DAT_00f0c2;
  if ((uVar1 & 0x1800) == 0x1800) {
    DAT_00f0c0 = 0xaaaa;
    DAT_00f0c0 = 0x5554;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x9600;
    DAT_00f0c0 = 0x800;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x8e00;
  }
  return;
}



/* ===== c0037e checksum16_be size=58 ===== */

short checksum16_be(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  bool bVar1;
  short sVar2;
  
  sVar2 = 0;
  __disable_watchdog();
  for (; param_2 < param_4 || param_2 == param_4 && param_1 < param_3; param_2 = param_2 + bVar1) {
    sVar2 = sVar2 + *(short *)(uint3)param_1 * 0x100 + (*(ushort *)(uint3)param_1 >> 8);
    bVar1 = 0xfffd < param_1;
    param_1 = param_1 + 2;
  }
  return sVar2;
}



/* ===== c003b8 delay_loop size=10 ===== */

void delay_loop(void)

{
  bool bVar1;
  short sVar2;
  
  sVar2 = 0;
  do {
    bVar1 = sVar2 < 0x62f;
    sVar2 = sVar2 + 1;
  } while (bVar1);
  return;
}



/* ===== c003c2 delay_ticks size=28 ===== */

void delay_ticks(short param_1)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  
  for (sVar3 = 0; sVar3 < param_1; sVar3 = sVar3 + 1) {
    __service_watchdog();
    sVar2 = 0;
    do {
      bVar1 = sVar2 < 0x7bbf;
      sVar2 = sVar2 + 1;
    } while (bVar1);
  }
  return;
}



/* ===== c003de boot_minimal_main size=18 ===== */

void boot_minimal_main(void)

{
  asc0_init(0);
  capcom_timer_init(0);
  can_bootloader_wait();
  return;
}



/* ===== c003f0 bootloader_entry size=56 ===== */

void bootloader_entry(void)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar1 = P1L;
  P1L = uVar1 & 0xffdf;
  uVar1 = BUSCON2;
  BUSCON2 = uVar1 & 0xffef;
  uVar1 = P1L;
  P1L = uVar1 & 0xffbf;
  delay_ticks(1);
  ssc_start_frame();
  delay_ticks(1);
  ssc_start_frame();
  uVar1 = DP1L;
  DP1L = uVar1 & 0xffbf;
  do {
    do {
      delay_ticks(500);
      uVar1 = DAT_00c078;
    } while ((uVar1 & 0x10) != 0);
    uVar1 = DP1L;
    DP1L = uVar1 | 0x40;
    uVar2 = P1L;
    uVar1 = P1L;
    uVar3 = P1L;
    P1L = uVar3 & 0xffbf | ((uVar1 & 0x40) >> 6 ^ 1) << 6;
  } while( true );
}



/* ===== c00428 gap_c00428 size=10 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c00428(undefined2 param_1)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  
  uVar2 = Ram00fd22;
  Ram00fd22 = uVar2 & 0xffdf;
  uVar2 = Ram00fe22;
  uRam00116a = uRam00116a & uVar2;
  uVar2 = Ram00fe22;
  Ram00fe22 = uVar2 | 0x8ef6;
  sVar1 = Ram00ff80;
  Ram00ff80 = (short)&UNK_00fce6 + sVar1;
  _DAT_200210 = 0;
  _DAT_200222 = 0x60;
  uVar2 = DAT_00f138;
  DAT_00f138 = uVar2 | 8;
  uVar2 = BUSCON3;
  BUSCON3 = uVar2 & 0xfff7 | 8;
  uVar2 = DAT_00f13a;
  DAT_00f13a = uVar2 | 8;
  _DAT_20020c = 0x2387;
  _DAT_20020e = 0;
  _DAT_200214 = 0;
  _DAT_200216 = 0;
  _DAT_200314 = 0x80;
  _DAT_200316 = _DAT_200516 & 0xfff8;
  _DAT_20030c = 0xffff;
  _DAT_20030e = 0xffff;
  _DAT_200308 = 0;
  _DAT_20030a = 0x1f80;
  _DAT_200300 = 0;
  _DAT_200302 = 0;
  _DAT_200304 = 0;
  _DAT_200306 = 0;
  _DAT_200318 = 0;
  _DAT_20031a = _DAT_20031a & 0xffe0;
  _DAT_200310 = 0x1599;
  _DAT_200312 = 0;
  _DAT_200514 = 0x88;
  _DAT_200516 = _DAT_200356 & 0xfff8 | 2;
  _DAT_20050c = 0xffff;
  _DAT_20050e = 0xffff;
  _DAT_200508 = 0;
  _DAT_20050a = 0x1f90;
  _DAT_200500 = 0;
  _DAT_200502 = 0;
  _DAT_200504 = 0;
  _DAT_200506 = 0;
  _DAT_200518 = 0x200f;
  _DAT_20051a = 0x210;
  _DAT_200510 = 0x1595;
  _DAT_200512 = 0;
  bVar3 = 0;
  _DAT_200200 = param_1;
  do {
    sVar1 = (ushort)bVar3 * 0x20;
    *(undefined2 *)(uint3)(sVar1 + 0x534) = 8;
    *(undefined2 *)(uint3)(sVar1 + 0x536) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x52c) = 0xffff;
    *(undefined2 *)(uint3)(sVar1 + 0x52e) = 0xffff;
    *(undefined2 *)(uint3)(sVar1 + 0x528) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x52a) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x520) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x522) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x524) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x526) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x538) = 0x200f;
    *(undefined2 *)(uint3)(sVar1 + 0x53a) = 0x310;
    *(undefined2 *)(uint3)(sVar1 + 0x530) = 0x1595;
    *(undefined2 *)(uint3)(sVar1 + 0x532) = 0;
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0xf);
  uVar2 = XP2IC;
  XP2IC = uVar2 | 8;
  uVar2 = XP2IC;
  XP2IC = uVar2 | 0x40;
  DAT_00c000 = 0x10;
  _DAT_200004 = 0xb;
  _DAT_000200 = _DAT_000200 & 0xffbe;
  return;
}



/* ===== c00434 can_twincan_init size=608 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can_twincan_init(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  
  DAT_00c016 = 0;
  _DAT_200200 = 0x41;
  _DAT_200210 = 0;
  _DAT_200222 = 0x60;
  uVar2 = DAT_00f138;
  DAT_00f138 = uVar2 | 8;
  uVar2 = BUSCON3;
  BUSCON3 = uVar2 & 0xfff7 | 8;
  uVar2 = DAT_00f13a;
  DAT_00f13a = uVar2 | 8;
  _DAT_20020c = 0x2387;
  _DAT_20020e = 0;
  _DAT_200214 = 0;
  _DAT_200216 = 0;
  _DAT_200314 = 0x80;
  _DAT_200316 = _DAT_200516 & 0xfff8;
  _DAT_20030c = 0xffff;
  _DAT_20030e = 0xffff;
  _DAT_200308 = 0;
  _DAT_20030a = 0x1f80;
  _DAT_200300 = 0;
  _DAT_200302 = 0;
  _DAT_200304 = 0;
  _DAT_200306 = 0;
  _DAT_200318 = 0;
  _DAT_20031a = _DAT_20031a & 0xffe0;
  _DAT_200310 = 0x1599;
  _DAT_200312 = 0;
  _DAT_200514 = 0x88;
  _DAT_200516 = _DAT_200356 & 0xfff8 | 2;
  _DAT_20050c = 0xffff;
  _DAT_20050e = 0xffff;
  _DAT_200508 = 0;
  _DAT_20050a = 0x1f90;
  _DAT_200500 = 0;
  _DAT_200502 = 0;
  _DAT_200504 = 0;
  _DAT_200506 = 0;
  _DAT_200518 = 0x200f;
  _DAT_20051a = 0x210;
  _DAT_200510 = 0x1595;
  _DAT_200512 = 0;
  bVar3 = 0;
  do {
    sVar1 = (ushort)bVar3 * 0x20;
    *(undefined2 *)(uint3)(sVar1 + 0x534) = 8;
    *(undefined2 *)(uint3)(sVar1 + 0x536) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x52c) = 0xffff;
    *(undefined2 *)(uint3)(sVar1 + 0x52e) = 0xffff;
    *(undefined2 *)(uint3)(sVar1 + 0x528) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x52a) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x520) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x522) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x524) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x526) = 0;
    *(undefined2 *)(uint3)(sVar1 + 0x538) = 0x200f;
    *(undefined2 *)(uint3)(sVar1 + 0x53a) = 0x310;
    *(undefined2 *)(uint3)(sVar1 + 0x530) = 0x1595;
    *(undefined2 *)(uint3)(sVar1 + 0x532) = 0;
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0xf);
  uVar2 = XP2IC;
  XP2IC = uVar2 | 8;
  uVar2 = XP2IC;
  XP2IC = uVar2 | 0x40;
  DAT_00c000 = 0x10;
  _DAT_200004 = 0xb;
  _DAT_000200 = _DAT_000200 & 0xffbe;
  return;
}



/* ===== c00694 can0_isr size=232 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can0_isr(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  byte bVar15;
  
  DAT_00fc00 = &stack0x0000;
  uVar6 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DPP0 = 0x300;
  uVar7 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP2 = 0x302;
  uVar14 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar8 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar9 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar13 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar12 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar10 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar11 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  can_rx_process(uVar4,uVar3,uVar2,uVar1,uVar11,uVar10,uVar12,uVar13,uVar9,uVar8,uVar14,uVar7,uVar6)
  ;
  while ((_DAT_200284 & 1) != 0) {
    if ((_DAT_200310 & 3) == 2) {
      if ((((_DAT_200284 & 1) != 0) && ((_DAT_200310 & 0x300) == 0x200)) &&
         ((_DAT_200310 & 0xc00) != 0x800)) {
        bVar15 = 0;
        do {
          bVar15 = bVar15 + 1;
        } while (bVar15 < 8);
        DAT_00c016 = 1;
      }
      _DAT_200310 = 0xfffd;
    }
  }
  DAT_00f006 = uVar4;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  DAT_00f004 = uVar3;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  DAT_00f002 = uVar2;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  DAT_00f000 = uVar1;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  DAT_00ff0a = uVar11;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  DAT_00ff08 = uVar10;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  DAT_00ffda = uVar12;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  DAT_00ffdc = uVar13;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  DAT_00fe5e = uVar9;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  DAT_00fe5c = uVar8;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  DAT_00ffde = uVar14;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  DPP2 = uVar7;
  uVar1 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP0 = uVar6;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c0077c gap_c0077c size=284 ===== */

undefined2 gap_c0077c(ushort param_1,ushort param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  undefined1 uVar6;
  byte bVar7;
  undefined2 in_r4;
  undefined1 uVar8;
  
  uVar8 = (undefined1)((ushort)in_r4 >> 8);
  sVar4 = (param_1 & 0xff) * 0x20;
  uVar6 = 2;
  if ((*(ushort *)(sVar4 + 0x31a) & 0x700) == 0x200) {
    bVar7 = DAT_00c000;
    sVar5 = (ushort)bVar7 * 0x20;
    uVar2 = sVar5 + 0x310;
    uVar6 = 0;
    if ((*(ushort *)(uint3)uVar2 & 0x3000) == 0x1000) {
      uVar3 = sVar4 + 0x318;
      bVar7 = DAT_00c000;
      DAT_00c000 = bVar7 & ~((byte)*(undefined2 *)(uint3)uVar3 & 0x1f) |
                   cRam000000 + 1U & 0x1f & (byte)*(undefined2 *)(uint3)uVar3;
      *(undefined2 *)(uint3)uVar2 = 63999;
      uVar3 = sVar5 + 0x314;
      if ((*(ushort *)(uint3)uVar3 & 4) == 0) {
        *(short *)(uint3)(sVar5 + 0x30a) = *(short *)(uint3)(param_2 + 2) << 2;
        *(undefined2 *)(uint3)(sVar5 + 0x308) = 0;
      }
      else {
        uVar1 = *(undefined2 *)(uint3)(param_2 + 2);
        *(undefined2 *)(uint3)(sVar5 + 0x30a) = *(undefined2 *)(uint3)(param_2 + 4);
        *(undefined2 *)(uint3)(sVar5 + 0x308) = uVar1;
      }
      *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xf | *(ushort *)(uint3)param_2 & 0xf0;
      for (bVar7 = 0; uVar8 = 0, (ushort)bVar7 < (*(ushort *)(uint3)param_2 & 0xf0) >> 4;
          bVar7 = bVar7 + 1) {
        *(undefined1 *)(uint3)((ushort)bVar7 + sVar5 + 0x300 & 0x3fff) =
             *(undefined1 *)(uint3)(param_2 + 10 + (ushort)bVar7);
      }
      *(undefined2 *)(uint3)uVar2 = 0x66bf;
      uVar6 = 1;
    }
  }
  return CONCAT11(uVar8,uVar6);
}



/* ===== c00898 gap_c00898 size=104 ===== */

void gap_c00898(void)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  char cVar4;
  char cVar5;
  short sVar6;
  undefined3 uVar7;
  short in_r1;
  ushort uVar8;
  ushort uVar9;
  short in_r3;
  ushort extraout_r3;
  ushort uVar10;
  ushort uVar11;
  short sVar12;
  short sVar13;
  
  cVar4 = DAT_00c000;
  cVar5 = DPP0._0_1_;
  DAT_00c000 = cVar4 + cVar5;
  cVar4 = UNK_00c074;
  cVar5 = DPP0._0_1_;
  UNK_00c074 = cVar4 + cVar5;
  cVar4 = DAT_00c096._0_1_;
  cVar5 = DPP0._0_1_;
  DAT_00c096._0_1_ = cVar4 + cVar5;
  sVar13 = DPP0;
  uVar8 = Ram00ff80;
  Ram00ff80 = uVar8 & 0xfbff;
  sVar12 = DPP1;
  sVar12 = ((short)uRam000005 + sVar13) - sVar12;
  uRam000005 = CONCAT12(uRam000005._2_1_,sVar12);
  uVar7 = uRam000005;
  sVar13 = DPP0;
  DPP0 = sVar13 + 0x20;
  cVar4 = DPP0._0_1_;
  DPP0._0_1_ = cVar4 + cRam0008b8;
  sVar13 = DPP0;
  DPP0 = sVar13 + 0x6e;
  cVar4 = DPP0._0_1_;
  DPP0._0_1_ = cVar4 + cRam000ca0;
  puVar3 = (undefined2 *)(CONCAT11((char)((ushort)in_r3 >> 8),(char)in_r3 * '\x02') + in_r3 * 2);
  sVar13 = DPP0;
  DPP0 = sVar13 + uRam000005._1_2_;
  cVar4 = DPP0._0_1_;
  DPP0._0_1_ = cVar4 + cRam000daa;
  cVar4 = DPP0._0_1_;
  uRam000005._1_1_ = (char)((ushort)sVar12 >> 8);
  DPP0._0_1_ = cVar4 + uRam000005._1_1_;
  uRam000003 = *puVar3;
  uRam000005 = uVar7;
  func_0x0d0300(*(undefined2 *)(uint3)(in_r1 + 0xc));
  sVar12 = DPP0;
  DPP0 = sVar12 + 0x9a;
  cVar4 = DPP0._0_1_;
  DPP0._0_1_ = cVar4 + cRam001130;
  sVar12 = DPP0;
  uRam000005 = CONCAT21(uRam000005._1_2_ + sVar12 +
                        (ushort)CARRY2(CONCAT11((char)((ushort)puVar3 >> 8),(char)puVar3 * '\x02'),
                                       extraout_r3),(undefined1)uRam000005);
  DPP1 = (short)(char)uRam000003;
  sVar12 = DPP0;
  DPP0 = sVar12 + sRam000000;
  uVar8 = (ushort)&DAT_00fdfe;
  do {
    if ((uVar8 != (ushort)&UNK_00fc22) && (uVar8 != (ushort)&DAT_00fc20)) {
      *(undefined2 *)(uint3)uVar8 = 0;
    }
    bVar1 = uVar8 != (ushort)&DAT_00fd00;
    uVar8 = uVar8 - 2;
  } while (bVar1);
  uVar8 = 0x8ba;
  do {
    DPP0 = 0x300;
    while( true ) {
      while( true ) {
        uVar10 = uVar8 + 2;
        sVar12 = *(short *)(uint3)uVar8;
        if (sVar12 != 1) break;
        uVar8 = uVar8 + 0xe;
      }
      if (sVar12 == 5) break;
      if (sVar12 == 6) {
        uVar9 = *(ushort *)(uint3)uVar10 & 0x7fff | 0x4000;
        DPP1 = *(undefined2 *)(uint3)(uVar8 + 4);
        uVar11 = *(ushort *)(uint3)(uVar8 + 6) & 0xbfff | 0x8000;
        DPP2 = *(undefined2 *)(uint3)(uVar8 + 8);
        uVar10 = uVar8 + 10;
        uVar8 = uVar8 + 0xc;
        sVar12 = *(short *)(uint3)uVar10;
        while (bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1) {
          puVar2 = (undefined1 *)(uint3)uVar11;
          uVar11 = uVar11 + 1;
          *(undefined1 *)(uint3)uVar9 = *puVar2;
          bVar1 = uVar9 == 0x7fff;
          uVar9 = uVar9 + 1;
          if (bVar1) {
            uVar9 = 0x4000;
            sVar13 = DPP1;
            DPP1 = sVar13 + 1;
          }
        }
        DPP1 = 0x301;
        DPP2 = 0x302;
      }
      else {
        if (sVar12 != 7) {
          uVar8 = 0x898;
          do {
            DPP0 = 0x300;
            while( true ) {
              uVar10 = uVar8 + 2;
              sVar12 = *(short *)(uint3)uVar8;
              if (sVar12 == 5) break;
              if (sVar12 == 6) {
                uVar9 = *(ushort *)(uint3)uVar10 & 0x7fff | 0x4000;
                DPP1 = *(undefined2 *)(uint3)(uVar8 + 4);
                uVar10 = uVar8 + 6;
                uVar8 = uVar8 + 8;
                sVar12 = *(short *)(uint3)uVar10;
                while (bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1) {
                  *(undefined1 *)(uint3)uVar9 = 0;
                  uVar9 = uVar9 + 1;
                }
                DPP1 = 0x301;
              }
              else {
                if (sVar12 != 7) {
                  DPP0 = 0x300;
                  return;
                }
                DPP1 = (*(ushort *)(uint3)(uVar8 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar10 >> 0xe
                ;
                uVar10 = *(ushort *)(uint3)uVar10 & 0x7fff | 0x4000;
                uVar9 = uVar8 + 8;
                sVar12 = *(short *)(uint3)(uVar8 + 6);
                uVar8 = uVar8 + 10;
                sVar13 = *(short *)(uint3)uVar9;
                while ((bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1 ||
                       (bVar1 = sVar13 != 0, sVar13 = sVar13 + -1, bVar1))) {
                  *(undefined1 *)(uint3)uVar10 = 0;
                  bVar1 = uVar10 == 0x7fff;
                  uVar10 = uVar10 + 1;
                  if (bVar1) {
                    uVar10 = 0x4000;
                    sVar6 = DPP1;
                    DPP1 = sVar6 + 1;
                  }
                }
                DPP1 = 0x301;
              }
            }
            uVar9 = uVar8 + 4;
            uVar10 = *(ushort *)(uint3)uVar10;
            uVar8 = uVar8 + 6;
            sVar12 = *(short *)(uint3)uVar9;
            DPP0 = 0x300;
            while (bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1) {
              *(undefined1 *)(uint3)uVar10 = 0;
              uVar10 = uVar10 + 1;
            }
          } while( true );
        }
        DPP1 = (*(ushort *)(uint3)(uVar8 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar10 >> 0xe;
        uVar9 = *(ushort *)(uint3)uVar10 & 0x7fff | 0x4000;
        DPP2 = (*(ushort *)(uint3)(uVar8 + 8) & 0xff) << 2 | *(ushort *)(uint3)(uVar8 + 6) >> 0xe;
        uVar10 = *(ushort *)(uint3)(uVar8 + 6) & 0xbfff | 0x8000;
        uVar11 = uVar8 + 0xc;
        sVar12 = *(short *)(uint3)(uVar8 + 10);
        uVar8 = uVar8 + 0xe;
        sVar13 = *(short *)(uint3)uVar11;
        while ((bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1 ||
               (bVar1 = sVar13 != 0, sVar13 = sVar13 + -1, bVar1))) {
          *(undefined1 *)(uint3)uVar9 = *(undefined1 *)(uint3)uVar10;
          bVar1 = uVar9 == 0x7fff;
          uVar9 = uVar9 + 1;
          if (bVar1) {
            uVar9 = 0x4000;
            sVar6 = DPP1;
            DPP1 = sVar6 + 1;
          }
          bVar1 = uVar10 == 0xbfff;
          uVar10 = uVar10 + 1;
          if (bVar1) {
            uVar10 = 0x8000;
            sVar6 = DPP2;
            DPP2 = sVar6 + 1;
          }
        }
        DPP1 = 0x301;
        DPP2 = 0x302;
      }
    }
    uVar10 = *(ushort *)(uint3)uVar10;
    uVar11 = uVar8 + 6;
    uVar9 = *(ushort *)(uint3)(uVar8 + 4);
    uVar8 = uVar8 + 8;
    sVar12 = *(short *)(uint3)uVar11;
    DPP0 = 0x300;
    while (bVar1 = sVar12 != 0, sVar12 = sVar12 + -1, bVar1) {
      puVar2 = (undefined1 *)(uint3)uVar9;
      uVar9 = uVar9 + 1;
      *(undefined1 *)(uint3)uVar10 = *puVar2;
      uVar10 = uVar10 + 1;
    }
  } while( true );
}



/* ===== c00904 boot_cinit size=372 ===== */

void boot_cinit(void)

{
  bool bVar1;
  undefined1 *puVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  short sVar8;
  short sVar9;
  
  uVar4 = (ushort)&DAT_00fdfe;
  do {
    if ((uVar4 != (ushort)&UNK_00fc22) && (uVar4 != (ushort)&DAT_00fc20)) {
      *(undefined2 *)(uint3)uVar4 = 0;
    }
    bVar1 = uVar4 != (ushort)&DAT_00fd00;
    uVar4 = uVar4 - 2;
  } while (bVar1);
  uVar4 = 0x8ba;
  do {
    DPP0 = 0x300;
    while( true ) {
      while( true ) {
        uVar6 = uVar4 + 2;
        sVar8 = *(short *)(uint3)uVar4;
        if (sVar8 != 1) break;
        uVar4 = uVar4 + 0xe;
      }
      if (sVar8 == 5) break;
      if (sVar8 == 6) {
        uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
        DPP1 = *(undefined2 *)(uint3)(uVar4 + 4);
        uVar7 = *(ushort *)(uint3)(uVar4 + 6) & 0xbfff | 0x8000;
        DPP2 = *(undefined2 *)(uint3)(uVar4 + 8);
        uVar6 = uVar4 + 10;
        uVar4 = uVar4 + 0xc;
        sVar8 = *(short *)(uint3)uVar6;
        while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
          puVar2 = (undefined1 *)(uint3)uVar7;
          uVar7 = uVar7 + 1;
          *(undefined1 *)(uint3)uVar5 = *puVar2;
          bVar1 = uVar5 == 0x7fff;
          uVar5 = uVar5 + 1;
          if (bVar1) {
            uVar5 = 0x4000;
            sVar9 = DPP1;
            DPP1 = sVar9 + 1;
          }
        }
        DPP1 = 0x301;
        DPP2 = 0x302;
      }
      else {
        if (sVar8 != 7) {
          uVar4 = 0x898;
          do {
            DPP0 = 0x300;
            while( true ) {
              uVar6 = uVar4 + 2;
              sVar8 = *(short *)(uint3)uVar4;
              if (sVar8 == 5) break;
              if (sVar8 == 6) {
                uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
                DPP1 = *(undefined2 *)(uint3)(uVar4 + 4);
                uVar6 = uVar4 + 6;
                uVar4 = uVar4 + 8;
                sVar8 = *(short *)(uint3)uVar6;
                while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
                  *(undefined1 *)(uint3)uVar5 = 0;
                  uVar5 = uVar5 + 1;
                }
                DPP1 = 0x301;
              }
              else {
                if (sVar8 != 7) {
                  DPP0 = 0x300;
                  return;
                }
                DPP1 = (*(ushort *)(uint3)(uVar4 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar6 >> 0xe;
                uVar6 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
                uVar5 = uVar4 + 8;
                sVar8 = *(short *)(uint3)(uVar4 + 6);
                uVar4 = uVar4 + 10;
                sVar9 = *(short *)(uint3)uVar5;
                while ((bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1 ||
                       (bVar1 = sVar9 != 0, sVar9 = sVar9 + -1, bVar1))) {
                  *(undefined1 *)(uint3)uVar6 = 0;
                  bVar1 = uVar6 == 0x7fff;
                  uVar6 = uVar6 + 1;
                  if (bVar1) {
                    uVar6 = 0x4000;
                    sVar3 = DPP1;
                    DPP1 = sVar3 + 1;
                  }
                }
                DPP1 = 0x301;
              }
            }
            uVar5 = uVar4 + 4;
            uVar6 = *(ushort *)(uint3)uVar6;
            uVar4 = uVar4 + 6;
            sVar8 = *(short *)(uint3)uVar5;
            DPP0 = 0x300;
            while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
              *(undefined1 *)(uint3)uVar6 = 0;
              uVar6 = uVar6 + 1;
            }
          } while( true );
        }
        DPP1 = (*(ushort *)(uint3)(uVar4 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar6 >> 0xe;
        uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
        DPP2 = (*(ushort *)(uint3)(uVar4 + 8) & 0xff) << 2 | *(ushort *)(uint3)(uVar4 + 6) >> 0xe;
        uVar6 = *(ushort *)(uint3)(uVar4 + 6) & 0xbfff | 0x8000;
        uVar7 = uVar4 + 0xc;
        sVar8 = *(short *)(uint3)(uVar4 + 10);
        uVar4 = uVar4 + 0xe;
        sVar9 = *(short *)(uint3)uVar7;
        while ((bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1 ||
               (bVar1 = sVar9 != 0, sVar9 = sVar9 + -1, bVar1))) {
          *(undefined1 *)(uint3)uVar5 = *(undefined1 *)(uint3)uVar6;
          bVar1 = uVar5 == 0x7fff;
          uVar5 = uVar5 + 1;
          if (bVar1) {
            uVar5 = 0x4000;
            sVar3 = DPP1;
            DPP1 = sVar3 + 1;
          }
          bVar1 = uVar6 == 0xbfff;
          uVar6 = uVar6 + 1;
          if (bVar1) {
            uVar6 = 0x8000;
            sVar3 = DPP2;
            DPP2 = sVar3 + 1;
          }
        }
        DPP1 = 0x301;
        DPP2 = 0x302;
      }
    }
    uVar6 = *(ushort *)(uint3)uVar6;
    uVar7 = uVar4 + 6;
    uVar5 = *(ushort *)(uint3)(uVar4 + 4);
    uVar4 = uVar4 + 8;
    sVar8 = *(short *)(uint3)uVar7;
    DPP0 = 0x300;
    while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
      puVar2 = (undefined1 *)(uint3)uVar5;
      uVar5 = uVar5 + 1;
      *(undefined1 *)(uint3)uVar6 = *puVar2;
      uVar6 = uVar6 + 1;
    }
  } while( true );
}



/* ===== c00a78 boot_reset size=440 ===== */

/* WARNING: This function may have set the stack pointer */

void boot_reset(void)

{
  ushort uVar1;
  
  WDTCON = 0xcf01;
  ADDRSEL1 = 0x17;
  ADDRSEL2 = 0x8fbb;
  SYSCON1 = 0;
  SYSCON3 = 0;
  DAT_00ffaa = 0;
  uVar1 = DP3;
  DP3 = uVar1 | 0x8000;
  uVar1 = P3;
  P3 = uVar1 | 0x8000;
  DAT_00f0fa = 0x8000;
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



/* ===== c00c30 gap_c00c30 size=6 ===== */

void gap_c00c30(void)

{
  do {
    __idle();
  } while( true );
}



/* ===== c00c36 asc0_init size=78 ===== */

void asc0_init(char param_1)

{
  ushort uVar1;
  
  if (param_1 == '\x02') {
    DAT_00feb6 = 0x1ce;
    S0BG = 0x2e;
  }
  else {
    DAT_00feb6 = 0xcd;
    S0BG = 0x4c;
  }
  S0CON = 0x811;
  DAT_00f0c6 = 0x807;
  DAT_00f0c4 = 0x807;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x400;
  uVar1 = P3;
  P3 = uVar1 & 0xfbff | 0x400;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfbff | 0x400;
  uVar1 = S0TBIC;
  S0TBIC = uVar1 | 0x80;
  uVar1 = S0TIC;
  S0TIC = uVar1 | 0x80;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x8000;
  return;
}



/* ===== c00c84 asc0_tx_byte size=6 ===== */

void asc0_tx_byte(undefined2 param_1)

{
  S0TBUF = param_1;
  return;
}



/* ===== c00c8a asc0_read_rx_clear size=8 ===== */

undefined2 asc0_read_rx_clear(void)

{
  undefined2 uVar1;
  ushort uVar2;
  
  uVar2 = S0RIC;
  S0RIC = uVar2 & 0xff7f;
  uVar1 = Ram00feb2;
  return uVar1;
}



/* ===== c00c92 gap_c00c92 size=14 ===== */

bool gap_c00c92(void)

{
  bool bVar1;
  ushort uVar2;
  
  uVar2 = S0TIC;
  bVar1 = (uVar2 & 0x80) != 0;
  if (bVar1) {
    uVar2 = S0TIC;
    S0TIC = uVar2 & 0xff7f;
  }
  return bVar1;
}



/* ===== c00ca2 capcom_timer_init size=146 ===== */

void capcom_timer_init(char param_1)

{
  ushort uVar1;
  
  T78CON = 0;
  if (param_1 == '\x02') {
    T7 = 0xfbe0;
    T7REL = 0xfbe0;
  }
  else {
    T7 = 0xf060;
    T7REL = 0xf060;
  }
  T8 = 0xffff;
  T8REL = 0;
  T7IC = 0x58;
  CC16 = 0;
  CC17 = 0;
  CC18 = 0;
  CC19 = 0;
  CC20 = 0;
  CC21 = 0;
  CC22 = 0;
  CC23 = 0;
  CC24 = 0;
  CC25 = 0;
  CC26 = 0;
  CC27 = 0;
  CC28 = 0;
  CC29 = 0;
  CC30 = 0;
  CC31 = 0;
  CCM4 = 0;
  CCM5 = 0;
  CCM6 = 0;
  CCM7 = 0;
  DAT_00ff2a = 0;
  DAT_00fe28 = 0;
  DAT_00fe2a = 0;
  DAT_00ff2c = 0;
  uVar1 = T78CON;
  T78CON = uVar1 | 0x40;
  return;
}



/* ===== c00d34 timer7_isr size=118 ===== */

void timer7_isr(void)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  
  DAT_00fc40 = &stack0x0000;
  uVar8 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  DPP0 = 0x300;
  uVar9 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x302;
  uVar16 = DAT_00ffde;
  uVar3 = DAT_00ffde;
  uVar3 = DAT_00ffde;
  uVar10 = DAT_00fe5c;
  uVar3 = DAT_00fe5c;
  uVar3 = DAT_00fe5c;
  uVar11 = DAT_00fe5e;
  uVar3 = DAT_00fe5e;
  uVar3 = DAT_00fe5e;
  uVar15 = DAT_00ffdc;
  uVar3 = DAT_00ffdc;
  uVar3 = DAT_00ffdc;
  uVar14 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar12 = DAT_00ff08;
  uVar3 = DAT_00ff08;
  uVar3 = DAT_00ff08;
  uVar13 = DAT_00ff0a;
  uVar3 = DAT_00ff0a;
  uVar3 = DAT_00ff0a;
  uVar3 = DAT_00f000;
  uVar4 = DAT_00f000;
  uVar4 = DAT_00f000;
  uVar4 = DAT_00f002;
  uVar5 = DAT_00f002;
  uVar5 = DAT_00f002;
  uVar5 = DAT_00f004;
  uVar6 = DAT_00f004;
  uVar6 = DAT_00f004;
  uVar6 = DAT_00f006;
  uVar7 = DAT_00f006;
  uVar7 = DAT_00f006;
  asc0_state_dispatch(uVar6,uVar5,uVar4,uVar3,uVar13,uVar12,uVar14,uVar15,uVar11,uVar10,uVar16,uVar9
                      ,uVar8);
  kwp_dispatch();
  uVar1 = DAT_00c06e;
  sVar2 = DAT_00c06e;
  DAT_00c06e = sVar2 + 1;
  if (1000 < uVar1) {
    DAT_00c06e = 0;
  }
  DAT_00f006 = uVar6;
  uVar6 = DAT_00f006;
  uVar6 = DAT_00f006;
  uVar6 = DAT_00f006;
  DAT_00f004 = uVar5;
  uVar5 = DAT_00f004;
  uVar5 = DAT_00f004;
  uVar5 = DAT_00f004;
  DAT_00f002 = uVar4;
  uVar4 = DAT_00f002;
  uVar4 = DAT_00f002;
  uVar4 = DAT_00f002;
  DAT_00f000 = uVar3;
  uVar3 = DAT_00f000;
  uVar3 = DAT_00f000;
  uVar3 = DAT_00f000;
  DAT_00ff0a = uVar13;
  uVar3 = DAT_00ff0a;
  uVar3 = DAT_00ff0a;
  uVar3 = DAT_00ff0a;
  DAT_00ff08 = uVar12;
  uVar3 = DAT_00ff08;
  uVar3 = DAT_00ff08;
  uVar3 = DAT_00ff08;
  DAT_00ffda = uVar14;
  uVar3 = DAT_00ffda;
  uVar3 = DAT_00ffda;
  uVar3 = DAT_00ffda;
  DAT_00ffdc = uVar15;
  uVar3 = DAT_00ffdc;
  uVar3 = DAT_00ffdc;
  uVar3 = DAT_00ffdc;
  DAT_00fe5e = uVar11;
  uVar3 = DAT_00fe5e;
  uVar3 = DAT_00fe5e;
  uVar3 = DAT_00fe5e;
  DAT_00fe5c = uVar10;
  uVar3 = DAT_00fe5c;
  uVar3 = DAT_00fe5c;
  uVar3 = DAT_00fe5c;
  DAT_00ffde = uVar16;
  uVar3 = DAT_00ffde;
  uVar3 = DAT_00ffde;
  uVar3 = DAT_00ffde;
  DPP2 = uVar9;
  uVar3 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP0 = uVar8;
  uVar3 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  return;
}



/* ===== c00daa gap_c00daa size=4 ===== */

void gap_c00daa(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd00;
  DAT_00fd00 = uVar1 | 0x8000;
  DAT_00c080 = 0xffff;
  DAT_00c092 = 2;
  DAT_00c091 = 0;
  DAT_00c090 = 0;
  DAT_00c08f = 0x1f;
  DAT_00c08e = 0;
  DAT_00c08d = 0;
  DAT_00c08c = 0;
  ssc_start_frame();
  return;
}



/* ===== c00dae boot_port_adc_init size=44 ===== */

void boot_port_adc_init(void)

{
  DAT_00c080 = 0xffff;
  DAT_00c092 = 2;
  DAT_00c091 = 0;
  DAT_00c090 = 0;
  DAT_00c08f = 0x1f;
  DAT_00c08e = 0;
  DAT_00c08d = 0;
  DAT_00c08c = 0;
  ssc_start_frame();
  return;
}



/* ===== c00dda gap_c00dda size=2 ===== */

void gap_c00dda(void)

{
  ushort uVar1;
  
  uVar1 = SSCCON;
  SSCCON = uVar1 & 0x7fff;
  SSCBR = 1;
  uVar1 = P3;
  P3 = uVar1 & 0xdfff;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 | 0x2000;
  SSCCON = 0xc037;
  uVar1 = P3;
  P3 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfeff;
  uVar1 = P3;
  P3 = uVar1 | 0x200;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x200;
  uVar1 = DP3;
  DP3 = uVar1 | 0x200;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x10;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x40;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x80;
  uVar1 = SSCTIC;
  SSCTIC = uVar1 | 0x80;
  return;
}



/* ===== c00ddc asc0_pin_init size=44 ===== */

void asc0_pin_init(void)

{
  ushort uVar1;
  
  uVar1 = SSCCON;
  SSCCON = uVar1 & 0x7fff;
  SSCBR = 1;
  uVar1 = P3;
  P3 = uVar1 & 0xdfff;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 | 0x2000;
  SSCCON = 0xc037;
  uVar1 = P3;
  P3 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfeff;
  uVar1 = P3;
  P3 = uVar1 | 0x200;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x200;
  uVar1 = DP3;
  DP3 = uVar1 | 0x200;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x10;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x40;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0x80;
  uVar1 = SSCTIC;
  SSCTIC = uVar1 | 0x80;
  return;
}



/* ===== c00e08 ssc_send_byte size=12 ===== */

void ssc_send_byte(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = SSCTIC;
  SSCTIC = uVar1 & 0xff7f;
  SSCTB = (ushort)*(byte *)(uint3)param_1;
  return;
}



/* ===== c00e14 ssc0_rx_isr size=182 ===== */

void ssc0_rx_isr(void)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined1 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  undefined2 uVar17;
  undefined2 uVar18;
  byte bVar19;
  
  DAT_00fc60 = &stack0x0000;
  uVar10 = DPP0;
  DPP0 = 0x300;
  uVar11 = DPP2;
  DPP2 = 0x302;
  uVar18 = DAT_00ffde;
  uVar12 = DAT_00fe5c;
  uVar13 = DAT_00fe5e;
  uVar17 = DAT_00ffdc;
  uVar16 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar14 = DAT_00ff08;
  uVar15 = DAT_00ff0a;
  uVar5 = DAT_00f000;
  uVar6 = DAT_00f002;
  uVar7 = DAT_00f004;
  uVar8 = DAT_00f006;
  uVar9 = SSCRB;
  uVar1 = DAT_00c098;
  *(undefined1 *)(uint3)uVar1 = uVar9;
  cVar2 = DAT_00c094;
  DAT_00c094 = cVar2 + -1;
  cVar2 = DAT_00c094;
  if (cVar2 == '\0') {
    uVar1 = P1H;
    P1H = uVar1 | 8;
    bVar19 = 0;
    do {
      uVar1 = (ushort)bVar19;
      bVar19 = bVar19 + 1;
      *(undefined1 *)(uint3)((short)&DAT_00c082 + uVar1) =
           *(undefined1 *)(uint3)((short)&DAT_00c078 + uVar1);
    } while (bVar19 < 7);
    DAT_00c094 = 7;
    DAT_00c096 = 0xc08c;
    DAT_00c098 = 0xc078;
  }
  else {
    sVar3 = DAT_00c096;
    DAT_00c096 = sVar3 + 1;
    sVar4 = DAT_00c098;
    DAT_00c098 = sVar4 + 1;
    ssc_send_byte(sVar3 + 1,uVar8,uVar7,uVar6,uVar5,uVar15,uVar14,uVar16,uVar17,uVar13,uVar12,uVar18
                  ,uVar11,uVar10);
  }
  DAT_00f006 = uVar8;
  uVar8 = DAT_00f006;
  uVar8 = DAT_00f006;
  uVar8 = DAT_00f006;
  DAT_00f004 = uVar7;
  uVar7 = DAT_00f004;
  uVar7 = DAT_00f004;
  uVar7 = DAT_00f004;
  DAT_00f002 = uVar6;
  uVar6 = DAT_00f002;
  uVar6 = DAT_00f002;
  uVar6 = DAT_00f002;
  DAT_00f000 = uVar5;
  uVar5 = DAT_00f000;
  uVar5 = DAT_00f000;
  uVar5 = DAT_00f000;
  DAT_00ff0a = uVar15;
  uVar5 = DAT_00ff0a;
  uVar5 = DAT_00ff0a;
  uVar5 = DAT_00ff0a;
  DAT_00ff08 = uVar14;
  uVar5 = DAT_00ff08;
  uVar5 = DAT_00ff08;
  uVar5 = DAT_00ff08;
  DAT_00ffda = uVar16;
  uVar5 = DAT_00ffda;
  uVar5 = DAT_00ffda;
  uVar5 = DAT_00ffda;
  DAT_00ffdc = uVar17;
  uVar5 = DAT_00ffdc;
  uVar5 = DAT_00ffdc;
  uVar5 = DAT_00ffdc;
  DAT_00fe5e = uVar13;
  uVar5 = DAT_00fe5e;
  uVar5 = DAT_00fe5e;
  uVar5 = DAT_00fe5e;
  DAT_00fe5c = uVar12;
  uVar5 = DAT_00fe5c;
  uVar5 = DAT_00fe5c;
  uVar5 = DAT_00fe5c;
  DAT_00ffde = uVar18;
  uVar5 = DAT_00ffde;
  uVar5 = DAT_00ffde;
  uVar5 = DAT_00ffde;
  DPP2 = uVar11;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar10;
  uVar5 = DPP0;
  uVar5 = DPP0;
  uVar5 = DPP0;
  return;
}



/* ===== c00eca ssc_start_frame size=30 ===== */

void ssc_start_frame(void)

{
  ushort uVar1;
  
  uVar1 = P1H;
  P1H = uVar1 & 0xfff7;
  DAT_00c094 = 7;
  DAT_00c096 = 0xc08c;
  DAT_00c098 = 0xc078;
  ssc_send_byte();
  return;
}



/* ===== c00ee8 boot_extint_init size=36 ===== */

void boot_extint_init(void)

{
  boot_bus_mode();
  EXISEL = 0;
  boot_bus_mode();
  DAT_00f1d8 = 0;
  boot_bus_mode();
  EXICON = 0;
  XP3IC = 0x44;
  return;
}



/* ===== c00f0c trap_stack_overflow size=94 ===== */

void trap_stack_overflow(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  ushort uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  
  DAT_00fc80 = &stack0x0000;
  uVar7 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DPP0 = 0x300;
  uVar8 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP2 = 0x302;
  uVar16 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar9 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar10 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar15 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar14 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar11 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar12 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar6 = PSW;
  PSW = uVar6 & 0xf7ff;
  uVar13 = TFR;
  uVar6 = DAT_00fdfe;
  DAT_00fdfe = uVar6 | uVar13;
  uVar6 = TFR;
  TFR = uVar6 & 0xbfff;
  __software_reset();
  DAT_00f006 = uVar4;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  DAT_00f004 = uVar3;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  DAT_00f002 = uVar2;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  DAT_00f000 = uVar1;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  DAT_00ff0a = uVar12;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  DAT_00ff08 = uVar11;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  DAT_00ffda = uVar14;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  DAT_00ffdc = uVar15;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  DAT_00fe5e = uVar10;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  DAT_00fe5c = uVar9;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  DAT_00ffde = uVar16;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  DPP2 = uVar8;
  uVar1 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP0 = uVar7;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c00f6a trap_stack_underflow size=94 ===== */

void trap_stack_underflow(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  ushort uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  
  DAT_00fc80 = &stack0x0000;
  uVar7 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DPP0 = 0x300;
  uVar8 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP2 = 0x302;
  uVar16 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar9 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar10 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar15 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar14 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar11 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar12 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar6 = PSW;
  PSW = uVar6 & 0xf7ff;
  uVar13 = TFR;
  uVar6 = DAT_00fdfe;
  DAT_00fdfe = uVar6 | uVar13;
  uVar6 = TFR;
  TFR = uVar6 & 0xdfff;
  __software_reset();
  DAT_00f006 = uVar4;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  DAT_00f004 = uVar3;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  DAT_00f002 = uVar2;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  DAT_00f000 = uVar1;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  DAT_00ff0a = uVar12;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  DAT_00ff08 = uVar11;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  DAT_00ffda = uVar14;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  DAT_00ffdc = uVar15;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  DAT_00fe5e = uVar10;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  DAT_00fe5c = uVar9;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  DAT_00ffde = uVar16;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  DPP2 = uVar8;
  uVar1 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP0 = uVar7;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c00fc8 trap_bootstrap size=128 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trap_bootstrap(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  ushort uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  
  DAT_00fc80 = &stack0x0000;
  uVar7 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DPP0 = 0x300;
  uVar8 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP2 = 0x302;
  uVar16 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar9 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar10 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar15 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar14 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar11 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar12 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar6 = PSW;
  PSW = uVar6 & 0xf7ff;
  uVar13 = TFR;
  uVar6 = DAT_00fdfe;
  DAT_00fdfe = uVar6 | uVar13;
  uVar6 = TFR;
  if ((uVar6 & 0x80) != 0) {
    uVar6 = TFR;
    TFR = uVar6 & 0xff7f;
  }
  uVar6 = TFR;
  if ((uVar6 & 0x10) != 0) {
    uVar6 = TFR;
    TFR = uVar6 & 0xffef;
    _DAT_fffdfc = _DAT_fffdfc | _DAT_fff000;
  }
  uVar6 = TFR;
  if ((uVar6 & 8) != 0) {
    uVar6 = TFR;
    TFR = uVar6 & 0xfff7;
  }
  uVar6 = TFR;
  if ((uVar6 & 4) != 0) {
    uVar6 = TFR;
    TFR = uVar6 & 0xfffb;
  }
  __software_reset();
  DAT_00f006 = uVar4;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  DAT_00f004 = uVar3;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  DAT_00f002 = uVar2;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  DAT_00f000 = uVar1;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  DAT_00ff0a = uVar12;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  DAT_00ff08 = uVar11;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  DAT_00ffda = uVar14;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  DAT_00ffdc = uVar15;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  DAT_00fe5e = uVar10;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  DAT_00fe5c = uVar9;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  DAT_00ffde = uVar16;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  DPP2 = uVar8;
  uVar1 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP0 = uVar7;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c01048 pll_isr size=56 ===== */

void pll_isr(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  
  uVar12 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar6 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar7 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar11 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar10 = DAT_00ffda;
  DAT_00ffda = 0;
  uVar8 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar9 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f000;
  uVar2 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f002;
  uVar3 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f004;
  uVar4 = DAT_00f006;
  uVar5 = DAT_00f006;
  uVar5 = DAT_00f006;
  __software_reset();
  DAT_00f006 = uVar4;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  uVar4 = DAT_00f006;
  DAT_00f004 = uVar3;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  uVar3 = DAT_00f004;
  DAT_00f002 = uVar2;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  uVar2 = DAT_00f002;
  DAT_00f000 = uVar1;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  uVar1 = DAT_00f000;
  DAT_00ff0a = uVar9;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  uVar1 = DAT_00ff0a;
  DAT_00ff08 = uVar8;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  uVar1 = DAT_00ff08;
  DAT_00ffda = uVar10;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  uVar1 = DAT_00ffda;
  DAT_00ffdc = uVar11;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  uVar1 = DAT_00ffdc;
  DAT_00fe5e = uVar7;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  uVar1 = DAT_00fe5e;
  DAT_00fe5c = uVar6;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  uVar1 = DAT_00fe5c;
  DAT_00ffde = uVar12;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  uVar1 = DAT_00ffde;
  return;
}



/* ===== c01080 clock_init size=176 ===== */

void clock_init(void)

{
  ushort uVar1;
  
  PICON = 0;
  P0H = 0;
  POCON0H = 0;
  DP0H = 0;
  P0L = 0;
  POCON0L = 0;
  DP0L = 0;
  P1H = 8;
  DAT_00f120 = 0;
  POCON1H = 0;
  DP1H = 0x2e;
  P1L = 0;
  DAT_00f130 = 0;
  POCON1L = 0;
  DP1L = 0x71;
  uVar1 = DP1L;
  DP1L = uVar1 | 10;
  uVar1 = DP1L;
  DP1L = uVar1 | 0x40;
  ODP3 = 0;
  P3 = 0;
  DAT_00f126 = 0;
  DAT_00f128 = 0;
  POCON3 = 0;
  DP3 = 0x2240;
  ODP4 = 0;
  P4 = 0;
  DAT_00f12a = 0;
  DAT_00f136 = 0;
  POCON4 = 0;
  DP4 = 0;
  BUSCON4 = 0;
  BUSCON2 = 0;
  DAT_00f138 = 0;
  DAT_00f13a = 3;
  DAT_00f094 = 0;
  BUSCON3 = 0x10;
  DAT_00ffb4 = 0;
  POCON20 = 0;
  DAT_00ffb6 = 0;
  return;
}



/* ===== c01130 gap_c01130 size=12 ===== */

/* WARNING: Control flow encountered bad instruction data */

void gap_c01130(void)

{
  undefined2 in_r1;
  short in_r3;
  
  *(undefined2 *)(uint3)(in_r3 - 2) = in_r1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ===== c01144 asc0_state_dispatch size=26 ===== */

void asc0_state_dispatch(void)

{
  byte bVar1;
  
  bVar1 = DAT_00c0af;
  if (5 < bVar1) {
    DAT_00c0af = 0;
    return;
  }
                    /* WARNING: Could not emulate address calculation at 0xc01154 */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((ushort)bVar1 * 2 + 0x428) | 0xc00000))();
  return;
}



/* ===== c01158 asc0_task0 size=6 ===== */

void asc0_task0(void)

{
  asc0_state0();
  return;
}



/* ===== c0115e asc0_task1 size=6 ===== */

void asc0_task1(void)

{
  asc0_state1();
  return;
}



/* ===== c01164 asc0_task2 size=6 ===== */

void asc0_task2(void)

{
  asc0_state2();
  return;
}



/* ===== c0116a asc0_task3 size=6 ===== */

void asc0_task3(void)

{
  asc0_state3();
  return;
}



/* ===== c01170 asc0_task4 size=6 ===== */

void asc0_task4(void)

{
  asc0_state4();
  return;
}



/* ===== c01176 asc0_task5 size=6 ===== */

void asc0_task5(void)

{
  asc0_state5();
  return;
}



/* ===== c01182 asc0_clear_state size=6 ===== */

void asc0_clear_state(void)

{
  DAT_00c13e = 0;
  return;
}



/* ===== c01188 asc0_state0 size=22 ===== */

void asc0_state0(void)

{
  ushort uVar1;
  
  DAT_00c0af = 1;
  DAT_00c0b0 = 0;
  asc0_clear_state();
  DAT_00c13a = 0;
  uVar1 = S0CON;
  S0CON = uVar1 & 0xffef;
  return;
}



/* ===== c0119e asc0_state1 size=56 ===== */

void asc0_state1(void)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = P3;
  if ((uVar2 & 0x800) == 0) {
    sVar1 = DAT_00c0b0;
    DAT_00c0b0 = sVar1 + 1;
    return;
  }
  uVar2 = DAT_00c0b0;
  if ((0x14 < uVar2) && (uVar2 < 0x1c)) {
    DAT_00c0af = 2;
    DAT_00c0ae = 0;
    uVar2 = DAT_00f0c6;
    DAT_00f0c6 = uVar2 & 0xfffd | 2;
    uVar2 = S0CON;
    S0CON = uVar2 | 0x10;
  }
  DAT_00c0b0 = 0;
  return;
}



/* ===== c011d6 asc0_state2 size=2 ===== */

void asc0_state2(void)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  
  while (uVar1 = S0RIC, (uVar1 & 0x80) != 0) {
    uVar4 = asc0_read_rx_clear();
    bVar2 = DAT_00c0ae;
    uVar1 = (short)&DAT_00c144 + (ushort)bVar2;
    *(undefined1 *)(uint3)uVar1 = uVar4;
    if (*(char *)(uint3)uVar1 == *(char *)(uint3)((short)&UNK_00c0a3 + (ushort)bVar2)) {
      cVar3 = DAT_00c0ae;
      if (cVar3 == '\x04') {
        cVar3 = DAT_00c0af;
        DAT_00c0af = cVar3 + '\x01';
        DAT_00c1d1 = 1;
      }
      else {
        cVar3 = DAT_00c0ae;
        DAT_00c0ae = cVar3 + '\x01';
      }
    }
    else {
      DAT_00c0af = 1;
    }
  }
  return;
}



/* ===== c01212 kline_receive_pattern size=64 ===== */

void kline_receive_pattern(void)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  
  while (uVar1 = S0RIC, (uVar1 & 0x80) != 0) {
    uVar4 = asc0_read_rx_clear();
    bVar2 = DAT_00c0ae;
    uVar1 = (short)&DAT_00c144 + (ushort)bVar2;
    *(undefined1 *)(uint3)uVar1 = uVar4;
    if (*(char *)(uint3)uVar1 == *(char *)(uint3)((short)&UNK_00c0a3 + (ushort)bVar2)) {
      cVar3 = DAT_00c0ae;
      if (cVar3 == '\x04') {
        cVar3 = DAT_00c0af;
        DAT_00c0af = cVar3 + '\x01';
        DAT_00c1d1 = 1;
      }
      else {
        cVar3 = DAT_00c0ae;
        DAT_00c0ae = cVar3 + '\x01';
      }
    }
    else {
      DAT_00c0af = 1;
    }
  }
  return;
}



/* ===== c01218 asc0_state2_init size=58 ===== */

void asc0_state2_init(char param_1)

{
  ushort uVar1;
  
  asc0_clear_state();
  if (param_1 == '\x02') {
    DAT_00c09e = 0x5e;
    DAT_00c0a0 = 0x49fb;
    DAT_00c0a2 = 0x79;
  }
  DAT_00c0af = 3;
  DAT_00c1d0 = 0;
  DAT_00c09a = 1;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x10;
  return;
}



/* ===== c01252 asc0_state3 size=148 ===== */

/* WARNING: Control flow encountered bad instruction data */

void asc0_state3(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  ushort uVar7;
  byte bVar8;
  
  cVar1 = DAT_00c1d0;
  if (cVar1 == '\0') {
    DAT_00c140 = 0;
    DAT_00c1d0 = 1;
    goto LAB_c012ba;
  }
  if (cVar1 != '\x01') {
    DAT_00c1d0 = 0;
    goto LAB_c012ba;
  }
  uVar4 = S0RIC;
  if ((uVar4 & 0x80) == 0) {
    cVar1 = DAT_00c13c;
    if (cVar1 == '\x01') {
      bVar8 = DAT_00c140;
      bVar2 = DAT_00c09e;
      bVar3 = DAT_00c09e;
      if (bVar8 != bVar3 && bVar2 <= bVar8) {
        DAT_00c0af = 5;
        goto LAB_c01292;
      }
    }
    cVar1 = DAT_00c13c;
    if ((cVar1 == '\0') && (cVar1 = DAT_00c09b, cVar1 == '\x01')) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else {
    DAT_00c0af = 4;
LAB_c01292:
    DAT_00c1d0 = 0;
  }
  cVar1 = DAT_00c140;
  DAT_00c140 = cVar1 + '\x01';
LAB_c012ba:
  sVar6 = DAT_00c13e;
  DAT_00c13e = sVar6 + 1;
  uVar7 = DAT_00c13e;
  uVar4 = DAT_00c0a0;
  uVar5 = DAT_00c0a0;
  if (uVar7 != uVar5 && uVar4 <= uVar7) {
    DAT_00c13e = 0;
    DAT_00c0af = 2;
    DAT_00c0ae = 0;
    uVar4 = DAT_00f0c6;
    DAT_00f0c6 = uVar4 & 0xfffd | 2;
    uVar4 = S0CON;
    S0CON = uVar4 | 0x10;
  }
  return;
}



/* ===== c012e6 asc0_state4 size=258 ===== */

void asc0_state4(void)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  byte bVar5;
  undefined1 uVar6;
  ushort uVar7;
  
  cVar3 = DAT_00c1d0;
  if (cVar3 == '\0') {
    DAT_00c0ae = 0;
    DAT_00c147 = 4;
    DAT_00c1d0 = 1;
    DAT_00c09c = 0;
  }
  else if (cVar3 != '\x01') {
    if (cVar3 == '\x02') {
      while (uVar7 = S0RIC, (uVar7 & 0x80) != 0) {
        bVar5 = DAT_00c147;
        bVar2 = DAT_00c0ae;
        if (bVar5 + 4 < (ushort)bVar2) break;
        uVar6 = asc0_read_rx_clear(0);
        bVar2 = DAT_00c0ae;
        *(undefined1 *)(uint3)((short)&DAT_00c144 + (ushort)bVar2) = uVar6;
        cVar3 = DAT_00c0ae;
        DAT_00c0ae = cVar3 + '\x01';
        DAT_00c09c = 0;
      }
      sVar1 = DAT_00c09c;
      DAT_00c09c = sVar1 + 1;
      bVar2 = DAT_00c147;
      DAT_00c142 = bVar2 + 4;
      bVar2 = DAT_00c0ae;
      uVar7 = DAT_00c142;
      uVar4 = DAT_00c142;
      if (bVar2 == uVar4 || bVar2 < uVar7) {
        bVar2 = DAT_00c0a2;
        uVar7 = DAT_00c09c;
        if (bVar2 < uVar7) {
          DAT_00c0af = 3;
          DAT_00c1d0 = 0;
          DAT_00c144 = 0;
        }
      }
      else {
        for (uVar7 = 0; uVar4 = DAT_00c142, uVar7 < uVar4; uVar7 = uVar7 + 1) {
        }
        DAT_00c0af = 3;
        DAT_00c1d0 = 0;
        DAT_00c1d1 = 1;
      }
    }
    else {
      DAT_00c1d0 = 0;
    }
    goto LAB_c013e2;
  }
  while ((uVar7 = S0RIC, (uVar7 & 0x80) != 0 && (bVar2 = DAT_00c0ae, bVar2 < 3))) {
    uVar6 = asc0_read_rx_clear();
    bVar2 = DAT_00c0ae;
    uVar7 = (short)&DAT_00c144 + (ushort)bVar2;
    *(undefined1 *)(uint3)uVar7 = uVar6;
    bVar2 = DAT_00c0ae;
    if ((ushort)*(byte *)(uint3)uVar7 != *(ushort *)(uint3)((short)&DAT_00c0a8 + (ushort)bVar2 * 2))
    {
      DAT_00c0af = 3;
      DAT_00c1d0 = 0;
    }
    cVar3 = DAT_00c0ae;
    DAT_00c0ae = cVar3 + '\x01';
  }
  cVar3 = DAT_00c0ae;
  if (cVar3 == '\x03') {
    DAT_00c1d0 = 2;
  }
LAB_c013e2:
  sVar1 = DAT_00c13e;
  DAT_00c13e = sVar1 + 1;
  return;
}



/* ===== c013e8 asc0_state5 size=154 ===== */

void asc0_state5(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  char cVar6;
  char cVar7;
  ushort uVar8;
  
  cVar7 = '\0';
  cVar6 = DAT_00c1d0;
  if (cVar6 == '\0') {
    DAT_00c138 = 0;
    DAT_00c0b2 = 0x80;
    DAT_00c0b3 = 0xf1;
    DAT_00c0b4 = 0x11;
    bVar1 = DAT_00c0b5;
    DAT_00c142 = bVar1 + 4;
    for (uVar8 = 0; uVar4 = DAT_00c142, uVar8 < uVar4; uVar8 = uVar8 + 1) {
      cVar7 = cVar7 + *(char *)(uint3)((short)&DAT_00c0b2 + uVar8);
    }
    sVar2 = DAT_00c142;
    *(char *)(uint3)(ushort)((short)&DAT_00c0b2 + sVar2) = cVar7;
    DAT_00c1d0 = 1;
    uVar8 = S0CON;
    S0CON = uVar8 & 0xffef;
  }
  else if (cVar6 == '\x01') {
    sVar2 = DAT_00c138;
    sVar3 = DAT_00c138;
    DAT_00c138 = sVar3 + 1;
    asc0_tx_byte(*(undefined1 *)(uint3)(ushort)((short)&DAT_00c0b2 + sVar2));
    uVar8 = DAT_00c138;
    uVar4 = DAT_00c142;
    uVar5 = DAT_00c142;
    if (uVar8 != uVar5 && uVar4 <= uVar8) {
      DAT_00c1d0 = 2;
    }
  }
  else {
    if (cVar6 == '\x02') {
      uVar8 = S0CON;
      S0CON = uVar8 | 0x10;
      DAT_00c0af = 3;
      DAT_00c13c = 0;
    }
    DAT_00c1d0 = 0;
  }
  cVar7 = DAT_00c140;
  DAT_00c140 = cVar7 + '\x01';
  DAT_00c13e = 0;
  return;
}



/* ===== c01482 kwp_dispatch size=154 ===== */

void kwp_dispatch(void)

{
  char cVar1;
  
  cVar1 = DAT_00c1d1;
  if (cVar1 == '\x01') {
    cVar1 = DAT_00c147;
    if (cVar1 == -0x7f) {
      kwp_sid81();
    }
    else {
      cVar1 = DAT_00c148;
      if (cVar1 == '\x10') {
        kwp_sid10_session();
      }
      else if (cVar1 == -0x7d) {
        kwp_sid83();
      }
      else if (cVar1 == '#') {
        kwp_sid23_read_mem();
      }
      else if (cVar1 == '\'') {
        kwp_sid27_security();
      }
      else if (cVar1 == '1') {
        kwp_sid31_routine();
      }
      else if (cVar1 == '4') {
        kwp_sid34_download();
      }
      else if (cVar1 == '6') {
        kwp_sid36_transfer();
      }
      else if (cVar1 == '8') {
        kwp_sid38();
      }
      else if (cVar1 == '=') {
        kwp_sid3D_write_mem();
      }
      else {
        kwp_negative();
      }
    }
    DAT_00c1d1 = 0;
    DAT_00c13c = 1;
  }
  return;
}



/* ===== c0151c kwp_sid81 size=40 ===== */

void kwp_sid81(void)

{
  DAT_00c0b2 = 0x80;
  DAT_00c0b5 = 3;
  DAT_00c0b6 = 0xc1;
  DAT_00c0b7 = 0xef;
  DAT_00c0b8 = 0x8f;
  return;
}



/* ===== c01544 kwp_sid27_security size=150 ===== */

void kwp_sid27_security(void)

{
  char cVar1;
  
  cVar1 = DAT_00c149;
  if (cVar1 == '\x01') {
    DAT_00c0b2 = 0x80;
    DAT_00c0b5 = 4;
    DAT_00c0b6 = 0x67;
    DAT_00c0b7 = 1;
    DAT_00c0b8 = 0x12;
    DAT_00c0b9 = 0x34;
    return;
  }
  if (cVar1 == '\x02') {
    DAT_00c0b5 = 3;
    DAT_00c0b2 = 0x80;
    cVar1 = DAT_00c14a;
    if ((cVar1 == -0x7c) && (cVar1 = DAT_00c14b, cVar1 == 't')) {
      DAT_00c09a = 1;
      DAT_00c0b6 = 0x67;
      DAT_00c0b7 = 2;
      DAT_00c0b8 = 0x34;
      return;
    }
    DAT_00c0b6 = 0x7f;
    DAT_00c0b7 = 0x27;
    DAT_00c0b8 = 0x35;
  }
  return;
}



/* ===== c015da kwp_negative size=30 ===== */

void kwp_negative(void)

{
  DAT_00c0b5 = 3;
  DAT_00c0b6 = 0x7f;
  DAT_00c0b7 = 0x10;
  DAT_00c0b8 = 1;
  return;
}



/* ===== c015f8 kwp_sid10_session size=114 ===== */

void kwp_sid10_session(void)

{
  char cVar1;
  
  cVar1 = DAT_00c149;
  if (cVar1 == -0x7f) {
    DAT_00c0b5 = 2;
    DAT_00c0b6 = 0x50;
    DAT_00c0b7 = 0x81;
  }
  else if (cVar1 == -0x7b) {
    cVar1 = DAT_00c09a;
    if (cVar1 == '\x01') {
      DAT_00c0b5 = 2;
      DAT_00c0b6 = 0x50;
      DAT_00c0b7 = 0x85;
    }
    else {
      DAT_00c0b5 = 3;
      DAT_00c0b6 = 0x7f;
      DAT_00c0b7 = 0x10;
      DAT_00c0b8 = 0x85;
    }
  }
  DAT_00c0b2 = 0x80;
  return;
}



/* ===== c0166a kwp_sid83 size=88 ===== */

void kwp_sid83(void)

{
  char cVar1;
  
  cVar1 = DAT_00c149;
  if (cVar1 == '\0') {
    DAT_00c0b2 = 0x87;
    DAT_00c0b5 = 7;
    DAT_00c0b6 = 0xc3;
    DAT_00c0b7 = 0;
    DAT_00c0b8 = 0;
    DAT_00c0b9 = 0xff;
    DAT_00c0ba = 0;
    DAT_00c0bb = 0xff;
    DAT_00c0bc = 0;
  }
  else if (cVar1 == '\x03') {
    DAT_00c0b2 = 0x82;
    DAT_00c0b5 = 2;
    DAT_00c0b6 = 0xc3;
    DAT_00c0b7 = 3;
    return;
  }
  return;
}



/* ===== c016c2 kwp_sid34_download size=72 ===== */

void kwp_sid34_download(void)

{
  char cVar1;
  
  cVar1 = DAT_00c09a;
  if (cVar1 != '\x01') {
    DAT_00c0b5 = 3;
    DAT_00c0b6 = 0x7f;
    DAT_00c0b7 = 0x10;
    DAT_00c0b8 = 0x33;
    return;
  }
  DAT_00c0b2 = 0x82;
  DAT_00c0b5 = 2;
  DAT_00c0b6 = 0x74;
  DAT_00c0b7 = 0xfb;
  return;
}



/* ===== c0170a kwp_sid36_transfer size=158 ===== */

ushort kwp_sid36_transfer(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  ushort uVar8;
  ushort uVar9;
  
  cVar7 = DAT_00c09a;
  if (cVar7 == '\x01') {
    bVar4 = DAT_00c149;
    bVar5 = DAT_00c14a;
    uVar3 = (ushort)bVar5 * 0x100;
    bVar6 = DAT_00c14b;
    uVar1 = uVar3 + bVar6;
    cVar7 = '\0';
    uVar8 = 0;
    uVar9 = uVar1 & 0x3fff;
    do {
      uVar2 = (short)&DAT_00c14c + uVar8;
      *(undefined1 *)(uint3)(uVar9 & 0x3fff) = *(undefined1 *)(uint3)uVar2;
      cVar7 = cVar7 + *(char *)(uint3)(uVar2 & 0x3fff);
      uVar8 = uVar8 + 1;
      uVar9 = uVar9 + 1;
    } while (uVar8 < 0x80);
    DAT_00c0b5 = 2;
    DAT_00c0b6 = 0x76;
    DAT_00c0b7 = cVar7;
    return (((ushort)bVar4 * 0x100 + (ushort)bVar5 >> 8) + (ushort)CARRY2(uVar3,(ushort)bVar6)) * 4
           | uVar1 >> 0xe;
  }
  DAT_00c0b5 = 3;
  DAT_00c0b6 = 0x7f;
  DAT_00c0b7 = 0x36;
  DAT_00c0b8 = 0xbd;
  return 0xbd;
}



/* ===== c017a8 kwp_sid31_routine size=66 ===== */

void kwp_sid31_routine(void)

{
  char cVar1;
  
  cVar1 = DAT_00c09a;
  if (cVar1 != '\x01') {
    DAT_00c0b5 = 3;
    DAT_00c0b6 = 0x7f;
    DAT_00c0b7 = 0x31;
    DAT_00c0b8 = 0xbd;
    return;
  }
  DAT_00c09b = 1;
  DAT_00c0b5 = 2;
  DAT_00c0b6 = 0x71;
  DAT_00c0b7 = 2;
  return;
}



/* ===== c017ea kwp_sid38 size=86 ===== */

void kwp_sid38(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = DAT_00c09a;
  if (cVar1 != '\x01') {
    DAT_00c0b5 = 3;
    DAT_00c0b6 = 0x7f;
    DAT_00c0b7 = 0x31;
    DAT_00c0b8 = 0xbd;
    return;
  }
  DAT_00c09b = 1;
  DAT_00c0b5 = 4;
  DAT_00c0b6 = 0x78;
  uVar2 = DAT_00c149;
  DAT_00c0b7 = uVar2;
  uVar2 = DAT_00c14a;
  DAT_00c0b8 = uVar2;
  uVar2 = DAT_00c14b;
  DAT_00c0b9 = uVar2;
  return;
}



/* ===== c01840 kwp_sid23_read_mem size=204 ===== */

short kwp_sid23_read_mem(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  short sVar7;
  ushort uVar8;
  ushort uVar9;
  
  bVar6 = DAT_00c14c;
  uVar2 = (ushort)bVar6;
  bVar4 = DAT_00c149;
  bVar5 = DAT_00c14a;
  uVar3 = (ushort)bVar5;
  bVar5 = DAT_00c14b;
  uVar8 = uVar3 * 0x100 + (ushort)bVar5;
  uVar3 = ((ushort)CARRY2((ushort)bVar4 * 0x100,uVar3) * 0x100 | (ushort)bVar4 * 0x100 + uVar3 >> 8)
          + (ushort)CARRY2(uVar3 * 0x100,(ushort)bVar5);
  uVar9 = uVar8 & 0x3fff;
  sVar7 = (short)&T2CON + uVar3;
  if ((((0xbf < uVar3) &&
       (sVar7 = 0, uVar1 = uVar3 + CARRY2(uVar8,uVar2),
       uVar1 == 0xc4 && uVar8 + uVar2 == 0 || uVar1 < 0xc4)) ||
      ((0xdf < uVar3 &&
       (uVar1 = uVar8 + uVar2, uVar3 = uVar3 + CARRY2(uVar8,uVar2),
       (short)&T78CON + uVar3 == (ushort)(uVar1 < 0x1800) && uVar1 == 0x1800 ||
       (uVar3 < 0xe0 || uVar3 == 0xe0 && uVar1 < 0x1800))))) && (uVar2 < 0x81)) {
    for (uVar8 = 1; uVar8 <= uVar2; uVar8 = uVar8 + 1) {
      uVar3 = uVar9 & 0x3fff;
      uVar9 = uVar9 + 1;
      *(undefined1 *)(uint3)(uVar8 + 0xb6 & 0x3fff) = *(undefined1 *)(uint3)uVar3;
    }
    DAT_00c0b5 = bVar6 + 1;
    DAT_00c0b6 = 99;
    return sVar7;
  }
  DAT_00c0b5 = 3;
  DAT_00c0b6 = 0x7f;
  DAT_00c0b7 = 0x23;
  DAT_00c0b8 = 0x12;
  return CONCAT11((char)((ushort)sVar7 >> 8),0x12);
}



/* ===== c0190c kwp_sid3D_write_mem size=200 ===== */

void kwp_sid3D_write_mem(void)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  ushort uVar6;
  ushort uVar7;
  
  bVar3 = DAT_00c14c;
  uVar2 = (ushort)bVar3;
  bVar3 = DAT_00c149;
  bVar5 = DAT_00c14a;
  uVar6 = (ushort)bVar5;
  bVar5 = DAT_00c14b;
  uVar7 = uVar6 * 0x100 + (ushort)bVar5;
  uVar6 = ((ushort)CARRY2((ushort)bVar3 * 0x100,uVar6) * 0x100 | (ushort)bVar3 * 0x100 + uVar6 >> 8)
          + (ushort)CARRY2(uVar6 * 0x100,(ushort)bVar5);
  if (((0xdf < uVar6) &&
      (uVar1 = uVar7 + uVar2, uVar6 = uVar6 + CARRY2(uVar7,uVar2),
      (short)&T78CON + uVar6 == (ushort)(uVar1 < 0x1800) && uVar1 == 0x1800 ||
      (uVar6 < 0xe0 || uVar6 == 0xe0 && uVar1 < 0x1800))) && (uVar2 < 0x81)) {
    uVar7 = uVar7 & 0x3fff;
    for (uVar6 = 1; uVar6 <= uVar2; uVar6 = uVar6 + 1) {
      *(undefined1 *)(uint3)(uVar7 & 0x3fff) = *(undefined1 *)(uint3)((short)&DAT_00c14c + uVar6);
      uVar7 = uVar7 + 1;
    }
    DAT_00c0b5 = 4;
    DAT_00c0b6 = 0x7d;
    uVar4 = DAT_00c149;
    DAT_00c0b7 = uVar4;
    uVar4 = DAT_00c14a;
    DAT_00c0b8 = uVar4;
    uVar4 = DAT_00c14b;
    DAT_00c0b9 = uVar4;
    return;
  }
  DAT_00c0b5 = 3;
  DAT_00c0b6 = 0x7f;
  DAT_00c0b7 = 0x3d;
  DAT_00c0b8 = 0x12;
  return;
}



/* ===== c019d4 gap_c019d4 size=2 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c019d4(void)

{
  _DAT_20044a = 0x1fb8;
  _DAT_200450 = 0x5599;
  _DAT_20044c = 0xffff;
  _DAT_20042a = 0x1fbc;
  _DAT_200430 = 0x5599;
  _DAT_20042c = 0xffff;
  _DAT_20042e = 0xffff;
  return;
}



/* ===== c019d6 can_diag_object_init size=70 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can_diag_object_init(void)

{
  _DAT_20044a = 0x1fb8;
  _DAT_200450 = 0x5599;
  _DAT_20044c = 0xffff;
  _DAT_20042a = 0x1fbc;
  _DAT_200430 = 0x5599;
  _DAT_20042c = 0xffff;
  _DAT_20042e = 0xffff;
  return;
}



/* ===== c01a1c can_rx_process size=184 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can_rx_process(void)

{
  short sVar1;
  byte bVar2;
  
  if ((_DAT_200284 & 0x400) == 0) {
    if ((_DAT_200284 & 0x200) == 0) {
      DAT_00c1d2 = 0;
    }
    else if (((_DAT_200430 & 2) != 0) && (((byte)(_DAT_200430 >> 8) & 3) == 2)) {
      DAT_00c1d2 = 9;
    }
  }
  else if (((_DAT_200450 & 2) != 0) && (((byte)(_DAT_200450 >> 8) & 3) == 2)) {
    DAT_00c1d2 = 10;
  }
  __service_watchdog();
  sVar1 = DAT_00c1d2;
  if (sVar1 != 0) {
    bVar2 = 0;
    do {
      sVar1 = DAT_00c1d2;
      *(undefined1 *)(uint3)(bVar2 + 0x3740 & 0x3fff) =
           *(undefined1 *)(uint3)((ushort)bVar2 + sVar1 * 0x20 + 0x300 & 0x3fff);
      bVar2 = bVar2 + 1;
    } while (bVar2 < 8);
    can_rx_dispatch(3);
    _DAT_200450 = 0x5599;
    _DAT_200430 = 0x5599;
  }
  return;
}



/* ===== c01ad4 can_bootloader_wait size=78 ===== */

void can_bootloader_wait(void)

{
  undefined4 uVar1;
  undefined1 auStack_8 [4];
  undefined1 local_4 [4];
  
  can_diag_object_init();
  uVar1 = seg_to_ptr(local_4,4);
  uVar1 = seg_to_ptr((short)uVar1,(short)((uint)uVar1 >> 0x10),auStack_8);
  memcpy_wdt((short)uVar1,(short)((uint)uVar1 >> 0x10));
  __service_watchdog();
  ret_stub();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== c01b22 can_rx_dispatch size=194 ===== */

void can_rx_dispatch(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined1 uVar6;
  
  sVar1 = DAT_00c1d2;
  if (sVar1 == 10) {
    bVar3 = DAT_00f744;
    DAT_00c1d4 = (ushort)bVar3;
    DAT_00c1d4 = (ushort)bVar3 << 8;
    bVar3 = DAT_00f745;
    uVar2 = DAT_00c1d4;
    DAT_00c1d4 = uVar2 | bVar3;
    bVar3 = DAT_00f740;
    DAT_00c1d8 = (ushort)bVar3;
    DAT_00c1da = 0;
    uVar4 = DAT_00f741;
    DAT_00c1d8 = CONCAT11(bVar3,uVar4);
    DAT_00c1da = 0;
    bVar5 = DAT_00f742;
    DAT_00c1d8 = CONCAT11(bVar3,uVar4) << 8 | (ushort)bVar5;
    DAT_00c1da = (ushort)bVar3;
    uVar6 = DAT_00f743;
    DAT_00c1d8 = CONCAT11(bVar5,uVar6);
    DAT_00c1da = CONCAT11(bVar3,uVar4);
    DAT_00c1dc = CONCAT11(bVar5,uVar6);
    DAT_00c1de = CONCAT11(bVar3,uVar4);
    can_rx_cmd();
  }
  sVar1 = DAT_00c1d2;
  if (sVar1 == 9) {
    can_isotp_send();
  }
  return;
}



/* ===== c01be4 can_rx_cmd size=138 ===== */

void can_rx_cmd(void)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined2 uVar4;
  char cVar5;
  ushort uVar6;
  undefined4 uVar7;
  
  cVar5 = DAT_00f746;
  if (cVar5 == -1) {
    can_tx_confirm();
    while (sVar1 = DAT_00c1d4, sVar1 != 0) {
      uVar6 = DAT_00c1d4;
      if (uVar6 < 9) {
        uVar6 = DAT_00c1d4;
      }
      else {
        uVar6 = 8;
      }
      uVar7 = seg_to_ptr((short)&UNK_00f750,uVar6);
      uVar2 = DAT_00c1dc;
      uVar4 = DAT_00c1de;
      memcpy_wdt((short)uVar7,(short)((uint)uVar7 >> 0x10),uVar2,uVar4);
      can_tx_frame(uVar6);
      sVar1 = DAT_00c1d4;
      DAT_00c1d4 = sVar1 - uVar6;
      uVar3 = DAT_00c1dc;
      DAT_00c1dc = uVar3 + uVar6;
      sVar1 = DAT_00c1de;
      DAT_00c1de = sVar1 + (ushort)CARRY2(uVar3,uVar6);
      __service_watchdog();
    }
  }
  else {
    cVar5 = DAT_00f746;
    if ((cVar5 == '\0') && (sVar1 = DAT_00c1d4, sVar1 != 0)) {
      DAT_00c1d6 = 1;
      can_tx_confirm();
    }
  }
  return;
}



/* ===== c01c6e can_isotp_send size=90 ===== */

void can_isotp_send(void)

{
  short sVar1;
  char cVar2;
  undefined2 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined4 uVar7;
  
  cVar2 = DAT_00c1d6;
  if ((cVar2 != '\0') && (uVar6 = DAT_00c1d4, uVar6 != 0)) {
    if (uVar6 < 9) {
      uVar6 = DAT_00c1d4;
    }
    else {
      uVar6 = 8;
    }
    uVar3 = DAT_00c1dc;
    uVar5 = DAT_00c1de;
    uVar7 = seg_to_ptr(uVar3,uVar5,(short)&DAT_00f740,uVar6);
    memcpy_wdt((short)uVar7,(short)((uint)uVar7 >> 0x10));
    sVar1 = DAT_00c1d4;
    DAT_00c1d4 = sVar1 - uVar6;
    uVar4 = DAT_00c1dc;
    DAT_00c1dc = uVar4 + uVar6;
    sVar1 = DAT_00c1de;
    DAT_00c1de = sVar1 + (ushort)CARRY2(uVar4,uVar6);
    sVar1 = DAT_00c1d4;
    if (sVar1 == 0) {
      DAT_00c1d6 = 0;
    }
  }
  return;
}



/* ===== c01cc8 can_tx_frame size=210 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can_tx_frame(ushort param_1)

{
  ushort uVar1;
  
  do {
  } while (((byte)((ushort)_DAT_200430 >> 0xc) & 3) == 2);
  _DAT_000430 = _DAT_000430 & 0xf0ff | 0x200;
  if (param_1 < 8) {
    _DAT_000434 = _DAT_000434 & 0xff0f | (param_1 & 0xf) << 4;
  }
  else {
    _DAT_000434 = _DAT_000434 & 0xff7f | 0xf0;
  }
  uVar1 = 0;
  do {
    *(undefined1 *)(uint3)(uVar1 + 0x420 & 0x3fff) = *(undefined1 *)(uint3)(uVar1 + 0x3750 & 0x3fff)
    ;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  _DAT_000430 = _DAT_000430 & 0xc3ff | 0x2400;
  do {
  } while (((byte)((ushort)_DAT_200430 >> 0xc) & 3) == 2);
  return;
}



/* ===== c01d9a memcpy_wdt size=40 ===== */

void memcpy_wdt(ushort param_1,ushort param_2,ushort unaff_00000000)

{
  ushort uVar1;
  
  for (uVar1 = 0; uVar1 < unaff_00000000; uVar1 = uVar1 + 1) {
    *(undefined1 *)(uint3)param_1 = *(undefined1 *)(uint3)param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    __service_watchdog();
  }
  return;
}



/* ===== c01dc2 gap_c01dc2 size=42 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c01dc2(void)

{
  uRam000450 = uRam000450 & 0xfcff | 0x100;
  _DAT_000430 = _DAT_000430 & 0xfcff | 0x100;
  return;
}



/* ===== c01dec can_tx_confirm size=212 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void can_tx_confirm(void)

{
  if (DAT_0001d6 == '\0') {
    _DAT_000434 = _DAT_000434 & 0xfff7 | 8;
    _DAT_000430 = _DAT_000430 & 0xbd | 0x59c0;
  }
  else {
    _DAT_000434 = _DAT_000434 & 0xfff7;
    _DAT_000430 = _DAT_000430 & 0xbd | 0x55c0;
  }
  _DAT_000430 = _DAT_000430 & 0xff7f | 0xc0;
  return;
}



/* ===== c01ec0 gap_c01ec0 size=8 ===== */

void gap_c01ec0(void)

{
  __atomic(3);
  return;
}



/* ===== c01ec8 ret_stub size=6 ===== */

void ret_stub(void)

{
  return;
}



/* ===== c01ece mem_read_word size=14 ===== */

short mem_read_word(void)

{
  ushort in_r4;
  short in_r5;
  
  return in_r5 + (ushort)(0xfffd < in_r4);
}



/* ===== c01edc mem_write_word size=14 ===== */

short mem_write_word(void)

{
  ushort in_r4;
  short in_r5;
  undefined2 in_r10;
  undefined2 in_r11;
  
  *(undefined2 *)(uint3)in_r4 = in_r10;
  *(undefined2 *)(uint3)(in_r4 + 2) = in_r11;
  return in_r5 + (ushort)(0xfffd < in_r4);
}



/* ===== c01eea seg_to_ptr size=22 ===== */

undefined4 seg_to_ptr(void)

{
  ushort uVar1;
  ushort in_r4;
  
  uVar1 = *(ushort *)(uint3)((in_r4 >> 0xe) * 2 - 0x200);
  return CONCAT22(uVar1 >> 2,in_r4 & 0x3fff | (uVar1 & 1) << 0xe | ((uVar1 & 2) >> 1) << 0xf);
}



/* ===== c01f00 gap_c01f00 size=34 ===== */
/* DECOMPILE FAILED: Exception while decompiling c01f00: process: timeout
 */


/* ===== c02000 boot_hidden_main size=192 ===== */

void boot_hidden_main(void)

{
  ushort uVar1;
  undefined4 uVar2;
  
  LAB_e00000 = 0xff;
  DAT_00f800 = 0;
  uVar1 = P1H;
  P1H = uVar1 & 0xfffb | 4;
  boot_hidden_periph();
  uVar1 = P1H;
  P1H = uVar1 & 0xfff7 | 8;
  boot_hidden_xram_init();
  boot_hidden_xram2();
  boot_hidden_xram3();
  uVar1 = P5;
  if ((uVar1 & 0x800) != 0) {
    uVar2 = boot_hidden_store32(4,0x4000,0xc0);
    uVar2 = boot_hidden_store32((short)uVar2,(short)((uint)uVar2 >> 0x10));
    boot_hidden_memcpy((short)uVar2,(short)((uint)uVar2 >> 0x10));
    boot_hidden_delay();
  }
  do {
    if (LAB_e00000 != 0xff) {
      if (LAB_e00000 < 0x1a) {
        boot_hidden_delay();
      }
      LAB_e00000 = 0xff;
    }
    __service_watchdog();
  } while( true );
}



/* ===== c020c0 gap_c020c0 size=4 ===== */

void gap_c020c0(void)

{
  undefined4 uVar1;
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  uVar1 = boot_hidden_store32(auStack_4,4);
  uVar1 = boot_hidden_store32((short)uVar1,(short)((uint)uVar1 >> 0x10),auStack_8);
  boot_hidden_memcpy((short)uVar1,(short)((uint)uVar1 >> 0x10));
  boot_hidden_delay();
  return;
}



/* ===== c020c4 boot_hidden_copy size=70 ===== */

void boot_hidden_copy(void)

{
  undefined4 uVar1;
  
  uVar1 = boot_hidden_store32(&stack0x0004,4);
  uVar1 = boot_hidden_store32((short)uVar1,(short)((uint)uVar1 >> 0x10),&stack0x0000);
  boot_hidden_memcpy((short)uVar1,(short)((uint)uVar1 >> 0x10));
  boot_hidden_delay();
  return;
}



/* ===== c0210a boot_hidden_memcpy size=40 ===== */

void boot_hidden_memcpy(ushort param_1,ushort param_2,byte unaff_00000000)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < unaff_00000000; bVar1 = bVar1 + 1) {
    *(undefined1 *)(uint3)param_1 = *(undefined1 *)(uint3)param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    __service_watchdog();
  }
  return;
}



/* ===== c02132 gap_c02132 size=14 ===== */

void gap_c02132(void)

{
  uRame00020 = 0xdd;
  return;
}



/* ===== c02140 boot_hidden_periph size=158 ===== */

void boot_hidden_periph(void)

{
  undefined2 uVar1;
  ushort uVar2;
  
  PICON = 0x80;
  POCON1L = 0x4444;
  POCON1H = 0x4444;
  DAT_00f120 = 0;
  DP1L = 0xfb;
  DP1H = 0x2f;
  uVar2 = P3;
  P3 = uVar2 & 0xdfff;
  uVar1 = DAT_00f126;
  uVar2 = DAT_00f126;
  DAT_00f126 = uVar2 | 0x2200;
  uVar1 = DAT_00f128;
  uVar1 = ODP3;
  uVar2 = DP3;
  DP3 = uVar2 | 0xa240;
  uVar2 = P3;
  P3 = uVar2 | 0xa200;
  uVar2 = P5DIDIS;
  P5DIDIS = uVar2 | 0x80ff;
  DAT_00f138 = 8;
  DAT_00f13a = 8;
  uVar1 = BUSCON4;
  uVar2 = BUSCON3;
  BUSCON3 = uVar2 | 0x1b;
  uVar2 = P1H;
  P1H = uVar2 & 0xfffb | 4;
  return;
}



/* ===== c021de gap_c021de size=114 ===== */

void gap_c021de(void)

{
  ushort uVar1;
  
  uVar1 = T78CON;
  T78CON = uVar1 & 0xfffa | 7;
  uVar1 = T78CON;
  T78CON = uVar1 & 0xfff7;
  uVar1 = T78CON;
  T78CON = uVar1 & 0xffbf;
  DAT_00ff2a = 0x5555;
  DAT_00f066 = 4;
  T7 = 0;
  T7REL = 0;
  uVar1 = CCM5;
  CCM5 = uVar1 & 0xffdf | 0x70;
  uVar1 = CCM5;
  CCM5 = uVar1 & 0xff7f;
  uVar1 = CCM6;
  CCM6 = uVar1 & 0xfffd | 7;
  uVar1 = CCM6;
  CCM6 = uVar1 & 0xfff7;
  T7IC = 0;
  return;
}



/* ===== c02250 boot_hidden_xram_init size=172 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void boot_hidden_xram_init(void)

{
  ushort uVar1;
  
  _DAT_00e892 = 0xf423;
  _DAT_00e8b2 = 0xf423;
  _DAT_00e8ac = 0x909;
  _DAT_00e8ae = 0x20;
  _DAT_00e8a0 = 0x5780;
  _DAT_00e8a2 = 0x4b00;
  _DAT_00e8a4 = 0x6a40;
  _DAT_00e8b6 = 0x28a0;
  _DAT_00e894 = 1;
  _DAT_00e8c6 = 0x10;
  _DAT_00e8a8 = 0;
  _DAT_00e8c4 = 0;
  _DAT_00e8c0 = 4;
  _DAT_00e8ca = 0;
  _DAT_00e8a6 = 0x40;
  _DAT_00e8ce = 0;
  _DAT_00e8c2 = 0;
  uVar1 = DAT_00f130;
  DAT_00f130 = uVar1 & 0xfffb | 4;
  uVar1 = P1L;
  P1L = uVar1 & 0xfffb | 4;
  uVar1 = DP1L;
  DP1L = uVar1 & 0xfffb | 4;
  uVar1 = P1L;
  P1L = uVar1 & 0xffef;
  uVar1 = DP1L;
  DP1L = uVar1 & 0xffef | 0x10;
  return;
}



/* ===== c022fc boot_hidden_xram2 size=34 ===== */

void boot_hidden_xram2(void)

{
  T2CON = 6;
  T2 = 0;
  T3CON = 2;
  T3 = 0;
  T4CON = 1;
  T4 = 0;
  return;
}



/* ===== c0231e boot_hidden_xram3 size=24 ===== */

void boot_hidden_xram3(void)

{
  SSCCON = 0;
  SSCBR = 1;
  SSCCON = 0xc037;
  return;
}



/* ===== c02430 gap_c02430 size=30 ===== */

void gap_c02430(void)

{
  ushort uVar1;
  
  func_0xc02386();
  uVar1 = P1H;
  P1H = uVar1 & 0xffdf | 0x20;
  uRame00020 = uRame00001;
  return;
}



/* ===== c0248a boot_hidden_task size=212 ===== */

void boot_hidden_task(void)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  ushort uVar4;
  
  uVar4 = 0x20;
  cVar1 = DAT_00f800;
  if (cVar1 == -1) {
    uVar4 = 0x22;
  }
  ADCIC = 0;
  uVar2 = ADCON;
  ADCON = uVar2 & 0xff7f;
  DAT_00ffbe = 0;
  DAT_00f09c = 0;
  uVar2 = ADCIC;
  ADCIC = uVar2 & 0xff7f;
  bVar3 = 0;
  do {
    if ((bVar3 < 7) || (0xe < bVar3)) {
      uVar2 = ADCON;
      ADCON = uVar2 & 0xfff0 | bVar3 & 0xf;
      uVar2 = ADCON;
      ADCON = uVar2 & 0xff7f | 0x80;
      while (uVar2 = ADCIC, (uVar2 & 0x80) == 0) {
        __service_watchdog();
      }
      uVar2 = ADCON;
      ADCON = uVar2 & 0xff7f;
      uVar2 = ADCIC;
      ADCIC = uVar2 & 0xff7f;
      uVar2 = ADDAT;
      *(ushort *)(uint3)uVar4 = uVar2 & 0x3ff;
      uVar4 = uVar4 + 2;
    }
    __service_watchdog();
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0x10);
  uVar4 = ADCON;
  if ((uVar4 & 0x100) != 0) {
    uVar4 = ADCON;
    ADCON = uVar4 & 0xff7f;
  }
  return;
}



/* ===== c02a46 gap_c02a46 size=130 ===== */

void gap_c02a46(void)

{
  byte bVar1;
  byte bVar2;
  undefined2 *puVar3;
  ushort uVar4;
  
  bVar1 = bRame00001;
  if ((bRame00001 & 1) != 0) {
    bVar1 = bRame00001 + 1;
  }
  puVar3 = (undefined2 *)CONCAT11(uRame00003,uRame00004);
  uVar4 = (ushort)&UNK_00c700;
  for (bVar2 = 0; bVar2 < bVar1 >> 1; bVar2 = bVar2 + 1) {
    *(undefined2 *)(uint3)uVar4 = *puVar3;
    __service_watchdog();
    puVar3 = puVar3 + 1;
    uVar4 = uVar4 + 2;
  }
  return;
}



/* ===== c02ac8 gap_c02ac8 size=174 ===== */

ushort gap_c02ac8(void)

{
  byte bVar1;
  byte bVar2;
  ushort in_r5;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  
  bVar1 = bRame00001;
  uRame00020 = 0;
  uVar4 = CONCAT11(uRame00003,uRame00004);
  uVar3 = uVar4;
  uVar5 = 5;
  for (bVar2 = 0; bVar2 < bVar1; bVar2 = bVar2 + 1) {
    *(undefined1 *)(uint3)uVar3 = *(undefined1 *)(uint3)uVar5;
    in_r5 = uVar3;
    uVar3 = uVar3 + 1;
    uVar5 = uVar5 + 1;
  }
  bVar2 = 0;
  uVar3 = 5;
  uVar5 = 0xe0;
  while( true ) {
    if (bVar1 <= bVar2) {
      return in_r5;
    }
    if (*(char *)(uint3)uVar4 != *(char *)(uint3)uVar3) break;
    bVar2 = bVar2 + 1;
    in_r5 = uVar5;
    uVar4 = uVar4 + 1;
    uVar3 = uVar3 + 1;
    uVar5 = uVar5 + (0xfffe < uVar3);
  }
  uRame00020 = 0xff;
  return uVar5;
}



/* ===== c02b76 boot_hidden_eeprom size=36 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort boot_hidden_eeprom(void)

{
  while ((_DAT_fff000 & 1) != 0) {
    __service_watchdog();
  }
  return _DAT_fff000;
}



/* ===== c02ddc gap_c02ddc size=366 ===== */

void gap_c02ddc(void)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  ushort uStack_6;
  ushort uStack_4;
  
  uVar3 = CONCAT11(uRame00003,uRame00004);
  uVar1 = CONCAT11(uRame00006,uRame00007) - uVar3;
  sVar5 = (((ushort)bRame00005 - (ushort)bRame00002) -
          (ushort)(CONCAT11(uRame00006,uRame00007) < uVar3)) + (ushort)(0xfffe < uVar1);
  uStack_6 = 0xffff;
  uStack_4 = 0xffff;
  for (sVar4 = uVar1 + 1; sVar4 != 0 || sVar5 != 0; sVar4 = sVar4 + -1) {
    uStack_6 = uStack_6 ^ *(byte *)(uint3)uVar3;
    bVar2 = 0;
    do {
      if ((uStack_6 & 1) == 0) {
        uStack_6 = uStack_6 >> 1 | uStack_4 << 0xf;
        uStack_4 = uStack_4 >> 1;
      }
      else {
        uStack_6 = (uStack_6 >> 1 | uStack_4 << 0xf) ^ 0x8320;
        uStack_4 = uStack_4 >> 1 ^ 0xedb8;
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < 8);
    sVar5 = sVar5 - (ushort)(sVar4 == 0);
    uVar3 = uVar3 + 1;
  }
  func_0xc02f4a(&uStack_6);
  uRame00020 = (char)(uStack_4 >> 8);
  uRame00021 = (char)uStack_4;
  uRame00022 = (char)((ushort)*(undefined2 *)((uint3)((ushort)&uStack_6 & 0x3fff) + 0xe00000) >> 8);
  uRame00023 = (char)*(undefined2 *)((uint3)((ushort)&uStack_6 & 0x3fff) + 0xe00000);
  return;
}



/* ===== c03a04 gap_c03a04 size=18 ===== */

void gap_c03a04(void)

{
  ushort uVar1;
  
  uVar1 = P1L;
  P1L = uVar1 & 0xfffe | 1;
  __service_watchdog();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== c03a16 gap_c03a16 size=36 ===== */

void gap_c03a16(void)

{
  DAT_000020 = 3;
  uRam000021 = 0x50;
  return;
}



/* ===== c03a3a gap_c03a3a size=290 ===== */

void gap_c03a3a(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  byte bVar4;
  
  bVar4 = bRame00002;
  if (0x41 < bRame00002) {
    bVar4 = 0x41;
  }
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf;
  T3 = 0;
  if (cRame00001 == '\x01') {
    uVar3 = P1L;
    P1L = uVar3 & 0xfffd | 2;
    uVar3 = P1L;
    P1L = uVar3 & 0xfff7;
    uVar3 = P1H;
    P1H = uVar3 & 0xfffe;
  }
  else {
    if (cRame00001 == '\x02') {
      uVar3 = P1L;
      P1L = uVar3 & 0xfffd;
      uVar3 = P1L;
      P1L = uVar3 & 0xfff7 | 8;
    }
    else {
      if (cRame00001 != '\x03') goto LAB_c03ad2;
      uVar3 = P1L;
      P1L = uVar3 & 0xfffd | 2;
    }
    uVar3 = P1H;
    P1H = uVar3 & 0xfffe | 1;
  }
LAB_c03ad2:
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf | 0x40;
  sVar1 = T3;
  uVar3 = P1L;
  P1L = uVar3 & 0xff7f | 0x80;
  while (sVar2 = T3, (ushort)(sVar2 - sVar1) < (ushort)bVar4 * 1000) {
    __service_watchdog();
  }
  uVar3 = P5;
  if ((uVar3 & 0x1000) == 0) {
    uRame00020 = 0;
  }
  else {
    uRame00020 = 0xff;
  }
  uVar3 = P1L;
  P1L = uVar3 & 0xff7f;
  uVar3 = P1H;
  P1H = uVar3 & 0xfffe;
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf;
  uVar3 = P1L;
  P1L = uVar3 & 0xfffd;
  uVar3 = P1L;
  P1L = uVar3 & 0xfff7;
  return;
}



/* ===== c03b5c gap_c03b5c size=230 ===== */

void gap_c03b5c(void)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  
  uVar3 = P1H;
  P1H = uVar3 & 0xfffb | 4;
  ADCIC = 0;
  uVar3 = ADCON;
  ADCON = uVar3 & 0xff7f;
  DAT_00ffbe = 0;
  DAT_00f09c = 0;
  uVar3 = ADCIC;
  ADCIC = uVar3 & 0xff7f;
  uVar3 = ADCON;
  ADCON = uVar3 & 0xfffd | 0xf;
  do {
    uVar3 = ADCON;
    ADCON = uVar3 & 0xff7f | 0x80;
    while (uVar3 = ADCIC, (uVar3 & 0x80) == 0) {
      __service_watchdog();
    }
    uVar3 = ADCON;
    ADCON = uVar3 & 0xff7f;
    uVar3 = ADCON;
    if ((uVar3 & 0x100) != 0) {
      uVar3 = ADCON;
      ADCON = uVar3 & 0xff7f;
    }
    uVar3 = ADCIC;
    ADCIC = uVar3 & 0xff7f;
    uVar3 = ADDAT;
  } while (0xf < (uVar3 & 0x3ff));
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf;
  uVar3 = T3CON;
  T3CON = uVar3 & 0xfffa | 7;
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf | 0x40;
  sVar1 = T3;
  while (sVar2 = T3, (ushort)(sVar2 - sVar1) < 0x186a) {
    __service_watchdog();
  }
  uVar3 = T3CON;
  T3CON = uVar3 & 0xffbf;
  uVar3 = P1H;
  P1H = uVar3 & 0xfffb;
  return;
}



/* ===== c03cb8 boot_hidden_i2c_a size=24 ===== */

undefined4 boot_hidden_i2c_a(void)

{
  ushort in_r4;
  short in_r5;
  ushort in_r10;
  short in_r11;
  
  return CONCAT22(in_r5 * in_r10 + in_r4 * in_r11 + (short)((uint)in_r4 * (uint)in_r10 >> 0x10),
                  (short)((uint)in_r4 * (uint)in_r10));
}



/* ===== c03cd0 boot_hidden_i2c_b size=130 ===== */

uint boot_hidden_i2c_b(void)

{
  uint uVar1;
  int iVar2;
  short sVar4;
  ushort in_r2;
  short sVar5;
  ushort in_r4;
  ushort uVar6;
  ushort in_r5;
  ushort uVar7;
  ushort in_r10;
  ushort in_r11;
  ushort uVar8;
  ushort uVar3;
  
  if (in_r11 != 0) {
    sVar5 = LZCOUNT(in_r11);
    if (sVar5 == 0) {
      uVar7 = 0;
      uVar6 = in_r5;
      uVar8 = in_r11;
    }
    else {
      sVar4 = -sVar5;
      uVar7 = in_r5 >> sVar4;
      uVar6 = in_r4 >> sVar4 | in_r5 << sVar5;
      uVar8 = in_r11 << sVar5 | in_r10 >> sVar4;
    }
    uVar1 = CONCAT22(uVar7,uVar6) / (uint)uVar8;
    uVar6 = (ushort)uVar1;
    iVar2 = (uVar1 & 0xffff) * (uint)in_r10;
    uVar8 = (ushort)iVar2;
    uVar3 = (ushort)((uint)iVar2 >> 0x10);
    uVar7 = uVar6 * in_r11 + uVar3;
    if ((CARRY2(uVar6 * in_r11,uVar3)) ||
       ((uVar7 - in_r2 != (ushort)(uVar8 < in_r5) || uVar8 != in_r5) &&
        (in_r2 <= uVar7 && (uVar7 != in_r2 || uVar8 >= in_r5)))) {
      uVar6 = uVar6 - 1;
    }
    return (uint)uVar6;
  }
  return CONCAT22(in_r5 / in_r10,(short)(CONCAT22(in_r5 % in_r10,in_r4) / (uint)in_r10));
}



/* ===== c03dd4 gap_c03dd4 size=8 ===== */

void gap_c03dd4(void)

{
  __atomic(3);
  return;
}



/* ===== c03ddc boot_hidden_delay size=6 ===== */

void boot_hidden_delay(void)

{
  return;
}



/* ===== c03de2 boot_hidden_store32 size=22 ===== */

undefined4 boot_hidden_store32(void)

{
  ushort uVar1;
  ushort in_r4;
  
  uVar1 = *(ushort *)(uint3)((in_r4 >> 0xe) * 2 - 0x200);
  return CONCAT22(uVar1 >> 2,in_r4 & 0x3fff | (uVar1 & 1) << 0xe | ((uVar1 & 2) >> 1) << 0xf);
}



/* ===== c03df8 gap_c03df8 size=92 ===== */

/* WARNING: Control flow encountered bad instruction data */

short gap_c03df8(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  short sVar5;
  short in_r2;
  ushort uVar6;
  ushort uVar7;
  ushort in_r4;
  ushort uVar8;
  short sVar9;
  ushort in_r5;
  ushort in_r10;
  short in_r11;
  ushort in_PSW;
  ushort uVar4;
  
  sVar9 = (in_r2 - in_r4) - (ushort)((byte)(in_PSW >> 1) & 1);
  uVar8 = Ram00fd48;
  Ram00fd48 = uVar8 & 0xffef;
  uVar8 = Ram00fd48;
  if ((uVar8 & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  sVar5 = -sVar9;
  uVar2 = CONCAT22(in_r5 >> sVar5,in_r4 >> sVar5 | in_r5 << sVar9) /
          (uint)(in_r11 << sVar9 | in_r10 >> sVar5);
  uVar7 = (short)uVar2 * sRam000000;
  iVar3 = (uVar2 & 0xffff) * (uint)uRam000002;
  uVar6 = (ushort)iVar3;
  uVar4 = (ushort)((uint)iVar3 >> 0x10);
  uVar8 = uVar7 + uVar4;
  if (CARRY2(uVar7,uVar4)) {
    bVar1 = uVar6 < uRam000002;
    uVar6 = uVar6 - uRam000002;
    uVar8 = (uVar8 - sRam000000) - (ushort)bVar1;
  }
  uVar7 = uVar6 - uRam000006;
  sVar9 = (uVar8 - uRam000008) - (ushort)(uVar6 < uRam000006);
  if ((sVar9 != 0 || uVar7 != 0) &&
      (uRam000008 <= uVar8 && (uVar8 != uRam000008 || uVar6 >= uRam000006))) {
    bVar1 = uVar7 < uRam000002;
    uVar7 = uVar7 - uRam000002;
    sVar9 = (sVar9 - sRam000000) - (ushort)bVar1;
  }
  return -(ushort)(uVar7 != 0) - sVar9;
}



/* ===== c0ba9e set_can_flag size=22 ===== */

void set_can_flag(void)

{
  ushort uVar1;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  DAT_00c210 = 0xbab4;
  DAT_00c212 = 0xc0;
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}



/* ===== c0bab4 FUN_c0bab4 size=30 ===== */

void FUN_c0bab4(void)

{
  ushort uVar1;
  byte bVar2;
  
  FUN_c1ac7c();
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  DAT_00c1fa = 0;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xdfff;
  return;
}



/* ===== c0bb54 gap_c0bb54 size=112 ===== */

void gap_c0bb54(byte param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  short sVar1;
  char cVar2;
  ushort uVar3;
  
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x1fc;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003b54;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + CONCAT11(uRam000003,sRam000001._1_1_);
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x3a0;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003d9e;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + CONCAT11((undefined1)sRam000004,uRam000003);
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x492;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003fd8;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + sRam000001;
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x4cc;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003fda;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + sRam000001;
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x506;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003fdc;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + CONCAT11(uRam000003,sRam000001._1_1_);
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x546;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003fde;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + sRam000004;
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x550;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003ff2;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + CONCAT11(uRam000003,sRam000001._1_1_);
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x5fe;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003ffa;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + sRam000004;
  sVar1 = DPP0;
  DPP0 = sVar1 + 0x3d1e;
  cVar2 = DPP0._0_1_;
  DPP0._0_1_ = cVar2 + cRam003ffe;
  sVar1 = Ram00fe06;
  Ram00fe06 = sVar1 + CONCAT11(uRam000003,sRam000001._1_1_);
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  sVar1 = (ushort)param_1 * 0x12;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c412 + sVar1) = param_2;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c414 + sVar1) = param_3;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c410 + sVar1) = param_4;
  DAT_00c40c = *(undefined2 *)((short)&stack0x0000 * 4);
  DAT_00c400 = ((undefined2 *)((short)&stack0x0000 * 4))[1];
  event_schedule(param_1);
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  return;
}



/* ===== c0bbc4 capcom_event_config2 size=50 ===== */

void capcom_event_config2
               (byte param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 unaff_00000000,undefined2 unaff_00000002)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  sVar1 = (ushort)param_1 * 0x12;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c412 + sVar1) = param_2;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c414 + sVar1) = param_3;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c410 + sVar1) = param_4;
  DAT_00c40c = unaff_00000000;
  DAT_00c400 = unaff_00000002;
  event_schedule(param_1);
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return;
}



/* ===== c0bc44 FUN_c0bc44 size=48 ===== */

void FUN_c0bc44(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  DAT_00fa60 = &stack0x0000;
  uVar1 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x303;
  FUN_c0df4c(0,uVar2,uVar1);
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c0bc74 FUN_c0bc74 size=48 ===== */

void FUN_c0bc74(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  DAT_00fa60 = &stack0x0000;
  uVar1 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x303;
  FUN_c0df4c(1,uVar2,uVar1);
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c0bca4 capcom_event_config size=176 ===== */

void capcom_event_config(ushort param_1,byte param_2,short param_3)

{
  ushort *puVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  
  uVar4 = PSW;
  PSW = uVar4 & 0xf7ff;
  if (param_3 != 0) {
    DAT_00c40e = 1;
  }
  sVar2 = (param_1 & 0xff) * 0x12;
  sVar3 = (param_1 & 0xff) * 8;
  puVar1 = (ushort *)((short)&DAT_00c394 + sVar3);
  *(byte *)(uint3)(ushort)((short)&UNK_00c41d + sVar2) = param_2;
  *(undefined2 *)(uint3)*puVar1 = *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar1);
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c41e + sVar2) =
       *(undefined2 *)(uint3)(ushort)((short)&DAT_00c392 + sVar3);
  DAT_00c3fe = 0xfe28;
  DAT_00c404 = 0xfe2a;
  DAT_00c40a = 0xff2c;
  DAT_00c402 = 0xff22;
  puVar1 = (ushort *)((short)&DAT_00c396 + sVar3);
  DAT_00c3fc = 0xf050;
  *(undefined2 *)(uint3)(ushort)((short)&UNK_00c420 + sVar2) = *(undefined2 *)ZEXT23(puVar1);
  *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) =
       *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) | 0x30 | param_1 & 0xff;
  uVar4 = DAT_00c3fe;
  *(ushort *)(uint3)uVar4 = *(ushort *)(uint3)uVar4 | 1 << (param_2 & 0xf);
  event_cancel(param_1 & 0xff,param_1);
  *(ushort *)(uint3)*puVar1 = *(ushort *)(uint3)*(ushort *)ZEXT23(puVar1) | 0x40;
  uVar4 = PSW;
  PSW = uVar4 | 0x800;
  return;
}



/* ===== c0bd54 p1l1_set size=4 ===== */

void p1l1_set(void)

{
  ushort uVar1;
  
  uVar1 = P1L;
  P1L = uVar1 | 2;
  return;
}



/* ===== c0bd58 capcom16_17_init size=70 ===== */

void capcom16_17_init(void)

{
  ushort uVar1;
  
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 1;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 2;
  DAT_00c390 = 0x10;
  DAT_00c392 = 0xfe60;
  DAT_00c394 = 0xff22;
  DAT_00c396 = 0xf160;
  DAT_00c398 = 0x11;
  DAT_00c39a = 0xfe62;
  DAT_00c39c = 0xff22;
  DAT_00c39e = 0xf162;
  return;
}



/* ===== c0bd9e gap_c0bd9e size=4 ===== */

void gap_c0bd9e(void)

{
  ushort uVar1;
  
  if (DAT_c05080 == '\x01') {
    T4CON = 5;
    T4 = 0xff83;
    uVar1 = T4IC;
    T4IC = uVar1 | 0x61;
    uVar1 = DAT_00f138;
    DAT_00f138 = uVar1 & 0xfffd;
    uVar1 = DAT_00f13a;
    DAT_00f13a = uVar1 & 0xfffd;
    uVar1 = T4CON;
    T4CON = uVar1 | 0x40;
    DAT_00c3a4 = 0;
  }
  return;
}



/* ===== c0bda2 timer4_init size=38 ===== */

void timer4_init(void)

{
  ushort uVar1;
  
  if (DAT_c05080 == '\x01') {
    T4CON = 5;
    T4 = 0xff83;
    uVar1 = T4IC;
    T4IC = uVar1 | 0x61;
    uVar1 = DAT_00f138;
    DAT_00f138 = uVar1 & 0xfffd;
    uVar1 = DAT_00f13a;
    DAT_00f13a = uVar1 & 0xfffd;
    uVar1 = T4CON;
    T4CON = uVar1 | 0x40;
    DAT_00c3a4 = 0;
  }
  return;
}



/* ===== c0bdc8 FUN_c0bdc8 size=126 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c0bdc8(void)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  ushort uVar7;
  ushort uVar8;
  
  DAT_00fa80 = &stack0x0000;
  uVar4 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  DPP2 = 0x303;
  T4 = 0xff83;
  sVar1 = DAT_00cb60;
  if (sVar1 == DAT_c07d76) {
    DAT_00c3a0 = 1;
  }
  sVar1 = DAT_00c3a0;
  if (sVar1 == 1) {
    DAT_00c3a4 = 0;
  }
  else {
    cVar2 = DAT_00c3a2;
    DAT_00c3a2 = cVar2 + '\x01';
    bVar3 = DAT_00c3a2;
    if (100 < bVar3) {
      DAT_00c3a2 = 0;
      FUN_c14824(uVar5,uVar4);
    }
    bVar3 = DAT_00c3a2;
    if ((ushort)bVar3 < (ushort)(_DAT_e008ca * 2)) {
      uVar6 = BUSCON2;
      uVar7 = BUSCON2;
      uVar8 = BUSCON2;
      BUSCON2 = uVar8 & 0xfffd | ((uVar7 & 2) >> 1 ^ 1) << 1;
      goto LAB_c0be38;
    }
  }
  uVar7 = BUSCON2;
  BUSCON2 = uVar7 & 0xfffd;
LAB_c0be38:
  DPP2 = uVar5;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar4;
  uVar4 = DPP0;
  uVar4 = DPP0;
  uVar4 = DPP0;
  return;
}



/* ===== c0be46 cc22_23_output_disable size=18 ===== */

void cc22_23_output_disable(short param_1)

{
  ushort uVar1;
  
  if (param_1 != 0) {
    uVar1 = CCM5;
    CCM5 = uVar1 & 0xf8ff;
    return;
  }
  uVar1 = CCM5;
  CCM5 = uVar1 & 0x8fff;
  return;
}



/* ===== c0be58 gap_c0be58 size=18 ===== */

void gap_c0be58(short param_1)

{
  ushort uVar1;
  
  if (param_1 != 0) {
    uVar1 = CCM5;
    CCM5 = uVar1 & 0xf8ff | 0x500;
    return;
  }
  uVar1 = CCM5;
  CCM5 = uVar1 & 0x8fff | 0x5000;
  return;
}



/* ===== c0be6a cc22_23_schedule size=134 ===== */

void cc22_23_schedule(short param_1,short param_2)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  
  sVar3 = t7_timestamp();
  if (((ushort)(param_2 - sVar3) < 3) || (0x1fff < (ushort)(param_2 - sVar3))) {
    sVar1 = T7;
    if (param_1 == 0) {
      __atomic(2);
      CC23 = sVar1 + 7;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x80;
    }
    else {
      __atomic(2);
      CC22 = sVar1 + 7;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x40;
    }
    *(short *)(uint3)(ushort)((short)&DAT_00c3d2 + param_1 * 0x1a) = sVar3;
  }
  else {
    if (param_1 == 0) {
      __atomic(2);
      CC23 = param_2 << 3;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x80;
    }
    else {
      __atomic(2);
      CC22 = param_2 << 3;
      uVar2 = DAT_00fe2a;
      DAT_00fe2a = uVar2 | 0x40;
    }
    *(short *)(uint3)(ushort)((short)&DAT_00c3d2 + param_1 * 0x1a) = param_2;
  }
  return;
}



/* ===== c0bef0 cc_control_ptr_init size=18 ===== */

void cc_control_ptr_init(void)

{
  DAT_00c3c4 = 0xff2c;
  DAT_00c3c2 = 0xfe2a;
  return;
}



/* ===== c0bf02 cc22_23_output_init size=62 ===== */

void cc22_23_output_init(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fe28;
  DAT_00fe28 = uVar1 | 0xc0;
  uVar1 = CCM5;
  CCM5 = uVar1 | 0x5500;
  uVar1 = DAT_00f130;
  DAT_00f130 = uVar1 | 0x80;
  uVar1 = DAT_00f120;
  DAT_00f120 = uVar1 | 1;
  uVar1 = DP1L;
  DP1L = uVar1 | 0x80;
  uVar1 = DP1H;
  DP1H = uVar1 | 1;
  uVar1 = CC22IC;
  CC22IC = uVar1 | 0x34;
  uVar1 = CC23IC;
  CC23IC = uVar1 | 0x35;
  DAT_00c3c6 = 0xfe6e;
  DAT_00c3e0 = 0xfe6c;
  DAT_00c3c8 = 0xf16e;
  DAT_00c3e2 = 0xf16c;
  return;
}



/* ===== c0bf40 timer6_init size=20 ===== */

void timer6_init(void)

{
  ushort uVar1;
  
  T6CON = 0x800a;
  T6 = 0xffff;
  CAPREL = 0xffff;
  uVar1 = T6IC;
  T6IC = uVar1 | 0x7a;
  uVar1 = T6CON;
  T6CON = uVar1 | 0x40;
  return;
}



/* ===== c0bf54 cc_irq_enable size=56 ===== */

void cc_irq_enable(ushort param_1,short param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_2 == 0) {
    uVar1 = DAT_00c3c4;
    *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & ~(1 << (param_1 >> 1 & 0xf));
    return;
  }
  uVar2 = DAT_00c3c4;
  uVar1 = 1 << (param_1 >> 1 & 0xf);
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & ~uVar1 | uVar1;
  return;
}



/* ===== c0bf8c cc_irq_is_enabled size=36 ===== */

undefined2 cc_irq_is_enabled(ushort param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  
  uVar2 = DAT_00c3c4;
  uVar1 = 1 << (param_1 >> 1 & 0xf);
  if (((*(ushort *)(uint3)uVar2 & uVar1) == 0) || (uVar1 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* ===== c0bfcc gap_c0bfcc size=6 ===== */

void gap_c0bfcc(void)

{
  func_0xc1454e();
  return;
}



/* ===== c0bfd2 app_clear_flag size=6 ===== */

void app_clear_flag(void)

{
  DAT_00c446 = 0;
  return;
}



/* ===== c0bfd8 gap_c0bfd8 size=10 ===== */

void gap_c0bfd8(short param_1)

{
  if ((param_1 != 0) && (param_1 != 1)) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  app_main_init();
  return;
}



/* ===== c0bfe2 app_run size=16 ===== */

void app_run(short param_1)

{
  if ((param_1 != 0) && (param_1 != 1)) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  app_main_init();
  return;
}



/* ===== c0bff2 gap_c0bff2 size=2 ===== */

void gap_c0bff2(void)

{
  ushort uVar1;
  
  uVar1 = Ram00fd1e;
  Ram00fd1e = uVar1 | 1;
  return;
}



/* ===== c0bff4 empty_stub_1 size=2 ===== */

void empty_stub_1(void)

{
  return;
}



/* ===== c0bff6 empty_stub_2 size=2 ===== */

void empty_stub_2(void)

{
  return;
}



/* ===== c0c5de FUN_c0c5de size=124 ===== */

undefined4 FUN_c0c5de(void)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short sVar7;
  
  uVar6 = PSW;
  PSW = uVar6 & 0xf7ff;
  uVar5 = CC24;
  uVar2 = DAT_00c4c8;
  uVar6 = uVar2 * 8 + uVar5;
  sVar7 = (uVar2 >> 0xd) + (ushort)CARRY2(uVar2 * 8,uVar5);
  uVar2 = T7;
  uVar4 = T7;
  if ((uVar5 == uVar4 || uVar5 < uVar2) || (uVar2 = T7IC, (uVar2 & 0x80) != 0)) {
    uVar2 = T7IC;
    if ((uVar2 & 0x80) != 0) {
      uVar2 = T7;
      uVar4 = T7;
      if (uVar5 == uVar4 || uVar5 < uVar2) {
        sVar3 = DAT_00c4c8;
        if (sVar3 == -0x2000) {
          sVar7 = 0;
          uVar6 = uVar5;
        }
        else {
          sVar7 = sVar7 + 1;
        }
      }
    }
  }
  else {
    sVar3 = DAT_00c4c8;
    if (sVar3 == 0) {
      sVar3 = DAT_00c4c8;
      bVar1 = CARRY2(uVar6,sVar3 * 8);
      uVar6 = uVar6 + sVar3 * 8;
      sVar7 = sVar7 + (sVar3 + 0xe000U >> 0xd) + (ushort)bVar1;
    }
    else {
      sVar7 = sVar7 + -1;
    }
  }
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return CONCAT22(sVar7,uVar6);
}



/* ===== c0c65a FUN_c0c65a size=152 ===== */

void FUN_c0c65a(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  
  uVar2 = DAT_00fd00;
  DAT_00fd00 = uVar2 & 0xffef;
  cVar3 = DAT_00c256;
  DAT_00c276 = cVar3 + '\x01';
  while (bVar4 = DAT_00c276, *(short *)(uint3)((short)&DAT_00c282 + (ushort)bVar4 * 2) == 0) {
    cVar3 = DAT_00c276;
    DAT_00c276 = cVar3 + '\x01';
  }
  bVar5 = DAT_00c276;
  bVar4 = DAT_00c256;
  uVar2 = (ushort)bVar5 - (ushort)bVar4 & 0xff;
  uVar8 = T5;
  uVar6 = CC24IC;
  uVar7 = PSW;
  PSW = uVar7 & 0xffbf | ((uVar6 & 0x80) >> 7) << 6;
  uVar6 = PSW;
  bVar1 = (uVar6 & 0x40) != 0;
  if (bVar1) {
    uVar8 = T5;
  }
  if (uVar2 <= uVar8) {
    uVar6 = DAT_00fd00;
    DAT_00fd00 = uVar6 | 0x10;
  }
  uVar6 = T5CON;
  T5CON = uVar6 & 0xffbf;
  T5 = uVar8 - uVar2;
  uVar6 = T5CON;
  T5CON = uVar6 | 0x40;
  uVar6 = CC24IC;
  uVar7 = PSW;
  PSW = uVar7 & 0xffbf | ((uVar6 & 0x80) >> 7) << 6;
  uVar6 = PSW;
  if (((uVar6 & 0x40) != 0) && (!bVar1)) {
    uVar6 = DAT_00fd00;
    DAT_00fd00 = uVar6 & 0xffef;
    if (uVar2 <= uVar8 + 1) {
      uVar6 = DAT_00fd00;
      DAT_00fd00 = uVar6 | 0x10;
    }
    uVar6 = T5CON;
    T5CON = uVar6 & 0xffbf;
    T5 = (uVar8 + 1) - uVar2;
    uVar2 = T5CON;
    T5CON = uVar2 | 0x40;
  }
  uVar2 = DAT_00fd00;
  if ((uVar2 & 0x10) != 0) {
    uVar2 = T5IC;
    T5IC = uVar2 & 0xff7f;
  }
  return;
}



/* ===== c0c6f2 FUN_c0c6f2 size=496 ===== */

void FUN_c0c6f2(void)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  byte bVar4;
  char cVar5;
  undefined1 uVar6;
  ushort uVar7;
  
  while( true ) {
    uVar6 = DAT_00c276;
    DAT_00c256 = uVar6;
    bVar4 = DAT_00c256;
    uVar1 = (short)&DAT_00c282 + (ushort)bVar4 * 2;
    if ((*(ushort *)(uint3)uVar1 & 1) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c244;
      uVar3 = DAT_00c246;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 2) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c240;
      uVar3 = DAT_00c242;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 4) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c23c;
      uVar3 = DAT_00c23e;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 8) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c238;
      uVar3 = DAT_00c23a;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x10) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c234;
      uVar3 = DAT_00c236;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x20) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c230;
      uVar3 = DAT_00c232;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x40) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c22c;
      uVar3 = DAT_00c22e;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x80) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c228;
      uVar3 = DAT_00c22a;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x100) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c224;
      uVar3 = DAT_00c226;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x200) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c220;
      uVar3 = DAT_00c222;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x400) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c21c;
      uVar3 = DAT_00c21e;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x800) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c218;
      uVar3 = DAT_00c21a;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x1000) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c214;
      uVar3 = DAT_00c216;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x2000) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c210;
      uVar3 = DAT_00c212;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x4000) != 0) {
      uVar7 = PSW;
      PSW = uVar7 & 0xf7ff;
      uVar3 = DAT_00c20c;
      uVar3 = DAT_00c20e;
      empty_stub_0();
      uVar7 = PSW;
      PSW = uVar7 | 0x800;
    }
    if ((*(ushort *)(uint3)uVar1 & 0x8000) != 0) {
      uVar1 = PSW;
      PSW = uVar1 & 0xf7ff;
      uVar3 = DAT_00c208;
      empty_stub_0();
      uVar1 = PSW;
      PSW = uVar1 | 0x800;
    }
    cVar5 = DAT_00c256;
    if (cVar5 == '\x14') break;
    uVar1 = PSW;
    PSW = uVar1 & 0xf7ff;
    FUN_c0c65a();
    uVar1 = PSW;
    PSW = uVar1 | 0x800;
    sVar2 = DAT_00c204;
    if ((sVar2 == 1) && (sVar2 = DAT_00c24a, sVar2 == 0)) {
      DAT_00c24a = 1;
      uVar1 = CC31IC;
      CC31IC = uVar1 | 0x80;
    }
    uVar1 = DAT_00fd00;
    if ((uVar1 & 0x10) == 0) {
      return;
    }
  }
  return;
}



/* ===== c0c8e2 gap_c0c8e2 size=50 ===== */

void gap_c0c8e2(void)

{
  ushort uVar1;
  byte bVar2;
  
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xfffe;
  DAT_00c2b2 = 0;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xffbf;
  T5 = 0;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xff7f;
  uVar1 = CC24IC;
  CC24IC = uVar1 | 0x40;
  uVar1 = DAT_00fd00;
  DAT_00fd00 = uVar1 & 0xdfff;
  uVar1 = DAT_00c2aa;
  DAT_00c2aa = uVar1 | 1;
  gap_c0d70a();
  return;
}



/* ===== c0cac2 watchdog_pin size=24 ===== */

void watchdog_pin(void)

{
  ushort uVar1;
  
  uVar1 = input_status;
  if (((uVar1 & 1) == 0) && (uVar1 = input_status, (uVar1 & 2) == 0)) {
    uVar1 = DAT_00fd00;
    DAT_00fd00 = uVar1 & 0xffdf;
    return;
  }
  uVar1 = DAT_00fd00;
  DAT_00fd00 = uVar1 | 0x20;
  return;
}



/* ===== c0cada FUN_c0cada size=586 ===== */

undefined2 FUN_c0cada(void)

{
  short sVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  ushort uVar8;
  ushort uVar9;
  short sVar10;
  undefined2 uVar11;
  uint uVar12;
  
  uVar5 = DAT_00fd00;
  if ((uVar5 & 0x2000) != 0) {
    uVar11 = CC24;
    DAT_00c25e = uVar11;
    uVar12 = FUN_c0c5de();
    DAT_00c260 = (short)uVar12;
    DAT_00c262 = (short)(uVar12 >> 0x10);
    uVar11 = DAT_00c27e;
    DAT_00c2c4 = uVar11;
    sVar1 = (short)(uVar12 >> 3);
    DAT_00c27e = sVar1;
    uVar11 = DAT_00c266;
    DAT_00c27c = uVar11;
    sVar10 = DAT_00c2c4;
    DAT_00c266 = sVar1 - sVar10;
    return (short)((uVar12 >> 3) >> 0x10);
  }
  cVar2 = DAT_00c1fd;
  DAT_00c1fd = cVar2 + '\x01';
  uVar11 = CC24;
  DAT_00c25e = uVar11;
  uVar12 = FUN_c0c5de();
  DAT_00c260 = (short)uVar12;
  DAT_00c262 = (short)(uVar12 >> 0x10);
  uVar11 = (undefined2)((uVar12 >> 3) >> 0x10);
  DAT_00c27e = (short)(uVar12 >> 3);
  uVar5 = DAT_00fd00;
  if ((uVar5 & 0x8000) != 0) {
    uVar5 = DAT_00fd00;
    DAT_00fd00 = uVar5 & 0x7fff;
    goto LAB_c0cce2;
  }
  sVar1 = DAT_00c27e;
  sVar10 = DAT_00c2c4;
  DAT_00c252 = sVar1 - sVar10;
  uVar5 = DAT_00fd00;
  if ((uVar5 & 0x100) == 0) {
    cVar2 = DAT_00c1fd;
    cVar3 = DAT_00c3da;
    if (cVar2 == cVar3) {
      uVar11 = FUN_c0f132(0);
    }
    cVar2 = DAT_00c1fd;
    cVar3 = DAT_00c3f4;
    if (cVar2 == cVar3) {
      uVar11 = FUN_c0f132(1);
    }
    cVar2 = DAT_00c1fd;
    cVar3 = DAT_00c38e;
    if (cVar2 == cVar3) {
      uVar11 = FUN_c0d076();
    }
    cVar2 = DAT_00c1fd;
    cVar3 = DAT_00c3ae;
    if (cVar2 == cVar3) {
      uVar11 = FUN_c0d956();
    }
    cVar3 = DAT_00c1fd;
    cVar2 = DAT_00c1fa;
    if (cVar3 == cVar2) {
      uVar11 = FUN_c0bab4();
    }
    cVar2 = DAT_00c1fd;
    if (cVar2 == '\x04') {
      uVar11 = FUN_c0d296();
    }
    uVar5 = DAT_00fd00;
    DAT_00fd00 = uVar5 | 0x200;
    uVar5 = DAT_00fd00;
    if ((uVar5 & 0x400) == 0) {
      uVar5 = DAT_00fd00;
      DAT_00fd00 = uVar5 | 0x400;
    }
    else {
      uVar5 = DAT_00fd18;
      if ((uVar5 & 0x80) == 0) {
        uVar5 = DAT_00fd00;
        if ((uVar5 & 0x4000) == 0) {
          uVar8 = DAT_00c270;
          sVar1 = DAT_00c270;
          uVar5 = DAT_00c252;
          if ((uVar8 >> 1) + sVar1 < uVar5) {
            uVar5 = DAT_00fd00;
            DAT_00fd00 = uVar5 | 0x4000;
          }
        }
        else {
          uVar5 = DAT_00c252;
          sVar1 = DAT_00c252;
          uVar8 = DAT_00c270;
          if ((uVar5 >> 1) + sVar1 < uVar8) {
            uVar5 = DAT_00fd00;
            DAT_00fd00 = uVar5 & 0xbfff;
            uVar5 = DAT_00fd00;
            DAT_00fd00 = uVar5 | 0x2000;
            uVar5 = DAT_00fd00;
            DAT_00fd00 = uVar5 | 0x800;
            uVar5 = DAT_00fd00;
            DAT_00fd00 = uVar5 | 0x80;
          }
          else {
            uVar5 = DAT_00c252;
            uVar8 = DAT_00c270;
            uVar9 = DAT_00c270;
            if (uVar5 == uVar9 || uVar5 < uVar8) {
              uVar5 = DAT_00fd00;
              DAT_00fd00 = uVar5 & 0xbfff;
            }
          }
        }
      }
      uVar5 = DAT_00fd00;
      if ((uVar5 & 0x2000) != 0) {
        uVar11 = DAT_00c260;
        uVar6 = DAT_00c262;
        DAT_00c24c = uVar11;
        DAT_00c24e = uVar6;
        DAT_00c256 = 2;
        uVar7 = DAT_00c256;
        DAT_00c1fc = uVar7;
        cVar2 = DAT_00c2b2;
        cVar3 = T5._0_1_;
        DAT_00c2b2 = cVar3 + cVar2;
        uVar5 = T5CON;
        T5CON = uVar5 & 0xffbf;
        T5 = 0;
        uVar11 = FUN_c0c65a();
        uVar5 = T5IC;
        T5IC = uVar5 | 0x40;
        DAT_00c1fd = 0;
        uVar5 = DAT_00fd00;
        DAT_00fd00 = uVar5 & 0xfbff;
        uVar5 = DAT_00fd00;
        if ((uVar5 & 0x1000) == 0) {
          uVar5 = DAT_00fd00;
          DAT_00fd00 = uVar5 | 0x1000;
        }
        else {
          bVar4 = DAT_00c2b2;
          if (bVar4 < 5) {
            cVar2 = DAT_00c264;
            DAT_00c264 = cVar2 + '\x01';
LAB_c0cc80:
            DAT_00c280 = 0;
          }
          else {
            bVar4 = DAT_00c2b2;
            if (5 < bVar4) {
              cVar2 = DAT_00c272;
              DAT_00c272 = cVar2 + '\x01';
              goto LAB_c0cc80;
            }
            cVar2 = DAT_00c2b2;
            if (cVar2 == '\x05') {
              cVar2 = DAT_00c280;
              DAT_00c280 = cVar2 + '\x01';
            }
          }
          cVar2 = DAT_00c264;
          cVar3 = DAT_00c272;
          DAT_00c277 = cVar2 + cVar3;
        }
        uVar5 = DAT_00fd00;
        if ((uVar5 & 0x10) != 0) {
          uVar11 = FUN_c0c6f2();
        }
      }
      uVar5 = DAT_00fd00;
      if ((uVar5 & 0x4000) == 0) {
        uVar6 = DAT_00c266;
        DAT_00c27c = uVar6;
        uVar6 = DAT_00c252;
        DAT_00c266 = uVar6;
      }
      else {
        uVar6 = DAT_00c266;
        DAT_00c27c = uVar6;
        uVar5 = DAT_00c252;
        DAT_00c266 = uVar5 >> 1;
      }
    }
  }
  else {
    uVar5 = DAT_00fd00;
    if ((uVar5 & 0x20) == 0) {
      uVar5 = DAT_00c252;
      if ((uVar5 < 0x9d) || (uVar5 = DAT_00c252, 0xc34 < uVar5)) {
        DAT_00c202 = 0;
      }
      else {
        cVar2 = DAT_00c202;
        DAT_00c202 = cVar2 + '\x01';
        bVar4 = DAT_00c202;
        if ((byte)PTR_DAT_c05030 <= bVar4) {
          uVar5 = DAT_00fd00;
          DAT_00fd00 = uVar5 | 0x200;
          uVar5 = DAT_00fd00;
          DAT_00fd00 = uVar5 & 0xfeff;
          uVar5 = DAT_00fd00;
          DAT_00fd00 = uVar5 | 0x400;
          DAT_00c202 = 0;
        }
        cVar2 = DAT_00c202;
        if (cVar2 == '\x02') {
          uVar5 = DAT_00fd02;
          DAT_00fd02 = uVar5 | 0x100;
          DAT_00c3b4 = 0;
        }
      }
    }
    else {
      uVar5 = DAT_00fd00;
      DAT_00fd00 = uVar5 & 0xfeff;
      uVar5 = DAT_00fd00;
      DAT_00fd00 = uVar5 | 0x400;
      uVar5 = DAT_00fd00;
      DAT_00fd00 = uVar5 & 0xffdf;
    }
    uVar5 = DAT_00fd02;
    DAT_00fd02 = uVar5 | 0x200;
  }
  uVar6 = DAT_00c252;
  DAT_00c270 = uVar6;
LAB_c0cce2:
  uVar6 = DAT_00c27e;
  DAT_00c2c4 = uVar6;
  return uVar11;
}



/* ===== c0cd24 speed_timing_calc size=214 ===== */

void speed_timing_calc(void)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  undefined2 uVar5;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  bVar1 = DAT_00c268;
  bVar4 = bVar1 + 1;
  if (bVar4 < bVar1) {
    bVar4 = 0xff;
  }
  DAT_00c268 = bVar4;
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = DAT_00fd00;
  uVar3 = DAT_00fd00;
  DAT_00fd00 = uVar3 & 0xffbf;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = DAT_00fd02;
  DAT_00fd02 = uVar3 & 0xbfff | (uVar2 >> 6 & 1) << 0xe;
  uVar2 = DAT_00fd02;
  if ((uVar2 & 0x4000) != 0) {
    uVar2 = DAT_00fd02;
    DAT_00fd02 = uVar2 | 0x8000;
  }
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = DAT_00fd00;
  uVar3 = DAT_00fd00;
  DAT_00fd00 = uVar3 & 0xf7ff;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = DAT_00fd02;
  DAT_00fd02 = uVar3 & 0xdfff | (uVar2 >> 0xb & 1) << 0xd;
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = DAT_00fd00;
  uVar3 = DAT_00fd00;
  DAT_00fd00 = uVar3 & 0xfdff;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  uVar3 = DAT_00fd02;
  DAT_00fd02 = uVar3 & 0xefff | (uVar2 >> 9 & 1) << 0xc;
  uVar2 = DAT_00fd02;
  if ((uVar2 & 0x1000) != 0) {
    uVar2 = DAT_00fd02;
    DAT_00fd02 = uVar2 & 0xf3ff | 0xc00;
  }
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  uVar5 = DAT_00c9d0;
  uVar5 = axis16_unsigned(0x7000,uVar5);
  DAT_00c254 = uVar5;
  uVar5 = tbl16_interp(0x504c,0xc0,uVar5);
  DAT_00c274 = uVar5;
  uVar5 = DAT_00c254;
  uVar5 = tbl16_interp(0x5038,0xc0,uVar5);
  DAT_00c26e = uVar5;
  return;
}



/* ===== c0cdfa timer5_init size=168 ===== */

void timer5_init(void)

{
  ushort uVar1;
  byte bVar2;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xffbf;
  T5 = 0;
  uVar1 = CC24IC;
  CC24IC = uVar1 & 0xffbf;
  DAT_00c274 = 0x200;
  DAT_00c26e = 0;
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  bVar2 = 0;
  do {
    uVar1 = (ushort)bVar2;
    bVar2 = bVar2 + 1;
    *(undefined2 *)(uint3)((short)&DAT_00c282 + uVar1 * 2) = 0;
  } while (bVar2 < 0x18);
  DAT_00fd00 = 0x8100;
  DAT_00c2b2 = 0;
  DAT_00c280 = 0;
  DAT_00c277 = 0;
  DAT_00c264 = 0;
  DAT_00c272 = 0;
  uVar1 = DAT_00fd00;
  DAT_00fd00 = uVar1 & 0xffbf;
  DAT_00c2b4 = 0xffff;
  DAT_00c26a = 0xffff;
  DAT_00c26c = 0xffff;
  DAT_00c268 = 0xff;
  DAT_00c25c = 0;
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  DAT_00c244 = 0xc8e2;
  DAT_00c246 = 0xc0;
  DAT_00c240 = 0xc914;
  DAT_00c242 = 0xc0;
  uVar1 = DAT_00c2aa;
  DAT_00c2aa = uVar1 | 1;
  uVar1 = DAT_00c28a;
  DAT_00c28a = uVar1 | 2;
  uVar1 = DAT_00c2a2;
  DAT_00c2a2 = uVar1 | 2;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xffbf;
  T5 = 0;
  uVar1 = T5IC;
  T5IC = uVar1 & 0xff7f;
  uVar1 = CC24IC;
  CC24IC = uVar1 | 0x40;
  watchdog_pin();
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}



/* ===== c0cea2 capcom_start size=118 ===== */

void capcom_start(void)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = DAT_00f066;
  DAT_00f066 = uVar2 | 4;
  uVar2 = T78CON;
  T78CON = uVar2 | 5;
  T7 = 0;
  T7REL = 0;
  T8 = 0;
  T8REL = 0;
  bVar1 = 0;
  uVar2 = (ushort)&CC16;
  do {
    bVar1 = bVar1 + 1;
    *(undefined2 *)(uint3)uVar2 = 0;
    uVar2 = uVar2 + 2;
  } while (bVar1 < 0x10);
  CCM4 = 0;
  CCM7 = 0;
  CCM6 = 3;
  DAT_00ff2a = 0;
  DAT_00fe28 = 0;
  DAT_00fe2a = 0;
  DAT_00ff2c = 0;
  uVar2 = CC24IC;
  CC24IC = uVar2 | 0x38;
  uVar2 = T5CON;
  T5CON = uVar2 | 10;
  T5 = 0;
  CAPREL = 0;
  uVar2 = T5IC;
  T5IC = uVar2 | 0x24;
  uVar2 = T7IC;
  T7IC = uVar2 | 0x79;
  uVar2 = T5CON;
  T5CON = uVar2 | 0x40;
  uVar2 = T78CON;
  T78CON = uVar2 | 0x40;
  uVar2 = CC31IC;
  CC31IC = uVar2 | 0xcc;
  return;
}



/* ===== c0cf18 FUN_c0cf18 size=48 ===== */

void FUN_c0cf18(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  
  DAT_00fa00 = &stack0x0000;
  uVar1 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x303;
  uVar4 = PSW;
  PSW = uVar4 | 0x800;
  FUN_c11f10(uVar2,uVar1);
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c0cf48 FUN_c0cf48 size=200 ===== */

void FUN_c0cf48(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  DAT_00fa20 = &stack0x0000;
  uVar4 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  DPP2 = 0x303;
  uVar3 = DAT_00fd18;
  if ((uVar3 & 0x80) != 0) goto LAB_c0d002;
  uVar3 = P1H;
  if ((uVar3 & 0x10) != 0) {
    if (DAT_c05081 == '\x04') {
      uVar3 = P1L;
      P1L = uVar3 & 0xffef;
    }
    goto LAB_c0d002;
  }
  if (DAT_c05081 == '\x04') {
LAB_c0cfe8:
    uVar3 = P1L;
    P1L = uVar3 | 0x10;
  }
  else if (DAT_c05081 == '\x03') {
    bVar1 = DAT_00c1fc;
    if ((1 < bVar1) && (bVar1 < 0x11)) {
      cVar2 = DAT_00c1fc;
      DAT_00c1fc = cVar2 + '\x01';
      cVar2 = DAT_00c1fc;
      if ((cVar2 == '\b') || (cVar2 == '\x0e')) goto LAB_c0cfec;
      if ((cVar2 == '\t') || (cVar2 == '\x0f')) goto LAB_c0cfe8;
    }
  }
  else if ((DAT_c05081 == '\x05') && ((bVar1 = DAT_00c1fc, 1 < bVar1 && (bVar1 < 0x17)))) {
    cVar2 = DAT_00c1fc;
    DAT_00c1fc = cVar2 + '\x01';
    cVar2 = DAT_00c1fc;
    if ((cVar2 == '\x04') || (cVar2 == '\x10')) {
LAB_c0cfec:
      uVar3 = P1L;
      P1L = uVar3 & 0xffef;
    }
    else if ((cVar2 == '\n') || (cVar2 == '\x16')) goto LAB_c0cfe8;
  }
  FUN_c0cada(uVar5,uVar4);
LAB_c0d002:
  DPP2 = uVar5;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar4;
  uVar4 = DPP0;
  uVar4 = DPP0;
  uVar4 = DPP0;
  return;
}



/* ===== c0d010 FUN_c0d010 size=48 ===== */

void FUN_c0d010(void)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  DAT_00fa20 = &stack0x0000;
  uVar2 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  DPP0 = 0x301;
  uVar3 = DPP2;
  uVar4 = DPP2;
  uVar4 = DPP2;
  DPP2 = 0x303;
  sVar1 = DAT_00c4c8;
  DAT_00c4c8 = sVar1 + 0x2000;
  sVar1 = DAT_00c4ca;
  DAT_00c4ca = sVar1 + 0x100;
  DPP2 = uVar3;
  uVar3 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}



/* ===== c0d040 FUN_c0d040 size=54 ===== */

void FUN_c0d040(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  DAT_00fa40 = &stack0x0000;
  uVar2 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  DPP0 = 0x301;
  uVar3 = DPP2;
  uVar4 = DPP2;
  uVar4 = DPP2;
  DPP2 = 0x303;
  uVar1 = DAT_00fd18;
  if ((uVar1 & 0x80) == 0) {
    FUN_c0c6f2(uVar3,uVar2);
  }
  DPP2 = uVar3;
  uVar3 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}



/* ===== c0d076 FUN_c0d076 size=6 ===== */

void FUN_c0d076(void)

{
  FUN_c0d5ca();
  return;
}



/* ===== c0d07c gap_c0d07c size=6 ===== */

void gap_c0d07c(void)

{
  func_0xc0ed22();
  return;
}



/* ===== c0d082 gap_c0d082 size=6 ===== */

void gap_c0d082(void)

{
  gap_c0ee3c();
  return;
}



/* ===== c0d088 gap_c0d088 size=6 ===== */

void gap_c0d088(void)

{
  func_0xc0ef48();
  return;
}



/* ===== c0d08e gap_c0d08e size=6 ===== */

void gap_c0d08e(void)

{
  gap_c0ef4a();
  return;
}



/* ===== c0d094 gap_c0d094 size=6 ===== */

void gap_c0d094(void)

{
  gap_c0f032();
  return;
}



/* ===== c0d09a gap_c0d09a size=6 ===== */

void gap_c0d09a(void)

{
  gap_c0f2b8();
  return;
}



/* ===== c0d0a0 gap_c0d0a0 size=6 ===== */

void gap_c0d0a0(void)

{
  gap_c0f378();
  return;
}



/* ===== c0d0a6 gap_c0d0a6 size=6 ===== */

void gap_c0d0a6(void)

{
  func_0xc0f2b4();
  return;
}



/* ===== c0d0ac gap_c0d0ac size=6 ===== */

void gap_c0d0ac(void)

{
  func_0xc0f2b6();
  return;
}



/* ===== c0d0b2 gap_c0d0b2 size=46 ===== */

void gap_c0d0b2(void)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = DAT_00c3d9;
  cVar1 = DAT_00c256;
  if (*(char *)(uint3)((ushort)bVar2 * 2 + 0x700e) == cVar1) {
    FUN_c0f132(0);
  }
  bVar2 = DAT_00c3f3;
  cVar1 = DAT_00c256;
  if (*(char *)(uint3)((short)&DAT_00c468 + (ushort)bVar2 * 2) == cVar1) {
    FUN_c0f132(1);
  }
  return;
}



/* ===== c0d0e0 FUN_c0d0e0 size=74 ===== */

void FUN_c0d0e0(byte param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = DAT_00c374;
  uVar2 = DAT_00c37e;
  capcom_event_config2
            (param_1,*(undefined2 *)(uint3)((short)&DAT_00c384 + (ushort)param_1 * 4),
             *(undefined2 *)(uint3)((short)&DAT_00c386 + (ushort)param_1 * 4),
             *(undefined2 *)(uint3)((short)&UNK_00c36a + (ushort)param_1 * 2),uVar2,uVar1);
  *(undefined2 *)(uint3)((short)&DAT_00c416 + (ushort)param_1 * 0x12) = 0;
  *(undefined2 *)(uint3)((short)&DAT_00c418 + (ushort)param_1 * 0x12) = 0;
  return;
}



/* ===== c0d296 FUN_c0d296 size=78 ===== */

void FUN_c0d296(void)

{
  ushort uVar1;
  char cVar2;
  
  DAT_00c20c = 0x1f16;
  DAT_00c20e = 0xc1;
  cVar2 = DAT_00c92f;
  if (cVar2 == '\0') {
    uVar1 = (short)&DAT_00c282 + (ushort)DAT_c05085 * 2;
    *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xbfff | 0x4000;
    return;
  }
  uVar1 = (short)&DAT_00c282 + (ushort)DAT_c05084 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xbfff | 0x4000;
  return;
}



/* ===== c0d2e4 FUN_c0d2e4 size=48 ===== */

undefined2 FUN_c0d2e4(short param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_00c2ba;
  uVar2 = div32u(0,uVar1,-0x4c00 - param_1);
  uVar1 = mul32((short)uVar2,(short)((uint)uVar2 >> 0x10));
  return uVar1;
}



/* ===== c0d314 gap_c0d314 size=36 ===== */

void gap_c0d314(short param_1,undefined2 param_2)

{
  undefined2 uVar1;
  
  if (param_1 != 0) {
    DAT_00c380 = param_2;
    uVar1 = FUN_c0d2e4(param_2);
    DAT_00c374 = uVar1;
    return;
  }
  DAT_00c376 = param_2;
  uVar1 = FUN_c0d2e4(param_2);
  DAT_00c37e = uVar1;
  return;
}



/* ===== c0d39e event_start size=88 ===== */

void event_start(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  byte bVar4;
  
  sVar3 = t7_timestamp_extended();
  bVar4 = 0;
  do {
    uVar1 = DAT_00c374;
    uVar2 = DAT_00c37e;
    capcom_event_config2
              (bVar4,*(undefined2 *)(uint3)((short)&DAT_00c384 + (ushort)bVar4 * 4),
               *(undefined2 *)(uint3)((short)&DAT_00c386 + (ushort)bVar4 * 4),sVar3 + 4,uVar2,uVar1)
    ;
    *(undefined2 *)(uint3)((short)&DAT_00c416 + (ushort)bVar4 * 0x12) = 0;
    *(undefined2 *)(uint3)((short)&DAT_00c418 + (ushort)bVar4 * 0x12) = 0;
    bVar4 = bVar4 + 1;
  } while (bVar4 < 2);
  DAT_00c36e = 0;
  return;
}



/* ===== c0d4ca gap_c0d4ca size=76 ===== */

void gap_c0d4ca(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  
  sVar1 = DAT_00c372;
  if (sVar1 == 0) {
    uVar2 = DAT_00c384;
    uVar3 = DAT_00c386;
    uVar4 = DAT_00c416;
    uVar5 = DAT_00c418;
    if (uVar3 - uVar5 == (ushort)(uVar2 < uVar4) && uVar2 == uVar4 ||
        (uVar3 < uVar5 || uVar3 == uVar5 && uVar2 < uVar4)) {
      sVar6 = DAT_00c418;
      sVar1 = DAT_00c416;
      if (sVar6 != 0 || sVar1 != 0) goto LAB_c0d50e;
    }
  }
  sVar1 = DAT_00c372;
  if (sVar1 != 0) {
    return;
  }
  uVar2 = DAT_00c388;
  uVar3 = DAT_00c38a;
  uVar4 = Ram00c428;
  uVar5 = Ram00c42a;
  if ((uVar3 - uVar5 != (ushort)(uVar2 < uVar4) || uVar2 != uVar4) &&
      (uVar5 <= uVar3 && (uVar3 != uVar5 || uVar2 >= uVar4))) {
    return;
  }
  sVar6 = Ram00c42a;
  sVar1 = Ram00c428;
  if (sVar6 == 0 && sVar1 == 0) {
    return;
  }
LAB_c0d50e:
  DAT_00c36e = 1;
  return;
}



/* ===== c0d516 event_reset size=18 ===== */

void event_reset(void)

{
  DAT_00c378 = 0;
  DAT_00c37e = 0;
  DAT_00c374 = 0;
  DAT_00c370 = 0;
  return;
}



/* ===== c0d528 event_init size=58 ===== */

void event_init(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  capcom16_17_init();
  bVar3 = 0;
  do {
    capcom_event_config(bVar3,*(undefined1 *)(uint3)((short)&DAT_00c390 + (ushort)bVar3 * 8),1);
    bVar3 = bVar3 + 1;
  } while (bVar3 < 2);
  DAT_00c370 = 0;
  sVar1 = DAT_00c372;
  if (sVar1 == 0) {
    event_start();
  }
  event_reset();
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return;
}



/* ===== c0d562 angle_init size=104 ===== */

void angle_init(void)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  DAT_00c224 = 0xd076;
  DAT_00c226 = 0xc0;
  bVar3 = 0;
  do {
    uVar1 = (ushort)bVar3;
    uVar2 = (ushort)bVar3;
    bVar3 = bVar3 + 1;
    bVar4 = (char)(*(ushort *)(uint3)(uVar1 * 2 + 0x5032) / 0x3c0) + 4;
    if (0x18 < bVar4) {
      bVar4 = bVar4 % 0x18;
    }
    *(byte *)(uint3)((short)&DAT_00c382 + uVar2) = bVar4;
  } while (bVar3 < 2);
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}



/* ===== c0d5ca FUN_c0d5ca size=222 ===== */

void FUN_c0d5ca(void)

{
  short sVar1;
  byte bVar2;
  undefined1 uVar3;
  short extraout_r3;
  undefined2 uVar4;
  ushort uVar5;
  short sVar6;
  ushort uVar7;
  short sVar8;
  
  sVar1 = DAT_00c372;
  if (sVar1 == 1) {
    bVar2 = DAT_00c38f;
    uVar5 = (short)&DAT_00c382 + (ushort)bVar2;
    if ((2 < *(byte *)(uint3)uVar5) && (*(byte *)(uint3)uVar5 < 0x15)) {
      uVar5 = (short)&DAT_00c282 + (ushort)*(byte *)(uint3)uVar5 * 2;
      *(ushort *)(uint3)uVar5 = *(ushort *)(uint3)uVar5 & 0xfeff;
    }
    DAT_00c38e = 0;
    bVar2 = DAT_00c38f;
    uVar5 = (ushort)bVar2;
    uVar7 = DAT_00c2ba;
    sVar8 = 0;
    div32u(0,0);
    sVar6 = uVar5 * 2;
    uVar4 = DAT_00c206;
    uVar5 = mul32((*(ushort *)(sVar6 + 0x5032) >> 6) % 0xb4);
    sVar1 = uVar7 * 4 + uVar5;
    *(short *)(uint3)(ushort)((short)&UNK_00c36a + sVar6) = extraout_r3 + sVar1;
    *(short *)(uint3)(ushort)((short)&UNK_00c37a + sVar6) = sVar1;
    uVar4 = DAT_00c376;
    uVar4 = FUN_c0d2e4(uVar4,(sVar8 * 2 + (ushort)CARRY2(uVar7,uVar7)) * 2 +
                             (ushort)CARRY2(uVar7 * 2,uVar7 * 2) + (ushort)CARRY2(uVar7 * 4,uVar5));
    DAT_00c37e = uVar4;
    uVar4 = DAT_00c380;
    uVar4 = FUN_c0d2e4(uVar4);
    DAT_00c374 = uVar4;
    uVar3 = DAT_00c38f;
    FUN_c0d0e0(uVar3);
  }
  return;
}



/* ===== c0d6f0 event_start_fixed size=26 ===== */

void event_start_fixed(void)

{
  DAT_00c384 = 0x1194;
  DAT_00c386 = 0;
  DAT_00c388 = 0x1194;
  DAT_00c38a = 0;
  event_start();
  return;
}



/* ===== c0d70a gap_c0d70a size=20 ===== */

void gap_c0d70a(void)

{
  undefined1 uVar1;
  short sVar2;
  
  sVar2 = Ram00c3fa;
  if (sVar2 != -0x6010) {
    uVar1 = UNK_00c3b9;
    func_0xc0e526(uVar1);
  }
  return;
}



/* ===== c0d71e FUN_c0d71e size=96 ===== */

undefined4 FUN_c0d71e(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  
  uVar6 = div32u();
  sVar4 = (short)((uVar6 >> 6) >> 0x10);
  uVar1 = (ushort)(uVar6 >> 6);
  DAT_00c3a6 = uVar1;
  DAT_00c3a8 = sVar4;
  sVar2 = uVar1 + 0x100;
  sVar3 = sVar4 - (ushort)(uVar1 < 0xff00);
  if (sVar3 == 0 && sVar2 == 0 || sVar4 == 0 && uVar1 < 0xff00) {
    sVar4 = DAT_00c3a6;
    sVar5 = CC24;
    uVar1 = DAT_00c48e;
    *(short *)(uint3)uVar1 = sVar4 + sVar5;
    return CONCAT22(sVar3,sVar2);
  }
  uVar1 = DAT_00c3a6;
  DAT_00c3a6 = uVar1 + 0x100;
  sVar4 = DAT_00c3a8;
  DAT_00c3a8 = sVar4 - (ushort)(uVar1 < 0xff00);
  DAT_00c3aa = 1;
  sVar4 = CC24;
  uVar1 = DAT_00c48e;
  *(short *)(uint3)uVar1 = sVar4 + -0x100;
  return CONCAT22(sVar3,sVar2);
}



/* ===== c0d8fa gap_c0d8fa size=26 ===== */

void gap_c0d8fa(void)

{
  ushort uVar1;
  byte bVar2;
  undefined2 uVar3;
  
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xf7ff;
  uVar3 = CC24;
  Ram00c3b6 = uVar3;
  return;
}



/* ===== c0d956 FUN_c0d956 size=22 ===== */

void FUN_c0d956(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  DAT_00c3ae = 0;
  uVar1 = DAT_00c3ac;
  uVar2 = DAT_00c3c0;
  FUN_c0d71e(uVar1,uVar2);
  uVar3 = DAT_00fe2a;
  DAT_00fe2a = uVar3 | 0x400;
  return;
}



/* ===== c0d9e4 ssc_init size=126 ===== */

void ssc_init(void)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  DAT_00c218 = 0xd8fa;
  DAT_00c21a = 0xc0;
  DAT_00c21c = 0xd914;
  DAT_00c21e = 0xc0;
  cc26_ptr_init();
  uVar2 = DAT_00c490;
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 | 0x68;
  ssc_pin_config();
  sVar1 = DAT_00c48a;
  if (sVar1 != 0) {
    DAT_00c214 = 0xd8ce;
    DAT_00c216 = 0xc0;
  }
  sVar1 = DAT_00c48c;
  if ((sVar1 == 0) && (sVar1 = DAT_00c48a, sVar1 == 0)) {
    DAT_00c3ba = 1;
    sVar1 = DAT_00c48a;
    if (sVar1 == 0) {
      DAT_00c214 = 0xd8ce;
      DAT_00c216 = 0xc0;
    }
  }
  else {
    DAT_00c3ba = 0;
  }
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return;
}



/* ===== c0da62 cc26_ptr_init size=42 ===== */

void cc26_ptr_init(void)

{
  DAT_00c48e = 0xfe74;
  DAT_00c482 = 0xff26;
  DAT_00c490 = 0xf174;
  DAT_00c488 = 0xfe28;
  DAT_00c486 = 0xfe2a;
  return;
}



/* ===== c0da8c FUN_c0da8c size=166 ===== */

void FUN_c0da8c(void)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  short sVar6;
  undefined2 uVar7;
  char cVar8;
  
  DAT_00faa0 = &stack0x0000;
  uVar4 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  DPP2 = 0x303;
  sVar2 = DAT_00c3aa;
  if (sVar2 == 0) {
    FUN_c19aa6(uVar5,uVar4);
    cVar8 = FUN_c243a8(0x14);
    if ((cVar8 == '\0') && (cVar8 = FUN_c243a8(0x15), cVar8 == '\0')) {
      if (DAT_c05081 == '\x01') {
        uVar7 = P1L;
        uVar1 = P1L;
        uVar3 = P1L;
        P1L = uVar3 & 0xffef | ((uVar1 & 0x10) >> 4 ^ 1) << 4;
      }
    }
    else {
      uVar1 = P1L;
      P1L = uVar1 & 0xffef;
    }
  }
  else {
    uVar1 = DAT_00c3a6;
    uVar3 = DAT_00c3a8;
    if (uVar3 == uVar1 < 0xff00 && uVar1 == 0xff00 || uVar3 == 0 && uVar1 < 0xff00) {
      DAT_00c3aa = 0;
      sVar2 = DAT_00c3a6;
      sVar6 = CC24;
      uVar1 = DAT_00c48e;
      *(short *)(uint3)uVar1 = sVar2 + sVar6;
    }
    else {
      uVar1 = DAT_00c3a6;
      DAT_00c3a6 = uVar1 + 0x100;
      sVar2 = DAT_00c3a8;
      DAT_00c3a8 = sVar2 - (ushort)(uVar1 < 0xff00);
      DAT_00c3aa = 1;
      sVar2 = CC24;
      uVar1 = DAT_00c48e;
      *(short *)(uint3)uVar1 = sVar2 + -0x100;
    }
  }
  DPP2 = uVar5;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar4;
  uVar4 = DPP0;
  uVar4 = DPP0;
  uVar4 = DPP0;
  return;
}



/* ===== c0db90 cc_irq_enable_bit size=22 ===== */

void cc_irq_enable_bit(char param_1)

{
  ushort uVar1;
  
  if (param_1 != '\x10') {
    uVar1 = DAT_00fe2a;
    DAT_00fe2a = uVar1 | 2;
    return;
  }
  uVar1 = DAT_00fe2a;
  DAT_00fe2a = uVar1 | 1;
  return;
}



/* ===== c0dba6 cc_compare_mode_set size=56 ===== */

void cc_compare_mode_set(ushort param_1)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  
  cVar1 = *(char *)(uint3)((short)&UNK_00c41d + (param_1 & 0xff) * 0x12);
  cVar2 = DAT_00c40e;
  if (cVar2 != '\0') {
    if (cVar1 != '\x10') {
      uVar3 = DAT_00ff2c;
      DAT_00ff2c = uVar3 & 0xfffd;
      return;
    }
    uVar3 = DAT_00ff2c;
    DAT_00ff2c = uVar3 & 0xfffe;
    return;
  }
  if (cVar1 != '\x10') {
    uVar3 = DAT_00ff2c;
    DAT_00ff2c = uVar3 | 2;
    return;
  }
  uVar3 = DAT_00ff2c;
  DAT_00ff2c = uVar3 | 1;
  return;
}



/* ===== c0dbde event_force size=132 ===== */

void event_force(ushort param_1)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  char cVar5;
  
  sVar3 = (param_1 & 0xff) * 0x12;
  uVar4 = DAT_00c40a;
  bVar1 = *(byte *)(uint3)(ushort)((short)&UNK_00c41d + sVar3);
  bVar2 = bVar1 & 0xf;
  cVar5 = DAT_00c40e;
  if (((*(ushort *)(uint3)uVar4 & 1 << bVar2) != 0) == (cVar5 == '\0')) {
    uVar4 = DAT_00c3fc;
    *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar3) =
         *(short *)(uint3)uVar4 + 10;
  }
  uVar4 = DAT_00c402;
  sVar3 = (ushort)bVar2 << 2;
  *(ushort *)(uint3)uVar4 = *(ushort *)(uint3)uVar4 & ~(0xf << sVar3);
  uVar4 = DAT_00c402;
  *(ushort *)(uint3)uVar4 = *(ushort *)(uint3)uVar4 | 5 << sVar3;
  cc_irq_enable_bit(bVar1);
  return;
}



/* ===== c0dc62 event_cancel size=40 ===== */

void event_cancel(byte param_1)

{
  short sVar1;
  
  sVar1 = (ushort)param_1 * 0x12;
  *(undefined2 *)(uint3)(ushort)((short)&DAT_00c416 + sVar1) = 0;
  *(undefined2 *)(uint3)(ushort)((short)&DAT_00c418 + sVar1) = 0;
  *(undefined1 *)(uint3)(ushort)((short)&UNK_00c41c + sVar1) = 0;
  event_idle(param_1);
  return;
}



/* ===== c0dc8a event_schedule size=428 ===== */

void event_schedule(byte param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort *puVar4;
  short *psVar5;
  ushort uVar6;
  short sVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  short sVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  
  sVar7 = (ushort)param_1 * 0x12;
  uVar3 = (short)&UNK_00c41c + sVar7;
  puVar4 = (ushort *)((short)&UNK_00c41e + sVar7);
  uVar10 = (ushort)*(byte *)(uint3)(ushort)((short)&UNK_00c41d + sVar7);
  *(byte *)(uint3)uVar3 = *(byte *)(uint3)uVar3 & 0xe3;
  uVar2 = DAT_00c3fc;
  uVar13 = *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar4);
  uVar1 = *(undefined2 *)(uint3)uVar2;
  cc_compare_mode_set(param_1);
  uVar12 = uVar13;
  if (((*(byte *)(uint3)uVar3 & 1) == 0) ||
     (((*(byte *)(uint3)uVar3 & 4) == 0 &&
      (uVar12 = uVar1, (**(ushort **)(uint3)(ushort)((short)&UNK_00c420 + sVar7) & 0x80) == 0)))) {
    *(undefined2 *)(uint3)*(ushort *)ZEXT23(puVar4) = uVar1;
    uVar13 = uVar12;
  }
  uVar2 = *(ushort *)(uint3)(ushort)((short)&UNK_00c420 + sVar7);
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xff7f;
  *(byte *)(uint3)uVar3 = *(byte *)(uint3)uVar3 | 0x20;
  if ((*(byte *)(uint3)uVar3 & 1) == 0) {
    if ((*(byte *)(uint3)uVar3 & 2) == 0) {
      event_schedule_duration(param_1);
    }
    else {
      uVar2 = DAT_00c3fc;
      psVar5 = (short *)((short)&UNK_00c41a + sVar7);
      uVar3 = (*(short *)(uint3)uVar2 - *psVar5) + 10;
      uVar6 = DAT_00c406;
      uVar8 = DAT_00c406;
      if (uVar3 == uVar8 || uVar3 < uVar6) {
        sVar7 = DAT_00c406;
        *(short *)(uint3)*(ushort *)ZEXT23(puVar4) = *(short *)ZEXT23(psVar5) + sVar7;
      }
      else {
        *(short *)(uint3)*(ushort *)ZEXT23(puVar4) = *(short *)(uint3)uVar2 + 10;
      }
      uVar3 = DAT_00c402;
      sVar7 = (uVar10 & 0xf) << 2;
      *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & ~(0xf << sVar7);
      uVar3 = DAT_00c402;
      *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 | 4 << sVar7;
      cc_irq_enable_bit(uVar10);
    }
  }
  else {
    event_accum(param_1,uVar13);
    uVar2 = (short)&UNK_00c412 + sVar7;
    *(byte *)(uint3)uVar3 = *(byte *)(uint3)uVar3 & 0xfe;
    uVar6 = *(ushort *)(uint3)uVar2 | *(ushort *)(uint3)(ushort)((short)&UNK_00c414 + sVar7);
    if (uVar6 == 0) {
      event_idle(param_1);
    }
    else {
      sVar11 = t7_timestamp_extended(uVar6);
      uVar2 = *(ushort *)(uint3)uVar2;
      uVar9 = DAT_00c408;
      uVar6 = uVar2 + uVar9;
      uVar8 = DAT_00c406;
      if ((uVar6 + uVar8 >> 8 |
          (*(short *)(uint3)(ushort)((short)&UNK_00c414 + sVar7) + (ushort)CARRY2(uVar2,uVar9) +
          (ushort)CARRY2(uVar6,uVar8)) * 0x100) <
          (ushort)(*(short *)(uint3)(ushort)((short)&UNK_00c410 + sVar7) - sVar11)) {
        uVar2 = DAT_00c3fc;
        sVar7 = DAT_00c406;
        *(short *)(uint3)*puVar4 = *(short *)(uint3)uVar2 + sVar7;
        uVar2 = DAT_00c402;
        sVar7 = (uVar10 & 0xf) << 2;
        *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & ~(0xf << sVar7);
        uVar2 = DAT_00c402;
        *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 | 4 << sVar7;
        cc_irq_enable_bit(uVar10,0);
        *(byte *)(uint3)uVar3 = *(byte *)(uint3)uVar3 | 2;
      }
      else {
        event_force(param_1);
        *(byte *)(uint3)uVar3 = *(byte *)(uint3)uVar3 | 0x40;
      }
    }
  }
  return;
}



/* ===== c0df4c FUN_c0df4c size=618 ===== */

void FUN_c0df4c(byte param_1)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short sVar7;
  short *psVar8;
  short sVar9;
  ushort uVar10;
  ushort uVar11;
  
  sVar7 = (ushort)param_1 * 0x12;
  uVar10 = (short)&UNK_00c41c + sVar7;
  if ((*(byte *)(uint3)uVar10 & 0x20) == 0) {
    return;
  }
  if ((*(byte *)(uint3)uVar10 & 4) == 0) {
    if ((*(byte *)(uint3)uVar10 & 3) == 0) {
      if ((*(byte *)(uint3)uVar10 & 0x40) == 0) {
        *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 | 0x80;
        sVar9 = DAT_00c408;
        *(short *)(uint3)(ushort)((short)&UNK_00c41a + sVar7) =
             **(short **)(uint3)(ushort)((short)&UNK_00c41e + sVar7) + sVar9;
      }
      else {
        *(undefined2 *)(uint3)(ushort)((short)&UNK_00c41a + sVar7) =
             **(undefined2 **)(uint3)(ushort)((short)&UNK_00c41e + sVar7);
      }
      *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 | 1;
      if ((*(byte *)(uint3)uVar10 & 8) == 0) {
        if ((*(byte *)(uint3)uVar10 & 0x40) == 0) {
          uVar10 = *(ushort *)(uint3)(ushort)((short)&UNK_00c412 + sVar7);
          uVar11 = DAT_00c408;
          sVar9 = uVar10 + uVar11;
          uVar11 = *(short *)(uint3)(ushort)((short)&UNK_00c414 + sVar7) +
                   (ushort)CARRY2(uVar10,uVar11) & 0xff;
        }
        else {
          sVar9 = *(short *)(uint3)(ushort)((short)&UNK_00c412 + sVar7);
          uVar11 = *(ushort *)(uint3)(ushort)((short)&UNK_00c414 + sVar7);
          *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 & 0xbf;
        }
      }
      else {
        uVar5 = (short)&UNK_00c412 + sVar7;
        uVar6 = (short)&DAT_00c416 + sVar7;
        uVar10 = *(ushort *)(uint3)uVar5;
        uVar1 = *(ushort *)(uint3)(ushort)((short)&UNK_00c414 + sVar7);
        uVar11 = *(ushort *)(uint3)uVar6;
        uVar2 = *(ushort *)(uint3)(ushort)((short)&DAT_00c418 + sVar7);
        if (uVar1 - uVar2 == (ushort)(uVar10 < uVar11) && uVar10 == uVar11 ||
            (uVar1 < uVar2 || uVar1 == uVar2 && uVar10 < uVar11)) {
          sVar9 = DAT_00c408;
          uVar11 = 0;
        }
        else {
          uVar10 = *(ushort *)(uint3)uVar5;
          uVar11 = *(ushort *)(uint3)uVar6;
          uVar1 = uVar10 - uVar11;
          uVar2 = DAT_00c408;
          sVar9 = uVar1 + uVar2;
          uVar11 = ((*(short *)(uint3)(ushort)((short)&UNK_00c414 + sVar7) -
                    *(short *)(uint3)(ushort)((short)&DAT_00c418 + sVar7)) -
                   (ushort)(uVar10 < uVar11)) + (ushort)CARRY2(uVar1,uVar2) & 0xff;
        }
      }
      FUN_c0e3da(param_1,sVar9,uVar11);
      return;
    }
    bVar3 = *(byte *)(uint3)(ushort)((short)&UNK_00c41d + sVar7);
    if ((*(byte *)(uint3)uVar10 & 2) == 0) {
      event_accum(param_1,**(undefined2 **)(uint3)(ushort)((short)&UNK_00c41e + sVar7));
      psVar8 = (short *)DAT_00c3fc;
      sVar9 = DAT_00c406;
      sVar9 = *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar7) + sVar9;
      if ((((short)&UNK_00fff6 + sVar9) - *psVar8 & 0x8000U) == 0) {
        *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar7) = sVar9;
      }
      else {
        uVar11 = DAT_00c3fc;
        *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar7) =
             *(short *)(uint3)uVar11 + 10;
      }
      uVar11 = DAT_00c402;
      sVar7 = (bVar3 & 0xf) << 2;
      *(ushort *)(uint3)uVar11 = *(ushort *)(uint3)uVar11 & ~(0xf << sVar7);
      uVar11 = DAT_00c402;
      *(ushort *)(uint3)uVar11 = *(ushort *)(uint3)uVar11 | 4 << sVar7;
      cc_irq_enable_bit(bVar3);
      if ((*(byte *)(uint3)uVar10 & 8) == 0) {
        *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 | 8;
      }
      else {
        *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 | 0x10;
      }
      if ((DAT_c07d06 == 0) || (param_1 + 1 == (ushort)DAT_c07d06)) {
        sVar9 = div32u();
        sVar7 = DAT_00c3a4;
        DAT_00c3a4 = sVar7 + sVar9;
      }
      *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 | 2;
      *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 & 0xfe;
      return;
    }
    *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 & 0xfd;
  }
  else if ((*(byte *)(uint3)uVar10 & 1) != 0) {
    event_accum(param_1,**(undefined2 **)(uint3)(ushort)((short)&UNK_00c41e + sVar7));
    uVar11 = 0;
    if ((*(byte *)(uint3)uVar10 & 0x80) != 0) {
      uVar11 = *(short *)(uint3)(ushort)((short)&UNK_00c41a + sVar7) -
               **(short **)(uint3)(ushort)((short)&UNK_00c41e + sVar7);
    }
    uVar6 = (short)&DAT_00c416 + sVar7;
    uVar4 = (short)&UNK_00c412 + sVar7;
    uVar10 = *(ushort *)(uint3)uVar6;
    uVar2 = *(ushort *)(uint3)(ushort)((short)&DAT_00c418 + sVar7);
    uVar1 = *(ushort *)(uint3)uVar4;
    uVar5 = *(ushort *)(uint3)(ushort)((short)&UNK_00c414 + sVar7);
    if (uVar2 - uVar5 == (ushort)(uVar10 < uVar1) && uVar10 == uVar1 ||
        (uVar2 < uVar5 || uVar2 == uVar5 && uVar10 < uVar1)) {
      uVar1 = *(ushort *)(uint3)uVar4;
      uVar2 = *(ushort *)(uint3)uVar6;
      uVar5 = uVar1 - uVar2;
      uVar10 = uVar5 + uVar11;
      uVar11 = ((*(short *)(uint3)(ushort)((short)&UNK_00c414 + sVar7) -
                *(short *)(uint3)(ushort)((short)&DAT_00c418 + sVar7)) - (ushort)(uVar1 < uVar2)) +
               (ushort)CARRY2(uVar5,uVar11) & 0xff;
    }
    else {
      uVar10 = 0x28;
      uVar11 = 0;
    }
    if (uVar11 == uVar10 < 0x28 && uVar10 == 0x28 || uVar11 == 0 && uVar10 < 0x28) {
      FUN_c0e3da(param_1,0x28,0);
      return;
    }
    FUN_c0e3da(param_1,uVar10,uVar11);
    return;
  }
  if ((*(byte *)(uint3)uVar10 & 8) == 0) {
    event_schedule_duration(param_1);
  }
  return;
}



/* ===== c0e1b6 event_idle size=128 ===== */

void event_idle(byte param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  
  sVar3 = (ushort)param_1 * 0x12;
  bVar1 = *(byte *)(uint3)(ushort)((short)&UNK_00c41d + sVar3);
  cc_compare_mode_set(param_1);
  uVar2 = (short)&UNK_00c41c + sVar3;
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xdf;
  uVar5 = DAT_00c3fc;
  *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar3) =
       *(short *)(uint3)uVar5 + 0x7000;
  uVar5 = DAT_00c402;
  sVar4 = (bVar1 & 0xf) << 2;
  *(ushort *)(uint3)uVar5 = *(ushort *)(uint3)uVar5 & ~(0xf << sVar4);
  uVar5 = DAT_00c402;
  *(ushort *)(uint3)uVar5 = *(ushort *)(uint3)uVar5 | 4 << sVar4;
  cc_irq_enable_bit(bVar1);
  *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 4;
  uVar2 = *(ushort *)(uint3)(ushort)((short)&UNK_00c420 + sVar3);
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xff7f;
  return;
}



/* ===== c0e236 event_accum size=70 ===== */

void event_accum(ushort param_1,short param_2)

{
  ushort uVar1;
  short *psVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  
  sVar6 = (param_1 & 0xff) * 0x12;
  psVar2 = (short *)((short)&UNK_00c41a + sVar6);
  uVar5 = param_2 - *psVar2;
  if (uVar5 < 0x7f01) {
    uVar3 = (short)&DAT_00c416 + sVar6;
    uVar1 = *(ushort *)(uint3)uVar3;
    *(ushort *)(uint3)(ushort)((short)&DAT_00c418 + sVar6) =
         *(short *)(uint3)(ushort)((short)&DAT_00c418 + sVar6) + (ushort)CARRY2(uVar1,uVar5);
    uVar4 = (short)&UNK_00c41c + sVar6;
    *(ushort *)(uint3)uVar3 = uVar1 + uVar5;
    *(short *)ZEXT23(psVar2) = param_2;
    *(byte *)(uint3)uVar4 = *(byte *)(uint3)uVar4 & 0x7f;
  }
  return;
}



/* ===== c0e27c event_schedule_duration size=350 ===== */

void event_schedule_duration(byte param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short sVar7;
  short sVar8;
  ushort uVar9;
  ushort uVar10;
  
  sVar7 = (ushort)param_1 * 0x12;
  uVar2 = (short)&UNK_00c412 + sVar7;
  uVar3 = (short)&UNK_00c41d + sVar7;
  bVar1 = *(byte *)(uint3)uVar3;
  uVar9 = *(ushort *)(uint3)uVar2 | *(ushort *)(uint3)(ushort)((short)&UNK_00c414 + sVar7);
  if (uVar9 == 0) {
    event_idle(param_1);
  }
  else {
    sVar8 = t7_timestamp_extended(uVar9);
    uVar5 = *(short *)(uint3)(ushort)((short)&UNK_00c410 + sVar7) - sVar8;
    uVar2 = *(ushort *)(uint3)uVar2;
    uVar10 = DAT_00c408;
    uVar9 = uVar2 + uVar10;
    uVar10 = *(short *)(uint3)(ushort)((short)&UNK_00c414 + sVar7) + (ushort)CARRY2(uVar2,uVar10);
    uVar2 = (short)&UNK_00c41c + sVar7;
    if ((*(byte *)(uint3)uVar2 & 8) == 0) {
      uVar4 = uVar9 >> 8 | uVar10 * 0x100;
      uVar6 = DAT_00c40c;
      uVar9 = uVar6 + uVar4;
      uVar10 = (uVar10 >> 8) + (ushort)CARRY2(uVar6,uVar4);
    }
    else {
      uVar4 = *(ushort *)(uint3)(ushort)((short)&DAT_00c416 + sVar7);
      uVar6 = (uVar10 - *(short *)(uint3)(ushort)((short)&DAT_00c418 + sVar7)) -
              (ushort)(uVar9 < uVar4);
      uVar10 = uVar9 - uVar4 >> 8 | uVar6 * 0x100;
      uVar4 = DAT_00c400;
      uVar9 = uVar4 + uVar10;
      uVar10 = (uVar6 >> 8) + (ushort)CARRY2(uVar4,uVar10);
    }
    if ((uVar10 != (uVar9 != 0xffff) || uVar9 != 0xffff) && (uVar10 != 0 || uVar9 == 0xffff)) {
      uVar9 = 0xffff;
      uVar10 = 0;
    }
    if (uVar9 < uVar5) {
      uVar5 = uVar5 - uVar9;
      if (0x7f < uVar5) {
        uVar3 = DAT_00c3fc;
        *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar7) =
             *(short *)(uint3)uVar3 + 0x7000;
        uVar3 = DAT_00c402;
        sVar7 = (bVar1 & 0xf) << 2;
        *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & ~(0xf << sVar7);
        uVar3 = DAT_00c402;
        *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 | 4 << sVar7;
        cc_irq_enable_bit(bVar1);
        *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 4;
        return;
      }
      bVar1 = *(byte *)(uint3)uVar3;
      uVar3 = DAT_00c3fc;
      *(ushort *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar7) =
           *(short *)(uint3)uVar3 + uVar5 * 0x100;
      uVar3 = DAT_00c402;
      sVar7 = (bVar1 & 0xf) << 2;
      *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & ~(0xf << sVar7);
      uVar3 = DAT_00c402;
      *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 | 5 << sVar7;
      cc_irq_enable_bit(bVar1);
    }
    else {
      event_force(param_1,uVar10);
    }
    *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xfb;
  }
  return;
}



/* ===== c0e3da FUN_c0e3da size=230 ===== */

void FUN_c0e3da(ushort param_1,ushort param_2,ushort param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort *puVar3;
  short sVar4;
  short sVar5;
  short *psVar6;
  
  sVar4 = (param_1 & 0xff) * 0x12;
  uVar2 = (short)&UNK_00c41d + sVar4;
  bVar1 = *(byte *)(uint3)uVar2;
  if (param_3 == param_2 < 0x7f00 && param_2 == 0x7f00 || param_3 == 0 && param_2 < 0x7f00) {
    bVar1 = *(byte *)(uint3)uVar2;
    puVar3 = (ushort *)((short)&UNK_00c41e + sVar4);
    psVar6 = (short *)DAT_00c3fc;
    if ((((short)&UNK_00fff6 + **(short **)ZEXT23(puVar3) + param_2) - *psVar6 & 0x8000) == 0) {
      *(ushort *)(uint3)*puVar3 = **(short **)ZEXT23(puVar3) + param_2;
    }
    else {
      uVar2 = DAT_00c3fc;
      *(short *)(uint3)*puVar3 = *(short *)(uint3)uVar2 + 10;
    }
    uVar2 = DAT_00c402;
    sVar5 = (bVar1 & 0xf) << 2;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & ~(0xf << sVar5);
    uVar2 = DAT_00c402;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 | 5 << sVar5;
    cc_irq_enable_bit(bVar1);
    uVar2 = (short)&UNK_00c41c + sVar4;
    *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 & 0xfb;
  }
  else {
    puVar3 = (ushort *)((short)&UNK_00c41e + sVar4);
    *(short *)(uint3)*puVar3 = **(short **)ZEXT23(puVar3) + 0x7000;
    uVar2 = DAT_00c402;
    sVar5 = (bVar1 & 0xf) << 2;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & ~(0xf << sVar5);
    uVar2 = DAT_00c402;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 | 4 << sVar5;
    cc_irq_enable_bit(bVar1);
    uVar2 = (short)&UNK_00c41c + sVar4;
    *(byte *)(uint3)uVar2 = *(byte *)(uint3)uVar2 | 4;
  }
  return;
}



/* ===== c0e4c0 gap_c0e4c0 size=38 ===== */

undefined2 gap_c0e4c0(ushort param_1)

{
  short sVar1;
  undefined2 uVar2;
  
  uVar2 = 0;
  sVar1 = Ram00c3fa;
  if ((sVar1 != -0x6010) &&
     ((*(byte *)(uint3)((short)&UNK_00c41c + (param_1 & 0xff) * 0x12) & 8) != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== c0e606 FUN_c0e606 size=38 ===== */

ushort FUN_c0e606(ushort param_1)

{
  return (ushort)((uint)param_1 * (uint)DAT_c05060) >> 7 |
         (short)((uint)param_1 * (uint)DAT_c05060 >> 0x10) << 9;
}



/* ===== c0e62c FUN_c0e62c size=38 ===== */

ushort FUN_c0e62c(ushort param_1)

{
  return (ushort)((uint)param_1 * (uint)DAT_c05061) >> 7 |
         (short)((uint)param_1 * (uint)DAT_c05061 >> 0x10) << 9;
}



/* ===== c0e652 FUN_c0e652 size=26 ===== */

void FUN_c0e652(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00c474;
  DAT_00c452 = uVar1;
  uVar1 = DAT_00c464;
  DAT_00c45a = uVar1;
  uVar1 = DAT_00c44a;
  DAT_00c472 = uVar1;
  return;
}



/* ===== c0e6b0 FUN_c0e6b0 size=114 ===== */

void FUN_c0e6b0(short param_1)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  if (param_1 == 0) {
    uVar3 = (ushort)&DAT_00fd08;
  }
  else {
    uVar3 = (ushort)&DAT_00fd06;
  }
  uVar2 = DAT_00c474;
  uVar2 = FUN_c0e606(uVar2);
  DAT_00c464 = uVar2;
  uVar2 = DAT_00c474;
  uVar2 = FUN_c0e62c(uVar2);
  DAT_00c44a = uVar2;
  FUN_c0e652();
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xf0ff;
  sVar1 = DAT_00c454;
  if (sVar1 == 0) {
    *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xf7ff | 0x800;
  }
  else if (sVar1 == 1) {
    *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfbff | 0x400;
  }
  else if (sVar1 == 2) {
    *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfdff | 0x200;
  }
  else if (sVar1 == 3) {
    *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfeff | 0x100;
  }
  return;
}



/* ===== c0e722 cc22_23_hysteresis_a size=62 ===== */

void cc22_23_hysteresis_a(ushort param_1)

{
  short sVar1;
  
  sVar1 = DAT_00c450;
  if (sVar1 == 0) {
    if (param_1 < 0x6901) {
      return;
    }
  }
  else {
    if (sVar1 == 1) {
      if (param_1 < 0x6400) {
        DAT_00c450 = 0;
      }
      if (param_1 < 0xa401) {
        return;
      }
      DAT_00c450 = 2;
      return;
    }
    if (sVar1 != 2) {
      return;
    }
    if (0x9fff < param_1) {
      return;
    }
  }
  DAT_00c450 = 1;
  return;
}



/* ===== c0e760 cc22_23_hysteresis_b size=106 ===== */

void cc22_23_hysteresis_b(ushort param_1)

{
  short sVar1;
  
  sVar1 = DAT_00c454;
  if (sVar1 == 0) {
    if (0x1c00 < param_1) {
      DAT_00c454 = 1;
    }
  }
  else if (sVar1 == 1) {
    if (param_1 < 0x1800) {
      DAT_00c454 = 0;
    }
    if ((0x5f00 < param_1) || (sVar1 = DAT_00c450, sVar1 != 0)) {
LAB_c0e7ba:
      DAT_00c454 = 2;
      return;
    }
  }
  else if (sVar1 == 2) {
    if ((param_1 < 0x5a00) && (sVar1 = DAT_00c450, sVar1 == 0)) {
      DAT_00c454 = 1;
    }
    if (0x8400 < param_1) {
      DAT_00c454 = 3;
      return;
    }
  }
  else if ((sVar1 == 3) && (param_1 < 0x8000)) goto LAB_c0e7ba;
  return;
}



/* ===== c0e7ca FUN_c0e7ca size=34 ===== */

void FUN_c0e7ca(short param_1)

{
  *(short *)(uint3)(ushort)((short)&UNK_00c3de + param_1 * 0x1a) =
       0x3480 - (*(short *)(uint3)(ushort)((short)&UNK_00c460 + param_1 * 2) + 0xf00);
  return;
}



/* ===== c0e7ec FUN_c0e7ec size=68 ===== */

/* WARNING: Removing unreachable block (ram,0xc0e820) */

undefined2 FUN_c0e7ec(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = DAT_00c476;
  return (short)(((uint)uVar1 * (uint)param_1) / 0x5a00);
}



/* ===== c0e830 FUN_c0e830 size=100 ===== */

/* WARNING: Removing unreachable block (ram,0xc0e864) */

void FUN_c0e830(short param_1)

{
  ushort uVar1;
  short sVar2;
  undefined1 uVar3;
  short *psVar4;
  
  param_1 = param_1 * 0x1a;
  psVar4 = (short *)((short)&UNK_00c3de + param_1);
  sVar2 = DAT_00c274;
  uVar3 = div32u(*(short *)ZEXT23(psVar4) - sVar2);
  uVar1 = (short)&UNK_00c3d8 + param_1;
  *(undefined1 *)(uint3)uVar1 = uVar3;
  *(ushort *)(uint3)(ushort)((short)&UNK_00c3dc + param_1) =
       *psVar4 + (ushort)*(byte *)(uint3)uVar1 * -0x780;
  return;
}



/* ===== c0e894 FUN_c0e894 size=124 ===== */

/* WARNING: Removing unreachable block (ram,0xc0e8ea) */

ushort FUN_c0e894(ushort param_1,ushort param_2,ushort param_3,ushort unaff_00000000)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  
  uVar2 = DAT_00c266;
  DAT_00c45c = uVar2;
  sVar1 = (param_1 & 0xff) * uVar2 + (short)(((uint)uVar2 * (uint)param_2 & 0x7fff80) / 0x780);
  *(short *)(uint3)unaff_00000000 = sVar1;
  sVar3 = DAT_00c452;
  sVar4 = DAT_00c466;
  *(short *)(uint3)param_3 = (sVar1 - sVar3) + sVar4;
  return (ushort)((uint)uVar2 * (uint)param_2 >> 0x17);
}



/* ===== c0ebe6 cc_output_gate_update size=38 ===== */

void cc_output_gate_update(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd10;
  if (((uVar1 & 4) == 0) && (uVar1 = DAT_00fd1a, (uVar1 & 0x20) != 0)) {
    uVar1 = DAT_00fd08;
    DAT_00fd08 = uVar1 | 0x8000;
  }
  else {
    uVar1 = DAT_00fd08;
    DAT_00fd08 = uVar1 & 0x7fff;
  }
  uVar1 = DAT_00fd0c;
  if (((uVar1 & 4) == 0) && (uVar1 = DAT_00fd1a, (uVar1 & 0x10) != 0)) {
    uVar1 = DAT_00fd06;
    DAT_00fd06 = uVar1 | 0x8000;
    return;
  }
  uVar1 = DAT_00fd06;
  DAT_00fd06 = uVar1 & 0x7fff;
  return;
}



/* ===== c0ecb6 FUN_c0ecb6 size=48 ===== */

short FUN_c0ecb6(short param_1,short param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar1 = param_1 - param_2;
  if (uVar1 < 0x8000) {
    uVar2 = DAT_00c472;
    uVar3 = DAT_00c472;
    if (uVar1 == uVar3 || uVar1 < uVar2) {
      uVar2 = DAT_00c45a;
      if (uVar1 < uVar2) {
        param_1 = DAT_00c45a;
        param_1 = param_2 + param_1;
      }
    }
    else {
      param_1 = DAT_00c472;
      param_1 = param_2 + param_1;
    }
  }
  else {
    param_1 = DAT_00c452;
    param_1 = param_2 + param_1;
  }
  return param_1;
}



/* ===== c0ece6 gap_c0ece6 size=60 ===== */

undefined2 gap_c0ece6(void)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  
  uVar3 = 0;
  sVar2 = Ram00c44e;
  if (sVar2 == 1) {
    uVar1 = Ram00c072;
    if (uRamc0508c < uVar1) {
      uVar1 = DAT_00c266;
      if (uVar1 <= uRamc0508a) {
        return 0;
      }
    }
    else {
      uVar1 = DAT_00c266;
      if (uVar1 <= uRamc05088) {
        return 0;
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* ===== c0ee3c gap_c0ee3c size=268 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c0ee3c(void)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  ushort uVar9;
  
  bVar1 = DAT_00c256;
  uVar9 = (short)&DAT_00c282 + (ushort)bVar1 * 2;
  *(ushort *)(uint3)uVar9 = *(ushort *)(uint3)uVar9 & 0xff7f;
  sVar7 = gap_c0ece6();
  if (sVar7 == 0) {
    sVar7 = cc_irq_is_enabled(_DAT_007048);
    if ((sVar7 == 0) && (uVar9 = DAT_00fd06, (uVar9 & 1) != 0)) {
      uVar3 = DAT_00c27e;
      DAT_00c466 = uVar3;
      DAT_00c3ee = uVar3;
      sVar7 = Ram00c3e4;
      uVar9 = DAT_00fd06;
      if ((uVar9 & 2) == 0) {
        bVar1 = DAT_00c256;
        uVar9 = (short)&DAT_00c284 + (ushort)bVar1 * 2;
        cVar2 = UNK_00c3f2;
        UNK_00c3f2 = cVar2 + -1;
        *(ushort *)(uint3)uVar9 = *(ushort *)(uint3)uVar9 & 0xff7f | 0x80;
        uVar4 = UNK_00c3f2;
        uVar3 = Ram00c3f6;
        FUN_c0e894(1,uVar4,uVar3,(short)&UNK_00c3e4,(short)&DAT_00c3e6);
      }
      else {
        sVar8 = DAT_00c3e6;
        sVar5 = DAT_00c452;
        sVar6 = DAT_00c466;
        Ram00c3e4 = (sVar8 - sVar5) + sVar6;
      }
      sVar8 = Ram00c3e4;
      sVar5 = DAT_00c466;
      uVar9 = sVar8 - sVar5;
      if ((uVar9 & 0x8000) != 0) {
        uVar9 = 0;
      }
      if (((DAT_c05036 == '\0') && (sVar8 = Ram00c462, sVar8 != 0)) &&
         (cVar2 = DAT_00c256, cVar2 == '\x14')) {
        uVar9 = 0;
      }
      sVar8 = DAT_00c45c;
      if (((uVar9 < sVar8 + 0x1eU) && (uVar9 < 0xfff)) || (uVar9 = DAT_00fd06, (uVar9 & 2) != 0)) {
        sVar8 = t7_timestamp();
        if (((0x19 < (ushort)(sVar7 - sVar8)) && ((ushort)(sVar7 - sVar8) < 0x8000)) ||
           (uVar9 = DAT_00fd06, (uVar9 & 4) == 0)) {
          uVar3 = Ram00c3e4;
          FUN_c0f97a(uVar3,1);
        }
      }
    }
  }
  else {
    FUN_c0fa98();
    uVar9 = DAT_00fd06;
    DAT_00fd06 = uVar9 & 0xfffe;
    uVar9 = DAT_00fd06;
    DAT_00fd06 = uVar9 & 0xffdf;
    uVar9 = DAT_00fd06;
    DAT_00fd06 = uVar9 & 0xffef;
    uVar9 = DAT_00fd06;
    DAT_00fd06 = uVar9 & 0xfffb;
  }
  return;
}



/* ===== c0ef4a gap_c0ef4a size=232 ===== */

/* WARNING: Removing unreachable block (ram,0xc0efca) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c0ef4a(void)

{
  ushort uVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  undefined2 uVar6;
  short sVar7;
  
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xffef;
  uVar6 = DAT_00c27e;
  DAT_00c466 = uVar6;
  DAT_00c3d4 = uVar6;
  uVar1 = DAT_00fd08;
  if ((uVar1 & 0x2000) == 0) {
    uVar1 = DAT_00c266;
    uVar4 = Ram00c3dc;
    DAT_00c45c = uVar1;
    DAT_00c3cc = (short)(((uint)uVar4 * (uint)uVar1 & 0x7fff80) / 0x780);
  }
  else {
    uVar6 = Ram00c3dc;
    uVar6 = FUN_c0e7ec(uVar6);
    DAT_00c3cc = uVar6;
  }
  sVar7 = cc_irq_is_enabled(_DAT_007046);
  if ((sVar7 == 1) && (uVar1 = DAT_00fd08, (uVar1 & 0x10) != 0)) {
    sVar3 = DAT_00c3d4;
    sVar7 = DAT_00c3cc;
    FUN_c0fa2a(0);
    sVar5 = DAT_00c44c;
    if (sVar5 == 1) {
      FUN_c0fa2a(sVar3 + sVar7,1);
    }
  }
  uVar1 = DAT_00fd08;
  DAT_00fd08 = uVar1 | 2;
  sVar7 = DAT_00c44c;
  if (sVar7 == 1) {
    uVar6 = Ram00c3ca;
    Ram00c3e4 = uVar6;
    uVar6 = DAT_00c3cc;
    DAT_00c3e6 = uVar6;
    uVar6 = DAT_00c3d4;
    DAT_00c3ee = uVar6;
    uVar1 = DAT_00fd06;
    DAT_00fd06 = uVar1 | 2;
  }
  return;
}



/* ===== c0f032 gap_c0f032 size=180 ===== */

/* WARNING: Removing unreachable block (ram,0xc0f0b2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c0f032(void)

{
  ushort uVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  undefined2 uVar5;
  short sVar6;
  
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xffdf;
  uVar5 = DAT_00c27e;
  DAT_00c466 = uVar5;
  DAT_00c3ee = uVar5;
  uVar1 = DAT_00fd06;
  if ((uVar1 & 0x2000) == 0) {
    uVar1 = DAT_00c266;
    uVar4 = Ram00c3f6;
    DAT_00c45c = uVar1;
    DAT_00c3e6 = (short)(((uint)uVar4 * (uint)uVar1 & 0x7fff80) / 0x780);
  }
  else {
    uVar5 = Ram00c3f6;
    uVar5 = FUN_c0e7ec(uVar5);
    DAT_00c3e6 = uVar5;
  }
  sVar6 = cc_irq_is_enabled(_DAT_007048);
  if ((sVar6 == 1) && (uVar1 = DAT_00fd06, (uVar1 & 0x10) != 0)) {
    sVar3 = DAT_00c3ee;
    sVar6 = DAT_00c3e6;
    FUN_c0fa2a(sVar3 + sVar6,1);
  }
  uVar1 = DAT_00fd06;
  DAT_00fd06 = uVar1 | 2;
  return;
}



/* ===== c0f0e6 FUN_c0f0e6 size=76 ===== */

void FUN_c0f0e6(short param_1,ushort param_2)

{
  ushort uVar1;
  byte bVar2;
  
  if (param_1 == 0) {
    bVar2 = *(byte *)(uint3)((param_2 & 0xff) * 2 + 0x700e);
  }
  else {
    bVar2 = *(byte *)(uint3)((short)&DAT_00c468 + (param_2 & 0xff) * 2);
  }
  uVar1 = (short)&DAT_00c3da + param_1 * 0x1a;
  *(undefined1 *)(uint3)uVar1 = 0;
  if (bVar2 != 0) {
    if (bVar2 < 3) {
      *(byte *)(uint3)uVar1 = bVar2 + 3;
      return;
    }
    if (0x14 < bVar2) {
      *(byte *)(uint3)uVar1 = bVar2 - 0x14;
    }
  }
  return;
}



/* ===== c0f132 FUN_c0f132 size=386 ===== */

void FUN_c0f132(ushort param_1)

{
  short sVar1;
  undefined2 *puVar2;
  ushort uVar3;
  undefined2 uVar4;
  short sVar5;
  short sVar6;
  char cVar7;
  byte bVar8;
  ushort uVar9;
  ushort local_a;
  
  if (param_1 == 0) {
    local_a = DAT_00fd08;
    bVar8 = DAT_00c3d9;
    cVar7 = *(char *)(uint3)((ushort)bVar8 * 2 + 0x700f);
  }
  else {
    local_a = DAT_00fd06;
    bVar8 = DAT_00c3f3;
    cVar7 = *(char *)(uint3)((short)&DAT_00c469 + (ushort)bVar8 * 2);
  }
  sVar5 = cc_irq_is_enabled(*(undefined2 *)(uint3)((short)&DAT_007046 + param_1 * 2));
  if (sVar5 == 0) {
    sVar5 = param_1 * 0x1a;
    uVar9 = (short)&DAT_00c3d9 + sVar5;
    *(char *)(uint3)uVar9 = *(char *)(uint3)uVar9 + '\x01';
    uVar3 = DAT_00c266;
    DAT_00c45c = uVar3;
    if (uVar3 < 0x105) {
      FUN_c0f0e6(param_1,*(undefined1 *)(uint3)uVar9);
      bVar8 = *(byte *)(uint3)((ushort)*(byte *)(uint3)uVar9 * 2 + 0x700f);
      if (bVar8 == 0) {
        bVar8 = 3;
      }
      uVar4 = DAT_00c27e;
      DAT_00c466 = uVar4;
      *(undefined2 *)(uint3)(ushort)((short)&UNK_00c3d6 + sVar5) = uVar4;
      uVar4 = DAT_00c466;
      *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3d4 + sVar5) = uVar4;
      FUN_c0e7ca(param_1);
      FUN_c0e830(param_1);
      uVar9 = (short)&UNK_00c3d8 + sVar5;
      *(char *)(uint3)uVar9 = *(char *)(uint3)uVar9 + cVar7;
      puVar2 = (undefined2 *)((short)&UNK_00c3ca + sVar5);
      sVar1 = *(short *)ZEXT23(puVar2);
      FUN_c0e894(param_1,*(undefined1 *)(uint3)uVar9,
                 *(undefined2 *)(uint3)(ushort)((short)&UNK_00c3dc + sVar5),puVar2,
                 (short)&DAT_00c3cc + sVar5);
      sVar6 = DAT_00c466;
      uVar9 = *(short *)ZEXT23(puVar2) - sVar6;
      if ((uVar9 & 0x8000) != 0) {
        uVar9 = 0;
      }
      uVar3 = DAT_00c45c;
      if (uVar9 < (short)((uint)bVar8 * (uint)uVar3) + 0x1eU) {
        sVar6 = t7_timestamp((short)((uint)bVar8 * (uint)uVar3 >> 0x10));
        if (((0x19 < (ushort)(sVar1 - sVar6)) && ((ushort)(sVar1 - sVar6) < 0x8000)) ||
           ((local_a & 4) == 0)) {
          FUN_c0f97a(*(undefined2 *)ZEXT23(puVar2),param_1);
          sVar1 = DAT_00c44c;
          if (sVar1 == 1) {
            FUN_c0f97a(*(undefined2 *)ZEXT23(puVar2),param_1 ^ 1);
            sVar1 = (param_1 ^ 1) * 0x1a;
            *(undefined2 *)(uint3)((short)&UNK_00c3ca + (param_1 ^ 1) * 0x1a) = *puVar2;
            *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3cc + sVar1) =
                 *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3cc + sVar5);
            *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3d4 + sVar1) =
                 *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3d4 + sVar5);
          }
        }
      }
    }
  }
  else {
    *(undefined1 *)(uint3)((short)&DAT_00c3d9 + param_1 * 0x1a) = 0;
    *(undefined1 *)(uint3)((short)&DAT_00c3da + param_1 * 0x1a) = 0;
  }
  return;
}



/* ===== c0f2b8 gap_c0f2b8 size=116 ===== */

void gap_c0f2b8(void)

{
  undefined2 uVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  
  if (cRamc07468 == '\x01') {
    bVar2 = UNK_00c3b9;
    DAT_00c446 = bVar2 ^ 1;
  }
  else {
    bVar2 = UNK_00c3b9;
    DAT_00c446 = (ushort)bVar2;
  }
  sVar3 = DAT_00c446;
  uVar1 = DAT_00c27e;
  DAT_00c466 = uVar1;
  uVar4 = DAT_00fd08;
  if ((uVar4 & 0x8000) != 0) {
    uVar4 = DAT_00fd0a;
    if (((uVar4 & 2) == 0) || ((uVar4 = DAT_00fd0a, (uVar4 & 2) != 0 && (sVar3 == 0)))) {
      DAT_00c446 = 0;
      FUN_c0e7ca(0);
      uVar1 = DAT_00c466;
      Ram00c3d6 = uVar1;
      func_0xc0eafe();
      func_0xc0e910();
      uVar4 = DAT_00fd08;
      DAT_00fd08 = uVar4 | 1;
      sVar3 = DAT_00c44c;
      if (sVar3 == 1) {
        uVar1 = DAT_00c466;
        Ram00c3f0 = uVar1;
        uVar4 = DAT_00fd06;
        DAT_00fd06 = uVar4 | 1;
        return;
      }
    }
    else {
      uVar4 = DAT_00fd08;
      if ((uVar4 & 0x800) == 0) {
        uVar1 = DAT_00c466;
        Ram00c3d6 = uVar1;
        sVar5 = FUN_c0f482(0);
        sVar3 = DAT_00c44c;
        if (sVar3 == 1) {
          if (sVar5 == 1) {
            uVar1 = Ram00c3ca;
            FUN_c0f97a(uVar1,1);
          }
          uVar1 = Ram00c3ca;
          Ram00c3e4 = uVar1;
          uVar1 = DAT_00c3cc;
          DAT_00c3e6 = uVar1;
          uVar1 = DAT_00c3d4;
          DAT_00c3ee = uVar1;
          uVar1 = Ram00c3d6;
          Ram00c3f0 = uVar1;
        }
      }
    }
  }
  return;
}



/* ===== c0f32c gap_c0f32c size=76 ===== */

void gap_c0f32c(void)

{
  undefined2 uVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  
  uVar3 = DAT_00fd08;
  if ((uVar3 & 0x800) == 0) {
    uVar1 = DAT_00c466;
    Ram00c3d6 = uVar1;
    sVar4 = FUN_c0f482(0);
    sVar2 = DAT_00c44c;
    if (sVar2 == 1) {
      if (sVar4 == 1) {
        uVar1 = Ram00c3ca;
        FUN_c0f97a(uVar1,1);
      }
      uVar1 = Ram00c3ca;
      Ram00c3e4 = uVar1;
      uVar1 = DAT_00c3cc;
      DAT_00c3e6 = uVar1;
      uVar1 = DAT_00c3d4;
      DAT_00c3ee = uVar1;
      uVar1 = Ram00c3d6;
      Ram00c3f0 = uVar1;
    }
  }
  return;
}



/* ===== c0f378 gap_c0f378 size=90 ===== */

void gap_c0f378(void)

{
  undefined2 uVar1;
  byte bVar2;
  ushort uVar3;
  
  bVar2 = UNK_00c3b9;
  DAT_00c446 = (ushort)bVar2;
  uVar1 = DAT_00c27e;
  DAT_00c466 = uVar1;
  uVar3 = DAT_00fd06;
  if ((uVar3 & 0x8000) != 0) {
    uVar3 = DAT_00fd0a;
    if (((uVar3 & 1) == 0) || ((uVar3 = DAT_00fd0a, (uVar3 & 1) != 0 && (bVar2 == 1)))) {
      DAT_00c446 = 1;
      FUN_c0e7ca();
      uVar1 = DAT_00c466;
      Ram00c3f0 = uVar1;
      func_0xc0eafe();
      func_0xc0e910();
      uVar3 = DAT_00fd06;
      DAT_00fd06 = uVar3 | 1;
      return;
    }
    uVar3 = DAT_00fd06;
    if ((uVar3 & 0x800) == 0) {
      uVar1 = DAT_00c466;
      Ram00c3f0 = uVar1;
      FUN_c0f482(1);
    }
  }
  return;
}



/* ===== c0f3d2 cc22_23_task size=164 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cc22_23_task(void)

{
  undefined2 uVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  
  uVar4 = DAT_00c9d0;
  if (uVar4 < 0xc7ff) {
    uVar4 = DAT_00c9d0;
  }
  else {
    uVar4 = 0xc7ff;
  }
  cc22_23_hysteresis_a();
  cc22_23_hysteresis_b((short)(CONCAT22(uVar4 >> 0xb,uVar4 << 5) / 0x19));
  uVar4 = DAT_00fd02;
  if (((uVar4 & 0x400) == 0) && (uVar4 = DAT_00fd02, (uVar4 & 0x80) != 0)) {
    sVar3 = cc_irq_is_enabled(_DAT_007046);
    if (sVar3 == 1) {
      cc22_23_output_disable(0);
      cc_irq_enable(_DAT_007046,0);
      uVar4 = CC23IC;
      CC23IC = uVar4 & 0xffbf;
    }
    sVar3 = cc_irq_is_enabled(_DAT_007048);
    if (sVar3 == 1) {
      cc22_23_output_disable(1);
      cc_irq_enable(_DAT_007048,0);
      uVar4 = CC22IC;
      CC22IC = uVar4 & 0xffbf;
    }
  }
  uVar1 = DAT_00fd02;
  uVar4 = DAT_00fd02;
  uVar2 = DAT_00fd02;
  DAT_00fd02 = uVar2 & 0xff7f | ((uVar4 & 0x400) >> 10) << 7;
  cc_event_timeout_tick();
  return;
}



/* ===== c0f476 FUN_c0f476 size=12 ===== */

void FUN_c0f476(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = DAT_00c45a;
  if (param_1 < uVar1) {
    DAT_00c45a = param_1;
  }
  return;
}



/* ===== c0f482 FUN_c0f482 size=216 ===== */

undefined2 FUN_c0f482(short param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  undefined2 uVar7;
  
  uVar7 = 0;
  FUN_c0e7ca();
  sVar4 = param_1 * 0x1a;
  sVar5 = FUN_c0e7ec(*(undefined2 *)(uint3)(ushort)((short)&UNK_00c3de + sVar4));
  sVar6 = DAT_00c476;
  uVar1 = (short)&DAT_00c3cc + sVar4;
  *(short *)(uint3)uVar1 = sVar6 * 2 + sVar5;
  sVar6 = DAT_00c452;
  uVar3 = *(short *)(uint3)uVar1 - sVar6;
  uVar1 = (short)&UNK_00c3d6 + sVar4;
  uVar2 = (short)&UNK_00c3ca + sVar4;
  *(ushort *)(uint3)uVar2 = *(short *)(uint3)uVar1 + uVar3;
  sVar6 = DAT_00c476;
  if ((uVar3 < sVar6 + 0x1eU) || (0x7fff < uVar3)) {
    sVar6 = t7_timestamp();
    if (0x7fff < (ushort)(*(short *)(uint3)uVar2 - (sVar6 + 0x4b))) {
      sVar6 = t7_timestamp();
      *(short *)(uint3)uVar2 = sVar6 + 0x4b;
      sVar6 = DAT_00c476;
      FUN_c0f476(sVar6 * 2 + -0x4b);
    }
    FUN_c0f97a(*(undefined2 *)(uint3)uVar2,param_1);
    uVar7 = 1;
  }
  *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3d4 + sVar4) = *(undefined2 *)(uint3)uVar1;
  uVar1 = (short)&DAT_00c3d9 + sVar4;
  *(undefined1 *)(uint3)uVar1 = 1;
  sVar4 = DAT_00c44c;
  if ((sVar4 == 1) && (param_1 == 1)) {
    DAT_00c3f3 = 0;
  }
  FUN_c0f0e6(param_1,*(undefined1 *)(uint3)uVar1);
  return uVar7;
}



/* ===== c0f55a FUN_c0f55a size=206 ===== */

void FUN_c0f55a(short param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  FUN_c0e6b0();
  uVar2 = DAT_00c26e;
  DAT_00c458 = uVar2;
  if (param_1 == 0) {
    FUN_c0fa8e(0);
    uVar3 = (ushort)&DAT_00fd08;
    uVar1 = DAT_00fd0a;
    uVar1 = uVar1 >> 1;
  }
  else {
    FUN_c0fa98();
    uVar3 = (ushort)&DAT_00fd06;
    uVar1 = DAT_00fd0a;
  }
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfffd;
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfffe;
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xffdf;
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xffef;
  *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfffb;
  if ((*(ushort *)(uint3)uVar3 & 0x800) == 0) {
    if (((uVar1 & 1) == 0) && ((*(ushort *)(uint3)uVar3 & 0x8000) != 0)) {
      FUN_c0f482(param_1);
      goto LAB_c0f620;
    }
  }
  else if (param_1 == 0) {
    uVar1 = CC23IC;
    CC23IC = uVar1 & 0xffbf;
  }
  else if (param_1 == 1) {
    uVar1 = CC22IC;
    CC22IC = uVar1 & 0xffbf;
  }
  *(undefined1 *)(uint3)(ushort)((short)&DAT_00c3da + param_1 * 0x1a) = 0;
  *(undefined1 *)(uint3)(ushort)((short)&DAT_00c3d9 + param_1 * 0x1a) = 0;
LAB_c0f620:
  FUN_c0fd82();
  return;
}



/* ===== c0f628 config_sensor_setup size=532 ===== */

void config_sensor_setup(void)

{
  ushort uVar1;
  byte bVar2;
  undefined2 in_r1;
  byte bVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  
  uVar5 = PSW;
  PSW = uVar5 & 0xf7ff;
  uVar5 = DAT_00fd0a;
  DAT_00fd0a = uVar5 & 0xfffe;
  uVar5 = DAT_00fd0a;
  DAT_00fd0a = uVar5 & 0xfffd;
  bVar3 = (byte)((ushort)in_r1 >> 8);
  if (DAT_c05036 < 4) {
    DAT_00c23c = 0xd09a;
    DAT_00c23e = 0xc0;
    DAT_00c22c = 0xd07c;
    DAT_00c22e = 0xc0;
    DAT_00c234 = 0xd08e;
    DAT_00c236 = 0xc0;
    DAT_00c220 = 0xd0b2;
    DAT_00c222 = 0xc0;
    uVar5 = DAT_00c28a;
    DAT_00c28a = uVar5 | 4;
    DAT_00c45e = 2;
    DAT_00c238 = 0xd0a0;
    DAT_00c23a = 0xc0;
    DAT_00c228 = 0xd082;
    DAT_00c22a = 0xc0;
    DAT_00c230 = 0xd094;
    DAT_00c232 = 0xc0;
    if (DAT_c05036 == 2) {
      uVar5 = CONCAT11(bVar3,0x5a);
      uVar1 = DAT_00c28a;
      DAT_00c28a = uVar1 | 0x200;
      uVar1 = DAT_00c290;
      DAT_00c290 = uVar1 | 0x200;
      sVar6 = 0x7022;
    }
    else if (DAT_c05036 == 3) {
      uVar5 = CONCAT11(bVar3,0x3c);
      uVar1 = DAT_00c2aa;
      DAT_00c2aa = uVar1 | 0x200;
      uVar1 = DAT_00c28c;
      DAT_00c28c = uVar1 | 0x200;
      sVar6 = 0x7018;
    }
    else if (DAT_c05036 == 0) {
      uVar5 = CONCAT11(bVar3,0xb4);
      uVar1 = DAT_00c28a;
      DAT_00c28a = uVar1 | 0x200;
      uVar1 = DAT_00c296;
      DAT_00c296 = uVar1 | 0x200;
      uVar1 = DAT_00c29c;
      DAT_00c29c = uVar1 | 0x200;
      sVar6 = 0x702c;
    }
    else {
      uVar5 = (ushort)bVar3 << 8;
      sVar6 = 0x700e;
    }
    uVar1 = DAT_00c2a2;
    DAT_00c2a2 = uVar1 | 0x200;
    DAT_00c44c = 0;
    fp_load(CONCAT11((char)(uVar5 >> 8),(char)((uVar5 & 0xff) / 0xf)));
    fp_neg();
    sVar4 = fp_compare();
    if (sVar4 == -1) {
      fp_load();
      fp_neg();
      fp_div_signed();
      fp_copy();
    }
    else {
      fp_neg();
      fp_load();
      fp_div_unsigned();
      fp_copy();
    }
    uVar5 = fp_to_int();
    uVar5 = (short)&DAT_00c282 + (uVar5 & 0xff) * 2;
    bVar3 = 0;
    *(ushort *)(uint3)uVar5 = *(ushort *)(uint3)uVar5 & 0xfff7 | 8;
    do {
      sVar4 = (ushort)bVar3 * 2;
      bVar3 = bVar3 + 1;
      *(undefined1 *)(uint3)(ushort)((short)&DAT_00c468 + sVar4) =
           *(undefined1 *)(uint3)(ushort)(sVar6 + sVar4);
      *(undefined1 *)(uint3)(ushort)((short)&DAT_00c469 + sVar4) =
           *(undefined1 *)(uint3)(ushort)(sVar6 + 1 + sVar4);
    } while (bVar3 < 5);
    for (bVar3 = 0; bVar2 = DAT_00c45e, bVar3 < bVar2; bVar3 = bVar3 + 1) {
      *(undefined1 *)(uint3)((short)&DAT_00c3da + (ushort)bVar3 * 0x1a) = 0;
      *(undefined1 *)(uint3)((short)&DAT_00c3d9 + (ushort)bVar3 * 0x1a) = 0;
    }
    cc22_23_output_init();
    cc_control_ptr_init();
  }
  DAT_00fd08 = 0x4800;
  DAT_00fd06 = 0x4800;
  cc_output_gate_update();
  DAT_00c456 = 0;
  uVar5 = PSW;
  PSW = uVar5 | 0x800;
  return;
}



/* ===== c0f83c gap_c0f83c size=6 ===== */

void gap_c0f83c(void)

{
  func_0xc13f66();
  return;
}



/* ===== c0f842 FUN_c0f842 size=156 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c0f842(void)

{
  undefined2 uVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  short sVar6;
  
  DAT_00fc00 = &stack0x0000;
  uVar4 = DPP0;
  uVar5 = DPP0;
  uVar5 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP2 = 0x303;
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  uVar3 = CC7IC;
  CC7IC = uVar3 & 0xffbf;
  uVar3 = DAT_00fe2a;
  DAT_00fe2a = uVar3 & 0xff7f;
  uVar3 = CC7IC;
  CC7IC = uVar3 | 0x40;
  sVar6 = cc_irq_is_enabled(_DAT_007046,uVar5,uVar4);
  if (sVar6 == 1) {
    sVar6 = FUN_c0faa2(0);
    if (sVar6 != 1) {
      uVar3 = DAT_00fd08;
      DAT_00fd08 = uVar3 | 0x10;
      uVar1 = DAT_00c3d2;
      DAT_00c3ce = uVar1;
      uVar3 = DAT_00fd08;
      if (((uVar3 & 1) == 0) ||
         ((uVar3 = DAT_00fd08, (uVar3 & 0x1000) == 0 && (uVar3 = DAT_00fd08, (uVar3 & 2) == 0)))) {
        sVar6 = DAT_00c3ce;
        sVar2 = DAT_00c472;
        FUN_c0fa2a(sVar6 + sVar2,0);
        uVar3 = DAT_00fd08;
        DAT_00fd08 = uVar3 | 0x20;
      }
      else {
        sVar2 = DAT_00c3d4;
        sVar6 = DAT_00c3cc;
        FUN_c0fa2a(sVar2 + sVar6,0);
      }
    }
  }
  else {
    sVar6 = FUN_c0faf8(0);
    if (sVar6 != 1) {
      uVar1 = DAT_00c3d2;
      DAT_00c3d0 = uVar1;
      FUN_c0f55a(0);
    }
  }
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  DPP2 = uVar5;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar4;
  uVar4 = DPP0;
  uVar4 = DPP0;
  uVar4 = DPP0;
  return;
}



/* ===== c0f8de FUN_c0f8de size=156 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c0f8de(void)

{
  undefined2 uVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  short sVar6;
  
  DAT_00fc00 = &stack0x0000;
  uVar4 = DPP0;
  uVar5 = DPP0;
  uVar5 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  uVar1 = DPP2;
  uVar1 = DPP2;
  DPP2 = 0x303;
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  uVar3 = CC7IC;
  CC7IC = uVar3 & 0xffbf;
  uVar3 = DAT_00fe2a;
  DAT_00fe2a = uVar3 & 0xffbf;
  uVar3 = CC7IC;
  CC7IC = uVar3 | 0x40;
  sVar6 = cc_irq_is_enabled(_DAT_007048,uVar5,uVar4);
  if (sVar6 == 1) {
    sVar6 = FUN_c0faa2(1);
    if (sVar6 != 1) {
      uVar3 = DAT_00fd06;
      DAT_00fd06 = uVar3 | 0x10;
    }
    uVar1 = DAT_00c3ec;
    DAT_00c3e8 = uVar1;
    uVar3 = DAT_00fd06;
    if (((uVar3 & 1) == 0) ||
       ((uVar3 = DAT_00fd06, (uVar3 & 0x1000) == 0 && (uVar3 = DAT_00fd06, (uVar3 & 2) == 0)))) {
      sVar6 = DAT_00c3e8;
      sVar2 = DAT_00c472;
      FUN_c0fa2a(sVar6 + sVar2,1);
      uVar3 = DAT_00fd06;
      DAT_00fd06 = uVar3 | 0x20;
    }
    else {
      sVar2 = DAT_00c3ee;
      sVar6 = DAT_00c3e6;
      FUN_c0fa2a(sVar2 + sVar6,1);
    }
  }
  else {
    sVar6 = FUN_c0faf8(1);
    if (sVar6 != 1) {
      uVar1 = DAT_00c3ec;
      DAT_00c3ea = uVar1;
      FUN_c0f55a(1);
    }
  }
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  DPP2 = uVar5;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar4;
  uVar4 = DPP0;
  uVar4 = DPP0;
  uVar4 = DPP0;
  return;
}



/* ===== c0f97a FUN_c0f97a size=176 ===== */

void FUN_c0f97a(short param_1,short param_2)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  
  sVar2 = FUN_c0fe0c(param_2);
  if (sVar2 != 1) {
    if (param_2 == 0) {
      uVar5 = (ushort)&DAT_00fd08;
    }
    else {
      uVar5 = (ushort)&DAT_00fd06;
    }
    sVar2 = param_2 * 2;
    sVar3 = cc_irq_is_enabled(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + sVar2));
    if ((sVar3 == 0) && ((*(ushort *)(uint3)uVar5 & 0x20) == 0)) {
      sVar3 = DAT_00c458;
      sVar4 = t7_timestamp();
      if ((ushort)((param_1 - sVar3) - sVar4) < 0x8000) {
        cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + sVar2),param_2,
                         param_1 - sVar3);
      }
      else {
        sVar3 = t7_timestamp();
        cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + sVar2),param_2,
                         sVar3 + 0xe);
      }
      if (param_2 == 0) {
        uVar1 = CC23IC;
        CC23IC = uVar1 | 0x40;
      }
      else if (param_2 == 1) {
        uVar1 = CC22IC;
        CC22IC = uVar1 | 0x40;
      }
      *(ushort *)(uint3)uVar5 = *(ushort *)(uint3)uVar5 & 0xfffb | 4;
    }
  }
  return;
}



/* ===== c0fa2a FUN_c0fa2a size=100 ===== */

void FUN_c0fa2a(short param_1,short param_2)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  
  sVar2 = cc_irq_is_enabled(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + param_2 * 2));
  if (sVar2 == 1) {
    sVar2 = DAT_00c458;
    uVar3 = FUN_c0ecb6(param_1 - sVar2,
                       *(undefined2 *)(uint3)(ushort)((short)&DAT_00c3ce + param_2 * 0x1a));
    cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + param_2 * 2),param_2,uVar3)
    ;
    if (param_2 == 0) {
      uVar1 = CC23IC;
      CC23IC = uVar1 | 0x40;
    }
    else if (param_2 == 1) {
      uVar1 = CC22IC;
      CC22IC = uVar1 | 0x40;
    }
  }
  return;
}



/* ===== c0fa8e FUN_c0fa8e size=10 ===== */

void FUN_c0fa8e(void)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar2 = DAT_00fd10;
  if ((uVar2 & 4) == 0) {
    uVar1 = DAT_00fd08;
    uVar3 = DAT_00fd1a;
    uVar2 = DAT_00fd08;
    DAT_00fd08 = uVar2 & 0x7fff | ((uVar3 & 0x20) >> 5) << 0xf;
  }
  return;
}



/* ===== c0fa98 FUN_c0fa98 size=10 ===== */

void FUN_c0fa98(void)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar2 = DAT_00fd0c;
  if ((uVar2 & 4) == 0) {
    uVar1 = DAT_00fd06;
    uVar3 = DAT_00fd1a;
    uVar2 = DAT_00fd06;
    DAT_00fd06 = uVar2 & 0x7fff | ((uVar3 & 0x10) >> 4) << 0xf;
  }
  return;
}



/* ===== c0faa2 FUN_c0faa2 size=44 ===== */

undefined2 FUN_c0faa2(short param_1)

{
  char cVar1;
  undefined2 uVar2;
  
  uVar2 = 0;
  cVar1 = DAT_00c456;
  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    uVar2 = DAT_00c448;
    cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + param_1 * 2),param_1,uVar2)
    ;
    uVar2 = 1;
    cVar1 = DAT_00c456;
    DAT_00c456 = cVar1 + '\x01';
  }
  return uVar2;
}



/* ===== c0face cc22_23_start_pair size=42 ===== */

void cc22_23_start_pair(short param_1,undefined2 param_2)

{
  ushort uVar1;
  
  cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + param_1 * 2),param_1,param_2)
  ;
  if (param_1 == 0) {
    uVar1 = CC23IC;
    CC23IC = uVar1 | 0x40;
    return;
  }
  if (param_1 == 1) {
    uVar1 = CC22IC;
    CC22IC = uVar1 | 0x40;
  }
  return;
}



/* ===== c0faf8 FUN_c0faf8 size=62 ===== */

undefined2 FUN_c0faf8(short param_1)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  
  uVar3 = 0;
  cVar1 = DAT_00c456;
  if ((cVar1 == '\x03') || (cVar1 == '\x04')) {
    if (param_1 == 0) {
      uVar2 = CC23IC;
      CC23IC = uVar2 | 0x40;
    }
    else if (param_1 == 1) {
      uVar2 = CC22IC;
      CC22IC = uVar2 | 0x40;
    }
    uVar3 = 1;
    cVar1 = DAT_00c456;
    DAT_00c456 = cVar1 + '\x01';
  }
  cVar1 = DAT_00c456;
  if (cVar1 == '\x05') {
    DAT_00c456 = 0;
  }
  return uVar3;
}



/* ===== c0fb36 cc22_23_start_once size=56 ===== */

void cc22_23_start_once(void)

{
  char cVar1;
  short sVar2;
  
  cVar1 = DAT_00c456;
  if (cVar1 == '\0') {
    DAT_00c456 = 1;
    p1l1_set();
    sVar2 = t7_timestamp();
    cc22_23_start_pair(0,sVar2);
    cc22_23_start_pair(1,sVar2);
    DAT_c04448 = sVar2 + DAT_c079da;
  }
  return;
}



/* ===== c0fb6e timer6_start size=30 ===== */

void timer6_start(void)

{
  timer6_init();
  ssc_state_reset();
  DAT_00fd12 = 0;
  DAT_00fd10 = 0;
  DAT_00fd0e = 0;
  DAT_00fd0c = 0;
  DAT_00c478 = 0;
  return;
}



/* ===== c0fb8c cc_event_timeout_tick size=64 ===== */

void cc_event_timeout_tick(void)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  
  sVar1 = DAT_00c478;
  DAT_00c478 = sVar1 + 1;
  uVar2 = DAT_00c478;
  if (0xa00 < uVar2) {
    DAT_00c478 = 0;
    cVar3 = DAT_00fd12;
    if ((cVar3 != '\0') && (bVar4 = DAT_00fd12, bVar4 < 0x10)) {
      cVar3 = DAT_00fd12;
      DAT_00fd12 = cVar3 + -1;
    }
    cVar3 = DAT_00fd0e;
    if ((cVar3 != '\0') && (bVar4 = DAT_00fd0e, bVar4 < 0x10)) {
      cVar3 = DAT_00fd0e;
      DAT_00fd0e = cVar3 + -1;
    }
  }
  return;
}



/* ===== c0fbcc FUN_c0fbcc size=118 ===== */

void FUN_c0fbcc(short param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  
  FUN_c0e6b0();
  uVar1 = DAT_00c26e;
  DAT_00c458 = uVar1;
  if (param_1 == 0) {
    uVar2 = (ushort)&DAT_00fd08;
  }
  else {
    uVar2 = (ushort)&DAT_00fd06;
  }
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xfffd;
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xfffe;
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xffdf;
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xffef;
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xfffb;
  *(undefined1 *)(uint3)(ushort)((short)&DAT_00c3da + param_1 * 0x1a) = 0;
  *(undefined1 *)(uint3)(ushort)((short)&DAT_00c3d9 + param_1 * 0x1a) = 0;
  FUN_c0fd82();
  return;
}



/* ===== c0fc42 FUN_c0fc42 size=78 ===== */

void FUN_c0fc42(short param_1)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  undefined2 uVar4;
  
  sVar3 = t7_timestamp();
  sVar1 = *(short *)(uint3)(ushort)((short)&DAT_00c3d2 + param_1 * 0x1a);
  uVar2 = sVar1 - sVar3;
  if ((uVar2 != 1 && sVar1 != sVar3) && (uVar2 < 0x8000)) {
    uVar4 = t7_timestamp();
    cc22_23_schedule(*(undefined2 *)(uint3)(ushort)((short)&DAT_007046 + param_1 * 2),param_1,uVar4)
    ;
    FUN_c0fbcc(param_1);
  }
  if (param_1 == 0) {
    uVar2 = DAT_00fd10;
    DAT_00fd10 = uVar2 | 2;
  }
  else {
    uVar2 = DAT_00fd0c;
    DAT_00fd0c = uVar2 | 2;
  }
  return;
}



/* ===== c0fc90 ssc_state_reset size=22 ===== */

void ssc_state_reset(void)

{
  DAT_00c47e = 0;
  DAT_00c47c = 0;
  DAT_00c480 = 0;
  DAT_00c47b = 0;
  DAT_00c47a = 0;
  return;
}



/* ===== c0fca6 FUN_c0fca6 size=220 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c0fca6(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  short sVar5;
  
  DAT_00fa20 = &stack0x0000;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar3 = DPP2;
  DPP2 = 0x303;
  uVar4 = PSW;
  PSW = uVar4 & 0xf7ff;
  if ((DAT_c06b69 == '\0') && (cVar1 = DAT_00fd0a._0_1_, cVar1 != '\x03')) goto LAB_c0fd72;
  sVar5 = cc_irq_is_enabled(_DAT_007046,uVar3,uVar2);
  if ((sVar5 == 1) && (sVar5 = cc_irq_is_enabled(_DAT_007048,uVar3,uVar2), sVar5 == 1)) {
    sVar5 = DAT_00c47e;
    if (sVar5 == 0) {
      FUN_c0fc42(0);
      FUN_c0fc42(1);
      ssc_state_reset();
      DAT_00c47e = 1;
      goto LAB_c0fd72;
    }
    sVar5 = DAT_00c47e;
    if (sVar5 != 3) goto LAB_c0fd72;
    cVar1 = DAT_00c47a;
    DAT_00c47a = cVar1 + '\x01';
    FUN_c0fc42(0);
  }
  else {
    sVar5 = DAT_00c47e;
    if (sVar5 == 0) {
      sVar5 = cc_irq_is_enabled(_DAT_007046,uVar3,uVar2);
      if (sVar5 == 1) {
        cVar1 = DAT_00fd12;
        DAT_00fd12 = cVar1 + '\x01';
        FUN_c0fc42(0);
      }
      sVar5 = cc_irq_is_enabled(_DAT_007048,uVar3,uVar2);
      if (sVar5 != 1) goto LAB_c0fd72;
      cVar1 = DAT_00fd0e;
      DAT_00fd0e = cVar1 + '\x01';
    }
    else {
      sVar5 = DAT_00c47e;
      if (sVar5 == 2) {
        cVar1 = DAT_00c480;
        DAT_00c480 = cVar1 + '\x01';
        FUN_c0fc42(0);
      }
      sVar5 = DAT_00c47e;
      if (sVar5 != 1) goto LAB_c0fd72;
      cVar1 = DAT_00c47b;
      DAT_00c47b = cVar1 + '\x01';
    }
  }
  FUN_c0fc42(1);
LAB_c0fd72:
  uVar4 = PSW;
  PSW = uVar4 | 0x800;
  DPP2 = uVar3;
  uVar3 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}



/* ===== c0fd82 FUN_c0fd82 size=126 ===== */

void FUN_c0fd82(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  
  bVar1 = DAT_00fd12;
  if (0x10 < bVar1) {
    uVar3 = DAT_00fd10;
    DAT_00fd10 = uVar3 | 4;
  }
  bVar1 = DAT_00fd0e;
  if (0x10 < bVar1) {
    uVar3 = DAT_00fd0c;
    DAT_00fd0c = uVar3 | 4;
  }
  bVar1 = DAT_00c47c;
  if (0x10 < bVar1) {
    sVar2 = DAT_00c47e;
    if (sVar2 == 1) {
      bVar1 = DAT_00c47b;
      if (bVar1 < 8) {
        DAT_00c47e = 2;
      }
      else {
        DAT_00c47e = 0;
        uVar3 = DAT_00fd0c;
        DAT_00fd0c = uVar3 | 4;
      }
    }
    else if (sVar2 == 2) {
      bVar1 = DAT_00c480;
      if (bVar1 < 8) {
        DAT_00c47e = 3;
      }
      else {
        DAT_00c47e = 0;
        uVar3 = DAT_00fd10;
        DAT_00fd10 = uVar3 | 4;
      }
    }
    else {
      if (sVar2 != 3) {
        return;
      }
      bVar1 = DAT_00c47a;
      if (7 < bVar1) {
        uVar3 = DAT_00fd10;
        DAT_00fd10 = uVar3 | 4;
      }
      DAT_00c47e = 0;
    }
    DAT_00c47c = 0;
  }
  return;
}



/* ===== c0fe0c FUN_c0fe0c size=114 ===== */

/* WARNING: Removing unreachable block (ram,0xc0fe22) */
/* WARNING: Removing unreachable block (ram,0xc0fe30) */
/* WARNING: Removing unreachable block (ram,0xc0fe34) */

undefined2 FUN_c0fe0c(short param_1)

{
  short sVar1;
  ushort uVar2;
  
  if (param_1 == 0) {
    uVar2 = DAT_00fd10;
    if ((uVar2 & 4) == 0) {
      sVar1 = DAT_00c47e;
      if (sVar1 != 1) {
        return 0;
      }
    }
    else {
      uVar2 = CC23IC;
      CC23IC = uVar2 & 0xffbf;
    }
  }
  else {
    uVar2 = DAT_00fd0c;
    if ((uVar2 & 4) == 0) {
      sVar1 = DAT_00c47e;
      if (sVar1 != 2) {
        return 0;
      }
    }
    else if (param_1 == 0) {
      uVar2 = CC23IC;
      CC23IC = uVar2 & 0xffbf;
    }
    else if (param_1 == 1) {
      uVar2 = CC22IC;
      CC22IC = uVar2 & 0xffbf;
    }
  }
  return 1;
}



/* ===== c0fe7e ssc_pin_config size=48 ===== */

void ssc_pin_config(void)

{
  ushort uVar1;
  
  ssc_mode_select();
  uVar1 = DAT_00c482;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xf0ff;
  uVar1 = DAT_00c482;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 | 0x400;
  uVar1 = DAT_00c488;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 | 0x400;
  uVar1 = DAT_00c490;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xff7f;
  return;
}



/* ===== c0feae ssc_mode_select size=82 ===== */

void ssc_mode_select(void)

{
  DAT_00c484 = 4;
  DAT_00c48c = 0;
  if (DAT_c06b68 == '\0') {
    DAT_00c48a = 1;
    if (DAT_c05036 == '\x01') {
      DAT_00c48a = 0;
      DAT_00c48c = 1;
      return;
    }
    if (DAT_c05036 == '\x02') {
      DAT_00c484 = 10;
      return;
    }
    if (DAT_c05036 == '\x03') {
      DAT_00c484 = 8;
      return;
    }
  }
  else {
    DAT_00c48a = 0;
  }
  return;
}



/* ===== c0ff00 ssc0_init_app size=40 ===== */

void ssc0_init_app(void)

{
  ushort uVar1;
  
  uVar1 = SSCCON;
  SSCCON = uVar1 & 0x7fff;
  SSCBR = 3;
  uVar1 = P3;
  P3 = uVar1 & 0xdfff;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 | 0x2000;
  SSCCON = 0xc037;
  uVar1 = P3;
  P3 = uVar1 | 0x2000;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfeff;
  uVar1 = P3;
  P3 = uVar1 | 0x200;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x200;
  uVar1 = DP3;
  DP3 = uVar1 | 0x200;
  uVar1 = SSCRIC;
  SSCRIC = uVar1 | 0xd0;
  uVar1 = SSCTIC;
  SSCTIC = uVar1 | 0x80;
  return;
}



/* ===== c0ff28 ssc_send size=12 ===== */

void ssc_send(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = SSCTIC;
  SSCTIC = uVar1 & 0xff7f;
  SSCTB = (ushort)*(byte *)(uint3)param_1;
  return;
}



/* ===== c0ff34 FUN_c0ff34 size=140 ===== */

void FUN_c0ff34(void)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  short sVar4;
  short sVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  byte bVar9;
  
  DAT_00fc20 = &stack0x0000;
  uVar7 = DPP0;
  DPP0 = 0x301;
  uVar8 = DPP2;
  DPP2 = 0x303;
  uVar6 = SSCRB;
  uVar1 = DAT_00c496;
  *(undefined1 *)(uint3)uVar1 = uVar6;
  cVar3 = DAT_00c492;
  DAT_00c492 = cVar3 + -1;
  cVar3 = DAT_00c492;
  if (cVar3 == '\0') {
    uVar1 = P1H;
    P1H = uVar1 | 8;
    bVar9 = 0;
    do {
      uVar2 = (ushort)bVar9;
      uVar1 = (short)&DAT_00c4ac + uVar2;
      bVar9 = bVar9 + 1;
      *(byte *)(uint3)uVar1 = *(byte *)(uint3)uVar1 | *(byte *)(uint3)((short)&DAT_00c4a0 + uVar2);
    } while (bVar9 < 7);
    DAT_00c492 = 7;
    DAT_00c494 = 0xc4b8;
    DAT_00c496 = 0xc4a0;
  }
  else {
    sVar4 = DAT_00c494;
    DAT_00c494 = sVar4 + 1;
    sVar5 = DAT_00c496;
    DAT_00c496 = sVar5 + 1;
    ssc_send(sVar4 + 1,uVar8,uVar7);
  }
  DPP2 = uVar8;
  uVar8 = DPP2;
  uVar8 = DPP2;
  uVar8 = DPP2;
  DPP0 = uVar7;
  uVar7 = DPP0;
  uVar7 = DPP0;
  uVar7 = DPP0;
  return;
}



/* ===== c0ffc0 ssc_rx_start size=30 ===== */

void ssc_rx_start(void)

{
  ushort uVar1;
  
  uVar1 = P1H;
  P1H = uVar1 & 0xfff7;
  DAT_00c492 = 7;
  DAT_00c494 = 0xc4b8;
  DAT_00c496 = 0xc4a0;
  ssc_send();
  return;
}



/* ===== c0ffde app_main size=16 ===== */

void app_main(void)

{
  input_latch();
  app_hw_init();
  app_run(0);
  return;
}



/* ===== c0ffee gap_c0ffee size=6 ===== */

void gap_c0ffee(void)

{
  gap_c13e94();
  return;
}



/* ===== c10000 app_entry size=4 ===== */

/* WARNING: This function may have set the stack pointer */

void app_entry(void)

{
  bool bVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  __disable_watchdog();
  ADDRSEL1 = 0x17;
  ADDRSEL2 = 0x8fbb;
  SYSCON1 = 0;
  SYSCON3 = 0;
  DAT_00ffaa = 0;
  DAT_00f0fa = 0x8000;
  SYSCON = 0xc1;
  __atomic(3);
  SP = 0xfc00;
  STKOV = 0xfada;
  STKUN = 0xfc00;
  uVar3 = (ushort)&DAT_00face;
  do {
    *(undefined2 *)(uint3)uVar3 = 0x165;
    bVar1 = uVar3 != (ushort)&UNK_00fbfe;
    uVar3 = uVar3 + 2;
  } while (bVar1);
  uVar2 = DPP0;
  DPP0 = 3;
  uVar3 = 0x2ca;
  do {
    *(undefined2 *)(uint3)uVar3 = 0x167;
    bVar1 = uVar3 != 0x368;
    uVar3 = uVar3 + 2;
  } while (bVar1);
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  DPP1 = 0x302;
  DPP2 = 0x303;
  app_cinit();
  app_main(0,0,0);
  do {
    __idle();
  } while( true );
}



/* ===== c10200 ssc_rx_queue_init size=64 ===== */

void ssc_rx_queue_init(void)

{
  ushort uVar1;
  
  DAT_00c4a8 = 0xffff;
  uVar1 = P1H;
  P1H = uVar1 | 8;
  DAT_00c4be = 0x40;
  DAT_00c4bd = 0;
  DAT_00c4bc = 0;
  DAT_00c4ba._1_1_ = 0x1f;
  DAT_00c4ba._0_1_ = 0xfc;
  DAT_00c4b9 = 0;
  DAT_00c4b8 = 0;
  ssc_rx_start();
  DAT_00c4aa = 0;
  DAT_00c49e = 0;
  DAT_00c4b4 = 0;
  return;
}



/* ===== c10240 empty_stub_3 size=2 ===== */

void empty_stub_3(void)

{
  return;
}



/* ===== c10242 input_debounce_sample size=154 ===== */

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



/* ===== c102dc gap_c102dc size=102 ===== */

void gap_c102dc(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  
  cVar1 = DAT_00c4aa;
  DAT_00c4aa = cVar1 + '\x01';
  bVar2 = DAT_00c4aa;
  if ((bVar2 & 0xf) == 1) {
    uVar3 = P1L;
    P1L = uVar3 & 0xffbf;
    DAT_00c4b4 = 1;
  }
  if ((bVar2 & 0xf) == 5) {
    uVar3 = Ram00c4a4;
    if ((uVar3 & 0x800) == 0) {
      uVar3 = Ram00c4a4;
      Ram00c4a4 = uVar3 & 0xf7ff;
      uVar3 = DAT_00c4ba;
      DAT_00c4ba = uVar3 | 0x200;
    }
    else {
      cVar1 = DAT_00c49e;
      DAT_00c49e = cVar1 + '\x01';
    }
  }
  cVar1 = DAT_00c4aa;
  if (cVar1 == '\x7f') {
    DAT_00c4aa = 0xff;
    bVar2 = DAT_00c49e;
    if (6 < bVar2) {
      uVar3 = DP1L;
      DP1L = uVar3 & 0xffbf;
      uVar3 = P1L;
      P1L = uVar3 | 0x40;
      DAT_00c4b4 = 0x55;
      return;
    }
    DAT_00c4b4 = 0;
  }
  return;
}



/* ===== c10342 ssc_task size=46 ===== */

void ssc_task(void)

{
  char cVar1;
  ushort uVar2;
  
  ssc_rx_start();
  cVar1 = DAT_00c498;
  if (cVar1 == '\0') {
    uVar2 = DAT_00c4ba;
    DAT_00c4ba = uVar2 | 0x200;
    ssc_rx_start();
    empty_stub_3();
    DAT_00c498 = 0x50;
  }
  else {
    cVar1 = DAT_00c498;
    DAT_00c498 = cVar1 + -1;
  }
  input_debounce_sample();
  return;
}



/* ===== c10370 adc_start size=32 ===== */

void adc_start(void)

{
  DAT_00ffbe = 0x9000;
  DAT_00f09c = 0;
  if (DAT_c0506a != 0) {
    P5DIDIS = 0xc47f;
    return;
  }
  P5DIDIS = 0x847f;
  return;
}



/* ===== c10398 gap_c10398 size=40 ===== */

short gap_c10398(ushort param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  uVar1 = DAT_00ffbe;
  DAT_00ffbe = uVar1 & 0xf000 | param_1;
  uVar1 = DAT_00ffbe;
  DAT_00ffbe = uVar1 | 0x80;
  do {
    uVar1 = ADCIC;
  } while ((uVar1 & 0x80) == 0);
  uVar2 = func_0xc10390();
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return (uVar2 & 0xffc) << 4;
}



/* ===== c103c0 port_bus_init size=260 ===== */

void port_bus_init(void)

{
  ushort uVar1;
  
  PICON = 0x80;
  P0H = 0;
  POCON0H = 0;
  DP0H = 0;
  P0L = 0;
  POCON0L = 0;
  DP0L = 0;
  P1H = 4;
  DAT_00f120 = 0;
  POCON1H = 0;
  DP1H = 0x2e;
  P1L = 0;
  DAT_00f130 = 0;
  POCON1L = 0;
  DP1L = 0x71;
  uVar1 = DP1L;
  DP1L = uVar1 | 10;
  uVar1 = DP1L;
  DP1L = uVar1 | 0x40;
  ODP3 = 0;
  P3 = 0;
  DAT_00f126 = 0;
  DAT_00f128 = 0;
  POCON3 = 0;
  DP3 = 0x8040;
  ODP4 = 0;
  P4 = 0;
  DAT_00f12a = 0;
  DAT_00f136 = 0;
  POCON4 = 0;
  DP4 = 0;
  BUSCON4 = 0;
  BUSCON2 = 0;
  DAT_00f138 = 0;
  DAT_00f13a = 3;
  DAT_00f094 = 0;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 & 0xffdf;
  BUSCON3 = 0;
  uVar1 = BUSCON3;
  BUSCON3 = uVar1 | 0x10;
  DAT_00ffb4 = 0;
  POCON20 = 0;
  DAT_00ffb6 = 0;
  uVar1 = P5;
  if ((uVar1 & 0x80) == 0) {
    POCON0H = 0x3333;
    P0H = 0;
    DP0H = 0xff;
    POCON0L = 0x3333;
    P0L = 0;
    DP0L = 0xff;
    uVar1 = P1H;
    P1H = uVar1 & 0x3f;
    uVar1 = DP1H;
    DP1H = uVar1 | 0xc0;
    uVar1 = P3;
    P3 = uVar1 & 0x6fff;
    uVar1 = DP3;
    DP3 = uVar1 | 0x9000;
    POCON4 = 0x3333;
    P4 = 0;
    DP4 = 0xff;
    POCON20 = 0x3333;
    DAT_00ffb4 = 0;
    DAT_00ffb6 = 0xffff;
  }
  return;
}



/* ===== c104c4 farcall_04 size=48 ===== */

void farcall_04(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  DAT_00fc40 = &stack0x0000;
  uVar2 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  DPP0 = 0x301;
  uVar3 = DPP2;
  uVar4 = DPP2;
  uVar4 = DPP2;
  DPP2 = 0x303;
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  __disable_watchdog();
  uVar5 = TFR;
  uVar1 = DAT_00fdfe;
  DAT_00fdfe = uVar1 | uVar5;
  uVar1 = TFR;
  TFR = uVar1 & 0xbfff;
  __software_reset();
  DPP2 = uVar3;
  uVar3 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}



/* ===== c104f4 farcall_06 size=48 ===== */

void farcall_06(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  DAT_00fc40 = &stack0x0000;
  uVar2 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  DPP0 = 0x301;
  uVar3 = DPP2;
  uVar4 = DPP2;
  uVar4 = DPP2;
  DPP2 = 0x303;
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  __disable_watchdog();
  uVar5 = TFR;
  uVar1 = DAT_00fdfe;
  DAT_00fdfe = uVar1 | uVar5;
  uVar1 = TFR;
  TFR = uVar1 & 0xdfff;
  __software_reset();
  DPP2 = uVar3;
  uVar3 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}



/* ===== c10524 farcall_10 size=100 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void farcall_10(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  DAT_00fc40 = &stack0x0000;
  uVar2 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  DPP0 = 0x301;
  uVar3 = DPP2;
  uVar4 = DPP2;
  uVar4 = DPP2;
  DPP2 = 0x303;
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  __disable_watchdog();
  uVar5 = TFR;
  uVar1 = DAT_00fdfe;
  DAT_00fdfe = uVar1 | uVar5;
  uVar1 = TFR;
  if ((uVar1 & 0x80) != 0) {
    uVar1 = TFR;
    TFR = uVar1 & 0xff7f;
  }
  uVar1 = TFR;
  if ((uVar1 & 0x10) != 0) {
    uVar1 = TFR;
    TFR = uVar1 & 0xffef;
    _DAT_fffdfc = _DAT_fffdfc | _DAT_fff000;
    FUN_c10588(uVar3,uVar2);
  }
  uVar1 = TFR;
  if ((uVar1 & 8) != 0) {
    uVar1 = TFR;
    TFR = uVar1 & 0xfff7;
  }
  uVar1 = TFR;
  if ((uVar1 & 4) != 0) {
    uVar1 = TFR;
    TFR = uVar1 & 0xfffb;
  }
  __software_reset();
  DPP2 = uVar3;
  uVar3 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}



/* ===== c10588 FUN_c10588 size=94 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c10588(short param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  undefined2 uVar4;
  
  DAT_00c4c2 = 0x4000;
  DAT_00c4c4 = 0xc0;
  do {
    uVar1 = DAT_00c4c2;
    _DAT_0004c0 = *(undefined2 *)(uVar1 & 0x3fff);
    uVar1 = TFR;
    if ((uVar1 & 0x10) != 0) {
      uVar1 = TFR;
      TFR = uVar1 & 0xffef;
      uVar2 = DAT_00c4c2;
      uVar4 = DAT_00c4c4;
      FUN_c10d8e(uVar2,uVar4,param_1);
    }
    uVar1 = DAT_00c4c2;
    DAT_00c4c2 = uVar1 + 2;
    sVar3 = DAT_00c4c4;
    DAT_00c4c4 = sVar3 + (ushort)(0xfffd < uVar1);
    sVar3 = DAT_00c4c2;
    uVar1 = DAT_00c4c4;
    param_1 = (uVar1 - 0xc1) - (ushort)(sVar3 != -1);
  } while (uVar1 < 0xc1 || uVar1 == 0xc1 && sVar3 != -1);
  return;
}



/* ===== c105e6 farcall_67 size=6 ===== */

void farcall_67(void)

{
  __software_reset();
  return;
}



/* ===== c105ec adc_calibrate size=44 ===== */

void adc_calibrate(void)

{
  ushort uVar1;
  
  can_bus_config();
  uVar1 = DAT_00f1be;
  DAT_00f1be = uVar1 & 0xbfff;
  do {
    uVar1 = DAT_00f110;
  } while ((uVar1 & 0x8000) == 0);
  DAT_00f110 = 0;
  T14 = 0xfc31;
  T14REL = 0xfc31;
  uVar1 = DAT_00f1a0;
  DAT_00f1a0 = uVar1 | 0x54;
  DAT_00f10c = 1;
  uVar1 = DAT_00f110;
  DAT_00f110 = uVar1 | 1;
  return;
}



/* ===== c10618 farcall_93 size=52 ===== */

void farcall_93(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  DAT_00fc60 = &stack0x0000;
  uVar4 = DPP0;
  uVar5 = DPP0;
  uVar5 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  uVar6 = DPP2;
  uVar6 = DPP2;
  DPP2 = 0x303;
  bVar1 = DAT_00c4c6;
  if ((bVar1 & 1) != 0) {
    uVar3 = DAT_00fd14;
    DAT_00fd14 = uVar3 | 4;
  }
  cVar2 = DAT_00c4c6;
  DAT_00c4c6 = cVar2 + '\x01';
  uVar3 = DAT_00f10c;
  if ((uVar3 & 2) != 0) {
    uVar3 = DAT_00f10c;
    DAT_00f10c = uVar3 & 0xfffd;
  }
  DPP2 = uVar5;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar4;
  uVar4 = DPP0;
  uVar4 = DPP0;
  uVar4 = DPP0;
  return;
}



/* ===== c1064c t7_timestamp size=40 ===== */

short t7_timestamp(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  uVar1 = T7;
  if ((uVar1 < 0x8001) && (uVar2 = T7IC, (uVar2 & 0x80) != 0)) {
    sVar3 = DAT_00c4c8;
    sVar3 = (uVar1 >> 3) + sVar3 + 0x2000;
  }
  else {
    sVar3 = DAT_00c4c8;
    sVar3 = (uVar1 >> 3) + sVar3;
  }
  return sVar3;
}



/* ===== c10674 gap_c10674 size=36 ===== */

short gap_c10674(void)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = T7IC;
  if ((uVar2 & 0x80) == 0) {
    uVar2 = T7;
    sVar1 = DAT_00c4c8;
    return (uVar2 >> 3) + sVar1;
  }
  uVar2 = T7;
  sVar1 = DAT_00c4c8;
  return (uVar2 >> 3) + sVar1 + 0x2000;
}



/* ===== c106e6 t7_timestamp_extended size=68 ===== */

short t7_timestamp_extended(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  uVar1 = PSW;
  uVar1 = (uVar1 & 0x800) >> 0xb;
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  uVar2 = T7;
  sVar3 = DAT_00c4ca;
  sVar3 = (uVar2 >> 8) + sVar3;
  uVar2 = T7IC;
  if ((uVar2 & 0x80) != 0) {
    sVar3 = DAT_00c4ca;
    uVar2 = T7;
    sVar3 = sVar3 + 0x100 + (uVar2 >> 8);
  }
  if (uVar1 == 1) {
    uVar1 = PSW;
    PSW = uVar1 | 0x800;
  }
  else if (uVar1 == 0) {
    uVar1 = PSW;
    PSW = uVar1 & 0xf7ff;
  }
  return sVar3;
}



/* ===== c1072a timer8_init size=76 ===== */

void timer8_init(void)

{
  ushort uVar1;
  
  uVar1 = T78CON;
  T78CON = uVar1 & 0xff | 0x500;
  T8 = 0;
  T8REL = 0;
  uVar1 = T8IC;
  T8IC = uVar1 | 0xe9;
  if ((DAT_c05068 == 0) || (DAT_c05068 == 4)) {
    CC21 = 0;
    uVar1 = CCM5;
    CCM5 = uVar1 & 0xff8f;
    uVar1 = CCM5;
    CCM5 = uVar1 | 0x30;
    uVar1 = CCM5;
    CCM5 = uVar1 | 0x80;
    uVar1 = CC21IC;
    CC21IC = uVar1 | 0xe0;
  }
  uVar1 = T78CON;
  T78CON = uVar1 | 0x4000;
  return;
}



/* ===== c10776 farcall_62 size=22 ===== */

void farcall_62(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  uVar2 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  DPP0 = 0x301;
  uVar3 = DPP2;
  uVar4 = DPP2;
  uVar4 = DPP2;
  DPP2 = 0x303;
  cVar1 = DAT_00c4da;
  DAT_00c4da = cVar1 + '\x01';
  DPP2 = uVar3;
  uVar3 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  return;
}



/* ===== c1078c farcall_53 size=296 ===== */

void farcall_53(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  ushort uVar8;
  ushort uVar9;
  short sVar10;
  short sVar11;
  byte local_12;
  
  DAT_00fc80 = &stack0x0000;
  uVar5 = DPP0;
  DPP0 = 0x301;
  uVar6 = DPP2;
  DPP2 = 0x303;
  uVar9 = PSW;
  PSW = uVar9 & 0xf7ff;
  uVar8 = CC21;
  local_12 = DAT_00c4da;
  uVar9 = T8;
  uVar1 = T8IC;
  if (((uVar1 & 0x80) == 0) && (uVar9 < uVar8)) {
    local_12 = local_12 - 1;
  }
  uVar9 = (ushort)local_12;
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  if ((DAT_c05068 != 0) && (DAT_c05068 != 4)) goto LAB_c108a4;
  DAT_00c4cc = 0;
  uVar1 = BUSCON2;
  if ((uVar1 & 0x20) == 0) {
    DAT_00c4ce = uVar8;
    DAT_00c4d0 = uVar9;
    goto LAB_c108a4;
  }
  uVar1 = BUSCON2;
  if ((uVar1 & 0x20) == 0) goto LAB_c108a4;
  uVar1 = DAT_00c4d6;
  uVar2 = DAT_00c4d8;
  if (uVar9 - uVar2 == (ushort)(uVar8 < uVar1) && uVar8 == uVar1 ||
      (uVar9 < uVar2 || uVar9 == uVar2 && uVar8 < uVar1)) {
    sVar11 = DAT_00c4d6;
    uVar1 = -sVar11 - 1;
    sVar11 = DAT_00c4d8;
    DAT_00c4d2 = uVar8 + uVar1;
    DAT_00c4d4 = uVar9 + (0xff - sVar11) + (ushort)CARRY2(uVar8,uVar1);
    uVar2 = DAT_00c4ce;
    uVar3 = DAT_00c4d0;
    if (uVar9 < uVar3 || uVar9 == uVar3 && uVar8 < uVar2) goto LAB_c10860;
    uVar2 = DAT_00c4ce;
    sVar10 = uVar1 + uVar2;
    sVar4 = DAT_00c4d0;
    sVar11 = (0xff - sVar11) + sVar4 + (ushort)CARRY2(uVar1,uVar2);
  }
  else {
    uVar1 = DAT_00c4d6;
    sVar11 = DAT_00c4d8;
    DAT_00c4d2 = uVar8 - uVar1;
    DAT_00c4d4 = (uVar9 - sVar11) - (ushort)(uVar8 < uVar1);
LAB_c10860:
    uVar1 = DAT_00c4ce;
    sVar11 = DAT_00c4d0;
    uVar2 = DAT_00c4d6;
    sVar10 = uVar1 - uVar2;
    sVar4 = DAT_00c4d8;
    sVar11 = (sVar11 - sVar4) - (ushort)(uVar1 < uVar2);
  }
  mul32(sVar10,sVar11,uVar6,uVar5);
  uVar7 = DAT_00c4d2;
  uVar7 = DAT_00c4d4;
  uVar7 = div32u();
  DAT_00c4dc = uVar7;
  DAT_00c4d6 = uVar8;
  DAT_00c4d8 = uVar9;
LAB_c108a4:
  DPP2 = uVar6;
  uVar6 = DPP2;
  uVar6 = DPP2;
  uVar6 = DPP2;
  DPP0 = uVar5;
  uVar5 = DPP0;
  uVar5 = DPP0;
  uVar5 = DPP0;
  return;
}



/* ===== c108b4 timeout_counter_tick size=26 ===== */

void timeout_counter_tick(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = DAT_00c4cc;
  if (bVar1 < 0x81) {
    cVar2 = DAT_00c4cc;
    DAT_00c4cc = cVar2 + '\x01';
    return;
  }
  DAT_00c4d2 = 0;
  DAT_00c4d4 = 0;
  return;
}



/* ===== c108ce pwm_init size=160 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pwm_init(void)

{
  ushort uVar1;
  
  _DAT_00e892 = 0xf423;
  _DAT_00e8ac = 0x805;
  _DAT_00e8ae = 0x20;
  _DAT_00e8a0 = 0x5780;
  _DAT_00e8a2 = 0x4b00;
  _DAT_00e8a4 = 0;
  _DAT_00e894 = 1;
  _DAT_00e8c6 = 0x110;
  _DAT_00e8a8 = 0;
  _DAT_00e8c4 = 0;
  _DAT_00e8c0 = 0x8014;
  _DAT_00e8ca = 0;
  _DAT_00e8ce = 0;
  _DAT_00e8c2 = 0;
  uVar1 = CC19IC;
  CC19IC = uVar1 | 0x5c;
  uVar1 = CC20IC;
  CC20IC = uVar1 | 0x5d;
  uVar1 = CC18IC;
  CC18IC = uVar1 | 0x5e;
  if (DAT_c05081 == '\x02') {
    uVar1 = DAT_00f130;
    DAT_00f130 = uVar1 | 0x10;
    uVar1 = P1L;
    P1L = uVar1 & 0xffef | 0x10;
    uVar1 = DP1L;
    DP1L = uVar1 & 0xffef | 0x10;
  }
  _DAT_00e8a6 = 0x202;
  return;
}



/* ===== c1096e div32_checked size=52 ===== */

undefined4 div32_checked(short param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != 0) &&
     (uVar2 = div32u(), sVar1 = (short)((uint)uVar2 >> 0x10),
     sVar1 == -1 && (sVar1 != -1 || (short)uVar2 == -1))) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* ===== c109a2 mul_div32 size=24 ===== */

void mul_div32(void)

{
  mul32();
  div32u();
  return;
}



/* ===== c10a3e gap_c10a3e size=18 ===== */

void gap_c10a3e(undefined2 param_1,undefined2 param_2)

{
  func_0xc109ba((short)&UNK_00c4ec,param_1,param_2);
  return;
}



/* ===== c10a50 gap_c10a50 size=18 ===== */

void gap_c10a50(undefined2 param_1,undefined2 param_2)

{
  func_0xc109ba((short)&UNK_00c4f8,param_1,param_2);
  return;
}



/* ===== c10a62 gap_c10a62 size=18 ===== */

void gap_c10a62(undefined2 param_1,undefined2 param_2)

{
  func_0xc109ba((short)&UNK_00c4de,param_1,param_2);
  return;
}



/* ===== c10a74 pwm_period_duty_calc size=106 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pwm_period_duty_calc(undefined2 param_1,undefined2 param_2)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  short sVar6;
  
  uVar3 = _DAT_00e8ac & 0xf;
  uVar5 = 0x4800;
  sVar6 = 0x1e8;
  while (bVar1 = uVar3 != 0, uVar3 = uVar3 - 1, bVar1) {
    uVar5 = uVar5 >> 1 | sVar6 << 0xf;
    sVar6 = sVar6 >> 1;
  }
  uVar4 = div32_checked(uVar5,sVar6,param_1);
  DAT_00c504 = uVar4;
  uVar4 = mul_div32(uVar4,0,param_2);
  DAT_00c4ea = uVar4;
  sVar2 = DAT_00c504;
  sVar6 = DAT_00c4ea;
  if (sVar2 == sVar6) {
    sVar6 = DAT_00c4ea;
    DAT_00c4ea = sVar6 + 1;
  }
  _DAT_00e892 = DAT_00c504;
  _DAT_00e8a2 = DAT_00c4ea;
  _DAT_00e8a6 = _DAT_00e8a6 | 0x40;
  return;
}



/* ===== c10ade gap_c10ade size=10 ===== */

void gap_c10ade(void)

{
  ushort uVar1;
  
  uVar1 = CCM4;
  CCM4 = uVar1 & 0xfff;
  uVar1 = CCM4;
  CCM4 = uVar1 | 0xc000;
  return;
}



/* ===== c10afc pwm_output_enable size=16 ===== */

void pwm_output_enable(void)

{
  ushort uVar1;
  
  __atomic(4);
  uVar1 = DAT_00f130;
  DAT_00f130 = uVar1 | 4;
  uVar1 = P1L;
  P1L = uVar1 | 4;
  __atomic(4);
  uVar1 = DP1L;
  DP1L = uVar1 | 4;
  return;
}



/* ===== c10b0c gap_c10b0c size=50 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c10b0c(void)

{
  short sVar1;
  
  sVar1 = _DAT_00e892;
  _DAT_00e8a4 = div32u();
  if (sVar1 == _DAT_00e8a4) {
    _DAT_00e8a4 = _DAT_00e8a4 + 1;
  }
  _DAT_00e8a6 = _DAT_00e8a6 | 0x40;
  return;
}



/* ===== c10b3e FUN_c10b3e size=252 ===== */

short FUN_c10b3e(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  short in_r4;
  short sVar5;
  
  uVar2 = param_1 + 2;
  if (*(short *)(uint3)uVar2 == 0 && *(short *)(uint3)(param_1 + 4) == 0) {
    *(ushort *)(uint3)param_3 = *(ushort *)(uint3)param_3 & ~param_4;
    return in_r4;
  }
  uVar3 = param_1 + 6;
  sVar1 = *(short *)(uint3)(param_1 + 8);
  if (*(short *)(uint3)uVar3 == 0 && sVar1 == 0) {
    *(ushort *)(uint3)param_3 = *(ushort *)(uint3)param_3 | param_4;
    return sVar1;
  }
  if (*(short *)(uint3)param_1 == 0) {
    sVar1 = *(short *)(uint3)uVar2;
    sVar5 = *(short *)(uint3)(param_1 + 4) - (ushort)(sVar1 != -1);
    if ((sVar5 != 0 || sVar1 != -1) && (*(short *)(uint3)(param_1 + 4) != 0 || sVar1 == -1)) {
      uVar4 = param_1 + 10;
      sVar5 = CONCAT11((char)((ushort)sVar5 >> 8),*(char *)(uint3)uVar4 + -1);
      *(char *)(uint3)uVar4 = *(char *)(uint3)uVar4 + -1;
      if (*(char *)(uint3)uVar4 == '\0') goto LAB_c10c20;
    }
    if ((*(char *)(uint3)(param_1 + 10) < '\0') ||
       (sVar5 = *(short *)(uint3)(param_1 + 4) - (ushort)(*(short *)(uint3)uVar2 != -1),
       *(short *)(uint3)(param_1 + 4) == 0 && *(short *)(uint3)uVar2 != -1)) {
      *(undefined2 *)(uint3)param_1 = 1;
      *(ushort *)(uint3)param_3 = *(ushort *)(uint3)param_3 & ~param_4;
      if (*(short *)(uint3)(param_1 + 8) != 0 || *(short *)(uint3)uVar3 == -1) {
        *(char *)(uint3)(param_1 + 0xb) = (char)*(undefined2 *)(uint3)(param_1 + 8);
        return sVar5;
      }
LAB_c10be8:
      *(short *)(uint3)param_2 = *(short *)(uint3)param_2 + *(short *)(uint3)uVar3;
      return sVar5;
    }
  }
  else {
    sVar1 = *(short *)(uint3)uVar3;
    sVar5 = *(short *)(uint3)(param_1 + 8) - (ushort)(sVar1 != -1);
    if ((sVar5 != 0 || sVar1 != -1) && (*(short *)(uint3)(param_1 + 8) != 0 || sVar1 == -1)) {
      uVar4 = param_1 + 0xb;
      sVar5 = CONCAT11((char)((ushort)sVar5 >> 8),*(char *)(uint3)uVar4 + -1);
      *(char *)(uint3)uVar4 = *(char *)(uint3)uVar4 + -1;
      if (*(char *)(uint3)uVar4 == '\0') goto LAB_c10be8;
    }
    if ((*(char *)(uint3)(param_1 + 0xb) < '\0') ||
       (sVar5 = *(short *)(uint3)(param_1 + 8) - (ushort)(*(short *)(uint3)uVar3 != -1),
       *(short *)(uint3)(param_1 + 8) == 0 && *(short *)(uint3)uVar3 != -1)) {
      *(undefined2 *)(uint3)param_1 = 0;
      *(ushort *)(uint3)param_3 = *(ushort *)(uint3)param_3 | param_4;
      if (*(short *)(uint3)(param_1 + 4) == 0 && *(short *)(uint3)uVar2 != -1) {
LAB_c10c20:
        *(short *)(uint3)param_2 = *(short *)(uint3)param_2 + *(short *)(uint3)uVar2;
        return sVar5;
      }
      *(char *)(uint3)(param_1 + 10) = (char)*(undefined2 *)(uint3)(param_1 + 4);
    }
  }
  return sVar5;
}



/* ===== c10c3a farcall_51 size=60 ===== */

void farcall_51(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  DAT_00fca0 = &stack0x0000;
  uVar1 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x303;
  FUN_c10b3e((short)&UNK_00c4ec,(short)&CC19,(short)&P1L,1,uVar2,uVar1);
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c10c76 farcall_52 size=62 ===== */

void farcall_52(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  DAT_00fca0 = &stack0x0000;
  uVar1 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x303;
  FUN_c10b3e((short)&UNK_00c4f8,(short)&CC20,(short)&BUSCON2,0x10,uVar2,uVar1);
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c10cb4 farcall_50 size=62 ===== */

void farcall_50(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  DAT_00fca0 = &stack0x0000;
  uVar1 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x303;
  FUN_c10b3e((short)&UNK_00c4de,(short)&CC18,(short)&P1L,0x20,uVar2,uVar1);
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c10cf2 FUN_c10cf2 size=14 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c10cf2(void)

{
  _DAT_0000aa = 0xf5;
  FUN_c10d18();
  return;
}



/* ===== c10d00 FUN_c10d00 size=24 ===== */

undefined2 FUN_c10d00(void)

{
  ushort uVar1;
  
  __service_watchdog();
  do {
    uVar1 = DAT_00f000;
  } while ((uVar1 & 1) != 0);
  return 0;
}



/* ===== c10d18 FUN_c10d18 size=24 ===== */

ushort FUN_c10d18(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  uVar1 = DAT_00f000;
  if ((uVar1 & 0x40) != 0) {
    uVar2 = 0x40;
  }
  if ((uVar1 & 0x80) != 0) {
    uVar2 = uVar2 | 0x80;
  }
  return uVar2;
}



/* ===== c10d8e FUN_c10d8e size=112 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c10d8e(ushort param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  FUN_c10cf2();
  uVar1 = PSW;
  uVar1 = (uVar1 & 0x800) >> 0xb;
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  _DAT_0000aa = 0x80;
  _DAT_000054 = 0xaa;
  *(undefined2 *)(uint3)param_1 = 3;
  FUN_c10d00(0xc0);
  if (uVar1 == 1) {
    uVar1 = PSW;
    PSW = uVar1 | 0x800;
  }
  else if (uVar1 == 0) {
    uVar1 = PSW;
    PSW = uVar1 & 0xf7ff;
  }
  FUN_c10d18();
  return;
}



/* ===== c10dfe gap_c10dfe size=70 ===== */

void gap_c10dfe(void)

{
  func_0xc10d30(0,0xc0);
  func_0xc10d30(0x2000,0xc0);
  func_0xc10d30(0x4000,0xc0);
  func_0xc10d30(0x6000,0xc0);
  func_0xc10d30(0x8000,0xc0);
  func_0xc10d30(0,0xc1);
  return;
}



/* ===== c10ed0 gap_c10ed0 size=54 ===== */

undefined4 gap_c10ed0(short param_1,ushort param_2)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  
  uVar2 = 0xaa55;
  sVar3 = 0;
  for (uVar4 = 0; uVar4 < param_2; uVar4 = uVar4 + 1) {
    bVar1 = CARRY2(uVar2,(ushort)*(byte *)(uint3)(param_1 + uVar4));
    uVar2 = uVar2 + *(byte *)(uint3)(param_1 + uVar4);
    sVar3 = sVar3 + (ushort)bVar1;
  }
  return CONCAT22(sVar3,uVar2);
}



/* ===== c10f90 gap_c10f90 size=88 ===== */

ushort gap_c10f90(short param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  
  uVar2 = param_1 + 0x10;
  *(ushort *)(uint3)(param_1 + 0x12) =
       *(short *)(uint3)(param_1 + 0x12) + (ushort)(0xfffe < *(ushort *)(uint3)uVar2);
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 + 1;
  for (uVar6 = 0; uVar6 < 4; uVar6 = uVar6 + 1) {
    uVar5 = *(ushort *)(uint3)uVar2;
    sVar3 = *(short *)(uint3)(param_1 + 0x12);
    sVar4 = uVar6 << 3;
    while (bVar1 = sVar4 != 0, sVar4 = sVar4 + -1, bVar1) {
      uVar5 = uVar5 >> 1 | sVar3 << 0xf;
      sVar3 = sVar3 >> 1;
    }
    *(char *)(uint3)(param_2 + uVar6) = (char)uVar5;
  }
  return uVar6;
}



/* ===== c10fe8 gap_c10fe8 size=118 ===== */

bool gap_c10fe8(short param_1,short param_2,undefined2 param_3)

{
  short sVar1;
  short sVar2;
  
  sVar1 = 0;
  if (*(ushort *)(uint3)(param_1 + 0x2c) <=
      *(short *)(uint3)(*(short *)(uint3)(param_1 + 0x3a) * 8 + 0x7050) - 0x80U) {
    sVar1 = func_0xc10e44(*(undefined2 *)(uint3)(param_1 + 0x32),
                          *(undefined2 *)(uint3)(param_1 + 0x34),param_2,param_3);
    for (sVar2 = 0; sVar2 < 0x80; sVar2 = sVar2 + 1) {
      *(undefined1 *)(uint3)(ushort)(param_2 + sVar2) = 0;
    }
  }
  if (sVar1 == 0) {
    sVar1 = func_0xc10f06(param_1);
  }
  return sVar1 == 0;
}



/* ===== c1105e gap_c1105e size=28 ===== */

void gap_c1105e(short param_1)

{
  short sVar1;
  short sVar2;
  
  sVar2 = *(short *)(uint3)(param_1 + 0x3a) * 8;
  sVar1 = *(short *)(uint3)(sVar2 + 0x7052);
  sVar2 = *(short *)(uint3)(sVar2 + 0x7054);
  *(short *)(uint3)(param_1 + 4) = sVar1 + -1;
  *(ushort *)(uint3)(param_1 + 6) = sVar2 - (ushort)(sVar1 == 0);
  return;
}



/* ===== c1145c gap_c1145c size=110 ===== */

bool gap_c1145c(short param_1)

{
  short sVar1;
  
  func_0xc1128a();
  sVar1 = func_0xc114ca(*(undefined2 *)(uint3)(param_1 + 0x18),
                        *(undefined2 *)(uint3)(param_1 + 0x1a),
                        *(undefined2 *)(uint3)(param_1 + 0x3a));
  if (sVar1 == 0) {
    *(undefined2 *)(uint3)(param_1 + 0x30) = 0;
    *(ushort *)(uint3)(param_1 + 0x32) = *(ushort *)(uint3)(param_1 + 0x18) + 4;
    *(ushort *)(uint3)(param_1 + 0x34) =
         *(short *)(uint3)(param_1 + 0x1a) + (ushort)(0xfffb < *(ushort *)(uint3)(param_1 + 0x18));
    *(undefined2 *)(uint3)(param_1 + 0x36) = 0xaa55;
    *(undefined2 *)(uint3)(param_1 + 0x38) = 0;
    *(undefined2 *)(uint3)(param_1 + 0x2c) = 0;
    *(undefined2 *)(uint3)(param_1 + 0x2e) = 0;
    *(undefined2 *)(uint3)(param_1 + 0x24) =
         *(undefined2 *)(uint3)(*(short *)(uint3)(param_1 + 0x3a) * 8 + 0x7050);
    *(undefined2 *)(uint3)(param_1 + 0x26) = 0;
  }
  return sVar1 == 0;
}



/* ===== c114fc gap_c114fc size=138 ===== */

short gap_c114fc(short param_1)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  char *pcVar5;
  ushort uVar6;
  ushort uVar7;
  short sVar8;
  ushort uVar9;
  
  uVar7 = *(short *)(uint3)(param_1 + 8) + 4;
  uVar2 = param_1 + 0x30;
  sVar8 = 0;
  *(undefined2 *)(uint3)uVar2 = 0;
  uVar3 = param_1 + 0x3c;
  *(short *)(uint3)uVar3 = *(short *)(uint3)uVar2 * 6 + 0x73d0;
  do {
    if ((*(short *)(uint3)uVar3 == 0) || (sVar8 != 0)) {
      return sVar8;
    }
    uVar4 = param_1 + 0x2e;
    uVar9 = *(ushort *)(uint3)*(ushort *)(uint3)uVar3;
    *(undefined2 *)(uint3)uVar4 = *(undefined2 *)(uint3)(*(short *)(uint3)uVar3 + 2);
    uVar6 = uVar7;
    while (uVar7 = uVar6, *(short *)(uint3)uVar4 != 0) {
      uVar7 = uVar6 + 1;
      pcVar5 = (char *)(uint3)uVar9;
      uVar9 = uVar9 + 1;
      if (*(char *)(uint3)uVar6 != *pcVar5) {
        sVar8 = 1;
        break;
      }
      *(short *)(uint3)uVar4 = *(short *)(uint3)uVar4 + -1;
      uVar6 = uVar7;
    }
    sVar1 = *(short *)(uint3)uVar2;
    *(short *)(uint3)uVar2 = sVar1 + 1;
    *(short *)(uint3)uVar3 = (sVar1 + 1) * 6 + 0x73d0;
  } while( true );
}



/* ===== c11662 gap_c11662 size=40 ===== */

void gap_c11662(void)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 0x80; bVar1 = bVar1 + 1) {
    *(undefined1 *)(uint3)bVar1 = 0;
  }
  return;
}



/* ===== c1168a gap_c1168a size=334 ===== */

short gap_c1168a(short param_1)

{
  ushort uVar1;
  byte *pbVar2;
  short sVar3;
  undefined2 uVar4;
  ushort uVar5;
  ushort uVar6;
  undefined2 uVar7;
  short sVar8;
  ushort uVar9;
  byte abStack_6 [2];
  
  sVar8 = 1;
  Ram00c542 = param_1;
  if ((param_1 == 1) && (sVar3 = Ram00c506, sVar3 == 0)) {
    func_0xc1128a((short)&UNK_00c508);
    uVar7 = gap_c114fc((short)&UNK_00c508);
    Ram00c506 = uVar7;
  }
  if ((param_1 == 0) || (sVar3 = Ram00c506, sVar3 == 1)) {
    Ram00c506 = 0;
    sVar8 = gap_c1145c((short)&UNK_00c508);
    if (sVar8 == 1) {
      gap_c11662();
      abStack_6[0] = gap_c10f90((short)&UNK_00c508,0,0xe0);
      Ram00c534 = (ushort)abStack_6[0];
      uVar7 = Ram00c520;
      uVar4 = Ram00c522;
      Ram00c53a = uVar7;
      Ram00c53c = uVar4;
      if (param_1 == 0) {
        Ram00c544 = 0x73b4;
      }
      else {
        Ram00c544 = 0x73d0;
      }
      while ((sVar8 == 1 && (uVar9 = Ram00c544, *(short *)(uint3)uVar9 != 0))) {
        uVar1 = Ram00c544;
        uVar9 = *(ushort *)(uint3)uVar1;
        Ram00c536 = *(undefined2 *)(uint3)(uVar1 + 2);
        while ((sVar8 == 1 && (sVar3 = Ram00c536, sVar3 != 0))) {
          sVar3 = Ram00c542;
          uVar1 = *(short *)(uint3)(sVar3 * 8 + 0x7050) - 4;
          uVar5 = Ram00c534;
          uVar6 = Ram00c534;
          if (uVar1 == uVar6 || uVar1 < uVar5) break;
          *(undefined1 *)(uint3)abStack_6[0] = *(undefined1 *)(uint3)uVar9;
          pbVar2 = (byte *)(uint3)uVar9;
          uVar9 = uVar9 + 1;
          uVar1 = Ram00c53e;
          Ram00c53e = uVar1 + *pbVar2;
          sVar8 = Ram00c540;
          Ram00c540 = sVar8 + (ushort)CARRY2(uVar1,(ushort)*pbVar2);
          sVar8 = Ram00c536;
          Ram00c536 = sVar8 + -1;
          sVar8 = Ram00c534;
          Ram00c534 = sVar8 + 1;
          sVar8 = func_0xc11586((short)&UNK_00c508,0,0xe0,abStack_6);
          abStack_6[0] = abStack_6[0] + 1;
        }
        sVar3 = Ram00c538;
        Ram00c538 = sVar3 + 1;
        sVar3 = Ram00c538;
        Ram00c544 = sVar3 * 6 + 0x73d0;
      }
      if (sVar8 == 1) {
        sVar8 = gap_c10fe8((short)&UNK_00c508,0,0xe0);
      }
    }
  }
  return sVar8;
}



/* ===== c11926 gap_c11926 size=6 ===== */

void gap_c11926(undefined2 param_1)

{
  Ram00c506 = param_1;
  return;
}



/* ===== c1192c app_cinit size=372 ===== */

void app_cinit(void)

{
  bool bVar1;
  undefined1 *puVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  short sVar8;
  short sVar9;
  
  uVar4 = (ushort)&DAT_00fdfe;
  do {
    if ((uVar4 != (ushort)&UNK_00fcc2) && (uVar4 != (ushort)&UNK_00fcc0)) {
      *(undefined2 *)(uint3)uVar4 = 0;
    }
    bVar1 = uVar4 != (ushort)&DAT_00fd00;
    uVar4 = uVar4 - 2;
  } while (bVar1);
  uVar4 = (ushort)&DAT_003b56;
  do {
    DPP0 = 0x302;
    while( true ) {
      while( true ) {
        uVar6 = uVar4 + 2;
        sVar8 = *(short *)(uint3)uVar4;
        if (sVar8 != 1) break;
        uVar4 = uVar4 + 0xe;
      }
      if (sVar8 == 5) break;
      if (sVar8 == 6) {
        uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
        DPP1 = *(undefined2 *)(uint3)(uVar4 + 4);
        uVar7 = *(ushort *)(uint3)(uVar4 + 6) & 0xbfff | 0x8000;
        DPP2 = *(undefined2 *)(uint3)(uVar4 + 8);
        uVar6 = uVar4 + 10;
        uVar4 = uVar4 + 0xc;
        sVar8 = *(short *)(uint3)uVar6;
        while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
          puVar2 = (undefined1 *)(uint3)uVar7;
          uVar7 = uVar7 + 1;
          *(undefined1 *)(uint3)uVar5 = *puVar2;
          bVar1 = uVar5 == 0x7fff;
          uVar5 = uVar5 + 1;
          if (bVar1) {
            uVar5 = 0x4000;
            sVar9 = DPP1;
            DPP1 = sVar9 + 1;
          }
        }
        DPP1 = 0x302;
        DPP2 = 0x303;
      }
      else {
        if (sVar8 != 7) {
          uVar4 = 0;
          do {
            DPP0 = 0x303;
            while( true ) {
              uVar6 = uVar4 + 2;
              sVar8 = *(short *)(uint3)uVar4;
              if (sVar8 == 5) break;
              if (sVar8 == 6) {
                uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
                DPP1 = *(undefined2 *)(uint3)(uVar4 + 4);
                uVar6 = uVar4 + 6;
                uVar4 = uVar4 + 8;
                sVar8 = *(short *)(uint3)uVar6;
                while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
                  *(undefined1 *)(uint3)uVar5 = 0;
                  uVar5 = uVar5 + 1;
                }
                DPP1 = 0x302;
              }
              else {
                if (sVar8 != 7) {
                  DPP0 = 0x301;
                  return;
                }
                DPP1 = (*(ushort *)(uint3)(uVar4 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar6 >> 0xe;
                uVar6 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
                uVar5 = uVar4 + 8;
                sVar8 = *(short *)(uint3)(uVar4 + 6);
                uVar4 = uVar4 + 10;
                sVar9 = *(short *)(uint3)uVar5;
                while ((bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1 ||
                       (bVar1 = sVar9 != 0, sVar9 = sVar9 + -1, bVar1))) {
                  *(undefined1 *)(uint3)uVar6 = 0;
                  bVar1 = uVar6 == 0x7fff;
                  uVar6 = uVar6 + 1;
                  if (bVar1) {
                    uVar6 = 0x4000;
                    sVar3 = DPP1;
                    DPP1 = sVar3 + 1;
                  }
                }
                DPP1 = 0x302;
              }
            }
            uVar5 = uVar4 + 4;
            uVar6 = *(ushort *)(uint3)uVar6;
            uVar4 = uVar4 + 6;
            sVar8 = *(short *)(uint3)uVar5;
            DPP0 = 0x301;
            while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
              *(undefined1 *)(uint3)uVar6 = 0;
              uVar6 = uVar6 + 1;
            }
          } while( true );
        }
        DPP1 = (*(ushort *)(uint3)(uVar4 + 4) & 0xff) << 2 | *(ushort *)(uint3)uVar6 >> 0xe;
        uVar5 = *(ushort *)(uint3)uVar6 & 0x7fff | 0x4000;
        DPP2 = (*(ushort *)(uint3)(uVar4 + 8) & 0xff) << 2 | *(ushort *)(uint3)(uVar4 + 6) >> 0xe;
        uVar6 = *(ushort *)(uint3)(uVar4 + 6) & 0xbfff | 0x8000;
        uVar7 = uVar4 + 0xc;
        sVar8 = *(short *)(uint3)(uVar4 + 10);
        uVar4 = uVar4 + 0xe;
        sVar9 = *(short *)(uint3)uVar7;
        while ((bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1 ||
               (bVar1 = sVar9 != 0, sVar9 = sVar9 + -1, bVar1))) {
          *(undefined1 *)(uint3)uVar5 = *(undefined1 *)(uint3)uVar6;
          bVar1 = uVar5 == 0x7fff;
          uVar5 = uVar5 + 1;
          if (bVar1) {
            uVar5 = 0x4000;
            sVar3 = DPP1;
            DPP1 = sVar3 + 1;
          }
          bVar1 = uVar6 == 0xbfff;
          uVar6 = uVar6 + 1;
          if (bVar1) {
            uVar6 = 0x8000;
            sVar3 = DPP2;
            DPP2 = sVar3 + 1;
          }
        }
        DPP1 = 0x302;
        DPP2 = 0x303;
      }
    }
    uVar6 = *(ushort *)(uint3)uVar6;
    uVar7 = uVar4 + 6;
    uVar5 = *(ushort *)(uint3)(uVar4 + 4);
    uVar4 = uVar4 + 8;
    sVar8 = *(short *)(uint3)uVar7;
    DPP0 = 0x301;
    while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
      puVar2 = (undefined1 *)(uint3)uVar5;
      uVar5 = uVar5 + 1;
      *(undefined1 *)(uint3)uVar6 = *puVar2;
      uVar6 = uVar6 + 1;
    }
  } while( true );
}



/* ===== c11aa0 app_cstart size=138 ===== */

/* WARNING: This function may have set the stack pointer */

void app_cstart(void)

{
  bool bVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  __disable_watchdog();
  ADDRSEL1 = 0x17;
  ADDRSEL2 = 0x8fbb;
  SYSCON1 = 0;
  SYSCON3 = 0;
  DAT_00ffaa = 0;
  DAT_00f0fa = 0x8000;
  SYSCON = 0xc1;
  __atomic(3);
  SP = 0xfc00;
  STKOV = 0xfada;
  STKUN = 0xfc00;
  uVar3 = (ushort)&DAT_00face;
  do {
    *(undefined2 *)(uint3)uVar3 = 0x165;
    bVar1 = uVar3 != (ushort)&UNK_00fbfe;
    uVar3 = uVar3 + 2;
  } while (bVar1);
  uVar2 = DPP0;
  DPP0 = 3;
  uVar3 = 0x2ca;
  do {
    *(undefined2 *)(uint3)uVar3 = 0x167;
    bVar1 = uVar3 != 0x368;
    uVar3 = uVar3 + 2;
  } while (bVar1);
  DPP0 = uVar2;
  uVar2 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  DPP1 = 0x302;
  DPP2 = 0x303;
  app_cinit();
  app_main(0,0,0);
  do {
    __idle();
  } while( true );
}



/* ===== c11b2a can_bus_config size=112 ===== */

void can_bus_config(void)

{
  ushort uVar1;
  undefined2 uVar2;
  
  uVar1 = DAT_00f0c2;
  if ((uVar1 & 0x1800) == 0x800) {
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x8e00;
  }
  uVar1 = DAT_00f0c2;
  if ((uVar1 & 0x1800) == 0x1800) {
    DAT_00f0c0 = 0xaaaa;
    DAT_00f0c0 = 0x5554;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x9600;
    DAT_00f0c0 = 0x800;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x8e00;
  }
  return;
}



/* ===== c11b9a cal_checksum size=90 ===== */

void cal_checksum(void)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar3 = (ushort)&DAT_005000;
  uVar4 = 0xc0;
  DAT_00c546 = 0;
  DAT_00c548 = 0;
  for (; uVar4 < 0xc0 || uVar4 == 0xc0 && uVar3 < 0xaffd; uVar4 = uVar4 + bVar1) {
    sVar2 = DAT_00c546;
    DAT_00c546 = sVar2 + *(short *)(uint3)uVar3 * 0x100;
    sVar2 = DAT_00c546;
    DAT_00c546 = sVar2 + (*(ushort *)(uint3)uVar3 >> 8);
    bVar1 = 0xfffd < uVar3;
    uVar3 = uVar3 + 2;
  }
  if (DAT_c0affe == DAT_c08546) {
    DAT_00c548 = 1;
  }
  return;
}



/* ===== c11bf4 app_hw_init size=110 ===== */

void app_hw_init(void)

{
  ushort uVar1;
  
  can_bus_config();
  uVar1 = DAT_00f0fe;
  DAT_00f0fe = uVar1 | 1;
  SYSCON2 = 0x7f13;
  port_bus_init();
  adc_calibrate();
  adc_start();
  asc0_init_app();
  ssc0_init_app();
  ssc_rx_queue_init();
  pwm_init();
  timer8_init();
  capcom_start();
  timer5_init();
  app_clear_flag();
  capture_init();
  config_sensor_setup();
  timer6_start();
  angle_init();
  event_init();
  timer4_init();
  ssc_init();
  set_can_flag();
  cal_checksum();
  can_bus_config();
  WDTCON = 0xbc01;
  uVar1 = P1H;
  P1H = uVar1 & 0xfffb;
  return;
}



/* ===== c11c62 app_main_init size=76 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void app_main_init(void)

{
  ushort *puVar1;
  ushort uVar2;
  byte bVar3;
  
  if ((_DAT_007092 | _DAT_007090) != 0) {
    empty_stub_0(_DAT_007092 | _DAT_007090);
  }
  bVar3 = 0;
  do {
    puVar1 = (ushort *)((ushort)bVar3 * 6 + 0x7088);
    uVar2 = (ushort)bVar3;
    bVar3 = bVar3 + 1;
    *(undefined1 *)(uint3)((short)&DAT_00c54c + uVar2 * 2) =
         *(undefined1 *)(uint3)*(ushort *)ZEXT23(puVar1);
    *(undefined1 *)(uint3)((short)&DAT_00c54d + uVar2 * 2) = *(undefined1 *)(uint3)*puVar1;
  } while (bVar3 < 2);
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  uVar2 = P1H;
  P1H = uVar2 | 4;
  app_scheduler();
  return;
}



/* ===== c11cae app_idle_wait size=234 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void app_idle_wait(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  byte bVar6;
  
  while( true ) {
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) {
      app_scheduler();
      return;
    }
    __service_watchdog();
    uVar4 = DAT_00fd14;
    DAT_00fd14 = uVar4 & 0xfffb;
    cVar3 = DAT_00c54a;
    DAT_00c54a = cVar3 + '\x01';
    cc22_23_task();
    ssc_task();
    timeout_counter_tick();
    bVar6 = DAT_00c54a;
    if ((bVar6 & 1) != 0) {
      speed_timing_calc();
      uVar4 = DAT_00c962;
      if ((((uVar4 < 0x5800) || (0x6800 < uVar4)) || (sVar5 = DAT_00cb60, sVar5 != 0)) ||
         (cVar3 = DAT_00c280, cVar3 != '\0')) {
        DAT_00c5e6 = 0;
        bVar6 = DAT_00fd18._0_1_;
        DAT_00fd18._0_1_ = bVar6 & 0x80;
        DAT_00c5e8 = 0;
        DAT_00c5ea = 0;
      }
      else {
        DAT_00c5e6 = 1;
        test_command_dispatch(0);
      }
    }
    scheduler_tick();
    bVar6 = 0;
    do {
      pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar6 * 2);
      if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar6 * 2) != *pcVar2) {
        *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
        pbVar1 = *(byte **)(uint3)((ushort)bVar6 * 6 + 0x7088);
        if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
          *(undefined1 *)ZEXT23(pcVar2) = 0;
        }
        empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
      }
      bVar6 = bVar6 + 1;
    } while (bVar6 < 2);
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) {
      empty_stub_0();
    }
    else {
      uVar4 = DAT_00fd14;
      DAT_00fd14 = uVar4 | 0x10;
    }
    kline_transport_task(1);
    sVar5 = DAT_00c584;
    if (sVar5 - 4U < 0xc) break;
    diag_status_build();
    sVar5 = empty_stub_0();
    if (sVar5 != 0) {
      uVar4 = PSW;
      PSW = uVar4 & 0xf7ff;
      __disable_watchdog();
      if (_DAT_007096 != 0 || _DAT_007094 != 0) {
        empty_stub_0();
      }
      uVar4 = P1H;
      P1H = uVar4 & 0xfffb;
      __software_reset();
      return;
    }
  }
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((sVar5 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
  return;
}



/* ===== c11d98 gap_c11d98 size=34 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c11d98(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  ushort uVar4;
  char cVar5;
  short sVar6;
  byte bVar7;
  
  cVar5 = asc0_read_rx_raw();
  cVar3 = UNK_00c5b3;
  if ((cVar5 == cVar3) || (sVar6 = DAT_00c5a2, sVar6 == 0)) {
    uVar4 = DAT_00c57a;
    if (uVar4 < 7) {
                    /* WARNING: Could not emulate address calculation at 0xc11db6 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar4 * 2 + 0x7076 & 0x3fff) | 0xc10000))();
      return;
    }
    sVar6 = DAT_00c5a2;
    if (sVar6 == 0) {
      DAT_00c5be = 0;
    }
  }
  else {
    sVar6 = DAT_00c5a2;
    if (sVar6 == 1) {
      DAT_00c5ac = 0;
      DAT_00c584 = 10;
    }
  }
  while( true ) {
    diag_status_build();
    sVar6 = empty_stub_0();
    if (sVar6 != 0) {
      uVar4 = PSW;
      PSW = uVar4 & 0xf7ff;
      __disable_watchdog();
      if (_DAT_007096 != 0 || _DAT_007094 != 0) {
        empty_stub_0();
      }
      uVar4 = P1H;
      P1H = uVar4 & 0xfffb;
      __software_reset();
      return;
    }
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) break;
    __service_watchdog();
    uVar4 = DAT_00fd14;
    DAT_00fd14 = uVar4 & 0xfffb;
    cVar3 = DAT_00c54a;
    DAT_00c54a = cVar3 + '\x01';
    cc22_23_task();
    ssc_task();
    timeout_counter_tick();
    bVar7 = DAT_00c54a;
    if ((bVar7 & 1) != 0) {
      speed_timing_calc();
      uVar4 = DAT_00c962;
      if ((((uVar4 < 0x5800) || (0x6800 < uVar4)) || (sVar6 = DAT_00cb60, sVar6 != 0)) ||
         (cVar3 = DAT_00c280, cVar3 != '\0')) {
        DAT_00c5e6 = 0;
        bVar7 = DAT_00fd18._0_1_;
        DAT_00fd18._0_1_ = bVar7 & 0x80;
        DAT_00c5e8 = 0;
        DAT_00c5ea = 0;
      }
      else {
        DAT_00c5e6 = 1;
        test_command_dispatch(0);
      }
    }
    scheduler_tick();
    bVar7 = 0;
    do {
      pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar7 * 2);
      if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar7 * 2) != *pcVar2) {
        *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
        pbVar1 = *(byte **)(uint3)((ushort)bVar7 * 6 + 0x7088);
        if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
          *(undefined1 *)ZEXT23(pcVar2) = 0;
        }
        empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
      }
      bVar7 = bVar7 + 1;
    } while (bVar7 < 2);
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) {
      empty_stub_0();
    }
    else {
      uVar4 = DAT_00fd14;
      DAT_00fd14 = uVar4 | 0x10;
    }
    kline_transport_task(1);
    sVar6 = DAT_00c584;
    if (sVar6 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((sVar6 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
      return;
    }
  }
  app_scheduler();
  return;
}



/* ===== c11dba gap_c11dba size=22 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c11dba(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  undefined1 uVar4;
  ushort uVar5;
  short sVar6;
  byte bVar7;
  
  UNK_00c576 = 1;
  bVar7 = UNK_00c58b;
  if ((bVar7 & 0xc0) == 0x80) {
    DAT_00c57a = 1;
    uVar4 = UNK_00c5b7;
    UNK_00c5b3 = uVar4;
  }
  else {
    bVar7 = UNK_00c58b;
    if ((bVar7 & 0x3f) == 0) {
      DAT_00c57a = 3;
      uVar4 = UNK_00c593;
      UNK_00c5b3 = uVar4;
    }
    else {
      bVar7 = UNK_00c5c7;
      DAT_00c57a = 4;
      UNK_00c5b3 = *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar7);
    }
  }
  gap_c127a2();
  sVar6 = DAT_00c5a2;
  if (sVar6 == 0) {
    DAT_00c5be = 0;
  }
  while( true ) {
    diag_status_build();
    sVar6 = empty_stub_0();
    if (sVar6 != 0) {
      uVar5 = PSW;
      PSW = uVar5 & 0xf7ff;
      __disable_watchdog();
      if (_DAT_007096 != 0 || _DAT_007094 != 0) {
        empty_stub_0();
      }
      uVar5 = P1H;
      P1H = uVar5 & 0xfffb;
      __software_reset();
      return;
    }
    uVar5 = DAT_00fd14;
    if ((uVar5 & 4) == 0) break;
    __service_watchdog();
    uVar5 = DAT_00fd14;
    DAT_00fd14 = uVar5 & 0xfffb;
    cVar3 = DAT_00c54a;
    DAT_00c54a = cVar3 + '\x01';
    cc22_23_task();
    ssc_task();
    timeout_counter_tick();
    bVar7 = DAT_00c54a;
    if ((bVar7 & 1) != 0) {
      speed_timing_calc();
      uVar5 = DAT_00c962;
      if ((((uVar5 < 0x5800) || (0x6800 < uVar5)) || (sVar6 = DAT_00cb60, sVar6 != 0)) ||
         (cVar3 = DAT_00c280, cVar3 != '\0')) {
        DAT_00c5e6 = 0;
        bVar7 = DAT_00fd18._0_1_;
        DAT_00fd18._0_1_ = bVar7 & 0x80;
        DAT_00c5e8 = 0;
        DAT_00c5ea = 0;
      }
      else {
        DAT_00c5e6 = 1;
        test_command_dispatch(0);
      }
    }
    scheduler_tick();
    bVar7 = 0;
    do {
      pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar7 * 2);
      if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar7 * 2) != *pcVar2) {
        *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
        pbVar1 = *(byte **)(uint3)((ushort)bVar7 * 6 + 0x7088);
        if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
          *(undefined1 *)ZEXT23(pcVar2) = 0;
        }
        empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
      }
      bVar7 = bVar7 + 1;
    } while (bVar7 < 2);
    uVar5 = DAT_00fd14;
    if ((uVar5 & 4) == 0) {
      empty_stub_0();
    }
    else {
      uVar5 = DAT_00fd14;
      DAT_00fd14 = uVar5 | 0x10;
    }
    kline_transport_task(1);
    sVar6 = DAT_00c584;
    if (sVar6 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((sVar6 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
      return;
    }
  }
  app_scheduler();
  return;
}



/* ===== c11dd0 gap_c11dd0 size=16 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c11dd0(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  undefined1 uVar4;
  ushort uVar5;
  short sVar6;
  byte bVar7;
  
  DAT_00c57a = 2;
  uVar4 = UNK_00c5c1;
  UNK_00c5b3 = uVar4;
  gap_c127a2();
  sVar6 = DAT_00c5a2;
  if (sVar6 == 0) {
    DAT_00c5be = 0;
  }
  while( true ) {
    diag_status_build();
    sVar6 = empty_stub_0();
    if (sVar6 != 0) {
      uVar5 = PSW;
      PSW = uVar5 & 0xf7ff;
      __disable_watchdog();
      if (_DAT_007096 != 0 || _DAT_007094 != 0) {
        empty_stub_0();
      }
      uVar5 = P1H;
      P1H = uVar5 & 0xfffb;
      __software_reset();
      return;
    }
    uVar5 = DAT_00fd14;
    if ((uVar5 & 4) == 0) break;
    __service_watchdog();
    uVar5 = DAT_00fd14;
    DAT_00fd14 = uVar5 & 0xfffb;
    cVar3 = DAT_00c54a;
    DAT_00c54a = cVar3 + '\x01';
    cc22_23_task();
    ssc_task();
    timeout_counter_tick();
    bVar7 = DAT_00c54a;
    if ((bVar7 & 1) != 0) {
      speed_timing_calc();
      uVar5 = DAT_00c962;
      if ((((uVar5 < 0x5800) || (0x6800 < uVar5)) || (sVar6 = DAT_00cb60, sVar6 != 0)) ||
         (cVar3 = DAT_00c280, cVar3 != '\0')) {
        DAT_00c5e6 = 0;
        bVar7 = DAT_00fd18._0_1_;
        DAT_00fd18._0_1_ = bVar7 & 0x80;
        DAT_00c5e8 = 0;
        DAT_00c5ea = 0;
      }
      else {
        DAT_00c5e6 = 1;
        test_command_dispatch(0);
      }
    }
    scheduler_tick();
    bVar7 = 0;
    do {
      pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar7 * 2);
      if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar7 * 2) != *pcVar2) {
        *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
        pbVar1 = *(byte **)(uint3)((ushort)bVar7 * 6 + 0x7088);
        if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
          *(undefined1 *)ZEXT23(pcVar2) = 0;
        }
        empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
      }
      bVar7 = bVar7 + 1;
    } while (bVar7 < 2);
    uVar5 = DAT_00fd14;
    if ((uVar5 & 4) == 0) {
      empty_stub_0();
    }
    else {
      uVar5 = DAT_00fd14;
      DAT_00fd14 = uVar5 | 0x10;
    }
    kline_transport_task(1);
    sVar6 = DAT_00c584;
    if (sVar6 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((sVar6 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
      return;
    }
  }
  app_scheduler();
  return;
}



/* ===== c11e0e thunk_FUN_c11e3c size=2 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_c11e3c(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  short sVar6;
  byte bVar7;
  
  do {
    uVar5 = Ram00f0ba;
    if (6 < (uVar5 & 0x3f00) >> 8) {
LAB_c11e78:
      sVar6 = DAT_00c5a2;
      if (sVar6 == 0) {
        DAT_00c5be = 0;
      }
      while( true ) {
        diag_status_build();
        sVar6 = empty_stub_0();
        if (sVar6 != 0) {
          uVar5 = PSW;
          PSW = uVar5 & 0xf7ff;
          __disable_watchdog();
          if (_DAT_007096 != 0 || _DAT_007094 != 0) {
            empty_stub_0();
          }
          uVar5 = P1H;
          P1H = uVar5 & 0xfffb;
          __software_reset();
          return;
        }
        uVar5 = DAT_00fd14;
        if ((uVar5 & 4) == 0) break;
        __service_watchdog();
        uVar5 = DAT_00fd14;
        DAT_00fd14 = uVar5 & 0xfffb;
        cVar3 = DAT_00c54a;
        DAT_00c54a = cVar3 + '\x01';
        cc22_23_task();
        ssc_task();
        timeout_counter_tick();
        bVar7 = DAT_00c54a;
        if ((bVar7 & 1) != 0) {
          speed_timing_calc();
          uVar5 = DAT_00c962;
          if ((((uVar5 < 0x5800) || (0x6800 < uVar5)) || (sVar6 = DAT_00cb60, sVar6 != 0)) ||
             (cVar3 = DAT_00c280, cVar3 != '\0')) {
            DAT_00c5e6 = 0;
            bVar7 = DAT_00fd18._0_1_;
            DAT_00fd18._0_1_ = bVar7 & 0x80;
            DAT_00c5e8 = 0;
            DAT_00c5ea = 0;
          }
          else {
            DAT_00c5e6 = 1;
            test_command_dispatch(0);
          }
        }
        scheduler_tick();
        bVar7 = 0;
        do {
          pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar7 * 2);
          if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar7 * 2) != *pcVar2) {
            *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
            pbVar1 = *(byte **)(uint3)((ushort)bVar7 * 6 + 0x7088);
            if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
              *(undefined1 *)ZEXT23(pcVar2) = 0;
            }
            empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
          }
          bVar7 = bVar7 + 1;
        } while (bVar7 < 2);
        uVar5 = DAT_00fd14;
        if ((uVar5 & 4) == 0) {
          empty_stub_0();
        }
        else {
          uVar5 = DAT_00fd14;
          DAT_00fd14 = uVar5 | 0x10;
        }
        kline_transport_task(1);
        sVar6 = DAT_00c584;
        if (sVar6 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)((uint3)*(ushort *)((sVar6 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
          return;
        }
      }
      app_scheduler();
      return;
    }
    bVar7 = UNK_00c576;
    bVar4 = UNK_00c593;
    if (bVar4 <= bVar7) {
      DAT_00c57a = 5;
      goto LAB_c11e78;
    }
    bVar4 = UNK_00c5c7;
    bVar7 = UNK_00c576;
    UNK_00c5b3 = *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar4 + (ushort)bVar7);
    gap_c127a2();
    cVar3 = UNK_00c576;
    UNK_00c576 = cVar3 + '\x01';
  } while( true );
}



/* ===== c11e3c FUN_c11e3c size=60 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_c11e3c(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  short sVar6;
  byte bVar7;
  
  do {
    uVar5 = Ram00f0ba;
    if (6 < (uVar5 & 0x3f00) >> 8) {
LAB_c11e78:
      sVar6 = DAT_00c5a2;
      if (sVar6 == 0) {
        DAT_00c5be = 0;
      }
      while( true ) {
        diag_status_build();
        sVar6 = empty_stub_0();
        if (sVar6 != 0) {
          uVar5 = PSW;
          PSW = uVar5 & 0xf7ff;
          __disable_watchdog();
          if (_DAT_007096 != 0 || _DAT_007094 != 0) {
            empty_stub_0();
          }
          uVar5 = P1H;
          P1H = uVar5 & 0xfffb;
          __software_reset();
          return;
        }
        uVar5 = DAT_00fd14;
        if ((uVar5 & 4) == 0) break;
        __service_watchdog();
        uVar5 = DAT_00fd14;
        DAT_00fd14 = uVar5 & 0xfffb;
        cVar3 = DAT_00c54a;
        DAT_00c54a = cVar3 + '\x01';
        cc22_23_task();
        ssc_task();
        timeout_counter_tick();
        bVar7 = DAT_00c54a;
        if ((bVar7 & 1) != 0) {
          speed_timing_calc();
          uVar5 = DAT_00c962;
          if ((((uVar5 < 0x5800) || (0x6800 < uVar5)) || (sVar6 = DAT_00cb60, sVar6 != 0)) ||
             (cVar3 = DAT_00c280, cVar3 != '\0')) {
            DAT_00c5e6 = 0;
            bVar7 = DAT_00fd18._0_1_;
            DAT_00fd18._0_1_ = bVar7 & 0x80;
            DAT_00c5e8 = 0;
            DAT_00c5ea = 0;
          }
          else {
            DAT_00c5e6 = 1;
            test_command_dispatch(0);
          }
        }
        scheduler_tick();
        bVar7 = 0;
        do {
          pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar7 * 2);
          if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar7 * 2) != *pcVar2) {
            *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
            pbVar1 = *(byte **)(uint3)((ushort)bVar7 * 6 + 0x7088);
            if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
              *(undefined1 *)ZEXT23(pcVar2) = 0;
            }
            empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
          }
          bVar7 = bVar7 + 1;
        } while (bVar7 < 2);
        uVar5 = DAT_00fd14;
        if ((uVar5 & 4) == 0) {
          empty_stub_0();
        }
        else {
          uVar5 = DAT_00fd14;
          DAT_00fd14 = uVar5 | 0x10;
        }
        kline_transport_task(1);
        sVar6 = DAT_00c584;
        if (sVar6 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)((uint3)*(ushort *)((sVar6 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
          return;
        }
      }
      app_scheduler();
      return;
    }
    bVar7 = UNK_00c576;
    bVar4 = UNK_00c593;
    if (bVar4 <= bVar7) {
      DAT_00c57a = 5;
      goto LAB_c11e78;
    }
    bVar4 = UNK_00c5c7;
    bVar7 = UNK_00c576;
    UNK_00c5b3 = *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar4 + (ushort)bVar7);
    gap_c127a2();
    cVar3 = UNK_00c576;
    UNK_00c576 = cVar3 + '\x01';
  } while( true );
}



/* ===== c11e4c gap_c11e4c size=20 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c11e4c(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  byte bVar6;
  
  DAT_00c57a = 6;
  sVar5 = DAT_00c5a2;
  if (sVar5 == 0) {
    DAT_00c5be = 0;
  }
  while( true ) {
    diag_status_build();
    sVar5 = empty_stub_0();
    if (sVar5 != 0) {
      uVar4 = PSW;
      PSW = uVar4 & 0xf7ff;
      __disable_watchdog();
      if (_DAT_007096 != 0 || _DAT_007094 != 0) {
        empty_stub_0();
      }
      uVar4 = P1H;
      P1H = uVar4 & 0xfffb;
      __software_reset();
      return;
    }
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) break;
    __service_watchdog();
    uVar4 = DAT_00fd14;
    DAT_00fd14 = uVar4 & 0xfffb;
    cVar3 = DAT_00c54a;
    DAT_00c54a = cVar3 + '\x01';
    cc22_23_task();
    ssc_task();
    timeout_counter_tick();
    bVar6 = DAT_00c54a;
    if ((bVar6 & 1) != 0) {
      speed_timing_calc();
      uVar4 = DAT_00c962;
      if ((((uVar4 < 0x5800) || (0x6800 < uVar4)) || (sVar5 = DAT_00cb60, sVar5 != 0)) ||
         (cVar3 = DAT_00c280, cVar3 != '\0')) {
        DAT_00c5e6 = 0;
        bVar6 = DAT_00fd18._0_1_;
        DAT_00fd18._0_1_ = bVar6 & 0x80;
        DAT_00c5e8 = 0;
        DAT_00c5ea = 0;
      }
      else {
        DAT_00c5e6 = 1;
        test_command_dispatch(0);
      }
    }
    scheduler_tick();
    bVar6 = 0;
    do {
      pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar6 * 2);
      if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar6 * 2) != *pcVar2) {
        *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
        pbVar1 = *(byte **)(uint3)((ushort)bVar6 * 6 + 0x7088);
        if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
          *(undefined1 *)ZEXT23(pcVar2) = 0;
        }
        empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
      }
      bVar6 = bVar6 + 1;
    } while (bVar6 < 2);
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) {
      empty_stub_0();
    }
    else {
      uVar4 = DAT_00fd14;
      DAT_00fd14 = uVar4 | 0x10;
    }
    kline_transport_task(1);
    sVar5 = DAT_00c584;
    if (sVar5 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((sVar5 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
      return;
    }
  }
  app_scheduler();
  return;
}



/* ===== c11e54 gap_c11e54 size=12 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c11e54(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  undefined1 uVar4;
  ushort uVar5;
  short sVar6;
  byte bVar7;
  
  uVar4 = UNK_00c5a4;
  UNK_00c5b3 = uVar4;
  DAT_00c5c4 = 0;
  UNK_00c589 = 0;
  gap_c127a2();
  sVar6 = DAT_00c5a2;
  if (sVar6 == 0) {
    DAT_00c5be = 0;
  }
  while( true ) {
    diag_status_build();
    sVar6 = empty_stub_0();
    if (sVar6 != 0) {
      uVar5 = PSW;
      PSW = uVar5 & 0xf7ff;
      __disable_watchdog();
      if (_DAT_007096 != 0 || _DAT_007094 != 0) {
        empty_stub_0();
      }
      uVar5 = P1H;
      P1H = uVar5 & 0xfffb;
      __software_reset();
      return;
    }
    uVar5 = DAT_00fd14;
    if ((uVar5 & 4) == 0) break;
    __service_watchdog();
    uVar5 = DAT_00fd14;
    DAT_00fd14 = uVar5 & 0xfffb;
    cVar3 = DAT_00c54a;
    DAT_00c54a = cVar3 + '\x01';
    cc22_23_task();
    ssc_task();
    timeout_counter_tick();
    bVar7 = DAT_00c54a;
    if ((bVar7 & 1) != 0) {
      speed_timing_calc();
      uVar5 = DAT_00c962;
      if ((((uVar5 < 0x5800) || (0x6800 < uVar5)) || (sVar6 = DAT_00cb60, sVar6 != 0)) ||
         (cVar3 = DAT_00c280, cVar3 != '\0')) {
        DAT_00c5e6 = 0;
        bVar7 = DAT_00fd18._0_1_;
        DAT_00fd18._0_1_ = bVar7 & 0x80;
        DAT_00c5e8 = 0;
        DAT_00c5ea = 0;
      }
      else {
        DAT_00c5e6 = 1;
        test_command_dispatch(0);
      }
    }
    scheduler_tick();
    bVar7 = 0;
    do {
      pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar7 * 2);
      if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar7 * 2) != *pcVar2) {
        *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
        pbVar1 = *(byte **)(uint3)((ushort)bVar7 * 6 + 0x7088);
        if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
          *(undefined1 *)ZEXT23(pcVar2) = 0;
        }
        empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
      }
      bVar7 = bVar7 + 1;
    } while (bVar7 < 2);
    uVar5 = DAT_00fd14;
    if ((uVar5 & 4) == 0) {
      empty_stub_0();
    }
    else {
      uVar5 = DAT_00fd14;
      DAT_00fd14 = uVar5 | 0x10;
    }
    kline_transport_task(1);
    sVar6 = DAT_00c584;
    if (sVar6 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((sVar6 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
      return;
    }
  }
  app_scheduler();
  return;
}



/* ===== c11e94 gap_c11e94 size=28 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c11e94(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  byte bVar6;
  
  sVar5 = DAT_00c5a2;
  if (sVar5 == 1) {
    DAT_00c5ac = 0;
  }
  sVar5 = DAT_00c5a2;
  if (sVar5 == 0) {
    Ram00c59a = 0;
  }
  while( true ) {
    diag_status_build();
    sVar5 = empty_stub_0();
    if (sVar5 != 0) {
      uVar4 = PSW;
      PSW = uVar4 & 0xf7ff;
      __disable_watchdog();
      if (_DAT_007096 != 0 || _DAT_007094 != 0) {
        empty_stub_0();
      }
      uVar4 = P1H;
      P1H = uVar4 & 0xfffb;
      __software_reset();
      return;
    }
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) break;
    __service_watchdog();
    uVar4 = DAT_00fd14;
    DAT_00fd14 = uVar4 & 0xfffb;
    cVar3 = DAT_00c54a;
    DAT_00c54a = cVar3 + '\x01';
    cc22_23_task();
    ssc_task();
    timeout_counter_tick();
    bVar6 = DAT_00c54a;
    if ((bVar6 & 1) != 0) {
      speed_timing_calc();
      uVar4 = DAT_00c962;
      if ((((uVar4 < 0x5800) || (0x6800 < uVar4)) || (sVar5 = DAT_00cb60, sVar5 != 0)) ||
         (cVar3 = DAT_00c280, cVar3 != '\0')) {
        DAT_00c5e6 = 0;
        bVar6 = DAT_00fd18._0_1_;
        DAT_00fd18._0_1_ = bVar6 & 0x80;
        DAT_00c5e8 = 0;
        DAT_00c5ea = 0;
      }
      else {
        DAT_00c5e6 = 1;
        test_command_dispatch(0);
      }
    }
    scheduler_tick();
    bVar6 = 0;
    do {
      pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar6 * 2);
      if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar6 * 2) != *pcVar2) {
        *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
        pbVar1 = *(byte **)(uint3)((ushort)bVar6 * 6 + 0x7088);
        if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
          *(undefined1 *)ZEXT23(pcVar2) = 0;
        }
        empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
      }
      bVar6 = bVar6 + 1;
    } while (bVar6 < 2);
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) {
      empty_stub_0();
    }
    else {
      uVar4 = DAT_00fd14;
      DAT_00fd14 = uVar4 | 0x10;
    }
    kline_transport_task(1);
    sVar5 = DAT_00c584;
    if (sVar5 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((sVar5 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
      return;
    }
  }
  app_scheduler();
  return;
}



/* ===== c11eb4 app_scheduler size=18 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void app_scheduler(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  byte bVar6;
  
  while( true ) {
    sVar5 = empty_stub_0();
    if (sVar5 != 0) {
      uVar4 = PSW;
      PSW = uVar4 & 0xf7ff;
      __disable_watchdog();
      if (_DAT_007096 != 0 || _DAT_007094 != 0) {
        empty_stub_0();
      }
      uVar4 = P1H;
      P1H = uVar4 & 0xfffb;
      __software_reset();
      return;
    }
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) break;
    __service_watchdog();
    uVar4 = DAT_00fd14;
    DAT_00fd14 = uVar4 & 0xfffb;
    cVar3 = DAT_00c54a;
    DAT_00c54a = cVar3 + '\x01';
    cc22_23_task();
    ssc_task();
    timeout_counter_tick();
    bVar6 = DAT_00c54a;
    if ((bVar6 & 1) != 0) {
      speed_timing_calc();
      uVar4 = DAT_00c962;
      if ((((uVar4 < 0x5800) || (0x6800 < uVar4)) || (sVar5 = DAT_00cb60, sVar5 != 0)) ||
         (cVar3 = DAT_00c280, cVar3 != '\0')) {
        DAT_00c5e6 = 0;
        bVar6 = DAT_00fd18._0_1_;
        DAT_00fd18._0_1_ = bVar6 & 0x80;
        DAT_00c5e8 = 0;
        DAT_00c5ea = 0;
      }
      else {
        DAT_00c5e6 = 1;
        test_command_dispatch(0);
      }
    }
    scheduler_tick();
    bVar6 = 0;
    do {
      pcVar2 = (char *)((short)&DAT_00c54d + (ushort)bVar6 * 2);
      if (*(char *)(uint3)((short)&DAT_00c54c + (ushort)bVar6 * 2) != *pcVar2) {
        *(char *)ZEXT23(pcVar2) = *(char *)ZEXT23(pcVar2) + '\x01';
        pbVar1 = *(byte **)(uint3)((ushort)bVar6 * 6 + 0x7088);
        if (*(byte *)ZEXT23(pcVar2) != *pbVar1 && *pbVar1 <= *(byte *)ZEXT23(pcVar2)) {
          *(undefined1 *)ZEXT23(pcVar2) = 0;
        }
        empty_stub_0(*(undefined1 *)ZEXT23(pcVar2));
      }
      bVar6 = bVar6 + 1;
    } while (bVar6 < 2);
    uVar4 = DAT_00fd14;
    if ((uVar4 & 4) == 0) {
      empty_stub_0();
    }
    else {
      uVar4 = DAT_00fd14;
      DAT_00fd14 = uVar4 | 0x10;
    }
    kline_transport_task(1);
    sVar5 = DAT_00c584;
    if (sVar5 - 4U < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0xc11d94 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((sVar5 - 4U) * 2 + 0x705e & 0x3fff) | 0xc10000))();
      return;
    }
    diag_status_build();
  }
  app_scheduler();
  return;
}



/* ===== c11ec6 app_scheduler_path size=38 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void app_scheduler_path(void)

{
  ushort uVar1;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  __disable_watchdog();
  if (_DAT_007096 != 0 || _DAT_007094 != 0) {
    empty_stub_0();
  }
  uVar1 = P1H;
  P1H = uVar1 & 0xfffb;
  __software_reset();
  return;
}



/* ===== c11eec scheduler_tick size=24 ===== */

void scheduler_tick(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  cVar1 = DAT_00c54c;
  DAT_00c54c = cVar1 + '\x01';
  bVar2 = DAT_00c54c;
  bVar3 = DAT_00c550;
  bVar4 = DAT_00c550;
  if (bVar2 != bVar4 && bVar3 <= bVar2) {
    DAT_00c54c = 0;
  }
  command_dispatch_index3();
  return;
}



/* ===== c11f04 gap_c11f04 size=10 ===== */

void gap_c11f04(undefined1 param_1)

{
  func_0xc14768(param_1);
  return;
}



/* ===== c11f10 FUN_c11f10 size=6 ===== */

void FUN_c11f10(void)

{
  FUN_c147ce();
  return;
}



/* ===== c11f16 gap_c11f16 size=6 ===== */

void gap_c11f16(void)

{
  gap_c147d6();
  return;
}



/* ===== c11f1c asc0_init_app size=62 ===== */

void asc0_init_app(void)

{
  ushort uVar1;
  
  DAT_00feb6 = 0x1a2;
  S0BG = 0x9c;
  S0CON = 0x811;
  DAT_00f0c6 = 0x807;
  DAT_00f0c4 = 0x107;
  uVar1 = DAT_00f126;
  DAT_00f126 = uVar1 | 0x400;
  uVar1 = P3;
  P3 = uVar1 & 0xfbff | 0x400;
  uVar1 = DP3;
  DP3 = uVar1 & 0xfbff | 0x400;
  uVar1 = S0RIC;
  S0RIC = uVar1 | 0x49;
  uVar1 = S0TIC;
  S0TIC = uVar1 | 0x4a;
  uVar1 = S0CON;
  S0CON = uVar1 | 0x8000;
  return;
}



/* ===== c11f5a gap_c11f5a size=6 ===== */

void gap_c11f5a(undefined2 param_1)

{
  S0TBUF = param_1;
  return;
}



/* ===== c11f60 asc0_read_rx_raw size=6 ===== */

undefined1 asc0_read_rx_raw(void)

{
  undefined1 uVar1;
  
  uVar1 = S0RBUF;
  return uVar1;
}



/* ===== c11f66 asc0_rx_handler size=52 ===== */

void asc0_rx_handler(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  
  DAT_00fce0 = &stack0x0000;
  uVar1 = DPP0;
  uVar2 = DPP0;
  uVar2 = DPP0;
  DPP0 = 0x301;
  uVar2 = DPP2;
  uVar3 = DPP2;
  uVar3 = DPP2;
  DPP2 = 0x303;
  uVar4 = asc0_read_rx_raw(uVar2,uVar1);
  kline_push_rx_byte(uVar4);
  DPP2 = uVar2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  uVar2 = DPP2;
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  return;
}



/* ===== c11f9a asc0_tx_handler size=98 ===== */

void asc0_tx_handler(void)

{
  short sVar1;
  char cVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  DAT_00fce0 = &stack0x0000;
  uVar3 = DPP0;
  DPP0 = 0x301;
  uVar4 = DPP2;
  DPP2 = 0x303;
  sVar1 = DAT_00c57a;
  if (sVar1 == 6) {
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5ac = 0;
      cVar2 = DAT_00c57d;
      if (cVar2 == '\0') {
        kline_state_reset(5);
      }
      else {
        cVar2 = DAT_00c5b6;
        if (cVar2 != '\0') {
          kline_rx_state_8(uVar4,uVar3);
        }
      }
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      kline_prepare_frame(0);
    }
  }
  DPP2 = uVar4;
  uVar4 = DPP2;
  uVar4 = DPP2;
  uVar4 = DPP2;
  DPP0 = uVar3;
  uVar3 = DPP0;
  uVar3 = DPP0;
  uVar3 = DPP0;
  return;
}



/* ===== c11ffe gap_c11ffe size=104 ===== */

void gap_c11ffe(void)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  
  sVar1 = Ram00c5c2;
  if ((sVar1 == 0) && (cVar3 = UNK_00c578, cVar3 == '\x02')) {
    uVar4 = UNK_00f63e;
    cVar3 = func_0xc23c0e(uVar4,0x10);
    if (cVar3 == '\x01') {
      uVar4 = UNK_00f63e;
      UNK_00f640 = uVar4;
      bVar2 = UNK_00c5c7;
      uVar4 = UNK_00cb2c;
      uVar4 = func_0xc23cc2((short)&UNK_00f63d + (ushort)bVar2,2,uVar4);
      gap_c12910(uVar4);
      return;
    }
  }
  func_0xc128ec(0x12);
  return;
}



/* ===== c12066 gap_c12066 size=192 ===== */

void gap_c12066(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  short sVar4;
  
  sVar4 = Ram00c5c2;
  if (sVar4 == 0) {
    UNK_00cb25 = 0;
    cVar2 = UNK_00c578;
    if (cVar2 == '\x03') {
      uVar3 = UNK_00f63e;
      cVar2 = func_0xc23c0e(uVar3,0x20);
      if ((cVar2 == '\x01') && (cVar2 = UNK_00f63f, cVar2 == '\0')) {
        uVar3 = UNK_00cb25;
        sVar4 = func_0xc234be(uVar3);
        if (((sVar4 != 0) ||
            ((((cVar2 = UNK_00f63e, cVar2 == '\x02' || (cVar2 == '\x03')) || (cVar2 == '\x04')) ||
             ((cVar2 == '\x05' || (cVar2 == '\a')))))) ||
           ((cVar2 == '\t' ||
            (((cVar2 == '\v' || (cVar2 == '\f')) ||
             ((cVar2 == '\r' || ((cVar2 == '\x11' || (cVar2 == '\x7f')))))))))) {
          uVar3 = UNK_00f63e;
          UNK_00f641 = uVar3;
          UNK_00f642 = 0;
          bVar1 = UNK_00c5c7;
          uVar3 = UNK_00cb2c;
          uVar3 = func_0xc23cc2((short)&UNK_00f63d + (ushort)bVar1,3,uVar3);
          gap_c12910(uVar3);
          return;
        }
      }
    }
  }
  func_0xc128ec(0x12);
  return;
}



/* ===== c12126 gap_c12126 size=40 ===== */

void gap_c12126(void)

{
  char cVar1;
  short sVar2;
  
  sVar2 = Ram00c5c2;
  if ((sVar2 == 0) && (cVar1 = UNK_00c578, cVar1 == '\x01')) {
    func_0xc1214e(0);
    return;
  }
  func_0xc128ec(0x12);
  return;
}



/* ===== c1223a gap_c1223a size=40 ===== */

void gap_c1223a(void)

{
  char cVar1;
  short sVar2;
  
  sVar2 = Ram00c5c2;
  if ((sVar2 == 0) && (cVar1 = UNK_00c578, cVar1 == '\x01')) {
    func_0xc12262(0);
    return;
  }
  func_0xc128ec(0x12);
  return;
}



/* ===== c12324 gap_c12324 size=116 ===== */

/* WARNING: Removing unreachable block (ram,0xc124bc) */
/* WARNING: Removing unreachable block (ram,0xc124c6) */
/* WARNING: Removing unreachable block (ram,0xc124cc) */
/* WARNING: Removing unreachable block (ram,0xc124ae) */
/* WARNING: Removing unreachable block (ram,0xc124b8) */
/* WARNING: Removing unreachable block (ram,0xc124ba) */
/* WARNING: Removing unreachable block (ram,0xc124b6) */
/* WARNING: Removing unreachable block (ram,0xc124c4) */

void gap_c12324(void)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  
  UNK_00c55d = 0;
  UNK_00c55f = 0;
  UNK_00c55e = 0;
  UNK_00c55b = 0;
  UNK_00c55a = 0;
  UNK_00cb58 = 0;
  sVar3 = Ram00c5c2;
  if ((sVar3 == 0) && (cVar1 = UNK_00c578, cVar1 == '\x02')) {
    bVar2 = UNK_00f63e;
    UNK_00cb46 = bVar2;
    if (bVar2 < 9) {
      sVar3 = 3;
      UNK_00f640 = bVar2;
      bVar2 = UNK_00cb46;
      if (bVar2 < 7) {
                    /* WARNING: Could not emulate address calculation at 0xc12394 */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((uint3)*(ushort *)((ushort)bVar2 * 2 + 0x70b4 & 0x3fff) | 0xc10000))();
        return;
      }
    }
  }
  func_0xc128ec(0x12,sVar3);
  return;
}



/* ===== c12398 gap_c12398 size=70 ===== */

void gap_c12398(void)

{
  byte bVar1;
  byte bVar2;
  byte in_RL1;
  char in_RL2;
  char in_RL3;
  
  *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)in_RL1) = 1;
  *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 1)) = uRam007692;
  *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 2)) = uRam007694;
  *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 3)) = uRam0076bd;
  *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 4)) = uRam0076be;
  if (in_RL2 != '\0') {
    bVar1 = UNK_00c55a;
    bVar2 = UNK_00c55d;
    if ((bVar1 < bVar2) && (in_RL3 != '\0')) {
      DAT_00c5b6 = 1;
      if ((byte)(in_RL1 + 3) == '\0') {
        return;
      }
      goto LAB_c124cc;
    }
  }
  if (in_RL3 == '\0') {
    func_0xc128ec(0x12);
    return;
  }
LAB_c124cc:
  gap_c12910(in_RL1 + 3);
  return;
}



/* ===== c123de gap_c123de size=22 ===== */

void gap_c123de(void)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  byte in_RL1;
  char in_RL2;
  char in_RL3;
  
  if ((bRam007692 & 0x20) == 0) {
    in_RL3 = '\0';
  }
  else {
    uVar1 = (ushort)in_RL1;
    in_RL1 = in_RL1 + 1;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + uVar1) = 4;
  }
  if (in_RL2 != '\0') {
    bVar2 = UNK_00c55a;
    bVar3 = UNK_00c55d;
    if ((bVar2 < bVar3) && (in_RL3 != '\0')) {
      DAT_00c5b6 = 1;
      if ((byte)(in_RL1 - 2) == '\0') {
        return;
      }
      goto LAB_c124cc;
    }
  }
  if (in_RL3 == '\0') {
    func_0xc128ec(0x12);
    return;
  }
LAB_c124cc:
  gap_c12910(in_RL1 - 2);
  return;
}



/* ===== c123f4 gap_c123f4 size=80 ===== */

void gap_c123f4(short param_1)

{
  byte bVar1;
  char cVar2;
  byte in_RL1;
  byte bVar3;
  char in_RL2;
  byte bVar4;
  char in_RL3;
  
  if ((bRam007692 & 0x10) == 0) {
    in_RL3 = '\0';
  }
  else {
    UNK_00c55d = 4;
    UNK_00c55a = 1;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)in_RL1) = 1;
    bVar4 = 0;
    bVar3 = in_RL1 + 1;
    do {
      bVar1 = UNK_00c55e;
      cVar2 = UNK_00c55e;
      UNK_00c55e = cVar2 + '\x01';
      param_1 = (0xa51e < bVar1) + 0xc0;
      in_RL1 = bVar3 + 1;
      bVar4 = bVar4 + 1;
      *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar3) =
           *(undefined1 *)(uint3)(bVar1 + 0x5ae1);
      bVar3 = in_RL1;
    } while (bVar4 < 4);
    in_RL2 = '\x01';
  }
  if (in_RL2 != '\0') {
    bVar4 = UNK_00c55a;
    bVar3 = UNK_00c55d;
    if ((bVar4 < bVar3) && (in_RL3 != '\0')) {
      DAT_00c5b6 = 1;
      if ((byte)(in_RL1 - 2) == '\0') {
        return;
      }
      goto LAB_c124cc;
    }
  }
  if (in_RL3 == '\0') {
    func_0xc128ec(0x12);
    return;
  }
LAB_c124cc:
  gap_c12910(in_RL1 - 2,param_1);
  return;
}



/* ===== c12444 gap_c12444 size=22 ===== */

void gap_c12444(void)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  byte in_RL1;
  char in_RL2;
  char in_RL3;
  
  if ((bRam007692 & 8) == 0) {
    in_RL3 = '\0';
  }
  else {
    uVar1 = (ushort)in_RL1;
    in_RL1 = in_RL1 + 1;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + uVar1) = 1;
  }
  if (in_RL2 != '\0') {
    bVar2 = UNK_00c55a;
    bVar3 = UNK_00c55d;
    if ((bVar2 < bVar3) && (in_RL3 != '\0')) {
      DAT_00c5b6 = 1;
      if ((byte)(in_RL1 - 2) == '\0') {
        return;
      }
      goto LAB_c124cc;
    }
  }
  if (in_RL3 == '\0') {
    func_0xc128ec(0x12);
    return;
  }
LAB_c124cc:
  gap_c12910(in_RL1 - 2);
  return;
}



/* ===== c1245a gap_c1245a size=128 ===== */

void gap_c1245a(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  byte bVar4;
  byte in_RL1;
  char in_RL2;
  char in_RL3;
  
  if ((bRam007692 & 4) == 0) {
    in_RL3 = '\0';
  }
  else {
    *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)in_RL1) = 1;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 1)) = 0;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 2)) = 0;
    uVar3 = DAT_00c546;
    bVar1 = in_RL1 + 4;
    *(char *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 3)) = (char)((ushort)uVar3 >> 8);
    uVar2 = DAT_00c546._0_1_;
    in_RL1 = in_RL1 + 5;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar1) = uVar2;
  }
  if (in_RL2 != '\0') {
    bVar1 = UNK_00c55a;
    bVar4 = UNK_00c55d;
    if ((bVar1 < bVar4) && (in_RL3 != '\0')) {
      DAT_00c5b6 = 1;
      if ((byte)(in_RL1 - 2) == '\0') {
        return;
      }
      goto LAB_c124cc;
    }
  }
  if (in_RL3 == '\0') {
    func_0xc128ec(0x12);
    return;
  }
LAB_c124cc:
  gap_c12910(in_RL1 - 2);
  return;
}



/* ===== c124e0 gap_c124e0 size=240 ===== */

void gap_c124e0(short param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  
  cVar5 = '\x01';
  cVar3 = UNK_00c55d;
  if (cVar3 != '\0') {
    bVar6 = UNK_00c55a;
    bVar7 = UNK_00c55d;
    if (bVar6 < bVar7) {
      param_1 = 3;
      uVar2 = UNK_00cb46;
      UNK_00f640 = uVar2;
      cVar5 = UNK_00c55a;
      UNK_00c55a = cVar5 + '\x01';
      uVar2 = UNK_00c55a;
      bVar6 = 5;
      UNK_00f641 = uVar2;
      cVar5 = UNK_00cb46;
      if (cVar5 == '\x04') {
        bVar7 = 0;
        do {
          bVar4 = UNK_00c55e;
          if (bVar4 < 8) {
            cVar5 = UNK_00c55e;
            UNK_00c55e = cVar5 + '\x01';
            param_1 = (0xa51e < bVar4) + 0xc0;
            uVar1 = (ushort)bVar6;
            bVar6 = bVar6 + 1;
            *(undefined1 *)(uint3)((short)&UNK_00f63d + uVar1) =
                 *(undefined1 *)(uint3)(bVar4 + 0x5ae1);
          }
          else {
            bVar4 = UNK_00c55e;
            if (bVar4 < 0x10) {
              cVar5 = UNK_00c55e;
              UNK_00c55e = cVar5 + '\x01';
              uVar1 = (ushort)bVar6;
              bVar6 = bVar6 + 1;
              *(undefined1 *)(uint3)((short)&UNK_00f63d + uVar1) = 0;
            }
          }
          bVar7 = bVar7 + 1;
        } while (bVar7 < 4);
        cVar5 = UNK_00c55e;
        if (cVar5 == '\x10') {
          cVar5 = UNK_00c55f;
          UNK_00c55f = cVar5 + '\x01';
          UNK_00c55e = 0;
        }
      }
      else if (cVar5 == '\x06') {
        UNK_00c55f = 0;
      }
      cVar5 = bVar6 - 2;
      goto LAB_c125a4;
    }
  }
  UNK_00c55d = 0;
  UNK_00c55a = 0;
  DAT_00c5b6 = 0;
LAB_c125a4:
  cVar3 = UNK_00cb46;
  if (cVar3 == '\x06') {
    DAT_00c5b6 = 1;
    UNK_00cb58 = 0;
    return;
  }
  bVar6 = UNK_00c55a;
  bVar7 = UNK_00c55d;
  if (bVar7 <= bVar6) {
    DAT_00c5b6 = 0;
  }
  gap_c12910(cVar5,param_1);
  return;
}



/* ===== c125d2 gap_c125d2 size=20 ===== */

undefined1 gap_c125d2(void)

{
  short sVar1;
  ushort uVar2;
  undefined1 uVar3;
  
  uVar2 = DAT_00fd02;
  if (((uVar2 & 0x800) == 0) && (sVar1 = DAT_00c9d0, sVar1 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* ===== c125f4 gap_c125f4 size=6 ===== */

undefined2 gap_c125f4(void)

{
  return 0x1234;
}



/* ===== c125fa gap_c125fa size=6 ===== */

undefined2 gap_c125fa(void)

{
  return 0x8474;
}



/* ===== c12602 gap_c12602 size=118 ===== */

undefined2 gap_c12602(ushort param_1,ushort param_2,ushort param_3)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  short in_r4;
  undefined1 uVar5;
  
  if (param_2 == 0 && param_1 < 0xc000) {
LAB_c1262a:
    if (param_2 != 0 || 0xf5ff < param_1) {
      uVar3 = (param_3 & 0xff) - 1;
      uVar1 = param_1 + uVar3;
      sVar2 = param_2 + ((short)uVar3 >> 0xf) + (ushort)CARRY2(param_1,uVar3);
      in_r4 = sVar2 - (ushort)(uVar1 < 0xfdff);
      if (in_r4 == 0 && uVar1 == 0xfdff || sVar2 == 0 && uVar1 < 0xfdff) goto LAB_c12672;
    }
    uVar5 = (undefined1)((ushort)in_r4 >> 8);
    uVar4 = 0;
    if (param_2 < 0xc0 || param_2 == 0xc0 && param_1 < (ushort)&DAT_005000) goto LAB_c12674;
    uVar3 = (param_3 & 0xff) - 1;
    uVar1 = param_1 + uVar3;
    uVar3 = param_2 + ((short)uVar3 >> 0xf) + (ushort)CARRY2(param_1,uVar3);
    uVar4 = 0;
    if (((short)&T2CON + uVar3 != (ushort)(uVar1 < 0xafff) || uVar1 != 0xafff) &&
        (0xbf < uVar3 && (uVar3 != 0xc0 || uVar1 >= 0xafff))) goto LAB_c12674;
  }
  else {
    uVar3 = (param_3 & 0xff) - 1;
    uVar1 = param_1 + uVar3;
    sVar2 = param_2 + ((short)uVar3 >> 0xf) + (ushort)CARRY2(param_1,uVar3);
    in_r4 = sVar2 - (ushort)(uVar1 < 0xcfff);
    if ((in_r4 != 0 || uVar1 != 0xcfff) && (sVar2 != 0 || uVar1 >= 0xcfff)) goto LAB_c1262a;
  }
LAB_c12672:
  uVar5 = (undefined1)((ushort)in_r4 >> 8);
  uVar4 = 1;
LAB_c12674:
  return CONCAT11(uVar5,uVar4);
}



/* ===== c1267a gap_c1267a size=14 ===== */

bool gap_c1267a(void)

{
  short sVar1;
  
  sVar1 = DAT_00c56a;
  return sVar1 == 0;
}



/* ===== c12696 kline_get_status size=6 ===== */

undefined1 kline_get_status(void)

{
  undefined1 uVar1;
  
  uVar1 = DAT_00c56d;
  return uVar1;
}



/* ===== c1269c gap_c1269c size=10 ===== */

void gap_c1269c(void)

{
  func_0xc128ec(0x11);
  return;
}



/* ===== c126a6 gap_c126a6 size=10 ===== */

void gap_c126a6(void)

{
  func_0xc128ec(0x11);
  return;
}



/* ===== c126b0 kline_start_timeout size=10 ===== */

void kline_start_timeout(void)

{
  DAT_00c56a = 0x500;
  return;
}



/* ===== c126bc kline_state_reset size=22 ===== */

void kline_state_reset(undefined1 param_1)

{
  ushort uVar1;
  
  DAT_00c582 = param_1;
  DAT_00c57d = 0;
  uVar1 = S0CON;
  S0CON = uVar1 & 0xffef;
  DAT_00c588 = 0;
  DAT_00c584 = 0;
  return;
}



/* ===== c126d2 gap_c126d2 size=8 ===== */

void gap_c126d2(void)

{
  ushort uVar1;
  
  uVar1 = S0CON;
  S0CON = uVar1 & 0xffef;
  func_0xc1297a();
  return;
}



/* ===== c126da kline_prepare_frame size=200 ===== */

void kline_prepare_frame(undefined1 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  
  DAT_00c5a9 = param_1;
  DAT_00c59e = 0;
  cVar4 = DAT_00c5a0;
  if (cVar4 != '\0') {
    bVar3 = DAT_00c599;
    bVar1 = DAT_00c57f;
    DAT_00c5a6 = (short)(bVar3 + 0xf) >> 4;
    uVar5 = (ushort)bVar1;
    if (0xf0 < uVar5) {
      uVar5 = uVar5 * 0x100 + 0x1000;
    }
    DAT_00c5a5 = bVar1;
    uVar2 = DAT_00c598;
    DAT_00c57e = uVar2;
    uVar2 = DAT_00c580;
    DAT_00c5a8 = uVar2;
    uVar2 = DAT_00c592;
    DAT_00c577 = uVar2;
    bVar1 = DAT_00c57e;
    DAT_00c5bc = (short)(bVar1 + 0xf) >> 4;
    cVar4 = DAT_00c5a8;
    DAT_00c57c = bVar3;
    DAT_00c59c = (uVar5 << 5) / 10;
    if (cVar4 == -1) {
      DAT_00c5b4 = 0xffff;
    }
    else {
      bVar1 = DAT_00c5a8;
      DAT_00c5b4 = (ushort)bVar1 << 5;
    }
    bVar1 = DAT_00c577;
    DAT_00c586 = (short)(bVar1 + 0xf) >> 4;
    DAT_00c5a0 = 0;
  }
  DAT_00c584 = 6;
  DAT_00c58c = 0;
  DAT_00c56f = 0;
  uVar5 = S0CON;
  S0CON = uVar5 | 0x10;
  return;
}



/* ===== c127a2 gap_c127a2 size=92 ===== */

void gap_c127a2(short param_1)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  undefined1 uVar4;
  char cVar5;
  ushort uVar6;
  
  uVar2 = S0CON;
  S0CON = uVar2 & 0xffef;
  sVar1 = DAT_00c57a;
  if ((sVar1 == 0) && (uVar2 = S0TBIC, (uVar2 & 0x80) == 0)) {
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5ac = 0;
      DAT_00c584 = 10;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      Ram00c59a = 0;
      DAT_00c584 = 0xb;
      return;
    }
  }
  else {
    uVar6 = DAT_00c5be;
    uVar2 = DAT_00c586;
    if ((uVar6 < uVar2) && (param_1 = DAT_00c5a2, param_1 == 0)) {
      DAT_00c584 = 0xc;
      return;
    }
    uVar4 = UNK_00c5b3;
    gap_c11f5a(uVar4,param_1);
    cVar5 = UNK_00c5b3;
    cVar3 = UNK_00c5a4;
    UNK_00c5a4 = cVar3 + cVar5;
  }
  return;
}



/* ===== c12826 kline_rx_state_7 size=34 ===== */

void kline_rx_state_7(void)

{
  short sVar1;
  
  sVar1 = DAT_00c5a2;
  if (sVar1 == 1) {
    DAT_00c5be = 0;
  }
  sVar1 = DAT_00c5a2;
  if (sVar1 == 0) {
    DAT_00c5b0 = 0;
  }
  DAT_00c574 = 0;
  DAT_00c584 = 7;
  return;
}



/* ===== c12848 kline_rx_state_8 size=14 ===== */

void kline_rx_state_8(void)

{
  DAT_00c584 = 8;
  DAT_00c5ba = 2;
  return;
}



/* ===== c12856 gap_c12856 size=112 ===== */

void gap_c12856(byte param_1)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  ushort uVar4;
  
  bVar1 = UNK_00c5ae;
  if ((bVar1 & 0xc0) == 0xc0) {
    UNK_00c58b = 0x80;
  }
  else {
    bVar1 = UNK_00c5ae;
    UNK_00c58b = bVar1 & 0xc0;
  }
  if ((param_1 & 0x3f) == param_1) {
    bVar1 = UNK_00c58b;
    UNK_00c58b = bVar1 | param_1;
  }
  UNK_00c593 = param_1;
  bVar1 = UNK_00c5ae;
  if (((bVar1 & 0x80) != 0) || ((bVar1 & 0xc0) != 0)) {
    uVar2 = UNK_00c594;
    UNK_00c5b7 = uVar2;
    UNK_00c5c1 = 0x11;
  }
  uVar4 = DAT_00c5ac;
  uVar3 = DAT_00c5a6;
  if (uVar4 < uVar3) {
    DAT_00c584 = 10;
    return;
  }
  func_0xc127fe();
  return;
}



/* ===== c12910 gap_c12910 size=44 ===== */

void gap_c12910(char param_1)

{
  byte bVar1;
  byte bVar2;
  
  if (param_1 == '\0') {
    kline_prepare_frame(0);
    return;
  }
  bVar1 = DAT_00c5c4;
  bVar2 = UNK_00c5c7;
  *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar2) =
       *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar1) + '@';
  gap_c12856(param_1);
  return;
}



/* ===== c1293c kline_push_rx_byte size=50 ===== */

void kline_push_rx_byte(undefined1 param_1)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  
  bVar2 = DAT_00c58c;
  cVar3 = DAT_00c58c;
  DAT_00c58c = cVar3 + '\x01';
  *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar2) = param_1;
  sVar1 = DAT_00c584;
  if ((sVar1 == 6) && (cVar3 = DAT_00f600, cVar3 != '\0')) {
    kline_rx_state_7();
  }
  cVar3 = DAT_00c58c;
  if (cVar3 == '=') {
    DAT_00c58c = 0;
  }
  return;
}



/* ===== c1296e gap_c1296e size=12 ===== */

void gap_c1296e(void)

{
  UNK_00c570 = 0;
  DAT_00c574 = 4;
  return;
}



/* ===== c12982 kline_transport_task size=84 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kline_transport_task(short param_1,undefined2 param_2)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  byte bVar5;
  bool bVar6;
  char cVar7;
  
  if (param_1 == 0) {
    kline_state_reset(6);
    uVar4 = S0CON;
    S0CON = uVar4 & 0xffef;
    kline_start_timeout();
    DAT_00c5ab = 0;
    DAT_00c568 = 0;
    empty_stub_2();
    store32();
    test_command_clear();
  }
  else if (param_1 == 1) {
    uVar4 = DAT_00c584;
    if (uVar4 < 0x10) {
                    /* WARNING: Could not emulate address calculation at 0xc129d2 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar4 * 2 + 0x7164 & 0x3fff) | 0xc10000))();
      return;
    }
    sVar1 = DAT_00c56a;
    if (sVar1 != 0) {
      sVar1 = DAT_00c56a;
      DAT_00c56a = sVar1 + -1;
    }
    sVar1 = DAT_00c584;
    if ((sVar1 != 0xd) && (sVar1 != 10)) {
      cVar7 = DAT_00c5ab;
      if (cVar7 != '\0') {
        DAT_00c5ab = 0;
        uVar4 = PSW;
        PSW = uVar4 & 0xf7ff;
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      param_2 = 0;
    }
    cVar7 = DAT_00c57d;
    if (cVar7 == '\0') {
      DAT_00c568 = 0;
    }
    else {
      cVar7 = DAT_00c568;
      if (cVar7 == '\0') {
        DAT_00c568 = 1;
        empty_stub_1(param_2);
      }
    }
    cVar7 = DAT_00c5b6;
    if ((((cVar7 == '\0') && (cVar7 = kline_get_status(), cVar7 == '\0')) ||
        (sVar1 = DAT_00c584, sVar1 == 0xd)) || (sVar1 == 10)) {
      sVar1 = DAT_00c584;
      if (sVar1 == 9) {
        bVar5 = DAT_00c5c4;
        bVar6 = false;
        DAT_00c56c = 0;
        while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
          bVar3 = DAT_00c56c;
          if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
              *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar5)) {
            empty_stub_0();
            bVar6 = true;
            break;
          }
          cVar7 = DAT_00c56c;
          DAT_00c56c = cVar7 + '\x01';
        }
        if (!bVar6) {
          empty_stub_0();
        }
      }
    }
    else {
      uVar2 = DAT_00c56c;
      empty_stub_0();
    }
  }
  return;
}



/* ===== c129d6 gap_c129d6 size=12 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c129d6(void)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  bool bVar6;
  char cVar7;
  
  uVar5 = P3;
  if ((uVar5 & 0x800) == 0) {
    func_0xc1281a();
  }
  else {
    kline_state_reset(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar7 = DAT_00c5ab, cVar7 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar7 = DAT_00c57d;
  if (cVar7 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar7 = DAT_00c568;
    if (cVar7 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar7 = DAT_00c5b6;
  if (((cVar7 == '\0') && (cVar7 = kline_get_status(), cVar7 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar6 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar6 = true;
          break;
        }
        cVar7 = DAT_00c56c;
        DAT_00c56c = cVar7 + '\x01';
      }
      if (!bVar6) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c129e2 gap_c129e2 size=52 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c129e2(void)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  bool bVar6;
  char cVar7;
  
  uVar5 = P3;
  if ((uVar5 & 0x800) == 0) {
    cVar7 = UNK_00c571;
    UNK_00c571 = cVar7 + '\x01';
  }
  else {
    bVar4 = UNK_00c571;
    if (1 < bVar4) {
      UNK_00c571 = 0;
      DAT_00c584 = 3;
      goto LAB_c12f6e;
    }
    kline_state_reset(0);
  }
  bVar4 = UNK_00c571;
  if (4 < bVar4) {
    kline_state_reset(0);
  }
LAB_c12f6e:
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar7 = DAT_00c5ab, cVar7 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar7 = DAT_00c57d;
  if (cVar7 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar7 = DAT_00c568;
    if (cVar7 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar7 = DAT_00c5b6;
  if (((cVar7 == '\0') && (cVar7 = kline_get_status(), cVar7 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar6 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar6 = true;
          break;
        }
        cVar7 = DAT_00c56c;
        DAT_00c56c = cVar7 + '\x01';
      }
      if (!bVar6) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12a16 gap_c12a16 size=108 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12a16(void)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  bool bVar6;
  char cVar7;
  
  uVar5 = P3;
  if ((uVar5 & 0x800) == 0) {
    kline_state_reset(0);
  }
  else {
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c599 = 0x46;
      DAT_00c57f = 2;
      DAT_00c598 = 0;
      DAT_00c580 = 0x14;
      DAT_00c592 = 0;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      DAT_00c599 = 0x46;
      DAT_00c57f = 2;
      DAT_00c598 = 0;
      DAT_00c580 = 0x14;
      DAT_00c592 = 0;
    }
    DAT_00c5a0 = 1;
    kline_prepare_frame(1);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar7 = DAT_00c5ab, cVar7 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar7 = DAT_00c57d;
  if (cVar7 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar7 = DAT_00c568;
    if (cVar7 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar7 = DAT_00c5b6;
  if (((cVar7 == '\0') && (cVar7 = kline_get_status(), cVar7 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar6 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar6 = true;
          break;
        }
        cVar7 = DAT_00c56c;
        DAT_00c56c = cVar7 + '\x01';
      }
      if (!bVar6) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12a78 gap_c12a78 size=98 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12a78(void)

{
  ushort uVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  byte bVar6;
  bool bVar7;
  char cVar8;
  ushort extraout_r10;
  ushort extraout_r10_00;
  short extraout_r11;
  short extraout_r11_00;
  short sVar9;
  
  gap_c28c54();
  if ((extraout_r11 + 0x9bb0U == (ushort)(extraout_r10 < 0x8625) && extraout_r10 == 0x8625) ||
     (gap_c28c54(),
     extraout_r11_00 + 0x79cdU == (ushort)(extraout_r10_00 < 0x6450) && extraout_r10_00 == 0x6450))
  {
    __disable_watchdog();
    uVar1 = PSW;
    PSW = uVar1 & 0xf7ff;
    __software_reset();
  }
  else {
    cVar8 = DAT_00c5a9;
    if (cVar8 == '\0') {
      sVar9 = DAT_00c5b4;
    }
    else {
      sVar9 = 2;
    }
    if (sVar9 == -1) {
      sVar9 = DAT_00c59e;
      if (sVar9 != -1) {
        sVar9 = DAT_00c59e;
        DAT_00c59e = sVar9 + 1;
      }
    }
    else {
      uVar1 = sVar9 + 1;
      uVar4 = DAT_00c59e;
      uVar5 = DAT_00c59e;
      if (uVar1 != uVar5 && uVar4 <= uVar1) {
        sVar9 = DAT_00c59e;
        DAT_00c59e = sVar9 + 1;
      }
      uVar4 = DAT_00c59e;
      uVar5 = DAT_00c59e;
      if (uVar1 == uVar5 || uVar1 < uVar4) {
        kline_state_reset(0);
      }
    }
  }
  sVar9 = DAT_00c56a;
  if (sVar9 != 0) {
    sVar9 = DAT_00c56a;
    DAT_00c56a = sVar9 + -1;
  }
  sVar9 = DAT_00c584;
  if (((sVar9 != 0xd) && (sVar9 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar1 = PSW;
    PSW = uVar1 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar9 = DAT_00c584, sVar9 == 0xd || (sVar9 == 10)))) {
    sVar9 = DAT_00c584;
    if (sVar9 == 9) {
      bVar6 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar6)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12ae8 gap_c12ae8 size=20 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12ae8(undefined2 param_1)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  bool bVar6;
  char cVar7;
  
  sVar1 = DAT_00c59e;
  if (sVar1 != -1) {
    sVar1 = DAT_00c59e;
    DAT_00c59e = sVar1 + 1;
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if ((sVar1 != 0xd) && (sVar1 != 10)) {
    cVar7 = DAT_00c5ab;
    if (cVar7 != '\0') {
      DAT_00c5ab = 0;
      uVar5 = PSW;
      PSW = uVar5 & 0xf7ff;
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    param_1 = 0;
  }
  cVar7 = DAT_00c57d;
  if (cVar7 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar7 = DAT_00c568;
    if (cVar7 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1(param_1);
    }
  }
  cVar7 = DAT_00c5b6;
  if ((((cVar7 == '\0') && (cVar7 = kline_get_status(), cVar7 == '\0')) ||
      (sVar1 = DAT_00c584, sVar1 == 0xd)) || (sVar1 == 10)) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar6 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar6 = true;
          break;
        }
        cVar7 = DAT_00c56c;
        DAT_00c56c = cVar7 + '\x01';
      }
      if (!bVar6) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12afc gap_c12afc size=74 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12afc(char param_1)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  
  sVar1 = DAT_00c5a2;
  if (sVar1 == 1) {
    sVar1 = DAT_00c5be;
    DAT_00c5be = sVar1 + 1;
  }
  sVar1 = DAT_00c5a2;
  if (sVar1 == 0) {
    sVar1 = DAT_00c5b0;
    DAT_00c5b0 = sVar1 + 1;
  }
  while( true ) {
    cVar6 = DAT_00c58c;
    cVar8 = DAT_00c56f;
    if (cVar6 == cVar8) {
      bVar7 = false;
    }
    else {
      bVar4 = DAT_00c56f;
      *(undefined1 *)ZEXT23(&param_1) = *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4);
      bVar4 = DAT_00c56f;
      cVar8 = DAT_00c56f;
      DAT_00c56f = cVar8 + '\x01';
      *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4) = 0;
      cVar8 = DAT_00c56f;
      if (cVar8 == '=') {
        DAT_00c56f = 0;
      }
      bVar7 = true;
    }
    if ((!bVar7) || (sVar1 = DAT_00c584, sVar1 != 7)) break;
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5be = 0;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      DAT_00c5b0 = 0;
    }
    cVar8 = UNK_00c5a1;
    UNK_00c5a1 = cVar8 + param_1;
    uVar5 = DAT_00c574;
    if (uVar5 < 6) {
                    /* WARNING: Could not emulate address calculation at 0xc12b42 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar5 * 2 + 0x7184 & 0x3fff) | 0xc10000))();
      return;
    }
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 1) && (uVar5 = DAT_00c5be, 2 < uVar5)) {
    gap_c126d2();
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 0) && (uVar5 = DAT_00c5b0, 9 < uVar5)) {
    gap_c126d2(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12b46 gap_c12b46 size=74 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12b46(char param_1)

{
  byte bVar1;
  short sVar2;
  undefined1 uVar3;
  byte bVar4;
  ushort uVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  
  UNK_00c5ae = param_1;
  bVar1 = UNK_00c5ae;
  UNK_00c5a1 = bVar1;
  UNK_00c56e = 0;
  UNK_00c578 = bVar1 & 0x3f;
  bVar1 = UNK_00c5ae;
  bVar1 = bVar1 & 0xc0;
  if ((bVar1 == 0x80) || (bVar1 == 0xc0)) {
    DAT_00c574 = 1;
  }
  else {
    if (bVar1 == 0) {
      cVar8 = DAT_00c57d;
      if (cVar8 != '\0') {
        cVar8 = UNK_00c578;
        if (cVar8 == '\0') {
          DAT_00c574 = 3;
        }
        else {
          gap_c1296e();
        }
        goto LAB_c12cb0;
      }
    }
    else if (bVar1 != 0x40) goto LAB_c12cb0;
    gap_c126d2();
  }
LAB_c12cb0:
  while( true ) {
    cVar6 = DAT_00c58c;
    cVar8 = DAT_00c56f;
    if (cVar6 == cVar8) {
      bVar7 = false;
    }
    else {
      bVar1 = DAT_00c56f;
      *(undefined1 *)ZEXT23(&param_1) = *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar1);
      bVar1 = DAT_00c56f;
      cVar8 = DAT_00c56f;
      DAT_00c56f = cVar8 + '\x01';
      *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar1) = 0;
      cVar8 = DAT_00c56f;
      if (cVar8 == '=') {
        DAT_00c56f = 0;
      }
      bVar7 = true;
    }
    if ((!bVar7) || (sVar2 = DAT_00c584, sVar2 != 7)) break;
    sVar2 = DAT_00c5a2;
    if (sVar2 == 1) {
      DAT_00c5be = 0;
    }
    sVar2 = DAT_00c5a2;
    if (sVar2 == 0) {
      DAT_00c5b0 = 0;
    }
    cVar8 = UNK_00c5a1;
    UNK_00c5a1 = cVar8 + param_1;
    uVar5 = DAT_00c574;
    if (uVar5 < 6) {
                    /* WARNING: Could not emulate address calculation at 0xc12b42 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar5 * 2 + 0x7184 & 0x3fff) | 0xc10000))();
      return;
    }
  }
  sVar2 = DAT_00c5a2;
  if ((sVar2 == 1) && (uVar5 = DAT_00c5be, 2 < uVar5)) {
    gap_c126d2();
  }
  sVar2 = DAT_00c5a2;
  if ((sVar2 == 0) && (uVar5 = DAT_00c5b0, 9 < uVar5)) {
    gap_c126d2(0);
  }
  sVar2 = DAT_00c56a;
  if (sVar2 != 0) {
    sVar2 = DAT_00c56a;
    DAT_00c56a = sVar2 + -1;
  }
  sVar2 = DAT_00c584;
  if (((sVar2 != 0xd) && (sVar2 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar2 = DAT_00c584, sVar2 == 0xd || (sVar2 == 10)))) {
    sVar2 = DAT_00c584;
    if (sVar2 == 9) {
      bVar1 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar4 = DAT_00c56c, bVar4 <= DAT_007162) {
        bVar4 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar4 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar1)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar3 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12b90 gap_c12b90 size=122 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12b90(char param_1)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  
  UNK_00c5aa = param_1;
  bVar4 = UNK_00c5ae;
  if (((bVar4 & 0x80) == 0) || (cVar8 = UNK_00c5aa, cVar8 != '\x11')) {
    bVar4 = UNK_00c5ae;
    if (((((bVar4 & 0xc0) == 0) || (cVar8 = UNK_00c5aa, cVar8 != '3')) &&
        (((bVar4 & 0xc0) == 0 || (cVar8 = UNK_00c5aa, cVar8 != '\x10')))) &&
       ((bVar4 = UNK_00c5ae, (bVar4 & 0x80) == 0 || (cVar8 = UNK_00c5aa, cVar8 != '\x17')))) {
      gap_c126d2();
      goto LAB_c12cb0;
    }
  }
  DAT_00c574 = 2;
  bVar4 = UNK_00c5ae;
  if ((((bVar4 & 0xc0) != 0) && (cVar8 = UNK_00c5aa, cVar8 == '3')) ||
     (((bVar4 & 0xc0) != 0 && (cVar8 = UNK_00c5aa, cVar8 == '\x10')))) {
    UNK_00c56e = 1;
  }
LAB_c12cb0:
  while( true ) {
    cVar6 = DAT_00c58c;
    cVar8 = DAT_00c56f;
    if (cVar6 == cVar8) {
      bVar7 = false;
    }
    else {
      bVar4 = DAT_00c56f;
      *(undefined1 *)ZEXT23(&param_1) = *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4);
      bVar4 = DAT_00c56f;
      cVar8 = DAT_00c56f;
      DAT_00c56f = cVar8 + '\x01';
      *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4) = 0;
      cVar8 = DAT_00c56f;
      if (cVar8 == '=') {
        DAT_00c56f = 0;
      }
      bVar7 = true;
    }
    if ((!bVar7) || (sVar1 = DAT_00c584, sVar1 != 7)) break;
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5be = 0;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      DAT_00c5b0 = 0;
    }
    cVar8 = UNK_00c5a1;
    UNK_00c5a1 = cVar8 + param_1;
    uVar5 = DAT_00c574;
    if (uVar5 < 6) {
                    /* WARNING: Could not emulate address calculation at 0xc12b42 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar5 * 2 + 0x7184 & 0x3fff) | 0xc10000))();
      return;
    }
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 1) && (uVar5 = DAT_00c5be, 2 < uVar5)) {
    gap_c126d2();
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 0) && (uVar5 = DAT_00c5b0, 9 < uVar5)) {
    gap_c126d2(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12c0a gap_c12c0a size=40 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12c0a(char param_1)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  
  UNK_00c594 = param_1;
  cVar8 = UNK_00c594;
  if (((cVar8 == -0x10) || (cVar8 == -0xf)) || (cVar8 == -0x3f)) {
    cVar8 = UNK_00c578;
    if (cVar8 == '\0') {
      DAT_00c574 = 3;
    }
    else {
      gap_c1296e();
    }
  }
  else {
    gap_c126d2();
  }
  while( true ) {
    cVar6 = DAT_00c58c;
    cVar8 = DAT_00c56f;
    if (cVar6 == cVar8) {
      bVar7 = false;
    }
    else {
      bVar4 = DAT_00c56f;
      *(undefined1 *)ZEXT23(&param_1) = *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4);
      bVar4 = DAT_00c56f;
      cVar8 = DAT_00c56f;
      DAT_00c56f = cVar8 + '\x01';
      *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4) = 0;
      cVar8 = DAT_00c56f;
      if (cVar8 == '=') {
        DAT_00c56f = 0;
      }
      bVar7 = true;
    }
    if ((!bVar7) || (sVar1 = DAT_00c584, sVar1 != 7)) break;
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5be = 0;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      DAT_00c5b0 = 0;
    }
    cVar8 = UNK_00c5a1;
    UNK_00c5a1 = cVar8 + param_1;
    uVar5 = DAT_00c574;
    if (uVar5 < 6) {
                    /* WARNING: Could not emulate address calculation at 0xc12b42 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar5 * 2 + 0x7184 & 0x3fff) | 0xc10000))();
      return;
    }
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 1) && (uVar5 = DAT_00c5be, 2 < uVar5)) {
    gap_c126d2();
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 0) && (uVar5 = DAT_00c5b0, 9 < uVar5)) {
    gap_c126d2(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12c32 gap_c12c32 size=20 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12c32(char param_1)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  
  UNK_00c578 = param_1;
  bVar4 = UNK_00c578;
  if (bVar4 < 0x85) {
    gap_c1296e();
  }
  else {
    gap_c126d2();
  }
  while( true ) {
    cVar6 = DAT_00c58c;
    cVar8 = DAT_00c56f;
    if (cVar6 == cVar8) {
      bVar7 = false;
    }
    else {
      bVar4 = DAT_00c56f;
      *(undefined1 *)ZEXT23(&param_1) = *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4);
      bVar4 = DAT_00c56f;
      cVar8 = DAT_00c56f;
      DAT_00c56f = cVar8 + '\x01';
      *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4) = 0;
      cVar8 = DAT_00c56f;
      if (cVar8 == '=') {
        DAT_00c56f = 0;
      }
      bVar7 = true;
    }
    if ((!bVar7) || (sVar1 = DAT_00c584, sVar1 != 7)) break;
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5be = 0;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      DAT_00c5b0 = 0;
    }
    cVar8 = UNK_00c5a1;
    UNK_00c5a1 = cVar8 + param_1;
    uVar5 = DAT_00c574;
    if (uVar5 < 6) {
                    /* WARNING: Could not emulate address calculation at 0xc12b42 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar5 * 2 + 0x7184 & 0x3fff) | 0xc10000))();
      return;
    }
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 1) && (uVar5 = DAT_00c5be, 2 < uVar5)) {
    gap_c126d2();
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 0) && (uVar5 = DAT_00c5b0, 9 < uVar5)) {
    gap_c126d2(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12c46 gap_c12c46 size=76 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12c46(char param_1)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  
  bVar3 = DAT_00c5c4;
  bVar4 = UNK_00c570;
  *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar3 + (ushort)bVar4) = param_1;
  cVar6 = DAT_00c5c4;
  cVar8 = UNK_00c570;
  UNK_00c589 = cVar6 + cVar8;
  cVar8 = UNK_00c570;
  UNK_00c570 = cVar8 + '\x01';
  cVar8 = UNK_00c570;
  if (cVar8 == -0x78) {
    UNK_00c570 = 0;
    gap_c126d2();
  }
  else {
    cVar8 = UNK_00c570;
    cVar6 = UNK_00c578;
    if (cVar8 == cVar6) {
      cVar8 = UNK_00c589;
      UNK_00c5c7 = cVar8 + '\x01';
      DAT_00c574 = 5;
    }
  }
  while( true ) {
    cVar6 = DAT_00c58c;
    cVar8 = DAT_00c56f;
    if (cVar6 == cVar8) {
      bVar7 = false;
    }
    else {
      bVar4 = DAT_00c56f;
      *(undefined1 *)ZEXT23(&param_1) = *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4);
      bVar4 = DAT_00c56f;
      cVar8 = DAT_00c56f;
      DAT_00c56f = cVar8 + '\x01';
      *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4) = 0;
      cVar8 = DAT_00c56f;
      if (cVar8 == '=') {
        DAT_00c56f = 0;
      }
      bVar7 = true;
    }
    if ((!bVar7) || (sVar1 = DAT_00c584, sVar1 != 7)) break;
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5be = 0;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      DAT_00c5b0 = 0;
    }
    cVar8 = UNK_00c5a1;
    UNK_00c5a1 = cVar8 + param_1;
    uVar5 = DAT_00c574;
    if (uVar5 < 6) {
                    /* WARNING: Could not emulate address calculation at 0xc12b42 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar5 * 2 + 0x7184 & 0x3fff) | 0xc10000))();
      return;
    }
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 1) && (uVar5 = DAT_00c5be, 2 < uVar5)) {
    gap_c126d2();
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 0) && (uVar5 = DAT_00c5b0, 9 < uVar5)) {
    gap_c126d2(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12c92 gap_c12c92 size=18 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12c92(char param_1)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  
  cVar8 = UNK_00c5a1;
  if ((char)(cVar8 + param_1 * -2) == '\0') {
    kline_rx_state_8();
  }
  else {
    gap_c126d2();
  }
  while( true ) {
    cVar6 = DAT_00c58c;
    cVar8 = DAT_00c56f;
    if (cVar6 == cVar8) {
      bVar7 = false;
    }
    else {
      bVar4 = DAT_00c56f;
      *(undefined1 *)ZEXT23(&param_1) = *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4);
      bVar4 = DAT_00c56f;
      cVar8 = DAT_00c56f;
      DAT_00c56f = cVar8 + '\x01';
      *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4) = 0;
      cVar8 = DAT_00c56f;
      if (cVar8 == '=') {
        DAT_00c56f = 0;
      }
      bVar7 = true;
    }
    if ((!bVar7) || (sVar1 = DAT_00c584, sVar1 != 7)) break;
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5be = 0;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      DAT_00c5b0 = 0;
    }
    cVar8 = UNK_00c5a1;
    UNK_00c5a1 = cVar8 + param_1;
    uVar5 = DAT_00c574;
    if (uVar5 < 6) {
                    /* WARNING: Could not emulate address calculation at 0xc12b42 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar5 * 2 + 0x7184 & 0x3fff) | 0xc10000))();
      return;
    }
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 1) && (uVar5 = DAT_00c5be, 2 < uVar5)) {
    gap_c126d2();
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 0) && (uVar5 = DAT_00c5b0, 9 < uVar5)) {
    gap_c126d2(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12ca4 gap_c12ca4 size=126 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12ca4(char param_1)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  
  kline_rx_state_8();
  while( true ) {
    cVar6 = DAT_00c58c;
    cVar8 = DAT_00c56f;
    if (cVar6 == cVar8) {
      bVar7 = false;
    }
    else {
      bVar4 = DAT_00c56f;
      *(undefined1 *)ZEXT23(&param_1) = *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4);
      bVar4 = DAT_00c56f;
      cVar8 = DAT_00c56f;
      DAT_00c56f = cVar8 + '\x01';
      *(undefined1 *)(uint3)((short)&DAT_00f600 + (ushort)bVar4) = 0;
      cVar8 = DAT_00c56f;
      if (cVar8 == '=') {
        DAT_00c56f = 0;
      }
      bVar7 = true;
    }
    if ((!bVar7) || (sVar1 = DAT_00c584, sVar1 != 7)) break;
    sVar1 = DAT_00c5a2;
    if (sVar1 == 1) {
      DAT_00c5be = 0;
    }
    sVar1 = DAT_00c5a2;
    if (sVar1 == 0) {
      DAT_00c5b0 = 0;
    }
    cVar8 = UNK_00c5a1;
    UNK_00c5a1 = cVar8 + param_1;
    uVar5 = DAT_00c574;
    if (uVar5 < 6) {
                    /* WARNING: Could not emulate address calculation at 0xc12b42 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)(uVar5 * 2 + 0x7184 & 0x3fff) | 0xc10000))();
      return;
    }
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 1) && (uVar5 = DAT_00c5be, 2 < uVar5)) {
    gap_c126d2();
  }
  sVar1 = DAT_00c5a2;
  if ((sVar1 == 0) && (uVar5 = DAT_00c5b0, 9 < uVar5)) {
    gap_c126d2(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12d28 gap_c12d28 size=438 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12d28(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  bool bVar7;
  char cVar8;
  
  cVar8 = DAT_00c57d;
  if ((cVar8 == '\0') &&
     (bVar6 = DAT_00c5c4, *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar6) != -0x7f)) {
LAB_c12ed6:
    kline_state_reset(1);
  }
  else {
    bVar6 = DAT_00c5c4;
    DAT_00c5ac = 1;
    cVar8 = *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar6);
    if (cVar8 == -0x7f) {
      cVar8 = UNK_00c578;
      if ((cVar8 == '\x01') && (uVar1 = Ram00fd16, (uVar1 & 1) == 0)) {
        bVar6 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar6) = 0xef;
        *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar6) = 0x8f;
        gap_c12910(3);
        DAT_00c57d = 1;
        uVar1 = Ram00fd16;
        Ram00fd16 = uVar1 | 2;
        goto LAB_c12f6e;
      }
      cVar8 = DAT_00c57d;
      if (cVar8 == '\0') goto LAB_c12ed6;
    }
    else if (cVar8 == -0x7e) {
      cVar8 = UNK_00c578;
      if (cVar8 == '\x01') {
        gap_c12910(1);
        DAT_00c57d = 0;
        goto LAB_c12f6e;
      }
    }
    else {
      if (cVar8 != -0x7d) {
        UNK_00c58a = 0;
        DAT_00c584 = 9;
        goto LAB_c12f6e;
      }
      bVar6 = DAT_00c5c4;
      uVar1 = (short)&UNK_00f63e + (ushort)bVar6;
      cVar8 = *(char *)(uint3)uVar1;
      if (cVar8 == '\0') {
        cVar8 = UNK_00c578;
        if (cVar8 == '\x02') {
          bVar6 = UNK_00c5c7;
          uVar2 = (ushort)bVar6;
          *(undefined1 *)(uint3)((short)&UNK_00f63e + uVar2) = *(undefined1 *)(uint3)uVar1;
          *(undefined1 *)(uint3)((short)&UNK_00f63f + uVar2) = 0;
          *(undefined1 *)(uint3)((short)&UNK_00f640 + uVar2) = 0xff;
          *(undefined1 *)(uint3)((short)&UNK_00f641 + uVar2) = 0;
          *(undefined1 *)(uint3)((short)&UNK_00f642 + uVar2) = 0xff;
          *(undefined1 *)(uint3)((short)&UNK_00f643 + uVar2) = 0;
LAB_c12e64:
          gap_c12910(7);
          goto LAB_c12f6e;
        }
      }
      else if (cVar8 == '\x01') {
        cVar8 = UNK_00c578;
        if (cVar8 == '\x02') {
          DAT_00c599 = 0x46;
          DAT_00c57f = 2;
          DAT_00c598 = 0;
          DAT_00c580 = 0x14;
          DAT_00c592 = 0;
LAB_c12ea2:
          DAT_00c5a0 = 1;
LAB_c12ea8:
          bVar6 = DAT_00c5c4;
          bVar5 = UNK_00c5c7;
          *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar5) =
               *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar6);
          gap_c12910(2);
          goto LAB_c12f6e;
        }
      }
      else if (cVar8 == '\x02') {
        cVar8 = UNK_00c578;
        if (cVar8 == '\x02') {
          bVar6 = UNK_00c5c7;
          uVar2 = (ushort)bVar6;
          *(undefined1 *)(uint3)((short)&UNK_00f63e + uVar2) = *(undefined1 *)(uint3)uVar1;
          uVar4 = DAT_00c57c;
          *(undefined1 *)(uint3)((short)&UNK_00f63f + uVar2) = uVar4;
          uVar4 = DAT_00c5a5;
          *(undefined1 *)(uint3)((short)&UNK_00f640 + uVar2) = uVar4;
          uVar4 = DAT_00c57e;
          *(undefined1 *)(uint3)((short)&UNK_00f641 + uVar2) = uVar4;
          uVar4 = DAT_00c5a8;
          *(undefined1 *)(uint3)((short)&UNK_00f642 + uVar2) = uVar4;
          uVar4 = DAT_00c577;
          *(undefined1 *)(uint3)((short)&UNK_00f643 + uVar2) = uVar4;
          goto LAB_c12e64;
        }
      }
      else if (cVar8 == '\x03') {
        cVar8 = UNK_00c578;
        if (cVar8 == '\a') {
          bVar6 = DAT_00c5c4;
          uVar1 = (ushort)bVar6;
          DAT_00c599 = *(undefined1 *)(uint3)((short)&UNK_00f63f + uVar1);
          DAT_00c57f = *(undefined1 *)(uint3)((short)&UNK_00f640 + uVar1);
          DAT_00c598 = *(undefined1 *)(uint3)((short)&UNK_00f641 + uVar1);
          DAT_00c580 = *(undefined1 *)(uint3)((short)&UNK_00f642 + uVar1);
          DAT_00c592 = *(undefined1 *)(uint3)((short)&UNK_00f643 + uVar1);
          goto LAB_c12ea2;
        }
        goto LAB_c12ea8;
      }
    }
    func_0xc128ec(0x12);
  }
LAB_c12f6e:
  sVar3 = DAT_00c56a;
  if (sVar3 != 0) {
    sVar3 = DAT_00c56a;
    DAT_00c56a = sVar3 + -1;
  }
  sVar3 = DAT_00c584;
  if (((sVar3 != 0xd) && (sVar3 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar1 = PSW;
    PSW = uVar1 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar3 = DAT_00c584, sVar3 == 0xd || (sVar3 == 10)))) {
    sVar3 = DAT_00c584;
    if (sVar3 == 9) {
      bVar6 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar5 = DAT_00c56c, bVar5 <= DAT_007162) {
        bVar5 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar5 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar6)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar4 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12ede gap_c12ede size=50 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12ede(void)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  byte bVar6;
  bool bVar7;
  char cVar8;
  ushort uVar9;
  
  uVar4 = DAT_00c5ac;
  uVar9 = DAT_00c5a6;
  if (uVar4 < uVar9) {
    sVar1 = DAT_00c5ac;
    DAT_00c5ac = sVar1 + 1;
  }
  uVar9 = DAT_00c59c;
  if (uVar9 == 0xffff) {
    uVar9 = 0xfffe;
  }
  uVar4 = DAT_00c5ba;
  uVar5 = DAT_00c5ba;
  if (uVar9 != uVar5 && uVar4 <= uVar9) {
    sVar1 = DAT_00c5ba;
    DAT_00c5ba = sVar1 + 1;
  }
  uVar4 = DAT_00c5ba;
  uVar5 = DAT_00c5ba;
  if (uVar9 == uVar5 || uVar9 < uVar4) {
    kline_prepare_frame(0);
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar9 = PSW;
    PSW = uVar9 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar6 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar6)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12f10 gap_c12f10 size=48 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12f10(void)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  byte bVar6;
  bool bVar7;
  char cVar8;
  
  uVar5 = DAT_00c5ac;
  uVar4 = DAT_00c5a6;
  if (uVar5 < uVar4) {
    sVar1 = DAT_00c5ac;
    DAT_00c5ac = sVar1 + 1;
  }
  uVar5 = DAT_00c5ac;
  uVar4 = DAT_00c5a6;
  if (uVar4 <= uVar5) {
    cVar8 = UNK_00c58a;
    if (cVar8 == '\0') {
      func_0xc127fe();
    }
    else {
      func_0xc128c6(cVar8);
      UNK_00c58a = 0;
    }
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar8 = DAT_00c5ab, cVar8 != '\0')) {
    DAT_00c5ab = 0;
    uVar4 = PSW;
    PSW = uVar4 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar8 = DAT_00c57d;
  if (cVar8 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar8 = DAT_00c568;
    if (cVar8 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar8 = DAT_00c5b6;
  if (((cVar8 == '\0') && (cVar8 = kline_get_status(), cVar8 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar6 = DAT_00c5c4;
      bVar7 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar6)) {
          empty_stub_0();
          bVar7 = true;
          break;
        }
        cVar8 = DAT_00c56c;
        DAT_00c56c = cVar8 + '\x01';
      }
      if (!bVar7) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12f40 gap_c12f40 size=6 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12f40(void)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  bool bVar6;
  char cVar7;
  
  func_0xc1297a();
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar7 = DAT_00c5ab, cVar7 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar7 = DAT_00c57d;
  if (cVar7 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar7 = DAT_00c568;
    if (cVar7 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar7 = DAT_00c5b6;
  if (((cVar7 == '\0') && (cVar7 = kline_get_status(), cVar7 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar6 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar6 = true;
          break;
        }
        cVar7 = DAT_00c56c;
        DAT_00c56c = cVar7 + '\x01';
      }
      if (!bVar6) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c12f46 gap_c12f46 size=280 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c12f46(void)

{
  short sVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  bool bVar6;
  char cVar7;
  
  uVar5 = S0CON;
  S0CON = uVar5 & 0xffef;
  uVar5 = P3;
  if ((uVar5 & 0x800) == 0) {
    DAT_00c588 = 0;
    DAT_00c582 = 0;
    func_0xc1281a();
  }
  else {
    cVar7 = DAT_00c588;
    DAT_00c588 = cVar7 + '\x01';
    bVar3 = DAT_00c588;
    bVar4 = DAT_00c582;
    if (bVar4 <= bVar3) {
      DAT_00c584 = 1;
    }
  }
  sVar1 = DAT_00c56a;
  if (sVar1 != 0) {
    sVar1 = DAT_00c56a;
    DAT_00c56a = sVar1 + -1;
  }
  sVar1 = DAT_00c584;
  if (((sVar1 != 0xd) && (sVar1 != 10)) && (cVar7 = DAT_00c5ab, cVar7 != '\0')) {
    DAT_00c5ab = 0;
    uVar5 = PSW;
    PSW = uVar5 & 0xf7ff;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  cVar7 = DAT_00c57d;
  if (cVar7 == '\0') {
    DAT_00c568 = 0;
  }
  else {
    cVar7 = DAT_00c568;
    if (cVar7 == '\0') {
      DAT_00c568 = 1;
      empty_stub_1();
    }
  }
  cVar7 = DAT_00c5b6;
  if (((cVar7 == '\0') && (cVar7 = kline_get_status(), cVar7 == '\0')) ||
     ((sVar1 = DAT_00c584, sVar1 == 0xd || (sVar1 == 10)))) {
    sVar1 = DAT_00c584;
    if (sVar1 == 9) {
      bVar4 = DAT_00c5c4;
      bVar6 = false;
      DAT_00c56c = 0;
      while (bVar3 = DAT_00c56c, bVar3 <= DAT_007162) {
        bVar3 = DAT_00c56c;
        if (*(char *)(uint3)((ushort)bVar3 * 10 + 0x70c2) ==
            *(char *)(uint3)((short)&UNK_00f63d + (ushort)bVar4)) {
          empty_stub_0();
          bVar6 = true;
          break;
        }
        cVar7 = DAT_00c56c;
        DAT_00c56c = cVar7 + '\x01';
      }
      if (!bVar6) {
        empty_stub_0();
      }
    }
  }
  else {
    uVar2 = DAT_00c56c;
    empty_stub_0();
  }
  return;
}



/* ===== c1305e gap_c1305e size=84 ===== */

void gap_c1305e(char param_1,ushort param_2,ushort param_3,char param_4)

{
  char cVar1;
  
  if (param_1 == '\0') {
    *(undefined1 *)(uint3)param_2 = 0;
    return;
  }
  if (param_1 == '\a') {
    *(undefined1 *)(uint3)param_2 = 1;
  }
  else if (param_1 == -0x80) {
    *(undefined1 *)(uint3)param_2 = 2;
  }
  else {
    if (param_1 != -0x7f) {
      func_0xc13a92(1);
      return;
    }
    *(undefined1 *)(uint3)param_2 = 0x82;
  }
  cVar1 = func_0xc13a84();
  *(char *)(uint3)param_3 = cVar1 * param_4;
  return;
}



/* ===== c130b2 gap_c130b2 size=82 ===== */

void gap_c130b2(char param_1,ushort param_2,ushort param_3,short param_4)

{
  short sVar1;
  
  if (param_1 == '\0') {
    *(undefined1 *)(uint3)param_2 = 0;
    return;
  }
  if (param_1 == '\a') {
    *(undefined1 *)(uint3)param_2 = 1;
  }
  else if (param_1 == -0x80) {
    *(undefined1 *)(uint3)param_2 = 2;
  }
  else {
    if (param_1 != -0x7f) {
      func_0xc13a92(1);
      return;
    }
    *(undefined1 *)(uint3)param_2 = 0x82;
  }
  sVar1 = func_0xc13a84();
  *(short *)(uint3)param_3 = sVar1 * param_4;
  return;
}



/* ===== c13104 gap_c13104 size=46 ===== */

undefined2 gap_c13104(void)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  
  cVar1 = UNK_00c5e2;
  if (cVar1 == '\0') {
    uVar4 = DAT_00fd18;
    DAT_00fd18 = uVar4 & 0xfffe;
  }
  else {
    if (cVar1 != '\a') {
      return 0;
    }
    bVar3 = DAT_00fd18._0_1_;
    if ((bVar3 & 0x7f) != 0) {
      return 0;
    }
    sVar2 = DAT_00c5e6;
    if (sVar2 == 0) {
      return 0;
    }
    DAT_00fd18._0_1_ = 0x81;
  }
  return 1;
}



/* ===== c13132 gap_c13132 size=46 ===== */

undefined2 gap_c13132(void)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  
  cVar1 = UNK_00c5e2;
  if (cVar1 == '\0') {
    uVar4 = DAT_00fd18;
    DAT_00fd18 = uVar4 & 0xfffd;
  }
  else {
    if (cVar1 != '\a') {
      return 0;
    }
    bVar3 = DAT_00fd18._0_1_;
    if ((bVar3 & 0x7f) != 0) {
      return 0;
    }
    sVar2 = DAT_00c5e6;
    if (sVar2 == 0) {
      return 0;
    }
    DAT_00fd18._0_1_ = 0x82;
  }
  return 1;
}



/* ===== c13160 gap_c13160 size=46 ===== */

undefined2 gap_c13160(void)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  
  cVar1 = UNK_00c5e2;
  if (cVar1 == '\0') {
    uVar4 = DAT_00fd18;
    DAT_00fd18 = uVar4 & 0xfff7;
  }
  else {
    if (cVar1 != '\a') {
      return 0;
    }
    bVar3 = DAT_00fd18._0_1_;
    if ((bVar3 & 0x7f) != 0) {
      return 0;
    }
    sVar2 = DAT_00c5e6;
    if (sVar2 == 0) {
      return 0;
    }
    DAT_00fd18._0_1_ = 0x88;
  }
  return 1;
}



/* ===== c1318e gap_c1318e size=46 ===== */

undefined2 gap_c1318e(void)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  
  cVar1 = UNK_00c5e2;
  if (cVar1 == '\0') {
    uVar4 = DAT_00fd18;
    DAT_00fd18 = uVar4 & 0xfffb;
  }
  else {
    if (cVar1 != '\a') {
      return 0;
    }
    bVar3 = DAT_00fd18._0_1_;
    if ((bVar3 & 0x7f) != 0) {
      return 0;
    }
    sVar2 = DAT_00c5e6;
    if (sVar2 == 0) {
      return 0;
    }
    DAT_00fd18._0_1_ = 0x84;
  }
  return 1;
}



/* ===== c131ce gap_c131ce size=8 ===== */

void gap_c131ce(void)

{
  Ram00c5c2 = 1;
  return;
}



/* ===== c131d6 gap_c131d6 size=278 ===== */

void gap_c131d6(void)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  
  bVar2 = DAT_00c5c4;
  uVar1 = *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2);
  bVar2 = UNK_00c5c7;
  UNK_00c5c8 = uVar1;
  *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar1;
  UNK_00c5c0 = 0;
  UNK_00c5c5 = 0;
  cVar4 = UNK_00c578;
  if ((cVar4 == '\x03') || (cVar4 == '\x02')) {
    cVar4 = UNK_00c578;
    if (cVar4 == '\x02') {
      cVar4 = UNK_00c5c8;
      if (cVar4 == -0x7f) {
        cVar4 = func_0xc131be();
        if (cVar4 == '\0') {
          UNK_00c5c0 = 1;
          Ram00c5c2 = 0;
        }
        else {
          DAT_00c5ab = 1;
        }
        gap_c12910(2);
        return;
      }
      if (cVar4 == -0x7b) {
        cVar4 = func_0xc125e6();
        if (cVar4 == '\0') {
          func_0xc12688();
          return;
        }
        gap_c131ce();
        func_0xc12690();
        uVar3 = DAT_00fd14;
        DAT_00fd14 = uVar3 | 0x2000;
        gap_c12910(2);
        store32();
        return;
      }
    }
    else {
      cVar4 = UNK_00c5c8;
      if (cVar4 == -0x7b) {
        cVar4 = func_0xc125e6();
        if (cVar4 == '\0') {
          func_0xc12688();
          bVar2 = DAT_00c5c4;
          UNK_00c5c9 = *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2);
          UNK_00c5c5 = 1;
          return;
        }
        gap_c131ce();
        func_0xc12690();
        bVar2 = DAT_00c5c4;
        uVar1 = *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2);
        bVar2 = UNK_00c5c7;
        UNK_00c5c9 = uVar1;
        *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar1;
        cVar4 = UNK_00c5c9;
        if (cVar4 == '\x03') {
          gap_c12910(3);
          store32();
          return;
        }
        func_0xc128ec(0x31);
        return;
      }
    }
  }
  func_0xc128ec(0x12);
  return;
}



/* ===== c132ec gap_c132ec size=46 ===== */

void gap_c132ec(void)

{
  char cVar1;
  
  func_0xc12690();
  cVar1 = func_0xc125e6();
  if (cVar1 == '\0') {
    func_0xc128ec(0x22);
    return;
  }
  gap_c131ce();
  cVar1 = UNK_00c5c5;
  if (cVar1 != '\0') {
    UNK_00c5c5 = 0;
    return;
  }
  gap_c12910(2);
  return;
}



/* ===== c1331a gap_c1331a size=112 ===== */

void gap_c1331a(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  undefined2 uStack_2;
  
  bVar4 = DAT_00c5c4;
  uVar1 = *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar4);
  uVar2 = *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar4);
  uStack_2 = CONCAT11(uVar2,uVar1);
  cVar3 = UNK_00c578;
  if ((cVar3 == '\x03') && ((uStack_2 == 0 || (uStack_2 == -0x100)))) {
    gap_c25732(uStack_2);
    bVar4 = UNK_00c5c7;
    *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar4) = uVar1;
    bVar4 = UNK_00c5c7;
    *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar4) = uVar2;
    gap_c12910(3);
  }
  else {
    func_0xc128ec(0x12);
  }
  return;
}



/* ===== c1338a gap_c1338a size=250 ===== */

/* WARNING: Removing unreachable block (ram,0xc13426) */
/* WARNING: Removing unreachable block (ram,0xc1342a) */

void gap_c1338a(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  char cVar5;
  char cVar6;
  ushort uVar7;
  byte bVar8;
  undefined2 uStack_8;
  
  bVar8 = DAT_00c5c4;
  uVar7 = (ushort)bVar8;
  uStack_8 = CONCAT11(*(undefined1 *)(uint3)((short)&UNK_00f640 + uVar7),
                      *(undefined1 *)(uint3)((short)&UNK_00f63f + uVar7));
  cVar5 = UNK_00c578;
  if (cVar5 == '\x04') {
    if (*(char *)(uint3)((short)&UNK_00f63e + uVar7) == '\0') {
      if (uStack_8 == 0) {
        Ram00c5d2 = 0;
        Ram00c5ce = 0x3fff;
      }
      else {
        Ram00c5d2 = uStack_8;
        Ram00c5ce = uStack_8;
      }
      UNK_00c5ca = 0;
      UNK_00c5cc = 0;
      UNK_00c5cd = 0;
      UNK_00c5cb = 2;
      cVar5 = '\0';
      for (bVar8 = 0; bVar8 < uRam00735a; bVar8 = bVar8 + 1) {
        uVar7 = func_0xc2425c(bVar8);
        cVar6 = func_0xc24286(bVar8);
        if ((cVar6 != '\0') && (uVar1 = Ram00c5d2, uVar1 <= uVar7)) {
          uVar1 = Ram00c5ce;
          uVar2 = Ram00c5ce;
          if ((uVar7 == uVar2 || uVar7 < uVar1) &&
             ((cVar6 = func_0xc24530(bVar8), cVar6 != '\0' ||
              (((byte)((ushort)*(undefined2 *)(uint3)((short)&UNK_00c168 + (ushort)bVar8 * 2) >> 0xb
                      ) & 1) != 0)))) {
            cVar5 = cVar5 + '\x01';
          }
        }
      }
      UNK_00c5d0 = cVar5;
      sVar4 = Ram00c5d2;
      sVar3 = Ram00c5ce;
      if ((sVar4 != sVar3) || (cVar5 != '\0')) {
        DAT_00c5b6 = 1;
        return;
      }
    }
    func_0xc128ec(0x31);
  }
  else {
    func_0xc128ec(0x12);
  }
  return;
}



/* ===== c13484 gap_c13484 size=456 ===== */

void gap_c13484(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  undefined1 uVar6;
  short sVar7;
  char cVar8;
  char cVar9;
  ushort uVar10;
  byte bStack_8;
  
  bVar1 = UNK_00c5c7;
  uVar6 = UNK_00c5d0;
  *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) = uVar6;
  do {
    bVar1 = UNK_00c5cc;
    if (uRam00735a <= bVar1) {
LAB_c13608:
      bVar1 = UNK_00c5cb;
      if (bVar1 < 2) {
        gap_c12910(0);
      }
      else {
        gap_c12910(bVar1);
      }
      bVar1 = UNK_00c5cc;
      if ((bVar1 < uRam00735a) && (bVar1 = UNK_00c5cb, 0x85 < bVar1)) {
        UNK_00c5cb = 1;
        DAT_00c5b6 = 1;
      }
      else {
        DAT_00c5b6 = 0;
      }
      return;
    }
    cVar9 = UNK_00c5cd;
    bVar1 = UNK_00c5cc;
    Ram00c5d4 = 0;
    UNK_00c5d7 = 0;
    UNK_00c5d8 = 0;
    uVar10 = func_0xc2425c(bVar1);
    cVar8 = func_0xc24286(bVar1);
    if ((cVar8 != '\0') && (uVar3 = Ram00c5d2, uVar3 <= uVar10)) {
      uVar3 = Ram00c5ce;
      uVar4 = Ram00c5ce;
      if ((uVar10 == uVar4 || uVar10 < uVar3) &&
         ((cVar9 == '\x01' ||
          ((cVar9 == '\0' &&
           ((cVar9 = func_0xc24530(bVar1), cVar9 != '\0' ||
            (((byte)((ushort)*(undefined2 *)(uint3)((short)&UNK_00c168 + (ushort)bVar1 * 2) >> 0xb)
             & 1) != 0)))))))) {
        cVar9 = func_0xc245fa(bVar1);
        bVar2 = cVar9 << 7;
        cVar9 = func_0xc24530(bVar1);
        if (cVar9 == '\0') {
          cVar9 = func_0xc2465c(bVar1);
          if (cVar9 != '\0') {
            bVar2 = bStack_8 & 0x50 | bVar2 | 0x60;
          }
        }
        else {
          cVar9 = func_0xc2465c(bVar1);
          if (cVar9 == '\0') {
            bVar2 = bStack_8 & 0x30 | bVar2 | 0x60;
          }
          else {
            bVar2 = bVar2 | 0x60;
          }
        }
        cVar9 = func_0xc2446c(bVar1);
        if ((cVar9 == '\0') || (cVar9 = gap_c244ce(bVar1), cVar9 != '\0')) {
          bStack_8 = bVar2 & 0xef;
        }
        else {
          bStack_8 = bVar2 & 0xef | 0x10;
        }
        Ram00c5d4 = uVar10;
        UNK_00c5d7 = bStack_8;
        UNK_00c5d8 = 1;
      }
    }
    cVar9 = UNK_00c5d8;
    if (cVar9 != '\0') {
      cVar9 = UNK_00c5ca;
      UNK_00c5ca = cVar9 + '\x01';
      bVar2 = UNK_00c5cb;
      bVar1 = UNK_00c5c7;
      uVar6 = UNK_00c5d4;
      cVar9 = UNK_00c5cb;
      UNK_00c5cb = cVar9 + '\x01';
      *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar1 + (ushort)bVar2) = uVar6;
      bVar2 = UNK_00c5cb;
      bVar1 = UNK_00c5c7;
      uVar6 = UNK_00c5d5;
      cVar9 = UNK_00c5cb;
      UNK_00c5cb = cVar9 + '\x01';
      *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar1 + (ushort)bVar2) = uVar6;
      bVar2 = UNK_00c5cb;
      bVar1 = UNK_00c5c7;
      uVar6 = UNK_00c5d7;
      cVar9 = UNK_00c5cb;
      UNK_00c5cb = cVar9 + '\x01';
      *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar1 + (ushort)bVar2) = uVar6;
      sVar7 = Ram00c5d2;
      sVar5 = Ram00c5ce;
      if ((sVar7 == sVar5) || (bVar1 = UNK_00c5cb, 0x85 < bVar1)) {
        cVar9 = UNK_00c5cc;
        UNK_00c5cc = cVar9 + '\x01';
        goto LAB_c13608;
      }
    }
    cVar9 = UNK_00c5cc;
    UNK_00c5cc = cVar9 + '\x01';
  } while( true );
}



/* ===== c136a0 gap_c136a0 size=86 ===== */

void gap_c136a0(short param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  
  bVar3 = DAT_00c5c4;
  bVar2 = 2;
  bVar1 = UNK_00c5c7;
  *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) =
       *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar3);
  for (bVar3 = 0; bVar3 < param_2; bVar3 = bVar3 + 1) {
    uVar4 = (ushort)bVar2;
    bVar1 = UNK_00c5c7;
    bVar2 = bVar2 + 1;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + bVar1 + uVar4) =
         *(undefined1 *)(uint3)(param_1 + (ushort)bVar3);
  }
  gap_c12910(bVar2);
  return;
}



/* ===== c136f6 gap_c136f6 size=16 ===== */

void gap_c136f6(void)

{
  gap_c136a0(0x80,0xe0,4);
  return;
}



/* ===== c1385e gap_c1385e size=148 ===== */

void gap_c1385e(void)

{
  byte bVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  ushort uStack_6;
  undefined2 uStack_4;
  
  cVar5 = UNK_00c578;
  if (cVar5 == '\x05') {
    bVar1 = DAT_00c5c4;
    uVar2 = (ushort)bVar1;
    uStack_4 = CONCAT11(*(undefined1 *)(uint3)((short)&UNK_00f640 + uVar2),
                        *(undefined1 *)(uint3)((short)&UNK_00f63f + uVar2));
    uStack_6 = (ushort)*(byte *)(uint3)((short)&UNK_00f63e + uVar2) << 8;
    bVar1 = *(byte *)(uint3)((short)&UNK_00f641 + uVar2);
    cVar5 = gap_c12602(uStack_6,uStack_4,bVar1);
    if ((cVar5 == '\0') || (0x87 < bVar1)) {
      func_0xc128ec(0x31);
    }
    else {
      for (bVar4 = 1; bVar4 <= bVar1; bVar4 = bVar4 + 1) {
        bVar3 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar3 + (ushort)bVar4) =
             *(undefined1 *)(uint3)uStack_6;
        uStack_6 = uStack_6 + 1;
      }
      gap_c12910(bVar4);
    }
  }
  else {
    func_0xc128ec(0x12);
  }
  return;
}



/* ===== c13902 gap_c13902 size=382 ===== */

void gap_c13902(void)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  short sVar4;
  undefined1 uVar5;
  undefined2 uStack_8;
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  bVar1 = DAT_00c5c4;
  cVar2 = *(char *)(uint3)((short)&UNK_00f63e + (ushort)bVar1);
  if (cVar2 == '\x01') {
    cVar2 = UNK_00c578;
    if (cVar2 == '\x02') {
      cVar2 = func_0xc131be();
      if ((cVar2 == '\0') && (cVar2 = func_0xc138fc(), cVar2 == '\0')) {
        cVar2 = gap_c1267a();
        if (cVar2 == '\0') goto LAB_c139d4;
        UNK_00c5dc = 1;
        uVar3 = gap_c125f4();
        bVar1 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) = 1;
        uStack_5 = (undefined1)((ushort)uVar3 >> 8);
        bVar1 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1) = uStack_5;
        bVar1 = UNK_00c5c7;
        uStack_6 = (undefined1)uVar3;
        uVar5 = 4;
        *(undefined1 *)(uint3)((short)&UNK_00f640 + (ushort)bVar1) = uStack_6;
      }
      else {
        bVar1 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) = 1;
        bVar1 = UNK_00c5c7;
        *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1) = 0;
        bVar1 = UNK_00c5c7;
        uVar5 = 4;
        *(undefined1 *)(uint3)((short)&UNK_00f640 + (ushort)bVar1) = 0;
        func_0xc138f4();
      }
LAB_c13a3a:
      gap_c12910(uVar5);
      return;
    }
  }
  else if (cVar2 == '\x02') {
    cVar2 = gap_c1267a();
    if (cVar2 == '\0') {
LAB_c139d4:
      func_0xc128ec(0x37);
      return;
    }
    cVar2 = UNK_00c578;
    if (cVar2 == '\x04') {
      cVar2 = UNK_00c5dc;
      if (cVar2 == '\0') {
        func_0xc128ec(0x22);
        return;
      }
      bVar1 = DAT_00c5c4;
      uStack_8 = CONCAT11(*(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1),
                          *(undefined1 *)(uint3)((short)&UNK_00f640 + (ushort)bVar1));
      sVar4 = gap_c125fa();
      if (sVar4 != uStack_8) {
        cVar2 = UNK_00c5de;
        UNK_00c5de = cVar2 + '\x01';
        cVar2 = UNK_00c5de;
        if (cVar2 != '\x02') {
          func_0xc128ec(0x35);
          return;
        }
        func_0xc128ec(0x36);
        kline_start_timeout();
        UNK_00c5de = 0;
        return;
      }
      UNK_00c5dc = 0;
      func_0xc138f4();
      bVar1 = UNK_00c5c7;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) = 2;
      bVar1 = UNK_00c5c7;
      uVar5 = 3;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1) = 0x34;
      goto LAB_c13a3a;
    }
  }
  func_0xc128ec(0x12);
  return;
}



/* ===== c13a9a gap_c13a9a size=270 ===== */

void gap_c13a9a(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  
  bVar3 = DAT_00c5c4;
  bVar1 = *(byte *)(uint3)((short)&UNK_00f63e + (ushort)bVar3);
  cVar2 = *(char *)(uint3)((short)&UNK_00f63f + (ushort)bVar3);
  cVar5 = func_0xc131be();
  if (cVar5 != '\0') {
    func_0xc128ec(0x22);
    return;
  }
  cVar5 = UNK_00c578;
  if (cVar5 == '\x05') {
    if (((bVar1 < 0x90) && (0x7f < bVar1)) &&
       ((cVar2 == '\a' || ((cVar2 == -0x80 || (cVar2 == -0x7f)))))) {
      bVar1 = DAT_00c5c4;
      UNK_00c5e4 = *(undefined1 *)(uint3)((short)&UNK_00f641 + (ushort)bVar1);
LAB_c13b1e:
      bVar1 = DAT_00c5c4;
      UNK_00c5e3 = *(undefined1 *)(uint3)((short)&UNK_00f640 + (ushort)bVar1);
LAB_c13b4e:
      bVar1 = DAT_00c5c4;
      UNK_00c5e2 = *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1);
      UNK_00c5e1 = *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1);
      UNK_00c5e0 = 1;
      goto LAB_c13b7c;
    }
  }
  else {
    if (cVar5 != '\x04') {
      if (cVar5 != '\x03') {
        func_0xc128ec(0x12);
        goto LAB_c13b7c;
      }
      if (((0x8f < bVar1) || (bVar1 < 0x80)) ||
         ((cVar2 != '\0' && (((cVar2 != '\x01' && (cVar2 != '\x05')) && (cVar2 != -0x7e))))))
      goto LAB_c13b6a;
      goto LAB_c13b4e;
    }
    if (((bVar1 < 0x90) && (0x7f < bVar1)) &&
       ((cVar2 == '\a' || ((cVar2 == -0x80 || (cVar2 == -0x7f)))))) goto LAB_c13b1e;
  }
LAB_c13b6a:
  func_0xc128ec(0x31);
LAB_c13b7c:
  cVar2 = UNK_00c5e0;
  if (cVar2 == '\x01') {
    func_0xc13a92(0);
    cVar2 = UNK_00c5e1;
    if ((byte)(cVar2 + 0x80U) < 0x10) {
                    /* WARNING: Could not emulate address calculation at 0xc13ba4 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)((uint3)*(ushort *)((ushort)(byte)(cVar2 + 0x80U) * 2 + 0x7194 & 0x3fff) | 0xc10000)
      )();
      return;
    }
    UNK_00c5e0 = 0;
    bVar1 = UNK_00c5e5;
    if (bVar1 < 4) {
      cVar2 = *(char *)(uint3)(bVar1 + 0x7190);
      if (((cVar2 == '\x12') || (cVar2 == '\"')) || (cVar2 == '1')) {
        func_0xc128ec(cVar2);
      }
      else {
        bVar1 = UNK_00c5c7;
        uVar4 = UNK_00c5e1;
        *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar1) = uVar4;
        uVar4 = UNK_00c5e2;
        *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar1) = uVar4;
        cVar5 = UNK_00c5e2;
        if (cVar5 == '\0') {
          gap_c12910(3);
        }
        else {
          bVar1 = UNK_00c5c7;
          *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar1) = cVar2;
          gap_c12910(4);
        }
      }
    }
  }
  return;
}



/* ===== c13ba8 gap_c13ba8 size=42 ===== */

void gap_c13ba8(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  uVar3 = UNK_00c5e2;
  gap_c130b2(uVar3,(short)&UNK_00c912,(short)&UNK_00c910,0x40);
  uVar3 = UNK_00c5e2;
  gap_c130b2(uVar3,(short)&UNK_00c90a,(short)&UNK_00c908,0x40);
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13bd2 gap_c13bd2 size=22 ===== */

void gap_c13bd2(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  uVar3 = UNK_00c5e2;
  gap_c130b2(uVar3,(short)&UNK_00c9e0,(short)&UNK_00c9de,0x40);
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13be8 gap_c13be8 size=8 ===== */

void gap_c13be8(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  UNK_00c010 = 1;
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13bf0 gap_c13bf0 size=20 ===== */

void gap_c13bf0(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  uVar3 = UNK_00c5e2;
  gap_c130b2(uVar3,(short)&UNK_00c894,(short)&UNK_00c892,4);
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13c04 gap_c13c04 size=22 ===== */

void gap_c13c04(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  uVar3 = UNK_00c5e2;
  gap_c130b2(uVar3,(short)&UNK_00c848,(short)&UNK_00c846,0x80);
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13c1a gap_c13c1a size=22 ===== */

void gap_c13c1a(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  uVar3 = UNK_00c5e2;
  gap_c130b2(uVar3,(short)&UNK_00c6de,(short)&UNK_00c6dc,0x80);
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13c30 gap_c13c30 size=22 ===== */

void gap_c13c30(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  uVar3 = UNK_00c5e2;
  gap_c130b2(uVar3,(short)&UNK_00c6e6,(short)&UNK_00c6e4,0x80);
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13c46 gap_c13c46 size=20 ===== */

void gap_c13c46(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  uVar3 = UNK_00c5e2;
  gap_c1305e(uVar3,(short)&UNK_00c9e3,(short)&UNK_00c9e2,1);
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13c5a gap_c13c5a size=22 ===== */

void gap_c13c5a(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  uVar3 = UNK_00c5e2;
  gap_c130b2(uVar3,(short)&UNK_00c84c,(short)&UNK_00c84a,0x800);
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13c70 gap_c13c70 size=10 ===== */

void gap_c13c70(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  short sVar5;
  
  sVar5 = gap_c13104();
  if (sVar5 == 0) {
    func_0xc13a92(2);
  }
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13c7a gap_c13c7a size=10 ===== */

void gap_c13c7a(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  short sVar5;
  
  sVar5 = gap_c13132();
  if (sVar5 == 0) {
    func_0xc13a92(2);
  }
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13c84 gap_c13c84 size=18 ===== */

void gap_c13c84(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  short sVar5;
  
  sVar5 = gap_c13160();
  if (sVar5 == 0) {
    func_0xc13a92(2);
  }
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13c9e gap_c13c9e size=118 ===== */

void gap_c13c9e(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  
  uVar3 = UNK_00c5e2;
  gap_c130b2(uVar3,(short)&UNK_00c90e,(short)&UNK_00c90c,8);
  UNK_00c5e0 = 0;
  bVar2 = UNK_00c5e5;
  if (bVar2 < 4) {
    cVar1 = *(char *)(uint3)(bVar2 + 0x7190);
    if (((cVar1 == '\x12') || (cVar1 == '\"')) || (cVar1 == '1')) {
      func_0xc128ec(cVar1);
    }
    else {
      bVar2 = UNK_00c5c7;
      uVar3 = UNK_00c5e1;
      *(undefined1 *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) = uVar3;
      uVar3 = UNK_00c5e2;
      *(undefined1 *)(uint3)((short)&UNK_00f63f + (ushort)bVar2) = uVar3;
      cVar4 = UNK_00c5e2;
      if (cVar4 == '\0') {
        gap_c12910(3);
      }
      else {
        bVar2 = UNK_00c5c7;
        *(char *)(uint3)((short)&UNK_00f640 + (ushort)bVar2) = cVar1;
        gap_c12910(4);
      }
    }
  }
  return;
}



/* ===== c13d14 gap_c13d14 size=54 ===== */

void gap_c13d14(void)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = UNK_00c578;
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      bVar2 = DAT_00c5c4;
      if (*(char *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) == '\x01') goto LAB_c13d2c;
      bVar2 = DAT_00c5c4;
      if (*(char *)(uint3)((short)&UNK_00f63e + (ushort)bVar2) == '\x02') {
        DAT_00c59e = 0;
        return;
      }
    }
    func_0xc128ec(0x12);
    return;
  }
LAB_c13d2c:
  gap_c12910(1);
  return;
}



/* ===== c13d50 test_command_clear size=14 ===== */

void test_command_clear(void)

{
  DAT_00fd18._0_1_ = 0;
  DAT_00c5e8 = 0;
  DAT_00c5ea = 0;
  return;
}



/* ===== c13d5e test_command_dispatch size=106 ===== */

void test_command_dispatch(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  byte bVar5;
  ushort uVar6;
  
  bVar5 = DAT_00fd18._0_1_;
  if ((bVar5 & 0x7f) == 0) {
    DAT_00c5e8 = 0;
    DAT_00c5ea = 0;
    return;
  }
  uVar1 = DAT_00c5e8;
  sVar3 = DAT_00c5ea;
  if (sVar3 == 0 && uVar1 < 1000) {
    sVar2 = DAT_00c5e8;
    DAT_00c5e8 = sVar2 + 1;
    sVar4 = DAT_00c5ea;
    DAT_00c5ea = (sVar4 + 1) - (ushort)(sVar2 != -1);
    uVar6 = DAT_00fd18;
    if ((uVar6 & 1) != 0) {
      cc22_23_start_once(sVar3 - (ushort)(uVar1 < 1000));
      return;
    }
    uVar1 = DAT_00fd18;
    if ((uVar1 & 2) != 0) {
      event_start_fixed();
      return;
    }
    uVar1 = DAT_00fd18;
    if ((uVar1 & 4) != 0) {
      pwm_output_enable();
      pwm_period_duty_calc(0xfa,0);
      return;
    }
  }
  else {
    bVar5 = DAT_00fd18._0_1_;
    DAT_00fd18._0_1_ = bVar5 & 0x80;
  }
  return;
}



/* ===== c13dc8 FUN_c13dc8 size=24 ===== */

undefined2 FUN_c13dc8(byte param_1)

{
  undefined2 uVar1;
  
  if (8 < param_1) {
    return 0;
  }
                    /* WARNING: Could not emulate address calculation at 0xc13ddc */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)((uint3)*(ushort *)((ushort)param_1 * 2 + 0x71b4 & 0x3fff) | 0xc10000))();
  return uVar1;
}



/* ===== c13de0 gap_c13de0 size=10 ===== */

undefined2 gap_c13de0(void)

{
  undefined2 uVar1;
  
  uVar1 = gap_c10398(3);
  return uVar1;
}



/* ===== c13dea gap_c13dea size=10 ===== */

undefined2 gap_c13dea(void)

{
  undefined2 uVar1;
  
  uVar1 = gap_c10398(2);
  return uVar1;
}



/* ===== c13df4 gap_c13df4 size=10 ===== */

undefined2 gap_c13df4(void)

{
  undefined2 uVar1;
  
  uVar1 = gap_c10398(4);
  return uVar1;
}



/* ===== c13dfe gap_c13dfe size=10 ===== */

undefined2 gap_c13dfe(void)

{
  undefined2 uVar1;
  
  uVar1 = gap_c10398(6);
  return uVar1;
}



/* ===== c13e08 gap_c13e08 size=10 ===== */

undefined2 gap_c13e08(void)

{
  undefined2 uVar1;
  
  uVar1 = gap_c10398(5);
  return uVar1;
}



/* ===== c13e12 gap_c13e12 size=54 ===== */

undefined2 gap_c13e12(void)

{
  undefined2 uVar1;
  
  if (DAT_c05068 == 4) {
    uVar1 = gap_c146de(1,0);
  }
  else {
    uVar1 = gap_c10398(0);
    if (DAT_c05081 == '\x02') {
      gap_c14cde(7,uVar1);
    }
  }
  return uVar1;
}



/* ===== c13e48 gap_c13e48 size=12 ===== */

undefined2 gap_c13e48(void)

{
  undefined2 uVar1;
  
  if (sRamc05066 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = gap_c10398(1);
  }
  return uVar1;
}



/* ===== c13e54 gap_c13e54 size=14 ===== */

undefined2 gap_c13e54(void)

{
  undefined2 uVar1;
  
  if (DAT_c05068 == 2) {
    uVar1 = gap_c10398(0xf);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== c13e62 gap_c13e62 size=20 ===== */

undefined2 gap_c13e62(void)

{
  undefined2 uVar1;
  
  if (sRamc05066 == 0) {
    uVar1 = gap_c10398(1);
  }
  else if (DAT_c05068 == 1) {
    uVar1 = gap_c10398(0xf);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== c13e76 gap_c13e76 size=22 ===== */

undefined2 gap_c13e76(void)

{
  undefined2 uVar1;
  
  if (DAT_c05068 == 1) {
    uVar1 = gap_c10398(0xf);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== c13e94 gap_c13e94 size=156 ===== */

void gap_c13e94(void)

{
  undefined2 uVar1;
  
  uVar1 = gap_c10398(3);
  Ram00c5ec = uVar1;
  uVar1 = gap_c10398(2);
  Ram00c5ee = uVar1;
  uVar1 = gap_c10398(4);
  Ram00c5f0 = uVar1;
  uVar1 = gap_c10398(6);
  Ram00c5f2 = uVar1;
  uVar1 = gap_c10398(0);
  Ram00c5f6 = uVar1;
  uVar1 = gap_c10398(5);
  Ram00c5f4 = uVar1;
  if (sRamc05066 == 0) {
    uVar1 = gap_c10398(1);
    Ram00c5fc = uVar1;
    Ram00c5f8 = 0;
  }
  else {
    Ram00c5fc = 0;
    uVar1 = gap_c10398(1);
    Ram00c5f8 = uVar1;
  }
  if (DAT_c05068 == 1) {
    uVar1 = gap_c10398(0xf);
    Ram00c5fc = uVar1;
    Ram00c5fa = 0;
    return;
  }
  if (DAT_c05068 == 2) {
    Ram00c5fc = 0;
    uVar1 = gap_c10398(0xf);
    Ram00c5fa = uVar1;
  }
  return;
}



/* ===== c13f3c gap_c13f3c size=28 ===== */

void gap_c13f3c(void)

{
  undefined2 uVar1;
  
  mul32();
  uVar1 = div32u();
  DAT_00c474 = uVar1;
  return;
}



/* ===== c13f6c capture_control size=24 ===== */

void capture_control(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd10;
  if (((uVar1 & 4) == 0) && (DAT_c05064 == 0)) {
    uVar1 = DAT_00fd1a;
    DAT_00fd1a = uVar1 | 0x20;
  }
  uVar1 = DAT_00fd0c;
  if ((uVar1 & 4) == 0) {
    uVar1 = DAT_00fd1a;
    DAT_00fd1a = uVar1 | 0x10;
  }
  return;
}



/* ===== c13f84 gap_c13f84 size=4 ===== */

void gap_c13f84(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd1a;
  DAT_00fd1a = uVar1 & 0xffdf;
  return;
}



/* ===== c13f88 gap_c13f88 size=18 ===== */

void gap_c13f88(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd10;
  if (((uVar1 & 4) == 0) && (DAT_c05064 == 0)) {
    uVar1 = DAT_00fd1a;
    DAT_00fd1a = uVar1 | 0x20;
  }
  return;
}



/* ===== c13f9a capture_input_select size=24 ===== */

void capture_input_select(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd1a;
  DAT_00fd1a = uVar1 & 0xfc | param_1 & 0xff;
  return;
}



/* ===== c13fb2 gap_c13fb2 size=48 ===== */

bool gap_c13fb2(char param_1)

{
  ushort uVar1;
  
  if (param_1 == '\0') {
    uVar1 = DAT_00fd10;
    if ((uVar1 & 4) == 0) {
      return false;
    }
    uVar1 = DAT_00fd10;
  }
  else {
    uVar1 = DAT_00fd0c;
    if ((uVar1 & 4) == 0) {
      return false;
    }
    uVar1 = DAT_00fd0c;
  }
  return (uVar1 & 2) != 0;
}



/* ===== c13fe2 gap_c13fe2 size=4 ===== */

undefined1 gap_c13fe2(void)

{
  return 0;
}



/* ===== c13fe6 gap_c13fe6 size=4 ===== */

void gap_c13fe6(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd1a;
  DAT_00fd1a = uVar1 | 0x80;
  return;
}



/* ===== c14036 gap_c14036 size=6 ===== */

void gap_c14036(void)

{
  Ram00c3fa = 0xffff;
  return;
}



/* ===== c14074 gap_c14074 size=10 ===== */

void gap_c14074(void)

{
  undefined2 uVar1;
  
  uVar1 = Ram00c38c;
  Ram00c3fa = uVar1;
  return;
}



/* ===== c1408a gap_c1408a size=6 ===== */

void gap_c1408a(void)

{
  event_start();
  return;
}



/* ===== c14090 gap_c14090 size=96 ===== */

void gap_c14090(ushort param_1)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  byte bVar6;
  
  uVar3 = (uint)param_1 * 1000 >> 6;
  bVar6 = 0;
  do {
    sVar2 = (ushort)bVar6 * 4;
    uVar1 = (short)&DAT_00c384 + sVar2;
    *(short *)(uint3)(ushort)((short)&DAT_00c386 + sVar2) = (short)(uVar3 >> 0x10);
    *(short *)(uint3)uVar1 = (short)uVar3;
    uVar4 = DAT_00c374;
    uVar5 = DAT_00c37e;
    func_0xc0bbf6(bVar6,*(undefined2 *)(uint3)uVar1,
                  *(undefined2 *)(uint3)(ushort)((short)&DAT_00c386 + sVar2),
                  *(undefined2 *)(uint3)((short)&UNK_00c36a + (ushort)bVar6 * 2),uVar5,uVar4);
    bVar6 = bVar6 + 1;
  } while (bVar6 < 2);
  return;
}



/* ===== c141b6 gap_c141b6 size=10 ===== */

void gap_c141b6(undefined2 param_1)

{
  gap_c0d314(1,param_1);
  return;
}



/* ===== c141de gap_c141de size=30 ===== */

void gap_c141de(ushort param_1)

{
  DAT_00c406 = (ushort)((uint)param_1 * 1000) >> 6 | (short)((uint)param_1 * 1000 >> 0x10) << 10;
  return;
}



/* ===== c14236 gap_c14236 size=6 ===== */

void gap_c14236(void)

{
  gap_c0d4ca();
  return;
}



/* ===== c14246 gap_c14246 size=12 ===== */

void gap_c14246(void)

{
  DAT_00c36e = 1;
  DAT_00c370 = 0;
  return;
}



/* ===== c14298 capture_init size=12 ===== */

void capture_init(void)

{
  capture_control();
  capture_input_select(0);
  return;
}



/* ===== c142a4 gap_c142a4 size=30 ===== */

void gap_c142a4(void)

{
  ushort uVar1;
  
  timer5_init();
  uVar1 = DAT_00f130;
  DAT_00f130 = uVar1 & 0xff7f;
  uVar1 = P1L;
  P1L = uVar1 & 0xff7f;
  uVar1 = DAT_00f120;
  DAT_00f120 = uVar1 & 0xfffe;
  uVar1 = P1H;
  P1H = uVar1 & 0xfffe;
  capture_init();
  config_sensor_setup();
  DAT_00c3a4 = 0;
  return;
}



/* ===== c142c2 gap_c142c2 size=6 ===== */

void gap_c142c2(void)

{
  gap_c0f83c();
  return;
}



/* ===== c142da gap_c142da size=38 ===== */

bool gap_c142da(void)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = gap_c10398(10);
  if (0x2cb < uVar2 >> 6) {
    Ram00c5fe = 1;
  }
  if (uVar2 >> 6 < 0x200) {
    Ram00c5fe = 0;
  }
  sVar1 = Ram00c5fe;
  return sVar1 != 0;
}



/* ===== c14300 gap_c14300 size=62 ===== */

bool gap_c14300(void)

{
  short sVar1;
  ushort uVar2;
  
  if (DAT_c0506a == 1) {
    uVar2 = gap_c10398(0xe);
    if (0x265 < uVar2 >> 6) {
      Ram00c600 = 1;
    }
    if (uVar2 >> 6 < 0x200) {
      Ram00c600 = 0;
    }
  }
  else {
    uVar2 = P5;
    Ram00c600 = (uVar2 & 0x4000) >> 0xe;
  }
  sVar1 = Ram00c600;
  return sVar1 != 0;
}



/* ===== c1433e gap_c1433e size=8 ===== */

bool gap_c1433e(void)

{
  ushort uVar1;
  
  uVar1 = P5;
  return (uVar1 & 0x800) != 0;
}



/* ===== c14346 gap_c14346 size=20 ===== */

bool gap_c14346(void)

{
  ushort uVar1;
  
  uVar1 = P3;
  return (uVar1 & 0x40) != 0;
}



/* ===== c1434e gap_c1434e size=2 ===== */

bool gap_c1434e(void)

{
  ushort uVar1;
  
  uVar1 = P1H;
  return (uVar1 & 2) != 0;
}



/* ===== c14368 gap_c14368 size=80 ===== */

void gap_c14368(char param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  if (param_1 == '\x02') {
    uVar1 = PSW;
    uVar2 = PSW;
    uVar3 = PSW;
    PSW = uVar3 & 0xffbf | ((uVar2 & 8) >> 3 ^ 1) << 6;
    uVar1 = P3;
    uVar2 = PSW;
    uVar3 = P3;
    P3 = uVar3 & 0xffbf | uVar2 & 0x40;
  }
  else {
    if (param_1 == '\x03') {
      uVar1 = PSW;
      uVar2 = PSW;
      uVar3 = PSW;
      PSW = uVar3 & 0xffbf | ((uVar2 & 8) >> 3 ^ 1) << 6;
      uVar1 = P1H;
      uVar3 = PSW;
      uVar2 = P1H;
      P1H = uVar2 & 0xfffd | ((uVar3 & 0x40) >> 6) << 1;
      return;
    }
    if (param_1 == '\x04') {
      uVar1 = PSW;
      uVar2 = PSW;
      uVar3 = PSW;
      PSW = uVar3 & 0xffbf | ((uVar2 & 8) >> 3 ^ 1) << 6;
      uVar1 = P1H;
      uVar3 = PSW;
      uVar2 = P1H;
      P1H = uVar2 & 0xffdf | ((uVar3 & 0x40) >> 6) << 5;
      return;
    }
    if (param_1 == '\x06') {
      uVar1 = PSW;
      uVar2 = PSW;
      uVar3 = PSW;
      PSW = uVar3 & 0xffbf | ((uVar2 & 8) >> 3 ^ 1) << 6;
      uVar1 = P1L;
      uVar3 = PSW;
      uVar2 = P1L;
      P1L = uVar2 & 0xffbf | uVar3 & 0x40;
      return;
    }
  }
  return;
}



/* ===== c143b8 gap_c143b8 size=44 ===== */

void gap_c143b8(char param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  if (param_1 == '\x02') {
    uVar1 = P3;
    uVar2 = P3;
    uVar3 = P3;
    P3 = uVar3 & 0xffbf | ((uVar2 & 0x40) >> 6 ^ 1) << 6;
  }
  else {
    if (param_1 == '\x03') {
      uVar1 = P1H;
      uVar2 = P1H;
      uVar3 = P1H;
      P1H = uVar3 & 0xfffd | ((uVar2 & 2) >> 1 ^ 1) << 1;
      return;
    }
    if (param_1 == '\x04') {
      uVar1 = P1H;
      uVar2 = P1H;
      uVar3 = P1H;
      P1H = uVar3 & 0xffdf | ((uVar2 & 0x20) >> 5 ^ 1) << 5;
      return;
    }
    if (param_1 == '\x06') {
      uVar1 = P1L;
      uVar2 = P1L;
      uVar3 = P1L;
      P1L = uVar3 & 0xffbf | ((uVar2 & 0x40) >> 6 ^ 1) << 6;
      return;
    }
  }
  return;
}



/* ===== c143e4 gap_c143e4 size=190 ===== */

ushort gap_c143e4(char param_1,short param_2)

{
  byte bVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  if (param_1 == '\x06') {
    if (param_2 == 3) {
      uVar2 = DAT_00c4b6;
      bVar1 = (byte)uVar2;
    }
    else {
      if (param_2 != 1) {
        if (param_2 == 2) {
          uVar3 = Ram00c4ae;
          return uVar3 >> 4 & 1;
        }
        if (param_2 == 0) {
          uVar3 = Ram00c4ac;
          return uVar3 >> 4 & 1;
        }
        uVar3 = Ram00c4ae;
        if (((uVar3 & 0x10) == 0) && (uVar3 = Ram00c4ac, (uVar3 & 0x10) == 0)) {
          return 0;
        }
        return 1;
      }
      uVar2 = DAT_00c49c;
      bVar1 = (byte)uVar2;
    }
    if ((bVar1 & 8) != 8) {
      return 0;
    }
  }
  else {
    if (param_1 != '\x05') {
      return 0;
    }
    if ((param_2 != 3) && (param_2 != 1)) {
      if (param_2 == 2) {
        uVar3 = Ram00c4b2;
        return uVar3 >> 4 & 1;
      }
      if (param_2 == 0) {
        uVar3 = Ram00c4b0;
        return uVar3 >> 0xc & 1;
      }
      uVar3 = Ram00c4b2;
      if (((uVar3 & 0x10) == 0) && (uVar3 = Ram00c4b0, (uVar3 & 0x1000) == 0)) {
        return 0;
      }
      return 1;
    }
  }
  return 1;
}



/* ===== c14682 gap_c14682 size=92 ===== */

undefined2 gap_c14682(char param_1,ushort param_2)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  
  uVar4 = 0;
  if ((((DAT_c05068 == 0) || (DAT_c05068 == 4)) && ((param_1 == '\0' || (param_1 == '\x01')))) &&
     ((uVar4 = 0, DAT_c05068 == 0 || (DAT_c05068 == 4)))) {
    uVar3 = DAT_00c4d4;
    uVar2 = DAT_00c4d2;
    if ((uVar3 | uVar2) != 0) {
      param_2 = param_2 & 0xff;
      do {
        bVar1 = param_2 != 0;
        param_2 = param_2 - 1;
      } while (bVar1);
      uVar4 = DAT_00c4d2;
      uVar4 = DAT_00c4d4;
      uVar4 = div32u(uVar3 | uVar2);
    }
  }
  return uVar4;
}



/* ===== c146de gap_c146de size=52 ===== */

undefined2 gap_c146de(char param_1)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if ((((DAT_c05068 == 0) || (DAT_c05068 == 4)) && ((param_1 == '\0' || (param_1 == '\x01')))) &&
     ((uVar1 = 0, DAT_c05068 == 0 || (DAT_c05068 == 4)))) {
    uVar1 = DAT_00c4dc;
  }
  return uVar1;
}



/* ===== c14714 input_latch size=36 ===== */

void input_latch(void)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  
  uVar1 = input_status;
  uVar2 = DAT_00fd1c;
  uVar3 = DAT_00fd1c;
  DAT_00fd1c = uVar3 & 0xfffe | uVar1 >> 2 & 1;
  uVar1 = input_status;
  uVar2 = DAT_00fd1c;
  uVar3 = DAT_00fd1c;
  DAT_00fd1c = uVar3 & 0xfffd | (uVar1 >> 1 & 1) << 1;
  uVar1 = input_status;
  uVar2 = DAT_00fd1c;
  uVar3 = DAT_00fd1c;
  DAT_00fd1c = uVar3 & 0xfffb | (uVar1 & 1) << 2;
  return;
}



/* ===== c14738 gap_c14738 size=8 ===== */

undefined2 gap_c14738(void)

{
  undefined2 uVar1;
  
  uVar1 = T7;
  return uVar1;
}



/* ===== c14772 gap_c14772 size=8 ===== */

void gap_c14772(void)

{
  command_dispatch(0);
  return;
}



/* ===== c1477a gap_c1477a size=52 ===== */

void gap_c1477a(void)

{
  short sVar1;
  short sVar2;
  undefined2 uVar3;
  
  command_dispatch(1);
  sVar1 = gap_c1168a(0);
  sVar2 = gap_c1168a(1);
  if ((sVar1 == 0) || (sVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  func_0xc14712(uVar3);
  return;
}



/* ===== c147ae gap_c147ae size=16 ===== */

bool gap_c147ae(void)

{
  char cVar1;
  
  cVar1 = DAT_00c93c;
  return cVar1 == '\0';
}



/* ===== c147be gap_c147be size=2 ===== */

void gap_c147be(void)

{
  command_dispatch(2);
  return;
}



/* ===== c147c6 command_dispatch_index3 size=8 ===== */

void command_dispatch_index3(void)

{
  command_dispatch(3);
  return;
}



/* ===== c147ce FUN_c147ce size=8 ===== */

void FUN_c147ce(void)

{
  command_dispatch(5);
  return;
}



/* ===== c147d6 gap_c147d6 size=78 ===== */

void gap_c147d6(void)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  
  bVar2 = DAT_00c256;
  uVar1 = (short)&DAT_00c282 + (ushort)bVar2 * 2;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xbfff;
  command_dispatch(6);
  func_0xc0e4e6();
  cVar3 = DAT_00c92f;
  if (cVar3 == '\0') {
    DAT_00c208 = 0xd70a;
    DAT_00c20a = 0xc0;
    if ((DAT_c05036 == '\x02') || (DAT_c05036 == '\x03')) {
      uVar1 = Ram00c288;
      Ram00c288 = uVar1 | 0x8000;
    }
  }
  return;
}



/* ===== c14824 FUN_c14824 size=8 ===== */

void FUN_c14824(void)

{
  command_dispatch(4);
  return;
}



/* ===== c1482c diag_status_build size=464 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void diag_status_build(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  short sVar4;
  
  DAT_00c60f = 0;
  uVar3 = DAT_00c784;
  DAT_00c60e = uVar3;
  cVar1 = DAT_00c850;
  bVar2 = DAT_00c60e;
  DAT_00c60e = bVar2 | cVar1 << 1;
  cVar1 = DAT_00c786;
  bVar2 = DAT_00c60e;
  DAT_00c60e = bVar2 | cVar1 << 2;
  cVar1 = DAT_00c780;
  bVar2 = DAT_00c60e;
  DAT_00c60e = bVar2 | cVar1 << 3;
  cVar1 = DAT_00c781;
  bVar2 = DAT_00c60e;
  DAT_00c60e = bVar2 | cVar1 << 4;
  cVar1 = DAT_00c78d;
  bVar2 = DAT_00c60e;
  DAT_00c60e = bVar2 | cVar1 << 5;
  bVar2 = DAT_00c60e;
  DAT_00c60e = bVar2 | DAT_e00844 << 6;
  cVar1 = DAT_00cac6;
  bVar2 = DAT_00c60e;
  DAT_00c60e = bVar2 | cVar1 << 7;
  uVar3 = DAT_00cad6;
  DAT_00c610 = uVar3;
  cVar1 = DAT_00c014;
  bVar2 = DAT_00c610;
  DAT_00c610 = bVar2 | cVar1 << 1;
  cVar1 = DAT_00c824;
  bVar2 = DAT_00c610;
  DAT_00c610 = bVar2 | cVar1 << 2;
  cVar1 = DAT_00c841;
  bVar2 = DAT_00c610;
  DAT_00c610 = bVar2 | cVar1 << 3;
  cVar1 = DAT_00c830;
  bVar2 = DAT_00c610;
  DAT_00c610 = bVar2 | cVar1 << 4;
  cVar1 = DAT_00c836;
  bVar2 = DAT_00c610;
  DAT_00c610 = bVar2 | cVar1 << 5;
  cVar1 = DAT_00c840;
  bVar2 = DAT_00c610;
  DAT_00c610 = bVar2 | cVar1 << 6;
  cVar1 = DAT_00cad7;
  bVar2 = DAT_00c610;
  DAT_00c610 = bVar2 | cVar1 << 7;
  sVar4 = DAT_00cad0;
  if (sVar4 == 1) {
    DAT_00c60f = 1;
  }
  cVar1 = DAT_00cac5;
  bVar2 = DAT_00c60f;
  DAT_00c60f = bVar2 | cVar1 << 1;
  bVar2 = DAT_00c60f;
  DAT_00c60f = bVar2 | DAT_e00810 << 2;
  cVar1 = DAT_00caf8;
  bVar2 = DAT_00c60f;
  DAT_00c60f = bVar2 | cVar1 << 3;
  if (DAT_e0089e == '\0') {
    bVar2 = DAT_00c60f;
    DAT_00c60f = bVar2 | 0x10;
  }
  bVar2 = DAT_00c60f;
  DAT_00c60f = bVar2 | DAT_e0085c << 5;
  bVar2 = DAT_00c60f;
  DAT_00c60f = bVar2 | DAT_e00846 << 6;
  cVar1 = DAT_00c954;
  bVar2 = DAT_00c60f;
  DAT_00c60f = bVar2 | cVar1 << 7;
  uVar3 = DAT_00c92b;
  DAT_00c60d = uVar3;
  cVar1 = DAT_00c934;
  bVar2 = DAT_00c60d;
  DAT_00c60d = bVar2 | cVar1 << 1;
  bVar2 = DAT_00c60d;
  DAT_00c60d = bVar2 | DAT_e0081a << 2;
  cVar1 = DAT_00c81c;
  bVar2 = DAT_00c60d;
  DAT_00c60d = bVar2 | cVar1 << 3;
  cVar1 = DAT_00c77e;
  bVar2 = DAT_00c60d;
  DAT_00c60d = bVar2 | cVar1 << 4;
  cVar1 = DAT_00c604;
  if (cVar1 == '\0') {
    bVar2 = DAT_00c60d;
    DAT_00c60d = bVar2 | 0x20;
  }
  cVar1 = DAT_00c603;
  if (cVar1 == '\0') {
    bVar2 = DAT_00c60d;
    DAT_00c60d = bVar2 | 0x40;
  }
  bVar2 = DAT_00c60d;
  DAT_00c60d = bVar2 | (_DAT_e0083e == 1) << 7;
  uVar3 = DAT_00c9f0;
  DAT_00c60c = uVar3;
  cVar1 = DAT_00c91c;
  bVar2 = DAT_00c60c;
  DAT_00c60c = bVar2 | cVar1 << 1;
  cVar1 = DAT_00c92e;
  bVar2 = DAT_00c60c;
  DAT_00c60c = bVar2 | cVar1 << 2;
  cVar1 = DAT_00ca44;
  bVar2 = DAT_00c60c;
  DAT_00c60c = bVar2 | cVar1 << 3;
  cVar1 = DAT_00c89e;
  bVar2 = DAT_00c60c;
  DAT_00c60c = bVar2 | cVar1 << 4;
  cVar1 = DAT_00c93c;
  if (cVar1 == '\x03') {
    bVar2 = DAT_00c60c;
    DAT_00c60c = bVar2 | 0x20;
  }
  bVar2 = DAT_00c60c;
  DAT_00c60c = bVar2 | DAT_e00894 << 6;
  cVar1 = DAT_00caf9;
  bVar2 = DAT_00c60c;
  DAT_00c60c = bVar2 | cVar1 << 7;
  return;
}



/* ===== c149fc gap_c149fc size=32 ===== */

undefined1 gap_c149fc(void)

{
  short sVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  sVar1 = func_0xc117d8(0);
  if (sVar1 == 2) {
    uVar2 = 2;
  }
  else if (sVar1 == 1) {
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== c14a1c gap_c14a1c size=32 ===== */

undefined1 gap_c14a1c(void)

{
  short sVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  sVar1 = func_0xc117d8(1);
  if (sVar1 == 2) {
    uVar2 = 2;
  }
  else if (sVar1 == 1) {
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== c14a3c gap_c14a3c size=262 ===== */

ushort gap_c14a3c(short param_1,short param_2)

{
  ushort uVar1;
  
  uVar1 = 0;
  if ((param_2 == 3) || (param_2 == 1)) {
    uVar1 = 1;
  }
  else if (param_1 == 0) {
    if (param_2 == 2) {
      uVar1 = Ram00c4ae;
      uVar1 = uVar1 >> 0xd & 1;
    }
    else if (param_2 == 0) {
      uVar1 = Ram00c4ac;
      uVar1 = uVar1 >> 0xd & 1;
    }
    else {
      uVar1 = Ram00c4ae;
      if (((uVar1 & 0x2000) == 0) && (uVar1 = Ram00c4ac, (uVar1 & 0x2000) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else if (param_1 == 1) {
    if (param_2 == 2) {
      uVar1 = Ram00c4ae;
      uVar1 = uVar1 >> 8 & 1;
    }
    else if (param_2 == 0) {
      uVar1 = Ram00c4ac;
      uVar1 = uVar1 >> 8 & 1;
    }
    else {
      uVar1 = Ram00c4ae;
      if (((uVar1 & 0x100) == 0) && (uVar1 = Ram00c4ac, (uVar1 & 0x100) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else if (param_1 == 2) {
    if (param_2 == 2) {
      uVar1 = Ram00c4ae;
      uVar1 = uVar1 >> 7 & 1;
    }
    else if (param_2 == 0) {
      uVar1 = Ram00c4ac;
      uVar1 = uVar1 >> 7 & 1;
    }
    else {
      uVar1 = Ram00c4ae;
      if (((uVar1 & 0x80) == 0) && (uVar1 = Ram00c4ac, (uVar1 & 0x80) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else if (param_1 == 3) {
    if (param_2 == 2) {
      uVar1 = Ram00c4ae;
      uVar1 = uVar1 >> 6 & 1;
    }
    else if (param_2 == 0) {
      uVar1 = Ram00c4ac;
      uVar1 = uVar1 >> 6 & 1;
    }
    else {
      uVar1 = Ram00c4ae;
      if (((uVar1 & 0x40) == 0) && (uVar1 = Ram00c4ac, (uVar1 & 0x40) == 0)) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}



/* ===== c14cde gap_c14cde size=14 ===== */

void gap_c14cde(char param_1,undefined2 param_2)

{
  if (param_1 == '\a') {
    gap_c10b0c(param_2);
  }
  return;
}



/* ===== c14d36 gap_c14d36 size=514 ===== */

/* WARNING: Type propagation algorithm not settling */

ushort gap_c14d36(char param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  
  if (((param_2 == 3) || (param_2 == 1)) &&
     ((param_1 == '\0' || (((param_1 == '\x05' || (param_1 == '\x06')) || (param_1 == '\x01')))))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || ((param_2 != 3 && (param_2 != 1)))) {
    if (!bVar1) {
      if (param_1 == '\0') {
        if (param_2 == 2) {
          uVar2 = Ram00c4ae;
          return uVar2 & 1;
        }
        if (param_2 == 0) {
          uVar2 = Ram00c4ac;
          return uVar2 & 1;
        }
        uVar2 = Ram00c4ae;
        if (((uVar2 & 1) == 0) && (uVar2 = Ram00c4ac, (uVar2 & 1) == 0)) {
          return 0;
        }
        return 1;
      }
      if (param_1 == '\x01') {
        if (param_2 == 2) {
          uVar2 = Ram00c4ae;
          return uVar2 >> 2 & 1;
        }
        if (param_2 == 0) {
          uVar2 = Ram00c4ac;
          return uVar2 >> 2 & 1;
        }
        uVar2 = Ram00c4ae;
        if (((uVar2 & 4) == 0) && (uVar2 = Ram00c4ac, (uVar2 & 4) == 0)) {
          return 0;
        }
        return 1;
      }
      if (param_1 == '\x05') {
        if (param_2 == 2) {
          uVar2 = Ram00c4ae;
          return uVar2 >> 5 & 1;
        }
        if (param_2 == 0) {
          uVar2 = Ram00c4ac;
          return uVar2 >> 5 & 1;
        }
        uVar2 = Ram00c4ae;
        if (((uVar2 & 0x20) == 0) && (uVar2 = Ram00c4ac, (uVar2 & 0x20) == 0)) {
          return 0;
        }
        return 1;
      }
      if (param_1 != '\x06') {
        return 0;
      }
      if (param_2 == 2) {
        uVar2 = Ram00c4ae;
        return uVar2 >> 3 & 1;
      }
      if (param_2 == 0) {
        uVar2 = Ram00c4ac;
        return uVar2 >> 3 & 1;
      }
      uVar2 = Ram00c4ae;
      if (((uVar2 & 8) == 0) && (uVar2 = Ram00c4ac, (uVar2 & 8) == 0)) {
        return 0;
      }
      return 1;
    }
    if (param_1 == '\0') {
      sVar3 = Ram00c98c;
      if (sVar3 == -0x8000) {
        sVar3 = 2;
      }
      else {
        sVar3 = Ram00c98c;
        if (sVar3 == 0) {
          sVar3 = 1;
        }
        else {
          sVar3 = 0;
        }
      }
    }
    else if (param_1 == '\x01') {
      sVar3 = Ram00c990;
      if (sVar3 == -0x8000) {
        sVar3 = 2;
      }
      else {
        sVar3 = Ram00c990;
        if (sVar3 == 0) {
          sVar3 = 1;
        }
        else {
          sVar3 = 0;
        }
      }
    }
    else if (param_1 == '\x06') {
      sVar3 = Ram00c98c;
      if (sVar3 == -0x8000) {
        sVar3 = 2;
      }
      else {
        sVar3 = Ram00c98c;
        if (sVar3 == 0) {
          sVar3 = 1;
        }
        else {
          sVar3 = 0;
        }
      }
    }
    else {
      if (param_1 != '\x05') {
        return 0;
      }
      sVar3 = Ram00c98c;
      if (sVar3 == -0x8000) {
        sVar3 = 2;
      }
      else {
        sVar3 = Ram00c98c;
        if (sVar3 == 0) {
          sVar3 = 1;
        }
        else {
          sVar3 = 0;
        }
      }
    }
    if (sVar3 != 0) {
      if (sVar3 != 1) {
        return (ushort)(param_2 == 1);
      }
      return (ushort)(param_2 == 3);
    }
  }
  return 1;
}



/* ===== c14f38 gap_c14f38 size=174 ===== */

void gap_c14f38(char param_1,short param_2)

{
  ushort uVar1;
  
  if ((param_2 != 3) && (param_2 != 1)) {
    if (param_1 == '\0') {
      uVar1 = DAT_00c4a8;
      if ((uVar1 & 0x80) != 0) {
        if (param_2 == 2) {
          uVar1 = Ram00c4ae;
          Ram00c4ae = uVar1 & 0xfffe;
          return;
        }
        if (param_2 == 0) {
          uVar1 = Ram00c4ac;
          Ram00c4ac = uVar1 & 0xfffe;
        }
      }
    }
    else if (param_1 == '\x01') {
      uVar1 = DAT_00c4a8;
      if ((uVar1 & 0x20) != 0) {
        if (param_2 == 2) {
          uVar1 = Ram00c4ae;
          Ram00c4ae = uVar1 & 0xfffb;
          return;
        }
        if (param_2 == 0) {
          uVar1 = Ram00c4ac;
          Ram00c4ac = uVar1 & 0xfffb;
          return;
        }
      }
    }
    else if (param_1 == '\x05') {
      uVar1 = DAT_00c4a8;
      if ((uVar1 & 4) != 0) {
        if (param_2 == 2) {
          uVar1 = Ram00c4ae;
          Ram00c4ae = uVar1 & 0xffdf;
          return;
        }
        if (param_2 == 0) {
          uVar1 = Ram00c4ac;
          Ram00c4ac = uVar1 & 0xffdf;
          return;
        }
      }
    }
    else if ((param_1 == '\x06') && (uVar1 = DAT_00c4a8, (uVar1 & 0x10) != 0)) {
      if (param_2 == 2) {
        uVar1 = Ram00c4ae;
        Ram00c4ae = uVar1 & 0xfff7;
        return;
      }
      if (param_2 == 0) {
        uVar1 = Ram00c4ac;
        Ram00c4ac = uVar1 & 0xfff7;
        return;
      }
    }
  }
  return;
}



/* ===== c15028 gap_c15028 size=60 ===== */

void gap_c15028(void)

{
  ushort uVar1;
  ushort uVar2;
  
  UNK_00c6ba = 0;
  uVar2 = 0;
  do {
    *(undefined1 *)(uint3)((short)&UNK_00c6a6 + uVar2) = 0;
    *(undefined1 *)(uint3)((short)&UNK_00c667 + uVar2) = 0;
    *(undefined1 *)(uint3)((short)&UNK_00c63b + uVar2) = 0;
    *(undefined1 *)(uint3)((short)&UNK_00c612 + uVar2) = 0;
    uVar1 = (short)&UNK_00c67c + uVar2 * 2;
    *(undefined1 *)(uint3)((short)&UNK_00c64f + uVar2) = 0;
    *(undefined1 *)(uint3)((short)&UNK_00c626 + uVar2) = 0;
    *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xfff0;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x14);
  return;
}



/* ===== c15064 gap_c15064 size=106 ===== */

void gap_c15064(byte param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined1 auStack_4 [2];
  
  UNK_00c63a = (char)((ushort)*(undefined2 *)(uint3)((ushort)param_1 * 0xc + 0x73e6) >> 8);
  func_0xc150f2(param_1);
  if (*(char *)(uint3)((short)&UNK_00c667 + (ushort)param_1) != '\0') {
    func_0xc154fa(param_1);
    uVar1 = (short)&UNK_00c67c + (ushort)param_1 * 2;
    uVar2 = func_0xc150ce(param_1);
    gap_c24d9a(uVar2,*(ushort *)(uint3)uVar1 & 1,*(ushort *)(uint3)uVar1 >> 1 & 1,auStack_4);
  }
  return;
}



/* ===== c150e0 gap_c150e0 size=18 ===== */

undefined2 gap_c150e0(ushort param_1)

{
  return *(undefined2 *)(uint3)((param_1 & 0xff) * 0xc + 0x73ec);
}



/* ===== c157e4 gap_c157e4 size=42 ===== */

void gap_c157e4(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  byte bVar3;
  
  gap_c15028();
  bVar3 = 0;
  do {
    uVar1 = gap_c150e0(bVar3);
    uVar2 = func_0xc150ce(bVar3);
    gap_c24c2a(uVar2,uVar1);
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0x14);
  return;
}



/* ===== c1580e gap_c1580e size=6 ===== */

void gap_c1580e(void)

{
  gap_c15028();
  return;
}



/* ===== c15814 gap_c15814 size=6 ===== */

void gap_c15814(void)

{
  gap_c15028();
  return;
}



/* ===== c1581a gap_c1581a size=6 ===== */

void gap_c1581a(void)

{
  gap_c15028();
  return;
}



/* ===== c15820 gap_c15820 size=6 ===== */

void gap_c15820(void)

{
  gap_c15028();
  return;
}



/* ===== c15828 gap_c15828 size=14 ===== */

void gap_c15828(void)

{
  gap_c15064(0);
  gap_c15064(1);
  return;
}



/* ===== c15836 gap_c15836 size=18 ===== */

void gap_c15836(void)

{
  gap_c15064(2);
  gap_c15064(3);
  gap_c265aa();
  return;
}



/* ===== c15848 gap_c15848 size=18 ===== */

void gap_c15848(void)

{
  gap_c15064(6);
  gap_c15064(7);
  func_0xc26044();
  return;
}



/* ===== c1585a gap_c1585a size=18 ===== */

void gap_c1585a(void)

{
  gap_c15064(4);
  gap_c15064(5);
  func_0xc26044();
  return;
}



/* ===== c1586c gap_c1586c size=18 ===== */

void gap_c1586c(void)

{
  gap_c15064(8);
  gap_c15064(9);
  gap_c26586();
  return;
}



/* ===== c1587e gap_c1587e size=52 ===== */

void gap_c1587e(void)

{
  short sVar1;
  undefined2 uVar2;
  
  sVar1 = gap_c13fb2(1);
  if (sVar1 == 0) {
    gap_c15064(10);
    gap_c15064(0xb);
  }
  else {
    uVar2 = gap_c13fb2(1);
    gap_c24d9a(0x12,1,uVar2,(short)&UNK_00c6bd);
  }
  gap_c25e52();
  return;
}



/* ===== c158b2 gap_c158b2 size=52 ===== */

void gap_c158b2(void)

{
  short sVar1;
  undefined2 uVar2;
  
  sVar1 = gap_c13fb2(0);
  if (sVar1 == 0) {
    gap_c15064(0xc);
    gap_c15064(0xd);
  }
  else {
    uVar2 = gap_c13fb2(0);
    gap_c24d9a(0x13,1,uVar2,(short)&UNK_00c6bc);
  }
  gap_c25e60();
  return;
}



/* ===== c158e6 gap_c158e6 size=14 ===== */

void gap_c158e6(void)

{
  gap_c15064(0xe);
  gap_c15064(0xf);
  return;
}



/* ===== c158f4 gap_c158f4 size=22 ===== */

void gap_c158f4(void)

{
  gap_c15064(0x10);
  gap_c15064(0x11);
  gap_c265ca();
  return;
}



/* ===== c1590a gap_c1590a size=18 ===== */

void gap_c1590a(void)

{
  gap_c15064(0x12);
  gap_c15064(0x13);
  return;
}



/* ===== c1596e rate_limit size=78 ===== */

ushort rate_limit(ushort param_1,ushort param_2,ushort param_3)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = param_1;
  if ((param_2 != param_1) && (param_3 != 0)) {
    if (param_1 < param_2) {
      sVar1 = (short)((uint)(param_2 - param_1) * (uint)param_3 >> 0x10);
    }
    else {
      sVar1 = -(short)((uint)(param_1 - param_2) * (uint)param_3 >> 0x10);
    }
    uVar2 = param_1 + sVar1;
    if (uVar2 == param_1) {
      if (param_1 < param_2) {
        uVar2 = uVar2 + 1;
      }
      else {
        uVar2 = uVar2 - 1;
      }
    }
  }
  return uVar2;
}



/* ===== c159e8 gap_c159e8 size=42 ===== */

void gap_c159e8(short param_1,short param_2,ushort param_3)

{
  ushort uVar1;
  ushort uVar2;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    if ((*(char *)(uint3)(param_2 + uVar2) != '\0') &&
       (uVar1 = param_1 + uVar2 * 2, *(short *)(uint3)uVar1 != 0)) {
      *(short *)(uint3)uVar1 = *(short *)(uint3)uVar1 + -1;
    }
  }
  return;
}



/* ===== c15a12 gap_c15a12 size=40 ===== */

void gap_c15a12(short param_1,short param_2,ushort param_3)

{
  ushort uVar1;
  ushort uVar2;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    if ((*(char *)(uint3)(param_2 + uVar2) != '\0') &&
       (uVar1 = param_1 + uVar2, *(char *)(uint3)uVar1 != -1)) {
      *(char *)(uint3)uVar1 = *(char *)(uint3)uVar1 + '\x01';
    }
  }
  return;
}



/* ===== c15a3a gap_c15a3a size=36 ===== */

void gap_c15a3a(short param_1,short param_2,ushort param_3)

{
  ushort uVar1;
  ushort uVar2;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    if ((*(char *)(uint3)(param_2 + uVar2) != '\0') &&
       (uVar1 = param_1 + uVar2, *(char *)(uint3)uVar1 != '\0')) {
      *(char *)(uint3)uVar1 = *(char *)(uint3)uVar1 + -1;
    }
  }
  return;
}



/* ===== c15ea6 gap_c15ea6 size=6 ===== */

void gap_c15ea6(void)

{
  func_0xc16182();
  return;
}



/* ===== c15eac gap_c15eac size=22 ===== */

void gap_c15eac(void)

{
  func_0xc15eda();
  func_0xc161a4();
  func_0xc15a5e();
  gap_c161c6();
  func_0xc15b4e();
  return;
}



/* ===== c15ecc gap_c15ecc size=14 ===== */

void gap_c15ecc(void)

{
  func_0xc15eda();
  func_0xc161a4();
  func_0xc15d1c();
  return;
}



/* ===== c161c6 gap_c161c6 size=34 ===== */

void gap_c161c6(void)

{
  undefined2 uVar1;
  
  uVar1 = Ram00c6c2;
  uVar1 = func_0xc1ca1c(uVar1,(short)&UNK_00c6d8);
  Ram00c6c2 = uVar1;
  uVar1 = Ram00c6c4;
  uVar1 = func_0xc1ca1c(uVar1,(short)&UNK_00c6e0);
  Ram00c6c4 = uVar1;
  return;
}



/* ===== c16464 gap_c16464 size=236 ===== */

void gap_c16464(void)

{
  undefined1 uVar1;
  char cVar2;
  short sVar3;
  char cVar4;
  
  gap_c149fc(0x73b4);
  UNK_00c70e = 0;
  Ram00c70c = 1;
  uVar1 = UNK_00c010;
  UNK_00c70f = uVar1;
  sVar3 = func_0xc16442(0x71e2);
  if (sVar3 == -1) {
    UNK_00c709 = 0;
  }
  else {
    UNK_00c709 = 1;
  }
  cVar4 = UNK_00c010;
  if ((cVar4 != '\0') || (cVar4 = UNK_00c003, cVar4 != '\0')) {
    cVar4 = '\x01';
    goto LAB_c16518;
  }
  cVar4 = '\0';
  cVar2 = UNK_00c6eb;
  if (cVar2 != '\0') goto LAB_c16518;
  UNK_00c6eb = 1;
  cVar2 = UNK_00c005;
  cVar4 = '\0';
  if (cVar2 == '\0') {
    UNK_00c710 = 1;
    sVar3 = func_0xc16442(0x71da);
    if (sVar3 == -1) {
      UNK_00c6ea = 0;
LAB_c16506:
      UNK_00c702 = 0;
      goto LAB_c16518;
    }
LAB_c1650c:
    UNK_00c6ea = 1;
  }
  else {
    UNK_00c710 = 0;
    func_0xc1665a((short)&UNK_00c005,0);
    sVar3 = func_0xc16442(0x71da);
    if (sVar3 != -1) goto LAB_c1650c;
    UNK_00c6ea = 0;
    sVar3 = func_0xc16442(0x71d2);
    if (sVar3 == -1) goto LAB_c16506;
  }
  UNK_00c702 = 1;
LAB_c16518:
  if ((cVar4 == '\0') && (cVar2 = UNK_00c702, cVar2 == '\0')) {
    cVar4 = UNK_00c710;
    if (cVar4 != '\0') {
      uVar1 = UNK_00c006;
      UNK_00c6ea = uVar1;
      UNK_00c702 = uVar1;
      uVar1 = UNK_00c004;
      UNK_00c70e = uVar1;
    }
  }
  else {
    func_0xc162f4(cVar4);
    UNK_00c010 = 0;
  }
  func_0xc163be();
  return;
}



/* ===== c1659a gap_c1659a size=16 ===== */

void gap_c1659a(undefined1 param_1)

{
  func_0xc1665a((short)&UNK_00c002,param_1);
  return;
}



/* ===== c165aa gap_c165aa size=22 ===== */

void gap_c165aa(void)

{
  func_0xc1665a((short)&UNK_00c004,0);
  func_0xc1665a((short)&UNK_00c006,0);
  return;
}



/* ===== c166a2 gap_c166a2 size=44 ===== */

void gap_c166a2(ushort param_1,short param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  sVar3 = func_0xc14740();
  sVar2 = Ram00c000;
  sVar1 = *(short *)(uint3)param_1;
  *(short *)(uint3)param_1 = param_2;
  Ram00c000 = (sVar2 + sVar1) - param_2;
  func_0xc14750(sVar3 >> 0xf);
  return;
}



/* ===== c166ce gap_c166ce size=72 ===== */

void gap_c166ce(ushort param_1,undefined2 param_2,undefined2 param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  
  sVar4 = func_0xc14740();
  sVar3 = Ram00c000;
  sVar1 = *(short *)(uint3)param_1;
  sVar2 = *(short *)(uint3)(param_1 + 2);
  *(undefined2 *)(uint3)(param_1 + 2) = param_3;
  *(undefined2 *)(uint3)param_1 = param_2;
  Ram00c000 = ((sVar3 + sVar1 + sVar2) - *(short *)(uint3)param_1) - *(short *)(uint3)(param_1 + 2);
  func_0xc14750(sVar4 >> 0xf);
  return;
}



/* ===== c16790 gap_c16790 size=52 ===== */

void gap_c16790(void)

{
  DAT_e00810 = 0;
  uRame00811 = 0;
  uRame00812 = 0;
  gap_c1b982();
  if (cRamc05b12 == '\x01') {
    UNK_00c751 = 1;
    Ram00c74e = 0;
  }
  return;
}



/* ===== c16946 gap_c16946 size=6 ===== */

void gap_c16946(void)

{
  gap_c16790();
  return;
}



/* ===== c16cde gap_c16cde size=796 ===== */

void gap_c16cde(void)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  ushort uVar7;
  
  cVar3 = DAT_00c93c;
  if (cVar3 != '\x03') {
    func_0xc1eb4a();
    cVar3 = DAT_00c93c;
    if ((cVar3 == '\x02') && (uVar7 = Ram00c996, uRamc06224 <= uVar7)) {
      UNK_00c7bc = 1;
      if ((bRamc06228 <= uRamc047e8) && (uVar7 = Ram00c76a, 0xcd < uVar7)) {
        Ram00c76a = (short)((uint)uVar7 * (uint)uRamc06226 >> 0x10);
        Ram00c7e8 = 0;
      }
      uVar7 = Ram00c76a;
      if (uVar7 < 0xce) {
        Ram00c7e8 = 0;
        UNK_00c7bc = 0;
        Ram00c76a = 0;
      }
    }
    else {
      UNK_00c7bc = 0;
      Ram00c7e8 = 0;
    }
    uVar2 = Ram00ca6e;
    uVar7 = Ram00c76a;
    uVar6 = Ram00c76a;
    if (uVar2 == uVar6 || uVar2 < uVar7) {
      Ram00c770 = 0xcd;
    }
    else {
      sVar1 = Ram00c76a;
      Ram00c770 = uVar2 - sVar1;
    }
    goto LAB_c16fce;
  }
  uVar5 = Ram00ca1c;
  uVar4 = gap_c28544(0x51aa,0xc0,uVar5);
  uVar5 = DAT_00c9d0;
  uVar5 = gap_c28544(0x5146,0xc0,uVar5);
  uVar5 = tbl2d_interp(0x5c62,0xc0,uVar4,uVar5);
  Ram00c776 = uVar5;
  func_0xc1eb2a();
  func_0xc1ebf8();
  if (cRamc05e04 == '\x01') {
LAB_c16dd8:
    uVar5 = Ram00ca5a;
    Ram00c772 = uVar5;
  }
  else {
    if (cRamc05e04 != '\x02') {
      if (cRamc05e04 != '\x03') goto LAB_c16dea;
      uVar7 = Ram00ca5a;
      uVar6 = Ram00ca5c;
      if (uVar7 < uVar6) goto LAB_c16dd8;
    }
    uVar5 = Ram00ca5c;
    Ram00c772 = uVar5;
  }
LAB_c16dea:
  if (cRame0089d == '\0') {
    cVar3 = DAT_00c77e;
    if ((cVar3 == '\0') || (cRame00832 != '\0')) {
      cVar3 = DAT_00c81c;
      if ((cVar3 == '\0') || (cRame00832 != '\0')) {
        cVar3 = DAT_00cad6;
        if (((cVar3 == '\0') && (cVar3 = DAT_00cad7, cVar3 == '\0')) ||
           ((sVar1 = DAT_00c936, sVar1 <= sRamc061a6 || (cRame00832 != '\0')))) {
          uVar5 = func_0xc1725c();
          Ram00c770 = uVar5;
        }
        else {
          sRamc04770 = sRamc06162;
        }
      }
      else {
        uVar6 = gap_c18d8a();
        uVar7 = DAT_00c9d0;
        if ((uVar7 < uRamc063b0) &&
           ((DAT_e0081a == '\x01' && (uVar2 = Ram00c774, uVar2 < uRamc0630e)))) {
          uVar5 = gap_c28544(0x5278,0xc0,uVar7);
          uVar7 = tbl8_interp(0x621c,0xc0,uVar5);
          uVar5 = DAT_00c97c;
          uVar6 = tbl8_interp(0x63c2,0xc0,uVar5);
          uVar7 = (ushort)((uint)uVar7 * (uint)uVar6) >> 0xf |
                  (short)((uint)uVar7 * (uint)uVar6 >> 0x10) << 1;
        }
        else {
          uVar7 = DAT_00ca2a;
          uVar2 = DAT_00ca2a;
          if (((uVar6 == uVar2 || uVar6 < uVar7) || (DAT_e0081a != '\0')) ||
             (uVar7 = Ram00c77a, uRamc06310 <= uVar7)) {
            uVar7 = Ram00c772;
            uVar6 = Ram00ca66;
            uVar7 = (ushort)((uint)uVar7 * (uint)uVar6) >> 0xf |
                    (short)((uint)uVar7 * (uint)uVar6 >> 0x10) << 1;
          }
          else {
            func_0xc1eb34();
            uVar5 = DAT_00c9d0;
            uVar5 = axis16_signed(0x7624,uVar5);
            uVar6 = tbl8_interp(0x6300,0xc0,uVar5);
            uVar7 = Ram00ca62;
            uVar7 = (ushort)((uint)uVar6 * (uint)uVar7) >> 0xf |
                    (short)((uint)uVar6 * (uint)uVar7 >> 0x10) << 1;
          }
        }
        if (uVar7 < 0xf801) {
          if (uVar7 < 0xcd) {
            uVar7 = 0xcd;
          }
        }
        else {
          uVar7 = 0xf800;
        }
        Ram00c770 = uVar7;
      }
    }
    else {
      uVar7 = Ram00c772;
      if (uVar7 < uRamc061a4) {
        Ram00c770 = 0;
      }
      else {
        sRamc04770 = Ram00c772;
        sRamc04770 = sRamc04770 - uRamc061a4;
      }
    }
  }
  else {
    sRamc04770 = sRamc061ec;
  }
  sVar1 = DAT_00c936;
  if ((sRamc0622a <= sVar1) || (uVar7 = Ram00c072, uRamc0622c <= uVar7)) {
    Ram00c7e8 = 0;
    UNK_00c7bc = 0;
    uRamc0476a = uRamc06222;
  }
LAB_c16fce:
  uVar7 = Ram00c770;
  if (uVar7 < 0xf801) {
    uVar7 = Ram00c770;
    if (uVar7 < 0xcd) {
      uVar5 = 0xcd;
    }
    else {
      uVar5 = Ram00c770;
    }
  }
  else {
    uVar5 = 0xf800;
  }
  Ram00c770 = uVar5;
  return;
}



/* ===== c170e6 gap_c170e6 size=140 ===== */

void gap_c170e6(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  
  cVar1 = DAT_00c93c;
  if (cVar1 != '\x03') {
    DAT_00c77e = 0;
    return;
  }
  cVar1 = DAT_00c77e;
  if (cVar1 == '\0') {
    cVar1 = DAT_00c81c;
    if ((cVar1 == '\0') || (sVar3 = DAT_00c936, sVar3 <= sRamc0619e)) {
      Ram00c7ca = 0;
    }
    else {
      UNK_00c7f8 = 1;
      Ram00c7cc = 0;
      uVar2 = Ram00c7ca;
      if (uVar2 <= uRamc061a0) {
        DAT_00c77e = 0;
        goto LAB_c17134;
      }
      DAT_00c77e = 1;
    }
    UNK_00c7f8 = 0;
  }
LAB_c17134:
  cVar1 = DAT_00c77e;
  if ((cVar1 != '\0') && (cVar1 = DAT_00c81c, cVar1 == '\0')) {
    UNK_00c7f9 = 1;
    uVar2 = Ram00c7cc;
    if (uVar2 <= uRamc061a2) {
      return;
    }
    DAT_00c77e = 0;
    UNK_00c7f9 = 0;
    Ram00c7ca = 0;
    return;
  }
  Ram00c7cc = 0;
  UNK_00c7f9 = 0;
  return;
}



/* ===== c1719a gap_c1719a size=54 ===== */

void gap_c1719a(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  func_0xc1eb4a();
  uRamc0476a = uRamc06222;
  uVar5 = Ram00ca6e;
  uVar1 = Ram00c76a;
  uVar2 = Ram00c76a;
  if (uVar5 == uVar2 || uVar5 < uVar1) {
    Ram00c77c = 0xcd;
  }
  else {
    sVar3 = Ram00c76a;
    Ram00c77c = uVar5 - sVar3;
  }
  uVar4 = Ram00c77c;
  Ram00c76c = uVar4;
  return;
}



/* ===== c17574 gap_c17574 size=242 ===== */

void gap_c17574(void)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  undefined1 uVar8;
  
  if ((sRame0082a < sRamc06314) || (sRamc06316 < sRame0082a)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  bVar6 = false;
  uVar3 = Ram00c8a0;
  if (uVar3 < uRamc0634e) {
    for (cVar7 = '\0'; cVar7 < '\f'; cVar7 = cVar7 + '\x01') {
      sVar1 = cVar7 * 2;
      uVar3 = Ram00c8a0;
      uVar4 = Ram00c8a0;
      if (*(ushort *)(sVar1 + 0x631e) == uVar4 || *(ushort *)(sVar1 + 0x631e) < uVar3) {
        uVar3 = Ram00c8a0;
        uVar4 = Ram00c8a0;
        if ((*(ushort *)(sVar1 + 0x6336) != uVar4 && uVar3 <= *(ushort *)(sVar1 + 0x6336)) &&
           (uVar3 = DAT_00c9d0, uVar3 <= *(ushort *)(uint3)(sVar1 + 0x6350))) {
          bVar6 = true;
        }
      }
    }
  }
  if ((sRamc04952 < sRamc06318) || (sVar1 = Ram00c952, sRamc0631a < sVar1)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((((cRamc06312 == '\0') || (!bVar5)) || (!bVar6)) ||
     ((uVar3 = DAT_00c06a, uVar3 <= uRamc0631c || (!bVar2)))) {
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
  }
  UNK_00c78e = uVar8;
  return;
}



/* ===== c17b52 FUN_c17b52 size=10 ===== */

void FUN_c17b52(void)

{
  FUN_c19846();
  FUN_c19846();
  return;
}



/* ===== c17b5c gap_c17b5c size=20 ===== */

void gap_c17b5c(void)

{
  func_0xc159bc((short)&UNK_00c7d8,(short)&UNK_00c7bd,4);
  func_0xc18208();
  return;
}



/* ===== c17b70 gap_c17b70 size=102 ===== */

void gap_c17b70(void)

{
  func_0xc159bc((short)&UNK_00c7c6,(short)&UNK_00c7c1,1);
  func_0xc159bc((short)&UNK_00c7ae,(short)&UNK_00c7fa,5);
  func_0xc159bc((short)&UNK_00c792,(short)&UNK_00c7ea,0xe);
  gap_c159e8((short)&UNK_00c7c4,(short)&UNK_00c7c2,1);
  func_0xc18ed6();
  func_0xc18edc();
  func_0xc21a18();
  func_0xc20d96();
  func_0xc21058();
  func_0xc20d76();
  func_0xc220b6();
  func_0xc22326();
  func_0xc17666();
  gap_c1823c();
  gap_c17f44();
  return;
}



/* ===== c17c28 gap_c17c28 size=6 ===== */

void gap_c17c28(void)

{
  gap_c17574();
  return;
}



/* ===== c17c2e gap_c17c2e size=20 ===== */

void gap_c17c2e(void)

{
  func_0xc159bc((short)&UNK_00c7ca,(short)&UNK_00c7f8,2);
  gap_c170e6();
  return;
}



/* ===== c17c70 gap_c17c70 size=30 ===== */

void gap_c17c70(void)

{
  gap_c18528();
  gap_c181c4();
  gap_c20e96();
  gap_c21158();
  gap_c22312();
  gap_c225a8();
  FUN_c19846();
  return;
}



/* ===== c17c8e gap_c17c8e size=14 ===== */

void gap_c17c8e(void)

{
  gap_c18554();
  gap_c181da();
  FUN_c19846();
  return;
}



/* ===== c17ca6 gap_c17ca6 size=14 ===== */

void gap_c17ca6(void)

{
  func_0xc182d4();
  gap_c18540();
  func_0xc181ea();
  return;
}



/* ===== c17f44 gap_c17f44 size=280 ===== */

void gap_c17f44(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  short sVar4;
  undefined2 uVar5;
  ushort uVar6;
  
  sVar4 = Ram00c818;
  if (sVar4 == 1) {
    uVar5 = DAT_00c9d0;
    uVar5 = gap_c28544(0x5252,0xc0,uVar5);
    uVar5 = tbl16_interp(0x5db0,0xc0,uVar5);
    Ram00c814 = uVar5;
    uVar5 = DAT_00c936;
    uVar5 = axis16_signed(0x7534,uVar5);
    uVar5 = tbl16_interp(0x7cdc,0xc0,uVar5);
    Ram00c810 = uVar5;
    UNK_00c7c1 = 1;
  }
  else {
    uVar5 = DAT_00c936;
    uVar5 = axis16_signed(0x7534,uVar5);
    uVar5 = tbl16_interp(0x5d9c,0xc0,uVar5);
    Ram00c814 = uVar5;
    Ram00c810 = 0;
  }
  uVar2 = Ram00c814;
  uVar6 = Ram00c80c;
  uVar1 = Ram00c80c;
  if (uVar2 == uVar1 || uVar2 < uVar6) {
    uVar1 = Ram00c814;
    uVar6 = Ram00c80c;
    if (uVar6 <= uVar1) goto LAB_c1804a;
    uVar5 = Ram00c80c;
    uVar3 = Ram00c814;
    uVar6 = FUN_c28852(uVar5,uVar3);
    if (uRamc05c4c < uVar6) {
      uVar6 = Ram00c7c6;
      if (uVar6 < uRamc05c4e) goto LAB_c1804a;
      uVar5 = Ram00c80c;
      uVar5 = FUN_c28852(uVar5,uRamc05c4c);
      Ram00c80c = uVar5;
      goto LAB_c18038;
    }
  }
  else {
    uVar5 = Ram00c80c;
    uVar6 = FUN_c28852(uVar5);
    if (uRamc05c4c < uVar6) {
      uVar6 = Ram00c7c6;
      if (uVar6 < uRamc05c4e) goto LAB_c1804a;
      uVar5 = Ram00c80c;
      uVar5 = func_0xc276a4(uVar5,uRamc05c4c);
      Ram00c80c = uVar5;
LAB_c18038:
      Ram00c7c6 = 0;
      goto LAB_c1804a;
    }
  }
  uVar5 = Ram00c814;
  Ram00c80c = uVar5;
  UNK_00c7c1 = 0;
LAB_c1804a:
  uVar5 = Ram00c80c;
  gap_c1c2b8(uVar5);
  uVar5 = Ram00c810;
  func_0xc1c2be(uVar5);
  return;
}



/* ===== c18138 gap_c18138 size=62 ===== */

void gap_c18138(void)

{
  ushort uVar1;
  byte bVar2;
  
  UNK_00c816 = 0;
  func_0xc1c2d6(0);
  UNK_00c81a = 0;
  UNK_00c9a5 = 0;
  bVar2 = 0;
  do {
    *(undefined2 *)(uint3)((short)&UNK_00c808 + (ushort)bVar2 * 2) = 0;
    uVar1 = (ushort)bVar2;
    bVar2 = bVar2 + 1;
    *(undefined1 *)(uint3)((short)&UNK_00c806 + uVar1) = 0;
  } while (bVar2 < 2);
  func_0xc1c296((short)&UNK_00c808);
  func_0xc1c312((short)&UNK_00c806);
  return;
}



/* ===== c18176 gap_c18176 size=78 ===== */

void gap_c18176(void)

{
  undefined2 uVar1;
  
  gap_c18138();
  UNK_00c812 = 0;
  gap_c1c3ee(0,0);
  uVar1 = DAT_00c936;
  uVar1 = axis16_signed(0x7534,uVar1);
  uVar1 = tbl16_interp(0x5d9c,0xc0,uVar1);
  Ram00c80c = uVar1;
  gap_c1c2b8(uVar1);
  uVar1 = Ram00c810;
  func_0xc1c2be(uVar1);
  uVar1 = func_0xc180fc();
  Ram00c804 = uVar1;
  UNK_00c826 = 0;
  func_0xc17e72();
  return;
}



/* ===== c181c4 gap_c181c4 size=16 ===== */

void gap_c181c4(void)

{
  UNK_00c82a = 0;
  UNK_00c826 = 1;
  gap_c18138();
  return;
}



/* ===== c181da gap_c181da size=16 ===== */

void gap_c181da(void)

{
  UNK_00c82a = 0;
  UNK_00c826 = 1;
  gap_c18138();
  return;
}



/* ===== c1823c gap_c1823c size=152 ===== */

void gap_c1823c(void)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  func_0xc18da6();
  cVar3 = DAT_00c93c;
  if (cVar3 != '\x03') {
    Ram00c79c = 0;
    UNK_00c7ef = 0;
    DAT_00c81c = 0;
    return;
  }
  cVar3 = UNK_00c853;
  if (cVar3 != '\0') {
    uVar4 = Ram00c984;
    uVar5 = tbl16_interp(0x613e,0xc0,uVar4);
    uVar1 = Ram00c79c;
    uVar2 = Ram00c79c;
    if ((uVar5 == uVar2 || uVar5 < uVar1) || (cVar3 = UNK_00c81d, cVar3 != '\0')) {
      UNK_00c81d = 1;
      UNK_00c7ef = 0;
      DAT_00c81c = 1;
    }
    else {
      UNK_00c7ef = 1;
    }
    Ram00c7ac = 0;
    UNK_00c7f7 = 0;
    return;
  }
  cVar3 = UNK_00c852;
  if (cVar3 != '\0') {
    uVar4 = Ram00c984;
    uVar5 = tbl16_interp(0x61f4,0xc0,uVar4);
    uVar1 = Ram00c7ac;
    uVar2 = Ram00c7ac;
    if (uVar5 == uVar2 || uVar5 < uVar1) {
      UNK_00c7f7 = 0;
      DAT_00c81c = 0;
    }
    else {
      UNK_00c7f7 = 1;
    }
    UNK_00c7ef = 0;
    return;
  }
  UNK_00c7ef = 0;
  return;
}



/* ===== c183e6 gap_c183e6 size=50 ===== */

void gap_c183e6(void)

{
  char cVar1;
  
  uRamc047dc = uRamc05c22;
  cVar1 = UNK_00c820;
  if ((cVar1 == '\0') && (cVar1 = UNK_00c81e, cVar1 == '\0')) {
    Ram00c822 = 0;
    DAT_00c824 = 0;
    return;
  }
  Ram00c822 = 0x8000;
  DAT_00c824 = 1;
  return;
}



/* ===== c18418 gap_c18418 size=16 ===== */

void gap_c18418(void)

{
  UNK_00c820 = 1;
  UNK_00c7be = 1;
  Ram00c7da = 0;
  return;
}



/* ===== c18528 gap_c18528 size=14 ===== */

void gap_c18528(void)

{
  func_0xc1858e();
  func_0xc1859a();
  func_0xc18562();
  return;
}



/* ===== c18536 gap_c18536 size=10 ===== */

void gap_c18536(void)

{
  func_0xc1859a();
  func_0xc18562();
  return;
}



/* ===== c18540 gap_c18540 size=10 ===== */

void gap_c18540(void)

{
  UNK_00c7bd = 0;
  Ram00c7d8 = 0;
  return;
}



/* ===== c18554 gap_c18554 size=14 ===== */

void gap_c18554(void)

{
  func_0xc1858e();
  func_0xc1859a();
  func_0xc18562();
  return;
}



/* ===== c18572 gap_c18572 size=22 ===== */

void gap_c18572(void)

{
  char cVar1;
  
  cVar1 = UNK_00c702;
  if ((cVar1 != '\0') || (cRamc0622e != '\0')) {
    DAT_00c014 = 0;
  }
  return;
}



/* ===== c18c0a gap_c18c0a size=18 ===== */

void gap_c18c0a(void)

{
  UNK_00c848 = 0;
  Ram00c846 = 0;
  UNK_00c84c = 0;
  Ram00c84a = 0;
  return;
}



/* ===== c18c5c gap_c18c5c size=44 ===== */

void gap_c18c5c(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  
  uVar4 = Ram00c984;
  uVar4 = tbl16_interp(0x636c,0xc0,uVar4);
  Ram00c84e = uVar4;
  uVar3 = DAT_00ca2a;
  uVar1 = Ram00c84e;
  uVar2 = Ram00c84e;
  if (uVar3 != uVar2 && uVar1 <= uVar3) {
    UNK_00c851 = 0;
    return;
  }
  UNK_00c851 = 1;
  return;
}



/* ===== c18d8a gap_c18d8a size=28 ===== */

void gap_c18d8a(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00c9d0;
  uVar1 = axis16_signed(0x7624,uVar1);
  tbl8_interp(0x63b4,0xc0,uVar1);
  return;
}



/* ===== c18ed0 gap_c18ed0 size=6 ===== */

void gap_c18ed0(void)

{
  Ram00c858 = 0;
  return;
}



/* ===== c193d6 gap_c193d6 size=38 ===== */

void gap_c193d6(void)

{
  func_0xc1d0dc();
  func_0xc1fd6c();
  gap_c2006e();
  gap_c1f61e();
  func_0xc19714();
  func_0xc1974a();
  uRamc04870 = uRamc063ec;
  return;
}



/* ===== c193fe gap_c193fe size=6 ===== */

void gap_c193fe(void)

{
  gap_c1fd90();
  return;
}



/* ===== c19420 gap_c19420 size=10 ===== */

void gap_c19420(void)

{
  gap_c1971a();
  gap_c1f664();
  return;
}



/* ===== c194ac gap_c194ac size=6 ===== */

void gap_c194ac(void)

{
  gap_c1fb28();
  return;
}



/* ===== c19706 gap_c19706 size=14 ===== */

void gap_c19706(void)

{
  uRame00823 = 0;
  func_0xc19720();
  return;
}



/* ===== c1971a gap_c1971a size=6 ===== */

void gap_c1971a(void)

{
  func_0xc19720();
  return;
}



/* ===== c19766 gap_c19766 size=70 ===== */

void gap_c19766(void)

{
  gap_c0bfcc();
  func_0xc16630();
  func_0xc1be78();
  gap_c24e34();
  func_0xc19e6e();
  gap_c15ea6();
  func_0xc17c42();
  FUN_c19846();
  gap_c193d6();
  gap_c16946();
  FUN_c19846();
  func_0xc270d0();
  func_0xc1f1f8();
  func_0xc2281a();
  func_0xc22df2();
  func_0xc23052();
  func_0xc23156();
  return;
}



/* ===== c197ac gap_c197ac size=22 ===== */

void gap_c197ac(void)

{
  gap_c1beca();
  gap_c19e84();
  gap_c17c70();
  func_0xc1940e();
  gap_c24e5a();
  return;
}



/* ===== c197c2 gap_c197c2 size=10 ===== */

void gap_c197c2(void)

{
  gap_c1beec();
  gap_c24e60();
  return;
}



/* ===== c197cc gap_c197cc size=6 ===== */

void gap_c197cc(void)

{
  gap_c24f26();
  return;
}



/* ===== c197ee gap_c197ee size=10 ===== */

void gap_c197ee(void)

{
  func_0xc193fc();
  gap_c24e6c();
  return;
}



/* ===== c197f8 gap_c197f8 size=8 ===== */

void gap_c197f8(void)

{
  gap_c17ca6();
  gap_c193fe();
  gap_c24e88();
  return;
}



/* ===== c1981a gap_c1981a size=22 ===== */

void gap_c1981a(void)

{
  func_0xc1befc();
  func_0xc19e8e();
  func_0xc17c9c();
  func_0xc19404();
  func_0xc24e7e();
  return;
}



/* ===== c19830 gap_c19830 size=14 ===== */

void gap_c19830(void)

{
  func_0xc1bf10();
  gap_c19e94();
  func_0xc17cb4();
  return;
}



/* ===== c1983e gap_c1983e size=6 ===== */

void gap_c1983e(void)

{
  gap_c1bf0a();
  return;
}



/* ===== c19846 FUN_c19846 size=2 ===== */

void FUN_c19846(void)

{
  return;
}



/* ===== c19850 gap_c19850 size=10 ===== */

void gap_c19850(void)

{
  gap_c16464();
  gap_c19766();
  return;
}



/* ===== c19860 gap_c19860 size=114 ===== */

void gap_c19860(void)

{
  byte bVar1;
  char cVar2;
  
  func_0xc19848(0);
  bVar1 = UNK_00c896;
  if ((bVar1 & 1) == 1) {
    func_0xc19ada();
    bVar1 = UNK_00c896;
    if ((bVar1 & 3) == 1) {
      func_0xc19af8();
      bVar1 = UNK_00c896;
      if ((bVar1 & 7) == 1) {
        func_0xc19b16();
        bVar1 = UNK_00c896;
        if ((bVar1 & 0x1f) == 1) {
          func_0xc19b76();
        }
        bVar1 = UNK_00c896;
        if ((bVar1 & 0x1f) == 0x11) {
          func_0xc19b78();
        }
      }
    }
  }
  else {
    func_0xc19ad8();
  }
  func_0xc1984a(0);
  bVar1 = UNK_00c896;
  func_0xc1984e(bVar1 & 3);
  cVar2 = UNK_00c896;
  UNK_00c896 = cVar2 + '\x02';
  return;
}



/* ===== c198f6 gap_c198f6 size=24 ===== */

void gap_c198f6(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  func_0xc19adc();
  func_0xc19afa();
  func_0xc19b18();
  func_0xc19b44();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c1990e gap_c1990e size=22 ===== */

void gap_c1990e(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  func_0xc19adc();
  gap_c19b04();
  func_0xc19b40();
  gap_c19b4a();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19924 gap_c19924 size=14 ===== */

void gap_c19924(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  gap_c19ae6();
  gap_c19b50();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19932 gap_c19932 size=22 ===== */

void gap_c19932(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  func_0xc19adc();
  func_0xc19afa();
  func_0xc19b42();
  gap_c19b56();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19948 gap_c19948 size=14 ===== */

void gap_c19948(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  gap_c19ae6();
  gap_c19b60();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19956 gap_c19956 size=18 ===== */

void gap_c19956(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  func_0xc19adc();
  gap_c19b04();
  gap_c19b66();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19968 gap_c19968 size=14 ===== */

void gap_c19968(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  gap_c19ae6();
  gap_c19b6c();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19976 gap_c19976 size=18 ===== */

void gap_c19976(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  func_0xc19adc();
  func_0xc19afa();
  func_0xc19b18();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19988 gap_c19988 size=14 ===== */

void gap_c19988(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  gap_c19ae6();
  gap_c19b32();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19996 gap_c19996 size=18 ===== */

void gap_c19996(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  func_0xc19adc();
  gap_c19b04();
  func_0xc19b40();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c199a8 gap_c199a8 size=18 ===== */

void gap_c199a8(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  func_0xc19adc();
  func_0xc19afa();
  func_0xc19b42();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c199ba gap_c199ba size=10 ===== */

void gap_c199ba(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  gap_c19ae6();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c199c4 gap_c199c4 size=30 ===== */

void gap_c199c4(void)

{
  undefined1 uVar1;
  
  gap_c19ab2();
  func_0xc19adc();
  gap_c19b04();
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c199d2 gap_c199d2 size=28 ===== */

void gap_c199d2(void)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  
  gap_c19ab2();
  gap_c19ae6();
  bVar2 = UNK_00c898;
  if (7 < bVar2) {
    UNK_00c898 = 0xff;
    cVar3 = UNK_00c898;
    UNK_00c898 = cVar3 + '\x01';
    func_0xc1984a(1);
    uVar1 = UNK_00c897;
    func_0xc1984c(uVar1);
    return;
  }
                    /* WARNING: Could not emulate address calculation at 0xc199ea */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((ushort)bVar2 * 2 + 0x7656 & 0x3fff) | 0xc10000))();
  return;
}



/* ===== c199ee gap_c199ee size=6 ===== */

void gap_c199ee(void)

{
  undefined1 uVar1;
  char cVar2;
  
  gap_c19b7a();
  cVar2 = UNK_00c898;
  UNK_00c898 = cVar2 + '\x01';
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c199f4 gap_c199f4 size=6 ===== */

void gap_c199f4(void)

{
  undefined1 uVar1;
  char cVar2;
  
  func_0xc19b9c();
  cVar2 = UNK_00c898;
  UNK_00c898 = cVar2 + '\x01';
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c199fa gap_c199fa size=6 ===== */

void gap_c199fa(void)

{
  undefined1 uVar1;
  char cVar2;
  
  func_0xc19b9e();
  cVar2 = UNK_00c898;
  UNK_00c898 = cVar2 + '\x01';
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19a00 gap_c19a00 size=6 ===== */

void gap_c19a00(void)

{
  undefined1 uVar1;
  char cVar2;
  
  gap_c19b84();
  cVar2 = UNK_00c898;
  UNK_00c898 = cVar2 + '\x01';
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19a06 gap_c19a06 size=8 ===== */

void gap_c19a06(void)

{
  undefined1 uVar1;
  char cVar2;
  
  gap_c19b92();
  UNK_00c898 = 0xff;
  cVar2 = UNK_00c898;
  UNK_00c898 = cVar2 + '\x01';
  func_0xc1984a(1);
  uVar1 = UNK_00c897;
  func_0xc1984c(uVar1);
  return;
}



/* ===== c19a22 gap_c19a22 size=10 ===== */

void gap_c19a22(void)

{
  FUN_c19846();
  func_0xc24f10();
  return;
}



/* ===== c19a2c command_dispatch size=20 ===== */

void command_dispatch(byte param_1)

{
  if (6 < param_1) {
    return;
  }
                    /* WARNING: Could not emulate address calculation at 0xc19a3a */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((uint3)*(ushort *)((ushort)param_1 * 2 + 0x7666 & 0x3fff) | 0xc10000))();
  return;
}



/* ===== c19a3e gap_c19a3e size=6 ===== */

void gap_c19a3e(void)

{
  func_0xc1985a();
  return;
}



/* ===== c19a44 gap_c19a44 size=6 ===== */

void gap_c19a44(void)

{
  gap_c19a22();
  return;
}



/* ===== c19a4a gap_c19a4a size=6 ===== */

void gap_c19a4a(void)

{
  gap_c19860();
  return;
}



/* ===== c19a50 gap_c19a50 size=6 ===== */

void gap_c19a50(void)

{
  gap_c19a68();
  return;
}



/* ===== c19a56 gap_c19a56 size=6 ===== */

void gap_c19a56(void)

{
  gap_c1c0b4();
  return;
}



/* ===== c19a5c gap_c19a5c size=6 ===== */

void gap_c19a5c(void)

{
  func_0xc22e06();
  return;
}



/* ===== c19a68 gap_c19a68 size=62 ===== */

void gap_c19a68(void)

{
  undefined2 uVar1;
  
  if (0x10 < DAT_c05084) {
    uVar1 = func_0xc14266(0);
    Ram00c89a = uVar1;
    uVar1 = Ram00c808;
    Ram00c89c = uVar1;
  }
  func_0xc1c06c();
  func_0xc19ea0();
  func_0xc15ec2();
  func_0xc17b30();
  FUN_c19846();
  FUN_c19846();
  func_0xc24eac();
  return;
}



/* ===== c19aa6 FUN_c19aa6 size=10 ===== */

void FUN_c19aa6(void)

{
  FUN_c1c098();
  FUN_c17b52();
  return;
}



/* ===== c19ab2 gap_c19ab2 size=38 ===== */

void gap_c19ab2(void)

{
  func_0xc1663c();
  gap_c14236();
  func_0xc1bf1e();
  gap_c19eb6();
  gap_c17b5c();
  FUN_c19846();
  func_0xc19434();
  gap_c24eb2();
  func_0xc24eb8();
  return;
}



/* ===== c19ae6 gap_c19ae6 size=18 ===== */

void gap_c19ae6(void)

{
  gap_c19ebc();
  gap_c15eac();
  gap_c17b70();
  func_0xc2280c();
  return;
}



/* ===== c19b04 gap_c19b04 size=18 ===== */

void gap_c19b04(void)

{
  gap_c1bfce();
  func_0xc19f6c();
  func_0xc0bfb0();
  func_0xc22de6();
  return;
}



/* ===== c19b32 gap_c19b32 size=14 ===== */

void gap_c19b32(void)

{
  gap_c194ac();
  gap_c24ec2();
  func_0xc2314c();
  return;
}



/* ===== c19b4a gap_c19b4a size=6 ===== */

void gap_c19b4a(void)

{
  gap_c1c024();
  return;
}



/* ===== c19b50 gap_c19b50 size=6 ===== */

void gap_c19b50(void)

{
  gap_c1c04a();
  return;
}



/* ===== c19b56 gap_c19b56 size=10 ===== */

void gap_c19b56(void)

{
  gap_c0ffee();
  gap_c19f80();
  return;
}



/* ===== c19b60 gap_c19b60 size=6 ===== */

void gap_c19b60(void)

{
  gap_c1f20a();
  return;
}



/* ===== c19b66 gap_c19b66 size=6 ===== */

void gap_c19b66(void)

{
  func_0xc2304a();
  return;
}



/* ===== c19b6c gap_c19b6c size=10 ===== */

void gap_c19b6c(void)

{
  gap_c17c28();
  FUN_c19846();
  return;
}



/* ===== c19b7a gap_c19b7a size=10 ===== */

void gap_c19b7a(void)

{
  func_0xc1c054();
  gap_c24ee0();
  return;
}



/* ===== c19b84 gap_c19b84 size=14 ===== */

void gap_c19b84(void)

{
  gap_c19f66();
  gap_c1c05e();
  gap_c17c2e();
  return;
}



/* ===== c19b92 gap_c19b92 size=10 ===== */

void gap_c19b92(void)

{
  gap_c2705e();
  gap_c24eee();
  return;
}



/* ===== c19d0a gap_c19d0a size=36 ===== */

void gap_c19d0a(void)

{
  short sVar1;
  char cVar2;
  
  cVar2 = DAT_00c93c;
  if (cVar2 == '\x03') {
    UNK_00c8a2 = 1;
  }
  cVar2 = UNK_00c8a2;
  if ((cVar2 != '\0') && (sVar1 = Ram00c8a0, sVar1 != -1)) {
    sVar1 = Ram00c8a0;
    Ram00c8a0 = sVar1 + 1;
  }
  return;
}



/* ===== c19d74 gap_c19d74 size=6 ===== */

void gap_c19d74(void)

{
  func_0xc19d80();
  return;
}



/* ===== c19e84 gap_c19e84 size=10 ===== */

void gap_c19e84(void)

{
  gap_c19d74();
  gap_c1a1e6();
  return;
}



/* ===== c19e94 gap_c19e94 size=6 ===== */

void gap_c19e94(void)

{
  gap_c1a208();
  return;
}



/* ===== c19eb6 gap_c19eb6 size=6 ===== */

void gap_c19eb6(void)

{
  func_0xc1a502();
  return;
}



/* ===== c19ebc gap_c19ebc size=170 ===== */

void gap_c19ebc(void)

{
  func_0xc159bc((short)&UNK_00c8aa,(short)&UNK_00c8be,5);
  func_0xc159bc((short)&UNK_00c8c4,(short)&UNK_00c8dc,1);
  func_0xc159bc((short)&UNK_00c8ca,(short)&UNK_00c8bc,1);
  func_0xc159bc((short)&UNK_00c8c8,(short)&UNK_00c8c6,1);
  func_0xc159bc((short)&UNK_00c8cc,(short)&UNK_00c8b4,4);
  func_0xc159bc((short)&UNK_00c8d4,(short)&UNK_00c8b8,4);
  func_0xc19d2e();
  func_0xc1abfc();
  func_0xc2098a();
  func_0xc20610();
  func_0xc20770();
  func_0xc1a4da();
  func_0xc19cb8();
  func_0xc1a7ec();
  func_0xc1e476();
  func_0xc1a192();
  gap_c1e714();
  func_0xc1e7d0();
  gap_c1a44e();
  func_0xc19f86();
  func_0xc1ab74();
  func_0xc1a1d0();
  func_0xc1e6a0();
  func_0xc1e8da();
  func_0xc1a4d4();
  func_0xc1abb8();
  func_0xc1a1d6();
  return;
}



/* ===== c19f66 gap_c19f66 size=6 ===== */

void gap_c19f66(void)

{
  gap_c19d0a();
  return;
}



/* ===== c19f80 gap_c19f80 size=6 ===== */

void gap_c19f80(void)

{
  func_0xc19ba0();
  return;
}



/* ===== c1a1e6 gap_c1a1e6 size=10 ===== */

void gap_c1a1e6(void)

{
  func_0xc1a35e();
  func_0xc1a440();
  return;
}



/* ===== c1a1f0 gap_c1a1f0 size=10 ===== */

void gap_c1a1f0(void)

{
  capture_control();
  func_0xc1a35e();
  return;
}



/* ===== c1a208 gap_c1a208 size=6 ===== */

void gap_c1a208(void)

{
  func_0xc1a35e();
  return;
}



/* ===== c1a298 gap_c1a298 size=122 ===== */

void gap_c1a298(void)

{
  short sVar1;
  short sVar2;
  
  sVar2 = Ram00c8ea;
  sVar1 = sRamc06506;
  if ((sVar2 <= sRamc06506) && (sVar2 = Ram00c8ea, sVar1 = sRamc06508, sRamc06508 <= sVar2)) {
    sVar1 = Ram00c8ea;
  }
  Ram00c8ea = sVar1;
  sVar1 = sVar1 + sRamc06cca;
  sVar2 = sRamc06506;
  if ((sVar1 <= sRamc06506) && (sVar2 = sRamc06508, sRamc06508 <= sVar1)) {
    sVar2 = sVar1;
  }
  Ram00c8e6 = sVar2;
  return;
}



/* ===== c1a44e gap_c1a44e size=134 ===== */

void gap_c1a44e(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  
  cVar1 = DAT_00c81c;
  if (cVar1 == '\0') {
    sVar2 = Ram00c8e8;
    sVar3 = sRamc06506;
    if ((sVar2 <= sRamc06506) && (sVar2 = Ram00c8e8, sVar3 = sRamc06508, sRamc06508 <= sVar2)) {
      sVar3 = Ram00c8e8;
    }
    Ram00c8ea = sVar3;
  }
  else {
    sVar2 = Ram00c8e0;
    sVar3 = sRamc06506;
    if ((sVar2 <= sRamc06506) && (sVar2 = Ram00c8e0, sVar3 = sRamc06508, sRamc06508 <= sVar2)) {
      sVar3 = Ram00c8e0;
    }
    Ram00c8e0 = sVar3;
    Ram00c8ea = sVar3;
  }
  func_0xc1e610();
  func_0xc1a3c6();
  return;
}



/* ===== c1a51a gap_c1a51a size=628 ===== */

short gap_c1a51a(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  short sVar6;
  short sVar7;
  
  if (cRame0089d == '\0') {
    sVar6 = sRamc079f2;
    if ((cRame008ba == '\0') && (cVar1 = UNK_00c78c, sVar6 = sRamc0650a, cVar1 == '\0')) {
      if (DAT_e0081a == '\0') {
        uVar5 = Ram00ca1c;
        uVar4 = axis16_unsigned(0x74f2,uVar5);
        uVar5 = Ram00c94e;
        uVar5 = axis16_signed(0x7552,uVar5);
        sVar6 = func_0xc28080(0x6646,0xc0,uVar4,uVar5);
        uVar5 = Ram00ca1c;
        uVar4 = axis16_unsigned(0x74f2,uVar5);
        uVar5 = DAT_00c936;
        uVar5 = axis16_signed(0x7552,uVar5);
        sVar7 = func_0xc28080(0x66e2,0xc0,uVar4,uVar5);
        Ram00c8ee = sVar6 + sVar7;
        func_0xc1ea58();
        if (cRame00832 == '\0') {
          cVar1 = DAT_00c81c;
          if (cVar1 == '\0') {
            uVar5 = DAT_00c9d0;
            uVar4 = gap_c28544(0x5122,0xc0,uVar5);
            uVar5 = Ram00ca1c;
            uVar5 = gap_c28544(0x51da,0xc0,uVar5);
            uVar5 = func_0xc28080(0x677e,0xc0,uVar4,uVar5);
            Ram00c8f2 = uVar5;
            func_0xc1ea12();
            sVar7 = Ram00c8f2;
            sVar6 = Ram00c8ee;
            Ram00c8fa = sVar7 + sVar6;
          }
          else {
            func_0xc1ea5a();
            sVar7 = Ram00ca56;
            sVar6 = Ram00c8ee;
            Ram00c8fa = sVar7 + sVar6;
          }
        }
        else {
          uVar5 = DAT_00c9d0;
          uVar4 = gap_c28544(0x5122,0xc0,uVar5);
          uVar5 = Ram00ca1c;
          uVar5 = gap_c28544(0x51da,0xc0,uVar5);
          sVar7 = func_0xc28080(0x6a24,0xc0,uVar4,uVar5);
          sVar6 = Ram00c8ee;
          Ram00c8fa = sVar7 + sVar6;
        }
        sVar6 = Ram00c8fa;
      }
      else {
        func_0xc1e9f2();
        uVar5 = DAT_00c06a;
        uVar5 = axis16_unsigned(0x7546,uVar5);
        sVar7 = gap_c27f0e(0x68bc,0xc0,uVar5);
        uVar5 = Ram00c8f8;
        uVar4 = DAT_00c962;
        uVar4 = rate_limit(uVar5,uVar4,uRamc0650c);
        uVar5 = axis16_unsigned(0x74da,uVar4);
        sVar2 = gap_c27f0e(0x68ca,0xc0,uVar5);
        uVar5 = DAT_00c9d0;
        uVar5 = gap_c28544(0x526a,0xc0,uVar5);
        sVar3 = gap_c27f0e(0x6a1c,0xc0,uVar5);
        sVar6 = Ram00ca58;
        Ram00c8f8 = uVar4;
        Ram00c8f6 = sVar6 + sVar7 + sVar2 + sVar3;
        cVar1 = UNK_00c8fe;
        if (cVar1 == '\0') {
          Ram00c8f4 = 0;
        }
        else {
          sVar6 = Ram00c88e;
          sVar7 = DAT_00c9d0;
          uVar5 = axis16_signed(0x74ec,sVar6 - sVar7);
          uVar5 = gap_c27f0e(0x68de,0xc0,uVar5);
          Ram00c8f4 = uVar5;
        }
        sVar2 = Ram00c8f6;
        sVar7 = Ram00c8f4;
        uVar5 = DAT_00c9d0;
        uVar5 = axis16_unsigned(0x74fe,uVar5);
        sVar6 = gap_c27f0e(0x68b4,0xc0,uVar5);
        if (sVar2 + sVar7 < sVar6) {
          sVar6 = sVar2 + sVar7;
        }
      }
    }
  }
  else {
    uRamc048f4 = 0;
    sVar6 = sRamc06a1a;
  }
  return sVar6;
}



/* ===== c1ac7c FUN_c1ac7c size=16 ===== */

void FUN_c1ac7c(void)

{
  undefined2 uVar1;
  
  DAT_00c920 = 1;
  uVar1 = FUN_c1aeac();
  DAT_00c91e = uVar1;
  return;
}



/* ===== c1ac8c gap_c1ac8c size=74 ===== */

void gap_c1ac8c(void)

{
  ushort uVar1;
  char cVar2;
  ushort uVar3;
  
  cVar2 = UNK_00c702;
  if (cVar2 != '\0') {
    uRamc0406a = uRamc06c50;
  }
  UNK_00c926 = 0;
  uVar1 = DAT_00c06a;
  uVar3 = uRamc06c5a;
  if (uRamc06c5a < uVar1) {
    uVar3 = uVar1;
  }
  if (uRamc06c58 < uVar3) {
    uRamc0406a = uRamc06c58;
    return;
  }
  DAT_00c06a = uVar3;
  return;
}



/* ===== c1acd6 gap_c1acd6 size=470 ===== */

void gap_c1acd6(void)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  cVar1 = UNK_00cc32;
  if ((cVar1 != '\0') || (cVar1 = UNK_00ca18, cVar1 != '\0')) {
    UNK_00c926 = 1;
    DAT_00c91c = 0;
    cVar1 = DAT_00c93c;
    if (cVar1 == '\x01') {
      uRamc0406a = uRamc06c50;
    }
    else {
      uRame0006a = uRame00826;
    }
    goto LAB_c1ae66;
  }
  UNK_00c926 = 0;
  uVar5 = DAT_00fd02;
  if (((uVar5 & 0x800) != 0) ||
     ((sVar2 = DAT_00c9d0, sVar2 != 0 || (uVar5 = DAT_00fd02, (uVar5 & 0x200) != 0)))) {
    func_0xc1d39c();
    cVar1 = DAT_00c93c;
    if ((((cVar1 == '\x03') && (cVar1 = DAT_00c934, cVar1 != '\0')) &&
        (uVar5 = DAT_00c9d0, uVar5 <= uRamc06c52)) &&
       (((cVar1 = UNK_00c9ea, cVar1 != '\0' && (uVar5 = Ram00c9ca, uVar5 < uRamc06ccc)) &&
        (cRamc0507b == '\0')))) {
      DAT_00c91c = 1;
      cVar1 = DAT_00c920;
      if (cVar1 != '\0') {
        DAT_00c920 = 0;
        uVar4 = DAT_00c91e;
        uVar3 = Ram00c924;
        uVar3 = func_0xc276a4(uVar4,uVar3);
        uVar4 = DAT_00c06a;
        uVar4 = rate_limit(uVar4,uVar3,uRamc06c56);
        DAT_00c06a = uVar4;
      }
    }
    else {
      DAT_00c920 = 0;
      DAT_00c91c = 0;
    }
    uVar4 = DAT_00c9d0;
    uVar4 = gap_c28544(0x50dc,0xc0,uVar4);
    uVar4 = tbl8_interp(0x6ca4,0xc0,uVar4);
    Ram00c922 = uVar4;
    goto LAB_c1ae66;
  }
  cVar1 = UNK_00cc2c;
  if (cVar1 != '\0') {
    uRamc0406a = uRamc06c50;
    UNK_00c926 = 1;
    goto LAB_c1ae66;
  }
  uVar4 = FUN_c1aeac();
  uVar5 = func_0xc27b10(uRame00824,uVar4);
  if (uRame00828 == 0) {
    uRame00824 = FUN_c1aeac(0);
LAB_c1ade6:
    uRame00828 = uRame00828 + 1;
  }
  else {
    if (uVar5 <= uRamc06cc2) goto LAB_c1ade6;
    uRame00828 = 0;
  }
  if (uRamc06cd6 < uRame00828) {
    uVar4 = DAT_00c06a;
    uVar4 = rate_limit(uVar4,uRame00824,uRamc06c54);
    DAT_00c06a = uVar4;
    uRame00828 = 0;
  }
LAB_c1ae66:
  uVar5 = DAT_00c06a;
  if (uVar5 <= uRamc06c5a) {
    uVar5 = uRamc06c5a;
  }
  if (uRamc06c58 < uVar5) {
    uRamc0406a = uRamc06c58;
  }
  else {
    DAT_00c06a = uVar5;
  }
  uRame00826 = DAT_00c06a;
  return;
}



/* ===== c1aeac FUN_c1aeac size=48 ===== */

void FUN_c1aeac(void)

{
  ushort uVar1;
  
  uVar1 = FUN_c13dc8(3);
  FUN_c276ba((short)((uint)uVar1 * (uint)DAT_c06c4c >> 0x10),DAT_c06c4e);
  return;
}



/* ===== c1aedc gap_c1aedc size=280 ===== */

/* WARNING: Removing unreachable block (ram,0xc1afb2) */

char gap_c1aedc(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  ushort uVar7;
  short sVar8;
  char cVar9;
  undefined2 uVar10;
  ushort uVar11;
  
  cVar5 = DAT_00c784;
  cVar4 = DAT_00c780;
  uVar11 = DAT_00c9d0;
  bVar1 = uRamc06c68 <= uVar11;
  uVar11 = DAT_00c9d0;
  bVar3 = uVar11 <= uRamc06c6a;
  sVar8 = Ram00ca26;
  bVar2 = sRamc0709e <= sVar8;
  cVar6 = UNK_00c9ba;
  uVar10 = DAT_00c9d0;
  uVar10 = axis16_unsigned(0x74e0,uVar10);
  uVar11 = tbl8_interp(0x6c20,0xc0,uVar10);
  cVar9 = DAT_00c954;
  if ((((((cVar9 == '\0') || (cVar5 != '\0')) || (cVar4 != '\0')) ||
       (((bVar1 || (bVar3)) || ((bVar2 || (uVar7 = Ram00ca1c, uVar7 <= uVar11)))))) ||
      ((cVar6 == '\0' && (uVar11 = Ram00c9ca, uRamc06c6c <= uVar11)))) ||
     ((DAT_c06b69 == '\0' &&
      ((((cVar9 = FUN_c243a8(0xb), cVar9 != '\0' || (cVar9 = FUN_c243a8(0xc), cVar9 != '\0')) ||
        (cVar9 = FUN_c243a8(0x12), cVar9 != '\0')) || (cVar9 = FUN_c243a8(0x13), cVar9 != '\0'))))))
  {
    DAT_00c92b = 0;
  }
  else {
    DAT_00c92b = 1;
  }
  return cVar9;
}



/* ===== c1b2e2 gap_c1b2e2 size=26 ===== */

void gap_c1b2e2(void)

{
  Ram00c932 = 0;
  Ram00c92c = 0;
  DAT_00c934 = 0;
  DAT_00c92e = 0;
  DAT_00c92b = 0;
  UNK_00c928 = 0;
  return;
}



/* ===== c1b2fc gap_c1b2fc size=78 ===== */

void gap_c1b2fc(void)

{
  undefined2 uVar1;
  
  uRame0082c = FUN_c13dc8(0);
  uVar1 = axis16_unsigned(0x74d4,uRame0082c);
  uVar1 = gap_c27bf8(0x6bdc,0xc0,uVar1);
  DAT_00c936 = uVar1;
  uVar1 = axis16_signed(0x74e6,uVar1);
  DAT_00c97c = uVar1;
  uRame0082e = DAT_00c936;
  uRame0082a = uRame0082e;
  return;
}



/* ===== c1b34a gap_c1b34a size=86 ===== */

void gap_c1b34a(void)

{
  undefined2 uVar1;
  
  func_0xc1b462();
  uRame0082c = FUN_c13dc8(0);
  uVar1 = axis16_unsigned(0x74d4,uRame0082c);
  uVar1 = gap_c27bf8(0x6bdc,0xc0,uVar1);
  DAT_00c936 = uVar1;
  gap_c20400();
  uRame0082e = func_0xc1591c(uRame0082e,uRame00936,uRamc06c70);
  return;
}



/* ===== c1b4fa gap_c1b4fa size=260 ===== */

void gap_c1b4fa(void)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  
  cVar3 = DAT_00c93c;
  if (cVar3 != '\x03') {
    sVar1 = DAT_00c936;
    if (sVar1 < sRamc06c3c) {
      uRamc0493f = uRamc06c42;
    }
    else {
      sVar1 = DAT_00c936;
      if (sVar1 < sRamc06c3e) {
        uRamc0493f = uRamc06c43;
      }
      else {
        uRamc0493f = uRamc06c3a;
      }
    }
  }
  cVar3 = DAT_00c93c;
  if ((cVar3 == '\x02') && (uVar5 = DAT_00c9d0, uRamc06c34 <= uVar5)) {
    UNK_00c93b = 2;
    bVar2 = UNK_00c938;
    bVar4 = UNK_00c93f;
    if (bVar4 <= bVar2) {
      UNK_00c943 = 1;
      UNK_00c93b = 1;
    }
  }
  else {
    UNK_00c943 = 0;
    UNK_00c93b = 0;
  }
  cVar3 = DAT_00c93c;
  if ((cVar3 == '\x02') && (uVar5 = DAT_00c9d0, uVar5 < 0xf1)) {
    UNK_00c944 = 1;
  }
  else {
    UNK_00c944 = 0;
  }
  cVar3 = DAT_00c93c;
  if ((cVar3 == '\x03') && (uVar5 = DAT_00c9d0, uVar5 <= uRamc06c36)) {
    UNK_00c948 = 1;
  }
  else {
    UNK_00c948 = 0;
  }
  cVar3 = DAT_00c93c;
  if ((cVar3 == '\x04') && (uVar5 = DAT_00c9d0, 0xf0 < uVar5)) {
    UNK_00c93e = 1;
  }
  else {
    UNK_00c93e = 0;
  }
  cVar3 = DAT_00c93c;
  if ((cVar3 == '\x01') && (uVar5 = DAT_00c9d0, 0xf0 < uVar5)) {
    UNK_00c939 = 1;
    return;
  }
  UNK_00c939 = 0;
  return;
}



/* ===== c1b5fe gap_c1b5fe size=96 ===== */

void gap_c1b5fe(void)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = DAT_00c954;
  if ((cVar1 == '\0') && (uVar2 = Ram00c946, uVar2 < uRamc06c40)) {
    UNK_00c941 = 1;
  }
  else {
    cVar1 = DAT_00c954;
    if ((cVar1 == '\0') && (uVar2 = Ram00c946, uRamc06c40 <= uVar2)) {
      UNK_00c940 = 1;
      UNK_00c941 = 0;
    }
    else {
      UNK_00c940 = 0;
      UNK_00c941 = 0;
      Ram00c946 = 0;
    }
  }
  cVar1 = UNK_00c940;
  if ((cVar1 != '\0') && (cVar1 = UNK_00c9e6, cVar1 != '\0')) {
    gap_c1c410();
    UNK_00c94a = 1;
  }
  return;
}



/* ===== c1b682 gap_c1b682 size=36 ===== */

void gap_c1b682(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  
  cVar1 = DAT_00c954;
  if (cVar1 == '\0') {
    DAT_00c93c = 5;
    func_0xc19806();
  }
  else {
    cVar1 = UNK_00c939;
    if (cVar1 != '\0') {
      DAT_00c93c = 2;
      func_0xc19810();
    }
  }
  uVar3 = DAT_00fd02;
  if (((uVar3 & 0x800) == 0) && (sVar2 = DAT_00c9d0, sVar2 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  UNK_00c93a = uVar4;
  return;
}



/* ===== c1b6a6 gap_c1b6a6 size=38 ===== */

void gap_c1b6a6(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  
  cVar1 = UNK_00c943;
  if (cVar1 == '\0') {
    cVar1 = UNK_00c944;
    if (cVar1 != '\0') {
      DAT_00c93c = 4;
      gap_c197ac();
    }
  }
  else {
    DAT_00c93c = 3;
    func_0xc197e4();
    uVar3 = DAT_00fd02;
    DAT_00fd02 = uVar3 & 0xfdff;
  }
  uVar3 = DAT_00fd02;
  if (((uVar3 & 0x800) == 0) && (sVar2 = DAT_00c9d0, sVar2 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  UNK_00c93a = uVar4;
  return;
}



/* ===== c1b6cc gap_c1b6cc size=36 ===== */

void gap_c1b6cc(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  
  cVar1 = DAT_00c954;
  if (cVar1 == '\0') {
    DAT_00c93c = 5;
    func_0xc197d2();
  }
  else {
    cVar1 = UNK_00c948;
    if (cVar1 != '\0') {
      DAT_00c93c = 2;
      gap_c197ee();
    }
  }
  uVar3 = DAT_00fd02;
  if (((uVar3 & 0x800) == 0) && (sVar2 = DAT_00c9d0, sVar2 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  UNK_00c93a = uVar4;
  return;
}



/* ===== c1b6f0 gap_c1b6f0 size=36 ===== */

void gap_c1b6f0(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  
  cVar1 = DAT_00c954;
  if (cVar1 == '\0') {
    DAT_00c93c = 5;
    gap_c197cc();
  }
  else {
    cVar1 = UNK_00c93e;
    if (cVar1 != '\0') {
      DAT_00c93c = 2;
      gap_c197c2();
    }
  }
  uVar3 = DAT_00fd02;
  if (((uVar3 & 0x800) == 0) && (sVar2 = DAT_00c9d0, sVar2 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  UNK_00c93a = uVar4;
  return;
}



/* ===== c1b714 gap_c1b714 size=38 ===== */

void gap_c1b714(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined1 uVar4;
  
  cVar1 = DAT_00c954;
  if (cVar1 == '\x01') {
    DAT_00c93c = 1;
    gap_c1981a();
  }
  else {
    cVar1 = UNK_00c940;
    if (cVar1 != '\0') {
      DAT_00c93c = 6;
      gap_c197f8();
    }
  }
  uVar3 = DAT_00fd02;
  if (((uVar3 & 0x800) == 0) && (sVar2 = DAT_00c9d0, sVar2 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  UNK_00c93a = uVar4;
  return;
}



/* ===== c1b73a gap_c1b73a size=70 ===== */

void gap_c1b73a(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  undefined1 uVar4;
  
  cVar1 = UNK_00c94a;
  if (cVar1 == '\0') {
    cVar1 = DAT_00c954;
    if (cVar1 == '\x01') {
      DAT_00c93c = 1;
      gap_c19830();
    }
    else {
      uVar2 = DAT_00c9d0;
      if (uVar2 < 0xf1) {
        uVar2 = DAT_00fd02;
        DAT_00fd02 = uVar2 & 0xf3ff;
      }
    }
  }
  else {
    gap_c1983e();
    DAT_00c93c = 0;
  }
  uVar2 = DAT_00fd02;
  if (((uVar2 & 0x800) == 0) && (sVar3 = DAT_00c9d0, sVar3 == 0)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  UNK_00c93a = uVar4;
  return;
}



/* ===== c1b784 gap_c1b784 size=50 ===== */

void gap_c1b784(void)

{
  short sVar1;
  char cVar2;
  
  cVar2 = DAT_00c93c;
  if (cVar2 == '\x03') {
    sVar1 = Ram00c072;
    if (sVar1 != -1) {
      sVar1 = Ram00c072;
      Ram00c072 = sVar1 + 1;
      UNK_00c93d = 1;
    }
    gap_c20450();
    return;
  }
  sVar1 = Ram00c072;
  if (sVar1 != 0) {
    Ram00c06c = sVar1;
  }
  Ram00c072 = 0;
  return;
}



/* ===== c1b866 gap_c1b866 size=284 ===== */

void gap_c1b866(void)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  ushort uVar4;
  char cVar5;
  ushort uVar6;
  undefined2 uVar7;
  
  if ((DAT_e00810 == '\0') && (cRame00811 == '\0')) {
    uRame00834 = 0;
  }
  else {
    uVar3 = DAT_00c97c;
    uVar6 = tbl16_interp(0x6b6a,0xc0,uVar3);
    uVar4 = DAT_00c9d0;
    if ((uVar4 <= uRamc06b92) || (uVar4 = Ram00ca1c, bVar1 = bRamc06b91, uVar4 <= uRamc06b94)) {
      bVar1 = bRamc06b90;
    }
    iVar2 = (uint)uVar6 * (uint)bVar1 * 0x100;
    uRame00834 = (ushort)iVar2 >> 0xf | (short)((uint)iVar2 >> 0x10) << 1;
    if (0x8000 < uRame00834) {
      uRame00834 = 0x8000;
    }
  }
  uVar3 = uRamc06b8e;
  uVar7 = func_0xc27b86(uRame00834,0x8000,0xf);
  Ram00c98c = uVar7;
  uVar7 = FUN_c28852(0x8000,uVar7);
  Ram00c98c = uVar7;
  func_0xc14c70(0,uVar3,uVar7);
  if (cRamc0506d == '\x01') {
    uVar7 = Ram00c98c;
    func_0xc14c70(5,uVar3,uVar7);
  }
  cVar5 = cRame00811;
  if (DAT_e00810 == '\x01') {
    func_0xc14cec(0);
  }
  if ((cRamc0506d == '\x01') && (cVar5 == '\x01')) {
    func_0xc14cec(5);
  }
  return;
}



/* ===== c1b982 gap_c1b982 size=138 ===== */

void gap_c1b982(void)

{
  undefined2 uVar1;
  char cVar2;
  undefined2 uVar3;
  
  uVar1 = uRamc06b8e;
  uRame00834 = 0;
  uVar3 = func_0xc27b86(0,0x8000,0xf);
  Ram00c98c = uVar3;
  uVar3 = FUN_c28852(0x8000,uVar3);
  Ram00c98c = uVar3;
  func_0xc14c70(0,uVar1,uVar3);
  if (cRamc0506d == '\x01') {
    uVar3 = Ram00c98c;
    func_0xc14c70(5,uVar1,uVar3);
  }
  cVar2 = cRame00811;
  if (DAT_e00810 == '\x01') {
    func_0xc14cec(0);
  }
  if ((cRamc0506d == '\x01') && (cVar2 == '\x01')) {
    func_0xc14cec(5);
  }
  return;
}



/* ===== c1bc74 gap_c1bc74 size=12 ===== */

void gap_c1bc74(void)

{
  Ram00c968 = 0;
  UNK_00c966 = 1;
  return;
}



/* ===== c1bc90 gap_c1bc90 size=6 ===== */

void gap_c1bc90(void)

{
  gap_c1bc74();
  return;
}



/* ===== c1bc96 gap_c1bc96 size=6 ===== */

void gap_c1bc96(void)

{
  gap_c1bc74();
  return;
}



/* ===== c1beca gap_c1beca size=34 ===== */

void gap_c1beca(void)

{
  func_0xc1c572();
  func_0xc1c26a();
  gap_c1b2e2();
  gap_c142a4();
  gap_c1c0ea();
  gap_c225e4();
  func_0xc1bca2();
  gap_c1d8c6();
  return;
}



/* ===== c1beec gap_c1beec size=10 ===== */

void gap_c1beec(void)

{
  gap_c1cbc4();
  func_0xc1bc9c();
  return;
}



/* ===== c1bf0a gap_c1bf0a size=6 ===== */

void gap_c1bf0a(void)

{
  gap_c1cb9e();
  return;
}



/* ===== c1bfce gap_c1bfce size=36 ===== */

void gap_c1bfce(void)

{
  func_0xc159bc((short)&UNK_00c974,(short)&UNK_00c976,1);
  func_0xc1c426();
  func_0xc209fa();
  func_0xc1e420();
  gap_c1e380();
  func_0xc1b7b6();
  return;
}



/* ===== c1c024 gap_c1c024 size=38 ===== */

void gap_c1c024(void)

{
  undefined2 uVar1;
  
  gap_c1b34a();
  func_0xc1ba3c();
  func_0xc14510();
  func_0xc1b3a0();
  func_0xc1ba8a();
  uVar1 = DAT_00c936;
  uVar1 = axis16_signed(0x74e6,uVar1);
  DAT_00c97c = uVar1;
  return;
}



/* ===== c1c04a gap_c1c04a size=10 ===== */

void gap_c1c04a(void)

{
  gap_c1b5fe();
  func_0xc1bd6a();
  return;
}



/* ===== c1c05e gap_c1c05e size=8 ===== */

void gap_c1c05e(void)

{
  gap_c1b784();
  gap_c2046c();
  gap_c1c1f0();
  return;
}



/* ===== c1c098 FUN_c1c098 size=6 ===== */

void FUN_c1c098(void)

{
  FUN_c1d950();
  return;
}



/* ===== c1c09e gap_c1c09e size=22 ===== */

void gap_c1c09e(void)

{
  undefined2 uVar1;
  
  func_0xc2282e();
  uVar1 = Ram00cafc;
  gap_c1da6e(uVar1);
  func_0xc228be();
  func_0xc1dc8c();
  return;
}



/* ===== c1c0b4 gap_c1c0b4 size=54 ===== */

void gap_c1c0b4(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00c9d0;
  if (uRamc07cd8 < uVar1) {
    Ram00cb02 = 0;
    Ram00cb04 = 0;
    gap_c1c3ee(0,0);
    gap_c1c3ee(0,1);
    return;
  }
  gap_c1c09e();
  gap_c15ecc();
  func_0xc17cbc();
  return;
}



/* ===== c1c0ea gap_c1c0ea size=6 ===== */

void gap_c1c0ea(void)

{
  func_0xc1c0f6();
  return;
}



/* ===== c1c12a gap_c1c12a size=48 ===== */

void gap_c1c12a(void)

{
  char cVar1;
  
  Ram00c99c = 0;
  Ram00c99e = 0;
  Ram00c9a0 = 0;
  cVar1 = UNK_00c702;
  if (cVar1 != '\0') {
    Ram00c066 = 0;
    Ram00c062 = 0;
    UNK_00c060 = 0;
    UNK_00c076 = 0;
    Ram00c070 = 0;
    UNK_00c068 = 0;
    Ram00c074 = 0;
  }
  return;
}



/* ===== c1c1f0 gap_c1c1f0 size=104 ===== */

void gap_c1c1f0(void)

{
  short sVar1;
  undefined2 uVar2;
  char cVar3;
  byte bVar4;
  undefined1 uVar5;
  short sVar6;
  
  cVar3 = UNK_00c1b6;
  if (cVar3 != '\0') {
    cVar3 = UNK_00c068;
    if (cVar3 == '\0') {
      Ram00c070 = 0;
      UNK_00c076 = 0;
      Ram00c074 = 0;
    }
    else {
      cVar3 = UNK_00c076;
      UNK_00c076 = cVar3 + '\x01';
      bVar4 = UNK_00c076;
      if (0x3b < bVar4) {
        sVar1 = Ram00c070;
        Ram00c070 = sVar1 + 1;
        sVar1 = Ram00c070;
        if (sVar1 == -1) {
          Ram00c070 = 0xffff;
        }
        UNK_00c076 = 0;
      }
      sVar1 = Ram00c062;
      sVar6 = Ram00c9a0;
      if ((sVar1 != sVar6) && (sVar1 = Ram00c074, sVar1 != -1)) {
        sVar1 = Ram00c074;
        Ram00c074 = sVar1 + 1;
      }
    }
  }
  uVar2 = Ram00c062;
  Ram00c9a0 = uVar2;
  uVar5 = UNK_00c1b6;
  UNK_00c068 = uVar5;
  return;
}



/* ===== c1c2b8 gap_c1c2b8 size=6 ===== */

void gap_c1c2b8(void)

{
  func_0xc140f0();
  return;
}



/* ===== c1c2c4 gap_c1c2c4 size=6 ===== */

void gap_c1c2c4(void)

{
  func_0xc141fc();
  return;
}



/* ===== c1c3ee gap_c1c3ee size=34 ===== */

void gap_c1c3ee(char param_1,ushort param_2)

{
  if (param_1 != '\x01') {
    func_0xc141fc(0xffff);
    return;
  }
  func_0xc141fc(*(undefined2 *)(uint3)((short)&UNK_00cb02 + (param_2 & 0xff) * 2));
  return;
}



/* ===== c1c410 gap_c1c410 size=22 ===== */

void gap_c1c410(void)

{
  short sVar1;
  char cVar2;
  
  cVar2 = UNK_00c9b0;
  if ((cVar2 != '\0') && (sVar1 = DAT_00c06e, sVar1 != -1)) {
    sVar1 = DAT_00c06e;
    DAT_00c06e = sVar1 + 1;
  }
  return;
}



/* ===== c1c564 gap_c1c564 size=14 ===== */

void gap_c1c564(void)

{
  Ram00c97e = 0;
  DAT_e00844 = 0;
  return;
}



/* ===== c1c718 gap_c1c718 size=332 ===== */

void gap_c1c718(void)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  byte bVar4;
  
  func_0xc159bc((short)&UNK_00c9d4,(short)&UNK_00c9b2,5);
  cVar2 = UNK_00c9bc;
  if (cVar2 == '\0') {
    UNK_00c9b2 = 1;
    uVar1 = DAT_00fd02;
    if ((uVar1 & 0x200) != 0) {
      UNK_00c9b5 = 1;
    }
    uVar1 = DAT_00fd02;
    if ((uVar1 & 0x100) != 0) {
      UNK_00c9b6 = 1;
    }
    uVar1 = Ram00c9dc;
    if (0x80 < uVar1) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfeff;
      UNK_00c9b6 = 0;
      Ram00c9dc = 0;
    }
    uVar1 = Ram00c9d4;
    if (uRamc06c5e < uVar1) {
      DAT_00c9d0 = 0;
      Ram00c9d2 = 0xffff;
      bVar4 = 0;
      do {
        uVar1 = (ushort)bVar4;
        bVar4 = bVar4 + 1;
        *(undefined2 *)(uint3)((short)&UNK_00c9c0 + uVar1 * 2) = 0xffff;
      } while (bVar4 < 4);
      UNK_00c9bb = 0;
    }
    uVar1 = Ram00c9da;
    if (uRamc06c60 < uVar1) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfdff;
      UNK_00c9b5 = 0;
      Ram00c9da = 0;
    }
  }
  else {
    UNK_00c9bc = 0;
    UNK_00c9b2 = 0;
    Ram00c9d4 = 0;
    uVar1 = DAT_00fd02;
    if ((uVar1 & 0x200) != 0) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfdff;
      UNK_00c9b5 = 0;
      Ram00c9da = 0;
    }
    uVar1 = DAT_00fd02;
    if ((uVar1 & 0x100) != 0) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfeff;
      UNK_00c9b6 = 0;
      Ram00c9dc = 0;
    }
  }
  sVar3 = DAT_00c9d0;
  if (sVar3 != 0) {
    UNK_00c9c8 = 1;
    Ram00c9d8 = 0;
    UNK_00c9b4 = 0;
  }
  uVar1 = DAT_00fd02;
  if ((((uVar1 & 0x800) == 0) && (sVar3 = DAT_00c9d0, sVar3 == 0)) ||
     (sVar3 = DAT_00c9d0, sVar3 != 0)) {
    UNK_00c9b3 = 0;
    Ram00c9d6 = 0;
  }
  else {
    cVar2 = UNK_00c9c8;
    if (cVar2 != '\0') {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfbff;
      UNK_00c9c8 = 0;
    }
    uVar1 = Ram00c9d6;
    if (uRamc06c62 < uVar1) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xf7ff;
      Ram00c9d6 = 0;
      UNK_00c9b3 = 0;
    }
    else {
      UNK_00c9b3 = 1;
    }
    uVar1 = DAT_00fd02;
    if ((uVar1 & 0x200) != 0) {
      uVar1 = DAT_00fd02;
      DAT_00fd02 = uVar1 & 0xfdff;
      UNK_00c9b5 = 0;
      Ram00c9da = 0;
    }
  }
  uVar1 = DAT_00fd02;
  if ((((uVar1 & 0x400) != 0) || (sVar3 = DAT_00c9d0, sVar3 != 0)) &&
     (sVar3 = DAT_00c9d0, sVar3 == 0)) {
    uVar1 = Ram00c9d8;
    if (uVar1 < 0x2b3) {
      UNK_00c9b4 = 1;
      return;
    }
    uVar1 = DAT_00fd02;
    DAT_00fd02 = uVar1 & 0xfbff;
  }
  UNK_00c9b4 = 0;
  Ram00c9d8 = 0;
  return;
}



/* ===== c1c864 gap_c1c864 size=10 ===== */

void gap_c1c864(void)

{
  UNK_00c9e0 = 0;
  Ram00c9de = 0;
  return;
}



/* ===== c1c956 gap_c1c956 size=102 ===== */

undefined4 gap_c1c956(undefined2 param_1,undefined2 param_2,ushort param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = CONCAT22(param_2,param_1);
  uVar1 = param_3 + 4;
  if ((*(byte *)(uint3)uVar1 & 0x7f) == 1) {
    if ((*(byte *)(uint3)uVar1 & 0x80) == 0) {
      uVar2 = CONCAT22(*(undefined2 *)(uint3)(param_3 + 2),*(undefined2 *)(uint3)param_3);
    }
    else {
      uVar2 = mul32();
    }
  }
  else if ((*(byte *)(uint3)uVar1 & 0x7f) == 2) {
    if ((*(byte *)(uint3)uVar1 & 0x80) == 0) {
      uVar2 = gap_c27738(*(undefined2 *)(uint3)param_3,*(undefined2 *)(uint3)(param_3 + 2));
    }
    else {
      uVar2 = gap_c288a8(*(undefined2 *)(uint3)param_3,*(undefined2 *)(uint3)(param_3 + 2));
    }
  }
  return uVar2;
}



/* ===== c1c9bc gap_c1c9bc size=96 ===== */

char gap_c1c9bc(char param_1,ushort param_2)

{
  ushort uVar1;
  short sVar2;
  
  uVar1 = param_2 + 1;
  if ((*(byte *)(uint3)uVar1 & 0x7f) == 1) {
    if ((*(byte *)(uint3)uVar1 & 0x80) == 0) {
      param_1 = *(char *)(uint3)param_2;
    }
    else {
      param_1 = -*(char *)(uint3)param_2;
    }
  }
  else if ((*(byte *)(uint3)uVar1 & 0x7f) == 2) {
    if ((*(byte *)(uint3)uVar1 & 0x80) == 0) {
      sVar2 = (short)param_1 + (short)*(char *)(uint3)param_2;
    }
    else {
      sVar2 = (short)param_1 - (short)*(char *)(uint3)param_2;
    }
    if (sVar2 < 0x80) {
      if (sVar2 < -0x80) {
        param_1 = -0x80;
      }
      else {
        param_1 = (char)sVar2;
      }
    }
    else {
      param_1 = '\x7f';
    }
  }
  return param_1;
}



/* ===== c1ca5e gap_c1ca5e size=94 ===== */

undefined4 gap_c1ca5e(undefined2 param_1,undefined2 param_2,ushort param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = CONCAT22(param_2,param_1);
  uVar1 = param_3 + 4;
  if ((*(byte *)(uint3)uVar1 & 0x7f) == 1) {
    if ((*(byte *)(uint3)uVar1 & 0x80) == 0) {
      uVar2 = CONCAT22(*(undefined2 *)(uint3)(param_3 + 2),*(undefined2 *)(uint3)param_3);
    }
    else {
      uVar2 = CONCAT22(-(*(short *)(uint3)(param_3 + 2) + (ushort)(*(short *)(uint3)param_3 != 0)),
                       -*(short *)(uint3)param_3);
    }
  }
  else if ((*(byte *)(uint3)uVar1 & 0x7f) == 2) {
    if ((*(byte *)(uint3)uVar1 & 0x80) == 0) {
      uVar2 = gap_c27776(*(undefined2 *)(uint3)param_3,*(undefined2 *)(uint3)(param_3 + 2));
    }
    else {
      uVar2 = gap_c288c2(*(undefined2 *)(uint3)param_3,*(undefined2 *)(uint3)(param_3 + 2));
    }
  }
  return uVar2;
}



/* ===== c1cad8 gap_c1cad8 size=198 ===== */

void gap_c1cad8(void)

{
  char cVar1;
  
  gap_c14368(4,1);
  cVar1 = UNK_00c702;
  if (cVar1 == '\0') {
    uRame00855 = DAT_00c078._0_1_;
    cVar1 = UNK_00c064;
    uRame009e7 = uRame00855;
    if (cVar1 == '\0') {
      gap_c14368(2,0);
    }
    else {
      gap_c14368(2,1);
    }
    cVar1 = UNK_00c069;
    if (cVar1 == '\0') {
      gap_c14368(3,0);
    }
    else {
      gap_c14368(3,1);
    }
  }
  else {
    uRame00855 = uRamc06ce2;
    UNK_00c9e7 = uRamc06ce2;
  }
  uRame00856 = 0;
  uRame00852 = 0;
  uRame00847 = 0;
  DAT_e00846 = 0;
  uRame0084e = 0;
  uRame00851 = 0;
  uRame009e6 = 0;
  uRame0084f = 0;
  uRame00858 = 0;
  uRame009e5 = 0;
  Ram00c9e8 = 0;
  uRame00859 = 1;
  uRame00854 = 1;
  return;
}



/* ===== c1cb9e gap_c1cb9e size=38 ===== */

void gap_c1cb9e(void)

{
  undefined1 uVar1;
  
  UNK_00c9e5 = 0;
  Ram00c9e8 = 0;
  uVar1 = UNK_00c9e7;
  DAT_00c078._0_1_ = uVar1;
  uVar1 = func_0xc142c8(3);
  UNK_00c064 = uVar1;
  uVar1 = func_0xc142c8(4);
  UNK_00c069 = uVar1;
  return;
}



/* ===== c1cbc4 gap_c1cbc4 size=20 ===== */

void gap_c1cbc4(void)

{
  gap_c14368(4,1);
  gap_c14368(2,0);
  gap_c14368(3,0);
  return;
}



/* ===== c1d0c4 gap_c1d0c4 size=12 ===== */

void gap_c1d0c4(undefined1 param_1)

{
  uRame00850 = param_1;
  return;
}



/* ===== c1d0d0 gap_c1d0d0 size=12 ===== */

void gap_c1d0d0(undefined1 param_1)

{
  uRame00849 = param_1;
  return;
}



/* ===== c1d358 gap_c1d358 size=68 ===== */

void gap_c1d358(void)

{
  Ram00c87e = 0;
  UNK_00c864 = 0;
  if (cRame0085a != '\0') {
    cRame0085e = 0;
    uRame009e7 = 0;
    DAT_e0085b = 0;
    cRame0085a = 0;
    return;
  }
  if (cRame0085e != '\0') {
    cRame0085e = '\0';
  }
  return;
}



/* ===== c1d450 gap_c1d450 size=30 ===== */

void gap_c1d450(void)

{
  ushort uVar1;
  char cVar2;
  byte bVar3;
  
  cVar2 = UNK_00c702;
  if (cVar2 != '\0') {
    bVar3 = 0;
    do {
      uVar1 = (ushort)bVar3;
      bVar3 = bVar3 + 1;
      *(undefined2 *)(uint3)((short)&UNK_00c07a + uVar1 * 2) = 0x8000;
    } while (bVar3 < 0x10);
  }
  return;
}



/* ===== c1d8c6 gap_c1d8c6 size=68 ===== */

void gap_c1d8c6(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00c06a;
  uVar1 = axis16_unsigned(0x7546,uVar1);
  uVar1 = tbl16_interp(0x6c7a,0xc0,uVar1);
  DAT_00ca04 = uVar1;
  Ram00ca16 = uVar1;
  DAT_00c9f8 = 0;
  Ram00ca0e = 0x2d00;
  Ram00c9fe = 0x2d00;
  func_0xc1d87a();
  uVar1 = DAT_00ca04;
  Ram00ca1c = uVar1;
  func_0xc1d8b2();
  return;
}



/* ===== c1d950 FUN_c1d950 size=286 ===== */

void FUN_c1d950(void)

{
  undefined2 uVar1;
  ushort uVar2;
  short sVar3;
  char cVar4;
  ushort uVar5;
  ushort uVar6;
  undefined2 uVar7;
  
  uVar5 = FUN_c13dc8(3);
  uVar5 = FUN_c276ba(DAT_c06c4e,(short)((uint)uVar5 * (uint)DAT_c06c4c >> 0x10));
  DAT_00c9f2 = uVar5;
  if ((uVar5 < DAT_c06c76) && (DAT_c06c78 < uVar5)) {
    uVar7 = DAT_00ca0c;
    uVar6 = rate_limit(uVar7,uVar5,DAT_c06c74);
    DAT_00ca0c = uVar6;
    sVar3 = DAT_00ca1a;
    DAT_00c9f6 = uVar6 + sVar3 >> 1;
    uVar5 = DAT_00c9f6;
    if (uVar6 < uVar5) {
      uVar7 = DAT_00c9f6;
      uVar1 = DAT_00ca0c;
      uVar7 = FUN_c28852(uVar7,uVar1);
    }
    else {
      uVar1 = DAT_00ca0c;
      uVar7 = DAT_00c9f6;
      uVar7 = FUN_c28852(uVar1,uVar7);
    }
    DAT_00ca02 = uVar7;
    uVar7 = DAT_00ca0c;
    DAT_00ca1a = uVar7;
    DAT_00ca14 = 0;
    cVar4 = DAT_00c934;
    if (cVar4 == '\0') {
      uVar2 = DAT_00ca0c;
      uVar5 = DAT_00c9f6;
      uVar6 = DAT_00c9f6;
      if (uVar2 == uVar6 || uVar2 < uVar5) {
LAB_c1da2a:
        uVar1 = DAT_00ca04;
        uVar7 = DAT_00c9f2;
        uVar7 = rate_limit(uVar1,uVar7,DAT_c06c92);
        DAT_00ca04 = uVar7;
        return;
      }
    }
    else {
      if (DAT_c06b68 == '\0') {
        cVar4 = DAT_00c92f;
      }
      else {
        cVar4 = DAT_00c930;
      }
      if (cVar4 == '\0') {
        cVar4 = DAT_00c9f8;
        if (cVar4 == '\0') {
          DAT_00c9f8 = 1;
          DAT_00ca08 = 0;
          uVar7 = DAT_00c9f2;
          DAT_00ca04 = uVar7;
          return;
        }
        DAT_00ca08 = 1;
        goto LAB_c1da2a;
      }
    }
  }
  else {
    DAT_00ca14 = 1;
    DAT_00ca08 = 0;
    uVar7 = DAT_00c06a;
    uVar7 = axis16_unsigned(0x7546,uVar7);
    uVar7 = tbl16_interp(0x6c7a,0xc0,uVar7);
    DAT_00ca04 = uVar7;
  }
  return;
}



/* ===== c1da6e gap_c1da6e size=170 ===== */

void gap_c1da6e(undefined2 param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar2 = DAT_00c9d0;
  uVar2 = gap_c28544(0x50dc,0xc0,uVar2);
  uVar3 = gap_c28544(0x6d0c,0xc0,param_1);
  uVar2 = tbl2d_interp(0x70f6,0xc0,uVar2,uVar3);
  Ram00ca00 = uVar2;
  bVar1 = UNK_00c9e7;
  if (bRamc070f2 < bVar1) {
    uVar2 = FUN_c28852(bVar1,bRamc070f2);
  }
  else {
    uVar2 = 0;
  }
  uVar3 = Ram00ca00;
  uVar2 = func_0xc2849c(uVar3,uVar2,8);
  uVar4 = func_0xc27b86(uVar2,0x6400,0xf);
  uVar5 = uRamc070f4;
  if (uVar4 <= uRamc070f4) {
    uVar5 = uVar4;
  }
  uVar5 = func_0xc276a4(uVar5,param_1);
  Ram00c9f4 = uVar5;
  if (0x8000 < uVar5) {
    Ram00c9f4 = 0x8000;
  }
  return;
}



/* ===== c1db18 gap_c1db18 size=372 ===== */

void gap_c1db18(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  uVar7 = DAT_00c9d0;
  uVar6 = gap_c28544(0x5146,0xc0,uVar7);
  uVar7 = Ram00c9f4;
  uVar7 = axis16_unsigned(0x753a,uVar7);
  uVar7 = tbl2d_interp(0x6e50,0xc0,uVar7,uVar6);
  Ram00ca16 = uVar7;
  uVar7 = DAT_00c06a;
  uVar6 = func_0xc27b86(uVar7,uRamc06b96,8);
  Ram00ca12 = uVar6;
  uVar7 = Ram00ca16;
  uVar6 = func_0xc2849c(uVar6,uVar7,8);
  Ram00ca06 = uVar6;
  uVar7 = Ram00c9ee;
  uVar7 = func_0xc2849c(uVar6,uVar7,0xf);
  Ram00ca1c = uVar7;
  cVar3 = UNK_00cc32;
  if ((cVar3 == '\0') && (cVar3 = UNK_00ca18, cVar3 == '\0')) {
    uVar2 = DAT_00ca2a;
    if ((uVar2 < uRamc0714a) && (cVar3 = DAT_00c841, cVar3 == '\0')) {
      uVar7 = DAT_00ca04;
      Ram00ca1c = uVar7;
      UNK_00ca10 = 1;
      goto LAB_c1dbdc;
    }
    cVar3 = UNK_00ca10;
    if (((cVar3 == '\x01') && (uVar2 = DAT_00ca2a, uVar2 < uRamc0714c)) &&
       (cVar3 = DAT_00c841, cVar3 == '\0')) {
      uVar7 = DAT_00ca04;
      Ram00ca1c = uVar7;
      goto LAB_c1dbdc;
    }
  }
  UNK_00ca10 = 0;
LAB_c1dbdc:
  if (cRamc0507b == '\x01') {
    uVar7 = DAT_00ca04;
    Ram00ca1c = uVar7;
  }
  uVar2 = DAT_00c06a;
  uVar4 = Ram00ca1c;
  uVar5 = Ram00ca1c;
  if (uVar2 == uVar5 || uVar2 < uVar4) {
    Ram00c9fc = 0;
  }
  else {
    uVar7 = Ram00ca1c;
    uVar7 = FUN_c28852(uVar2,uVar7);
    Ram00c9fc = uVar7;
  }
  uVar2 = DAT_00c06a;
  uVar4 = DAT_00ca04;
  uVar5 = DAT_00ca04;
  if (uVar2 == uVar5 || uVar2 < uVar4) {
    Ram00ca1e = 0;
  }
  else {
    uVar7 = DAT_00ca04;
    uVar7 = FUN_c28852(uVar2,uVar7);
    Ram00ca1e = uVar7;
  }
  uVar2 = Ram00ca1c;
  bVar1 = uRame0086e < uVar2;
  if (bVar1) {
    uRame0086a = FUN_c28852(uVar2,uRame0086e);
  }
  else {
    uRame0086a = FUN_c28852(uRame0086e,uRame00a1c);
  }
  uRame0086c = bVar1;
  uRame0086e = Ram00ca1c;
  return;
}



/* ===== c1dcf2 gap_c1dcf2 size=18 ===== */

void gap_c1dcf2(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00ca2a;
  gap_c1da6e(uVar1);
  gap_c1db18();
  func_0xc1dc8c();
  return;
}



/* ===== c1deee gap_c1deee size=210 ===== */

void gap_c1deee(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  
  UNK_00ca3c = 0;
  cVar1 = UNK_00c702;
  if (cVar1 == '\0') {
    uVar2 = Ram00c008;
    uVar2 = func_0xc276a4(uVar2,uRamc07090);
    gap_c166a2((short)&UNK_00c008,uVar2);
  }
  else {
    gap_c166a2((short)&UNK_00c008,uRamc07098);
  }
  Ram00ca26 = 0;
  uVar3 = FUN_c13dc8(5);
  Ram00ca38 = uVar3;
  uVar2 = Ram00c008;
  uVar2 = func_0xc28a54(uVar3,uVar2,1,1);
  uVar4 = func_0xc2849c(uRamc0709c,uVar2,0xe);
  if (uVar4 == 0) {
    uVar4 = 0;
  }
  if (uVar4 < 0x8001) {
    DAT_00ca2a = uVar4;
  }
  else {
    DAT_00ca2a = 0x8000;
  }
  if (cRamc0507b == '\x01') {
    uVar2 = Ram00ca0a;
    uVar2 = gap_c28544(0x51aa,0xc0,uVar2);
    uVar2 = tbl8_interp(0x6d48,0xc0,uVar2);
    DAT_00ca2a = uVar2;
  }
  uVar2 = DAT_00ca2a;
  Ram00ca3a = uVar2;
  Ram00ca2c = uVar2;
  Ram00ca2e = uVar2;
  Ram00ca30 = 0;
  Ram00ca20 = uVar2;
  return;
}



/* ===== c1e380 gap_c1e380 size=160 ===== */

void gap_c1e380(void)

{
  ushort uVar1;
  short *psVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  char cVar6;
  
  bVar5 = UNK_00ca41;
  if (bVar5 != 8) {
    if ((*(char *)(uint3)(bVar5 + 0x71b5) == '\0') ||
       (cVar6 = func_0xc24530(0x25,(0x8e4a < bVar5) + -0x40), cVar6 != '\0')) {
      bVar5 = UNK_00ca41;
      psVar2 = (short *)((ushort)bVar5 * 2 + 0x71a2);
      uVar1 = *(ushort *)ZEXT23(psVar2);
      uVar3 = DAT_00c9d0;
      uVar4 = DAT_00c9d0;
      if (uVar1 == uVar4 || uVar1 < uVar3) {
        UNK_00ca40 = 1;
      }
      if ((ushort)(*psVar2 - sRamc071b2) <= uRamc049d0) {
        return;
      }
    }
    else {
      bVar5 = UNK_00ca41;
      psVar2 = (short *)((ushort)bVar5 * 2 + 0x71be);
      uVar1 = *(ushort *)ZEXT23(psVar2);
      uVar3 = Ram00ca3e;
      uVar4 = Ram00ca3e;
      if (uVar1 == uVar4 || uVar1 < uVar3) {
        UNK_00ca40 = 1;
      }
      if ((ushort)(*psVar2 - sRamc071ce) <= uRamc04a3e) {
        return;
      }
    }
  }
  UNK_00ca40 = 0;
  return;
}



/* ===== c1e714 gap_c1e714 size=188 ===== */

void gap_c1e714(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  if (((cRamc07468 == '\0') || (cVar1 = DAT_00c93c, cVar1 != '\x03')) ||
     (cVar1 = DAT_00c786, cVar1 != '\0')) {
    Ram00ca48 = 0;
  }
  else if (DAT_e0081a == '\0') {
    cVar1 = DAT_00c81c;
    if (cVar1 == '\0') {
      uVar3 = DAT_00c9d0;
      uVar2 = gap_c28544(0x5122,0xc0,uVar3);
      uVar3 = Ram00ca1c;
      uVar3 = gap_c28544(0x51da,0xc0,uVar3);
      uVar3 = func_0xc28080(0x7296,0xc0,uVar2,uVar3);
      Ram00ca48 = uVar3;
    }
    else {
      uVar3 = DAT_00c9d0;
      uVar3 = gap_c28544(0x5122,0xc0,uVar3);
      uVar3 = gap_c27f0e(0x7282,0xc0,uVar3);
      Ram00ca48 = uVar3;
    }
  }
  else {
    uVar3 = DAT_00c936;
    uVar3 = gap_c286ca(0x522e,0xc0,uVar3);
    uVar3 = gap_c27f0e(0x726e,0xc0,uVar3);
    Ram00ca48 = uVar3;
  }
  return;
}



/* ===== c1e9d8 gap_c1e9d8 size=26 ===== */

void gap_c1e9d8(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  
  cVar1 = DAT_00c81c;
  if (cVar1 != '\0') {
    sVar2 = Ram00c8e8;
    sVar3 = Ram00ca52;
    Ram00c8e0 = sVar2 + sVar3;
    Ram00c8ea = sVar2 + sVar3;
  }
  return;
}



/* ===== c1ed9e gap_c1ed9e size=408 ===== */

void gap_c1ed9e(void)

{
  ushort uVar1;
  short sVar2;
  char cVar3;
  ushort uVar4;
  undefined2 uVar5;
  ushort uVar6;
  
  cVar3 = UNK_00ca7a;
  if (cVar3 == '\x01') {
    func_0xc14cec(6);
  }
  cVar3 = UNK_00ca7a;
  if (cVar3 == '\x01') {
    func_0xc1f2b0();
    uVar5 = DAT_00c9d0;
    uVar5 = gap_c28544(0x5122,0xc0,uVar5);
    uVar5 = tbl16_interp(0x7616,0xc0,uVar5);
    if (DAT_e0081a == '\x01') {
      uRamc04a7c = uRamc07614;
    }
    else {
      Ram00ca7c = uVar5;
    }
    if (cRame0087e == '\0') {
      uVar4 = Ram00ca7e;
      uVar1 = Ram00ca7c;
      if (uVar4 < uVar1) {
        sVar2 = Ram00c862;
        uVar6 = *(ushort *)(sVar2 * 2 + 0x77d6);
        uVar1 = Ram00ca80;
        uVar4 = Ram00ca80;
        if (uVar6 == uVar4 || uVar6 < uVar1) {
          uVar1 = *(ushort *)(uint3)(sVar2 * 2 + 0x774e);
          sVar2 = Ram00ca7e;
          Ram00ca7e = sVar2 + uVar1;
          uVar4 = Ram00ca7e;
          uVar6 = Ram00ca7e;
          if (uVar1 != uVar6 && uVar4 <= uVar1) {
            Ram00ca7e = 0xffff;
          }
          Ram00ca80 = 0;
        }
        else {
          UNK_00ca82 = 1;
        }
        uVar1 = Ram00ca7e;
        if (uVar1 <= uRamc07612) {
          uRamc04a7e = uRamc07612;
        }
        goto LAB_c1ef08;
      }
      Ram00ca80 = 0;
      UNK_00ca82 = 0;
    }
    else {
      if (cRame0087e == '\x01') {
        sVar2 = Ram00c862;
        uVar6 = *(ushort *)(sVar2 * 2 + 0x77d6);
        uVar1 = Ram00ca80;
        uVar4 = Ram00ca80;
        if (uVar6 == uVar4 || uVar6 < uVar1) {
          uVar1 = *(ushort *)(uint3)(sVar2 * 2 + 0x7792);
          uVar4 = Ram00ca7e;
          uVar6 = Ram00ca7e;
          if (uVar1 == uVar6 || uVar1 < uVar4) {
            sVar2 = Ram00ca7e;
            Ram00ca7e = sVar2 - uVar1;
          }
          else {
            Ram00ca7e = 0;
          }
          Ram00ca80 = 0;
        }
        else {
          UNK_00ca82 = 1;
        }
        uVar1 = Ram00ca7e;
        if (uRamc07612 <= uVar1) goto LAB_c1ef08;
        goto LAB_c1eefc;
      }
      Ram00ca80 = 0;
      UNK_00ca82 = 0;
      uVar4 = Ram00ca7e;
      uVar1 = Ram00ca7c;
      if (uVar4 < uVar1) goto LAB_c1ef08;
    }
    uVar5 = Ram00ca7c;
    Ram00ca7e = uVar5;
  }
  else {
LAB_c1eefc:
    Ram00ca80 = 0;
    UNK_00ca82 = 0;
    Ram00ca7e = 0;
  }
LAB_c1ef08:
  uVar5 = Ram00ca7e;
  uVar5 = func_0xc27b86(uVar5,0x8000,0xf);
  Ram00c98c = uVar5;
  uVar5 = FUN_c28852(0x8000,uVar5);
  Ram00c98c = uVar5;
  func_0xc14c70(6,0x40,uVar5);
  return;
}



/* ===== c1f20a gap_c1f20a size=36 ===== */

void gap_c1f20a(void)

{
  if (cRamc0506c == '\x01') {
    func_0xc159bc((short)&UNK_00ca80,(short)&UNK_00ca82,1);
    func_0xc1ef36();
    gap_c1ed9e();
  }
  return;
}



/* ===== c1f61e gap_c1f61e size=70 ===== */

void gap_c1f61e(void)

{
  char cVar1;
  
  cVar1 = UNK_00c702;
  if (cVar1 == '\0') {
    uRame0088e = Ram00c09a;
    Ram00ca84 = uRame0088e;
  }
  else {
    uRamc0409a = uRamc07828;
    Ram00ca84 = uRamc07828;
    uRame0088e = uRamc07828;
  }
  uRame00888 = Ram00c09a;
  DAT_e00894 = 0;
  return;
}



/* ===== c1f664 gap_c1f664 size=150 ===== */

void gap_c1f664(void)

{
  ushort uVar1;
  ushort uVar2;
  
  if (DAT_e00894 != '\0') {
    uRamc0409a = uRamc0409a + sRamc0782c;
    uVar2 = Ram00c09a;
    if (uRamc0782a <= uVar2) {
      uRamc0409a = uRamc0782a;
    }
    DAT_e00894 = '\0';
  }
  uRame0088e = Ram00c09a;
  uRame00a84 = uRame0088e;
  uVar2 = uRame00888 + uRamc07948;
  if (uVar2 < uRame00888) {
    uVar2 = 0xffff;
  }
  if ((uRamc07948 < uRame00888) && (uRamc0409a < uRame00888 - uRamc07948)) {
    Ram00c09a = uRame00888 - uRamc07948;
  }
  uVar1 = Ram00c09a;
  if (uVar2 < uVar1) {
    Ram00c09a = uVar2;
  }
  return;
}



/* ===== c1fb28 gap_c1fb28 size=10 ===== */

void gap_c1fb28(void)

{
  uRame0089d = 0;
  return;
}



/* ===== c1fd48 gap_c1fd48 size=36 ===== */

void gap_c1fd48(void)

{
  DAT_e0089e = 2;
  uRame00898 = uRamc0783a;
  uRame0089a = 0;
  return;
}



/* ===== c1fd90 gap_c1fd90 size=6 ===== */

void gap_c1fd90(void)

{
  DAT_00089e = 2;
  return;
}



/* ===== c1fd9c calc_load size=322 ===== */

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



/* ===== c1fede gap_c1fede size=76 ===== */

void gap_c1fede(void)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = DAT_00c93c;
  if (cVar1 != '\x03') {
    UNK_00ca86 = 3;
    return;
  }
  uVar2 = DAT_00ca2a;
  if (uVar2 <= uRamc079d6) {
    UNK_00ca86 = 0;
    return;
  }
  uVar2 = DAT_00ca2a;
  if ((uRamc079d6 < uVar2) && (uVar2 <= uRamc079d8)) {
    UNK_00ca86 = 1;
    return;
  }
  UNK_00ca86 = 2;
  return;
}



/* ===== c1ff2a gap_c1ff2a size=180 ===== */

void gap_c1ff2a(void)

{
  char cVar1;
  ushort uVar2;
  
  func_0xc159bc((short)&UNK_00ca8a,(short)&UNK_00ca88,1);
  cVar1 = DAT_00c93c;
  if (cVar1 == '\x01') {
    uVar2 = DAT_00fd18;
    if ((uVar2 & 8) != 0) {
      cVar1 = UNK_00c9e7;
      if ((cVar1 == cRamc06cfc) || (cVar1 == cRamc06cfd)) {
        UNK_00ca88 = 1;
      }
      else {
        UNK_00ca88 = 0;
      }
      uVar2 = Ram00ca8a;
      if (99 < uVar2) {
        uVar2 = Ram00ca8a;
        if (uVar2 < 0xa4) {
          cRame00855 = cRamc06cfd;
          return;
        }
        cRame00855 = cRamc06ce2;
        return;
      }
      cRame00855 = cRamc06cfc;
      return;
    }
    cVar1 = UNK_00c9e7;
    if (cVar1 != cRamc06ce2) {
      cRame00855 = cRamc06ce2;
    }
    UNK_00ca88 = 0;
    Ram00ca8a = 0;
  }
  return;
}



/* ===== c1fff6 gap_c1fff6 size=10 ===== */

undefined1 gap_c1fff6(ushort param_1)

{
  return *(undefined1 *)(uint3)((short)&UNK_00cb47 + (param_1 & 0xff));
}



/* ===== c2006e gap_c2006e size=40 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c2006e(void)

{
  undefined2 uVar1;
  
  calc_limit3();
  uVar1 = DAT_00c936;
  uVar1 = axis16_signed(0x7552,uVar1);
  _DAT_e008aa = tbl8_interp(0x7860,0xc0,uVar1);
  return;
}



/* ===== c20096 gap_c20096 size=6 ===== */

void gap_c20096(void)

{
  calc_limit3();
  return;
}



/* ===== c200aa calc_limit1 size=260 ===== */

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



/* ===== c201ae calc_limit2 size=320 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void calc_limit2(void)

{
  ushort uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  
  if (DAT_e0085b != '\0') {
    _DAT_e008b0 = 0;
    _DAT_e008aa = 0;
    return;
  }
  cVar2 = DAT_00c93c;
  if (cVar2 == '\x03') {
    cVar2 = DAT_00c93c;
    if (((cVar2 == '\x03') && (DAT_00c885 = 1, 0x80 < _DAT_e008aa)) &&
       (uVar1 = DAT_00c86c, DAT_c07834 <= uVar1)) {
      DAT_00c885 = 0;
      DAT_00c86c = 0;
      _DAT_e008aa = (ushort)((uint)_DAT_e008aa * (uint)DAT_c07830 >> 0x10);
      if (_DAT_e008aa < 0x81) {
        _DAT_e008aa = 0;
      }
    }
  }
  else {
    DAT_00c885 = 0;
    DAT_00c86c = 0;
    uVar4 = DAT_00c97c;
    _DAT_e008aa = tbl8_interp(0x7860,0xc0,uVar4);
  }
  cVar2 = DAT_00c93c;
  if (cVar2 != '\x03') {
    DAT_00c86a = 0;
    _DAT_e008b0 = 0;
    return;
  }
  uVar3 = DAT_00c9d0;
  uVar1 = DAT_00c86a;
  if ((uVar3 < DAT_c0781e) || (DAT_00c884 = 1, uVar1 < DAT_c07832)) {
    DAT_e008a2 = '\0';
  }
  else {
    DAT_00c884 = 0;
    DAT_e008a2 = '\x01';
  }
  uVar4 = DAT_c0783c;
  if (DAT_e008a2 != '\0') {
    uVar4 = DAT_00c958;
  }
  uVar4 = axis16_unsigned(0x7510,uVar4);
  _DAT_e008b0 = tbl8_interp(0x784c,0xc0,uVar4);
  return;
}



/* ===== c202ee calc_limit3 size=170 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void calc_limit3(void)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar1 = DAT_00c936;
  uVar1 = axis16_signed(0x7552,uVar1);
  _DAT_e008a6 = tbl16_interp(0x7912,0xc0,uVar1);
  _DAT_e008a4 = tbl8_interp(0x78e2,0xc0,uVar1);
  uVar2 = tbl8_interp(0x7874,0xc0,uVar1);
  uVar1 = DAT_00c06a;
  uVar1 = axis16_unsigned(0x750a,uVar1);
  uVar3 = tbl8_interp(0x78d8,0xc0,uVar1);
  _DAT_e008ac = (ushort)((uint)uVar2 * (uint)uVar3) >> 0xd |
                (short)((uint)uVar2 * (uint)uVar3 >> 0x10) << 3;
  if (0x8000 < _DAT_e008ac) {
    _DAT_e008ac = 0x8000;
  }
  _DAT_e008a0 = _DAT_e008ac;
  return;
}



/* ===== c20398 gap_c20398 size=104 ===== */

void gap_c20398(void)

{
  UNK_00ca86 = 3;
  uRame008b4 = 4;
  if (cRame00702 != '\0') {
    Ram00c0b4 = 0;
    Ram00c0a6 = 0;
    Ram00c0aa = 0;
    Ram00c0a2 = 0;
    Ram00c0ac = 0;
    Ram00c0b2 = 0;
    DAT_00c09c = 0;
    DAT_00c0a8 = 0;
    DAT_00c0b0._1_1_ = 0;
    UNK_00c09f = 0;
    UNK_00c0a4 = 0;
    DAT_00c0b0._0_1_ = 0;
    UNK_00c0be = 0;
    DAT_00c09e = 0;
    DAT_00c0a0._0_1_ = 0;
    DAT_00c0b6 = 0;
    Ram00c0ba = 0;
    Ram00c0bc = 0;
    Ram00c0ae = 0;
    Ram00c0b8 = 0;
  }
  return;
}



/* ===== c20400 gap_c20400 size=26 ===== */

void gap_c20400(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  if (cRame00830 == '\0') {
    sVar3 = DAT_00c936;
    sVar1 = Ram00c0ba;
    sVar2 = Ram00c0ba;
    if (sVar3 != sVar2 && sVar3 - sVar2 < 0 == SBORROW2(sVar3,sVar1)) {
      Ram00c0ba = sVar3;
    }
  }
  return;
}



/* ===== c2042a gap_c2042a size=22 ===== */

void gap_c2042a(void)

{
  short sVar1;
  short sVar2;
  char cVar3;
  short sVar4;
  
  cVar3 = UNK_00c94c;
  if (cVar3 == '\0') {
    sVar4 = Ram00c94e;
    sVar1 = Ram00c0ae;
    sVar2 = Ram00c0ae;
    if (sVar4 != sVar2 && sVar4 - sVar2 < 0 == SBORROW2(sVar4,sVar1)) {
      Ram00c0ae = sVar4;
    }
  }
  return;
}



/* ===== c20450 gap_c20450 size=28 ===== */

void gap_c20450(void)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  
  cVar2 = DAT_00c0b6;
  DAT_00c0b6 = cVar2 + '\x01';
  bVar3 = DAT_00c0b6;
  if (0xe0 < bVar3) {
    sVar1 = Ram00c00c;
    Ram00c00c = sVar1 + 1;
    sVar1 = DAT_00c0a8;
    DAT_00c0a8 = sVar1 + 1;
    DAT_00c0b6 = 0;
  }
  return;
}



/* ===== c2046c gap_c2046c size=364 ===== */

void gap_c2046c(void)

{
  short sVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  
  gap_c1fede();
  cVar2 = UNK_00ca86;
  if (cVar2 == '\0') {
    cVar2 = DAT_00c0b0._1_1_;
    DAT_00c0b0._1_1_ = cVar2 + '\x01';
    bVar3 = DAT_00c0b0._1_1_;
    if (0xe0 < bVar3) {
      sVar1 = Ram00c0b4;
      Ram00c0b4 = sVar1 + 1;
      DAT_00c0b0._1_1_ = 0;
    }
  }
  else {
    cVar2 = UNK_00ca86;
    if (cVar2 == '\x01') {
      cVar2 = UNK_00c09f;
      UNK_00c09f = cVar2 + '\x01';
      bVar3 = UNK_00c09f;
      if (0xe0 < bVar3) {
        sVar1 = Ram00c0a6;
        Ram00c0a6 = sVar1 + 1;
        UNK_00c09f = 0;
      }
    }
    else {
      cVar2 = UNK_00ca86;
      if (cVar2 == '\x02') {
        cVar2 = UNK_00c0a4;
        UNK_00c0a4 = cVar2 + '\x01';
        bVar3 = UNK_00c0a4;
        if (0xe0 < bVar3) {
          sVar1 = Ram00c0aa;
          Ram00c0aa = sVar1 + 1;
          UNK_00c0a4 = 0;
        }
      }
    }
  }
  cVar2 = DAT_00c93c;
  if (cVar2 == '\x03') {
    uVar4 = DAT_00c9d0;
    if (uRamc079d0 < uVar4) {
      uVar4 = DAT_00c9d0;
      if ((uRamc079d0 < uVar4) && (uVar4 <= uRamc079d2)) {
        cRame008b4 = '\x01';
      }
      else {
        uVar4 = DAT_00c9d0;
        if ((uRamc079d2 < uVar4) && (uVar4 <= uRamc079d4)) {
          cRame008b4 = '\x02';
        }
        else {
          cRame008b4 = '\x03';
        }
      }
    }
    else {
      cRame008b4 = '\0';
    }
  }
  else {
    cRame008b4 = '\x04';
  }
  if (cRame008b4 == '\0') {
    cVar2 = DAT_00c0b0._0_1_;
    DAT_00c0b0._0_1_ = cVar2 + '\x01';
    bVar3 = DAT_00c0b0._0_1_;
    if (0xe0 < bVar3) {
      sVar1 = Ram00c0a2;
      Ram00c0a2 = sVar1 + 1;
      DAT_00c0b0._0_1_ = 0;
      return;
    }
  }
  else if (cRame008b4 == '\x01') {
    cVar2 = UNK_00c0be;
    UNK_00c0be = cVar2 + '\x01';
    bVar3 = UNK_00c0be;
    if (0xe0 < bVar3) {
      sVar1 = Ram00c0ac;
      Ram00c0ac = sVar1 + 1;
      UNK_00c0be = 0;
      return;
    }
  }
  else if (cRame008b4 == '\x02') {
    cVar2 = DAT_00c09e;
    DAT_00c09e = cVar2 + '\x01';
    bVar3 = DAT_00c09e;
    if (0xe0 < bVar3) {
      sVar1 = Ram00c0b2;
      Ram00c0b2 = sVar1 + 1;
      DAT_00c09e = 0;
      return;
    }
  }
  else if (cRame008b4 == '\x03') {
    cVar2 = DAT_00c0a0._0_1_;
    DAT_00c0a0._0_1_ = cVar2 + '\x01';
    bVar3 = DAT_00c0a0._0_1_;
    if (0xe0 < bVar3) {
      sVar1 = DAT_00c09c;
      DAT_00c09c = sVar1 + 1;
      DAT_00c0a0._0_1_ = 0;
    }
  }
  return;
}



/* ===== c205d8 gap_c205d8 size=40 ===== */

void gap_c205d8(void)

{
  uint uVar1;
  ushort uVar2;
  undefined1 uVar3;
  
  uVar2 = Ram00c00c;
  uVar3 = DAT_00c0b6;
  uVar1 = (uint)uVar2 * 0xe10 >> 4;
  gap_c27738((short)uVar1,(short)(uVar1 >> 0x10),uVar3,0);
  return;
}



/* ===== c20600 gap_c20600 size=10 ===== */

undefined2 gap_c20600(void)

{
  undefined2 uVar1;
  
  uVar1 = gap_c205d8();
  return uVar1;
}



/* ===== c20e96 gap_c20e96 size=198 ===== */

void gap_c20e96(void)

{
  ushort uVar1;
  undefined2 *puVar2;
  char cVar3;
  short sVar4;
  char cVar5;
  
  gap_c18ed0();
  UNK_00ca94 = 0;
  UNK_00ca9c = 0;
  while( true ) {
    cVar3 = UNK_00ca9c;
    cVar5 = UNK_00ca9c;
    if ((char)('#' - cVar5) < '\0' != SBORROW1('#',cVar3)) break;
    cVar3 = UNK_00c702;
    if (cVar3 == '\x01') {
      cVar3 = UNK_00ca9c;
      *(undefined2 *)(uint3)(ushort)((short)&DAT_00c016 + cVar3 * 2) = 0x8000;
    }
    else {
      sVar4 = DAT_00c936;
      if (sVar4 < sRamc05b8a) {
        cVar3 = UNK_00ca9c;
        uVar1 = (short)&DAT_00c016 + cVar3 * 2;
        puVar2 = (undefined2 *)(cVar3 * 2 + 0x5bd4);
        if (*(ushort *)(uint3)uVar1 < *(ushort *)ZEXT23(puVar2)) {
          *(undefined2 *)(uint3)uVar1 = *puVar2;
        }
      }
      else {
        cVar3 = UNK_00ca9c;
        uVar1 = (short)&DAT_00c016 + cVar3 * 2;
        puVar2 = (undefined2 *)(cVar3 * 2 + 0x5b8c);
        if (*(ushort *)(uint3)uVar1 < *(ushort *)ZEXT23(puVar2)) {
          *(undefined2 *)(uint3)uVar1 = *puVar2;
        }
      }
    }
    cVar3 = UNK_00ca9c;
    UNK_00ca9c = cVar3 + '\x01';
  }
  UNK_00ca98 = 0;
  UNK_00c7ff = 0;
  UNK_00c800 = 0;
  Ram00c7d0 = 0;
  Ram00c7d2 = 0;
  UNK_00ca8c = 0;
  UNK_00ca9b = 0;
  UNK_00ca9a = 0;
  Ram00c862 = 0x20;
  return;
}



/* ===== c21158 gap_c21158 size=194 ===== */

void gap_c21158(void)

{
  ushort uVar1;
  undefined2 *puVar2;
  char cVar3;
  short sVar4;
  char cVar5;
  
  gap_c18ed0();
  UNK_00ca95 = 0;
  UNK_00ca9e = 0;
  while( true ) {
    cVar3 = UNK_00ca9e;
    cVar5 = UNK_00ca9e;
    if ((char)('#' - cVar5) < '\0' != SBORROW1('#',cVar3)) break;
    cVar3 = UNK_00c702;
    if (cVar3 == '\x01') {
      cVar3 = UNK_00ca9e;
      *(undefined2 *)(uint3)(ushort)((short)&UNK_00c0c0 + cVar3 * 2) = 0x8000;
    }
    else {
      sVar4 = DAT_00c936;
      if (sVar4 < sRamc05b8a) {
        cVar3 = UNK_00ca9e;
        uVar1 = (short)&UNK_00c0c0 + cVar3 * 2;
        puVar2 = (undefined2 *)(cVar3 * 2 + 0x5bd4);
        if (*(ushort *)(uint3)uVar1 < *(ushort *)ZEXT23(puVar2)) {
          *(undefined2 *)(uint3)uVar1 = *puVar2;
        }
      }
      else {
        cVar3 = UNK_00ca9e;
        uVar1 = (short)&UNK_00c0c0 + cVar3 * 2;
        puVar2 = (undefined2 *)(cVar3 * 2 + 0x5b8c);
        if (*(ushort *)(uint3)uVar1 < *(ushort *)ZEXT23(puVar2)) {
          *(undefined2 *)(uint3)uVar1 = *puVar2;
        }
      }
    }
    cVar3 = UNK_00ca9e;
    UNK_00ca9e = cVar3 + '\x01';
  }
  UNK_00ca99 = 0;
  UNK_00c801 = 0;
  UNK_00c802 = 0;
  Ram00c7d4 = 0;
  Ram00c7d6 = 0;
  UNK_00ca8d = 0;
  UNK_00ca9b = 0;
  Ram00c862 = 0x20;
  return;
}



/* ===== c21f42 gap_c21f42 size=372 ===== */

undefined2 gap_c21f42(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 uVar3;
  
  cVar2 = DAT_00c93c;
  if ((cVar2 == '\x02') || (cVar2 == '\x03')) {
    cVar2 = DAT_00cad6;
    if (((cVar2 == '\0') || (cVar2 = DAT_00c81c, cVar2 != '\0')) ||
       (cVar2 = DAT_00c784, cVar2 != '\0')) {
      cVar2 = FUN_c243a8(0xb);
      if ((((cVar2 == '\0') && (cVar2 = FUN_c243a8(0x12), cVar2 == '\0')) &&
          ((cRame00702 == '\0' &&
           ((cVar2 = UNK_00cc32, cVar2 == '\0' && (cVar2 = func_0xc24530(7), cVar2 == '\0')))))) &&
         ((cVar2 = func_0xc24530(8), cVar2 == '\0' &&
          (((((cVar2 = func_0xc24530(0x19), cVar2 == '\0' &&
              (cVar2 = func_0xc24530(0x1a), cVar2 == '\0')) &&
             (cVar2 = FUN_c243a8(0xe), cVar2 == '\0')) &&
            ((cVar2 = FUN_c243a8(0xf), cVar2 == '\0' && (cVar2 = UNK_00cc63, cVar2 == '\0')))) &&
           (cVar2 = UNK_00cc5d, cVar2 == '\0')))))) {
        cVar2 = DAT_00c784;
        if ((cVar2 == '\0') && (cVar2 = DAT_00c81c, cVar2 == '\0')) {
          uVar3 = 1;
        }
        else {
          uVar3 = 4;
        }
      }
      else {
        uVar3 = 8;
      }
    }
    else {
      uVar3 = 2;
    }
  }
  else {
    uVar3 = 0;
  }
  cVar2 = DAT_00c93c;
  if ((cVar2 == '\x02') || (cVar2 == '\x03')) {
    cVar2 = DAT_00cad7;
    if (((cVar2 == '\0') || (cVar2 = DAT_00c81c, cVar2 != '\0')) ||
       (cVar2 = DAT_00c784, cVar2 != '\0')) {
      cVar2 = FUN_c243a8(0xc);
      if ((((((cVar2 == '\0') && (cVar2 = FUN_c243a8(0x13), cVar2 == '\0')) &&
            ((cRame00702 == '\0' &&
             ((cVar2 = UNK_00cc32, cVar2 == '\0' && (cVar2 = func_0xc24530(7), cVar2 == '\0'))))))
           && (cVar2 = func_0xc24530(8), cVar2 == '\0')) &&
          ((((cVar2 = func_0xc24530(0x19), cVar2 == '\0' &&
             (cVar2 = func_0xc24530(0x1a), cVar2 == '\0')) &&
            (cVar2 = FUN_c243a8(0x21), cVar2 == '\0')) &&
           ((cVar2 = FUN_c243a8(0x22), cVar2 == '\0' && (cVar2 = UNK_00cc6e, cVar2 == '\0')))))) &&
         (cVar2 = UNK_00cc69, cVar2 == '\0')) {
        cVar2 = DAT_00c784;
        if ((cVar2 == '\0') && (cVar2 = DAT_00c81c, cVar2 == '\0')) {
          uVar1 = 1;
        }
        else {
          uVar1 = 4;
        }
      }
      else {
        uVar1 = 8;
      }
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 0;
  }
  return CONCAT11(uVar3,uVar1);
}



/* ===== c22312 gap_c22312 size=6 ===== */

void gap_c22312(void)

{
  DAT_00cad6 = 0;
  return;
}



/* ===== c225a8 gap_c225a8 size=6 ===== */

void gap_c225a8(void)

{
  DAT_00cad7 = 0;
  return;
}



/* ===== c225e4 gap_c225e4 size=6 ===== */

void gap_c225e4(void)

{
  func_0xc225f0();
  return;
}



/* ===== c225ea gap_c225ea size=6 ===== */

void gap_c225ea(void)

{
  func_0xc225f0();
  return;
}



/* ===== c22628 gap_c22628 size=26 ===== */

void gap_c22628(void)

{
  uRame008c2 = 0;
  uRame008c6 = 0;
  uRame008c4 = 0;
  return;
}



/* ===== c2292c gap_c2292c size=226 ===== */

void gap_c2292c(ushort param_1)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  char cVar4;
  short extraout_r2;
  short sVar5;
  ushort uVar6;
  ushort uVar7;
  undefined4 uVar8;
  
  sVar1 = (param_1 & 0xff) * 2;
  uVar8 = gap_c28b88(*(ushort *)(uint3)(ushort)((short)&UNK_00c832 + sVar1) >> 1);
  uVar7 = (ushort)((uint)uVar8 >> 0x10);
  uVar6 = (ushort)uVar8;
  if (uVar7 == uVar6 < 0x7fff && uVar6 == 0x7fff || (short)uVar7 < (short)(ushort)(uVar6 < 0x7fff))
  {
    if ((short)((uVar7 + 1) - (ushort)(uVar6 < 0x8000)) < 0 !=
        (SBORROW2(uVar7,-1) != SBORROW2(uVar7 + 1,(ushort)(uVar6 < 0x8000)))) {
      uVar6 = 0x8000;
    }
  }
  else {
    uVar6 = 0x7fff;
  }
  uVar7 = *(ushort *)(uint3)(ushort)((short)&UNK_00cb06 + sVar1);
  uVar2 = (ushort)(CONCAT22(uVar7 >> 4,uVar7 << 0xc) / (uint)uRamc05c48);
  uVar7 = uVar6 * 2 + uVar2;
  uVar6 = ((short)uVar6 >> 0xf) * 2 + (ushort)CARRY2(uVar6,uVar6) + extraout_r2 +
          (ushort)CARRY2(uVar6 * 2,uVar2);
  if (uVar6 == (uVar7 != 0xffff) && uVar7 == 0xffff ||
      (short)uVar6 < (short)(ushort)(uVar7 != 0xffff)) {
    if ((short)uVar6 < 0) {
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0xffff;
  }
  sVar5 = (short)((uint)uVar7 * 64000 >> 0x10);
  cVar4 = DAT_00c830;
  if (cVar4 == '\0') {
    sVar3 = Ram00c788;
    sVar5 = sVar5 + sVar3;
  }
  *(short *)(uint3)(ushort)((short)&UNK_00c764 + sVar1) = sVar5;
  return;
}



/* ===== c22cfc gap_c22cfc size=166 ===== */

void gap_c22cfc(void)

{
  ushort uVar1;
  undefined2 uVar2;
  
  if (cRamc0506c != '\x02') {
    return;
  }
  func_0xc14cec(6);
  uVar1 = DAT_00c9d0;
  if (uRamc07cf2 < uVar1) {
    uVar1 = DAT_00c9d0;
    if (uRamc07cf0 < uVar1) {
      cRame008c8 = '\x01';
    }
  }
  else {
    cRame008c8 = '\0';
  }
  if (cRame008c8 == '\0') {
    if (cRamc07cf4 == '\0') {
LAB_c22d60:
      uVar2 = func_0xc27b86(0,0x8000,0xf);
      Ram00c98c = uVar2;
      goto LAB_c22d84;
    }
  }
  else if (cRamc07cf4 == '\x01') goto LAB_c22d60;
  uVar2 = func_0xc27b86(0xffff,0x8000,0xf);
  Ram00c98c = uVar2;
LAB_c22d84:
  uVar2 = Ram00c98c;
  uVar2 = FUN_c28852(0x8000,uVar2);
  Ram00c98c = uVar2;
  func_0xc14c70(6,0x40,uVar2);
  return;
}



/* ===== c22f3a gap_c22f3a size=200 ===== */

void gap_c22f3a(void)

{
  short sVar1;
  char cVar2;
  undefined2 uVar3;
  
  if (cRamc0506c != '\x03') {
    return;
  }
  cVar2 = DAT_00c93c;
  if ((cVar2 == '\x03') && (cVar2 = DAT_00c954, cVar2 == '\x01')) {
    cVar2 = func_0xc24530(1);
    if ((cVar2 != '\0') ||
       (((cVar2 = func_0xc24530(2), cVar2 != '\0' || (cRame008cf == '\x01')) ||
        (sVar1 = DAT_00c936, sRamc07d08 < sVar1)))) {
      cRame008ce = '\x01';
      goto LAB_c22fb0;
    }
    sVar1 = DAT_00c936;
    if (sRamc07d0a < sVar1) goto LAB_c22fb0;
  }
  cRame008ce = '\0';
LAB_c22fb0:
  func_0xc14cec(6);
  if (cRame008ce == '\0') {
    uVar3 = func_0xc27b86(0,0x8000,0xf);
    Ram00c98c = uVar3;
  }
  else {
    uVar3 = func_0xc27b86(0xffff,0x8000,0xf);
    Ram00c98c = uVar3;
  }
  uVar3 = Ram00c98c;
  uVar3 = FUN_c28852(0x8000,uVar3);
  Ram00c98c = uVar3;
  func_0xc14c70(6,0x40,uVar3);
  return;
}



/* ===== c2316a gap_c2316a size=112 ===== */

void gap_c2316a(short param_1)

{
  if (param_1 == 0) {
    Ram00cb22 = 0;
    Ram00cb20 = 0x3fff;
    return;
  }
  if (param_1 == 0x4000) {
    Ram00cb22 = 0x4000;
    Ram00cb20 = 0x7fff;
    return;
  }
  if (param_1 == -0x8000) {
    Ram00cb22 = 0x8000;
    Ram00cb20 = 0xbfff;
    return;
  }
  if (param_1 == -0x4000) {
    Ram00cb22 = 0xc000;
    Ram00cb20 = 0xfeff;
    return;
  }
  if (param_1 == -0x100) {
    Ram00cb22 = 0;
    Ram00cb20 = 0xffff;
    return;
  }
  Ram00cb22 = param_1;
  Ram00cb20 = param_1;
  return;
}



/* ===== c232ea gap_c232ea size=160 ===== */

byte gap_c232ea(undefined2 param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  
  cVar1 = func_0xc24286();
  bVar2 = func_0xc24530(param_1);
  bVar3 = func_0xc2446c(param_1);
  bVar4 = gap_c244ce(param_1);
  bVar5 = func_0xc2465c(param_1);
  bVar2 = cVar1 != '\0' | (bVar2 & 1) << 1 | (bVar3 & 1) << 2 | (bVar4 & 1) << 3 | (bVar5 & 1) << 4;
  cVar1 = func_0xc2440a(param_1);
  if (cVar1 == '\0') {
    bVar2 = bVar2 | 0x20;
  }
  bVar3 = FUN_c243a8(param_1);
  cVar1 = func_0xc245fa(param_1);
  return bVar2 | (bVar3 & 1) << 6 | cVar1 << 7;
}



/* ===== c2338a gap_c2338a size=84 ===== */

char gap_c2338a(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  ushort uVar4;
  char cVar5;
  ushort uVar6;
  
  uVar6 = 0;
  cVar5 = '\0';
  do {
    uVar4 = func_0xc2425c(uVar6);
    cVar3 = func_0xc24286(uVar6);
    if ((cVar3 != '\0') && (uVar1 = Ram00cb22, uVar1 <= uVar4)) {
      uVar1 = Ram00cb20;
      uVar2 = Ram00cb20;
      if ((uVar4 == uVar2 || uVar4 < uVar1) &&
         ((param_1 == '\x01' || ((param_1 == '\0' && (cVar3 = func_0xc24530(uVar6), cVar3 != '\0')))
          ))) {
        cVar5 = cVar5 + '\x01';
      }
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x27);
  return cVar5;
}



/* ===== c233de gap_c233de size=104 ===== */

undefined2 gap_c233de(undefined2 param_1,char param_2)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  undefined1 uVar4;
  ushort uVar5;
  
  Ram00cb1a = 0;
  UNK_00cb1d = 0;
  UNK_00cb1e = 0;
  uVar5 = func_0xc2425c(param_1);
  cVar3 = func_0xc24286(param_1);
  if ((cVar3 != '\0') && (uVar1 = Ram00cb22, uVar1 <= uVar5)) {
    uVar1 = Ram00cb20;
    uVar2 = Ram00cb20;
    if ((uVar5 == uVar2 || uVar5 < uVar1) &&
       ((param_2 == '\x01' || ((param_2 == '\0' && (cVar3 = func_0xc24530(param_1), cVar3 != '\0')))
        ))) {
      uVar4 = func_0xc231e0(param_1);
      Ram00cb1a = uVar5;
      UNK_00cb1d = uVar4;
      UNK_00cb1e = 1;
    }
  }
  return (short)&UNK_00cb1a;
}



/* ===== c23446 gap_c23446 size=120 ===== */

undefined1 * gap_c23446(short param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  while ((*(short *)(sRam007340 + (ushort)bVar1 * 2) != 0xb &&
         (*(short *)(sRam007340 + (ushort)bVar1 * 2) != param_1))) {
    bVar1 = bVar1 + 1;
  }
  return &stack0x0000;
}



/* ===== c234e2 gap_c234e2 size=24 ===== */

void gap_c234e2(void)

{
  UNK_00cb24 = 1;
  func_0xc24e96();
  func_0xc1c258();
  func_0xc1c25e();
  func_0xc1c264();
  return;
}



/* ===== c234fa gap_c234fa size=90 ===== */

short gap_c234fa(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  
  uVar2 = 0;
  sVar3 = 0;
  do {
    cVar1 = func_0xc24286(uVar2);
    sVar4 = sVar3;
    if ((((cVar1 == '\b') || (cVar1 = func_0xc24286(uVar2), cVar1 == '\x04')) ||
        (cVar1 = func_0xc24286(uVar2), cVar1 == '\x02')) &&
       ((cVar1 = func_0xc2465c(uVar2), cVar1 != '\0' && (sVar4 = sVar3 + 1, sVar3 + 1 == 0)))) {
      sVar4 = sVar3;
    }
    uVar2 = uVar2 + 1;
    sVar3 = sVar4;
  } while (uVar2 < 0x27);
  return sVar4;
}



/* ===== c23554 gap_c23554 size=104 ===== */

undefined1 gap_c23554(char param_1,ushort param_2)

{
  if (param_1 == '\0') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76c8);
  }
  if (param_1 == '\x01') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76cc);
  }
  if (param_1 == '\x02') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76d0);
  }
  if (param_1 == '\x03') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76d4);
  }
  if (param_1 == '\x04') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76d8);
  }
  if (param_1 == '\x05') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76dc);
  }
  if (param_1 == '\x06') {
    return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76e4);
  }
  if (param_1 != '\a') {
    return 0;
  }
  return *(undefined1 *)(uint3)((param_2 & 0xff) + 0x76e0);
}



/* ===== c235bc gap_c235bc size=14 ===== */

undefined1 gap_c235bc(void)

{
  char cVar1;
  
  cVar1 = UNK_00c1b6;
  if (cVar1 == '\0') {
    return 0;
  }
  return 1;
}



/* ===== c235ca gap_c235ca size=116 ===== */

void gap_c235ca(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = UNK_00cb2d;
  if (cVar1 == '\x10') {
    uVar2 = gap_c23554(0,0);
    UNK_00cb39 = uVar2;
    uVar2 = gap_c23554(0,1);
    UNK_00cb38 = uVar2;
    uVar2 = gap_c23554(0,2);
    UNK_00cb37 = uVar2;
    uVar2 = gap_c23554(0,3);
    UNK_00cb36 = uVar2;
  }
  else if (cVar1 == ' ') {
    uVar2 = gap_c23554(1,0);
    UNK_00cb39 = uVar2;
    uVar2 = gap_c23554(1,1);
    UNK_00cb38 = uVar2;
    uVar2 = gap_c23554(1,2);
    UNK_00cb37 = uVar2;
    uVar2 = gap_c23554(1,3);
    UNK_00cb36 = uVar2;
    return;
  }
  return;
}



/* ===== c2363e gap_c2363e size=62 ===== */

void gap_c2363e(void)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar3;
  
  bVar2 = gap_c234fa();
  cVar3 = gap_c235bc(bVar2);
  UNK_00cb39 = bVar2 & 0x7f | cVar3 << 7;
  uRamc04b38 = uRamc07d17;
  uRamc04b37 = uRamc07d16;
  uVar1 = UNK_00cbe6;
  UNK_00cb36 = uVar1;
  return;
}



/* ===== c2367c gap_c2367c size=14 ===== */

void gap_c2367c(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  
  uVar1 = UNK_00cb25;
  uVar2 = func_0xc234be(uVar1);
  Ram00cb38 = uVar2;
  return;
}



/* ===== c2368a gap_c2368a size=60 ===== */

void gap_c2368a(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(0,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = gap_c21f42();
  }
  Ram00cb38 = uStack_4;
  return;
}



/* ===== c236c6 gap_c236c6 size=90 ===== */

void gap_c236c6(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(1,uVar1);
    uStack_4 = *(ushort *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = DAT_00ca2a;
  }
  if (uStack_4 < 0x7fff) {
    axis16_unsigned(0x7710,uStack_4);
    uStack_4._1_1_ = extraout_RH4;
  }
  else {
    uStack_4._1_1_ = 0xff;
  }
  UNK_00cb39 = uStack_4._1_1_;
  return;
}



/* ===== c23720 gap_c23720 size=74 ===== */

void gap_c23720(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(2,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = DAT_00c936;
  }
  axis16_signed(0x76fe,uStack_4);
  UNK_00cb39 = extraout_RH4;
  return;
}



/* ===== c2376a gap_c2376a size=38 ===== */

void gap_c2376a(void)

{
  undefined2 uVar1;
  undefined1 extraout_RH4;
  
  uVar1 = gap_c28450(uRamc07c3c,uRamc04acc);
  axis16_signed(0x7716,uVar1);
  UNK_00cb39 = extraout_RH4;
  return;
}



/* ===== c23790 gap_c23790 size=84 ===== */

void gap_c23790(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(3,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = Ram00ca8e;
  }
  uVar4 = gap_c289c2(uStack_4,1,0xf);
  axis16_signed(0x7716,uVar4);
  UNK_00cb39 = extraout_RH4;
  return;
}



/* ===== c237e4 gap_c237e4 size=38 ===== */

void gap_c237e4(void)

{
  undefined2 uVar1;
  undefined1 extraout_RH4;
  
  uVar1 = gap_c28450(uRamc07c3c,uRamc04ace);
  axis16_signed(0x7716,uVar1);
  UNK_00cb39 = extraout_RH4;
  return;
}



/* ===== c2380a gap_c2380a size=84 ===== */

void gap_c2380a(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(4,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = Ram00ca90;
  }
  uVar4 = gap_c289c2(uStack_4,1,0xf);
  axis16_signed(0x7716,uVar4);
  UNK_00cb39 = extraout_RH4;
  return;
}



/* ===== c2385e gap_c2385e size=62 ===== */

void gap_c2385e(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(5,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = DAT_00ca04;
  }
  UNK_00cb39 = (char)((ushort)uStack_4 >> 8);
  return;
}



/* ===== c2389c gap_c2389c size=56 ===== */

void gap_c2389c(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(6,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = DAT_00c9d0;
  }
  Ram00cb38 = uStack_4;
  return;
}



/* ===== c238d4 gap_c238d4 size=90 ===== */

void gap_c238d4(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(7,uVar1);
    uStack_4 = *(ushort *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = Ram00ca3e;
  }
  if (uStack_4 < 0x7f80) {
    axis16_unsigned(0x7704,uStack_4);
    uStack_4._1_1_ = extraout_RH4;
  }
  else {
    uStack_4._1_1_ = 0xff;
  }
  UNK_00cb39 = uStack_4._1_1_;
  return;
}



/* ===== c2392e gap_c2392e size=42 ===== */

void gap_c2392e(void)

{
  char cVar1;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar1 = UNK_00cb2d;
  if (cVar1 == '\x10') {
    uStack_4 = Ram00c8e8;
  }
  axis16_signed(0x771c,uStack_4);
  UNK_00cb39 = extraout_RH4;
  return;
}



/* ===== c23958 gap_c23958 size=42 ===== */

void gap_c23958(void)

{
  char cVar1;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar1 = UNK_00cb2d;
  if (cVar1 == '\x10') {
    uStack_4 = Ram00c94e;
  }
  axis16_signed(0x76fe,uStack_4);
  UNK_00cb39 = extraout_RH4;
  return;
}



/* ===== c23982 gap_c23982 size=88 ===== */

void gap_c23982(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(8,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = Ram00ca38;
  }
  uVar4 = func_0xc27b86(uStack_4,0xffff,0xf);
  axis16_unsigned(0x770a,uVar4);
  UNK_00cb39 = extraout_RH4;
  return;
}



/* ===== c239da gap_c239da size=28 ===== */

void gap_c239da(void)

{
  if (cRamc07c7c == '\0') {
    UNK_00cb39 = 1;
    return;
  }
  UNK_00cb39 = 0x11;
  return;
}



/* ===== c239f6 gap_c239f6 size=24 ===== */

void gap_c239f6(void)

{
  char cVar1;
  
  cVar1 = UNK_00cb2d;
  if (cVar1 == '\x10') {
    uRamc04b39 = uRamc07d10;
  }
  return;
}



/* ===== c23a0e gap_c23a0e size=116 ===== */

void gap_c23a0e(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = UNK_00cb2d;
  if (cVar1 == '\x10') {
    uVar2 = gap_c23554(2,0);
    UNK_00cb39 = uVar2;
    uVar2 = gap_c23554(2,1);
    UNK_00cb38 = uVar2;
    uVar2 = gap_c23554(2,2);
    UNK_00cb37 = uVar2;
    uVar2 = gap_c23554(2,3);
    UNK_00cb36 = uVar2;
  }
  else if (cVar1 == ' ') {
    uVar2 = gap_c23554(4,0);
    UNK_00cb39 = uVar2;
    uVar2 = gap_c23554(4,1);
    UNK_00cb38 = uVar2;
    uVar2 = gap_c23554(4,2);
    UNK_00cb37 = uVar2;
    uVar2 = gap_c23554(4,3);
    UNK_00cb36 = uVar2;
    return;
  }
  return;
}



/* ===== c23a82 gap_c23a82 size=20 ===== */

void gap_c23a82(void)

{
  undefined2 uVar1;
  char cVar2;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == '\x10') {
    uVar1 = Ram00c074;
    Ram00cb38 = uVar1;
  }
  return;
}



/* ===== c23a96 gap_c23a96 size=116 ===== */

void gap_c23a96(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = UNK_00cb2d;
  if (cVar1 == '\x10') {
    uVar2 = gap_c23554(3,0);
    UNK_00cb39 = uVar2;
    uVar2 = gap_c23554(3,1);
    UNK_00cb38 = uVar2;
    uVar2 = gap_c23554(3,2);
    UNK_00cb37 = uVar2;
    uVar2 = gap_c23554(3,3);
    UNK_00cb36 = uVar2;
  }
  else if (cVar1 == ' ') {
    uVar2 = gap_c23554(5,0);
    UNK_00cb39 = uVar2;
    uVar2 = gap_c23554(5,1);
    UNK_00cb38 = uVar2;
    uVar2 = gap_c23554(5,2);
    UNK_00cb37 = uVar2;
    uVar2 = gap_c23554(5,3);
    UNK_00cb36 = uVar2;
    return;
  }
  return;
}



/* ===== c23b0a gap_c23b0a size=10 ===== */

void gap_c23b0a(void)

{
  undefined2 uVar1;
  
  uVar1 = Ram00c070;
  Ram00cb38 = uVar1;
  return;
}



/* ===== c23b14 gap_c23b14 size=116 ===== */

void gap_c23b14(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = UNK_00cb2d;
  if (cVar1 == '\x10') {
    uVar2 = gap_c23554(6,0);
    UNK_00cb39 = uVar2;
    uVar2 = gap_c23554(6,1);
    UNK_00cb38 = uVar2;
    uVar2 = gap_c23554(6,2);
    UNK_00cb37 = uVar2;
    uVar2 = gap_c23554(6,3);
    UNK_00cb36 = uVar2;
  }
  else if (cVar1 == ' ') {
    uVar2 = gap_c23554(7,0);
    UNK_00cb39 = uVar2;
    uVar2 = gap_c23554(7,1);
    UNK_00cb38 = uVar2;
    uVar2 = gap_c23554(7,2);
    UNK_00cb37 = uVar2;
    uVar2 = gap_c23554(7,3);
    UNK_00cb36 = uVar2;
    return;
  }
  return;
}



/* ===== c23b88 gap_c23b88 size=128 ===== */

void gap_c23b88(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 unaff_0000fff8;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(9,uVar1);
    unaff_0000fff8 = *(undefined2 *)(uint3)uVar3;
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(10,uVar1,unaff_0000fff8,*(undefined2 *)(uint3)(uVar3 + 2));
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    unaff_0000fff8 = gap_c20600();
    uStack_4 = func_0xc2060a(unaff_0000fff8);
  }
  UNK_00cb39 = 1;
  UNK_00cb38 = (char)((ushort)unaff_0000fff8 >> 8);
  UNK_00cb37 = (char)unaff_0000fff8;
  UNK_00cb36 = (char)((ushort)uStack_4 >> 8);
  UNK_00cb3d = (char)uStack_4;
  return;
}



/* ===== c23d06 gap_c23d06 size=274 ===== */

char gap_c23d06(ushort param_1)

{
  undefined1 uVar1;
  char unaff_RL6;
  
  uVar1 = UNK_00cb33;
  *(undefined1 *)(uint3)(param_1 + 0x1a) = uVar1;
  uVar1 = UNK_00cb34;
  *(undefined1 *)(uint3)(param_1 + 0x19) = uVar1;
  uVar1 = UNK_00cb35;
  *(undefined1 *)(uint3)(param_1 + 0x18) = uVar1;
  uVar1 = UNK_00cb28;
  *(undefined1 *)(uint3)(param_1 + 0x17) = uVar1;
  uVar1 = UNK_00cb29;
  *(undefined1 *)(uint3)(param_1 + 0x16) = uVar1;
  uVar1 = UNK_00cb2a;
  *(undefined1 *)(uint3)(param_1 + 0x15) = uVar1;
  uVar1 = UNK_00cb2b;
  *(undefined1 *)(uint3)(param_1 + 0x14) = uVar1;
  uVar1 = UNK_00cb42;
  *(undefined1 *)(uint3)(param_1 + 0x13) = uVar1;
  uVar1 = UNK_00cb43;
  *(undefined1 *)(uint3)(param_1 + 0x12) = uVar1;
  uVar1 = UNK_00cb44;
  *(undefined1 *)(uint3)(param_1 + 0x11) = uVar1;
  uVar1 = UNK_00cb45;
  *(undefined1 *)(uint3)(param_1 + 0x10) = uVar1;
  uVar1 = UNK_00cb3e;
  *(undefined1 *)(uint3)(param_1 + 0xf) = uVar1;
  uVar1 = UNK_00cb3f;
  *(undefined1 *)(uint3)(param_1 + 0xe) = uVar1;
  uVar1 = UNK_00cb40;
  *(undefined1 *)(uint3)(param_1 + 0xd) = uVar1;
  uVar1 = UNK_00cb41;
  *(undefined1 *)(uint3)(param_1 + 0xc) = uVar1;
  uVar1 = UNK_00cb2e;
  *(undefined1 *)(uint3)(param_1 + 0xb) = uVar1;
  uVar1 = UNK_00cb2f;
  *(undefined1 *)(uint3)(param_1 + 10) = uVar1;
  uVar1 = UNK_00cb30;
  *(undefined1 *)(uint3)(param_1 + 9) = uVar1;
  uVar1 = UNK_00cb31;
  *(undefined1 *)(uint3)(param_1 + 8) = uVar1;
  uVar1 = UNK_00cb3a;
  *(undefined1 *)(uint3)(param_1 + 7) = uVar1;
  uVar1 = UNK_00cb3b;
  *(undefined1 *)(uint3)(param_1 + 6) = uVar1;
  uVar1 = UNK_00cb3c;
  *(undefined1 *)(uint3)(param_1 + 5) = uVar1;
  uVar1 = UNK_00cb3d;
  *(undefined1 *)(uint3)(param_1 + 4) = uVar1;
  uVar1 = UNK_00cb36;
  *(undefined1 *)(uint3)(param_1 + 3) = uVar1;
  uVar1 = UNK_00cb37;
  *(undefined1 *)(uint3)(param_1 + 2) = uVar1;
  uVar1 = UNK_00cb38;
  *(undefined1 *)(uint3)(param_1 + 1) = uVar1;
  uVar1 = UNK_00cb39;
  *(undefined1 *)(uint3)param_1 = uVar1;
  return unaff_RL6 + '\x1b';
}



/* ===== c23e18 gap_c23e18 size=30 ===== */

undefined1 * gap_c23e18(void)

{
  func_0xc28b5a(1);
  return &stack0x0000;
}



/* ===== c23e36 gap_c23e36 size=6 ===== */

void gap_c23e36(void)

{
  UNK_00cb5a = 0;
  return;
}



/* ===== c240fe gap_c240fe size=274 ===== */

void gap_c240fe(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  char cVar4;
  ushort uVar5;
  
  uVar5 = DAT_00c9d0;
  if (uVar5 <= uRamc07d1c) {
    cVar4 = UNK_00cb64;
    if (cVar4 == '\0') {
      UNK_00cb64 = 1;
      DAT_00cb60 = 0;
      uVar5 = Ram00cb68;
      do {
        uVar5 = uVar5 + 1;
        if (0x26 < uVar5) goto LAB_c24156;
        cVar4 = func_0xc24530(uVar5);
      } while (cVar4 == '\0');
      DAT_00cb60 = *(undefined2 *)(uint3)(*(short *)(uint3)(uVar5 * 4 + 0x71ea) + 2);
      Ram00cb68 = uVar5;
LAB_c24156:
      sVar1 = DAT_00cb60;
      if (sVar1 == 0) {
        uVar5 = 0;
        while( true ) {
          uVar2 = Ram00cb68;
          uVar3 = Ram00cb68;
          if (uVar5 != uVar3 && uVar2 <= uVar5) break;
          cVar4 = func_0xc24530(uVar5);
          if (cVar4 != '\0') {
            DAT_00cb60 = *(undefined2 *)(uint3)(*(short *)(uint3)(uVar5 * 4 + 0x71ea) + 2);
            Ram00cb68 = uVar5;
            return;
          }
          uVar5 = uVar5 + 1;
        }
      }
    }
    else {
      UNK_00cb64 = 0;
      Ram00cb62 = 0;
      uVar5 = Ram00cb66;
      do {
        uVar5 = uVar5 + 1;
        if (0x26 < uVar5) goto LAB_c241d2;
        cVar4 = gap_c244ce(uVar5);
      } while (cVar4 == '\0');
      Ram00cb62 = *(undefined2 *)(uint3)(*(short *)(uint3)(uVar5 * 4 + 0x71ea) + 2);
      Ram00cb66 = uVar5;
LAB_c241d2:
      sVar1 = Ram00cb62;
      if (sVar1 == 0) {
        uVar5 = 0;
        while( true ) {
          uVar2 = Ram00cb66;
          uVar3 = Ram00cb66;
          if (uVar5 != uVar3 && uVar2 <= uVar5) break;
          cVar4 = gap_c244ce(uVar5);
          if (cVar4 != '\0') {
            Ram00cb62 = *(undefined2 *)(uint3)(*(short *)(uint3)(uVar5 * 4 + 0x71ea) + 2);
            Ram00cb66 = uVar5;
            return;
          }
          uVar5 = uVar5 + 1;
        }
      }
    }
  }
  return;
}



/* ===== c2432e gap_c2432e size=34 ===== */

byte gap_c2432e(short param_1)

{
  short sVar1;
  byte bVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 == -1) {
    bVar2 = 0;
  }
  else {
    bVar2 = (byte)(*(ushort *)(uint3)(ushort)((short)&UNK_00c168 + sVar1 * 2) >> 6) & 3;
  }
  return bVar2;
}



/* ===== c24350 gap_c24350 size=56 ===== */

void gap_c24350(short param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if ((sVar1 != -1) &&
     (uVar2 = (short)&UNK_00c168 + sVar1 * 2, (*(ushort *)(uint3)uVar2 >> 6 & 3) != 0)) {
    *(ushort *)(uint3)uVar2 =
         *(ushort *)(uint3)uVar2 & 0xff3f | ((*(ushort *)(uint3)uVar2 >> 6 & 3) - 1 & 3) << 6;
  }
  return;
}



/* ===== c243a8 FUN_c243a8 size=34 ===== */

byte FUN_c243a8(short param_1)

{
  short sVar1;
  byte bVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 == -1) {
    bVar2 = 0;
  }
  else {
    bVar2 = (byte)(*(ushort *)(uint3)(ushort)((short)&UNK_00c168 + sVar1 * 2) >> 5) & 1;
  }
  return bVar2;
}



/* ===== c243ca gap_c243ca size=32 ===== */

void gap_c243ca(short param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 != -1) {
    uVar2 = (short)&UNK_00c168 + sVar1 * 2;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xffdf | 0x20;
  }
  return;
}



/* ===== c243ea gap_c243ea size=32 ===== */

void gap_c243ea(short param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 != -1) {
    uVar2 = (short)&UNK_00c168 + sVar1 * 2;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xffdf;
  }
  return;
}



/* ===== c2444c gap_c2444c size=32 ===== */

void gap_c2444c(short param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 != -1) {
    uVar2 = (short)&UNK_00c168 + sVar1 * 2;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xffef;
  }
  return;
}



/* ===== c244ce gap_c244ce size=34 ===== */

byte gap_c244ce(short param_1)

{
  short sVar1;
  byte bVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 == -1) {
    bVar2 = 0;
  }
  else {
    bVar2 = (byte)(*(ushort *)(uint3)(ushort)((short)&UNK_00c168 + sVar1 * 2) >> 2) & 1;
  }
  return bVar2;
}



/* ===== c24510 gap_c24510 size=32 ===== */

void gap_c24510(short param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 != -1) {
    uVar2 = (short)&UNK_00c168 + sVar1 * 2;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xfffb;
  }
  return;
}



/* ===== c24592 gap_c24592 size=32 ===== */

byte gap_c24592(short param_1)

{
  short sVar1;
  byte bVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 == -1) {
    bVar2 = 0;
  }
  else {
    bVar2 = (byte)*(undefined2 *)(uint3)(ushort)((short)&UNK_00c168 + sVar1 * 2) & 1;
  }
  return bVar2;
}



/* ===== c245b2 gap_c245b2 size=32 ===== */

void gap_c245b2(short param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 != -1) {
    uVar2 = (short)&UNK_00c168 + sVar1 * 2;
    *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0xfffe | 1;
  }
  return;
}



/* ===== c245f2 gap_c245f2 size=4 ===== */

undefined1 gap_c245f2(void)

{
  return 0;
}



/* ===== c246fe gap_c246fe size=34 ===== */

byte gap_c246fe(short param_1)

{
  short sVar1;
  byte bVar2;
  
  sVar1 = *(short *)(uint3)(param_1 * 2 + 0x7286);
  if (sVar1 == -1) {
    bVar2 = 0;
  }
  else {
    bVar2 = (byte)((ushort)*(undefined2 *)(uint3)(ushort)((short)&UNK_00c168 + sVar1 * 2) >> 0xc) &
            1;
  }
  return bVar2;
}



/* ===== c247aa gap_c247aa size=60 ===== */

void gap_c247aa(ushort param_1)

{
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  uStack_4 = *(ushort *)(uint3)param_1;
  uStack_2 = *(ushort *)(uint3)(param_1 + 2);
  while( true ) {
    if ((uStack_4 | uStack_2) == 0) break;
    empty_stub_0(uStack_4 | uStack_2);
    uStack_4 = *(ushort *)(uint3)(param_1 + 4);
    uStack_2 = *(ushort *)(uint3)(param_1 + 6);
    param_1 = param_1 + 4;
  }
  return;
}



/* ===== c247e6 gap_c247e6 size=28 ===== */

void gap_c247e6(undefined2 param_1)

{
  char cVar1;
  short sVar2;
  
  cVar1 = func_0xc24724();
  if (cVar1 != '\0') {
    sVar2 = func_0xc2473a(param_1);
    *(undefined1 *)(uint3)(ushort)((short)&UNK_00cb6c + sVar2) = 1;
  }
  return;
}



/* ===== c24802 gap_c24802 size=28 ===== */

void gap_c24802(undefined2 param_1)

{
  char cVar1;
  short sVar2;
  
  cVar1 = func_0xc24724();
  if (cVar1 != '\0') {
    sVar2 = func_0xc2473a(param_1);
    *(undefined1 *)(uint3)(ushort)((short)&UNK_00cb6c + sVar2) = 0;
  }
  return;
}



/* ===== c24828 gap_c24828 size=10 ===== */

void gap_c24828(void)

{
  gap_c247aa(0x7898);
  return;
}



/* ===== c24846 gap_c24846 size=10 ===== */

void gap_c24846(void)

{
  gap_c247aa(0x78e8);
  return;
}



/* ===== c2485a gap_c2485a size=10 ===== */

void gap_c2485a(void)

{
  gap_c247aa(0x78f4);
  return;
}



/* ===== c24864 gap_c24864 size=10 ===== */

void gap_c24864(void)

{
  gap_c247aa(0x78ec);
  return;
}



/* ===== c24878 gap_c24878 size=10 ===== */

void gap_c24878(void)

{
  gap_c247aa(0x7900);
  return;
}



/* ===== c24882 gap_c24882 size=10 ===== */

void gap_c24882(void)

{
  gap_c247aa(0x790c);
  return;
}



/* ===== c24896 gap_c24896 size=10 ===== */

void gap_c24896(void)

{
  func_0xc24764(0x791c);
  return;
}



/* ===== c248ce gap_c248ce size=10 ===== */

void gap_c248ce(void)

{
  func_0xc24764(0x794c);
  return;
}



/* ===== c248d8 gap_c248d8 size=18 ===== */

void gap_c248d8(void)

{
  func_0xc24764(0x7946);
  func_0xc24764(0x7952);
  return;
}



/* ===== c248ea gap_c248ea size=58 ===== */

void gap_c248ea(void)

{
  char cVar1;
  
  cVar1 = UNK_00c898;
  if (cVar1 != '\a') {
    if (cVar1 == '\x05') {
      func_0xc24764(0x7a2a);
      goto LAB_c2491a;
    }
    cVar1 = UNK_00c898;
    if (cVar1 != '\x03') {
      cVar1 = UNK_00c898;
      if (cVar1 != '\x01') {
        return;
      }
      goto LAB_c2491a;
    }
  }
  func_0xc24764(0x7a24);
LAB_c2491a:
  func_0xc24764(0x7a1e);
  return;
}



/* ===== c24924 gap_c24924 size=10 ===== */

void gap_c24924(void)

{
  func_0xc24764(0x7946);
  return;
}



/* ===== c2492e gap_c2492e size=10 ===== */

void gap_c2492e(void)

{
  UNK_00cbda = 0;
  UNK_00cbd4 = 0;
  return;
}



/* ===== c24a16 gap_c24a16 size=122 ===== */

void gap_c24a16(void)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  
  gap_c2492e();
  sVar5 = 0;
  uRame0083c = 0;
  uRame00bdb = 0;
  for (uVar4 = 0; uVar4 < 0x27; uVar4 = uVar4 + 1) {
    sVar1 = *(short *)(uint3)(uVar4 * 2 + 0x7286);
    if (sVar1 != -1) {
      cVar3 = func_0xc259ee(sVar1);
      if (cVar3 == '\0') {
        *(undefined2 *)(uint3)(ushort)((short)&UNK_00cb86 + sVar5 * 2) = 0xffff;
      }
      else {
        uVar2 = (short)&UNK_00c168 + sVar1 * 2;
        *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 & 0x9fff;
        sVar1 = Ram00cb84;
        Ram00cb84 = sVar1 + 1;
        *(ushort *)(uint3)(ushort)((short)&UNK_00cb86 + sVar5 * 2) = uVar4;
      }
      sVar5 = sVar5 + 1;
    }
  }
  UNK_00c1b6 = 0;
  UNK_00c1ba = 0;
  return;
}



/* ===== c24c14 gap_c24c14 size=22 ===== */

void gap_c24c14(void)

{
  gap_c15a12((short)&UNK_00cbd4,(short)&UNK_00cbda,1);
  UNK_00cbd9 = 1;
  return;
}



/* ===== c24c2a gap_c24c2a size=28 ===== */

void gap_c24c2a(undefined2 param_1)

{
  char cVar1;
  
  cVar1 = func_0xc24286();
  if (cVar1 != '\0') {
    gap_c247e6(param_1);
    return;
  }
  gap_c24802(param_1);
  return;
}



/* ===== c24c72 gap_c24c72 size=66 ===== */

void gap_c24c72(short param_1,undefined2 param_2,byte param_3)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = 0;
  while( true ) {
    if (param_3 <= bVar2) {
      return;
    }
    cVar1 = func_0xc24286(*(undefined2 *)(uint3)(param_1 + (ushort)bVar2 * 2));
    if (cVar1 == '\0') break;
    gap_c247e6(param_2);
    bVar2 = bVar2 + 1;
  }
  gap_c24802(param_2);
  return;
}



/* ===== c24cb4 gap_c24cb4 size=40 ===== */

void gap_c24cb4(char param_1,char param_2,char param_3,ushort param_4,ushort unaff_00000000)

{
  if (param_1 != '\0') {
    *(undefined2 *)(uint3)param_4 = 0;
    *(undefined2 *)(uint3)unaff_00000000 = 0;
  }
  if ((param_2 != '\0') &&
     (*(short *)(uint3)unaff_00000000 = *(short *)(uint3)unaff_00000000 + 1, param_3 != '\0')) {
    *(short *)(uint3)param_4 = *(short *)(uint3)param_4 + 1;
  }
  return;
}



/* ===== c24d1c gap_c24d1c size=36 ===== */

void gap_c24d1c(ushort param_1,ushort param_2,ushort param_3,ushort param_4,ushort unaff_00000000,
               ushort unaff_00000002)

{
  if (param_1 < param_3) {
    if (param_2 < param_4) {
      *(undefined1 *)(uint3)unaff_00000000 = 0;
      return;
    }
    *(undefined1 *)(uint3)unaff_00000002 = 0;
  }
  else {
    *(undefined1 *)(uint3)unaff_00000002 = 1;
  }
  *(undefined1 *)(uint3)unaff_00000000 = 1;
  return;
}



/* ===== c24d9a gap_c24d9a size=54 ===== */

void gap_c24d9a(char param_1,char param_2,ushort param_3)

{
  if (param_1 != '\0') {
    if ((param_2 == '\0') || (*(char *)(uint3)param_3 == '\x02')) {
      if ((param_2 == '\0') && (*(char *)(uint3)param_3 != '\x01')) {
        func_0xc2572c();
        *(undefined1 *)(uint3)param_3 = 1;
      }
    }
    else {
      func_0xc25710();
      *(undefined1 *)(uint3)param_3 = 2;
    }
  }
  return;
}



/* ===== c24e34 gap_c24e34 size=38 ===== */

void gap_c24e34(void)

{
  func_0xc24218();
  gap_c255cc();
  func_0xc24938();
  gap_c2756a();
  func_0xc252d0();
  func_0xc24ff8();
  func_0xc2481e();
  func_0xc257e6();
  func_0xc25a98();
  return;
}



/* ===== c24e5a gap_c24e5a size=6 ===== */

void gap_c24e5a(void)

{
  func_0xc2483c();
  return;
}



/* ===== c24e60 gap_c24e60 size=6 ===== */

void gap_c24e60(void)

{
  gap_c24846();
  return;
}



/* ===== c24e6c gap_c24e6c size=6 ===== */

void gap_c24e6c(void)

{
  func_0xc24850();
  return;
}



/* ===== c24e72 gap_c24e72 size=6 ===== */

void gap_c24e72(void)

{
  gap_c2485a();
  return;
}



/* ===== c24e78 gap_c24e78 size=6 ===== */

void gap_c24e78(void)

{
  gap_c24864();
  return;
}



/* ===== c24e88 gap_c24e88 size=14 ===== */

void gap_c24e88(void)

{
  gap_c25600();
  func_0xc2507e();
  gap_c24878();
  return;
}



/* ===== c24eb2 gap_c24eb2 size=6 ===== */

void gap_c24eb2(void)

{
  gap_c24896();
  return;
}



/* ===== c24ec2 gap_c24ec2 size=28 ===== */

void gap_c24ec2(void)

{
  func_0xc159bc((short)&UNK_00cbdc,(short)&UNK_00cbe0,2);
  func_0xc257f6();
  func_0xc259ce();
  func_0xc23fda();
  return;
}



/* ===== c24ee0 gap_c24ee0 size=14 ===== */

void gap_c24ee0(void)

{
  func_0xc2422c();
  gap_c24c14();
  gap_c2769c();
  return;
}



/* ===== c24eee gap_c24eee size=34 ===== */

void gap_c24eee(void)

{
  func_0xc27076();
  func_0xc2421a();
  gap_c25300();
  gap_c240fe();
  func_0xc24210();
  func_0xc24212();
  func_0xc24214();
  func_0xc24216();
  return;
}



/* ===== c24f1a gap_c24f1a size=6 ===== */

void gap_c24f1a(void)

{
  func_0xc2595e();
  return;
}



/* ===== c24f26 gap_c24f26 size=6 ===== */

void gap_c24f26(void)

{
  func_0xc2595e();
  return;
}



/* ===== c24f3e gap_c24f3e size=8 ===== */

undefined2 gap_c24f3e(void)

{
  undefined2 uVar1;
  
  uVar1 = gap_c21f42();
  return uVar1;
}



/* ===== c24f46 gap_c24f46 size=6 ===== */

undefined2 gap_c24f46(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00ca2a;
  return uVar1;
}



/* ===== c24f4c gap_c24f4c size=6 ===== */

undefined2 gap_c24f4c(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00c936;
  return uVar1;
}



/* ===== c24f52 gap_c24f52 size=6 ===== */

undefined2 gap_c24f52(void)

{
  undefined2 uVar1;
  
  uVar1 = Ram00ca8e;
  return uVar1;
}



/* ===== c24f58 gap_c24f58 size=6 ===== */

undefined2 gap_c24f58(void)

{
  undefined2 uVar1;
  
  uVar1 = Ram00ca90;
  return uVar1;
}



/* ===== c24f5e gap_c24f5e size=6 ===== */

undefined2 gap_c24f5e(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00ca04;
  return uVar1;
}



/* ===== c24f64 gap_c24f64 size=6 ===== */

undefined2 gap_c24f64(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00c9d0;
  return uVar1;
}



/* ===== c24f6a gap_c24f6a size=6 ===== */

undefined2 gap_c24f6a(void)

{
  undefined2 uVar1;
  
  uVar1 = Ram00ca3e;
  return uVar1;
}



/* ===== c24f70 gap_c24f70 size=6 ===== */

undefined2 gap_c24f70(void)

{
  undefined2 uVar1;
  
  uVar1 = Ram00ca38;
  return uVar1;
}



/* ===== c24f76 gap_c24f76 size=8 ===== */

undefined2 gap_c24f76(void)

{
  undefined2 uVar1;
  
  uVar1 = gap_c20600();
  return uVar1;
}



/* ===== c24f7e gap_c24f7e size=14 ===== */

undefined2 gap_c24f7e(void)

{
  undefined2 uVar1;
  
  uVar1 = func_0xc2060a();
  return uVar1;
}



/* ===== c24fd8 gap_c24fd8 size=32 ===== */

ushort gap_c24fd8(ushort param_1,ushort param_2,short param_3)

{
  short *psVar1;
  ushort uVar2;
  
  for (uVar2 = 0; (*(short *)(uint3)param_1 != 0xb && (uVar2 < param_2)); uVar2 = uVar2 + 1) {
    psVar1 = (short *)(uint3)param_1;
    param_1 = param_1 + 2;
    if (*psVar1 == param_3) {
      return uVar2;
    }
  }
  return 0xffff;
}



/* ===== c25026 gap_c25026 size=40 ===== */

void gap_c25026(void)

{
  bool bVar1;
  short sVar2;
  
  sVar2 = 0;
  do {
    func_0xc245d2(sVar2);
    func_0xc245f8(sVar2);
    func_0xc24388(sVar2);
    bVar1 = sVar2 < 0x26;
    sVar2 = sVar2 + 1;
  } while (bVar1);
  UNK_00c1b7 = 0;
  UNK_00c1b8 = 0;
  return;
}



/* ===== c2504e gap_c2504e size=48 ===== */

void gap_c2504e(undefined2 param_1)

{
  func_0xc2469e();
  gap_c24510(param_1);
  func_0xc2463c(param_1);
  func_0xc24572(param_1);
  func_0xc245d2(param_1);
  func_0xc24388(param_1);
  func_0xc246de(param_1);
  return;
}



/* ===== c25300 gap_c25300 size=144 ===== */

void gap_c25300(void)

{
  undefined2 uVar1;
  bool bVar2;
  bool bVar3;
  ushort in_r1;
  ushort uVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  
  bVar6 = 0;
  uVar4 = in_r1 & 0xff00;
  do {
    bVar7 = 0;
    bVar2 = false;
    bVar3 = true;
    while (*(short *)(uint3)(*(short *)(uint3)((ushort)bVar6 * 2 + 0x7318) + (ushort)bVar7 * 2) != 0
          ) {
      uVar1 = *(undefined2 *)
               (uint3)(*(short *)(uint3)((ushort)bVar6 * 2 + 0x7318) + (ushort)bVar7 * 2);
      cVar5 = func_0xc2446c();
      if (cVar5 != '\0') {
        bVar2 = true;
      }
      cVar5 = func_0xc245fa(uVar1,uVar4);
      if (cVar5 == '\x01') {
        bVar3 = false;
      }
      bVar7 = bVar7 + 1;
    }
    if (((bVar2) && (bVar3)) && ((bRamc07d16 >> (ushort)bVar6 & 1) != 0)) {
      uVar4 = CONCAT11((char)(uVar4 >> 8),(byte)uVar4 | '\x01' << (ushort)bVar6);
    }
    bVar6 = bVar6 + 1;
  } while (bVar6 < 8);
  UNK_00cbe6 = (char)uVar4;
  return;
}



/* ===== c253d2 gap_c253d2 size=4 ===== */

undefined1 gap_c253d2(void)

{
  return 1;
}



/* ===== c255cc gap_c255cc size=52 ===== */

void gap_c255cc(void)

{
  char cVar1;
  ushort uVar2;
  
  cVar1 = UNK_00c702;
  if (cVar1 == '\0') {
    uVar2 = 0;
    do {
      gap_c243ea(uVar2);
      gap_c2444c(uVar2);
      func_0xc24722(uVar2);
      func_0xc24572(uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x27);
  }
  else {
    func_0xc25414();
  }
  return;
}



/* ===== c25600 gap_c25600 size=272 ===== */

void gap_c25600(void)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  
  bVar6 = 0;
  do {
    sVar2 = (ushort)bVar6 * 0x1e;
    uVar1 = (short)&UNK_00c10e + sVar2;
    cVar5 = FUN_c243a8(*(undefined2 *)(uint3)uVar1);
    if (cVar5 == '\0') {
      cVar5 = func_0xc2440a(*(undefined2 *)(uint3)uVar1);
      if (cVar5 == '\0') {
        if (*(short *)(uint3)uVar1 != 0) {
          uVar1 = (short)&UNK_00c112 + sVar2;
          bVar4 = (byte)((ushort)*(undefined2 *)(uint3)uVar1 >> 8);
          bVar3 = bVar4 + 1;
          if (bVar3 == 0) {
            bVar3 = bVar4;
          }
          *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xff | (ushort)bVar3 << 8;
        }
      }
      else {
        uVar1 = (short)&UNK_00c112 + sVar2;
        bVar3 = (byte)*(undefined2 *)(uint3)uVar1 + 1;
        if (bVar3 == 0) {
          bVar3 = (byte)*(undefined2 *)(uint3)uVar1;
        }
        *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xff00 | (ushort)bVar3;
      }
    }
    else {
      uVar1 = (short)&UNK_00c110 + sVar2;
      bVar4 = (byte)((ushort)*(undefined2 *)(uint3)uVar1 >> 8);
      bVar3 = bVar4 + 1;
      if (bVar3 == 0) {
        bVar3 = bVar4;
      }
      *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xff | (ushort)bVar3 << 8;
    }
    bVar6 = bVar6 + 1;
  } while (bVar6 < 3);
  return;
}



/* ===== c25732 gap_c25732 size=46 ===== */

void gap_c25732(void)

{
  char cVar1;
  ushort uVar2;
  
  func_0xc25414();
  uVar2 = 0;
  do {
    cVar1 = func_0xc24286(uVar2);
    if ((cVar1 != '\0') && (cVar1 = func_0xc2465c(uVar2), cVar1 == '\x01')) {
      func_0xc246de(uVar2);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x27);
  return;
}



/* ===== c25a7c gap_c25a7c size=28 ===== */

bool gap_c25a7c(short param_1)

{
  return (*(ushort *)(uint3)*(ushort *)(uint3)(param_1 * 4 + 0x71ea) & 0x10) != 0;
}



/* ===== c25aa2 gap_c25aa2 size=10 ===== */

void gap_c25aa2(void)

{
  UNK_00cbf9 = 0;
  UNK_00cbf8 = 0;
  return;
}



/* ===== c25ae4 gap_c25ae4 size=26 ===== */

void gap_c25ae4(void)

{
  Ram00cbfe = 0;
  Ram00cbfc = 0;
  Ram00cbfa = 0;
  UNK_00cc01 = 0;
  UNK_00cc00 = 0;
  UNK_00cc02 = 0;
  return;
}



/* ===== c25afe gap_c25afe size=12 ===== */

void gap_c25afe(void)

{
  func_0xc24c46(8,7,8);
  return;
}



/* ===== c25b0a gap_c25b0a size=46 ===== */

void gap_c25b0a(void)

{
  char cVar1;
  
  cVar1 = DAT_00c954;
  if ((cVar1 == '\x01') &&
     (((cVar1 = DAT_00c93c, cVar1 == '\x03' || (cVar1 == '\x04')) || (cVar1 == '\x01')))) {
    uRame008d3 = 1;
    return;
  }
  uRame008d3 = 0;
  return;
}



/* ===== c25b38 gap_c25b38 size=110 ===== */

void gap_c25b38(void)

{
  ushort uVar1;
  
  if ((cRame008d3 == '\x01') && (uVar1 = DAT_00c962, uVar1 < uRamc07d2c)) {
    uRame008d2 = 0;
    uRame008d4 = 1;
    return;
  }
  if ((cRame008d3 == '\x01') && (uVar1 = DAT_00c962, uRamc07d2e < uVar1)) {
    uRame008d4 = 0;
    uRame008d2 = 1;
    return;
  }
  uRame008d2 = 0;
  uRame008d4 = 0;
  return;
}



/* ===== c25ba6 gap_c25ba6 size=152 ===== */

void gap_c25ba6(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 auStack_a [2];
  undefined1 auStack_8 [8];
  
  gap_c25b0a();
  gap_c25b38();
  uVar4 = UNK_00cc01;
  func_0xc24cdc(uVar4,uRame008d3,uRame008d4,uRame008d2);
  *(undefined2 *)((uint3)((ushort)auStack_8 & 0x3fff) + 0xc04000) = uRamc07d2a;
  *(undefined2 *)((uint3)((ushort)auStack_a & 0x3fff) + 0xc04000) = uRamc07d28;
  uVar3 = Ram00cbfe;
  uVar2 = Ram00cbfc;
  uVar1 = Ram00cbfa;
  func_0xc24d40(uVar3,uVar2,uVar1,uRamc07d26);
  uVar4 = UNK_00cc00;
  uVar4 = UNK_00cc01;
  uVar5 = UNK_00cc02;
  func_0xc24dd0(8,7,uVar4,uVar5);
  return;
}



/* ===== c25c3e gap_c25c3e size=34 ===== */

void gap_c25c3e(void)

{
  Ram00cc0c = 0;
  Ram00cc04 = 0;
  Ram00cc0e = 0;
  Ram00cc06 = 0;
  UNK_00cc0a = 0;
  UNK_00cc08 = 0;
  UNK_00cc09 = 0;
  UNK_00cc10 = 0;
  return;
}



/* ===== c25c60 gap_c25c60 size=12 ===== */

void gap_c25c60(void)

{
  func_0xc24c46(2,1,2);
  return;
}



/* ===== c25c6c gap_c25c6c size=310 ===== */

void gap_c25c6c(void)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  char cVar5;
  
  func_0xc25da2();
  func_0xc25e00();
  uVar2 = UNK_00cc08;
  gap_c24cb4(uVar2,uRame008d6,cRame00700,(short)&UNK_00cc0c,(short)&UNK_00cc04);
  uVar2 = UNK_00cc10;
  gap_c24cb4(uVar2,uRame008d7,cRame006fe,(short)&UNK_00cc0e,(short)&UNK_00cc06);
  uVar4 = Ram00cc0c;
  uVar1 = Ram00cc04;
  gap_c24d1c(uVar4,uVar1,uRamc07d3c,uRamc07d3e,(short)&UNK_00cc08,(short)&UNK_00cc0a);
  uVar4 = Ram00cc0e;
  uVar1 = Ram00cc06;
  gap_c24d1c(uVar4,uVar1,uRamc07d38,uRamc07d3a,(short)&UNK_00cc10,(short)&UNK_00cc09);
  uVar2 = UNK_00cc08;
  uVar3 = UNK_00cc0a;
  func_0xc24d82(2,uVar2,uVar3);
  uVar3 = UNK_00cc10;
  uVar2 = UNK_00cc09;
  func_0xc24d82(1,uVar3,uVar2);
  cVar5 = func_0xc24530(1);
  if ((cVar5 == '\0') && (cVar5 = func_0xc24530(2), cVar5 == '\0')) {
    uRame006fc = 0;
  }
  else {
    uRame006fc = 1;
  }
  cVar5 = func_0xc24530(1);
  if ((cVar5 == '\0') && (cVar5 = func_0xc24530(2), cVar5 == '\0')) {
    uRame006fd = 0;
  }
  else {
    uRame006fd = 1;
  }
  if ((cRame00700 == '\0') && (cRame006fe == '\0')) {
    uRame006ff = 0;
    return;
  }
  uRame006ff = 1;
  return;
}



/* ===== c25e52 gap_c25e52 size=14 ===== */

void gap_c25e52(void)

{
  undefined1 uVar1;
  
  uVar1 = FUN_c243a8(0x12);
  UNK_00cc13 = uVar1;
  return;
}



/* ===== c25e60 gap_c25e60 size=14 ===== */

void gap_c25e60(void)

{
  undefined1 uVar1;
  
  uVar1 = FUN_c243a8(0x13);
  UNK_00cc12 = uVar1;
  return;
}



/* ===== c25e7c gap_c25e7c size=38 ===== */

void gap_c25e7c(void)

{
  Ram00cc18 = 0;
  Ram00cc1c = 0;
  Ram00cc20 = 0;
  Ram00cc22 = 0;
  UNK_00cc25 = 0;
  UNK_00cc15 = 0;
  UNK_00cc24 = 0;
  UNK_00cc1f = 0;
  func_0xc25e70();
  return;
}



/* ===== c25ea2 gap_c25ea2 size=12 ===== */

void gap_c25ea2(void)

{
  func_0xc24c46(4,3,3);
  return;
}



/* ===== c25eb2 gap_c25eb2 size=246 ===== */

void gap_c25eb2(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  char cVar5;
  
  func_0xc25fa8();
  func_0xc25fd8();
  func_0xc26008();
  func_0xc26026();
  uVar1 = UNK_00cc15;
  gap_c24cb4(uVar1,uRame008d8,uRame00c1e,(short)&UNK_00cc18,(short)&UNK_00cc1c);
  uVar1 = UNK_00cc1f;
  gap_c24cb4(uVar1,uRame008d9,uRame00c1a,(short)&UNK_00cc20,(short)&UNK_00cc22);
  uVar2 = Ram00cc18;
  uVar3 = Ram00cc1c;
  gap_c24d1c(uVar2,uVar3,uRamc07d60,uRamc07d62,(short)&UNK_00cc15,(short)&UNK_00cc25);
  uVar2 = Ram00cc20;
  uVar3 = Ram00cc22;
  gap_c24d1c(uVar2,uVar3,uRamc07d5c,uRamc07d5e,(short)&UNK_00cc1f,(short)&UNK_00cc24);
  uVar1 = UNK_00cc15;
  uVar4 = UNK_00cc25;
  func_0xc24d82(4,uVar1,uVar4);
  uVar1 = UNK_00cc1f;
  uVar4 = UNK_00cc24;
  func_0xc24d82(3,uVar1,uVar4);
  cVar5 = func_0xc24530(4);
  if ((cVar5 == '\0') && (cVar5 = func_0xc24530(3), cVar5 == '\0')) {
    UNK_00cc16 = 0;
  }
  else {
    UNK_00cc16 = 1;
  }
  cVar5 = UNK_00cc1e;
  if ((cVar5 == '\0') && (cVar5 = UNK_00cc1a, cVar5 == '\0')) {
    UNK_00cc14 = 0;
    return;
  }
  UNK_00cc14 = 1;
  return;
}



/* ===== c26064 gap_c26064 size=34 ===== */

void gap_c26064(void)

{
  Ram00cc34 = 0;
  Ram00cc2e = 0;
  Ram00cc28 = 0;
  Ram00cc30 = 0;
  UNK_00cc33 = 0;
  UNK_00cc2a = 0;
  UNK_00cc36 = 0;
  UNK_00cc37 = 0;
  return;
}



/* ===== c26086 gap_c26086 size=46 ===== */

void gap_c26086(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00c936;
  uVar1 = axis16_signed(0x7a92,uVar1);
  uRame008da = tbl16_interp(0x7d88,0xc0,uVar1);
  func_0xc24c46(6,5,6);
  return;
}



/* ===== c260b4 gap_c260b4 size=36 ===== */

void gap_c260b4(void)

{
  undefined2 uVar1;
  
  uVar1 = DAT_00c936;
  uVar1 = axis16_signed(0x7a92,uVar1);
  uRame008da = tbl16_interp(0x7d88,0xc0,uVar1);
  return;
}



/* ===== c260d8 gap_c260d8 size=314 ===== */

void gap_c260d8(void)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  char cVar5;
  
  func_0xc26212();
  FUN_c19846();
  uVar2 = UNK_00cc2a;
  gap_c24cb4(uVar2,uRame008df,cRame008dd,(short)&UNK_00cc34,(short)&UNK_00cc2e);
  uVar2 = UNK_00cc37;
  gap_c24cb4(uVar2,uRame008de,cRame008dc,(short)&UNK_00cc28,(short)&UNK_00cc30);
  uVar3 = Ram00cc34;
  uVar1 = Ram00cc2e;
  gap_c24d1c(uVar3,uVar1,uRamc07d7c,uRamc07d7e,(short)&UNK_00cc2a,(short)&UNK_00cc33);
  uVar1 = Ram00cc28;
  uVar3 = Ram00cc30;
  gap_c24d1c(uVar1,uVar3,uRamc07d78,uRamc07d7a,(short)&UNK_00cc37,(short)&UNK_00cc36);
  uVar2 = UNK_00cc2a;
  uVar4 = UNK_00cc33;
  func_0xc24d82(6,uVar2,uVar4);
  uVar4 = UNK_00cc37;
  uVar2 = UNK_00cc36;
  func_0xc24d82(5,uVar4,uVar2);
  cVar5 = func_0xc24530(6);
  if ((((cVar5 == '\0') && (cVar5 = func_0xc24530(5), cVar5 == '\0')) && (cRame008dd == '\0')) &&
     (cRame008dc == '\0')) {
    UNK_00cc38 = 0;
  }
  else {
    UNK_00cc38 = 1;
  }
  cVar5 = func_0xc24530(6);
  if ((cVar5 == '\0') && (cVar5 = func_0xc24530(5), cVar5 == '\0')) {
    UNK_00cc32 = 0;
    UNK_00cc2b = 0;
  }
  else {
    UNK_00cc32 = 1;
    UNK_00cc2b = 1;
  }
  if ((cRame008dd == '\0') && (cRame008dc == '\0')) {
    UNK_00cc2c = 0;
    return;
  }
  UNK_00cc2c = 1;
  return;
}



/* ===== c263b2 gap_c263b2 size=26 ===== */

void gap_c263b2(void)

{
  Ram00cc46 = 0;
  Ram00cc3e = 0;
  Ram00cc42 = 0;
  UNK_00cc40 = 0;
  UNK_00cc3d = 0;
  UNK_00cc48 = 0;
  return;
}



/* ===== c263cc gap_c263cc size=12 ===== */

void gap_c263cc(void)

{
  func_0xc24c46(10,9,7);
  return;
}



/* ===== c264ee gap_c264ee size=152 ===== */

void gap_c264ee(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined1 auStack_a [2];
  undefined1 auStack_8 [8];
  
  func_0xc263d8();
  func_0xc263ee();
  uVar2 = UNK_00cc3d;
  uVar1 = UNK_00cc3c;
  func_0xc24cdc(uVar2,uVar1,uRame008e0,uRame008e1);
  *(undefined2 *)((uint3)((ushort)auStack_8 & 0x3fff) + 0xc04000) = uRamc07db4;
  *(undefined2 *)((uint3)((ushort)auStack_a & 0x3fff) + 0xc04000) = uRamc07db0;
  uVar5 = Ram00cc46;
  uVar4 = Ram00cc42;
  uVar3 = Ram00cc3e;
  func_0xc24d40(uVar5,uVar4,uVar3,uRamc07db2);
  uVar1 = UNK_00cc48;
  uVar1 = UNK_00cc3d;
  uVar2 = UNK_00cc40;
  func_0xc24dd0(10,9,uVar1,uVar2);
  func_0xc26446();
  return;
}



/* ===== c26586 gap_c26586 size=36 ===== */

void gap_c26586(void)

{
  undefined1 uVar1;
  char cVar2;
  
  cVar2 = FUN_c243a8(0x10);
  if ((cVar2 == '\0') && (cVar2 = FUN_c243a8(0x11), cVar2 == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  UNK_00cc54 = uVar1;
  return;
}



/* ===== c265aa gap_c265aa size=32 ===== */

void gap_c265aa(void)

{
  undefined1 uVar1;
  char cVar2;
  
  cVar2 = FUN_c243a8(0xe);
  if ((cVar2 == '\0') && (cVar2 = FUN_c243a8(0xf), cVar2 == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  UNK_00cc56 = uVar1;
  return;
}



/* ===== c265ca gap_c265ca size=36 ===== */

void gap_c265ca(void)

{
  undefined1 uVar1;
  char cVar2;
  
  cVar2 = FUN_c243a8(0x21);
  if ((cVar2 == '\0') && (cVar2 = FUN_c243a8(0x22), cVar2 == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  UNK_00cc58 = uVar1;
  return;
}



/* ===== c265ee gap_c265ee size=18 ===== */

void gap_c265ee(ushort param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = DAT_00c962;
  uVar2 = DAT_00c962;
  if (param_1 != uVar2 && uVar1 <= param_1) {
    *(undefined1 *)(uint3)param_2 = 0;
    return;
  }
  *(undefined1 *)(uint3)param_2 = 1;
  return;
}



/* ===== c26600 gap_c26600 size=58 ===== */

void gap_c26600(char param_1,ushort param_2,ushort param_3,short param_4,char unaff_00000000,
               char unaff_00000002)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  
  uVar1 = Ram00c072;
  if ((param_3 < uVar1) && (param_1 != '\0')) {
    sVar3 = DAT_00c936;
    sVar4 = DAT_00c936;
    if (((param_4 - sVar4 < 0 != SBORROW2(param_4,sVar3)) &&
        (((unaff_00000000 == '\0' || ((unaff_00000000 == '\x01' && (unaff_00000002 == '\0')))) &&
         (cVar2 = DAT_00c784, cVar2 == '\0')))) && (cVar2 = DAT_00c81c, cVar2 == '\0')) {
      *(undefined1 *)(uint3)param_2 = 1;
      return;
    }
  }
  *(undefined1 *)(uint3)param_2 = 0;
  return;
}



/* ===== c2663a gap_c2663a size=70 ===== */

void gap_c2663a(char param_1,ushort param_2,ushort param_3,ushort param_4,ushort unaff_00000000,
               ushort unaff_00000002,ushort unaff_00000004)

{
  if (param_1 != '\x01') {
    *(undefined1 *)(uint3)param_3 = 0;
    *(undefined1 *)(uint3)param_4 = 0;
    if ((*(char *)(uint3)param_2 == '\x01') && (unaff_00000000 < unaff_00000004)) {
      *(undefined1 *)(uint3)param_2 = 0;
    }
    return;
  }
  if (unaff_00000000 < unaff_00000002) {
    *(undefined1 *)(uint3)param_3 = 1;
  }
  else {
    if (unaff_00000004 < unaff_00000000) {
      *(undefined1 *)(uint3)param_3 = 0;
      *(undefined1 *)(uint3)param_4 = 1;
      return;
    }
    *(undefined1 *)(uint3)param_3 = 0;
  }
  *(undefined1 *)(uint3)param_4 = 0;
  return;
}



/* ===== c26680 gap_c26680 size=46 ===== */

void gap_c26680(void)

{
  func_0xc24c46(0x17,0x18,0x10);
  uRame008e4 = Ram00c99a;
  if (uRamc07df0 < uRame008e4) {
    UNK_00cc5a = 1;
  }
  return;
}



/* ===== c266ae gap_c266ae size=46 ===== */

void gap_c266ae(void)

{
  UNK_00cc65 = 0;
  UNK_00cc5b = 0;
  UNK_00cc5c = 0;
  UNK_00cc62 = 0;
  UNK_00cc64 = 0;
  Ram00cc60 = 0;
  Ram00cc5e = 0;
  Ram00cc66 = 0;
  UNK_00cc5a = 0;
  UNK_00cc5d = 0;
  UNK_00cc63 = 0;
  return;
}



/* ===== c266dc gap_c266dc size=34 ===== */

void gap_c266dc(void)

{
  uRame008e4 = rate_limit(uRame008e4,uRame0099a,uRamc07de6);
  return;
}



/* ===== c266fe gap_c266fe size=246 ===== */

void gap_c266fe(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  undefined1 auStack_a [2];
  undefined1 auStack_8 [2];
  undefined1 auStack_6 [2];
  undefined1 auStack_4 [2];
  undefined1 auStack_2 [2];
  
  gap_c265ee(uRamc07de8,(short)&UNK_00cc65);
  uVar1 = DAT_00cad6;
  uVar1 = DAT_00cac5;
  uVar1 = UNK_00cc65;
  gap_c26600(uVar1,(short)&UNK_00cc5b,uRamc07dec,uRamc07dea);
  *(undefined2 *)((uint3)((ushort)auStack_2 & 0x3fff) + 0xc04000) = uRamc07df0;
  *(undefined2 *)((uint3)((ushort)auStack_4 & 0x3fff) + 0xc04000) = uRamc07dee;
  *(undefined2 *)((uint3)((ushort)auStack_6 & 0x3fff) + 0xe00000) = uRame008e4;
  uVar1 = UNK_00cc5b;
  gap_c2663a(uVar1,(short)&UNK_00cc5a,(short)&UNK_00cc5c,(short)&UNK_00cc62);
  uVar6 = UNK_00cc64;
  uVar1 = UNK_00cc5b;
  uVar2 = UNK_00cc5c;
  uVar5 = UNK_00cc62;
  func_0xc24cdc(uVar6,uVar1,uVar2,uVar5);
  *(undefined2 *)((uint3)((ushort)auStack_8 & 0x3fff) + 0xc04000) = uRamc07df6;
  *(undefined2 *)((uint3)((ushort)auStack_a & 0x3fff) + 0xc04000) = uRamc07df4;
  uVar3 = Ram00cc5e;
  uVar4 = Ram00cc60;
  uVar7 = Ram00cc66;
  func_0xc24d40(uVar3,uVar4,uVar7,uRamc07df2);
  uVar1 = UNK_00cc63;
  uVar2 = UNK_00cc64;
  uVar1 = UNK_00cc5d;
  func_0xc24dd0(0x17,0x18,uVar2,uVar1);
  return;
}



/* ===== c267f4 gap_c267f4 size=46 ===== */

void gap_c267f4(void)

{
  func_0xc24c46(0x1f,0x20,0x14);
  uRame008e6 = Ram00cafa;
  if (uRamc07e0a < uRame008e6) {
    UNK_00cc68 = 1;
  }
  return;
}



/* ===== c26822 gap_c26822 size=46 ===== */

void gap_c26822(void)

{
  UNK_00cc74 = 0;
  UNK_00cc6c = 0;
  UNK_00cc75 = 0;
  UNK_00cc76 = 0;
  UNK_00cc6d = 0;
  Ram00cc72 = 0;
  Ram00cc6a = 0;
  Ram00cc70 = 0;
  UNK_00cc68 = 0;
  UNK_00cc69 = 0;
  UNK_00cc6e = 0;
  return;
}



/* ===== c26850 gap_c26850 size=34 ===== */

void gap_c26850(void)

{
  uRame008e6 = rate_limit(uRame008e6,uRame00afa,uRamc07e00);
  return;
}



/* ===== c26872 gap_c26872 size=246 ===== */

void gap_c26872(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 auStack_a [2];
  undefined1 auStack_8 [2];
  undefined1 auStack_6 [2];
  undefined1 auStack_4 [2];
  undefined1 auStack_2 [2];
  
  gap_c265ee(uRamc07e02,(short)&UNK_00cc74);
  uVar1 = DAT_00cad7;
  uVar1 = DAT_00cac6;
  uVar1 = UNK_00cc74;
  gap_c26600(uVar1,(short)&UNK_00cc6c,uRamc07e06,uRamc07e04);
  *(undefined2 *)((uint3)((ushort)auStack_2 & 0x3fff) + 0xc04000) = uRamc07e0a;
  *(undefined2 *)((uint3)((ushort)auStack_4 & 0x3fff) + 0xc04000) = uRamc07e08;
  *(undefined2 *)((uint3)((ushort)auStack_6 & 0x3fff) + 0xe00000) = uRame008e6;
  uVar1 = UNK_00cc6c;
  gap_c2663a(uVar1,(short)&UNK_00cc68,(short)&UNK_00cc75,(short)&UNK_00cc76);
  uVar3 = UNK_00cc6d;
  uVar1 = UNK_00cc6c;
  uVar6 = UNK_00cc75;
  uVar7 = UNK_00cc76;
  func_0xc24cdc(uVar3,uVar1,uVar6,uVar7);
  *(undefined2 *)((uint3)((ushort)auStack_8 & 0x3fff) + 0xc04000) = uRamc07e10;
  *(undefined2 *)((uint3)((ushort)auStack_a & 0x3fff) + 0xc04000) = uRamc07e0e;
  uVar2 = Ram00cc6a;
  uVar5 = Ram00cc72;
  uVar4 = Ram00cc70;
  func_0xc24d40(uVar2,uVar5,uVar4,uRamc07e0c);
  uVar1 = UNK_00cc6e;
  uVar3 = UNK_00cc6d;
  uVar1 = UNK_00cc69;
  func_0xc24dd0(0x1f,0x20,uVar3,uVar1);
  return;
}



/* ===== c26968 gap_c26968 size=12 ===== */

void gap_c26968(void)

{
  gap_c24c2a(0x16,0xf);
  return;
}



/* ===== c26974 gap_c26974 size=42 ===== */

void gap_c26974(void)

{
  uRame008ea = 0;
  uRame00c86 = 0;
  Ram00cc7c = 0;
  uRame008e8 = 0;
  uRame00c85 = 0;
  Ram00cc7a = 0;
  UNK_00cc7f = 0;
  UNK_00cc82 = 0;
  return;
}



/* ===== c2699e gap_c2699e size=88 ===== */

undefined1 gap_c2699e(void)

{
  ushort uVar1;
  short sVar2;
  
  uVar1 = DAT_00c06a;
  if ((((uRamc07e20 <= uVar1) && (uVar1 = Ram00c072, uRamc07e26 <= uVar1)) &&
      (sVar2 = Ram00c94e, sRamc07e28 <= sVar2)) &&
     (((uVar1 = DAT_00c962, uRamc07e30 <= uVar1 && (uVar1 <= uRamc07e2e)) &&
      (sVar2 = DAT_00c936, sRamc07e22 <= sVar2)))) {
    return 1;
  }
  return 0;
}



/* ===== c269f6 gap_c269f6 size=68 ===== */

void gap_c269f6(void)

{
  ushort uVar1;
  char cVar2;
  
  cVar2 = UNK_00cc7e;
  if (((cVar2 == '\0') && (cVar2 = gap_c2699e(), cVar2 == '\x01')) &&
     (cVar2 = UNK_00cc80, cVar2 == '\0')) {
    uVar1 = Ram00cc78;
    if (uRamc07e24 <= uVar1) {
      UNK_00cc84 = 0;
      UNK_00cc83 = 1;
      return;
    }
    UNK_00cc84 = 1;
  }
  else {
    UNK_00cc84 = 0;
    Ram00cc78 = 0;
  }
  UNK_00cc83 = 0;
  return;
}



/* ===== c26a3a gap_c26a3a size=48 ===== */

void gap_c26a3a(void)

{
  char cVar1;
  
  if ((cRamc07e1a == '\0') &&
     ((((cVar1 = UNK_00c848, cVar1 != '\0' || (cVar1 = UNK_00c912, cVar1 != '\0')) ||
       (cVar1 = UNK_00c90a, cVar1 != '\0')) || (cVar1 = UNK_00c90e, cVar1 != '\0')))) {
    UNK_00cc80 = 1;
    return;
  }
  UNK_00cc80 = 0;
  return;
}



/* ===== c26a6a gap_c26a6a size=52 ===== */

void gap_c26a6a(void)

{
  char cVar1;
  
  cVar1 = UNK_00cc83;
  if (cVar1 != '\x01') {
    uRame008ea = 0;
    return;
  }
  uRame008ea = rate_limit(uRame008ea,uRame00890,uRamc07e1c);
  return;
}



/* ===== c26a9e gap_c26a9e size=40 ===== */

void gap_c26a9e(void)

{
  char cVar1;
  
  cVar1 = UNK_00cc83;
  if ((cVar1 == '\x01') && (uRame008ea <= uRamc07e1e)) {
    UNK_00cc81 = 1;
    return;
  }
  UNK_00cc81 = 0;
  return;
}



/* ===== c26ac6 gap_c26ac6 size=62 ===== */

void gap_c26ac6(void)

{
  ushort uVar1;
  
  uVar1 = Ram00cc7a;
  if (uVar1 < uRamc07e2a) {
    uVar1 = Ram00cc7c;
    if (uVar1 < uRamc07e2c) {
      UNK_00cc82 = 0;
      return;
    }
    uRame008e8 = 0;
  }
  else {
    uRame008e8 = 1;
  }
  UNK_00cc82 = 1;
  return;
}



/* ===== c26b04 gap_c26b04 size=106 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c26b04(void)

{
  char cVar1;
  
  cVar1 = UNK_00cc81;
  if (((((cVar1 == '\0') && (cVar1 = UNK_00cc82, cVar1 == '\0')) && (_DAT_e008ac == 0)) &&
      ((DAT_e0089e == '\0' && (DAT_e00846 == '\0')))) && (cVar1 = UNK_00cc83, cVar1 == '\x01')) {
    UNK_00cc85 = 1;
  }
  else {
    UNK_00cc85 = 0;
    Ram00cc7a = 0;
  }
  cVar1 = UNK_00cc81;
  if (((cVar1 == '\x01') && (cVar1 = UNK_00cc83, cVar1 == '\x01')) &&
     (cVar1 = UNK_00cc82, cVar1 == '\0')) {
    UNK_00cc86 = 1;
    return;
  }
  UNK_00cc86 = 0;
  Ram00cc7c = 0;
  return;
}



/* ===== c26b6e gap_c26b6e size=60 ===== */

void gap_c26b6e(void)

{
  undefined1 uVar1;
  
  func_0xc159bc((short)&UNK_00cc78,(short)&UNK_00cc84,3);
  gap_c269f6();
  gap_c26a6a();
  gap_c26a9e();
  gap_c26b04();
  gap_c26ac6();
  uVar1 = UNK_00cc82;
  gap_c24d9a(0x16,uVar1,uRame008e8,(short)&UNK_00cc7f);
  return;
}



/* ===== c26baa gap_c26baa size=64 ===== */

void gap_c26baa(void)

{
  char cVar1;
  ushort uVar2;
  
  uVar2 = 0x7a9c;
  do {
    if (0x26 < *(short *)(uint3)uVar2) {
      UNK_00cc7e = 0;
LAB_c26be0:
      gap_c26a3a();
      return;
    }
    cVar1 = func_0xc24530(*(undefined2 *)(uint3)uVar2);
    if ((cVar1 != '\0') && (cVar1 = func_0xc24e0a(*(undefined2 *)(uint3)uVar2), cVar1 == '\0')) {
      UNK_00cc7e = 1;
      goto LAB_c26be0;
    }
    uVar2 = uVar2 + 2;
  } while( true );
}



/* ===== c26bea gap_c26bea size=42 ===== */

void gap_c26bea(void)

{
  func_0xc24c46(0x19,0x1a,0x11);
  func_0xc26caa();
  uRame008ee = DAT_00c962;
  uRame00c8b = 0;
  UNK_00cc8a = 0;
  return;
}



/* ===== c26c14 gap_c26c14 size=46 ===== */

void gap_c26c14(void)

{
  func_0xc26caa();
  UNK_00cc8d = 0;
  Ram00cc90 = 0;
  UNK_00cc8e = 0;
  Ram00cc92 = 0;
  uRame008f0 = 0;
  uRame008ec = 0;
  uRame00c8b = 0;
  UNK_00cc8a = 0;
  return;
}



/* ===== c26c42 gap_c26c42 size=6 ===== */

void gap_c26c42(void)

{
  func_0xc26caa();
  return;
}



/* ===== c26c48 gap_c26c48 size=98 ===== */

void gap_c26c48(void)

{
  uRame008f1 = 0;
  uRame00c94 = 0;
  uRame008f5 = 0;
  uRame008ed = 0;
  uRame00c96 = 0;
  Ram00cc88 = 0;
  UNK_00cc8c = 0;
  uRame008f4 = 0;
  uRame008ec = 0;
  uRame008f0 = 0;
  uRame008f2 = 0;
  uRame00c8d = 0;
  Ram00cc90 = 0;
  UNK_00cc8e = 0;
  Ram00cc92 = 0;
  UNK_00cc8b = 0;
  UNK_00cc8a = 0;
  return;
}



/* ===== c26cd4 gap_c26cd4 size=102 ===== */

void gap_c26cd4(void)

{
  byte bVar1;
  
  bVar1 = DAT_00c277;
  if (uRame008f2 < bVar1) {
    bVar1 = DAT_00c277;
    uRame008f2 = (ushort)bVar1;
  }
  func_0xc26d9c();
  func_0xc26ed6();
  func_0xc26f24();
  gap_c24d9a(0x1a,uRame008ed,uRame008f5,(short)&UNK_00cc8a);
  bVar1 = DAT_00c280;
  if (0x32 < bVar1) {
    DAT_00c280 = 0;
    DAT_00c277 = 0;
    DAT_00c264 = 0;
    DAT_00c272 = 0;
    uRame008f2 = 0;
  }
  return;
}



/* ===== c26d3a gap_c26d3a size=52 ===== */

void gap_c26d3a(void)

{
  func_0xc159bc((short)&UNK_00cc90,(short)&UNK_00cc8d,2);
  func_0xc26d6e();
  gap_c26dca();
  gap_c24d9a(0x19,uRame008f0,uRame008ec,(short)&UNK_00cc8b);
  return;
}



/* ===== c26dca gap_c26dca size=268 ===== */

void gap_c26dca(void)

{
  undefined2 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  ushort uVar6;
  
  uVar4 = FUN_c1aeac();
  uVar1 = DAT_00c06a;
  uVar5 = FUN_c28852(uVar1,uVar4);
  uVar6 = FUN_c28852(uRame008ee,uRame00962);
  if ((((cRame008f4 == '\0') ||
       ((((cVar2 = DAT_00c93c, cVar2 != '\x04' && (cVar2 != '\x01')) ||
         (cVar2 = UNK_00cc32, cVar2 != '\0')) ||
        ((cVar2 = UNK_00ca18, cVar2 != '\0' || (uVar3 = DAT_00fd00, (uVar3 & 0x2000) != 0)))))) ||
      (uVar5 < uRamc07e3c)) || (uVar6 < uRamc07e40)) {
    UNK_00cc8f = 0;
  }
  else {
    UNK_00cc8f = 1;
  }
  if (cRame008f0 != '\0') {
    cRame008f0 = '\0';
  }
  if (cRame008f4 == '\0') {
    UNK_00cc8d = 0;
    cVar2 = DAT_00c93c;
    if ((cVar2 != '\x03') && (uVar5 = Ram00cc92, uVar5 < uRamc07e42)) {
      UNK_00cc8e = 1;
      return;
    }
    uRame008ec = 0;
    uRame00c8e = 0;
    Ram00cc92 = 0;
  }
  else {
    UNK_00cc8e = 0;
    Ram00cc92 = 0;
    cVar2 = UNK_00cc8f;
    if (cVar2 == '\0') {
      UNK_00cc8d = 0;
      return;
    }
    uVar5 = Ram00cc90;
    if (uVar5 < uRamc07e3e) {
      UNK_00cc8d = 1;
      return;
    }
    uRame008ec = 1;
    uRame00c8d = 0;
  }
  Ram00cc90 = 0;
  cRame008f0 = 1;
  return;
}



/* ===== c2702a gap_c2702a size=26 ===== */

void gap_c2702a(void)

{
  undefined1 uVar1;
  
  uVar1 = func_0xc26f7c((short)&DAT_00c016);
  UNK_00cc98 = uVar1;
  uVar1 = func_0xc26fd2((short)&DAT_00c016);
  UNK_00cc99 = uVar1;
  return;
}



/* ===== c2705e gap_c2705e size=24 ===== */

void gap_c2705e(void)

{
  func_0xc159bc((short)&UNK_00cc9a,(short)&UNK_00cca0,3);
  gap_c2702a();
  gap_c270da();
  return;
}



/* ===== c270da gap_c270da size=94 ===== */

void gap_c270da(void)

{
  ushort uVar1;
  char cVar2;
  
  cVar2 = DAT_00c81c;
  if ((((cVar2 == '\0') || (cVar2 = DAT_00cad6, cVar2 == '\0')) ||
      (cVar2 = FUN_c243a8(0xe), cVar2 != '\0')) ||
     ((cVar2 = FUN_c243a8(0xf), cVar2 != '\0' || (uVar1 = Ram00c99a, uRamc07e4e <= uVar1)))) {
    uRame008f6 = 0;
    Ram00cc9e = 0;
  }
  else {
    uVar1 = Ram00cc9e;
    if (uVar1 < uRamc07e54) {
      uRame008f6 = 0;
      UNK_00cca2 = 1;
    }
    else {
      uRame008f6 = 1;
      UNK_00cca2 = 0;
    }
  }
  return;
}



/* ===== c27142 gap_c27142 size=18 ===== */

void gap_c27142(void)

{
  uRame008f8 = 0;
  uRame008f9 = 0;
  return;
}



/* ===== c27154 gap_c27154 size=14 ===== */

void gap_c27154(void)

{
  gap_c24c2a(0x1e,0x12);
  return;
}



/* ===== c27162 gap_c27162 size=54 ===== */

void gap_c27162(void)

{
  char cVar1;
  
  func_0xc27198();
  func_0xc24d82(0x1e,uRame008f8,uRame008f9);
  cVar1 = func_0xc24530(0x1e);
  if (cVar1 == '\0') {
    UNK_00cca4 = 0;
    return;
  }
  UNK_00cca4 = 1;
  return;
}



/* ===== c271c4 gap_c271c4 size=18 ===== */

void gap_c271c4(void)

{
  func_0xc271dc();
  gap_c24c2a(0x25,0x16);
  return;
}



/* ===== c271d6 gap_c271d6 size=6 ===== */

void gap_c271d6(void)

{
  func_0xc271dc();
  return;
}



/* ===== c27216 gap_c27216 size=828 ===== */

void gap_c27216(void)

{
  short sVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  char cVar6;
  ushort uVar7;
  
  if (sRamc07e74 == 0) {
    cRame00904 = '\0';
  }
  else {
    if (sRamc07e74 != 1) {
      if (sRamc07e74 == 2) {
        cRame008fe = '\x01';
        cRame00904 = '\0';
      }
      else if (sRamc07e74 == 3) {
        cRame00904 = '\x01';
        cRame008fe = '\x01';
      }
      goto LAB_c27272;
    }
    cRame00904 = '\x01';
  }
  cRame008fe = '\0';
LAB_c27272:
  cRame00903 = cRame006fc;
  if ((((cRame006fc == '\0') && (cRame00702 == '\0')) && (cVar6 = UNK_00cc32, cVar6 == '\0')) &&
     (((uVar7 = DAT_00c962, uRamc07e76 <= uVar7 && (uVar7 <= uRamc07e78)) &&
      (sVar1 = DAT_00c936, sRamc07e7a <= sVar1)))) {
    cRame00905 = '\x01';
  }
  else {
    cRame00905 = '\0';
  }
  if (cRame00904 != '\0') {
    if (((cRame00905 == '\0') || (uVar7 = Ram00ca0a, uVar7 <= uRamc07e7c)) ||
       ((uVar7 = DAT_00ca2a, uVar7 < uRamc07e7e ||
        (((uRamc07e80 < uVar7 || (uVar7 = DAT_00c9d0, uVar7 < uRamc07e82)) || (uRamc07e84 < uVar7)))
        ))) {
      cRame00902 = '\0';
    }
    else {
      cRame00902 = '\x01';
    }
    if ((cRame00902 == '\0') ||
       (((cVar6 = func_0xc24530(0x25), cVar6 != '\0' || (uVar7 = Ram00ca3e, uRamc07e86 < uVar7)) &&
        ((cVar6 = func_0xc24530(0x25), cVar6 == '\0' || (uVar7 = Ram00ca3e, uRamc07e88 < uVar7))))))
    {
      uRame008fa = 0;
    }
    else {
      uRame008fa = 1;
    }
    uVar2 = UNK_00ccaa;
    gap_c24cb4(uVar2,cRame00902,uRame008fa,(short)&UNK_00cca8,(short)&UNK_00ccb0);
    uVar4 = Ram00cca8;
    uVar5 = Ram00ccb0;
    gap_c24d1c(uVar4,uVar5,uRamc07e8c,uRamc07e8a,(short)&UNK_00ccaa,(short)&UNK_00ccb2);
    uVar2 = UNK_00ccaa;
    uVar3 = UNK_00ccb2;
    func_0xc24d82(0x25,uVar2,uVar3);
  }
  if (cRame008fe != '\0') {
    if (((cRame00905 == '\0') || (sRame00900 == 0)) ||
       ((uVar7 = Ram00ca0a, uRamc07e8e < uVar7 ||
        (((uVar7 = DAT_00ca2a, uRamc07e90 < uVar7 || (uVar7 = DAT_00c9d0, uVar7 < uRamc07e92)) ||
         (uRamc07e94 < uVar7)))))) {
      cRame00906 = '\0';
    }
    else {
      cRame00906 = '\x01';
    }
    cRame008fb = '\0';
    uRame008fc = 0;
    if (sRame00900 != 0) {
      uVar7 = Ram00ca3e;
      if (uVar7 < uRamc07e96) {
        if (cRame00906 != '\0') {
          uVar7 = FUN_c28852(sRame00900,uRame009d0);
          if (uVar7 < uRamc07e98) {
            uRame008fd = 1;
          }
          else {
            cRame008fb = '\x01';
            uRame008fd = 0;
          }
        }
      }
      else {
        uRame008fd = 0;
        uRame008fc = 1;
      }
    }
    sRame00900 = DAT_00c9d0;
    if ((cRame00ca6 != '\0') || (cRame008fb != '\0')) {
      Ram00ccae = 0;
      Ram00ccac = 0;
    }
    uVar2 = UNK_00cca6;
    gap_c24cb4(uVar2,cRame00906,uRame008fd,(short)&UNK_00ccae,(short)&UNK_00ccac);
    uVar5 = Ram00ccae;
    uVar4 = Ram00ccac;
    gap_c24d1c(uVar5,uVar4,uRamc07e9c,uRamc07e9a,(short)&UNK_00cca6,(short)&UNK_00cca7);
    uVar2 = UNK_00cca6;
    uVar3 = UNK_00cca7;
    func_0xc24d82(0x25,uVar2,uVar3);
  }
  return;
}



/* ===== c2756a gap_c2756a size=6 ===== */

void gap_c2756a(void)

{
  Ram00ccb6 = 0;
  return;
}



/* ===== c27570 gap_c27570 size=50 ===== */

void gap_c27570(void)

{
  short sVar1;
  ushort uVar2;
  
  Ram00c10a = 0;
  Ram00c1be = 0;
  Ram00c1bc = 0;
  Ram00c1c0 = 0;
  Ram00c1c2 = 0;
  uVar2 = 0;
  do {
    sVar1 = uVar2 * 2;
    uVar2 = uVar2 + 1;
    *(undefined2 *)(uint3)(ushort)((short)&UNK_00c1c4 + sVar1) = 0;
  } while (uVar2 < 0xc);
  return;
}



/* ===== c2769c gap_c2769c size=8 ===== */

void gap_c2769c(void)

{
  UNK_00ccb4 = 1;
  return;
}



/* ===== c276ba FUN_c276ba size=54 ===== */

short FUN_c276ba(ushort param_1,ushort param_2)

{
  short sVar1;
  short sVar2;
  
  sVar2 = param_1 + param_2;
  sVar1 = ((short)param_2 >> 0xf) + (ushort)CARRY2(param_1,param_2);
  if (sVar1 < (short)(ushort)(sVar2 != -1)) {
    if (sVar1 == 0 && sVar2 == 0 || sVar1 < 0) {
      sVar2 = 0;
    }
  }
  else {
    sVar2 = -1;
  }
  return sVar2;
}



/* ===== c276f0 gap_c276f0 size=72 ===== */

ushort gap_c276f0(ushort param_1,ushort param_2)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar3 = param_1 + param_2;
  sVar1 = ((short)param_1 >> 0xf) + ((short)param_2 >> 0xf) + (ushort)CARRY2(param_1,param_2);
  if (sVar1 < (short)(ushort)(uVar3 < 0x7fff)) {
    uVar2 = (ushort)(uVar3 < 0x8000);
    if (sVar1 + 1U == uVar2 && uVar3 == 0x8000 ||
        (short)((sVar1 + 1U) - uVar2) < 0 !=
        (SBORROW2(sVar1,-1) != SBORROW2(sVar1 + 1,(ushort)(uVar3 < 0x8000)))) {
      uVar3 = 0x8000;
    }
  }
  else {
    uVar3 = 0x7fff;
  }
  return uVar3;
}



/* ===== c27738 gap_c27738 size=28 ===== */

undefined4 gap_c27738(ushort param_1,short param_2,ushort param_3,ushort param_4)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = param_1 + param_3;
  uVar2 = param_2 + param_4 + (ushort)CARRY2(param_1,param_3);
  if (uVar2 < param_4 || uVar2 == param_4 && uVar1 < param_3) {
    uVar1 = 0xffff;
    uVar2 = 0xffff;
  }
  return CONCAT22(uVar2,uVar1);
}



/* ===== c27776 gap_c27776 size=60 ===== */

undefined4 gap_c27776(ushort param_1,short param_2,ushort param_3,short param_4)

{
  short sVar1;
  short sVar2;
  
  sVar1 = param_1 + param_3;
  sVar2 = param_2 + param_4 + (ushort)CARRY2(param_1,param_3);
  if (((-1 < sVar2) && (param_4 < 0)) && (param_2 < 0)) {
    sVar1 = 0;
    sVar2 = -0x8000;
  }
  if (((sVar2 < 0) && (-1 < param_4)) && (-1 < param_2)) {
    sVar1 = -1;
    sVar2 = 0x7fff;
  }
  return CONCAT22(sVar2,sVar1);
}



/* ===== c277b2 gap_c277b2 size=80 ===== */

ushort gap_c277b2(ushort param_1,ushort param_2,short param_3)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  
  sVar4 = 0;
  while (bVar1 = param_3 != 0, param_3 = param_3 + -1, bVar1) {
    bVar1 = CARRY2(param_1,param_1);
    param_1 = param_1 * 2;
    sVar4 = sVar4 * 2 + (ushort)bVar1;
  }
  uVar3 = param_1 + param_2;
  sVar4 = sVar4 + ((short)param_2 >> 0xf) + (ushort)CARRY2(param_1,param_2);
  if (sVar4 < (short)(ushort)(uVar3 < 0x7fff)) {
    uVar2 = (ushort)(uVar3 < 0x8000);
    if (sVar4 + 1U == uVar2 && uVar3 == 0x8000 ||
        (short)((sVar4 + 1U) - uVar2) < 0 !=
        (SBORROW2(sVar4,-1) != SBORROW2(sVar4 + 1,(ushort)(uVar3 < 0x8000)))) {
      uVar3 = 0x8000;
    }
  }
  else {
    uVar3 = 0x7fff;
  }
  return uVar3;
}



/* ===== c27bf8 gap_c27bf8 size=172 ===== */

ushort gap_c27bf8(short param_1,ushort param_2)

{
  bool bVar1;
  short sVar2;
  short extraout_r1;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  
  uVar6 = param_1 + 2 + (param_2 >> 8) * 2;
  uVar5 = *(ushort *)(uint3)uVar6;
  if ((param_2 & 0xff) != 0) {
    uVar6 = *(ushort *)(uVar6 + 2);
    sVar3 = uVar6 - uVar5;
    sVar2 = (((short)uVar6 >> 0xf) - ((short)uVar5 >> 0xf)) - (ushort)(uVar6 < uVar5);
    sVar4 = sVar2;
    if (sVar2 < 0) {
      bVar1 = sVar3 != 0;
      sVar3 = -sVar3;
      sVar4 = -(sVar2 + (ushort)bVar1);
    }
    uVar7 = mul32(sVar3,sVar4,8);
    sVar3 = extraout_r1;
    while( true ) {
      sVar4 = (short)uVar7;
      bVar1 = sVar3 == 0;
      sVar3 = sVar3 + -1;
      if (bVar1) break;
      uVar7 = uVar7 >> 1;
    }
    if (sVar2 < 0) {
      sVar4 = -sVar4;
    }
    uVar5 = uVar5 + sVar4;
  }
  return uVar5;
}



/* ===== c27ca4 tbl16_interp size=168 ===== */

ushort tbl16_interp(short param_1,ushort param_2)

{
  bool bVar1;
  short sVar2;
  short extraout_r1;
  short sVar3;
  short sVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  
  uVar6 = param_1 + 2 + (param_2 >> 8) * 2;
  uVar5 = *(ushort *)(uint3)uVar6;
  if ((param_2 & 0xff) != 0) {
    uVar6 = *(ushort *)(uVar6 + 2);
    sVar3 = uVar6 - uVar5;
    sVar2 = -(ushort)(uVar6 < uVar5);
    sVar4 = sVar2;
    if (sVar2 < 0) {
      bVar1 = sVar3 != 0;
      sVar3 = -sVar3;
      sVar4 = -(sVar2 + (ushort)bVar1);
    }
    uVar7 = mul32(sVar3,sVar4,8);
    sVar3 = extraout_r1;
    while( true ) {
      sVar4 = (short)uVar7;
      bVar1 = sVar3 == 0;
      sVar3 = sVar3 + -1;
      if (bVar1) break;
      uVar7 = uVar7 >> 1;
    }
    if (sVar2 < 0) {
      sVar4 = -sVar4;
    }
    uVar5 = uVar5 + sVar4;
  }
  return uVar5;
}



/* ===== c27f0e gap_c27f0e size=188 ===== */

ushort gap_c27f0e(short param_1,ushort param_2)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  
  sVar6 = 8 - (ushort)*(byte *)(uint3)(param_1 + 1);
  uVar5 = param_1 + 2 + (param_2 >> 8);
  uVar2 = (ushort)*(char *)(uint3)uVar5;
  uVar3 = uVar2;
  sVar4 = sVar6;
  while (bVar1 = sVar4 != 0, sVar4 = sVar4 + -1, bVar1) {
    uVar3 = uVar3 * 2;
  }
  if ((param_2 & 0xff) != 0) {
    sVar6 = 8 - sVar6;
    uVar5 = (ushort)*(char *)(uint3)(uVar5 + 1);
    iVar7 = mul32(uVar5 - uVar2,
                  (((short)uVar5 >> 0xf) - ((short)uVar2 >> 0xf)) - (ushort)(uVar5 < uVar2));
    if (iVar7 < 0) {
      uVar5 = -(short)iVar7;
      sVar4 = -((short)((uint)iVar7 >> 0x10) + (ushort)((short)iVar7 != 0));
      while (bVar1 = sVar6 != 0, sVar6 = sVar6 + -1, bVar1) {
        uVar5 = uVar5 >> 1 | sVar4 << 0xf;
        sVar4 = sVar4 >> 1;
      }
      sVar4 = -uVar5;
    }
    else {
      while( true ) {
        sVar4 = (short)iVar7;
        bVar1 = sVar6 == 0;
        sVar6 = sVar6 + -1;
        if (bVar1) break;
        iVar7 = iVar7 >> 1;
      }
    }
    uVar3 = uVar3 + sVar4;
  }
  return uVar3;
}



/* ===== c27fca tbl8_interp size=182 ===== */

ushort tbl8_interp(short param_1,ushort param_2)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  
  sVar6 = 8 - (ushort)*(byte *)(uint3)(param_1 + 1);
  uVar5 = param_1 + 2 + (param_2 >> 8);
  uVar2 = (ushort)*(byte *)(uint3)uVar5;
  uVar3 = uVar2;
  sVar4 = sVar6;
  while (bVar1 = sVar4 != 0, sVar4 = sVar4 + -1, bVar1) {
    uVar3 = uVar3 * 2;
  }
  if ((param_2 & 0xff) != 0) {
    sVar6 = 8 - sVar6;
    uVar5 = (ushort)*(byte *)(uint3)(uVar5 + 1);
    iVar7 = mul32(uVar5 - uVar2,-(ushort)(uVar5 < uVar2));
    if (iVar7 < 0) {
      uVar5 = -(short)iVar7;
      sVar4 = -((short)((uint)iVar7 >> 0x10) + (ushort)((short)iVar7 != 0));
      while (bVar1 = sVar6 != 0, sVar6 = sVar6 + -1, bVar1) {
        uVar5 = uVar5 >> 1 | sVar4 << 0xf;
        sVar4 = sVar4 >> 1;
      }
      sVar4 = -uVar5;
    }
    else {
      while( true ) {
        sVar4 = (short)iVar7;
        bVar1 = sVar6 == 0;
        sVar6 = sVar6 + -1;
        if (bVar1) break;
        iVar7 = iVar7 >> 1;
      }
    }
    uVar3 = uVar3 + sVar4;
  }
  return uVar3;
}



/* ===== c2826e tbl2d_interp size=482 ===== */

ushort tbl2d_interp(ushort param_1,short param_2,ushort param_3,ushort param_4)

{
  bool bVar1;
  ushort uVar2;
  short extraout_r1;
  ushort uVar3;
  short extraout_r1_00;
  short extraout_r2;
  short extraout_r3;
  short sVar4;
  short sVar5;
  short sVar6;
  ushort uVar7;
  short sVar8;
  ushort uVar9;
  int iVar10;
  
  sVar6 = 8 - (ushort)*(byte *)(uint3)(param_1 + 2);
  uVar2 = (ushort)*(byte *)(uint3)param_1;
  uVar9 = (param_4 >> 8) * uVar2 + (param_3 >> 8);
  uVar7 = param_1 + 3 + uVar9;
  sVar8 = param_2 + (ushort)(0xfffc < param_1) + (ushort)CARRY2(param_1 + 3,uVar9);
  uVar9 = (ushort)*(byte *)(uint3)uVar7;
  sVar5 = sVar6;
  while (bVar1 = sVar5 != 0, sVar5 = sVar5 + -1, bVar1) {
    uVar9 = uVar9 * 2;
  }
  if ((param_3 & 0xff) == 0) {
    sVar5 = 0;
  }
  else {
    iVar10 = mul32();
    sVar5 = extraout_r1;
    if (iVar10 < 0) {
      uVar3 = -(short)iVar10;
      sVar5 = -((short)((uint)iVar10 >> 0x10) + (ushort)((short)iVar10 != 0));
      sVar4 = extraout_r1;
      while (bVar1 = sVar4 != 0, sVar4 = sVar4 + -1, bVar1) {
        uVar3 = uVar3 >> 1 | sVar5 << 0xf;
        sVar5 = sVar5 >> 1;
      }
      sVar4 = -uVar3;
    }
    else {
      while( true ) {
        sVar4 = (short)iVar10;
        bVar1 = sVar5 == 0;
        sVar5 = sVar5 + -1;
        if (bVar1) break;
        iVar10 = iVar10 >> 1;
      }
    }
    uVar9 = uVar9 + sVar4;
    sVar5 = extraout_r3;
  }
  if ((param_4 & 0xff) != 0) {
    sVar8 = sVar8 + (ushort)CARRY2(uVar7,uVar2);
    do {
      bVar1 = sVar6 != 0;
      sVar6 = sVar6 + -1;
    } while (bVar1);
    if (sVar5 != 0) {
      sVar5 = mul32(*(undefined1 *)(uint3)(uVar7 + uVar2),0);
      sVar6 = extraout_r1_00;
      sVar8 = extraout_r2;
      if (sVar5 < 0) {
        do {
          bVar1 = sVar6 != 0;
          sVar6 = sVar6 + -1;
        } while (bVar1);
      }
      else {
        do {
          bVar1 = sVar6 != 0;
          sVar6 = sVar6 + -1;
        } while (bVar1);
      }
    }
    iVar10 = mul32(sVar8);
    if (iVar10 < 0) {
      uVar7 = -(short)iVar10;
      sVar6 = -((short)((uint)iVar10 >> 0x10) + (ushort)((short)iVar10 != 0));
      sVar8 = 8;
      while (bVar1 = sVar8 != 0, sVar8 = sVar8 + -1, bVar1) {
        uVar7 = uVar7 >> 1 | sVar6 << 0xf;
        sVar6 = sVar6 >> 1;
      }
      sVar8 = -uVar7;
    }
    else {
      sVar6 = 8;
      while( true ) {
        sVar8 = (short)iVar10;
        bVar1 = sVar6 == 0;
        sVar6 = sVar6 + -1;
        if (bVar1) break;
        iVar10 = iVar10 >> 1;
      }
    }
    uVar9 = uVar9 + sVar8;
  }
  return uVar9;
}



/* ===== c28450 gap_c28450 size=76 ===== */

ushort gap_c28450(void)

{
  ushort uVar1;
  ushort extraout_r1;
  short extraout_r2;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  undefined4 uVar6;
  
  uVar4 = 0x8000;
  sVar5 = -1;
  uVar6 = mul32();
  sVar3 = (short)((uint)uVar6 >> 0x10);
  uVar2 = (ushort)uVar6;
  if ((short)((sVar3 - extraout_r2) - (ushort)(uVar2 < extraout_r1)) < 0 ==
      (SBORROW2(sVar3,extraout_r2) != SBORROW2(sVar3 - extraout_r2,(ushort)(uVar2 < extraout_r1))))
  {
    uVar2 = 0x7fff;
  }
  else {
    uVar1 = (ushort)(uVar2 < uVar4);
    if (sVar3 - sVar5 == uVar1 && uVar2 == uVar4 ||
        (short)((sVar3 - sVar5) - uVar1) < 0 !=
        (SBORROW2(sVar3,sVar5) != SBORROW2(sVar3 - sVar5,(ushort)(uVar2 < uVar4)))) {
      uVar2 = 0x8000;
    }
  }
  return uVar2;
}



/* ===== c284d8 axis16_signed size=54 ===== */

ushort axis16_signed(ushort param_1,short param_2)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = *(short *)(uint3)(param_1 + 2);
  uVar2 = (*(short *)(uint3)param_1 + -1) * 0x100;
  if (sVar1 < param_2) {
    if (param_2 < *(short *)(uint3)(param_1 + 4)) {
      uVar2 = (ushort)(((uint)(ushort)(param_2 - sVar1) * (uint)uVar2) /
                      (uint)(ushort)(*(short *)(uint3)(param_1 + 4) - sVar1));
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* ===== c2850e axis16_unsigned size=54 ===== */

ushort axis16_unsigned(ushort param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *(ushort *)(uint3)(param_1 + 2);
  uVar2 = (*(short *)(uint3)param_1 + -1) * 0x100;
  if (uVar1 < param_2) {
    if (param_2 < *(ushort *)(uint3)(param_1 + 4)) {
      uVar2 = (ushort)(((uint)(param_2 - uVar1) * (uint)uVar2) /
                      (uint)(*(ushort *)(uint3)(param_1 + 4) - uVar1));
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* ===== c28544 gap_c28544 size=390 ===== */

short gap_c28544(ushort param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  short *psVar3;
  short sVar4;
  short *psVar5;
  short sVar6;
  ushort uVar7;
  undefined1 auStack_2 [2];
  
  uVar2 = param_1 + 2;
  sVar4 = *(short *)(uint3)param_1;
  sVar6 = sVar4 + -7;
  if ((sVar6 < 1) || (*(ushort *)(uint3)(uVar2 + sVar6 * 2) <= *(ushort *)ZEXT23(auStack_2))) {
    if (sVar6 < 1) {
      if (*(ushort *)ZEXT23(auStack_2) <= *(ushort *)(uint3)uVar2) {
        return 0;
      }
      sVar6 = (short)&UNK_00fffa + sVar4;
    }
    if (*(ushort *)(uint3)(uVar2 + (sVar4 + -1) * 2) <= *(ushort *)ZEXT23(auStack_2)) {
      return (sVar4 + -1) * 0x100;
    }
    uVar7 = sVar6 + 4;
  }
  else if (*(ushort *)ZEXT23(auStack_2) < *(ushort *)(param_1 + 0xe)) {
    if (*(ushort *)ZEXT23(auStack_2) <= *(ushort *)(uint3)uVar2) {
      return 0;
    }
    uVar7 = 2;
  }
  else if (*(ushort *)ZEXT23(auStack_2) < *(ushort *)(uint3)(uVar2 + (sVar4 >> 1) * 2)) {
    uVar7 = 8;
    while (*(ushort *)(uint3)(uVar2 + (uVar7 + 3) * 2) <= *(ushort *)ZEXT23(auStack_2)) {
      uVar7 = uVar7 + 5;
    }
  }
  else {
    uVar7 = sVar4 - 9;
    while (*(ushort *)ZEXT23(auStack_2) < *(ushort *)(uint3)(uVar2 + (uVar7 - 3) * 2)) {
      uVar7 = uVar7 - 5;
    }
  }
  psVar5 = (short *)(uVar2 + uVar7 * 2);
  sVar4 = param_2 + (ushort)(0xfffd < param_1) +
          ((short)uVar7 >> 0xf) * 2 + (ushort)CARRY2(uVar7,uVar7) + (ushort)CARRY2(uVar2,uVar7 * 2);
  psVar3 = psVar5;
  uVar2 = uVar7;
  if (*(ushort *)ZEXT23(auStack_2) < *(ushort *)ZEXT23(psVar5)) {
    do {
      uVar7 = uVar7 - 1;
      bVar1 = psVar5 < (short *)0x2;
      psVar5 = psVar5 + -1;
      sVar4 = sVar4 - (ushort)bVar1;
    } while (*(ushort *)ZEXT23(auStack_2) < *(ushort *)ZEXT23(psVar5));
  }
  else {
    do {
      uVar7 = uVar2;
      psVar5 = psVar3;
      psVar3 = psVar5 + 1;
      sVar4 = sVar4 + (ushort)((short *)&UNK_00fffd < psVar5);
      uVar2 = uVar7 + 1;
    } while (*(ushort *)ZEXT23(psVar3) <= *(ushort *)ZEXT23(auStack_2));
    sVar4 = sVar4 - (ushort)(psVar3 < (short *)0x2);
  }
  if (*(short *)ZEXT23(auStack_2) == *(short *)ZEXT23(psVar5)) {
    sVar4 = 0;
  }
  else {
    sVar4 = div32u(sVar4,psVar5[1] - *psVar5);
  }
  return uVar7 * 0x100 + sVar4;
}



/* ===== c286ca gap_c286ca size=392 ===== */

short gap_c286ca(ushort param_1,short param_2)

{
  bool bVar1;
  ushort uVar2;
  undefined2 *puVar3;
  short sVar4;
  undefined2 *puVar5;
  short sVar6;
  ushort uVar7;
  undefined1 auStack_2 [2];
  
  uVar2 = param_1 + 2;
  sVar4 = *(short *)(uint3)param_1;
  sVar6 = sVar4 + -7;
  if ((sVar6 < 1) || (*(short *)(uint3)(uVar2 + sVar6 * 2) <= *(short *)ZEXT23(auStack_2))) {
    if (sVar6 < 1) {
      if (*(short *)ZEXT23(auStack_2) <= *(short *)(uint3)uVar2) {
        return 0;
      }
      sVar6 = (short)&UNK_00fffa + sVar4;
    }
    if (*(short *)(uint3)(uVar2 + (sVar4 + -1) * 2) <= *(short *)ZEXT23(auStack_2)) {
      return (sVar4 + -1) * 0x100;
    }
    uVar7 = sVar6 + 4;
  }
  else if (*(short *)ZEXT23(auStack_2) < *(short *)(param_1 + 0xe)) {
    if (*(short *)ZEXT23(auStack_2) <= *(short *)(uint3)uVar2) {
      return 0;
    }
    uVar7 = 2;
  }
  else if (*(short *)ZEXT23(auStack_2) < *(short *)(uint3)(uVar2 + (sVar4 >> 1) * 2)) {
    uVar7 = 8;
    while (*(short *)(uint3)(uVar2 + (uVar7 + 3) * 2) <= *(short *)ZEXT23(auStack_2)) {
      uVar7 = uVar7 + 5;
    }
  }
  else {
    uVar7 = sVar4 - 9;
    while (*(short *)ZEXT23(auStack_2) < *(short *)(uint3)(uVar2 + (uVar7 - 3) * 2)) {
      uVar7 = uVar7 - 5;
    }
  }
  puVar5 = (undefined2 *)(uVar2 + uVar7 * 2);
  sVar4 = param_2 + (ushort)(0xfffd < param_1) +
          ((short)uVar7 >> 0xf) * 2 + (ushort)CARRY2(uVar7,uVar7) + (ushort)CARRY2(uVar2,uVar7 * 2);
  puVar3 = puVar5;
  uVar2 = uVar7;
  if (*(short *)ZEXT23(auStack_2) < *(short *)ZEXT23(puVar5)) {
    do {
      uVar7 = uVar7 - 1;
      bVar1 = puVar5 < (undefined2 *)0x2;
      puVar5 = puVar5 + -1;
      sVar4 = sVar4 - (ushort)bVar1;
    } while (*(short *)ZEXT23(auStack_2) < *(short *)ZEXT23(puVar5));
  }
  else {
    do {
      uVar7 = uVar2;
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
      sVar4 = sVar4 + (ushort)((undefined2 *)&UNK_00fffd < puVar5);
      uVar2 = uVar7 + 1;
    } while (*(short *)ZEXT23(puVar3) <= *(short *)ZEXT23(auStack_2));
    sVar4 = sVar4 - (ushort)(puVar3 < (undefined2 *)0x2);
  }
  if (*(short *)ZEXT23(auStack_2) - *(short *)ZEXT23(puVar5) == 0) {
    sVar4 = 0;
  }
  else {
    sVar4 = div32u(*puVar5,sVar4,*(short *)ZEXT23(auStack_2) - *(short *)ZEXT23(puVar5));
  }
  return uVar7 * 0x100 + sVar4;
}



/* ===== c28852 FUN_c28852 size=14 ===== */

short FUN_c28852(ushort param_1,ushort param_2)

{
  short sVar1;
  
  if (param_2 < param_1) {
    sVar1 = param_1 - param_2;
  }
  else {
    sVar1 = 0;
  }
  return sVar1;
}



/* ===== c28860 gap_c28860 size=72 ===== */

ushort gap_c28860(ushort param_1,ushort param_2)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  
  uVar3 = param_1 - param_2;
  sVar2 = (((short)param_1 >> 0xf) - ((short)param_2 >> 0xf)) - (ushort)(param_1 < param_2);
  if (sVar2 < (short)(ushort)(uVar3 < 0x7fff)) {
    uVar1 = (ushort)(uVar3 < 0x8000);
    if (sVar2 + 1U == uVar1 && uVar3 == 0x8000 ||
        (short)((sVar2 + 1U) - uVar1) < 0 !=
        (SBORROW2(sVar2,-1) != SBORROW2(sVar2 + 1,(ushort)(uVar3 < 0x8000)))) {
      uVar3 = 0x8000;
    }
  }
  else {
    uVar3 = 0x7fff;
  }
  return uVar3;
}



/* ===== c288a8 gap_c288a8 size=26 ===== */

undefined4 gap_c288a8(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  short sVar1;
  short sVar2;
  
  if (param_4 < param_2 || param_4 == param_2 && param_3 < param_1) {
    sVar1 = param_1 - param_3;
    sVar2 = (param_2 - param_4) - (ushort)(param_1 < param_3);
  }
  else {
    sVar1 = 0;
    sVar2 = 0;
  }
  return CONCAT22(sVar2,sVar1);
}



/* ===== c288c2 gap_c288c2 size=56 ===== */

undefined4 gap_c288c2(ushort param_1,short param_2,ushort param_3,short param_4)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  
  uVar2 = param_1 - param_3;
  sVar3 = (param_2 - param_4) - (ushort)(param_1 < param_3);
  if (param_4 == 0 && param_3 == 0 || param_4 < 0) {
    if ((short)((sVar3 - param_2) - (ushort)(uVar2 < param_1)) < 0 !=
        (SBORROW2(sVar3,param_2) != SBORROW2(sVar3 - param_2,(ushort)(uVar2 < param_1)))) {
      uVar2 = 0xffff;
      sVar3 = 0x7fff;
    }
  }
  else {
    uVar1 = (ushort)(uVar2 < param_1);
    if ((sVar3 - param_2 != uVar1 || uVar2 != param_1) &&
        (short)((sVar3 - param_2) - uVar1) < 0 ==
        (SBORROW2(sVar3,param_2) != SBORROW2(sVar3 - param_2,(ushort)(uVar2 < param_1)))) {
      uVar2 = 0;
      sVar3 = -0x8000;
    }
  }
  return CONCAT22(sVar3,uVar2);
}



/* ===== c289c2 gap_c289c2 size=72 ===== */

ushort gap_c289c2(ushort param_1,ushort param_2,short param_3)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  
  sVar3 = 0;
  while (bVar1 = param_3 != 0, param_3 = param_3 + -1, bVar1) {
    bVar1 = CARRY2(param_2,param_2);
    param_2 = param_2 * 2;
    sVar3 = sVar3 * 2 + (ushort)bVar1;
  }
  uVar4 = param_1 - param_2;
  sVar3 = -(ushort)(param_1 < param_2) - sVar3;
  if (sVar3 < (short)(ushort)(uVar4 < 0x7fff)) {
    uVar2 = (ushort)(uVar4 < 0x8000);
    if (sVar3 + 1U == uVar2 && uVar4 == 0x8000 ||
        (short)((sVar3 + 1U) - uVar2) < 0 !=
        (SBORROW2(sVar3,-1) != SBORROW2(sVar3 + 1,(ushort)(uVar4 < 0x8000)))) {
      uVar4 = 0x8000;
    }
  }
  else {
    uVar4 = 0x7fff;
  }
  return uVar4;
}



/* ===== c28acc gap_c28acc size=132 ===== */

ushort gap_c28acc(ushort param_1,ushort param_2,short param_3,short param_4)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  
  sVar3 = 0;
  while (bVar1 = param_3 != 0, param_3 = param_3 + -1, bVar1) {
    bVar1 = CARRY2(param_2,param_2);
    param_2 = param_2 * 2;
    sVar3 = sVar3 * 2 + (ushort)bVar1;
  }
  uVar5 = param_1 - param_2;
  sVar3 = -(ushort)(param_1 < param_2) - sVar3;
  if (sVar3 < 0) {
    uVar4 = -uVar5;
    uVar2 = -(sVar3 + (ushort)(uVar5 != 0));
    while (bVar1 = param_4 != 0, param_4 = param_4 + -1, bVar1) {
      uVar4 = uVar4 >> 1 | uVar2 << 0xf;
      uVar2 = uVar2 >> 1;
    }
    uVar5 = -uVar4;
    sVar3 = -(uVar2 + (uVar4 != 0));
  }
  else {
    while (bVar1 = param_4 != 0, param_4 = param_4 + -1, bVar1) {
      uVar5 = uVar5 >> 1 | sVar3 << 0xf;
      sVar3 = sVar3 >> 1;
    }
  }
  if (sVar3 < (short)(ushort)(uVar5 < 0x7fff)) {
    uVar2 = (ushort)(uVar5 < 0x8000);
    if (sVar3 + 1U == uVar2 && uVar5 == 0x8000 ||
        (short)((sVar3 + 1U) - uVar2) < 0 !=
        (SBORROW2(sVar3,-1) != SBORROW2(sVar3 + 1,(ushort)(uVar5 < 0x8000)))) {
      uVar5 = 0x8000;
    }
  }
  else {
    uVar5 = 0x7fff;
  }
  return uVar5;
}



/* ===== c28b50 gap_c28b50 size=20 ===== */

void gap_c28b50(ushort param_1,ushort param_2,short param_3)

{
  undefined2 *puVar1;
  
  if (param_3 == 0) {
    return;
  }
  do {
    puVar1 = (undefined2 *)(uint3)param_2;
    param_2 = param_2 + 2;
    *(undefined2 *)(uint3)param_1 = *puVar1;
    param_1 = param_1 + 2;
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return;
}



/* ===== c28b64 mul32 size=36 ===== */

undefined4 mul32(void)

{
  ushort in_r4;
  short in_r5;
  ushort in_r10;
  short in_r11;
  
  __atomic(2);
  __atomic(2);
  __atomic(2);
  return CONCAT22(in_r5 * in_r10 + in_r4 * in_r11 + (short)((uint)in_r4 * (uint)in_r10 >> 0x10),
                  (short)((uint)in_r4 * (uint)in_r10));
}



/* ===== c28b88 gap_c28b88 size=42 ===== */

short gap_c28b88(void)

{
  ushort extraout_r1;
  short sVar1;
  undefined4 uVar2;
  
  uVar2 = div32u();
  sVar1 = (short)((uint)uVar2 >> 0x10);
  if ((extraout_r1 & 0x8000) != 0) {
    sVar1 = -(ushort)((short)uVar2 != 0) - sVar1;
  }
  return sVar1;
}



/* ===== c28bb2 div32u size=148 ===== */

uint div32u(void)

{
  uint uVar1;
  int iVar2;
  short sVar4;
  ushort in_r2;
  short sVar5;
  ushort in_r4;
  ushort uVar6;
  ushort in_r5;
  ushort uVar7;
  ushort in_r10;
  ushort in_r11;
  ushort uVar8;
  ushort uVar3;
  
  if (in_r11 != 0) {
    sVar5 = LZCOUNT(in_r11);
    if (sVar5 == 0) {
      uVar7 = 0;
      uVar6 = in_r5;
      uVar8 = in_r11;
    }
    else {
      sVar4 = -sVar5;
      uVar7 = in_r5 >> sVar4;
      uVar6 = in_r4 >> sVar4 | in_r5 << sVar5;
      uVar8 = in_r11 << sVar5 | in_r10 >> sVar4;
    }
    __atomic(4);
    uVar1 = CONCAT22(uVar7,uVar6) / (uint)uVar8;
    uVar6 = (ushort)uVar1;
    __atomic(2);
    __atomic(2);
    iVar2 = (uVar1 & 0xffff) * (uint)in_r10;
    uVar8 = (ushort)iVar2;
    uVar3 = (ushort)((uint)iVar2 >> 0x10);
    uVar7 = uVar6 * in_r11 + uVar3;
    if ((CARRY2(uVar6 * in_r11,uVar3)) ||
       ((uVar7 - in_r2 != (ushort)(uVar8 < in_r5) || uVar8 != in_r5) &&
        (in_r2 <= uVar7 && (uVar7 != in_r2 || uVar8 >= in_r5)))) {
      uVar6 = uVar6 - 1;
    }
    return (uint)uVar6;
  }
  __atomic(4);
  __atomic(4);
  return CONCAT22(in_r5 / in_r10,
                  (short)(((uint)in_r4 | (uint)in_r5 % (uint)in_r10 << 0x10) / (uint)in_r10));
}



/* ===== c28c46 gap_c28c46 size=8 ===== */

void gap_c28c46(void)

{
  __atomic(3);
  return;
}



/* ===== c28c4e empty_stub_0 size=6 ===== */

void empty_stub_0(void)

{
  return;
}



/* ===== c28c54 gap_c28c54 size=14 ===== */

short gap_c28c54(void)

{
  ushort in_r4;
  short in_r5;
  
  return in_r5 + (ushort)(0xfffd < in_r4);
}



/* ===== c28c62 store32 size=14 ===== */

short store32(void)

{
  ushort in_r4;
  short in_r5;
  undefined2 in_r10;
  undefined2 in_r11;
  
  *(undefined2 *)(uint3)in_r4 = in_r10;
  *(undefined2 *)(uint3)(in_r4 + 2) = in_r11;
  return in_r5 + (ushort)(0xfffd < in_r4);
}



/* ===== c28c70 gap_c28c70 size=22 ===== */

undefined4 gap_c28c70(void)

{
  ushort uVar1;
  ushort in_r4;
  
  uVar1 = *(ushort *)(uint3)((in_r4 >> 0xe) * 2 - 0x200);
  return CONCAT22(uVar1 >> 2,in_r4 & 0x3fff | (uVar1 & 1) << 0xe | ((uVar1 & 2) >> 1) << 0xf);
}



/* ===== c28c9a gap_c28c9a size=10 ===== */

void gap_c28c9a(ushort param_1,ushort param_2,ushort param_3)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  ushort extraout_r1;
  ushort uVar6;
  ushort extraout_r2;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort unaff_r6;
  ushort uVar10;
  ushort unaff_r7;
  ushort uVar11;
  ushort unaff_r8;
  ushort unaff_r9;
  ushort uVar12;
  ushort in_r10;
  undefined4 uVar13;
  
  *(ushort *)(uint3)in_r10 =
       *(ushort *)(uint3)in_r10 & 0x7fff | (*(ushort *)(uint3)in_r10 >> 0xf ^ 1) << 0xf;
  uVar13 = fp_pack();
  uVar4 = (uint)uVar13 >> 0x10;
  if ((extraout_r2 != 0) && (extraout_r1 != 0)) {
    uVar6 = extraout_r1;
    uVar7 = extraout_r2;
    uVar10 = unaff_r6;
    uVar11 = unaff_r8;
    uVar12 = unaff_r9;
    if (extraout_r1 < extraout_r2) {
      uVar13 = CONCAT22(param_3,((ushort)uVar13 & 0xfffb | ((ushort)uVar13 & 1) << 2) >> 1);
      uVar6 = extraout_r2;
      uVar7 = extraout_r1;
      uVar10 = unaff_r7;
      unaff_r7 = unaff_r6;
      uVar11 = param_1;
      uVar12 = param_2;
      param_1 = unaff_r8;
      param_2 = unaff_r9;
      param_3 = (ushort)uVar4;
    }
    uVar9 = (ushort)((uint)uVar13 >> 0x10);
    uVar8 = 0;
    sVar3 = uVar7 - uVar6;
    if (sVar3 != 0) {
      uVar6 = -sVar3;
      uVar7 = uVar10;
      uVar10 = param_1;
      param_1 = param_2;
      if (sVar3 != -0x35 && 0x34 < (ushort)-sVar3) goto LAB_c28c92;
      while (param_2 = param_1, param_1 = uVar10, uVar10 = uVar7, 0xf < (short)uVar6) {
        uVar6 = uVar6 - 0x10;
        uVar8 = param_3;
        uVar7 = 0;
        param_3 = param_2;
      }
      if (uVar6 != 0) {
        uVar8 = uVar8 >> uVar6 | param_3 << -uVar6;
        param_3 = param_3 >> uVar6 | param_2 << -uVar6;
        param_2 = param_2 >> uVar6 | param_1 << -uVar6;
        param_1 = param_1 >> uVar6 | uVar10 << -uVar6;
        uVar10 = uVar10 >> uVar6;
      }
    }
    if (!(bool)((byte)(((ushort)uVar13 & 2) >> 1) ^ (byte)uVar13 & 1)) {
      fp_round();
      return;
    }
    uVar5 = -uVar8;
    bVar1 = uVar9 < param_3 || uVar9 == param_3 && uVar8 != 0;
    uVar8 = (uVar9 - param_3) - (ushort)(uVar8 != 0);
    bVar2 = uVar12 < param_2 || uVar12 == param_2 && bVar1;
    uVar6 = (uVar12 - param_2) - (ushort)bVar1;
    bVar1 = uVar11 < param_1 || uVar11 == param_1 && bVar2;
    uVar7 = (uVar11 - param_1) - (ushort)bVar2;
    uVar11 = (unaff_r7 - uVar10) - (ushort)bVar1;
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0)))) {
      fp_store_zero();
      return;
    }
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0))) ||
        (unaff_r7 < uVar10 || unaff_r7 == uVar10 && bVar1)) {
      uVar9 = ~uVar7;
      uVar10 = (ushort)(0xfffe < ~uVar5);
      uVar7 = (ushort)CARRY2(~uVar8,uVar10);
      uVar12 = (ushort)CARRY2(~uVar6,uVar7);
      uVar6 = ~uVar6 + uVar7;
      uVar7 = uVar9 + uVar12;
      uVar11 = ~uVar11 + (ushort)CARRY2(uVar9,uVar12);
      uVar5 = ~uVar5 + 1;
      uVar8 = ~uVar8 + uVar10;
    }
    while( true ) {
      while (uVar10 = uVar8, uVar8 = uVar5, uVar11 == 0 && uVar7 == 0) {
        uVar5 = 0;
        uVar7 = uVar6;
        uVar6 = uVar10;
      }
      if ((uVar11 & 0x10) != 0) break;
      uVar12 = (ushort)(CARRY2(uVar10,uVar10) || CARRY2(uVar10 * 2,(ushort)CARRY2(uVar8,uVar8)));
      uVar9 = (ushort)(CARRY2(uVar6,uVar6) || CARRY2(uVar6 * 2,uVar12));
      uVar6 = uVar6 * 2 + uVar12;
      uVar12 = uVar7 * 2;
      bVar1 = CARRY2(uVar7,uVar7);
      uVar7 = uVar7 * 2 + uVar9;
      uVar11 = uVar11 * 2 + (ushort)(bVar1 || CARRY2(uVar12,uVar9));
      uVar5 = uVar8 * 2;
      uVar8 = uVar10 * 2 + (ushort)CARRY2(uVar8,uVar8);
    }
    fp_round();
    return;
  }
LAB_c28c92:
  fp_store();
  return;
}



/* ===== c28ca4 fp_div_signed size=28 ===== */

void fp_div_signed(ushort param_1,ushort param_2,ushort param_3)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  ushort extraout_r1;
  ushort uVar6;
  ushort extraout_r2;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort unaff_r6;
  ushort uVar10;
  ushort unaff_r7;
  ushort uVar11;
  ushort unaff_r8;
  ushort unaff_r9;
  ushort uVar12;
  ushort in_r11;
  undefined4 uVar13;
  
  *(ushort *)(uint3)in_r11 =
       *(ushort *)(uint3)in_r11 & 0x7fff | (*(ushort *)(uint3)in_r11 >> 0xf ^ 1) << 0xf;
  uVar13 = fp_pack();
  uVar4 = (uint)uVar13 >> 0x10;
  if ((extraout_r2 != 0) && (extraout_r1 != 0)) {
    uVar6 = extraout_r1;
    uVar7 = extraout_r2;
    uVar10 = unaff_r6;
    uVar11 = unaff_r8;
    uVar12 = unaff_r9;
    if (extraout_r1 < extraout_r2) {
      uVar13 = CONCAT22(param_3,((ushort)uVar13 & 0xfffb | ((ushort)uVar13 & 1) << 2) >> 1);
      uVar6 = extraout_r2;
      uVar7 = extraout_r1;
      uVar10 = unaff_r7;
      unaff_r7 = unaff_r6;
      uVar11 = param_1;
      uVar12 = param_2;
      param_1 = unaff_r8;
      param_2 = unaff_r9;
      param_3 = (ushort)uVar4;
    }
    uVar9 = (ushort)((uint)uVar13 >> 0x10);
    uVar8 = 0;
    sVar3 = uVar7 - uVar6;
    if (sVar3 != 0) {
      uVar6 = -sVar3;
      uVar7 = uVar10;
      uVar10 = param_1;
      param_1 = param_2;
      if (sVar3 != -0x35 && 0x34 < (ushort)-sVar3) goto LAB_c28c92;
      while (param_2 = param_1, param_1 = uVar10, uVar10 = uVar7, 0xf < (short)uVar6) {
        uVar6 = uVar6 - 0x10;
        uVar8 = param_3;
        uVar7 = 0;
        param_3 = param_2;
      }
      if (uVar6 != 0) {
        uVar8 = uVar8 >> uVar6 | param_3 << -uVar6;
        param_3 = param_3 >> uVar6 | param_2 << -uVar6;
        param_2 = param_2 >> uVar6 | param_1 << -uVar6;
        param_1 = param_1 >> uVar6 | uVar10 << -uVar6;
        uVar10 = uVar10 >> uVar6;
      }
    }
    if (!(bool)((byte)(((ushort)uVar13 & 2) >> 1) ^ (byte)uVar13 & 1)) {
      fp_round();
      return;
    }
    uVar5 = -uVar8;
    bVar1 = uVar9 < param_3 || uVar9 == param_3 && uVar8 != 0;
    uVar8 = (uVar9 - param_3) - (ushort)(uVar8 != 0);
    bVar2 = uVar12 < param_2 || uVar12 == param_2 && bVar1;
    uVar6 = (uVar12 - param_2) - (ushort)bVar1;
    bVar1 = uVar11 < param_1 || uVar11 == param_1 && bVar2;
    uVar7 = (uVar11 - param_1) - (ushort)bVar2;
    uVar11 = (unaff_r7 - uVar10) - (ushort)bVar1;
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0)))) {
      fp_store_zero();
      return;
    }
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0))) ||
        (unaff_r7 < uVar10 || unaff_r7 == uVar10 && bVar1)) {
      uVar9 = ~uVar7;
      uVar10 = (ushort)(0xfffe < ~uVar5);
      uVar7 = (ushort)CARRY2(~uVar8,uVar10);
      uVar12 = (ushort)CARRY2(~uVar6,uVar7);
      uVar6 = ~uVar6 + uVar7;
      uVar7 = uVar9 + uVar12;
      uVar11 = ~uVar11 + (ushort)CARRY2(uVar9,uVar12);
      uVar5 = ~uVar5 + 1;
      uVar8 = ~uVar8 + uVar10;
    }
    while( true ) {
      while (uVar10 = uVar8, uVar8 = uVar5, uVar11 == 0 && uVar7 == 0) {
        uVar5 = 0;
        uVar7 = uVar6;
        uVar6 = uVar10;
      }
      if ((uVar11 & 0x10) != 0) break;
      uVar12 = (ushort)(CARRY2(uVar10,uVar10) || CARRY2(uVar10 * 2,(ushort)CARRY2(uVar8,uVar8)));
      uVar9 = (ushort)(CARRY2(uVar6,uVar6) || CARRY2(uVar6 * 2,uVar12));
      uVar6 = uVar6 * 2 + uVar12;
      uVar12 = uVar7 * 2;
      bVar1 = CARRY2(uVar7,uVar7);
      uVar7 = uVar7 * 2 + uVar9;
      uVar11 = uVar11 * 2 + (ushort)(bVar1 || CARRY2(uVar12,uVar9));
      uVar5 = uVar8 * 2;
      uVar8 = uVar10 * 2 + (ushort)CARRY2(uVar8,uVar8);
    }
    fp_round();
    return;
  }
LAB_c28c92:
  fp_store();
  return;
}



/* ===== c28cac fp_div_unsigned size=274 ===== */

void fp_div_unsigned(ushort param_1,ushort param_2,ushort param_3)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  ushort uVar5;
  ushort extraout_r1;
  ushort uVar6;
  ushort extraout_r2;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort unaff_r6;
  ushort uVar10;
  ushort unaff_r7;
  ushort uVar11;
  ushort unaff_r8;
  ushort unaff_r9;
  ushort uVar12;
  undefined4 uVar13;
  
  uVar13 = fp_pack();
  uVar4 = (uint)uVar13 >> 0x10;
  if ((extraout_r2 != 0) && (extraout_r1 != 0)) {
    uVar6 = extraout_r1;
    uVar7 = extraout_r2;
    uVar10 = unaff_r6;
    uVar11 = unaff_r8;
    uVar12 = unaff_r9;
    if (extraout_r1 < extraout_r2) {
      uVar13 = CONCAT22(param_3,((ushort)uVar13 & 0xfffb | ((ushort)uVar13 & 1) << 2) >> 1);
      uVar6 = extraout_r2;
      uVar7 = extraout_r1;
      uVar10 = unaff_r7;
      unaff_r7 = unaff_r6;
      uVar11 = param_1;
      uVar12 = param_2;
      param_1 = unaff_r8;
      param_2 = unaff_r9;
      param_3 = (ushort)uVar4;
    }
    uVar9 = (ushort)((uint)uVar13 >> 0x10);
    uVar8 = 0;
    sVar3 = uVar7 - uVar6;
    if (sVar3 != 0) {
      uVar6 = -sVar3;
      uVar7 = uVar10;
      uVar10 = param_1;
      param_1 = param_2;
      if (sVar3 != -0x35 && 0x34 < (ushort)-sVar3) goto LAB_c28c92;
      while (param_2 = param_1, param_1 = uVar10, uVar10 = uVar7, 0xf < (short)uVar6) {
        uVar6 = uVar6 - 0x10;
        uVar8 = param_3;
        uVar7 = 0;
        param_3 = param_2;
      }
      if (uVar6 != 0) {
        uVar8 = uVar8 >> uVar6 | param_3 << -uVar6;
        param_3 = param_3 >> uVar6 | param_2 << -uVar6;
        param_2 = param_2 >> uVar6 | param_1 << -uVar6;
        param_1 = param_1 >> uVar6 | uVar10 << -uVar6;
        uVar10 = uVar10 >> uVar6;
      }
    }
    if (!(bool)((byte)(((ushort)uVar13 & 2) >> 1) ^ (byte)uVar13 & 1)) {
      fp_round();
      return;
    }
    uVar5 = -uVar8;
    bVar1 = uVar9 < param_3 || uVar9 == param_3 && uVar8 != 0;
    uVar8 = (uVar9 - param_3) - (ushort)(uVar8 != 0);
    bVar2 = uVar12 < param_2 || uVar12 == param_2 && bVar1;
    uVar6 = (uVar12 - param_2) - (ushort)bVar1;
    bVar1 = uVar11 < param_1 || uVar11 == param_1 && bVar2;
    uVar7 = (uVar11 - param_1) - (ushort)bVar2;
    uVar11 = (unaff_r7 - uVar10) - (ushort)bVar1;
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0)))) {
      fp_store_zero();
      return;
    }
    if (uVar11 == 0 && (uVar7 == 0 && (uVar6 == 0 && (uVar8 == 0 && uVar5 == 0))) ||
        (unaff_r7 < uVar10 || unaff_r7 == uVar10 && bVar1)) {
      uVar9 = ~uVar7;
      uVar10 = (ushort)(0xfffe < ~uVar5);
      uVar7 = (ushort)CARRY2(~uVar8,uVar10);
      uVar12 = (ushort)CARRY2(~uVar6,uVar7);
      uVar6 = ~uVar6 + uVar7;
      uVar7 = uVar9 + uVar12;
      uVar11 = ~uVar11 + (ushort)CARRY2(uVar9,uVar12);
      uVar5 = ~uVar5 + 1;
      uVar8 = ~uVar8 + uVar10;
    }
    while( true ) {
      while (uVar10 = uVar8, uVar8 = uVar5, uVar11 == 0 && uVar7 == 0) {
        uVar5 = 0;
        uVar7 = uVar6;
        uVar6 = uVar10;
      }
      if ((uVar11 & 0x10) != 0) break;
      uVar12 = (ushort)(CARRY2(uVar10,uVar10) || CARRY2(uVar10 * 2,(ushort)CARRY2(uVar8,uVar8)));
      uVar9 = (ushort)(CARRY2(uVar6,uVar6) || CARRY2(uVar6 * 2,uVar12));
      uVar6 = uVar6 * 2 + uVar12;
      uVar12 = uVar7 * 2;
      bVar1 = CARRY2(uVar7,uVar7);
      uVar7 = uVar7 * 2 + uVar9;
      uVar11 = uVar11 * 2 + (ushort)(bVar1 || CARRY2(uVar12,uVar9));
      uVar5 = uVar8 * 2;
      uVar8 = uVar10 * 2 + (ushort)CARRY2(uVar8,uVar8);
    }
    fp_round();
    return;
  }
LAB_c28c92:
  fp_store();
  return;
}



/* ===== c28dbe fp_to_int size=50 ===== */

ushort fp_to_int(void)

{
  short sVar1;
  ushort extraout_r1;
  ushort uVar2;
  short unaff_r7;
  ushort unaff_r8;
  
  uVar2 = fp_pack_zero();
  if (((uVar2 & 1) == 0) && (0x3fe < extraout_r1)) {
    sVar1 = (short)&UNK_00fbf2 + extraout_r1;
    if (sVar1 == 0 || extraout_r1 < 0x40e) {
      uVar2 = (unaff_r7 << 0xb | unaff_r8 >> 5) >> -sVar1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* ===== c28dec fp_neg size=26 ===== */

void fp_neg(void)

{
  short in_r4;
  undefined1 auStack_2 [2];
  
  *(short *)ZEXT23(auStack_2) = -(in_r4 >> 0xf);
  if (-(in_r4 >> 0xf) != 0) {
    in_r4 = -in_r4;
  }
  if (in_r4 == 0) {
    *(undefined2 *)ZEXT23(auStack_2) = 0;
    fp_store_zero();
  }
  else {
    *(undefined2 *)ZEXT23(auStack_2) = 0;
    fp_store();
  }
  return;
}



/* ===== c28e06 gap_c28e06 size=74 ===== */

void gap_c28e06(void)

{
  short in_r4;
  undefined1 auStack_2 [2];
  
  *(undefined2 *)ZEXT23(auStack_2) = 0;
  if (in_r4 == 0) {
    *(undefined2 *)ZEXT23(auStack_2) = 0;
    fp_store_zero();
  }
  else {
    *(undefined2 *)ZEXT23(auStack_2) = 0;
    fp_store();
  }
  return;
}



/* ===== c28e50 fp_compare size=68 ===== */

ushort fp_compare(void)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort in_r10;
  ushort in_r11;
  
  uVar2 = *(ushort *)(uint3)in_r10;
  uVar3 = *(ushort *)(uint3)in_r11;
  if (((uVar2 | uVar3) & 0x7ff0) == 0) {
    return 0;
  }
  uVar4 = (short)uVar2 >> 0xf | 1;
  if ((!(bool)(((byte)(uVar2 >> 8) & 0x80 ^ (byte)(uVar3 >> 8) & 0x80) >> 7)) && (uVar2 <= uVar3)) {
    if (uVar3 <= uVar2) {
      uVar2 = *(ushort *)(uint3)(in_r10 + 2);
      bVar1 = *(ushort *)(in_r11 + 2) <= uVar2;
      if (uVar2 != *(ushort *)(in_r11 + 2) && bVar1) {
        return uVar4;
      }
      if (bVar1) {
        uVar2 = *(ushort *)(uint3)(in_r10 + 4);
        bVar1 = *(ushort *)(in_r11 + 4) <= uVar2;
        if (uVar2 != *(ushort *)(in_r11 + 4) && bVar1) {
          return uVar4;
        }
        if (bVar1) {
          uVar2 = *(ushort *)(uint3)(in_r10 + 6);
          bVar1 = *(ushort *)(in_r11 + 6) <= uVar2;
          if (uVar2 != *(ushort *)(in_r11 + 6) && bVar1) {
            return uVar4;
          }
          if (bVar1) {
            return 0;
          }
        }
      }
    }
    uVar4 = -uVar4;
  }
  return uVar4;
}



/* ===== c28e94 fp_pack size=62 ===== */

undefined4 fp_pack(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort in_r4;
  undefined2 unaff_r6;
  undefined2 unaff_r7;
  undefined2 unaff_r8;
  undefined2 unaff_r9;
  ushort in_r10;
  ushort in_r11;
  
  *(undefined2 *)(uint3)(in_r11 + 6) = param_3;
  *(undefined2 *)(uint3)(in_r11 + 4) = param_2;
  *(undefined2 *)(uint3)(in_r11 + 2) = param_1;
  uVar1 = *(ushort *)(uint3)in_r11;
  *(undefined2 *)(uint3)in_r11 = unaff_r6;
  uVar3 = PSW;
  uVar3 = *(undefined2 *)(uint3)(in_r10 + 6);
  *(undefined2 *)(uint3)(in_r10 + 6) = 1;
  *(undefined2 *)(uint3)(in_r10 + 4) = unaff_r9;
  *(undefined2 *)(uint3)(in_r10 + 2) = unaff_r8;
  uVar2 = *(ushort *)(uint3)in_r10;
  *(undefined2 *)(uint3)in_r10 = unaff_r7;
  uVar4 = PSW;
  return CONCAT22(uVar3,in_r4 & 0xfffc | (uVar1 >> 0xf) << 1 | uVar2 >> 0xf);
}



/* ===== c28ed2 fp_pack_zero size=56 ===== */

undefined4 fp_pack_zero(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort in_r4;
  undefined2 unaff_r7;
  undefined2 unaff_r8;
  undefined2 unaff_r9;
  ushort in_r10;
  
  uVar2 = *(undefined2 *)(uint3)(in_r10 + 6);
  *(undefined2 *)(uint3)(in_r10 + 6) = 0;
  *(undefined2 *)(uint3)(in_r10 + 4) = unaff_r9;
  *(undefined2 *)(uint3)(in_r10 + 2) = unaff_r8;
  uVar1 = *(ushort *)(uint3)in_r10;
  *(undefined2 *)(uint3)in_r10 = unaff_r7;
  uVar3 = PSW;
  return CONCAT22(uVar2,in_r4 & 0xfffe | uVar1 >> 0xf);
}



/* ===== c28f0e fp_round size=16 ===== */

void fp_round(void)

{
  bool bVar1;
  bool bVar2;
  ushort in_r1;
  ushort in_r3;
  short in_r4;
  ushort in_r5;
  ushort unaff_r7;
  ushort unaff_r8;
  ushort unaff_r9;
  ushort in_r10;
  
  if ((in_r3 & 0x8000) != 0) {
    bVar1 = 0xfffe < in_r5;
    in_r5 = in_r5 + 1;
    bVar2 = CARRY2(unaff_r9,(ushort)bVar1);
    unaff_r9 = unaff_r9 + bVar1;
    bVar1 = CARRY2(unaff_r8,(ushort)bVar2);
    unaff_r8 = unaff_r8 + bVar2;
    unaff_r7 = unaff_r7 + bVar1;
    if ((unaff_r7 & 0x20) != 0) {
      fp_store();
      return;
    }
  }
  *(ushort *)(uint3)(in_r10 + 6) = in_r5;
  *(ushort *)(uint3)(in_r10 + 4) = unaff_r9;
  *(ushort *)(uint3)(in_r10 + 2) = unaff_r8;
  *(ushort *)(uint3)in_r10 = unaff_r7 & 0xf | (in_r1 & 0x7ff) << 4 | in_r4 << 0xf;
  return;
}



/* ===== c28f1e fp_store size=64 ===== */

void fp_store(void)

{
  ushort in_r1;
  short in_r4;
  undefined2 in_r5;
  ushort unaff_r7;
  undefined2 unaff_r8;
  undefined2 unaff_r9;
  ushort in_r10;
  
  *(undefined2 *)(uint3)(in_r10 + 6) = in_r5;
  *(undefined2 *)(uint3)(in_r10 + 4) = unaff_r9;
  *(undefined2 *)(uint3)(in_r10 + 2) = unaff_r8;
  *(ushort *)(uint3)in_r10 = unaff_r7 & 0xf | (in_r1 & 0x7ff) << 4 | in_r4 << 0xf;
  return;
}



/* ===== c28f5e fp_store_zero size=14 ===== */

void fp_store_zero(void)

{
  fp_store();
  return;
}



/* ===== c28f6c fp_load size=24 ===== */

void fp_load(void)

{
  ushort in_r4;
  undefined1 auStack_8 [2];
  undefined1 auStack_6 [2];
  undefined1 auStack_4 [2];
  undefined1 auStack_2 [2];
  
  *(undefined2 *)ZEXT23(auStack_8) = *(undefined2 *)(uint3)in_r4;
  *(undefined2 *)ZEXT23(auStack_6) = *(undefined2 *)(uint3)(in_r4 + 2);
  *(undefined2 *)ZEXT23(auStack_4) = *(undefined2 *)(uint3)(in_r4 + 4);
  *(undefined2 *)ZEXT23(auStack_2) = *(undefined2 *)(uint3)(in_r4 + 6);
  return;
}



/* ===== c28f84 fp_copy size=16 ===== */

void fp_copy(void)

{
  ushort in_r4;
  ushort in_r10;
  
  *(undefined2 *)(uint3)in_r4 = *(undefined2 *)(uint3)in_r10;
  *(undefined2 *)(uint3)(in_r4 + 2) = *(undefined2 *)(uint3)(in_r10 + 2);
  *(undefined2 *)(uint3)(in_r4 + 4) = *(undefined2 *)(uint3)(in_r10 + 4);
  *(undefined2 *)(uint3)(in_r4 + 6) = *(undefined2 *)(uint3)(in_r10 + 6);
  return;
}


