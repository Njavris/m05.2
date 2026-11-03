; c27776 gap_c27776 size=60
c27776  mov r1,r12
c27778  mov r2,r13
c2777a  add r1,r14
c2777c  addc r2,r15
c2777e  mov r3,r1
c27780  mov r4,r2
c27782  jmpr cc_N,0xc27796
c27784  mov r3,r14
c27786  mov r4,r15
c27788  jmpr cc_NN,0xc27796
c2778a  mov r3,r12
c2778c  mov r4,r13
c2778e  jmpr cc_NN,0xc27796
c27790  mov r1,#0x0
c27792  mov r2,#0x8000
c27796  mov r3,r1
c27798  mov r4,r2
c2779a  jmpr cc_NN,0xc277ac
c2779c  cmp r15,#0x0
c2779e  jmpr cc_N,0xc277ac
c277a0  cmp r13,#0x0
c277a2  jmpr cc_N,0xc277ac
c277a4  mov r1,#0xffff
c277a8  mov r2,#0x7fff
c277ac  mov r4,r1
c277ae  mov r5,r2
c277b0  rets
