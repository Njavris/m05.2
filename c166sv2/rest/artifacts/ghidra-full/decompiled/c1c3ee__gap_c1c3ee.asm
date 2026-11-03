; c1c3ee gap_c1c3ee size=34
c1c3ee  mov r1,r12
c1c3f0  cmpb RL1,#0x1
c1c3f2  jmpr cc_NE,0xc1c406
c1c3f4  mov r1,r13
c1c3f6  movbz r12,RL1
c1c3f8  shl r12,#0x1
c1c3fa  mov r13,r12
c1c3fc  mov r12,[r13+#0xcb02]
c1c400  calls 0xc141fc
c1c404  rets
c1c406  mov r12,#0xffff
c1c40a  calls 0xc141fc
c1c40e  rets
