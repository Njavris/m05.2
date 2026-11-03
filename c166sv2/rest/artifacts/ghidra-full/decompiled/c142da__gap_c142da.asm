; c142da gap_c142da size=38
c142da  mov r12,#0xa
c142dc  calls 0xc10398
c142e0  shr r4,#0x6
c142e2  mov r12,r4
c142e4  cmp r12,#0x2cc
c142e8  jmpr cc_C,0xc142f0
c142ea  mov r13,#0x1
c142ec  mov 0xc5fe,r13
c142f0  cmp r12,#0x1ff
c142f4  jmpr cc_UGT,0xc142fa
c142f6  mov 0xc5fe,0xff1c
c142fa  mov r12,0xc5fe
c142fe  jmpr cc_UC,0xc1435c
