; c1fd9c calc_load size=322
c1fd9c  mov [-r0],r8
c1fd9e  extp 0x380, #0x1
c1fda2  movb RL1,0x89e
c1fda6  cmpb RL1,#0x2
c1fda8  jmpr cc_EQ,0xc1fdb0
c1fdaa  movb RL2,0xca37
c1fdae  jmpr cc_EQ,0xc1fdbc
c1fdb0  extp 0x380, #0x1
c1fdb4  mov 0x8a8,0xff1c
c1fdb8  jmpa cc_UC,0xc1feda
c1fdbc  extp 0x380, #0x1
c1fdc0  movb RL1,0x81b
c1fdc4  jmpr cc_EQ,0xc1fdd0
c1fdc6  extp 0x380, #0x1
c1fdca  mov 0x8b2,0xff1c
c1fdce  jmpr cc_UC,0xc1fe2c
c1fdd0  mov r12,#0x7564
c1fdd4  mov r13,0xc9d0
c1fdd8  calls 0xc2850e
c1fddc  mov r8,r4
c1fdde  mov r12,#0x755e
c1fde2  mov r13,0xca2a
c1fde6  calls 0xc2850e
c1fdea  mov r14,r4
c1fdec  mov r12,#0x794a
c1fdf0  mov r13,#0xc0
c1fdf4  mov r15,r14
c1fdf6  mov r14,r8
c1fdf8  calls 0xc2826e
c1fdfc  mov r8,r4
c1fdfe  mov r12,#0x79b6
c1fe02  mov r13,#0xc0
c1fe06  mov r14,0xc97c
c1fe0a  calls 0xc27fca
c1fe0e  mov r12,r4
c1fe10  mulu r8,r12
c1fe12  mov r13,0xfe0c
c1fe16  mov r12,r13
c1fe18  mov r8,0xfe0e
c1fe1c  shr r8,#0xf
c1fe1e  shr r13,#0xf
c1fe20  shl r12,#0x1
c1fe22  or r8,r12
c1fe24  extp 0x380, #0x1
c1fe28  mov 0x8b2,r8
c1fe2c  extp 0x380, #0x1
c1fe30  mov r8,0x8a8
c1fe34  extp 0x380, #0x1
c1fe38  cmp r8,0x8b2
c1fe3c  jmpr cc_NC,0xc1fe7a
c1fe3e  mov r12,#0x755e
c1fe42  mov r13,0xca2a
c1fe46  calls 0xc2850e
c1fe4a  mov r14,r4
c1fe4c  mov r12,#0x79aa
c1fe50  mov r13,#0xc0
c1fe54  calls 0xc27fca
c1fe58  mov r8,r4
c1fe5a  extp 0x380, #0x1
c1fe5e  mov r12,0x8a8
c1fe62  extp 0x380, #0x1
c1fe66  mov r13,0x8b2
c1fe6a  mov r14,r8
c1fe6c  calls 0xc1596e
c1fe70  extp 0x380, #0x1
c1fe74  mov 0x8a8,r4
c1fe78  jmpr cc_UC,0xc1feb2
c1fe7a  movb RL1,0xc604
c1fe7e  jmpr cc_NE,0xc1fe96
c1fe80  extp 0x301, #0x1
c1fe84  movb RL2,0x107a
c1fe88  cmpb RL2,#0x1
c1fe8a  jmpr cc_NE,0xc1fe96
c1fe8c  extp 0x301, #0x1
c1fe90  mov r8,0x39ca
c1fe94  jmpr cc_UC,0xc1feb2
c1fe96  mov r12,#0x7564
c1fe9a  mov r13,0xc9d0
c1fe9e  calls 0xc2850e
c1fea2  mov r14,r4
c1fea4  mov r12,#0x799e
c1fea8  mov r13,#0xc0
c1feac  calls 0xc27fca
c1feb0  mov r8,r4
c1feb2  extp 0x380, #0x1
c1feb6  mov r12,0x8a8
c1feba  extp 0x380, #0x1
c1febe  cmp r12,0x8b2
c1fec2  jmpr cc_C,0xc1feda
c1fec4  extp 0x380, #0x1
c1fec8  mov r13,0x8b2
c1fecc  mov r14,r8
c1fece  calls 0xc1596e
c1fed2  extp 0x380, #0x1
c1fed6  mov 0x8a8,r4
c1feda  mov r8,[r0+]
c1fedc  rets
