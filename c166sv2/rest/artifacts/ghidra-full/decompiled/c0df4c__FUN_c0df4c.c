// c0df4c FUN_c0df4c size=618 cc=unknown proto=undefined FUN_c0df4c(void)

void FUN_c0df4c(byte param_1)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short sVar7;
  short *psVar8;
  short sVar9;
  ushort uVar10;
  ushort uVar11;
  
  sVar7 = (ushort)param_1 * 0x12;
  uVar10 = (short)&UNK_00c41c + sVar7;
  if ((*(byte *)(uint3)uVar10 & 0x20) == 0) {
    return;
  }
  if ((*(byte *)(uint3)uVar10 & 4) == 0) {
    if ((*(byte *)(uint3)uVar10 & 3) == 0) {
      if ((*(byte *)(uint3)uVar10 & 0x40) == 0) {
        *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 | 0x80;
        sVar9 = DAT_00c408;
        *(short *)(uint3)(ushort)((short)&UNK_00c41a + sVar7) =
             **(short **)(uint3)(ushort)((short)&UNK_00c41e + sVar7) + sVar9;
      }
      else {
        *(undefined2 *)(uint3)(ushort)((short)&UNK_00c41a + sVar7) =
             **(undefined2 **)(uint3)(ushort)((short)&UNK_00c41e + sVar7);
      }
      *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 | 1;
      if ((*(byte *)(uint3)uVar10 & 8) == 0) {
        if ((*(byte *)(uint3)uVar10 & 0x40) == 0) {
          uVar10 = *(ushort *)(uint3)(ushort)((short)&UNK_00c412 + sVar7);
          uVar11 = DAT_00c408;
          sVar9 = uVar10 + uVar11;
          uVar11 = *(short *)(uint3)(ushort)((short)&UNK_00c414 + sVar7) +
                   (ushort)CARRY2(uVar10,uVar11) & 0xff;
        }
        else {
          sVar9 = *(short *)(uint3)(ushort)((short)&UNK_00c412 + sVar7);
          uVar11 = *(ushort *)(uint3)(ushort)((short)&UNK_00c414 + sVar7);
          *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 & 0xbf;
        }
      }
      else {
        uVar5 = (short)&UNK_00c412 + sVar7;
        uVar6 = (short)&DAT_00c416 + sVar7;
        uVar10 = *(ushort *)(uint3)uVar5;
        uVar1 = *(ushort *)(uint3)(ushort)((short)&UNK_00c414 + sVar7);
        uVar11 = *(ushort *)(uint3)uVar6;
        uVar2 = *(ushort *)(uint3)(ushort)((short)&DAT_00c418 + sVar7);
        if (uVar1 - uVar2 == (ushort)(uVar10 < uVar11) && uVar10 == uVar11 ||
            (uVar1 < uVar2 || uVar1 == uVar2 && uVar10 < uVar11)) {
          sVar9 = DAT_00c408;
          uVar11 = 0;
        }
        else {
          uVar10 = *(ushort *)(uint3)uVar5;
          uVar11 = *(ushort *)(uint3)uVar6;
          uVar1 = uVar10 - uVar11;
          uVar2 = DAT_00c408;
          sVar9 = uVar1 + uVar2;
          uVar11 = ((*(short *)(uint3)(ushort)((short)&UNK_00c414 + sVar7) -
                    *(short *)(uint3)(ushort)((short)&DAT_00c418 + sVar7)) -
                   (ushort)(uVar10 < uVar11)) + (ushort)CARRY2(uVar1,uVar2) & 0xff;
        }
      }
      FUN_c0e3da(param_1,sVar9,uVar11);
      return;
    }
    bVar3 = *(byte *)(uint3)(ushort)((short)&UNK_00c41d + sVar7);
    if ((*(byte *)(uint3)uVar10 & 2) == 0) {
      event_accum(param_1,**(undefined2 **)(uint3)(ushort)((short)&UNK_00c41e + sVar7));
      psVar8 = (short *)DAT_00c3fc;
      sVar9 = DAT_00c406;
      sVar9 = *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar7) + sVar9;
      if ((((short)&UNK_00fff6 + sVar9) - *psVar8 & 0x8000U) == 0) {
        *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar7) = sVar9;
      }
      else {
        uVar11 = DAT_00c3fc;
        *(short *)(uint3)*(ushort *)(uint3)(ushort)((short)&UNK_00c41e + sVar7) =
             *(short *)(uint3)uVar11 + 10;
      }
      uVar11 = DAT_00c402;
      sVar7 = (bVar3 & 0xf) << 2;
      *(ushort *)(uint3)uVar11 = *(ushort *)(uint3)uVar11 & ~(0xf << sVar7);
      uVar11 = DAT_00c402;
      *(ushort *)(uint3)uVar11 = *(ushort *)(uint3)uVar11 | 4 << sVar7;
      cc_irq_enable_bit(bVar3);
      if ((*(byte *)(uint3)uVar10 & 8) == 0) {
        *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 | 8;
      }
      else {
        *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 | 0x10;
      }
      if ((DAT_c07d06 == 0) || (param_1 + 1 == (ushort)DAT_c07d06)) {
        sVar9 = div32u();
        sVar7 = DAT_00c3a4;
        DAT_00c3a4 = sVar7 + sVar9;
      }
      *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 | 2;
      *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 & 0xfe;
      return;
    }
    *(byte *)(uint3)uVar10 = *(byte *)(uint3)uVar10 & 0xfd;
  }
  else if ((*(byte *)(uint3)uVar10 & 1) != 0) {
    event_accum(param_1,**(undefined2 **)(uint3)(ushort)((short)&UNK_00c41e + sVar7));
    uVar11 = 0;
    if ((*(byte *)(uint3)uVar10 & 0x80) != 0) {
      uVar11 = *(short *)(uint3)(ushort)((short)&UNK_00c41a + sVar7) -
               **(short **)(uint3)(ushort)((short)&UNK_00c41e + sVar7);
    }
    uVar6 = (short)&DAT_00c416 + sVar7;
    uVar4 = (short)&UNK_00c412 + sVar7;
    uVar10 = *(ushort *)(uint3)uVar6;
    uVar2 = *(ushort *)(uint3)(ushort)((short)&DAT_00c418 + sVar7);
    uVar1 = *(ushort *)(uint3)uVar4;
    uVar5 = *(ushort *)(uint3)(ushort)((short)&UNK_00c414 + sVar7);
    if (uVar2 - uVar5 == (ushort)(uVar10 < uVar1) && uVar10 == uVar1 ||
        (uVar2 < uVar5 || uVar2 == uVar5 && uVar10 < uVar1)) {
      uVar1 = *(ushort *)(uint3)uVar4;
      uVar2 = *(ushort *)(uint3)uVar6;
      uVar5 = uVar1 - uVar2;
      uVar10 = uVar5 + uVar11;
      uVar11 = ((*(short *)(uint3)(ushort)((short)&UNK_00c414 + sVar7) -
                *(short *)(uint3)(ushort)((short)&DAT_00c418 + sVar7)) - (ushort)(uVar1 < uVar2)) +
               (ushort)CARRY2(uVar5,uVar11) & 0xff;
    }
    else {
      uVar10 = 0x28;
      uVar11 = 0;
    }
    if (uVar11 == uVar10 < 0x28 && uVar10 == 0x28 || uVar11 == 0 && uVar10 < 0x28) {
      FUN_c0e3da(param_1,0x28,0);
      return;
    }
    FUN_c0e3da(param_1,uVar10,uVar11);
    return;
  }
  if ((*(byte *)(uint3)uVar10 & 8) == 0) {
    event_schedule_duration(param_1);
  }
  return;
}

