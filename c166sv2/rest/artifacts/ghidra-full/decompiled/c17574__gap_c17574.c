// c17574 gap_c17574 size=242 cc=unknown proto=undefined gap_c17574(void)

void gap_c17574(void)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  undefined1 uVar8;
  
  if ((sRame0082a < sRamc06314) || (sRamc06316 < sRame0082a)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  bVar6 = false;
  uVar3 = Ram00c8a0;
  if (uVar3 < uRamc0634e) {
    for (cVar7 = '\0'; cVar7 < '\f'; cVar7 = cVar7 + '\x01') {
      sVar1 = cVar7 * 2;
      uVar3 = Ram00c8a0;
      uVar4 = Ram00c8a0;
      if (*(ushort *)(sVar1 + 0x631e) == uVar4 || *(ushort *)(sVar1 + 0x631e) < uVar3) {
        uVar3 = Ram00c8a0;
        uVar4 = Ram00c8a0;
        if ((*(ushort *)(sVar1 + 0x6336) != uVar4 && uVar3 <= *(ushort *)(sVar1 + 0x6336)) &&
           (uVar3 = DAT_00c9d0, uVar3 <= *(ushort *)(uint3)(sVar1 + 0x6350))) {
          bVar6 = true;
        }
      }
    }
  }
  if ((sRamc04952 < sRamc06318) || (sVar1 = Ram00c952, sRamc0631a < sVar1)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((((cRamc06312 == '\0') || (!bVar5)) || (!bVar6)) ||
     ((uVar3 = DAT_00c06a, uVar3 <= uRamc0631c || (!bVar2)))) {
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
  }
  UNK_00c78e = uVar8;
  return;
}

