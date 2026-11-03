// c2663a gap_c2663a size=70 cc=unknown proto=undefined gap_c2663a(void)

void gap_c2663a(char param_1,ushort param_2,ushort param_3,ushort param_4,ushort unaff_00000000,
               ushort unaff_00000002,ushort unaff_00000004)

{
  if (param_1 != '\x01') {
    *(undefined1 *)(uint3)param_3 = 0;
    *(undefined1 *)(uint3)param_4 = 0;
    if ((*(char *)(uint3)param_2 == '\x01') && (unaff_00000000 < unaff_00000004)) {
      *(undefined1 *)(uint3)param_2 = 0;
    }
    return;
  }
  if (unaff_00000000 < unaff_00000002) {
    *(undefined1 *)(uint3)param_3 = 1;
  }
  else {
    if (unaff_00000004 < unaff_00000000) {
      *(undefined1 *)(uint3)param_3 = 0;
      *(undefined1 *)(uint3)param_4 = 1;
      return;
    }
    *(undefined1 *)(uint3)param_3 = 0;
  }
  *(undefined1 *)(uint3)param_4 = 0;
  return;
}

