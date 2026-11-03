; c15028 gap_c15028 size=60
c15028  movb 0xc6ba,0xff1c
c1502c  mov r12,#0x0
c1502e  movb RL1,#0x0
c15030  movb [r12+#0xc6a6],RL1
c15034  movb [r12+#0xc667],RL1
c15038  movb [r12+#0xc63b],RL1
c1503c  movb [r12+#0xc612],RL1
c15040  mov r13,#0xc67c
c15044  mov r14,r12
c15046  shl r14,#0x1
c15048  add r13,r14
c1504a  movb [r12+#0xc64f],RL1
c1504e  movb [r12+#0xc626],RL1
c15052  mov r14,[r13]
c15054  and r14,#0xfff0
c15058  mov [r13],r14
c1505a  add r12,#0x1
c1505c  cmp r12,#0x14
c15060  jmpr cc_C,0xc1502e
c15062  rets
