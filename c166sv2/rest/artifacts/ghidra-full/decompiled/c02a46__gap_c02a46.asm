; c02a46 gap_c02a46 size=130
c02a46  mov [-r0],r7
c02a48  mov [-r0],r6
c02a4a  extp 0x380, #0x1
c02a4e  movb RL6,0x1
c02a52  jnb r6.0x0,0xc02a58
c02a56  addb RL6,#0x1
c02a58  extp 0x380, #0x1
c02a5c  movb RL7,0x2
c02a60  movbz r13,RL7
c02a62  mov r12,#0x0
c02a64  extp 0x380, #0x1
c02a68  movbz r1,0x3
c02a6c  mov r14,#0x0
c02a6e  mov r15,r1
c02a70  shl r1,#0x8
c02a72  shl r14,#0x8
c02a74  shr r15,#0x8
c02a76  or r14,r15
c02a78  or r12,r1
c02a7a  or r13,r14
c02a7c  extp 0x380, #0x1
c02a80  movbz r1,0x4
c02a84  mov r14,#0x0
c02a86  or r12,r1
c02a88  or r13,r14
c02a8a  and r13,#0xff
c02a8e  mov r15,r12
c02a90  mov r1,r13
c02a92  mov r14,#0xc700
c02a96  mov r15,#0x0
c02a98  movb RL7,#0x0
c02a9a  jmpr cc_UC,0xc02aba
c02a9c  mov r1,r12
c02a9e  mov r2,r13
c02aa0  add r12,#0x2
c02aa2  addc r13,#0x0
c02aa4  exts r2, #0x1
c02aa6  mov r1,[r1]
c02aa8  mov r2,r14
c02aaa  mov r3,r15
c02aac  add r14,#0x2
c02aae  addc r15,#0x0
c02ab0  exts r3, #0x1
c02ab2  mov [r2],r1
c02ab4  srvwdt
c02ab8  addb RL7,#0x1
c02aba  movbz r1,RL6
c02abc  shr r1,#0x1
c02abe  cmpb RL1,RL7
c02ac0  jmpr cc_UGT,0xc02a9c
c02ac2  mov r6,[r0+]
c02ac4  mov r7,[r0+]
c02ac6  rets
