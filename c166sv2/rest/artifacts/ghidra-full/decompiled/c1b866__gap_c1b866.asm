; c1b866 gap_c1b866 size=284
c1b866  mov [-r0],r8
c1b868  mov [-r0],r6
c1b86a  extp 0x380, #0x1
c1b86e  movb RL1,0x810
c1b872  jmpr cc_NE,0xc1b87e
c1b874  extp 0x380, #0x1
c1b878  movb RL2,0x811
c1b87c  jmpr cc_EQ,0xc1b8f6
c1b87e  mov r12,#0x6b6a
c1b882  mov r13,#0xc0
c1b886  mov r14,0xc97c
c1b88a  calls 0xc27ca4
c1b88e  mov r13,r4
c1b890  mov r8,0xc9d0
c1b894  extp 0x301, #0x1
c1b898  cmp r8,0x2b92
c1b89c  jmpr cc_ULE,0xc1b8b8
c1b89e  mov r6,0xca1c
c1b8a2  extp 0x301, #0x1
c1b8a6  cmp r6,0x2b94
c1b8aa  jmpr cc_ULE,0xc1b8b8
c1b8ac  extp 0x301, #0x1
c1b8b0  movbz r12,0x2b91
c1b8b4  shl r12,#0x8
c1b8b6  jmpr cc_UC,0xc1b8c2
c1b8b8  extp 0x301, #0x1
c1b8bc  movbz r12,0x2b90
c1b8c0  shl r12,#0x8
c1b8c2  mulu r13,r12
c1b8c4  mov r8,0xfe0c
c1b8c8  mov r13,0xfe0e
c1b8cc  mov r6,r8
c1b8ce  shr r13,#0xf
c1b8d0  shr r8,#0xf
c1b8d2  shl r6,#0x1
c1b8d4  or r13,r6
c1b8d6  mov r12,r13
c1b8d8  cmp r12,#0x8000
c1b8dc  jmpr cc_ULE,0xc1b8ec
c1b8de  mov r8,#0x8000
c1b8e2  extp 0x380, #0x1
c1b8e6  mov 0x834,r8
c1b8ea  jmpr cc_UC,0xc1b8fe
c1b8ec  extp 0x380, #0x1
c1b8f0  mov 0x834,r12
c1b8f4  jmpr cc_UC,0xc1b8fe
c1b8f6  extp 0x380, #0x1
c1b8fa  mov 0x834,0xff1c
c1b8fe  extp 0x380, #0x1
c1b902  mov r12,0x834
c1b906  extp 0x301, #0x1
c1b90a  mov r8,0x2b8e
c1b90e  mov r13,#0x8000
c1b912  mov r14,#0xf
c1b914  calls 0xc27b86
c1b918  mov 0xc98c,r4
c1b91c  mov r12,#0x8000
c1b920  mov r13,r4
c1b922  calls 0xc28852
c1b926  mov 0xc98c,r4
c1b92a  mov r12,#0x0
c1b92c  mov r13,r8
c1b92e  mov r14,r4
c1b930  calls 0xc14c70
c1b934  extp 0x301, #0x1
c1b938  movb RL6,0x106d
c1b93c  cmpb RL6,#0x1
c1b93e  jmpr cc_NE,0xc1b94c
c1b940  mov r12,#0x5
c1b942  mov r13,r8
c1b944  mov r14,0xc98c
c1b948  calls 0xc14c70
c1b94c  extp 0x380, #0x1
c1b950  movb RL6,0x811
c1b954  extp 0x380, #0x1
c1b958  movb RL1,0x810
c1b95c  cmpb RL1,#0x1
c1b95e  jmpr cc_NE,0xc1b966
c1b960  mov r12,#0x0
c1b962  calls 0xc14cec
c1b966  extp 0x301, #0x1
c1b96a  movb RL1,0x106d
c1b96e  cmpb RL1,#0x1
c1b970  jmpr cc_NE,0xc1b97c
c1b972  cmpb RL6,#0x1
c1b974  jmpr cc_NE,0xc1b97c
c1b976  mov r12,#0x5
c1b978  calls 0xc14cec
c1b97c  mov r6,[r0+]
c1b97e  mov r8,[r0+]
c1b980  rets
