; c13104 gap_c13104 size=46
c13104  mov r12,#0x0
c13106  movb RL1,0xc5e2
c1310a  jmpr cc_EQ,0xc1312a
c1310c  cmpb RL1,#0x7
c1310e  jmpr cc_NE,0xc1312e
c13110  movb RL1,0xfd18
c13114  bclr r1.0x7
c13116  cmpb RL1,#0x0
c13118  jmpr cc_NE,0xc1312e
c1311a  mov r13,0xc5e6
c1311e  jmpr cc_EQ,0xc1312e
c13120  movb RL1,#0x81
c13124  movb 0xfd18,RL1
c13128  jmpr cc_UC,0xc1312c
c1312a  bclr 0xfd18.0x0
c1312c  mov r12,#0x1
c1312e  mov r4,r12
c13130  rets
