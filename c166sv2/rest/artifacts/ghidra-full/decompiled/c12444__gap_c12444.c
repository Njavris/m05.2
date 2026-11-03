// c12444 gap_c12444 size=22 cc=unknown proto=undefined gap_c12444(void)

void gap_c12444(void)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  byte in_RL1;
  char in_RL2;
  char in_RL3;
  
  if ((bRam007692 & 8) == 0) {
    in_RL3 = '\0';
  }
  else {
    uVar1 = (ushort)in_RL1;
    in_RL1 = in_RL1 + 1;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + uVar1) = 1;
  }
  if (in_RL2 != '\0') {
    bVar2 = UNK_00c55a;
    bVar3 = UNK_00c55d;
    if ((bVar2 < bVar3) && (in_RL3 != '\0')) {
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

