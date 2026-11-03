// c0077c gap_c0077c size=284 cc=unknown proto=undefined gap_c0077c(void)

undefined2 gap_c0077c(ushort param_1,ushort param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  undefined1 uVar6;
  byte bVar7;
  undefined2 in_r4;
  undefined1 uVar8;
  
  uVar8 = (undefined1)((ushort)in_r4 >> 8);
  sVar4 = (param_1 & 0xff) * 0x20;
  uVar6 = 2;
  if ((*(ushort *)(sVar4 + 0x31a) & 0x700) == 0x200) {
    bVar7 = DAT_00c000;
    sVar5 = (ushort)bVar7 * 0x20;
    uVar2 = sVar5 + 0x310;
    uVar6 = 0;
    if ((*(ushort *)(uint3)uVar2 & 0x3000) == 0x1000) {
      uVar3 = sVar4 + 0x318;
      bVar7 = DAT_00c000;
      DAT_00c000 = bVar7 & ~((byte)*(undefined2 *)(uint3)uVar3 & 0x1f) |
                   cRam000000 + 1U & 0x1f & (byte)*(undefined2 *)(uint3)uVar3;
      *(undefined2 *)(uint3)uVar2 = 63999;
      uVar3 = sVar5 + 0x314;
      if ((*(ushort *)(uint3)uVar3 & 4) == 0) {
        *(short *)(uint3)(sVar5 + 0x30a) = *(short *)(uint3)(param_2 + 2) << 2;
        *(undefined2 *)(uint3)(sVar5 + 0x308) = 0;
      }
      else {
        uVar1 = *(undefined2 *)(uint3)(param_2 + 2);
        *(undefined2 *)(uint3)(sVar5 + 0x30a) = *(undefined2 *)(uint3)(param_2 + 4);
        *(undefined2 *)(uint3)(sVar5 + 0x308) = uVar1;
      }
      *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xf | *(ushort *)(uint3)param_2 & 0xf0;
      for (bVar7 = 0; uVar8 = 0, (ushort)bVar7 < (*(ushort *)(uint3)param_2 & 0xf0) >> 4;
          bVar7 = bVar7 + 1) {
        *(undefined1 *)(uint3)((ushort)bVar7 + sVar5 + 0x300 & 0x3fff) =
             *(undefined1 *)(uint3)(param_2 + 10 + (ushort)bVar7);
      }
      *(undefined2 *)(uint3)uVar2 = 0x66bf;
      uVar6 = 1;
    }
  }
  return CONCAT11(uVar8,uVar6);
}

