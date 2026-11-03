// c26600 gap_c26600 size=58 cc=unknown proto=undefined gap_c26600(void)

void gap_c26600(char param_1,ushort param_2,ushort param_3,short param_4,char unaff_00000000,
               char unaff_00000002)

{
  ushort uVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  
  uVar1 = Ram00c072;
  if ((param_3 < uVar1) && (param_1 != '\0')) {
    sVar3 = DAT_00c936;
    sVar4 = DAT_00c936;
    if (((param_4 - sVar4 < 0 != SBORROW2(param_4,sVar3)) &&
        (((unaff_00000000 == '\0' || ((unaff_00000000 == '\x01' && (unaff_00000002 == '\0')))) &&
         (cVar2 = DAT_00c784, cVar2 == '\0')))) && (cVar2 = DAT_00c81c, cVar2 == '\0')) {
      *(undefined1 *)(uint3)param_2 = 1;
      return;
    }
  }
  *(undefined1 *)(uint3)param_2 = 0;
  return;
}

