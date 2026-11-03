// c0ff34 FUN_c0ff34 size=140 cc=unknown proto=undefined FUN_c0ff34(void)

void FUN_c0ff34(void)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  short sVar4;
  short sVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  byte bVar9;
  
  DAT_00fc20 = &stack0x0000;
  uVar7 = DPP0;
  DPP0 = 0x301;
  uVar8 = DPP2;
  DPP2 = 0x303;
  uVar6 = SSCRB;
  uVar1 = DAT_00c496;
  *(undefined1 *)(uint3)uVar1 = uVar6;
  cVar3 = DAT_00c492;
  DAT_00c492 = cVar3 + -1;
  cVar3 = DAT_00c492;
  if (cVar3 == '\0') {
    uVar1 = P1H;
    P1H = uVar1 | 8;
    bVar9 = 0;
    do {
      uVar2 = (ushort)bVar9;
      uVar1 = (short)&DAT_00c4ac + uVar2;
      bVar9 = bVar9 + 1;
      *(byte *)(uint3)uVar1 = *(byte *)(uint3)uVar1 | *(byte *)(uint3)((short)&DAT_00c4a0 + uVar2);
    } while (bVar9 < 7);
    DAT_00c492 = 7;
    DAT_00c494 = 0xc4b8;
    DAT_00c496 = 0xc4a0;
  }
  else {
    sVar4 = DAT_00c494;
    DAT_00c494 = sVar4 + 1;
    sVar5 = DAT_00c496;
    DAT_00c496 = sVar5 + 1;
    ssc_send(sVar4 + 1,uVar8,uVar7);
  }
  DPP2 = uVar8;
  uVar8 = DPP2;
  uVar8 = DPP2;
  uVar8 = DPP2;
  DPP0 = uVar7;
  uVar7 = DPP0;
  uVar7 = DPP0;
  uVar7 = DPP0;
  return;
}

