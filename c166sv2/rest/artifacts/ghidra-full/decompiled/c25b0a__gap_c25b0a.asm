; c25b0a gap_c25b0a size=46
c25b0a  movb RL1,0xc954
c25b0e  cmpb RL1,#0x1
c25b10  jmpr cc_NE,0xc25b2e
c25b12  movb RL2,0xc93c
c25b16  cmpb RL2,#0x3
c25b18  jmpr cc_EQ,0xc25b22
c25b1a  cmpb RL2,#0x4
c25b1c  jmpr cc_EQ,0xc25b22
c25b1e  cmpb RL2,#0x1
c25b20  jmpr cc_NE,0xc25b2e
c25b22  movb RL1,#0x1
c25b24  extp 0x380, #0x1
c25b28  movb 0x8d3,RL1
c25b2c  rets
c25b2e  extp 0x380, #0x1
c25b32  movb 0x8d3,0xff1c
c25b36  rets
