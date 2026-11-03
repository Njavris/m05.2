; c1b784 gap_c1b784 size=50
c1b784  movb RL1,0xc93c
c1b788  cmpb RL1,#0x3
c1b78a  jmpr cc_NE,0xc1b7a6
c1b78c  mov r12,0xc072
c1b790  cmp r12,#0xffff
c1b794  jmpr cc_NC,0xc1b7a0
c1b796  sub 0xc072,0xff1e
c1b79a  movb RL2,#0x1
c1b79c  movb 0xc93d,RL2
c1b7a0  calls 0xc20450
c1b7a4  rets
c1b7a6  mov r12,0xc072
c1b7aa  jmpr cc_EQ,0xc1b7b0
c1b7ac  mov 0xc06c,r12
c1b7b0  mov 0xc072,0xff1c
c1b7b4  rets
