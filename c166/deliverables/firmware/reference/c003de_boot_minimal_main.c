/* c003de boot_minimal_main */

/* Reduced boot path used when configuration ADC check selects it. */

void boot_minimal_main(void)

{
  asc0_init(0);
  capcom_timer_init(0);
  can_bootloader_wait();
  return;
}


