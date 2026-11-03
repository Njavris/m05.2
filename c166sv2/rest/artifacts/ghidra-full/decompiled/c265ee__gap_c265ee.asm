; c265ee gap_c265ee size=18
c265ee  cmp r12,0xc962
c265f2  jmpr cc_UGT,0xc265fa
c265f4  movb RL1,#0x1
c265f6  movb [r13],RL1
c265f8  rets
c265fa  movb RL1,#0x0
c265fc  movb [r13],RL1
c265fe  rets
