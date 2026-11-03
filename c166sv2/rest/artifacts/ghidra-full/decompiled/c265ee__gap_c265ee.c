// c265ee gap_c265ee size=18 cc=unknown proto=undefined gap_c265ee(void)

void gap_c265ee(ushort param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = DAT_00c962;
  uVar2 = DAT_00c962;
  if (param_1 != uVar2 && uVar1 <= param_1) {
    *(undefined1 *)(uint3)param_2 = 0;
    return;
  }
  *(undefined1 *)(uint3)param_2 = 1;
  return;
}

