; c0feae ssc_mode_select size=82
c0feae  movb RL1,#0x4
c0feb0  movb 0xc484,RL1
c0feb4  mov 0xc48c,0xff1c
c0feb8  extp 0x301, #0x1
c0febc  movb RL2,0x2b68
c0fec0  jmpr cc_NE,0xc0fefa
c0fec2  mov r12,#0x1
c0fec4  mov 0xc48a,r12
c0fec8  extp 0x301, #0x1
c0fecc  movb RL3,0x1036
c0fed0  cmpb RL3,#0x1
c0fed2  jmpr cc_EQ,0xc0feee
c0fed4  cmpb RL3,#0x2
c0fed6  jmpr cc_EQ,0xc0fede
c0fed8  cmpb RL3,#0x3
c0feda  jmpr cc_EQ,0xc0fee6
c0fedc  jmpr cc_UC,0xc0fefe
c0fede  movb RL1,#0xa
c0fee0  movb 0xc484,RL1
c0fee4  rets
c0fee6  movb RL1,#0x8
c0fee8  movb 0xc484,RL1
c0feec  rets
c0feee  mov 0xc48a,0xff1c
c0fef2  mov r12,#0x1
c0fef4  mov 0xc48c,r12
c0fef8  rets
c0fefa  mov 0xc48a,0xff1c
c0fefe  rets
