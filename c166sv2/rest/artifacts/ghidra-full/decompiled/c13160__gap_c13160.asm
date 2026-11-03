; c13160 gap_c13160 size=46
c13160  mov r12,#0x0
c13162  movb RL1,0xc5e2
c13166  jmpr cc_EQ,0xc13186
c13168  cmpb RL1,#0x7
c1316a  jmpr cc_NE,0xc1318a
c1316c  movb RL1,0xfd18
c13170  bclr r1.0x7
c13172  cmpb RL1,#0x0
c13174  jmpr cc_NE,0xc1318a
c13176  mov r13,0xc5e6
c1317a  jmpr cc_EQ,0xc1318a
c1317c  movb RL1,#0x88
c13180  movb 0xfd18,RL1
c13184  jmpr cc_UC,0xc13188
c13186  bclr 0xfd18.0x3
c13188  mov r12,#0x1
c1318a  mov r4,r12
c1318c  rets
