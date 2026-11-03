// c03df8 gap_c03df8 size=92 cc=unknown proto=undefined gap_c03df8(void)

/* WARNING: Control flow encountered bad instruction data */

short gap_c03df8(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  short sVar5;
  short in_r2;
  ushort uVar6;
  ushort uVar7;
  ushort in_r4;
  ushort uVar8;
  short sVar9;
  ushort in_r5;
  ushort in_r10;
  short in_r11;
  ushort in_PSW;
  ushort uVar4;
  
  sVar9 = (in_r2 - in_r4) - (ushort)((byte)(in_PSW >> 1) & 1);
  uVar8 = Ram00fd48;
  Ram00fd48 = uVar8 & 0xffef;
  uVar8 = Ram00fd48;
  if ((uVar8 & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  sVar5 = -sVar9;
  uVar2 = CONCAT22(in_r5 >> sVar5,in_r4 >> sVar5 | in_r5 << sVar9) /
          (uint)(in_r11 << sVar9 | in_r10 >> sVar5);
  uVar7 = (short)uVar2 * sRam000000;
  iVar3 = (uVar2 & 0xffff) * (uint)uRam000002;
  uVar6 = (ushort)iVar3;
  uVar4 = (ushort)((uint)iVar3 >> 0x10);
  uVar8 = uVar7 + uVar4;
  if (CARRY2(uVar7,uVar4)) {
    bVar1 = uVar6 < uRam000002;
    uVar6 = uVar6 - uRam000002;
    uVar8 = (uVar8 - sRam000000) - (ushort)bVar1;
  }
  uVar7 = uVar6 - uRam000006;
  sVar9 = (uVar8 - uRam000008) - (ushort)(uVar6 < uRam000006);
  if ((sVar9 != 0 || uVar7 != 0) &&
      (uRam000008 <= uVar8 && (uVar8 != uRam000008 || uVar6 >= uRam000006))) {
    bVar1 = uVar7 < uRam000002;
    uVar7 = uVar7 - uRam000002;
    sVar9 = (sVar9 - sRam000000) - (ushort)bVar1;
  }
  return -(ushort)(uVar7 != 0) - sVar9;
}

