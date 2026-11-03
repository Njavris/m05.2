// c0ffde app_main size=16 cc=unknown proto=undefined app_main(void)

void app_main(void)

{
  input_latch();
  app_hw_init();
  app_run(0);
  return;
}

