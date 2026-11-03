// c23790 gap_c23790 size=84 cc=unknown proto=undefined gap_c23790(void)

void gap_c23790(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(3,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = Ram00ca8e;
  }
  uVar4 = gap_c289c2(uStack_4,1,0xf);
  axis16_signed(0x7716,uVar4);
  UNK_00cb39 = extraout_RH4;
  return;
}

