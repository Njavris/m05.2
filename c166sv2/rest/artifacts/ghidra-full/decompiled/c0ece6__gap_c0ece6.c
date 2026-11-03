// c0ece6 gap_c0ece6 size=60 cc=unknown proto=undefined gap_c0ece6(void)

undefined2 gap_c0ece6(void)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  
  uVar3 = 0;
  sVar2 = Ram00c44e;
  if (sVar2 == 1) {
    uVar1 = Ram00c072;
    if (uRamc0508c < uVar1) {
      uVar1 = DAT_00c266;
      if (uVar1 <= uRamc0508a) {
        return 0;
      }
    }
    else {
      uVar1 = DAT_00c266;
      if (uVar1 <= uRamc05088) {
        return 0;
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}

