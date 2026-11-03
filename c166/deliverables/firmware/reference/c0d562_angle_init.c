/* c0d562 angle_init */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Initialize angle/time conversion from calibration. */

void angle_init(void)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  
  uVar1 = PSW;
  PSW = uVar1 & 0xf7ff;
  _sensor_var_c224 = 0xd076;
  _sensor_var_c226 = 0xc0;
  bVar3 = 0;
  do {
    uVar1 = (ushort)bVar3;
    uVar2 = (ushort)bVar3;
    bVar3 = bVar3 + 1;
    bVar4 = (char)(*(ushort *)
                    ((uint3)(uVar1 * 2 + 0x5032) + (uint3)((0xafcd < uVar1 * 2) + 0xc0) * 0x10000) /
                  0x3c0) + 4;
    if (0x18 < bVar4) {
      bVar4 = bVar4 % 0x18;
    }
    *(byte *)(uint3)(uVar2 + 0xc382) = bVar4;
  } while (bVar3 < 2);
  uVar1 = PSW;
  PSW = uVar1 | 0x800;
  return;
}


