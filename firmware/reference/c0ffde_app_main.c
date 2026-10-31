/* c0ffde app_main */

/* Application main entry. */

void app_main(void)

{
  input_latch();
  app_hw_init();
  app_run(0);
  return;
}


