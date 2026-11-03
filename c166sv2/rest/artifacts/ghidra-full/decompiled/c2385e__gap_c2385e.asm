; c2385e gap_c2385e size=62
c2385e  sub r0,#0x4
c23860  movb RL1,0xcb2d
c23864  cmpb RL1,#0x20
c23868  jmpr cc_EQ,0xc23876
c2386a  cmpb RL1,#0x10
c2386e  jmpr cc_NE,0xc2388e
c23870  mov [r0],0xca04
c23874  jmpr cc_UC,0xc2388e
c23876  sub r0,#0x4
c23878  mov r12,#0x5
c2387a  movbz r13,0xcb25
c2387e  calls 0xc23446
c23882  mov r14,[r4+]
c23884  mov r15,[r4]
c23886  add r0,#0x4
c23888  mov [r0],r14
c2388a  mov [r0+#0x2],r15
c2388e  mov r12,[r0]
c23890  shr r12,#0x8
c23892  mov r1,r12
c23894  movb 0xcb39,RL1
c23898  add r0,#0x4
c2389a  rets
