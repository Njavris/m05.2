// c236c6 gap_c236c6 size=90 cc=unknown proto=undefined gap_c236c6(void)

void gap_c236c6(void)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined1 extraout_RH4;
  undefined2 uStack_4;
  
  cVar2 = UNK_00cb2d;
  if (cVar2 == ' ') {
    uVar1 = UNK_00cb25;
    uVar3 = gap_c23446(1,uVar1);
    uStack_4 = *(ushort *)(uint3)uVar3;
  }
  else if (cVar2 == '\x10') {
    uStack_4 = DAT_00ca2a;
  }
  if (uStack_4 < 0x7fff) {
    axis16_unsigned(0x7710,uStack_4);
    uStack_4._1_1_ = extraout_RH4;
  }
  else {
    uStack_4._1_1_ = 0xff;
  }
  UNK_00cb39 = uStack_4._1_1_;
  return;
}

