; c2444c gap_c2444c size=32
c2444c  shl r12,#0x1
c2444e  mov r13,[r12+#0x7286]
c24452  mov r12,r13
c24454  cmp r12,#0xffff
c24458  jmpr cc_EQ,0xc2446a
c2445a  mov r13,#0xc168
c2445e  shl r12,#0x1
c24460  add r13,r12
c24462  mov r12,[r13]
c24464  and r12,#0xffef
c24468  mov [r13],r12
c2446a  rets
