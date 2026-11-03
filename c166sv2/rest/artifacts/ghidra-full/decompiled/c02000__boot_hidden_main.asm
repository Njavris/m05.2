; c02000 boot_hidden_main size=192
c02000  movb RL1,#0xff
c02004  extp 0x380, #0x1
c02008  movb 0x0,RL1
c0200c  mov r12,#0xff06
c02010  sub r0,#0x8
c02014  movb 0xf800,0xff1c
c02018  mov r13,[r12]
c0201a  bfldl r13,#0x4,#0x4
c0201e  mov [r12],r13
c02020  calls 0xc02140
c02024  mov r12,#0xff06
c02028  mov r13,[r12]
c0202a  bfldl r13,#0x8,#0x8
c0202e  mov [r12],r13
c02030  calls 0xc02250
c02034  calls 0xc022fc
c02038  calls 0xc0231e
c0203c  mov r12,0xffa2
c02040  jnb r12.0xb,0xc02084
c02044  mov r13,#0x4000
c02048  mov r14,#0xc0
c0204c  mov [r0+#0x4],r13
c02050  mov [r0+#0x6],r14
c02054  mov r15,#0x4
c02056  mov [-r0],r15
c02058  mov r1,#0x2
c0205a  add r1,r0
c0205c  mov r4,r1
c0205e  calls 0xc03de2
c02062  mov r12,r4
c02064  mov r13,r5
c02066  mov r1,#0x6
c02068  add r1,r0
c0206a  mov r4,r1
c0206c  calls 0xc03de2
c02070  mov r14,r4
c02072  mov r15,r5
c02074  calls 0xc0210a
c02078  add r0,#0x2
c0207a  mov r4,[r0]
c0207c  mov r5,[r0+#0x2]
c02080  calls 0xc03ddc
c02084  extp 0x380, #0x1
c02088  movb RL1,0x0
c0208c  cmpb RL1,#0xff
c02090  jmpr cc_EQ,0xc020ba
c02092  cmpb RL1,#0x19
c02096  jmpr cc_UGT,0xc020ae
c02098  mov r1,r1
c0209a  movbz r12,RL1
c0209c  shl r12,#0x2
c0209e  extp 0x300, #0x2
c020a2  mov r4,[r12+#0x3df8]
c020a6  mov r5,[r12+#0x3dfa]
c020aa  calls 0xc03ddc
c020ae  movb RL1,#0xff
c020b2  extp 0x380, #0x1
c020b6  movb 0x0,RL1
c020ba  srvwdt
c020be  jmpr cc_UC,0xc02084
