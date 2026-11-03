; c13132 gap_c13132 size=46
c13132  mov r12,#0x0
c13134  movb RL1,0xc5e2
c13138  jmpr cc_EQ,0xc13158
c1313a  cmpb RL1,#0x7
c1313c  jmpr cc_NE,0xc1315c
c1313e  movb RL1,0xfd18
c13142  bclr r1.0x7
c13144  cmpb RL1,#0x0
c13146  jmpr cc_NE,0xc1315c
c13148  mov r13,0xc5e6
c1314c  jmpr cc_EQ,0xc1315c
c1314e  movb RL1,#0x82
c13152  movb 0xfd18,RL1
c13156  jmpr cc_UC,0xc1315a
c13158  bclr 0xfd18.0x1
c1315a  mov r12,#0x1
c1315c  mov r4,r12
c1315e  rets
