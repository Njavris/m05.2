; c239f6 gap_c239f6 size=24
c239f6  movb RL1,0xcb2d
c239fa  cmpb RL1,#0x10
c239fe  jmpr cc_NE,0xc23a0c
c23a00  extp 0x301, #0x1
c23a04  movb RL1,0x3d10
c23a08  movb 0xcb39,RL1
c23a0c  rets
