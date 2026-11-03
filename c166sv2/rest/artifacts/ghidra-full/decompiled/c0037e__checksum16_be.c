// c0037e checksum16_be size=58 cc=unknown proto=undefined checksum16_be(void)

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

