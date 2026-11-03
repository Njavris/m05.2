// c0ee3c gap_c0ee3c size=268 cc=unknown proto=undefined gap_c0ee3c(void)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gap_c0ee3c(void)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  ushort uVar9;
  
  bVar1 = DAT_00c256;
  uVar9 = (short)&DAT_00c282 + (ushort)bVar1 * 2;
  *(ushort *)(uint3)uVar9 = *(ushort *)(uint3)uVar9 & 0xff7f;
  sVar7 = gap_c0ece6();
  if (sVar7 == 0) {
    sVar7 = cc_irq_is_enabled(_DAT_007048);
    if ((sVar7 == 0) && (uVar9 = DAT_00fd06, (uVar9 & 1) != 0)) {
      uVar3 = DAT_00c27e;
      DAT_00c466 = uVar3;
      DAT_00c3ee = uVar3;
      sVar7 = Ram00c3e4;
      uVar9 = DAT_00fd06;
      if ((uVar9 & 2) == 0) {
        bVar1 = DAT_00c256;
        uVar9 = (short)&DAT_00c284 + (ushort)bVar1 * 2;
        cVar2 = UNK_00c3f2;
        UNK_00c3f2 = cVar2 + -1;
        *(ushort *)(uint3)uVar9 = *(ushort *)(uint3)uVar9 & 0xff7f | 0x80;
        uVar4 = UNK_00c3f2;
        uVar3 = Ram00c3f6;
        FUN_c0e894(1,uVar4,uVar3,(short)&UNK_00c3e4,(short)&DAT_00c3e6);
      }
      else {
        sVar8 = DAT_00c3e6;
        sVar5 = DAT_00c452;
        sVar6 = DAT_00c466;
        Ram00c3e4 = (sVar8 - sVar5) + sVar6;
      }
      sVar8 = Ram00c3e4;
      sVar5 = DAT_00c466;
      uVar9 = sVar8 - sVar5;
      if ((uVar9 & 0x8000) != 0) {
        uVar9 = 0;
      }
      if (((DAT_c05036 == '\0') && (sVar8 = Ram00c462, sVar8 != 0)) &&
         (cVar2 = DAT_00c256, cVar2 == '\x14')) {
        uVar9 = 0;
      }
      sVar8 = DAT_00c45c;
      if (((uVar9 < sVar8 + 0x1eU) && (uVar9 < 0xfff)) || (uVar9 = DAT_00fd06, (uVar9 & 2) != 0)) {
        sVar8 = t7_timestamp();
        if (((0x19 < (ushort)(sVar7 - sVar8)) && ((ushort)(sVar7 - sVar8) < 0x8000)) ||
           (uVar9 = DAT_00fd06, (uVar9 & 4) == 0)) {
          uVar3 = Ram00c3e4;
          FUN_c0f97a(uVar3,1);
        }
      }
    }
  }
  else {
    FUN_c0fa98();
    uVar9 = DAT_00fd06;
    DAT_00fd06 = uVar9 & 0xfffe;
    uVar9 = DAT_00fd06;
    DAT_00fd06 = uVar9 & 0xffdf;
    uVar9 = DAT_00fd06;
    DAT_00fd06 = uVar9 & 0xffef;
    uVar9 = DAT_00fd06;
    DAT_00fd06 = uVar9 & 0xfffb;
  }
  return;
}

