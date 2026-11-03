// c0bfe2 app_run size=16 cc=unknown proto=undefined app_run(void)

void app_run(short param_1)

{
  if ((param_1 != 0) && (param_1 != 1)) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  app_main_init();
  return;
}

