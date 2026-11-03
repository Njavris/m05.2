; c1da6e gap_c1da6e size=170
c1da6e  mov [-r0],r9
c1da70  mov [-r0],r8
c1da72  mov r8,r12
c1da74  mov r12,#0x50dc
c1da78  mov r13,#0xc0
c1da7c  mov r14,0xc9d0
c1da80  calls 0xc28544
c1da84  mov r9,r4
c1da86  mov r12,#0x6d0c
c1da8a  mov r13,#0xc0
c1da8e  mov r14,r8
c1da90  calls 0xc28544
c1da94  mov r14,r4
c1da96  mov r12,#0x70f6
c1da9a  mov r13,#0xc0
c1da9e  mov r15,r14
c1daa0  mov r14,r9
c1daa2  calls 0xc2826e
c1daa6  mov 0xca00,r4
c1daaa  movb RL1,0xc9e7
c1daae  extp 0x301, #0x1
c1dab2  cmpb RL1,0x30f2
c1dab6  jmpr cc_ULE,0xc1daca
c1dab8  movbz r12,RL1
c1daba  extp 0x301, #0x1
c1dabe  movbz r13,0x30f2
c1dac2  calls 0xc28852
c1dac6  mov r12,r4
c1dac8  jmpr cc_UC,0xc1dacc
c1daca  mov r12,#0x0
c1dacc  mov r9,r12
c1dace  mov r12,0xca00
c1dad2  mov r13,r9
c1dad4  mov r14,#0x8
c1dad6  calls 0xc2849c
c1dada  mov r12,r4
c1dadc  mov r13,#0x6400
c1dae0  mov r14,#0xf
c1dae2  calls 0xc27b86
c1dae6  mov r12,r4
c1dae8  extp 0x301, #0x1
c1daec  cmp r12,0x30f4
c1daf0  jmpr cc_ULE,0xc1dafa
c1daf2  extp 0x301, #0x1
c1daf6  mov r12,0x30f4
c1dafa  mov r13,r8
c1dafc  calls 0xc276a4
c1db00  mov 0xc9f4,r4
c1db04  cmp r4,#0x8000
c1db08  jmpr cc_ULE,0xc1db12
c1db0a  mov r8,#0x8000
c1db0e  mov 0xc9f4,r8
c1db12  mov r8,[r0+]
c1db14  mov r9,[r0+]
c1db16  rets
