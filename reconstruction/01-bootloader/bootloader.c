/* ============================================================================
 * Delphi MT05.2 semantic reconstruction: bootloader firmware part
 * Generated from Ghidra decompiler output; not compilable source.
 * Functions are grouped by area and sorted by address.
 * ========================================================================== */

/* ============================== Bootloader ============================== */

/* ----------------------------------------------------------------------------
 * boot_main
 * Address: 0xC00200
 * Area:    bootloader
 * Size:    220 bytes
 * -------------------------------------------------------------------------- */
/* c00200 boot_main */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boot-block main: checks magic/checksums, selects app or bootloader. */

void boot_main(void)

{
  ushort uVar1;
  short sVar2;
  ushort extraout_r10;
  ushort extraout_r10_00;
  short extraout_r11;
  short extraout_r11_00;
  
  uVar1 = input_status;
  if ((uVar1 & 2) != 0) {
    mem_read_word(0x7fc,0xe0);
    if (extraout_r11 + 0x9bb0U == (ushort)(extraout_r10 < 0x8625) && extraout_r10 == 0x8625) {
      boot_variant = '\x01';
    }
    mem_read_word();
    if (extraout_r11_00 + 0x79cdU == (ushort)(extraout_r10_00 < 0x6450) && extraout_r10_00 == 0x6450
       ) {
      boot_variant = '\x02';
    }
  }
  mem_write_word();
  boot_periph_init();
  if (_app_entry == 0) {
    bootloader_entry(0);
  }
  uVar1 = input_status;
  if ((uVar1 & 0x400) != 0) {
    bootloader_entry();
  }
  if ((boot_variant == '\x01') || (boot_variant == '\x02')) {
    asc0_state2_init(boot_variant);
    bootloader_entry();
  }
  if ((app_magic != -0x5600) &&
     ((sVar2 = checksum16_be(0,0xc0,0x1ffd,0xc0), sVar2 != boot_checksum ||
      (sVar2 = checksum16_be(0xb000,0xc0,0xfffb,0xc3), sVar2 != app_checksum)))) {
    bootloader_entry();
    return;
  }
  app_entry();
  return;
}


/* ----------------------------------------------------------------------------
 * boot_periph_init
 * Address: 0xC002DC
 * Area:    bootloader
 * Size:    50 bytes
 * -------------------------------------------------------------------------- */
/* c002dc boot_periph_init */

/* Boot peripheral initialization wrapper. */

void boot_periph_init(void)

{
  ushort uVar1;
  
  boot_bus_mode();
  P7 = 0x7f13;
  clock_init();
  asc0_init(boot_variant);
  capcom_timer_init(boot_variant);
  boot_extint_init();
  asc0_pin_init();
  boot_port_adc_init();
  can_twincan_init();
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


/* ----------------------------------------------------------------------------
 * boot_bus_mode
 * Address: 0xC0030E
 * Area:    bootloader
 * Size:    112 bytes
 * -------------------------------------------------------------------------- */
/* c0030e boot_bus_mode */

/* External bus mode configuration based on SYSCON bits. */

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
    PECC0 = 0x5554;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x9600;
    PECC0 = 0x800;
    uVar2 = DAT_00f0c2;
    DAT_00f0c0 = (byte)~(byte)uVar2 | 0x8e00;
  }
  return;
}


/* ----------------------------------------------------------------------------
 * checksum16_be
 * Address: 0xC0037E
 * Area:    bootloader
 * Size:    50 bytes
 * -------------------------------------------------------------------------- */
/* c0037e checksum16_be */

/* WARNING: Control flow encountered bad instruction data */
/* 16-bit sum of big-endian words over a flash range. */

