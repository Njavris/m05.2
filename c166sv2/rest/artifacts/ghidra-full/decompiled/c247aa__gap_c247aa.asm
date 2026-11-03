; c247aa gap_c247aa size=60
c247aa  sub r0,#0x4
c247ac  mov r13,[r12]
c247ae  mov r14,[r12+#0x2]
c247b2  mov [r0],r13
c247b4  mov [r0+#0x2],r14
c247b8  jmpr cc_UC,0xc247d8
c247ba  mov [-r0],r12
c247bc  mov r4,[r0+#0x2]
c247c0  mov r5,[r0+#0x4]
c247c4  calls 0xc28c4e
c247c8  mov r12,[r0+]
c247ca  add r12,#0x4
c247cc  mov r13,[r12]
c247ce  mov r14,[r12+#0x2]
c247d2  mov [r0],r13
c247d4  mov [r0+#0x2],r14
c247d8  mov r13,[r0]
c247da  mov r14,[r0+#0x2]
c247de  or r13,r14
c247e0  jmpr cc_NE,0xc247ba
c247e2  add r0,#0x4
c247e4  rets
