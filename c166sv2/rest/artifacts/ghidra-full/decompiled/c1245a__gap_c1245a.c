// c1245a gap_c1245a size=128 cc=unknown proto=undefined gap_c1245a(void)

void gap_c1245a(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  byte bVar4;
  byte in_RL1;
  char in_RL2;
  char in_RL3;
  
  if ((bRam007692 & 4) == 0) {
    in_RL3 = '\0';
  }
  else {
    *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)in_RL1) = 1;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 1)) = 0;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 2)) = 0;
    uVar3 = DAT_00c546;
    bVar1 = in_RL1 + 4;
    *(char *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 3)) = (char)((ushort)uVar3 >> 8);
    uVar2 = DAT_00c546._0_1_;
    in_RL1 = in_RL1 + 5;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar1) = uVar2;
  }
  if (in_RL2 != '\0') {
    bVar1 = UNK_00c55a;
    bVar4 = UNK_00c55d;
    if ((bVar1 < bVar4) && (in_RL3 != '\0')) {
      DAT_00c5b6 = 1;
      if ((byte)(in_RL1 - 2) == '\0') {
        return;
      }
      goto LAB_c124cc;
    }
  }
  if (in_RL3 == '\0') {
    func_0xc128ec(0x12);
    return;
  }
LAB_c124cc:
  gap_c12910(in_RL1 - 2);
  return;
}

