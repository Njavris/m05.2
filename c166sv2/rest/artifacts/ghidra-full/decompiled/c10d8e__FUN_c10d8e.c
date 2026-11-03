// c10d8e FUN_c10d8e size=112 cc=unknown proto=undefined FUN_c10d8e(void)

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

