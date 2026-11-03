// c13f6c capture_control size=24 cc=unknown proto=undefined capture_control(void)

void capture_control(void)

{
  ushort uVar1;
  
  uVar1 = DAT_00fd10;
  if (((uVar1 & 4) == 0) && (DAT_c05064 == 0)) {
    uVar1 = DAT_00fd1a;
    DAT_00fd1a = uVar1 | 0x20;
  }
  uVar1 = DAT_00fd0c;
  if ((uVar1 & 4) == 0) {
    uVar1 = DAT_00fd1a;
    DAT_00fd1a = uVar1 | 0x10;
  }
  return;
}

