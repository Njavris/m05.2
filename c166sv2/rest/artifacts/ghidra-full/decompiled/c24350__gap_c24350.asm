; c24350 gap_c24350 size=56
c24350  shl r12,#0x1
c24352  mov r13,[r12+#0x7286]
c24356  mov r12,r13
c24358  cmp r12,#0xffff
c2435c  jmpr cc_EQ,0xc24386
c2435e  mov r13,#0xc168
c24362  shl r12,#0x1
c24364  add r13,r12
c24366  mov r12,[r13]
c24368  shr r12,#0x6
c2436a  and r12,#0x3
c2436c  cmp r12,#0x0
c2436e  jmpr cc_ULE,0xc24386
c24370  mov r12,[r13]
c24372  shr r12,#0x6
c24374  and r12,#0x3
c24376  sub r12,#0x1
c24378  and r12,#0x3
c2437a  shl r12,#0x6
c2437c  mov r14,[r13]
c2437e  and r14,#0xff3f
c24382  or r14,r12
c24384  mov [r13],r14
c24386  rets
