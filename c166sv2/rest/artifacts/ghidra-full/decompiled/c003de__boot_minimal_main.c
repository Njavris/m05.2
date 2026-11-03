// c003de boot_minimal_main size=18 cc=unknown proto=undefined boot_minimal_main(void)

void boot_minimal_main(void)

{
  asc0_init(0);
  capcom_timer_init(0);
  can_bootloader_wait();
  return;
}

