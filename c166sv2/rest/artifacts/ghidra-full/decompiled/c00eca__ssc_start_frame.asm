; c00eca ssc_start_frame size=30
c00eca  bclr 0xff06.0x3
c00ecc  movb RL1,#0x7
c00ece  movb 0xc094,RL1
c00ed2  mov r12,#0xc08c
c00ed6  mov 0xc096,r12
c00eda  mov r13,#0xc078
c00ede  mov 0xc098,r13
c00ee2  calls 0xc00e08
c00ee6  rets
