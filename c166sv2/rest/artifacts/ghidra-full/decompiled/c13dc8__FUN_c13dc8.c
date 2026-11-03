// c13dc8 FUN_c13dc8 size=24 cc=unknown proto=undefined FUN_c13dc8(void)

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

