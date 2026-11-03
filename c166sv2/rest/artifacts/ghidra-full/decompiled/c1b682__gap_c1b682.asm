; c1b682 gap_c1b682 size=36
c1b682  movb RL1,0xc954
c1b686  jmpr cc_NE,0xc1b694
c1b688  movb RL2,#0x5
c1b68a  movb 0xc93c,RL2
c1b68e  calls 0xc19806
c1b692  jmpr cc_UC,0xc1b76c
c1b694  movb RL1,0xc939
c1b698  jmpr cc_EQ,0xc1b76c
c1b69a  movb RL2,#0x2
c1b69c  movb 0xc93c,RL2
c1b6a0  calls 0xc19810
c1b6a4  jmpr cc_UC,0xc1b76c
