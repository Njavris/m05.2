// c240fe gap_c240fe size=274 cc=unknown proto=undefined gap_c240fe(void)

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

