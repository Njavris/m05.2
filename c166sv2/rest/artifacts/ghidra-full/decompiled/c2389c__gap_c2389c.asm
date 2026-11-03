; c2389c gap_c2389c size=56
c2389c  sub r0,#0x4
c2389e  movb RL1,0xcb2d
c238a2  cmpb RL1,#0x20
c238a6  jmpr cc_EQ,0xc238b4
c238a8  cmpb RL1,#0x10
c238ac  jmpr cc_NE,0xc238cc
c238ae  mov [r0],0xc9d0
c238b2  jmpr cc_UC,0xc238cc
c238b4  sub r0,#0x4
c238b6  mov r12,#0x6
c238b8  movbz r13,0xcb25
c238bc  calls 0xc23446
c238c0  mov r14,[r4+]
c238c2  mov r15,[r4]
c238c4  add r0,#0x4
c238c6  mov [r0],r14
c238c8  mov [r0+#0x2],r15
c238cc  mov 0xcb38,[r0]
c238d0  add r0,#0x4
c238d2  rets
