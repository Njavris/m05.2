; c0dc62 event_cancel size=40
c0dc62  mov r1,r12
c0dc64  movbz r12,RL1
c0dc66  mov r15,r12
c0dc68  shl r12,#0x3
c0dc6a  add r12,r15
c0dc6c  shl r12,#0x1
c0dc6e  mov r13,#0x0
c0dc70  mov r14,#0x0
c0dc72  mov [r12+#0xc416],r13
c0dc76  mov [r12+#0xc418],r14
c0dc7a  movb RL2,#0x0
c0dc7c  movb [r12+#0xc41c],RL2
c0dc80  mov r1,r1
c0dc82  movbz r12,RL1
c0dc84  calls 0xc0e1b6
c0dc88  rets
