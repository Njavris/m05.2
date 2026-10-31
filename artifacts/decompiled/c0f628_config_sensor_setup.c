/* c0f628 config_sensor_setup */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Selects sensor/ADC handler pointers from calibration config 0xC05036 and builds a float
   threshold. */

void config_sensor_setup(void)

{
  undefined2 in_r1;
  byte bVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  
  uVar3 = PSW;
  PSW = uVar3 & 0xf7ff;
  uVar3 = test_status;
  test_status = uVar3 & 0xfffe;
  uVar3 = test_status;
  test_status = uVar3 & 0xfffd;
  bVar1 = (byte)((ushort)in_r1 >> 8);
  if (cal_config_selector < 4) {
    _sensor_var_c23c = 0xd09a;
    _sensor_var_c23e = 0xc0;
    _sensor_var_c22c = 0xd07c;
    _sensor_var_c22e = 0xc0;
    _sensor_var_c234 = 0xd08e;
    _sensor_var_c236 = 0xc0;
    _sensor_setup = 0xd0b2;
    _sensor_var_c222 = 0xc0;
    sensor_channel_count = 2;
    _sensor_var_c238 = 0xd0a0;
    _sensor_var_c23a = 0xc0;
    _sensor_var_c228 = 0xd082;
    _sensor_var_c22a = 0xc0;
    _sensor_var_c230 = 0xd094;
    _sensor_var_c232 = 0xc0;
    if (cal_config_selector == 2) {
      uVar3 = CONCAT11(bVar1,0x5a);
      _sensor_cfg_flag_2 = _sensor_cfg_flag_2 | 0x200;
      sVar4 = (short)&sensor_coeff_table_2;
      _capture_irq_mask = _capture_irq_mask | 0x204;
    }
    else if (cal_config_selector == 3) {
      uVar3 = CONCAT11(bVar1,0x3c);
      _capture_enable = _capture_enable | 0x200;
      _sensor_cfg_flag_1 = _sensor_cfg_flag_1 | 0x200;
      sVar4 = (short)&sensor_coeff_table_1;
      _capture_irq_mask = _capture_irq_mask | 4;
    }
    else if (cal_config_selector == 0) {
      uVar3 = CONCAT11(bVar1,0xb4);
      _sensor_cfg_flag_3 = _sensor_cfg_flag_3 | 0x200;
      _sensor_cfg_flag_4 = _sensor_cfg_flag_4 | 0x200;
      sVar4 = (short)&sensor_coeff_table_3;
      _capture_irq_mask = _capture_irq_mask | 0x204;
    }
    else {
      uVar3 = (ushort)bVar1 << 8;
      sVar4 = (short)&sensor_coeff_table_0;
      _capture_irq_mask = _capture_irq_mask | 4;
    }
    _capture_irq_mask_2 = _capture_irq_mask_2 | 0x200;
    _sensor_setup_flag = 0;
    fp_load(CONCAT11((char)(uVar3 >> 8),(char)((uVar3 & 0xff) / 0xf)));
    fp_neg();
    sVar2 = fp_compare();
    if (sVar2 == -1) {
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
    uVar3 = fp_to_int();
    uVar3 = (uVar3 & 0xff) * 2 + 0xc282;
    bVar1 = 0;
    *(ushort *)(uint3)uVar3 = *(ushort *)(uint3)uVar3 & 0xfff7 | 8;
    do {
      sVar2 = (ushort)bVar1 * 2;
      bVar1 = bVar1 + 1;
      *(undefined1 *)(uint3)(ushort)((short)&sensor_coefficients + sVar2) =
           *(undefined1 *)(uint3)(ushort)(sVar4 + sVar2);
      *(undefined1 *)(uint3)(sVar2 + 0xc469) = *(undefined1 *)(uint3)(ushort)(sVar4 + 1 + sVar2);
    } while (bVar1 < 5);
    for (bVar1 = 0; bVar1 < sensor_channel_count; bVar1 = bVar1 + 1) {
      *(undefined1 *)(uint3)((ushort)bVar1 * 0x1a + 0xc3da) = 0;
      *(undefined1 *)(uint3)((ushort)bVar1 * 0x1a + 0xc3d9) = 0;
    }
    cc22_23_output_init();
    cc_control_ptr_init();
  }
  output_gate_0 = 0x4800;
  output_gate_1 = 0x4800;
  cc_output_gate_update();
  cc22_23_started = 0;
  uVar3 = PSW;
  PSW = uVar3 | 0x800;
  return;
}


