; c12856 gap_c12856 size=112
c12856  mov r1,r12
c12858  movb RL2,0xc5ae
c1285c  and r2,#0xc0
c12860  cmp r2,#0xc0
c12864  jmpr cc_NE,0xc12870
c12866  movb RL2,#0x80
c1286a  movb 0xc58b,RL2
c1286e  jmpr cc_UC,0xc1287c
c12870  movb RL2,0xc5ae
c12874  andb RL2,#0xc0
c12878  movb 0xc58b,RL2
c1287c  movb RL2,RL1
c1287e  and r2,#0x3f
c12882  movbz r12,RL1
c12884  cmp r2,r12
c12886  jmpr cc_NE,0xc1288c
c12888  orb 0xc58b,RL1
c1288c  movb 0xc593,RL1
c12890  movb RL2,0xc5ae
c12894  jb r2.0x7,0xc1289e
c12898  andb RL2,#0xc0
c1289c  jmpr cc_EQ,0xc128ae
c1289e  movb RL1,0xc594
c128a2  movb 0xc5b7,RL1
c128a6  movb RL2,#0x11
c128aa  movb 0xc5c1,RL2
c128ae  mov r12,0xc5ac
c128b2  cmp r12,0xc5a6
c128b6  jmpr cc_NC,0xc128c0
c128b8  mov r13,#0xa
c128ba  mov 0xc584,r13
c128be  rets
c128c0  calls 0xc127fe
c128c4  rets
