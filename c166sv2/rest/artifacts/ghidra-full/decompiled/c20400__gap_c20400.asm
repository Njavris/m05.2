; c20400 gap_c20400 size=26
c20400  extp 0x380, #0x1
c20404  movb RL1,0x830
c20408  jmpr cc_NE,0xc20418
c2040a  mov r12,0xc936
c2040e  cmp r12,0xc0ba
c20412  jmpr cc_SLE,0xc20418
c20414  mov 0xc0ba,r12
c20418  rets
