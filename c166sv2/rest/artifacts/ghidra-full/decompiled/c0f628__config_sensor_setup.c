// c0f628 config_sensor_setup size=532 cc=unknown proto=undefined config_sensor_setup(void)

void config_sensor_setup(void)

{
  ushort uVar1;
  byte bVar2;
  undefined2 in_r1;
  byte bVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  
  uVar5 = PSW;
  PSW = uVar5 & 0xf7ff;
  uVar5 = DAT_00fd0a;
  DAT_00fd0a = uVar5 & 0xfffe;
  uVar5 = DAT_00fd0a;
  DAT_00fd0a = uVar5 & 0xfffd;
  bVar3 = (byte)((ushort)in_r1 >> 8);
  if (DAT_c05036 < 4) {
    DAT_00c23c = 0xd09a;
    DAT_00c23e = 0xc0;
    DAT_00c22c = 0xd07c;
    DAT_00c22e = 0xc0;
    DAT_00c234 = 0xd08e;
    DAT_00c236 = 0xc0;
    DAT_00c220 = 0xd0b2;
    DAT_00c222 = 0xc0;
    uVar5 = DAT_00c28a;
    DAT_00c28a = uVar5 | 4;
    DAT_00c45e = 2;
    DAT_00c238 = 0xd0a0;
    DAT_00c23a = 0xc0;
    DAT_00c228 = 0xd082;
    DAT_00c22a = 0xc0;
    DAT_00c230 = 0xd094;
    DAT_00c232 = 0xc0;
    if (DAT_c05036 == 2) {
      uVar5 = CONCAT11(bVar3,0x5a);
      uVar1 = DAT_00c28a;
      DAT_00c28a = uVar1 | 0x200;
      uVar1 = DAT_00c290;
      DAT_00c290 = uVar1 | 0x200;
      sVar6 = 0x7022;
    }
    else if (DAT_c05036 == 3) {
      uVar5 = CONCAT11(bVar3,0x3c);
      uVar1 = DAT_00c2aa;
      DAT_00c2aa = uVar1 | 0x200;
      uVar1 = DAT_00c28c;
      DAT_00c28c = uVar1 | 0x200;
      sVar6 = 0x7018;
    }
    else if (DAT_c05036 == 0) {
      uVar5 = CONCAT11(bVar3,0xb4);
      uVar1 = DAT_00c28a;
      DAT_00c28a = uVar1 | 0x200;
      uVar1 = DAT_00c296;
      DAT_00c296 = uVar1 | 0x200;
      uVar1 = DAT_00c29c;
      DAT_00c29c = uVar1 | 0x200;
      sVar6 = 0x702c;
    }
    else {
      uVar5 = (ushort)bVar3 << 8;
      sVar6 = 0x700e;
    }
    uVar1 = DAT_00c2a2;
    DAT_00c2a2 = uVar1 | 0x200;
    DAT_00c44c = 0;
    fp_load(CONCAT11((char)(uVar5 >> 8),(char)((uVar5 & 0xff) / 0xf)));
    fp_neg();
    sVar4 = fp_compare();
    if (sVar4 == -1) {
      fp_load();
      fp_neg();
      fp_div_signed();
      fp_copy();
    }
    else {
      fp_neg();
      fp_load();
      fp_div_unsigned();
      fp_copy();
    }
    uVar5 = fp_to_int();
    uVar5 = (short)&DAT_00c282 + (uVar5 & 0xff) * 2;
    bVar3 = 0;
    *(ushort *)(uint3)uVar5 = *(ushort *)(uint3)uVar5 & 0xfff7 | 8;
    do {
      sVar4 = (ushort)bVar3 * 2;
      bVar3 = bVar3 + 1;
      *(undefined1 *)(uint3)(ushort)((short)&DAT_00c468 + sVar4) =
           *(undefined1 *)(uint3)(ushort)(sVar6 + sVar4);
      *(undefined1 *)(uint3)(ushort)((short)&DAT_00c469 + sVar4) =
           *(undefined1 *)(uint3)(ushort)(sVar6 + 1 + sVar4);
    } while (bVar3 < 5);
    for (bVar3 = 0; bVar2 = DAT_00c45e, bVar3 < bVar2; bVar3 = bVar3 + 1) {
      *(undefined1 *)(uint3)((short)&DAT_00c3da + (ushort)bVar3 * 0x1a) = 0;
      *(undefined1 *)(uint3)((short)&DAT_00c3d9 + (ushort)bVar3 * 0x1a) = 0;
    }
    cc22_23_output_init();
    cc_control_ptr_init();
  }
  DAT_00fd08 = 0x4800;
  DAT_00fd06 = 0x4800;
  cc_output_gate_update();
  DAT_00c456 = 0;
  uVar5 = PSW;
  PSW = uVar5 | 0x800;
  return;
}

