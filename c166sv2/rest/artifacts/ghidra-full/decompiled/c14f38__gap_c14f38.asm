; c14f38 gap_c14f38 size=174
c14f38  cmp r13,#0x3
c14f3a  jmpr cc_EQ,0xc14fe4
c14f3c  cmp r13,#0x1
c14f3e  jmpr cc_EQ,0xc14fe4
c14f40  mov r1,r12
c14f42  cmpb RL1,#0x0
c14f44  jmpr cc_EQ,0xc14f54
c14f46  cmpb RL1,#0x1
c14f48  jmpr cc_EQ,0xc14f70
c14f4a  cmpb RL1,#0x5
c14f4c  jmpr cc_EQ,0xc14f94
c14f4e  cmpb RL1,#0x6
c14f50  jmpr cc_EQ,0xc14fb8
c14f52  jmpr cc_UC,0xc14fe4
c14f54  mov r12,0xc4a8
c14f58  jnb r12.0x7,0xc14fe4
c14f5c  cmp r13,#0x2
c14f5e  jmpr cc_NE,0xc14f6a
c14f60  mov r13,#0xfffe
c14f64  and 0xc4ae,r13
c14f68  rets
c14f6a  cmp r13,#0x0
c14f6c  jmpr cc_NE,0xc14fe4
c14f6e  jmpr cc_UC,0xc14fdc
c14f70  mov r12,0xc4a8
c14f74  jnb r12.0x5,0xc14fe4
c14f78  cmp r13,#0x2
c14f7a  jmpr cc_NE,0xc14f86
c14f7c  mov r13,#0xfffb
c14f80  and 0xc4ae,r13
c14f84  rets
c14f86  cmp r13,#0x0
c14f88  jmpr cc_NE,0xc14fe4
c14f8a  mov r12,#0xfffb
c14f8e  and 0xc4ac,r12
c14f92  rets
c14f94  mov r12,0xc4a8
c14f98  jnb r12.0x2,0xc14fe4
c14f9c  cmp r13,#0x2
c14f9e  jmpr cc_NE,0xc14faa
c14fa0  mov r13,#0xffdf
c14fa4  and 0xc4ae,r13
c14fa8  rets
c14faa  cmp r13,#0x0
c14fac  jmpr cc_NE,0xc14fe4
c14fae  mov r12,#0xffdf
c14fb2  and 0xc4ac,r12
c14fb6  rets
c14fb8  mov r12,0xc4a8
c14fbc  jnb r12.0x4,0xc14fe4
c14fc0  cmp r13,#0x2
c14fc2  jmpr cc_NE,0xc14fce
c14fc4  mov r13,#0xfff7
c14fc8  and 0xc4ae,r13
c14fcc  rets
c14fce  cmp r13,#0x0
c14fd0  jmpr cc_NE,0xc14fe4
c14fd2  mov r12,#0xfff7
c14fd6  and 0xc4ac,r12
c14fda  rets
c14fdc  mov r12,#0xfffe
c14fe0  and 0xc4ac,r12
c14fe4  rets
