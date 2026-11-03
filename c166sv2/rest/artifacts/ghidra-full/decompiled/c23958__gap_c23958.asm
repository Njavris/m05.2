; c23958 gap_c23958 size=42
c23958  sub r0,#0x4
c2395a  movb RL1,0xcb2d
c2395e  cmpb RL1,#0x10
c23962  jmpr cc_NE,0xc23968
c23964  mov [r0],0xc94e
c23968  mov r12,#0x76fe
c2396c  mov r13,[r0]
c2396e  calls 0xc284d8
c23972  mov [r0],r4
c23974  mov r12,[r0]
c23976  shr r12,#0x8
c23978  mov r1,r12
c2397a  movb 0xcb39,RL1
c2397e  add r0,#0x4
c23980  rets
