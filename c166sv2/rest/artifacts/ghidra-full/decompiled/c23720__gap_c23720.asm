; c23720 gap_c23720 size=74
c23720  sub r0,#0x4
c23722  movb RL1,0xcb2d
c23726  cmpb RL1,#0x20
c2372a  jmpr cc_EQ,0xc23738
c2372c  cmpb RL1,#0x10
c23730  jmpr cc_NE,0xc23750
c23732  mov [r0],0xc936
c23736  jmpr cc_UC,0xc23750
c23738  sub r0,#0x4
c2373a  mov r12,#0x2
c2373c  movbz r13,0xcb25
c23740  calls 0xc23446
c23744  mov r14,[r4+]
c23746  mov r15,[r4]
c23748  add r0,#0x4
c2374a  mov [r0],r14
c2374c  mov [r0+#0x2],r15
c23750  mov r12,#0x76fe
c23754  mov r13,[r0]
c23756  calls 0xc284d8
c2375a  mov [r0],r4
c2375c  mov r12,[r0]
c2375e  shr r12,#0x8
c23760  mov r1,r12
c23762  movb 0xcb39,RL1
c23766  add r0,#0x4
c23768  rets
