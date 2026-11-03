; c1a298 gap_c1a298 size=122
c1a298  mov [-r0],r8
c1a29a  mov r12,0xc8ea
c1a29e  extp 0x301, #0x1
c1a2a2  cmp r12,0x2506
c1a2a6  jmpr cc_SLE,0xc1a2b2
c1a2a8  extp 0x301, #0x1
c1a2ac  mov r12,0x2506
c1a2b0  jmpr cc_UC,0xc1a2ce
c1a2b2  mov r12,0xc8ea
c1a2b6  extp 0x301, #0x1
c1a2ba  cmp r12,0x2508
c1a2be  jmpr cc_SGE,0xc1a2ca
c1a2c0  extp 0x301, #0x1
c1a2c4  mov r12,0x2508
c1a2c8  jmpr cc_UC,0xc1a2ce
c1a2ca  mov r12,0xc8ea
c1a2ce  mov r8,r12
c1a2d0  mov 0xc8ea,r8
c1a2d4  extp 0x301, #0x1
c1a2d8  mov r12,0x2cca
c1a2dc  add r8,r12
c1a2de  extp 0x301, #0x1
c1a2e2  cmp r8,0x2506
c1a2e6  jmpr cc_SLE,0xc1a2f2
c1a2e8  extp 0x301, #0x1
c1a2ec  mov r12,0x2506
c1a2f0  jmpr cc_UC,0xc1a308
c1a2f2  extp 0x301, #0x1
c1a2f6  cmp r8,0x2508
c1a2fa  jmpr cc_SGE,0xc1a306
c1a2fc  extp 0x301, #0x1
c1a300  mov r12,0x2508
c1a304  jmpr cc_UC,0xc1a308
c1a306  mov r12,r8
c1a308  mov r8,r12
c1a30a  mov 0xc8e6,r8
c1a30e  mov r8,[r0+]
c1a310  rets
