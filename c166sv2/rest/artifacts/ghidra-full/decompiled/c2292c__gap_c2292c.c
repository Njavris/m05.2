// c2292c gap_c2292c size=226 cc=unknown proto=undefined gap_c2292c(void)

void gap_c2292c(ushort param_1)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  char cVar4;
  short extraout_r2;
  short sVar5;
  ushort uVar6;
  ushort uVar7;
  undefined4 uVar8;
  
  sVar1 = (param_1 & 0xff) * 2;
  uVar8 = gap_c28b88(*(ushort *)(uint3)(ushort)((short)&UNK_00c832 + sVar1) >> 1);
  uVar7 = (ushort)((uint)uVar8 >> 0x10);
  uVar6 = (ushort)uVar8;
  if (uVar7 == uVar6 < 0x7fff && uVar6 == 0x7fff || (short)uVar7 < (short)(ushort)(uVar6 < 0x7fff))
  {
    if ((short)((uVar7 + 1) - (ushort)(uVar6 < 0x8000)) < 0 !=
        (SBORROW2(uVar7,-1) != SBORROW2(uVar7 + 1,(ushort)(uVar6 < 0x8000)))) {
      uVar6 = 0x8000;
    }
  }
  else {
    uVar6 = 0x7fff;
  }
  uVar7 = *(ushort *)(uint3)(ushort)((short)&UNK_00cb06 + sVar1);
  uVar2 = (ushort)(CONCAT22(uVar7 >> 4,uVar7 << 0xc) / (uint)uRamc05c48);
  uVar7 = uVar6 * 2 + uVar2;
  uVar6 = ((short)uVar6 >> 0xf) * 2 + (ushort)CARRY2(uVar6,uVar6) + extraout_r2 +
          (ushort)CARRY2(uVar6 * 2,uVar2);
  if (uVar6 == (uVar7 != 0xffff) && uVar7 == 0xffff ||
      (short)uVar6 < (short)(ushort)(uVar7 != 0xffff)) {
    if ((short)uVar6 < 0) {
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0xffff;
  }
  sVar5 = (short)((uint)uVar7 * 64000 >> 0x10);
  cVar4 = DAT_00c830;
  if (cVar4 == '\0') {
    sVar3 = Ram00c788;
    sVar5 = sVar5 + sVar3;
  }
  *(short *)(uint3)(ushort)((short)&UNK_00c764 + sVar1) = sVar5;
  return;
}

