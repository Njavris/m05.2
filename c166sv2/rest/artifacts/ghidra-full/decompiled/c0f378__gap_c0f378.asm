; c0f378 gap_c0f378 size=90
c0f378  movbz r12,0xc3b9
c0f37c  mov 0xc446,r12
c0f380  mov r13,0xc27e
c0f384  mov 0xc466,r13
c0f388  mov r14,0xfd06
c0f38c  jnb r14.0xf,0xc0f3d0
c0f390  jnb 0xfd0a.0x0,0xc0f3a0
c0f394  mov r14,0xfd0a
c0f398  jnb r14.0x0,0xc0f3be
c0f39c  cmp r12,#0x1
c0f39e  jmpr cc_NE,0xc0f3be
c0f3a0  mov r12,#0x1
c0f3a2  mov 0xc446,r12
c0f3a6  calls 0xc0e7ca
c0f3aa  mov r12,0xc466
c0f3ae  mov 0xc3f0,r12
c0f3b2  calls 0xc0eafe
c0f3b6  calls 0xc0e910
c0f3ba  bset 0xfd06.0x0
c0f3bc  rets
c0f3be  jb 0xfd06.0xb,0xc0f3d0
c0f3c2  mov r12,0xc466
c0f3c6  mov 0xc3f0,r12
c0f3ca  mov r12,#0x1
c0f3cc  calls 0xc0f482
c0f3d0  rets
