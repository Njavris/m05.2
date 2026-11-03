; c2663a gap_c2663a size=70
c2663a  mov r1,[r0]
c2663c  mov r2,[r0+#0x4]
c26640  mov r3,r12
c26642  cmpb RL3,#0x1
c26644  jmpr cc_NE,0xc2666c
c26646  mov r12,[r0+#0x2]
c2664a  cmp r1,r12
c2664c  jmpr cc_NC,0xc26654
c2664e  movb RL3,#0x1
c26650  movb [r14],RL3
c26652  jmpr cc_UC,0xc26666
c26654  cmp r1,r2
c26656  jmpr cc_ULE,0xc26662
c26658  movb RL1,#0x0
c2665a  movb [r14],RL1
c2665c  movb RL2,#0x1
c2665e  movb [r15],RL2
c26660  rets
c26662  movb RL1,#0x0
c26664  movb [r14],RL1
c26666  movb RL1,#0x0
c26668  movb [r15],RL1
c2666a  rets
c2666c  movb RL3,#0x0
c2666e  movb [r14],RL3
c26670  movb [r15],RL3
c26672  movb RL4,[r13]
c26674  cmpb RL4,#0x1
c26676  jmpr cc_NE,0xc2667e
c26678  cmp r1,r2
c2667a  jmpr cc_NC,0xc2667e
c2667c  movb [r13],RL3
c2667e  rets
