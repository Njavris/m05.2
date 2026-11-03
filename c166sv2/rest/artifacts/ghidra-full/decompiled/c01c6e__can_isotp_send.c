// c01c6e can_isotp_send size=90 cc=unknown proto=undefined can_isotp_send(void)

void can_isotp_send(void)

{
  short sVar1;
  char cVar2;
  undefined2 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined4 uVar7;
  
  cVar2 = DAT_00c1d6;
  if ((cVar2 != '\0') && (uVar6 = DAT_00c1d4, uVar6 != 0)) {
    if (uVar6 < 9) {
      uVar6 = DAT_00c1d4;
    }
    else {
      uVar6 = 8;
    }
    uVar3 = DAT_00c1dc;
    uVar5 = DAT_00c1de;
    uVar7 = seg_to_ptr(uVar3,uVar5,(short)&DAT_00f740,uVar6);
    memcpy_wdt((short)uVar7,(short)((uint)uVar7 >> 0x10));
    sVar1 = DAT_00c1d4;
    DAT_00c1d4 = sVar1 - uVar6;
    uVar4 = DAT_00c1dc;
    DAT_00c1dc = uVar4 + uVar6;
    sVar1 = DAT_00c1de;
    DAT_00c1de = sVar1 + (ushort)CARRY2(uVar4,uVar6);
    sVar1 = DAT_00c1d4;
    if (sVar1 == 0) {
      DAT_00c1d6 = 0;
    }
  }
  return;
}

