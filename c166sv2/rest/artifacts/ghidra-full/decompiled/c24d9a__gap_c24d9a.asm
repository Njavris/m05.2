; c24d9a gap_c24d9a size=54
c24d9a  mov [-r0],r8
c24d9c  mov r8,r15
c24d9e  mov r1,r14
c24da0  mov r2,r13
c24da2  cmpb RL2,#0x0
c24da4  jmpr cc_EQ,0xc24dcc
c24da6  cmpb RL1,#0x0
c24da8  jmpr cc_EQ,0xc24dba
c24daa  movb RL2,[r8]
c24dac  cmpb RL2,#0x2
c24dae  jmpr cc_EQ,0xc24dba
c24db0  calls 0xc25710
c24db4  movb RL1,#0x2
c24db6  movb [r8],RL1
c24db8  jmpr cc_UC,0xc24dcc
c24dba  cmpb RL1,#0x0
c24dbc  jmpr cc_NE,0xc24dcc
c24dbe  movb RL1,[r8]
c24dc0  cmpb RL1,#0x1
c24dc2  jmpr cc_EQ,0xc24dcc
c24dc4  calls 0xc2572c
c24dc8  movb RL1,#0x1
c24dca  movb [r8],RL1
c24dcc  mov r8,[r0+]
c24dce  rets
