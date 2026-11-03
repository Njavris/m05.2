/* c28dec fp_neg */

/* Software float negation/absolute-value helper. */

void fp_neg(void)

{
  short in_r4;
  undefined1 auStack_2 [2];
  
  *(short *)ZEXT23(auStack_2) = -(in_r4 >> 0xf);
  if (-(in_r4 >> 0xf) != 0) {
    in_r4 = -in_r4;
  }
  if (in_r4 == 0) {
    *(undefined2 *)ZEXT23(auStack_2) = 0;
    fp_store_zero();
  }
  else {
    *(undefined2 *)ZEXT23(auStack_2) = 0;
    fp_store();
  }
  return;
}


