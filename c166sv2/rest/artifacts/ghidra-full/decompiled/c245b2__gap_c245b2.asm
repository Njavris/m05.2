; c245b2 gap_c245b2 size=32
c245b2  shl r12,#0x1
c245b4  mov r13,[r12+#0x7286]
c245b8  mov r12,r13
c245ba  cmp r12,#0xffff
c245be  jmpr cc_EQ,0xc245d0
c245c0  mov r13,#0xc168
c245c4  shl r12,#0x1
c245c6  add r13,r12
c245c8  mov r12,[r13]
c245ca  bfldl r12,#0x1,#0x1
c245ce  mov [r13],r12
c245d0  rets
