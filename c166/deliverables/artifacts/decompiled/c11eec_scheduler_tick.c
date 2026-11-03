/* c11eec scheduler_tick */

/* Increments the scheduler counter and dispatches command 3. */

void scheduler_tick(void)

{
  scheduler_counter = scheduler_counter + 1;
  if (scheduler_counter_reload < scheduler_counter) {
    scheduler_counter = 0;
  }
  command_dispatch_index3();
  return;
}


