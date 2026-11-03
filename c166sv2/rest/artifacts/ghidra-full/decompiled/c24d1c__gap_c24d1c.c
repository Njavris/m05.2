// c24d1c gap_c24d1c size=36 cc=unknown proto=undefined gap_c24d1c(void)

void gap_c24d1c(ushort param_1,ushort param_2,ushort param_3,ushort param_4,ushort unaff_00000000,
               ushort unaff_00000002)

{
  if (param_1 < param_3) {
    if (param_2 < param_4) {
      *(undefined1 *)(uint3)unaff_00000000 = 0;
      return;
    }
    *(undefined1 *)(uint3)unaff_00000002 = 0;
  }
  else {
    *(undefined1 *)(uint3)unaff_00000002 = 1;
  }
  *(undefined1 *)(uint3)unaff_00000000 = 1;
  return;
}

