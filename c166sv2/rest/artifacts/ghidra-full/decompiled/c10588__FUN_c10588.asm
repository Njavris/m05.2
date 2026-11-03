; c10588 FUN_c10588 size=94
c10588  mov r12,#0x4000
c1058c  mov r13,#0xc0
c10590  mov 0xc4c2,r12
c10594  mov 0xc4c4,r13
c10598  mov r12,0xc4c2
c1059c  mov r13,0xc4c4
c105a0  mov [-r0],r12
c105a2  shr r12,#0xe
c105a4  shl r13,#0x2
c105a6  or r13,r12
c105a8  mov r12,[r0+]
c105aa  and r12,#0x3fff
c105ae  extp r13, #0x1
c105b0  mov r12,[r12]
c105b2  mov 0xc4c0,r12
c105b6  jnb 0xffac.0x4,0xc105c8
c105ba  bclr 0xffac.0x4
c105bc  mov r12,0xc4c2
c105c0  mov r13,0xc4c4
c105c4  calls 0xc10d8e
c105c8  mov r12,#0x2
c105ca  add 0xc4c2,r12
c105ce  addc 0xc4c4,0xff1c
c105d2  mov r13,0xc4c2
c105d6  mov r14,0xc4c4
c105da  sub r13,#0xffff
c105de  subc r14,#0xc1
c105e2  jmpr cc_C,0xc10598
c105e4  rets
