// c2380a gap_c2380a size=84 cc=unknown proto=undefined gap_c2380a(void)

void gap_c2380a(void)

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
    uVar3 = gap_c23446(4,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = Ram00ca90;
  }
  uVar4 = gap_c289c2(uStack_4,1,0xf);
  axis16_signed(0x7716,uVar4);
  UNK_00cb39 = extraout_RH4;
  return;
}

