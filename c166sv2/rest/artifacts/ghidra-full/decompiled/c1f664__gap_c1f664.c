// c1f664 gap_c1f664 size=150 cc=unknown proto=undefined gap_c1f664(void)

void gap_c1f664(void)

{
  ushort uVar1;
  ushort uVar2;
  
  if (DAT_e00894 != '\0') {
    uRamc0409a = uRamc0409a + sRamc0782c;
    uVar2 = Ram00c09a;
    if (uRamc0782a <= uVar2) {
      uRamc0409a = uRamc0782a;
    }
    DAT_e00894 = '\0';
  }
  uRame0088e = Ram00c09a;
  uRame00a84 = uRame0088e;
  uVar2 = uRame00888 + uRamc07948;
  if (uVar2 < uRame00888) {
    uVar2 = 0xffff;
  }
  if ((uRamc07948 < uRame00888) && (uRamc0409a < uRame00888 - uRamc07948)) {
    Ram00c09a = uRame00888 - uRamc07948;
  }
  uVar1 = Ram00c09a;
  if (uVar2 < uVar1) {
    Ram00c09a = uVar2;
  }
  return;
}

