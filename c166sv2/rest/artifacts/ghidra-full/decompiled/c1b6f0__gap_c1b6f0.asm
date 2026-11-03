; c1b6f0 gap_c1b6f0 size=36
c1b6f0  movb RL1,0xc954
c1b6f4  jmpr cc_NE,0xc1b702
c1b6f6  movb RL2,#0x5
c1b6f8  movb 0xc93c,RL2
c1b6fc  calls 0xc197cc
c1b700  jmpr cc_UC,0xc1b76c
c1b702  movb RL1,0xc93e
c1b706  jmpr cc_EQ,0xc1b76c
c1b708  movb RL2,#0x2
c1b70a  movb 0xc93c,RL2
c1b70e  calls 0xc197c2
c1b712  jmpr cc_UC,0xc1b76c
