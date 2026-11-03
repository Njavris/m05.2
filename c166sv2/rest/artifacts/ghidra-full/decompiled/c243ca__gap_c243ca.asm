; c243ca gap_c243ca size=32
c243ca  shl r12,#0x1
c243cc  mov r13,[r12+#0x7286]
c243d0  mov r12,r13
c243d2  cmp r12,#0xffff
c243d6  jmpr cc_EQ,0xc243e8
c243d8  mov r13,#0xc168
c243dc  shl r12,#0x1
c243de  add r13,r12
c243e0  mov r12,[r13]
c243e2  bfldl r12,#0x20,#0x20
c243e6  mov [r13],r12
c243e8  rets
