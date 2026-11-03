; c129e2 gap_c129e2 size=52
c129e2  jb 0xffc4.0xb,0xc129ec
c129e6  subb 0xc571,0xff1e
c129ea  jmpr cc_UC,0xc12a08
c129ec  movb RL1,0xc571
c129f0  cmpb RL1,#0x2
c129f2  jmpr cc_C,0xc12a02
c129f4  movb 0xc571,0xff1c
c129f8  mov r12,#0x3
c129fa  mov 0xc584,r12
c129fe  jmpa cc_UC,0xc12f6e
c12a02  mov r12,#0x0
c12a04  calls 0xc126bc
c12a08  movb RL1,0xc571
c12a0c  cmpb RL1,#0x4
c12a0e  jmpa cc_ULE,0xc12f6e
c12a12  jmpa cc_UC,0xc12ade
