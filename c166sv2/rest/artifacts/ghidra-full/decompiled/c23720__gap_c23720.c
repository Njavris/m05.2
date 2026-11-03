// c23720 gap_c23720 size=74 cc=unknown proto=undefined gap_c23720(void)

void gap_c23720(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(2,uVar1);
    uStack_4 = *(undefined2 *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = DAT_00c936;
  }
  axis16_signed(0x76fe,uStack_4);
  UNK_00cb39 = extraout_RH4;
  return;
}

