// c10000 app_entry size=4 cc=unknown proto=undefined app_entry(void)

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

