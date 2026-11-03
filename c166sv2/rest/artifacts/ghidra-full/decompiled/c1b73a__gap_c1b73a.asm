; c1b73a gap_c1b73a size=70
c1b73a  movb RL1,0xc94a
c1b73e  jmpr cc_EQ,0xc1b74a
c1b740  calls 0xc1983e
c1b744  movb 0xc93c,0xff1c
c1b748  jmpr cc_UC,0xc1b76c
c1b74a  movb RL1,0xc954
c1b74e  cmpb RL1,#0x1
c1b750  jmpr cc_NE,0xc1b75e
c1b752  movb RL2,#0x1
c1b754  movb 0xc93c,RL2
c1b758  calls 0xc19830
c1b75c  jmpr cc_UC,0xc1b76c
c1b75e  mov r12,0xc9d0
c1b762  cmp r12,#0xf0
c1b766  jmpr cc_UGT,0xc1b76c
c1b76c  jb 0xfd02.0xb,0xc1b778
c1b770  mov r12,0xc9d0
c1b774  cmp r12,#0x0
c1b776  jmpr cc_ULE,0xc1b77c
c1b778  movb RL1,#0x1
c1b77a  jmpr cc_UC,0xc1b77e
c1b77c  movb RL1,#0x0
c1b77e  movb 0xc93a,RL1
c1b782  rets
