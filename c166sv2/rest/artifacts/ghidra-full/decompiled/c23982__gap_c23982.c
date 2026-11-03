// c23982 gap_c23982 size=88 cc=unknown proto=undefined gap_c23982(void)

void gap_c23982(void)

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
    uVar3 = gap_c23446(8,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = Ram00ca38;
  }
  uVar4 = func_0xc27b86(uStack_4,0xffff,0xf);
  axis16_unsigned(0x770a,uVar4);
  UNK_00cb39 = extraout_RH4;
  return;
}

