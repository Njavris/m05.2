; c202ee calc_limit3 size=170
c202ee  mov [-r0],r8
c202f0  mov r12,#0x7552
c202f4  mov r13,0xc936
c202f8  calls 0xc284d8
c202fc  mov r8,r4
c202fe  mov r12,#0x7912
c20302  mov r13,#0xc0
c20306  mov r14,r8
c20308  calls 0xc27ca4
c2030c  extp 0x380, #0x1
c20310  mov 0x8a6,r4
c20314  mov r12,#0x78e2
c20318  mov r13,#0xc0
c2031c  mov r14,r8
c2031e  calls 0xc27fca
c20322  extp 0x380, #0x1
c20326  mov 0x8a4,r4
c2032a  mov r12,#0x7874
c2032e  mov r13,#0xc0
c20332  mov r14,r8
c20334  calls 0xc27fca
c20338  mov r8,r4
c2033a  mov r12,#0x750a
c2033e  mov r13,0xc06a
c20342  calls 0xc2850e
c20346  mov r14,r4
c20348  mov r12,#0x78d8
c2034c  mov r13,#0xc0
c20350  calls 0xc27fca
c20354  mov r12,r4
c20356  mulu r8,r12
c20358  mov r13,0xfe0c
c2035c  mov r12,r13
c2035e  mov r8,0xfe0e
c20362  shr r8,#0xd
c20364  shr r13,#0xd
c20366  shl r12,#0x3
c20368  or r8,r12
c2036a  extp 0x380, #0x1
c2036e  mov 0x8ac,r8
c20372  cmp r8,#0x8000
c20376  jmpr cc_ULE,0xc20384
c20378  mov r12,#0x8000
c2037c  extp 0x380, #0x1
c20380  mov 0x8ac,r12
c20384  extp 0x380, #0x1
c20388  mov r8,0x8ac
c2038c  extp 0x380, #0x1
c20390  mov 0x8a0,r8
c20394  mov r8,[r0+]
c20396  rets
