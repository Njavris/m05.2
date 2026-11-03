; c2699e gap_c2699e size=88
c2699e  mov r12,0xc06a
c269a2  extp 0x301, #0x1
c269a6  cmp r12,0x3e20
c269aa  jmpr cc_C,0xc269f2
c269ac  mov r13,0xc072
c269b0  extp 0x301, #0x1
c269b4  cmp r13,0x3e26
c269b8  jmpr cc_C,0xc269f2
c269ba  mov r14,0xc94e
c269be  extp 0x301, #0x1
c269c2  cmp r14,0x3e28
c269c6  jmpr cc_SLT,0xc269f2
c269c8  mov r15,0xc962
c269cc  extp 0x301, #0x1
c269d0  cmp r15,0x3e30
c269d4  jmpr cc_C,0xc269f2
c269d6  extp 0x301, #0x1
c269da  cmp r15,0x3e2e
c269de  jmpr cc_UGT,0xc269f2
c269e0  mov r1,0xc936
c269e4  extp 0x301, #0x1
c269e8  cmp r1,0x3e22
c269ec  jmpr cc_SLT,0xc269f2
c269ee  movb RL4,#0x1
c269f0  rets
c269f2  movb RL4,#0x0
c269f4  rets
