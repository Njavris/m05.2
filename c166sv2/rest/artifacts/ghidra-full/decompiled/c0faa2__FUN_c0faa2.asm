; c0faa2 FUN_c0faa2 size=44
c0faa2  mov r13,#0x0
c0faa4  movb RL1,0xc456
c0faa8  cmpb RL1,#0x1
c0faaa  jmpr cc_EQ,0xc0fab0
c0faac  cmpb RL1,#0x2
c0faae  jmpr cc_NE,0xc0faca
c0fab0  mov r13,r12
c0fab2  shl r13,#0x1
c0fab4  mov r14,r12
c0fab6  mov r12,[r13+#0x7046]
c0faba  mov r13,r14
c0fabc  mov r14,0xc448
c0fac0  calls 0xc0be6a
c0fac4  mov r13,#0x1
c0fac6  subb 0xc456,0xff1e
c0faca  mov r4,r13
c0facc  rets
