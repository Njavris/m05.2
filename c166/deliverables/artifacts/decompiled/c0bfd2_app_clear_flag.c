/* c0bfd2 app_clear_flag */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clear application flag. */

void app_clear_flag(void)

{
  _app_flag = 0;
  return;
}


