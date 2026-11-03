; c25c6c gap_c25c6c size=310
c25c6c  calls 0xc25da2
c25c70  calls 0xc25e00
c25c74  mov r12,#0xcc04
c25c78  mov [-r0],r12
c25c7a  movbz r12,0xcc08
c25c7e  extp 0x380, #0x1
c25c82  movbz r13,0x8d6
c25c86  extp 0x380, #0x1
c25c8a  movbz r14,0x700
c25c8e  mov r15,#0xcc0c
c25c92  calls 0xc24cb4
c25c96  mov r12,#0xcc06
c25c9a  mov [r0],r12
c25c9c  movbz r12,0xcc10
c25ca0  extp 0x380, #0x1
c25ca4  movbz r13,0x8d7
c25ca8  extp 0x380, #0x1
c25cac  movbz r14,0x6fe
c25cb0  mov r15,#0xcc0e
c25cb4  calls 0xc24cb4
c25cb8  mov r12,#0xcc0a
c25cbc  mov [r0],r12
c25cbe  mov r13,#0xcc08
c25cc2  mov [-r0],r13
c25cc4  mov r12,0xcc0c
c25cc8  mov r13,0xcc04
c25ccc  extp 0x301, #0x1
c25cd0  mov r14,0x3d3c
c25cd4  extp 0x301, #0x1
c25cd8  mov r15,0x3d3e
c25cdc  calls 0xc24d1c
c25ce0  add r0,#0x4
c25ce2  mov r12,#0xcc09
c25ce6  mov r13,#0xcc10
c25cea  mov [-r0],r12
c25cec  mov [-r0],r13
c25cee  mov r12,0xcc0e
c25cf2  mov r13,0xcc06
c25cf6  extp 0x301, #0x1
c25cfa  mov r14,0x3d38
c25cfe  extp 0x301, #0x1
c25d02  mov r15,0x3d3a
c25d06  calls 0xc24d1c
c25d0a  add r0,#0x4
c25d0c  mov r12,#0x2
c25d0e  movbz r13,0xcc08
c25d12  movbz r14,0xcc0a
c25d16  calls 0xc24d82
c25d1a  mov r12,#0x1
c25d1c  movbz r13,0xcc10
c25d20  movbz r14,0xcc09
c25d24  calls 0xc24d82
c25d28  mov r12,#0x1
c25d2a  calls 0xc24530
c25d2e  cmpb RL4,#0x0
c25d30  jmpr cc_NE,0xc25d3c
c25d32  mov r12,#0x2
c25d34  calls 0xc24530
c25d38  cmpb RL4,#0x0
c25d3a  jmpr cc_EQ,0xc25d48
c25d3c  movb RL1,#0x1
c25d3e  extp 0x380, #0x1
c25d42  movb 0x6fc,RL1
c25d46  jmpr cc_UC,0xc25d50
c25d48  extp 0x380, #0x1
c25d4c  movb 0x6fc,0xff1c
c25d50  mov r12,#0x1
c25d52  calls 0xc24530
c25d56  cmpb RL4,#0x0
c25d58  jmpr cc_NE,0xc25d64
c25d5a  mov r12,#0x2
c25d5c  calls 0xc24530
c25d60  cmpb RL4,#0x0
c25d62  jmpr cc_EQ,0xc25d70
c25d64  movb RL1,#0x1
c25d66  extp 0x380, #0x1
c25d6a  movb 0x6fd,RL1
c25d6e  jmpr cc_UC,0xc25d78
c25d70  extp 0x380, #0x1
c25d74  movb 0x6fd,0xff1c
c25d78  extp 0x380, #0x1
c25d7c  movb RL1,0x700
c25d80  jmpr cc_NE,0xc25d8c
c25d82  extp 0x380, #0x1
c25d86  movb RL2,0x6fe
c25d8a  jmpr cc_EQ,0xc25d98
c25d8c  movb RL1,#0x1
c25d8e  extp 0x380, #0x1
c25d92  movb 0x6ff,RL1
c25d96  rets
c25d98  extp 0x380, #0x1
c25d9c  movb 0x6ff,0xff1c
c25da0  rets
