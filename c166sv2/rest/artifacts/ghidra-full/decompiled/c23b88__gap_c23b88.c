// c23b88 gap_c23b88 size=128 cc=unknown proto=undefined gap_c23b88(void)

void gap_c23b88(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 unaff_0000fff8;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(9,uVar1);
    unaff_0000fff8 = *(undefined2 *)(uint3)uVar3;
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(10,uVar1,unaff_0000fff8,*(undefined2 *)(uint3)(uVar3 + 2));
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    unaff_0000fff8 = gap_c20600();
    uStack_4 = func_0xc2060a(unaff_0000fff8);
  }
  UNK_00cb39 = 1;
  UNK_00cb38 = (char)((ushort)unaff_0000fff8 >> 8);
  UNK_00cb37 = (char)unaff_0000fff8;
  UNK_00cb36 = (char)((ushort)uStack_4 >> 8);
  UNK_00cb3d = (char)uStack_4;
  return;
}

