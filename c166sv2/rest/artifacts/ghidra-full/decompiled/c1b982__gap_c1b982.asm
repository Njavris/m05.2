; c1b982 gap_c1b982 size=138
c1b982  mov [-r0],r8
c1b984  mov [-r0],r6
c1b986  extp 0x380, #0x1
c1b98a  mov 0x834,0xff1c
c1b98e  extp 0x301, #0x1
c1b992  mov r8,0x2b8e
c1b996  mov r12,#0x0
c1b998  mov r13,#0x8000
c1b99c  mov r14,#0xf
c1b99e  calls 0xc27b86
c1b9a2  mov 0xc98c,r4
c1b9a6  mov r12,#0x8000
c1b9aa  mov r13,r4
c1b9ac  calls 0xc28852
c1b9b0  mov 0xc98c,r4
c1b9b4  mov r12,#0x0
c1b9b6  mov r13,r8
c1b9b8  mov r14,r4
c1b9ba  calls 0xc14c70
c1b9be  extp 0x301, #0x1
c1b9c2  movb RL6,0x106d
c1b9c6  cmpb RL6,#0x1
c1b9c8  jmpr cc_NE,0xc1b9d6
c1b9ca  mov r12,#0x5
c1b9cc  mov r13,r8
c1b9ce  mov r14,0xc98c
c1b9d2  calls 0xc14c70
c1b9d6  extp 0x380, #0x1
c1b9da  movb RL6,0x811
c1b9de  extp 0x380, #0x1
c1b9e2  movb RL1,0x810
c1b9e6  cmpb RL1,#0x1
c1b9e8  jmpr cc_NE,0xc1b9f0
c1b9ea  mov r12,#0x0
c1b9ec  calls 0xc14cec
c1b9f0  extp 0x301, #0x1
c1b9f4  movb RL1,0x106d
c1b9f8  cmpb RL1,#0x1
c1b9fa  jmpr cc_NE,0xc1ba06
c1b9fc  cmpb RL6,#0x1
c1b9fe  jmpr cc_NE,0xc1ba06
c1ba00  mov r12,#0x5
c1ba02  calls 0xc14cec
c1ba06  mov r6,[r0+]
c1ba08  mov r8,[r0+]
c1ba0a  rets
