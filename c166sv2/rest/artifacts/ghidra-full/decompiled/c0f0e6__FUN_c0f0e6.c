// c0f0e6 FUN_c0f0e6 size=76 cc=unknown proto=undefined FUN_c0f0e6(void)

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

