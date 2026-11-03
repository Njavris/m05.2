; c288c2 gap_c288c2 size=56
c288c2  mov r1,r12
c288c4  mov r2,r13
c288c6  sub r1,r14
c288c8  subc r2,r15
c288ca  sub r14,#0x0
c288cc  subc r15,#0x0
c288ce  jmpr cc_SLE,0xc288e2
c288d0  mov r14,r1
c288d2  mov r15,r2
c288d4  sub r14,r12
c288d6  subc r15,r13
c288d8  jmpr cc_SLE,0xc288f4
c288da  mov r1,#0x0
c288dc  mov r2,#0x8000
c288e0  jmpr cc_UC,0xc288f4
c288e2  mov r14,r1
c288e4  mov r15,r2
c288e6  sub r14,r12
c288e8  subc r15,r13
c288ea  jmpr cc_SGE,0xc288f4
c288ec  mov r1,#0xffff
c288f0  mov r2,#0x7fff
c288f4  mov r4,r1
c288f6  mov r5,r2
c288f8  rets
