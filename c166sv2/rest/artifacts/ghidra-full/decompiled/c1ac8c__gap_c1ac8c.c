// c1ac8c gap_c1ac8c size=74 cc=unknown proto=undefined gap_c1ac8c(void)

void gap_c1ac8c(void)

{
  ushort uVar1;
  char cVar2;
  ushort uVar3;
  
  cVar2 = UNK_00c702;
  if (cVar2 != '\0') {
    uRamc0406a = uRamc06c50;
  }
  UNK_00c926 = 0;
  uVar1 = DAT_00c06a;
  uVar3 = uRamc06c5a;
  if (uRamc06c5a < uVar1) {
    uVar3 = uVar1;
  }
  if (uRamc06c58 < uVar3) {
    uRamc0406a = uRamc06c58;
    return;
  }
  DAT_00c06a = uVar3;
  return;
}

