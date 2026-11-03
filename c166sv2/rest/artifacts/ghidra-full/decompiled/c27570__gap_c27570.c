// c27570 gap_c27570 size=50 cc=unknown proto=undefined gap_c27570(void)

void gap_c27570(void)

{
  short sVar1;
  ushort uVar2;
  
  Ram00c10a = 0;
  Ram00c1be = 0;
  Ram00c1bc = 0;
  Ram00c1c0 = 0;
  Ram00c1c2 = 0;
  uVar2 = 0;
  do {
    sVar1 = uVar2 * 2;
    uVar2 = uVar2 + 1;
    *(undefined2 *)(uint3)(ushort)((short)&UNK_00c1c4 + sVar1) = 0;
  } while (uVar2 < 0xc);
  return;
}

