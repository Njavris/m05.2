; c18572 gap_c18572 size=22
c18572  movb RL1,0xc702
c18576  jmpr cc_NE,0xc18582
c18578  extp 0x301, #0x1
c1857c  movb RL2,0x222e
c18580  jmpr cc_EQ,0xc18586
c18582  movb 0xc014,0xff1c
c18586  rets
