; c1b6a6 gap_c1b6a6 size=38
c1b6a6  movb RL1,0xc943
c1b6aa  jmpr cc_EQ,0xc1b6ba
c1b6ac  movb RL2,#0x3
c1b6ae  movb 0xc93c,RL2
c1b6b2  calls 0xc197e4
c1b6b6  bclr 0xfd02.0x9
c1b6b8  jmpr cc_UC,0xc1b76c
c1b6ba  movb RL1,0xc944
c1b6be  jmpr cc_EQ,0xc1b76c
c1b6c0  movb RL2,#0x4
c1b6c2  movb 0xc93c,RL2
c1b6c6  calls 0xc197ac
c1b6ca  jmpr cc_UC,0xc1b76c
