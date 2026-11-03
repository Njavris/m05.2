; c243ea gap_c243ea size=32
c243ea  shl r12,#0x1
c243ec  mov r13,[r12+#0x7286]
c243f0  mov r12,r13
c243f2  cmp r12,#0xffff
c243f6  jmpr cc_EQ,0xc24408
c243f8  mov r13,#0xc168
c243fc  shl r12,#0x1
c243fe  add r13,r12
c24400  mov r12,[r13]
c24402  and r12,#0xffdf
c24406  mov [r13],r12
c24408  rets
