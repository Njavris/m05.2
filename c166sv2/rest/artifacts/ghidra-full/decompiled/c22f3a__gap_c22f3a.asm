; c22f3a gap_c22f3a size=200
c22f3a  extp 0x301, #0x1
c22f3e  movb RL1,0x106c
c22f42  cmpb RL1,#0x3
c22f44  jmpr cc_NE,0xc23000
c22f46  movb RL2,0xc93c
c22f4a  cmpb RL2,#0x3
c22f4c  jmpr cc_NE,0xc22f52
c22f4e  mov r12,#0x1
c22f50  jmpr cc_UC,0xc22f54
c22f52  mov r12,#0x0
c22f54  cmp r12,#0x1
c22f56  jmpr cc_NE,0xc22fa8
c22f58  movb RL1,0xc954
c22f5c  cmpb RL1,#0x1
c22f5e  jmpr cc_NE,0xc22fa8
c22f60  mov r12,#0x1
c22f62  calls 0xc24530
c22f66  cmpb RL4,#0x0
c22f68  jmpr cc_NE,0xc22f8e
c22f6a  mov r12,#0x2
c22f6c  calls 0xc24530
c22f70  cmpb RL4,#0x0
c22f72  jmpr cc_NE,0xc22f8e
c22f74  extp 0x380, #0x1
c22f78  movb RL1,0x8cf
c22f7c  cmpb RL1,#0x1
c22f7e  jmpr cc_EQ,0xc22f8e
c22f80  mov r12,0xc936
c22f84  extp 0x301, #0x1
c22f88  cmp r12,0x3d08
c22f8c  jmpr cc_SLE,0xc22f9a
c22f8e  movb RL1,#0x1
c22f90  extp 0x380, #0x1
c22f94  movb 0x8ce,RL1
c22f98  jmpr cc_UC,0xc22fb0
c22f9a  mov r12,0xc936
c22f9e  extp 0x301, #0x1
c22fa2  cmp r12,0x3d0a
c22fa6  jmpr cc_SGT,0xc22fb0
c22fa8  extp 0x380, #0x1
c22fac  movb 0x8ce,0xff1c
c22fb0  mov r12,#0x6
c22fb2  calls 0xc14cec
c22fb6  extp 0x380, #0x1
c22fba  movb RL1,0x8ce
c22fbe  jmpr cc_EQ,0xc22fd4
c22fc0  mov r12,#0xffff
c22fc4  mov r13,#0x8000
c22fc8  mov r14,#0xf
c22fca  calls 0xc27b86
c22fce  mov 0xc98c,r4
c22fd2  jmpr cc_UC,0xc22fe4
c22fd4  mov r12,#0x0
c22fd6  mov r13,#0x8000
c22fda  mov r14,#0xf
c22fdc  calls 0xc27b86
c22fe0  mov 0xc98c,r4
c22fe4  mov r12,#0x8000
c22fe8  mov r13,0xc98c
c22fec  calls 0xc28852
c22ff0  mov 0xc98c,r4
c22ff4  mov r12,#0x6
c22ff6  mov r13,#0x40
c22ffa  mov r14,r4
c22ffc  calls 0xc14c70
c23000  rets
