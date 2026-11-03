// c03cd0 boot_hidden_i2c_b size=130 cc=unknown proto=undefined boot_hidden_i2c_b(void)

uint boot_hidden_i2c_b(void)

{
  uint uVar1;
  int iVar2;
  short sVar4;
  ushort in_r2;
  short sVar5;
  ushort in_r4;
  ushort uVar6;
  ushort in_r5;
  ushort uVar7;
  ushort in_r10;
  ushort in_r11;
  ushort uVar8;
  ushort uVar3;
  
  if (in_r11 != 0) {
    sVar5 = LZCOUNT(in_r11);
    if (sVar5 == 0) {
      uVar7 = 0;
      uVar6 = in_r5;
      uVar8 = in_r11;
    }
    else {
      sVar4 = -sVar5;
      uVar7 = in_r5 >> sVar4;
      uVar6 = in_r4 >> sVar4 | in_r5 << sVar5;
      uVar8 = in_r11 << sVar5 | in_r10 >> sVar4;
    }
    uVar1 = CONCAT22(uVar7,uVar6) / (uint)uVar8;
    uVar6 = (ushort)uVar1;
    iVar2 = (uVar1 & 0xffff) * (uint)in_r10;
    uVar8 = (ushort)iVar2;
    uVar3 = (ushort)((uint)iVar2 >> 0x10);
    uVar7 = uVar6 * in_r11 + uVar3;
    if ((CARRY2(uVar6 * in_r11,uVar3)) ||
       ((uVar7 - in_r2 != (ushort)(uVar8 < in_r5) || uVar8 != in_r5) &&
        (in_r2 <= uVar7 && (uVar7 != in_r2 || uVar8 >= in_r5)))) {
      uVar6 = uVar6 - 1;
    }
    return (uint)uVar6;
  }
  return CONCAT22(in_r5 / in_r10,(short)(CONCAT22(in_r5 % in_r10,in_r4) / (uint)in_r10));
}

