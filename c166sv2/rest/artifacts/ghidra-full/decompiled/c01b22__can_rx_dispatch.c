// c01b22 can_rx_dispatch size=194 cc=unknown proto=undefined can_rx_dispatch(void)

void can_rx_dispatch(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined1 uVar6;
  
  sVar1 = DAT_00c1d2;
  if (sVar1 == 10) {
    bVar3 = DAT_00f744;
    DAT_00c1d4 = (ushort)bVar3;
    DAT_00c1d4 = (ushort)bVar3 << 8;
    bVar3 = DAT_00f745;
    uVar2 = DAT_00c1d4;
    DAT_00c1d4 = uVar2 | bVar3;
    bVar3 = DAT_00f740;
    DAT_00c1d8 = (ushort)bVar3;
    DAT_00c1da = 0;
    uVar4 = DAT_00f741;
    DAT_00c1d8 = CONCAT11(bVar3,uVar4);
    DAT_00c1da = 0;
    bVar5 = DAT_00f742;
    DAT_00c1d8 = CONCAT11(bVar3,uVar4) << 8 | (ushort)bVar5;
    DAT_00c1da = (ushort)bVar3;
    uVar6 = DAT_00f743;
    DAT_00c1d8 = CONCAT11(bVar5,uVar6);
    DAT_00c1da = CONCAT11(bVar3,uVar4);
    DAT_00c1dc = CONCAT11(bVar5,uVar6);
    DAT_00c1de = CONCAT11(bVar3,uVar4);
    can_rx_cmd();
  }
  sVar1 = DAT_00c1d2;
  if (sVar1 == 9) {
    can_isotp_send();
  }
  return;
}

