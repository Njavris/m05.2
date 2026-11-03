; c1096e div32_checked size=52
c1096e  mov r15,#0xffff
c10972  mov r1,r15
c10974  cmp r14,#0x0
c10976  jmpr cc_ULE,0xc1099c
c10978  mov r4,r12
c1097a  mov r5,r13
c1097c  mov r10,r14
c1097e  mov r11,#0x0
c10980  calls 0xc28bb2
c10984  mov r15,r4
c10986  mov r1,r5
c10988  mov r12,r15
c1098a  mov r13,r1
c1098c  sub r12,#0xffff
c10990  subc r13,#0xffff
c10994  jmpr cc_C,0xc1099c
c10996  mov r15,#0xffff
c1099a  mov r1,r15
c1099c  mov r4,r15
c1099e  mov r5,r1
c109a0  rets
