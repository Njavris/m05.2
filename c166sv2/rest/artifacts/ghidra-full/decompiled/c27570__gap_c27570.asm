; c27570 gap_c27570 size=50
c27570  mov 0xc10a,0xff1c
c27574  mov r12,#0x0
c27576  and 0xc1be,r12
c2757a  mov r12,#0x0
c2757c  and 0xc1bc,r12
c27580  mov r12,#0x0
c27582  and 0xc1c0,r12
c27586  mov r12,#0x0
c27588  and 0xc1c2,r12
c2758c  mov r12,#0x0
c2758e  mov r13,#0x0
c27590  mov r14,r12
c27592  shl r14,#0x1
c27594  add r12,#0x1
c27596  cmp r12,#0xc
c2759a  mov [r14+#0xc1c4],r13
c2759e  jmpr cc_C,0xc2758e
c275a0  rets
