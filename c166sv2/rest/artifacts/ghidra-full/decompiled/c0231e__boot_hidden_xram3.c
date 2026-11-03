// c0231e boot_hidden_xram3 size=24 cc=unknown proto=undefined boot_hidden_xram3(void)

void boot_hidden_xram3(void)

{
  SSCCON = 0;
  SSCBR = 1;
  SSCCON = 0xc037;
  return;
}

