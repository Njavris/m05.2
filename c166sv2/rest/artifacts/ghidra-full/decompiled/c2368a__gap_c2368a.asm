; c2368a gap_c2368a size=60
c2368a  sub r0,#0x4
c2368c  movb RL1,0xcb2d
c23690  cmpb RL1,#0x20
c23694  jmpr cc_EQ,0xc2369e
c23696  cmpb RL1,#0x10
c2369a  jmpr cc_EQ,0xc236b8
c2369c  jmpr cc_UC,0xc236be
c2369e  sub r0,#0x4
c236a0  mov r12,#0x0
c236a2  movbz r13,0xcb25
c236a6  calls 0xc23446
c236aa  mov r14,[r4+]
c236ac  mov r15,[r4]
c236ae  add r0,#0x4
c236b0  mov [r0],r14
c236b2  mov [r0+#0x2],r15
c236b6  jmpr cc_UC,0xc236be
c236b8  calls 0xc21f42
c236bc  mov [r0],r4
c236be  mov 0xcb38,[r0]
c236c2  add r0,#0x4
c236c4  rets
