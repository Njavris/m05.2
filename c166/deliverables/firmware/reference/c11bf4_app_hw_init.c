/* c11bf4 app_hw_init */

/* WARNING: Control flow encountered bad instruction data */
/* Application hardware initialization sequence. */

void app_hw_init(void)

{
  ushort uVar1;
  
  can_bus_config();
  uVar1 = DAT_00f0fe;
  DAT_00f0fe = uVar1 | 1;
  P7 = 0x7f13;
  port_bus_init();
  adc_calibrate();
  adc_start();
  asc0_init_app();
  ssc0_init_app();
  ssc_rx_queue_init();
  pwm_init();
  timer8_init();
  capcom_start();
  timer5_init();
  app_clear_flag();
  capture_init();
  config_sensor_setup();
  timer6_start();
  angle_init();
  event_init();
  timer4_init();
  ssc_init();
  set_can_flag();
  cal_checksum();
  can_bus_config();
  WDTCON = 0xbc01;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


