; c1b714 gap_c1b714 size=38
c1b714  movb RL1,0xc954
c1b718  cmpb RL1,#0x1
c1b71a  jmpr cc_NE,0xc1b728
c1b71c  movb RL2,#0x1
c1b71e  movb 0xc93c,RL2
c1b722  calls 0xc1981a
c1b726  jmpr cc_UC,0xc1b76c
c1b728  movb RL1,0xc940
c1b72c  jmpr cc_EQ,0xc1b76c
c1b72e  movb RL2,#0x6
c1b730  movb 0xc93c,RL2
c1b734  calls 0xc197f8
c1b738  jmpr cc_UC,0xc1b76c
