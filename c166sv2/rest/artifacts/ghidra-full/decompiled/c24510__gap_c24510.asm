; c24510 gap_c24510 size=32
c24510  shl r12,#0x1
c24512  mov r13,[r12+#0x7286]
c24516  mov r12,r13
c24518  cmp r12,#0xffff
c2451c  jmpr cc_EQ,0xc2452e
c2451e  mov r13,#0xc168
c24522  shl r12,#0x1
c24524  add r13,r12
c24526  mov r12,[r13]
c24528  and r12,#0xfffb
c2452c  mov [r13],r12
c2452e  rets
