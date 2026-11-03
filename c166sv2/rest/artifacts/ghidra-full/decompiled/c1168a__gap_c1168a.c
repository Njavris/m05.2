// c1168a gap_c1168a size=334 cc=unknown proto=undefined gap_c1168a(void)

short gap_c1168a(short param_1)

{
  ushort uVar1;
  byte *pbVar2;
  short sVar3;
  undefined2 uVar4;
  ushort uVar5;
  ushort uVar6;
  undefined2 uVar7;
  short sVar8;
  ushort uVar9;
  byte abStack_6 [2];
  
  sVar8 = 1;
  Ram00c542 = param_1;
  if ((param_1 == 1) && (sVar3 = Ram00c506, sVar3 == 0)) {
    func_0xc1128a((short)&UNK_00c508);
    uVar7 = gap_c114fc((short)&UNK_00c508);
    Ram00c506 = uVar7;
  }
  if ((param_1 == 0) || (sVar3 = Ram00c506, sVar3 == 1)) {
    Ram00c506 = 0;
    sVar8 = gap_c1145c((short)&UNK_00c508);
    if (sVar8 == 1) {
      gap_c11662();
      abStack_6[0] = gap_c10f90((short)&UNK_00c508,0,0xe0);
      Ram00c534 = (ushort)abStack_6[0];
      uVar7 = Ram00c520;
      uVar4 = Ram00c522;
      Ram00c53a = uVar7;
      Ram00c53c = uVar4;
      if (param_1 == 0) {
        Ram00c544 = 0x73b4;
      }
      else {
        Ram00c544 = 0x73d0;
      }
      while ((sVar8 == 1 && (uVar9 = Ram00c544, *(short *)(uint3)uVar9 != 0))) {
        uVar1 = Ram00c544;
        uVar9 = *(ushort *)(uint3)uVar1;
        Ram00c536 = *(undefined2 *)(uint3)(uVar1 + 2);
        while ((sVar8 == 1 && (sVar3 = Ram00c536, sVar3 != 0))) {
          sVar3 = Ram00c542;
          uVar1 = *(short *)(uint3)(sVar3 * 8 + 0x7050) - 4;
          uVar5 = Ram00c534;
          uVar6 = Ram00c534;
          if (uVar1 == uVar6 || uVar1 < uVar5) break;
          *(undefined1 *)(uint3)abStack_6[0] = *(undefined1 *)(uint3)uVar9;
          pbVar2 = (byte *)(uint3)uVar9;
          uVar9 = uVar9 + 1;
          uVar1 = Ram00c53e;
          Ram00c53e = uVar1 + *pbVar2;
          sVar8 = Ram00c540;
          Ram00c540 = sVar8 + (ushort)CARRY2(uVar1,(ushort)*pbVar2);
          sVar8 = Ram00c536;
          Ram00c536 = sVar8 + -1;
          sVar8 = Ram00c534;
          Ram00c534 = sVar8 + 1;
          sVar8 = func_0xc11586((short)&UNK_00c508,0,0xe0,abStack_6);
          abStack_6[0] = abStack_6[0] + 1;
        }
        sVar3 = Ram00c538;
        Ram00c538 = sVar3 + 1;
        sVar3 = Ram00c538;
        Ram00c544 = sVar3 * 6 + 0x73d0;
      }
      if (sVar8 == 1) {
        sVar8 = gap_c10fe8((short)&UNK_00c508,0,0xe0);
      }
    }
  }
  return sVar8;
}

