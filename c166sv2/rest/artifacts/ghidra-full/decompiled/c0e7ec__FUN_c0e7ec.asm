; c0e7ec FUN_c0e7ec size=68
c0e7ec  mov r14,0xc476
c0e7f0  mulu r14,r12
c0e7f2  sub r0,#0x2
c0e7f4  mov r15,0xfe0c
c0e7f8  mov r14,0xfe0e
c0e7fc  mov r1,r15
c0e7fe  shr r14,#0x7
c0e800  shr r15,#0x7
c0e802  shl r1,#0x9
c0e804  or r14,r1
c0e806  mov r1,#0xb4
c0e80a  mov 0xfe0c,r15
c0e80e  mov 0xfe0e,r14
c0e812  divlu r1
c0e814  mov r13,0xfe0e
c0e818  mov [r0],r13
c0e81a  cmp r13,#0xffff
c0e81e  jmpr cc_ULE,0xc0e826
c0e820  mov r13,#0xffff
c0e824  jmpr cc_UC,0xc0e828
c0e826  mov r13,[r0]
c0e828  mov r12,r13
c0e82a  mov r4,r12
c0e82c  add r0,#0x2
c0e82e  rets
