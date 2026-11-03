; c1318e gap_c1318e size=46
c1318e  mov r12,#0x0
c13190  movb RL1,0xc5e2
c13194  jmpr cc_EQ,0xc131b4
c13196  cmpb RL1,#0x7
c13198  jmpr cc_NE,0xc131b8
c1319a  movb RL1,0xfd18
c1319e  bclr r1.0x7
c131a0  cmpb RL1,#0x0
c131a2  jmpr cc_NE,0xc131b8
c131a4  mov r13,0xc5e6
c131a8  jmpr cc_EQ,0xc131b8
c131aa  movb RL1,#0x84
c131ae  movb 0xfd18,RL1
c131b2  jmpr cc_UC,0xc131b6
c131b4  bclr 0xfd18.0x2
c131b6  mov r12,#0x1
c131b8  mov r4,r12
c131ba  rets
