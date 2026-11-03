// c12398 gap_c12398 size=70 cc=unknown proto=undefined gap_c12398(void)

void gap_c12398(void)

{
  byte bVar1;
  byte bVar2;
  byte in_RL1;
  char in_RL2;
  char in_RL3;
  
  *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)in_RL1) = 1;
  *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 1)) = uRam007692;
  *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 2)) = uRam007694;
  *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 3)) = uRam0076bd;
  *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)(byte)(in_RL1 + 4)) = uRam0076be;
  if (in_RL2 != '\0') {
    bVar1 = UNK_00c55a;
    bVar2 = UNK_00c55d;
    if ((bVar1 < bVar2) && (in_RL3 != '\0')) {
      DAT_00c5b6 = 1;
      if ((byte)(in_RL1 + 3) == '\0') {
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
  gap_c12910(in_RL1 + 3);
  return;
}

