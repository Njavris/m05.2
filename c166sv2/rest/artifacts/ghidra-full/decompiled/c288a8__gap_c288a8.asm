; c288a8 gap_c288a8 size=26
c288a8  mov r1,r14
c288aa  mov r2,r15
c288ac  sub r1,r12
c288ae  subc r2,r13
c288b0  jmpr cc_C,0xc288b8
c288b2  mov r4,#0x0
c288b4  mov r5,#0x0
c288b6  jmpr cc_UC,0xc288c0
c288b8  mov r4,r12
c288ba  mov r5,r13
c288bc  sub r4,r14
c288be  subc r5,r15
c288c0  rets
