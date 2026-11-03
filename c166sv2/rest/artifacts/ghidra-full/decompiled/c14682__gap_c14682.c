// c14682 gap_c14682 size=92 cc=unknown proto=undefined gap_c14682(void)

undefined2 gap_c14682(char param_1,ushort param_2)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  
  uVar4 = 0;
  if ((((DAT_c05068 == 0) || (DAT_c05068 == 4)) && ((param_1 == '\0' || (param_1 == '\x01')))) &&
     ((uVar4 = 0, DAT_c05068 == 0 || (DAT_c05068 == 4)))) {
    uVar3 = DAT_00c4d4;
    uVar2 = DAT_00c4d2;
    if ((uVar3 | uVar2) != 0) {
      param_2 = param_2 & 0xff;
      do {
        bVar1 = param_2 != 0;
        param_2 = param_2 - 1;
      } while (bVar1);
      uVar4 = DAT_00c4d2;
      uVar4 = DAT_00c4d4;
      uVar4 = div32u(uVar3 | uVar2);
    }
  }
  return uVar4;
}

