; c0e4c0 gap_c0e4c0 size=38
c0e4c0  mov r13,#0x0
c0e4c2  mov r14,0xc3fa
c0e4c6  cmp r14,#0x9ff0
c0e4ca  jmpr cc_EQ,0xc0e4e2
c0e4cc  mov r1,r12
c0e4ce  movbz r12,RL1
c0e4d0  mov r15,r12
c0e4d2  shl r15,#0x3
c0e4d4  add r15,r12
c0e4d6  shl r15,#0x1
c0e4d8  movb RL1,[r15+#0xc41c]
c0e4dc  jnb r1.0x3,0xc0e4e2
c0e4e0  mov r13,#0x1
c0e4e2  mov r4,r13
c0e4e4  rets
