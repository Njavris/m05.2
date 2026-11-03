; c247e6 gap_c247e6 size=28
c247e6  mov [-r0],r12
c247e8  calls 0xc24724
c247ec  mov r12,[r0+]
c247ee  cmpb RL4,#0x0
c247f0  jmpr cc_EQ,0xc24800
c247f2  movb RL1,#0x1
c247f4  mov [-r0],r1
c247f6  calls 0xc2473a
c247fa  mov r1,[r0+]
c247fc  movb [r4+#0xcb6c],RL1
c24800  rets
