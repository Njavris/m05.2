// c0fe7e ssc_pin_config size=48 cc=unknown proto=undefined ssc_pin_config(void)

void ssc_pin_config(void)

{
  ushort uVar1;
  
  ssc_mode_select();
  uVar1 = DAT_00c482;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xf0ff;
  uVar1 = DAT_00c482;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 | 0x400;
  uVar1 = DAT_00c488;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 | 0x400;
  uVar1 = DAT_00c490;
  *(ushort *)(uint3)uVar1 = *(ushort *)(uint3)uVar1 & 0xff7f;
  return;
}

