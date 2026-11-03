; c10398 gap_c10398 size=40
c10398  bclr 0xff10.0xb
c1039a  mov r13,0xffbe
c1039e  and r13,#0xf000
c103a2  or r13,r12
c103a4  mov 0xffbe,r13
c103a8  bset 0xffbe.0x7
c103aa  jnb 0xff98.0x7,0xc103aa
c103ae  calls 0xc10390
c103b2  mov r12,r4
c103b4  and r12,#0xffc
c103b8  shl r12,#0x4
c103ba  bset 0xff10.0xb
c103bc  mov r4,r12
c103be  rets
