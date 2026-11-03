// c0d9e4 ssc_init size=126 cc=unknown proto=undefined ssc_init(void)

void ssc_init(void)

{
  short sVar1;
  ushort uVar2;
  
  uVar2 = PSW;
  PSW = uVar2 & 0xf7ff;
  DAT_00c218 = 0xd8fa;
  DAT_00c21a = 0xc0;
  DAT_00c21c = 0xd914;
  DAT_00c21e = 0xc0;
  cc26_ptr_init();
  uVar2 = DAT_00c490;
  *(ushort *)(uint3)uVar2 = *(ushort *)(uint3)uVar2 | 0x68;
  ssc_pin_config();
  sVar1 = DAT_00c48a;
  if (sVar1 != 0) {
    DAT_00c214 = 0xd8ce;
    DAT_00c216 = 0xc0;
  }
  sVar1 = DAT_00c48c;
  if ((sVar1 == 0) && (sVar1 = DAT_00c48a, sVar1 == 0)) {
    DAT_00c3ba = 1;
    sVar1 = DAT_00c48a;
    if (sVar1 == 0) {
      DAT_00c214 = 0xd8ce;
      DAT_00c216 = 0xc0;
    }
  }
  else {
    DAT_00c3ba = 0;
  }
  uVar2 = PSW;
  PSW = uVar2 | 0x800;
  return;
}

