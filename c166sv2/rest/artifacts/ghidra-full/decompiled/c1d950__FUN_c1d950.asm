; c1d950 FUN_c1d950 size=286
c1d950  mov r12,#0x3
c1d952  calls 0xc13dc8
c1d956  mov r12,r4
c1d958  extp 0x301, #0x1
c1d95c  mov r14,0x2c4c
c1d960  mulu r12,r14
c1d962  mov r13,#0x0
c1d964  mov r12,0xfe0c
c1d968  mov r15,r12
c1d96a  extp 0x301, #0x1
c1d96e  mov r13,0x2c4e
c1d972  calls 0xc276ba
c1d976  mov 0xc9f2,r4
c1d97a  extp 0x301, #0x1
c1d97e  cmp r4,0x2c76
c1d982  jmpr cc_NC,0xc1da44
c1d984  extp 0x301, #0x1
c1d988  cmp r4,0x2c78
c1d98c  jmpr cc_ULE,0xc1da44
c1d98e  mov r12,0xca0c
c1d992  mov r13,r4
c1d994  extp 0x301, #0x1
c1d998  mov r14,0x2c74
c1d99c  calls 0xc1596e
c1d9a0  mov 0xca0c,r4
c1d9a4  mov r12,r4
c1d9a6  add r12,0xca1a
c1d9aa  shr r12,#0x1
c1d9ac  mov 0xc9f6,r12
c1d9b0  cmp r4,0xc9f6
c1d9b4  jmpr cc_C,0xc1d9c4
c1d9b6  mov r12,0xca0c
c1d9ba  mov r13,0xc9f6
c1d9be  calls 0xc28852
c1d9c2  jmpr cc_UC,0xc1d9d0
c1d9c4  mov r12,0xc9f6
c1d9c8  mov r13,0xca0c
c1d9cc  calls 0xc28852
c1d9d0  mov 0xca02,r4
c1d9d4  mov r12,0xca0c
c1d9d8  mov 0xca1a,r12
c1d9dc  movb 0xca14,0xff1c
c1d9e0  movb RL1,0xc934
c1d9e4  jmpr cc_EQ,0xc1da20
c1d9e6  extp 0x301, #0x1
c1d9ea  movb RL2,0x2b68
c1d9ee  jmpr cc_NE,0xc1d9f6
c1d9f0  movb RL1,0xc92f
c1d9f4  jmpr cc_UC,0xc1d9fa
c1d9f6  movb RL1,0xc930
c1d9fa  cmpb RL1,#0x0
c1d9fc  jmpr cc_NE,0xc1da6c
c1d9fe  movb RL1,0xc9f8
c1da02  jmpr cc_NE,0xc1da18
c1da04  movb RL2,#0x1
c1da06  movb 0xc9f8,RL2
c1da0a  movb 0xca08,0xff1c
c1da0e  mov r12,0xc9f2
c1da12  mov 0xca04,r12
c1da16  rets
c1da18  movb RL1,#0x1
c1da1a  movb 0xca08,RL1
c1da1e  jmpr cc_UC,0xc1da2a
c1da20  mov r12,0xca0c
c1da24  cmp r12,0xc9f6
c1da28  jmpr cc_UGT,0xc1da6c
c1da2a  mov r12,0xca04
c1da2e  mov r13,0xc9f2
c1da32  extp 0x301, #0x1
c1da36  mov r14,0x2c92
c1da3a  calls 0xc1596e
c1da3e  mov 0xca04,r4
c1da42  rets
c1da44  movb RL1,#0x1
c1da46  movb 0xca14,RL1
c1da4a  movb 0xca08,0xff1c
c1da4e  mov r12,#0x7546
c1da52  mov r13,0xc06a
c1da56  calls 0xc2850e
c1da5a  mov r14,r4
c1da5c  mov r12,#0x6c7a
c1da60  mov r13,#0xc0
c1da64  calls 0xc27ca4
c1da68  mov 0xca04,r4
c1da6c  rets