void checksum16_be(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  bool bVar1;
  
  __disable_watchdog();
  for (; param_2 < param_4 || param_2 == param_4 && param_1 < param_3; param_2 = param_2 + bVar1) {
    bVar1 = 0xfffd < param_1;
    param_1 = param_1 + 2;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ----------------------------------------------------------------------------
 * delay_loop
 * Address: 0xC003B8
 * Area:    bootloader
 * Size:    10 bytes
 * -------------------------------------------------------------------------- */
/* c003b8 delay_loop */

/* Simple delay loop. */

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


/* ----------------------------------------------------------------------------
 * delay_ticks
 * Address: 0xC003C2
 * Area:    bootloader
 * Size:    28 bytes
 * -------------------------------------------------------------------------- */
/* c003c2 delay_ticks */

/* Delay loop parameterized by r12. */

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


/* ----------------------------------------------------------------------------
 * boot_minimal_main
 * Address: 0xC003DE
 * Area:    bootloader
 * Size:    18 bytes
 * -------------------------------------------------------------------------- */
/* c003de boot_minimal_main */

/* Reduced boot path used when configuration ADC check selects it. */

void boot_minimal_main(void)

{
  asc0_init(0);
  capcom_timer_init(0);
  can_bootloader_wait();
  return;
}


/* ----------------------------------------------------------------------------
 * bootloader_entry
 * Address: 0xC003F0
 * Area:    bootloader
 * Size:    56 bytes
 * -------------------------------------------------------------------------- */
/* c003f0 bootloader_entry */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Bootloader/test loop; bit-bangs P1L.6 and waits on P1L.4. */

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
  uVar1 = P1L;
  P1L = uVar1 & 0xffbf;
  do {
    do {
      delay_ticks(500);
    } while ((_ssc_rx_frame & 0x10) != 0);
    uVar1 = P1L;
    P1L = uVar1 | 0x40;
    uVar2 = P1L;
    uVar1 = P1L;
    uVar3 = P1L;
    P1L = uVar3 & 0xffbf | ((uVar1 & 0x40) >> 6 ^ 1) << 6;
  } while( true );
}


/* ----------------------------------------------------------------------------
 * boot_cinit
 * Address: 0xC00904
 * Area:    bootloader
 * Size:    372 bytes
 * -------------------------------------------------------------------------- */
/* c00904 boot_cinit */

/* Boot-block C runtime init (zero/init tables). */

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
  
  uVar4 = (ushort)&stack_guard_fdfe;
  do {
    if ((uVar4 != (ushort)&UNK_00fc22) && (uVar4 != (ushort)&UNK_00fc20)) {
      *(undefined2 *)(uint3)uVar4 = 0;
    }
    bVar1 = uVar4 != (ushort)&input_status_flags;
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


/* ----------------------------------------------------------------------------
 * boot_reset
 * Address: 0xC00A78
 * Area:    bootloader
 * Size:    440 bytes
 * -------------------------------------------------------------------------- */
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


/* ----------------------------------------------------------------------------
 * boot_port_adc_init
 * Address: 0xC00DAE
 * Area:    bootloader
 * Size:    44 bytes
 * -------------------------------------------------------------------------- */
/* c00dae boot_port_adc_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boot-block port/ADC-related register initialization. */

void boot_port_adc_init(void)

{
  _boot_port_cfg_c080 = 0xffff;
  boot_port_cfg_c092 = 2;
  boot_port_cfg_c091 = 0;
  boot_port_cfg_c090 = 0;
  boot_port_cfg_c08f = 0x1f;
  boot_port_cfg_c08e = 0;
  boot_port_cfg_c08d = 0;
  boot_port_cfg_c08c = 0;
  ssc_start_frame();
  return;
}


/* ----------------------------------------------------------------------------
 * boot_extint_init
 * Address: 0xC00EE8
 * Area:    bootloader
 * Size:    36 bytes
 * -------------------------------------------------------------------------- */
/* c00ee8 boot_extint_init */

/* Boot external-interrupt init: bus mode, EXICON, T1IC. */

void boot_extint_init(void)

{
  boot_bus_mode();
  DAT_00ffda = 0;
  boot_bus_mode();
  DAT_00ffd8 = 0;
  boot_bus_mode();
  EXICON = 0;
  T1IC = 0x44;
  return;
}


/* ----------------------------------------------------------------------------
 * trap_stack_overflow
 * Address: 0xC00F0C
 * Area:    bootloader
 * Size:    94 bytes
 * -------------------------------------------------------------------------- */
/* c00f0c trap_stack_overflow */

/* Stack overflow trap handler. */

void trap_stack_overflow(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined2 uVar6;
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
  
  isr_save_fc80 = &stack0x0000;
  uVar6 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DPP0 = 0x300;
  uVar7 = DPP2;
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
  uVar4 = DPP3;
  uVar8 = DPP3;
  uVar8 = DPP3;
  uVar5 = PSW;
  PSW = uVar5 & 0xf7ff;
  uVar13 = TFR;
  uVar5 = stack_guard_fdfe;
  stack_guard_fdfe = uVar5 | uVar13;
  uVar5 = TFR;
  TFR = uVar5 & 0xbfff;
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
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
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


/* ----------------------------------------------------------------------------
 * trap_stack_underflow
 * Address: 0xC00F6A
 * Area:    bootloader
 * Size:    94 bytes
 * -------------------------------------------------------------------------- */
/* c00f6a trap_stack_underflow */

/* Stack underflow trap handler. */

void trap_stack_underflow(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined2 uVar6;
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
  
  isr_save_fc80 = &stack0x0000;
  uVar6 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DPP0 = 0x300;
  uVar7 = DPP2;
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
  uVar4 = DPP3;
  uVar8 = DPP3;
  uVar8 = DPP3;
  uVar5 = PSW;
  PSW = uVar5 & 0xf7ff;
  uVar13 = TFR;
  uVar5 = stack_guard_fdfe;
  stack_guard_fdfe = uVar5 | uVar13;
  uVar5 = TFR;
  TFR = uVar5 & 0xdfff;
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
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
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


/* ----------------------------------------------------------------------------
 * trap_bootstrap
 * Address: 0xC00FC8
 * Area:    bootloader
 * Size:    128 bytes
 * -------------------------------------------------------------------------- */
/* c00fc8 trap_bootstrap */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Bootstrap trap handler. */

void trap_bootstrap(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  undefined2 uVar6;
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
  
  isr_save_fc80 = &stack0x0000;
  uVar6 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
  DPP0 = 0x300;
  uVar7 = DPP2;
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
  uVar4 = DPP3;
  uVar8 = DPP3;
  uVar8 = DPP3;
  uVar5 = PSW;
  PSW = uVar5 & 0xf7ff;
  uVar13 = TFR;
  uVar5 = stack_guard_fdfe;
  stack_guard_fdfe = uVar5 | uVar13;
  uVar5 = TFR;
  if ((uVar5 & 0x80) != 0) {
    uVar5 = TFR;
    TFR = uVar5 & 0xff7f;
  }
  uVar5 = TFR;
  if ((uVar5 & 0x10) != 0) {
    uVar5 = TFR;
    TFR = uVar5 & 0xffef;
    uVar5 = stack_guard_fdfc;
    stack_guard_fdfc = uVar5 | _DAT_fff000;
  }
  uVar5 = TFR;
  if ((uVar5 & 8) != 0) {
    uVar5 = TFR;
    TFR = uVar5 & 0xfff7;
  }
  uVar5 = TFR;
  if ((uVar5 & 4) != 0) {
    uVar5 = TFR;
    TFR = uVar5 & 0xfffb;
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
  DPP0 = uVar1;
  uVar1 = DPP0;
  uVar1 = DPP0;
  uVar1 = DPP0;
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


/* ----------------------------------------------------------------------------
 * can_bootloader_wait
 * Address: 0xC01AD4
 * Area:    bootloader
 * Size:    78 bytes
 * -------------------------------------------------------------------------- */
/* c01ad4 can_bootloader_wait */

/* Initializes CAN diagnostic objects and enters the boot wait loop. */

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

