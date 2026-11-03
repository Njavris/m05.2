; c0f2b8 gap_c0f2b8 size=116
c0f2b8  extp 0x301, #0x1
c0f2bc  movbz r12,0x3468
c0f2c0  cmp r12,#0x1
c0f2c2  jmpr cc_NE,0xc0f2d0
c0f2c4  movbz r12,0xc3b9
c0f2c8  xor r12,#0x1
c0f2ca  mov 0xc446,r12
c0f2ce  jmpr cc_UC,0xc0f2d8
c0f2d0  movbz r12,0xc3b9
c0f2d4  mov 0xc446,r12
c0f2d8  mov r12,0xc446
c0f2dc  mov r13,0xc27e
c0f2e0  mov 0xc466,r13
c0f2e4  mov r14,0xfd08
c0f2e8  jnb r14.0xf,0xc0f376
c0f2ec  jnb 0xfd0a.0x1,0xc0f2fc
c0f2f0  mov r14,0xfd0a
c0f2f4  jnb r14.0x1,0xc0f32c
c0f2f8  cmp r12,#0x0
c0f2fa  jmpr cc_NE,0xc0f32c
c0f2fc  mov 0xc446,0xff1c
c0f300  mov r12,#0x0
c0f302  calls 0xc0e7ca
c0f306  mov r12,0xc466
c0f30a  mov 0xc3d6,r12
c0f30e  calls 0xc0eafe
c0f312  calls 0xc0e910
c0f316  bset 0xfd08.0x0
c0f318  mov r12,0xc44c
c0f31c  cmp r12,#0x1
c0f31e  jmpr cc_NE,0xc0f376
c0f320  mov r13,0xc466
c0f324  mov 0xc3f0,r13
c0f328  bset 0xfd06.0x0
c0f32a  rets
