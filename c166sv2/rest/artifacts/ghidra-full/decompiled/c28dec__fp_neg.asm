; c28dec fp_neg size=26
c28dec  sub r0,#0x8
c28df0  mov r10,r0
c28df2  mov [-r0],r7
c28df4  mov [-r0],r8
c28df6  mov [-r0],r9
c28df8  mov r7,r4
c28dfa  shr r7,#0xf
c28dfc  mov [r10+#0x6],r7
c28e00  jmpr cc_EQ,0xc28e18
c28e02  neg r4
c28e04  jmpr cc_UC,0xc28e18
