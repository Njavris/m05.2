; c2392e gap_c2392e size=42
c2392e  sub r0,#0x4
c23930  movb RL1,0xcb2d
c23934  cmpb RL1,#0x10
c23938  jmpr cc_NE,0xc2393e
c2393a  mov [r0],0xc8e8
c2393e  mov r12,#0x771c
c23942  mov r13,[r0]
c23944  calls 0xc284d8
c23948  mov [r0],r4
c2394a  mov r12,[r0]
c2394c  shr r12,#0x8
c2394e  mov r1,r12
c23950  movb 0xcb39,RL1
c23954  add r0,#0x4
c23956  rets
