// c22cfc gap_c22cfc size=166 cc=unknown proto=undefined gap_c22cfc(void)

void gap_c22cfc(void)

{
  ushort uVar1;
  undefined2 uVar2;
  
  if (cRamc0506c != '\x02') {
    return;
  }
  func_0xc14cec(6);
  uVar1 = DAT_00c9d0;
  if (uRamc07cf2 < uVar1) {
    uVar1 = DAT_00c9d0;
    if (uRamc07cf0 < uVar1) {
      cRame008c8 = '\x01';
    }
  }
  else {
    cRame008c8 = '\0';
  }
  if (cRame008c8 == '\0') {
    if (cRamc07cf4 == '\0') {
LAB_c22d60:
      uVar2 = func_0xc27b86(0,0x8000,0xf);
      Ram00c98c = uVar2;
      goto LAB_c22d84;
    }
  }
  else if (cRamc07cf4 == '\x01') goto LAB_c22d60;
  uVar2 = func_0xc27b86(0xffff,0x8000,0xf);
  Ram00c98c = uVar2;
LAB_c22d84:
  uVar2 = Ram00c98c;
  uVar2 = FUN_c28852(0x8000,uVar2);
  Ram00c98c = uVar2;
  func_0xc14c70(6,0x40,uVar2);
  return;
}

