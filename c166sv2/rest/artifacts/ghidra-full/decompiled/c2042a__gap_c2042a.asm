; c2042a gap_c2042a size=22
c2042a  movb RL1,0xc94c
c2042e  jmpr cc_NE,0xc2043e
c20430  mov r12,0xc94e
c20434  cmp r12,0xc0ae
c20438  jmpr cc_SLE,0xc2043e
c2043a  mov 0xc0ae,r12
c2043e  rets
