; c03a16 gap_c03a16 size=36
c03a16  mov r12,#0x20
c03a1a  mov r13,#0xe0
c03a1e  movb RL1,#0x3
c03a20  mov r14,r12
c03a22  mov r15,r13
c03a24  mov r12,#0x21
c03a28  mov r13,#0xe0
c03a2c  exts r15, #0x1
c03a2e  movb [r14],RL1
c03a30  movb RL2,#0x50
c03a34  exts r13, #0x1
c03a36  movb [r12],RL2
c03a38  rets
