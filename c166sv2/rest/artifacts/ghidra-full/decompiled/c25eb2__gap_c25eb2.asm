; c25eb2 gap_c25eb2 size=246
c25eb2  calls 0xc25fa8
c25eb6  calls 0xc25fd8
c25eba  calls 0xc26008
c25ebe  calls 0xc26026
c25ec2  mov r12,#0xcc1c
c25ec6  mov [-r0],r12
c25ec8  movbz r12,0xcc15
c25ecc  extp 0x380, #0x1
c25ed0  movbz r13,0x8d8
c25ed4  movbz r14,0xcc1e
c25ed8  mov r15,#0xcc18
c25edc  calls 0xc24cb4
c25ee0  mov r12,#0xcc22
c25ee4  mov [r0],r12
c25ee6  movbz r12,0xcc1f
c25eea  extp 0x380, #0x1
c25eee  movbz r13,0x8d9
c25ef2  movbz r14,0xcc1a
c25ef6  mov r15,#0xcc20
c25efa  calls 0xc24cb4
c25efe  mov r12,#0xcc25
c25f02  mov [r0],r12
c25f04  mov r13,#0xcc15
c25f08  mov [-r0],r13
c25f0a  mov r12,0xcc18
c25f0e  mov r13,0xcc1c
c25f12  extp 0x301, #0x1
c25f16  mov r14,0x3d60
c25f1a  extp 0x301, #0x1
c25f1e  mov r15,0x3d62
c25f22  calls 0xc24d1c
c25f26  add r0,#0x4
c25f28  mov r12,#0xcc24
c25f2c  mov r13,#0xcc1f
c25f30  mov [-r0],r12
c25f32  mov [-r0],r13
c25f34  mov r12,0xcc20
c25f38  mov r13,0xcc22
c25f3c  extp 0x301, #0x1
c25f40  mov r14,0x3d5c
c25f44  extp 0x301, #0x1
c25f48  mov r15,0x3d5e
c25f4c  calls 0xc24d1c
c25f50  add r0,#0x4
c25f52  mov r12,#0x4
c25f54  movbz r13,0xcc15
c25f58  movbz r14,0xcc25
c25f5c  calls 0xc24d82
c25f60  mov r12,#0x3
c25f62  movbz r13,0xcc1f
c25f66  movbz r14,0xcc24
c25f6a  calls 0xc24d82
c25f6e  mov r12,#0x4
c25f70  calls 0xc24530
c25f74  cmpb RL4,#0x0
c25f76  jmpr cc_NE,0xc25f82
c25f78  mov r12,#0x3
c25f7a  calls 0xc24530
c25f7e  cmpb RL4,#0x0
c25f80  jmpr cc_EQ,0xc25f8a
c25f82  movb RL1,#0x1
c25f84  movb 0xcc16,RL1
c25f88  jmpr cc_UC,0xc25f8e
c25f8a  movb 0xcc16,0xff1c
c25f8e  movb RL1,0xcc1e
c25f92  jmpr cc_NE,0xc25f9a
c25f94  movb RL2,0xcc1a
c25f98  jmpr cc_EQ,0xc25fa2
c25f9a  movb RL1,#0x1
c25f9c  movb 0xcc14,RL1
c25fa0  rets
c25fa2  movb 0xcc14,0xff1c
c25fa6  rets
