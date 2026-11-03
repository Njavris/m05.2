; c276ba FUN_c276ba size=54
c276ba  mov r15,#0x0
c276bc  mov r14,r13
c276be  mov r1,r14
c276c0  ashr r1,#0xf
c276c2  mov r13,r15
c276c4  add r12,r14
c276c6  addc r13,r1
c276c8  mov r14,r12
c276ca  mov r1,r13
c276cc  sub r14,#0xffff
c276d0  subc r1,#0x0
c276d2  jmpr cc_SGE,0xc276e6
c276d4  mov r14,r12
c276d6  mov r15,r13
c276d8  sub r14,#0x0
c276da  subc r15,#0x0
c276dc  jmpr cc_SLE,0xc276e0
c276de  jmpr cc_UC,0xc276e2
c276e0  mov r12,#0x0
c276e2  mov r13,#0x0
c276e4  jmpr cc_UC,0xc276ec
c276e6  mov r12,#0xffff
c276ea  mov r13,#0x0
c276ec  mov r4,r12
c276ee  rets
