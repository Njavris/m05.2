// c126da kline_prepare_frame size=200 cc=unknown proto=undefined kline_prepare_frame(void)

void kline_prepare_frame(undefined1 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  
  DAT_00c5a9 = param_1;
  DAT_00c59e = 0;
  cVar4 = DAT_00c5a0;
  if (cVar4 != '\0') {
    bVar3 = DAT_00c599;
    bVar1 = DAT_00c57f;
    DAT_00c5a6 = (short)(bVar3 + 0xf) >> 4;
    uVar5 = (ushort)bVar1;
    if (0xf0 < uVar5) {
      uVar5 = uVar5 * 0x100 + 0x1000;
    }
    DAT_00c5a5 = bVar1;
    uVar2 = DAT_00c598;
    DAT_00c57e = uVar2;
    uVar2 = DAT_00c580;
    DAT_00c5a8 = uVar2;
    uVar2 = DAT_00c592;
    DAT_00c577 = uVar2;
    bVar1 = DAT_00c57e;
    DAT_00c5bc = (short)(bVar1 + 0xf) >> 4;
    cVar4 = DAT_00c5a8;
    DAT_00c57c = bVar3;
    DAT_00c59c = (uVar5 << 5) / 10;
    if (cVar4 == -1) {
      DAT_00c5b4 = 0xffff;
    }
    else {
      bVar1 = DAT_00c5a8;
      DAT_00c5b4 = (ushort)bVar1 << 5;
    }
    bVar1 = DAT_00c577;
    DAT_00c586 = (short)(bVar1 + 0xf) >> 4;
    DAT_00c5a0 = 0;
  }
  DAT_00c584 = 6;
  DAT_00c58c = 0;
  DAT_00c56f = 0;
  uVar5 = S0CON;
  S0CON = uVar5 | 0x10;
  return;
}

