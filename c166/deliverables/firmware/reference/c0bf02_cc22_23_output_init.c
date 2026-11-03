/* c0bf02 cc22_23_output_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initializes CC22/CC23 interrupt/port/compare pointers. */

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
  uVar1 = P1H;
  P1H = uVar1 | 1;
  uVar1 = CC22IC;
  CC22IC = uVar1 | 0x34;
  uVar1 = S0RIC;
  S0RIC = uVar1 | 0x35;
  _cc23_compare_ptr = SUB32(&CC23,0);
  _cc22_compare_ptr = SUB32(&CC22,0);
  _cc23_irq_ptr = SUB32(&CC23IC,0);
  _cc22_irq_ptr = SUB32(&CC22IC,0);
  return;
}


