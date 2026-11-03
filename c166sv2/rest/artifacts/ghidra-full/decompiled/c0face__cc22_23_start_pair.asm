; c0face cc22_23_start_pair size=42
c0face  mov [-r0],r12
c0fad0  shl r12,#0x1
c0fad2  mov r14,r12
c0fad4  mov r12,[r14+#0x7046]
c0fad8  mov r14,r13
c0fada  mov r13,[r0]
c0fadc  calls 0xc0be6a
c0fae0  mov r12,[r0+]
c0fae2  jmpa cc_NE,0xc0faec
c0fae6  extr #0x1
c0fae8  bset 0xf16e.0x6
c0faea  rets
c0faec  cmp r12,#0x1
c0faee  jmpa cc_NE,0xc0faf6
c0faf2  extr #0x1
c0faf4  bset 0xf16c.0x6
c0faf6  rets
