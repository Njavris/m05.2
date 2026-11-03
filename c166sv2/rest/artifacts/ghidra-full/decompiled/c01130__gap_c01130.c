// c01130 gap_c01130 size=12 cc=unknown proto=undefined gap_c01130(void)

/* WARNING: Control flow encountered bad instruction data */

void gap_c01130(void)

{
  undefined2 in_r1;
  short in_r3;
  
  *(undefined2 *)(uint3)(in_r3 - 2) = in_r1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

