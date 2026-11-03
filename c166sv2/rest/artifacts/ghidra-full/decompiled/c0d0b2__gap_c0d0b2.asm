; c0d0b2 gap_c0d0b2 size=46
c0d0b2  movbz r12,0xc3d9
c0d0b6  shl r12,#0x1
c0d0b8  movb RL1,[r12+#0x700e]
c0d0bc  cmpb RL1,0xc256
c0d0c0  jmpr cc_NE,0xc0d0c8
c0d0c2  mov r12,#0x0
c0d0c4  calls 0xc0f132
c0d0c8  movbz r12,0xc3f3
c0d0cc  shl r12,#0x1
c0d0ce  movb RL1,[r12+#0xc468]
c0d0d2  cmpb RL1,0xc256
c0d0d6  jmpr cc_NE,0xc0d0de
c0d0d8  mov r12,#0x1
c0d0da  calls 0xc0f132
c0d0de  rets
