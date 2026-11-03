; c1a44e gap_c1a44e size=134
c1a44e  movb RL1,0xc81c
c1a452  jmpr cc_EQ,0xc1a492
c1a454  mov r12,0xc8e0
c1a458  extp 0x301, #0x1
c1a45c  cmp r12,0x2506
c1a460  jmpr cc_SLE,0xc1a46c
c1a462  extp 0x301, #0x1
c1a466  mov r12,0x2506
c1a46a  jmpr cc_UC,0xc1a488
c1a46c  mov r12,0xc8e0
c1a470  extp 0x301, #0x1
c1a474  cmp r12,0x2508
c1a478  jmpr cc_SGE,0xc1a484
c1a47a  extp 0x301, #0x1
c1a47e  mov r12,0x2508
c1a482  jmpr cc_UC,0xc1a488
c1a484  mov r12,0xc8e0
c1a488  mov 0xc8e0,r12
c1a48c  mov 0xc8ea,r12
c1a490  jmpr cc_UC,0xc1a4ca
c1a492  mov r12,0xc8e8
c1a496  extp 0x301, #0x1
c1a49a  cmp r12,0x2506
c1a49e  jmpr cc_SLE,0xc1a4aa
c1a4a0  extp 0x301, #0x1
c1a4a4  mov r12,0x2506
c1a4a8  jmpr cc_UC,0xc1a4c6
c1a4aa  mov r12,0xc8e8
c1a4ae  extp 0x301, #0x1
c1a4b2  cmp r12,0x2508
c1a4b6  jmpr cc_SGE,0xc1a4c2
c1a4b8  extp 0x301, #0x1
c1a4bc  mov r12,0x2508
c1a4c0  jmpr cc_UC,0xc1a4c6
c1a4c2  mov r12,0xc8e8
c1a4c6  mov 0xc8ea,r12
c1a4ca  calls 0xc1e610
c1a4ce  calls 0xc1a3c6
c1a4d2  rets
