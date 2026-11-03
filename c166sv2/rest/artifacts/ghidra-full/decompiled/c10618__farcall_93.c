// c10618 farcall_93 size=52 cc=unknown proto=undefined farcall_93(void)

void farcall_93(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  DAT_00fc60 = &stack0x0000;
  uVar4 = DPP0;
  uVar5 = DPP0;
  uVar5 = DPP0;
  DPP0 = 0x301;
  uVar5 = DPP2;
  uVar6 = DPP2;
  uVar6 = DPP2;
  DPP2 = 0x303;
  bVar1 = DAT_00c4c6;
  if ((bVar1 & 1) != 0) {
    uVar3 = DAT_00fd14;
    DAT_00fd14 = uVar3 | 4;
  }
  cVar2 = DAT_00c4c6;
  DAT_00c4c6 = cVar2 + '\x01';
  uVar3 = DAT_00f10c;
  if ((uVar3 & 2) != 0) {
    uVar3 = DAT_00f10c;
    DAT_00f10c = uVar3 & 0xfffd;
  }
  DPP2 = uVar5;
  uVar5 = DPP2;
  uVar5 = DPP2;
  uVar5 = DPP2;
  DPP0 = uVar4;
  uVar4 = DPP0;
  uVar4 = DPP0;
  uVar4 = DPP0;
  return;
}

