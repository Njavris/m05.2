; c260d8 gap_c260d8 size=314
c260d8  calls 0xc26212
c260dc  calls 0xc19846
c260e0  mov r12,#0xcc2e
c260e4  mov [-r0],r12
c260e6  movbz r12,0xcc2a
c260ea  extp 0x380, #0x1
c260ee  movbz r13,0x8df
c260f2  extp 0x380, #0x1
c260f6  movbz r14,0x8dd
c260fa  mov r15,#0xcc34
c260fe  calls 0xc24cb4
c26102  mov r12,#0xcc30
c26106  mov [r0],r12
c26108  movbz r12,0xcc37
c2610c  extp 0x380, #0x1
c26110  movbz r13,0x8de
c26114  extp 0x380, #0x1
c26118  movbz r14,0x8dc
c2611c  mov r15,#0xcc28
c26120  calls 0xc24cb4
c26124  mov r12,#0xcc33
c26128  mov [r0],r12
c2612a  mov r13,#0xcc2a
c2612e  mov [-r0],r13
c26130  mov r12,0xcc34
c26134  mov r13,0xcc2e
c26138  extp 0x301, #0x1
c2613c  mov r14,0x3d7c
c26140  extp 0x301, #0x1
c26144  mov r15,0x3d7e
c26148  calls 0xc24d1c
c2614c  add r0,#0x4
c2614e  mov r12,#0xcc36
c26152  mov r13,#0xcc37
c26156  mov [-r0],r12
c26158  mov [-r0],r13
c2615a  mov r12,0xcc28
c2615e  mov r13,0xcc30
c26162  extp 0x301, #0x1
c26166  mov r14,0x3d78
c2616a  extp 0x301, #0x1
c2616e  mov r15,0x3d7a
c26172  calls 0xc24d1c
c26176  add r0,#0x4
c26178  mov r12,#0x6
c2617a  movbz r13,0xcc2a
c2617e  movbz r14,0xcc33
c26182  calls 0xc24d82
c26186  mov r12,#0x5
c26188  movbz r13,0xcc37
c2618c  movbz r14,0xcc36
c26190  calls 0xc24d82
c26194  mov r12,#0x6
c26196  calls 0xc24530
c2619a  cmpb RL4,#0x0
c2619c  jmpr cc_NE,0xc261bc
c2619e  mov r12,#0x5
c261a0  calls 0xc24530
c261a4  cmpb RL4,#0x0
c261a6  jmpr cc_NE,0xc261bc
c261a8  extp 0x380, #0x1
c261ac  movb RL1,0x8dd
c261b0  jmpr cc_NE,0xc261bc
c261b2  extp 0x380, #0x1
c261b6  movb RL2,0x8dc
c261ba  jmpr cc_EQ,0xc261c4
c261bc  movb RL1,#0x1
c261be  movb 0xcc38,RL1
c261c2  jmpr cc_UC,0xc261c8
c261c4  movb 0xcc38,0xff1c
c261c8  mov r12,#0x6
c261ca  calls 0xc24530
c261ce  cmpb RL4,#0x0
c261d0  jmpr cc_NE,0xc261dc
c261d2  mov r12,#0x5
c261d4  calls 0xc24530
c261d8  cmpb RL4,#0x0
c261da  jmpr cc_EQ,0xc261e8
c261dc  movb RL1,#0x1
c261de  movb 0xcc32,RL1
c261e2  movb 0xcc2b,RL1
c261e6  jmpr cc_UC,0xc261f0
c261e8  movb 0xcc32,0xff1c
c261ec  movb 0xcc2b,0xff1c
c261f0  extp 0x380, #0x1
c261f4  movb RL1,0x8dd
c261f8  jmpr cc_NE,0xc26204
c261fa  extp 0x380, #0x1
c261fe  movb RL2,0x8dc
c26202  jmpr cc_EQ,0xc2620c
c26204  movb RL1,#0x1
c26206  movb 0xcc2c,RL1
c2620a  rets
c2620c  movb 0xcc2c,0xff1c
c26210  rets
