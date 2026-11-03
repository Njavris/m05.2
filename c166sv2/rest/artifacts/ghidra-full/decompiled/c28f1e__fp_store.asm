; c28f1e fp_store size=64
c28f1e  mov r3,[r10+#0x6]
c28f22  jmpr cc_EQ,0xc28f32
c28f24  mov r14,[r11+#0x6]
c28f28  mov r13,[r11+#0x4]
c28f2c  mov r12,[r11+#0x2]
c28f30  mov r6,[r11]
c28f32  mov [r10+#0x6],r5
c28f36  mov r3,[r10+#0x4]
c28f3a  mov [r10+#0x4],r9
c28f3e  mov r9,r3
c28f40  mov r3,[r10+#0x2]
c28f44  mov [r10+#0x2],r8
c28f48  mov r8,r3
c28f4a  mov r3,[r10]
c28f4c  shl r1,#0x4
c28f4e  and r7,#0xf
c28f52  or r7,r1
c28f54  bmov r7.0xf,r4.0x0
c28f58  mov [r10],r7
c28f5a  mov r7,r3
c28f5c  rets
