c1293c: mov r1,r12
c1293e: movb RL2,0xc58c
c12942: movbz r12,RL2
c12944: subb 0xc58c,0xff1e
c12948: movb [r12+#0xf600],RL1
c1294c: mov r12,0xc584
c12950: cmp r12,#0x6
c12952: jmpr cc_NE,0xc1295e
c12954: movb RL1,0xf600
c12958: jmpr cc_EQ,0xc1295e
c1295a: calls 0xc12826
c1295e: movb RL1,0xc58c
c12962: cmpb RL1,#0x3d
c12966: jmpr cc_NE,0xc1296c
c12968: movb 0xc58c,0xff1c
c1296c: rets
