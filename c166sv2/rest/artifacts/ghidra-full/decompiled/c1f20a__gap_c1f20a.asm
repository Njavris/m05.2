; c1f20a gap_c1f20a size=36
c1f20a  extp 0x301, #0x1
c1f20e  movb RL1,0x106c
c1f212  cmpb RL1,#0x1
c1f214  jmpr cc_NE,0xc1f22c
c1f216  mov r12,#0xca80
c1f21a  mov r13,#0xca82
c1f21e  mov r14,#0x1
c1f220  calls 0xc159bc
c1f224  calls 0xc1ef36
c1f228  calls 0xc1ed9e
c1f22c  rets
