// c123f4 gap_c123f4 size=80 cc=unknown proto=undefined gap_c123f4(void)

void gap_c123f4(short param_1)

{
  byte bVar1;
  char cVar2;
  byte in_RL1;
  byte bVar3;
  char in_RL2;
  byte bVar4;
  char in_RL3;
  
  if ((bRam007692 & 0x10) == 0) {
    in_RL3 = '\0';
  }
  else {
    UNK_00c55d = 4;
    UNK_00c55a = 1;
    *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)in_RL1) = 1;
    bVar4 = 0;
    bVar3 = in_RL1 + 1;
    do {
      bVar1 = UNK_00c55e;
      cVar2 = UNK_00c55e;
      UNK_00c55e = cVar2 + '\x01';
      param_1 = (0xa51e < bVar1) + 0xc0;
      in_RL1 = bVar3 + 1;
      bVar4 = bVar4 + 1;
      *(undefined1 *)(uint3)((short)&UNK_00f63d + (ushort)bVar3) =
           *(undefined1 *)(uint3)(bVar1 + 0x5ae1);
      bVar3 = in_RL1;
    } while (bVar4 < 4);
    in_RL2 = '\x01';
  }
  if (in_RL2 != '\0') {
    bVar4 = UNK_00c55a;
    bVar3 = UNK_00c55d;
    if ((bVar4 < bVar3) && (in_RL3 != '\0')) {
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
  gap_c12910(in_RL1 - 2,param_1);
  return;
}

