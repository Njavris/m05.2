; c0ecb6 FUN_c0ecb6 size=48
c0ecb6  mov r14,r12
c0ecb8  sub r12,r13
c0ecba  cmp r12,#0x8000
c0ecbe  jmpr cc_C,0xc0ecc8
c0ecc0  mov r14,r13
c0ecc2  add r14,0xc452
c0ecc6  jmpr cc_UC,0xc0ece2
c0ecc8  cmp r12,0xc472
c0eccc  jmpr cc_ULE,0xc0ecd6
c0ecce  mov r14,r13
c0ecd0  add r14,0xc472
c0ecd4  jmpr cc_UC,0xc0ece2
c0ecd6  cmp r12,0xc45a
c0ecda  jmpr cc_NC,0xc0ece2
c0ecdc  mov r14,r13
c0ecde  add r14,0xc45a
c0ece2  mov r4,r14
c0ece4  rets
