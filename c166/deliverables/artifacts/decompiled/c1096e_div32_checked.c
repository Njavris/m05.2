/* c1096e div32_checked */

/* Checked 32-bit division; returns 0xFFFFFFFF on overflow/zero. */

undefined4 div32_checked(short param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != 0) &&
     (uVar2 = div32u(), sVar1 = (short)((uint)uVar2 >> 0x10),
     sVar1 == -1 && (sVar1 != -1 || (short)uVar2 == -1))) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


