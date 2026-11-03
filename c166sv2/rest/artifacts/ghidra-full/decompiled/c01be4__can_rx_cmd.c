// c01be4 can_rx_cmd size=138 cc=unknown proto=undefined can_rx_cmd(void)

void can_rx_cmd(void)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined2 uVar4;
  char cVar5;
  ushort uVar6;
  undefined4 uVar7;
  
  cVar5 = DAT_00f746;
  if (cVar5 == -1) {
    can_tx_confirm();
    while (sVar1 = DAT_00c1d4, sVar1 != 0) {
      uVar6 = DAT_00c1d4;
      if (uVar6 < 9) {
        uVar6 = DAT_00c1d4;
      }
      else {
        uVar6 = 8;
      }
      uVar7 = seg_to_ptr((short)&UNK_00f750,uVar6);
      uVar2 = DAT_00c1dc;
      uVar4 = DAT_00c1de;
      memcpy_wdt((short)uVar7,(short)((uint)uVar7 >> 0x10),uVar2,uVar4);
      can_tx_frame(uVar6);
      sVar1 = DAT_00c1d4;
      DAT_00c1d4 = sVar1 - uVar6;
      uVar3 = DAT_00c1dc;
      DAT_00c1dc = uVar3 + uVar6;
      sVar1 = DAT_00c1de;
      DAT_00c1de = sVar1 + (ushort)CARRY2(uVar3,uVar6);
      __service_watchdog();
    }
  }
  else {
    cVar5 = DAT_00f746;
    if ((cVar5 == '\0') && (sVar1 = DAT_00c1d4, sVar1 != 0)) {
      DAT_00c1d6 = 1;
      can_tx_confirm();
    }
  }
  return;
}

