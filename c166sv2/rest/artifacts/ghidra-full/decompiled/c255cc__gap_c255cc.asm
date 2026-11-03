; c255cc gap_c255cc size=52
c255cc  mov [-r0],r8
c255ce  movb RL1,0xc702
c255d2  jmpr cc_EQ,0xc255da
c255d4  calls 0xc25414
c255d8  jmpr cc_UC,0xc255fc
c255da  mov r8,#0x0
c255dc  mov r12,r8
c255de  calls 0xc243ea
c255e2  mov r12,r8
c255e4  calls 0xc2444c
c255e8  mov r12,r8
c255ea  calls 0xc24722
c255ee  mov r12,r8
c255f0  calls 0xc24572
c255f4  add r8,#0x1
c255f6  cmp r8,#0x27
c255fa  jmpr cc_C,0xc255dc
c255fc  mov r8,[r0+]
c255fe  rets
