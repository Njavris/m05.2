/* c0bd54 p1l1_set */

/* Sets port P1L.1. */

void p1l1_set(void)

{
  ushort uVar1;
  
  uVar1 = P1L;
  P1L = uVar1 | 2;
  return;
}


