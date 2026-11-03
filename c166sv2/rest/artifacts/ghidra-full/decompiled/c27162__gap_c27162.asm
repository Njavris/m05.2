; c27162 gap_c27162 size=54
c27162  calls 0xc27198
c27166  mov r12,#0x1e
c2716a  extp 0x380, #0x1
c2716e  movbz r13,0x8f8
c27172  extp 0x380, #0x1
c27176  movbz r14,0x8f9
c2717a  calls 0xc24d82
c2717e  mov r12,#0x1e
c27182  calls 0xc24530
c27186  cmpb RL4,#0x0
c27188  jmpr cc_EQ,0xc27192
c2718a  movb RL1,#0x1
c2718c  movb 0xcca4,RL1
c27190  rets
c27192  movb 0xcca4,0xff1c
c27196  rets
