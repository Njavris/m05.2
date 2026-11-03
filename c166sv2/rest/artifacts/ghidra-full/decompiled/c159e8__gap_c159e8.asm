; c159e8 gap_c159e8 size=42
c159e8  mov r15,#0x0
c159ea  jmpr cc_UC,0xc15a0c
c159ec  mov r1,r13
c159ee  add r1,r15
c159f0  movb RL1,[r1]
c159f2  jmpr cc_EQ,0xc15a0a
c159f4  mov r1,r15
c159f6  shl r1,#0x1
c159f8  mov r2,r1
c159fa  mov r1,r12
c159fc  add r1,r2
c159fe  mov r2,[r1]
c15a00  cmp r2,#0x0
c15a02  jmpr cc_ULE,0xc15a0a
c15a04  mov r2,[r1]
c15a06  sub r2,#0x1
c15a08  mov [r1],r2
c15a0a  add r15,#0x1
c15a0c  cmp r15,r14
c15a0e  jmpr cc_C,0xc159ec
c15a10  rets
