; c1e380 gap_c1e380 size=160
c1e380  movb RL1,0xca41
c1e384  cmpb RL1,#0x8
c1e388  jmpr cc_EQ,0xc1e41a
c1e38a  mov r12,#0x71b5
c1e38e  mov r13,#0xc0
c1e392  movbz r1,RL1
c1e394  mov r14,#0x0
c1e396  add r12,r1
c1e398  addc r13,r14
c1e39a  exts r13, #0x1
c1e39c  movb RL1,[r12]
c1e39e  jmpr cc_EQ,0xc1e3ac
c1e3a0  mov r12,#0x25
c1e3a4  calls 0xc24530
c1e3a8  cmpb RL4,#0x0
c1e3aa  jmpr cc_EQ,0xc1e3e4
c1e3ac  mov r12,#0x71a2
c1e3b0  mov r13,#0xc0
c1e3b4  movbz r14,0xca41
c1e3b8  shl r14,#0x1
c1e3ba  mov r15,#0x0
c1e3bc  add r12,r14
c1e3be  addc r13,r15
c1e3c0  exts r13, #0x1
c1e3c2  mov r14,[r12]
c1e3c4  cmp r14,0xc9d0
c1e3c8  jmpr cc_UGT,0xc1e3d0
c1e3ca  movb RL1,#0x1
c1e3cc  movb 0xca40,RL1
c1e3d0  exts r13, #0x1
c1e3d2  mov r12,[r12]
c1e3d4  extp 0x301, #0x1
c1e3d8  sub r12,0x31b2
c1e3dc  cmp r12,0xc9d0
c1e3e0  jmpr cc_ULE,0xc1e41e
c1e3e2  jmpr cc_UC,0xc1e41a
c1e3e4  mov r12,#0x71be
c1e3e8  mov r13,#0xc0
c1e3ec  movbz r14,0xca41
c1e3f0  shl r14,#0x1
c1e3f2  mov r15,#0x0
c1e3f4  add r12,r14
c1e3f6  addc r13,r15
c1e3f8  exts r13, #0x1
c1e3fa  mov r14,[r12]
c1e3fc  cmp r14,0xca3e
c1e400  jmpr cc_UGT,0xc1e408
c1e402  movb RL1,#0x1
c1e404  movb 0xca40,RL1
c1e408  exts r13, #0x1
c1e40a  mov r12,[r12]
c1e40c  extp 0x301, #0x1
c1e410  sub r12,0x31ce
c1e414  cmp r12,0xca3e
c1e418  jmpr cc_ULE,0xc1e41e
c1e41a  movb 0xca40,0xff1c
c1e41e  rets
