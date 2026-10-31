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


