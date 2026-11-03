; c0d4ca gap_c0d4ca size=76
c0d4ca  mov r12,0xc372
c0d4ce  jmpr cc_NE,0xc0d4ec
c0d4d0  mov r13,0xc384
c0d4d4  mov r14,0xc386
c0d4d8  sub r13,0xc416
c0d4dc  subc r14,0xc418
c0d4e0  jmpr cc_UGT,0xc0d4ec
c0d4e2  mov r13,0xc418
c0d4e6  or r13,0xc416
c0d4ea  jmpr cc_NE,0xc0d50e
c0d4ec  mov r12,0xc372
c0d4f0  jmpr cc_NE,0xc0d514
c0d4f2  mov r13,0xc388
c0d4f6  mov r14,0xc38a
c0d4fa  sub r13,0xc428
c0d4fe  subc r14,0xc42a
c0d502  jmpr cc_UGT,0xc0d514
c0d504  mov r13,0xc42a
c0d508  or r13,0xc428
c0d50c  jmpr cc_EQ,0xc0d514
c0d50e  mov r12,#0x1
c0d510  mov 0xc36e,r12
c0d514  rets
