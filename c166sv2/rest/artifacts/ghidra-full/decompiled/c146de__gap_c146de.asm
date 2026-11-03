; c146de gap_c146de size=52
c146de  mov r13,#0x0
c146e0  extp 0x301, #0x1
c146e4  mov r14,0x1068
c146e8  jmpr cc_EQ,0xc146ee
c146ea  cmp r14,#0x4
c146ec  jmpr cc_NE,0xc1470e
c146ee  mov r1,r12
c146f0  cmpb RL1,#0x0
c146f2  jmpr cc_EQ,0xc146f8
c146f4  cmpb RL1,#0x1
c146f6  jmpr cc_NE,0xc1470e
c146f8  mov r12,#0x0
c146fa  extp 0x301, #0x1
c146fe  mov r13,0x1068
c14702  jmpr cc_EQ,0xc14708
c14704  cmp r13,#0x4
c14706  jmpr cc_NE,0xc1470c
c14708  mov r12,0xc4dc
c1470c  mov r13,r12
c1470e  mov r4,r13
c14710  rets
