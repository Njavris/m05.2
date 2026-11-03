// c2385e gap_c2385e size=62 cc=unknown proto=undefined gap_c2385e(void)

void gap_c2385e(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(5,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = DAT_00ca04;
  }
  UNK_00cb39 = (char)((ushort)uStack_4 >> 8);
  return;
}

