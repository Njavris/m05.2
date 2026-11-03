; c10b0c gap_c10b0c size=50
c10b0c  mov r13,0xe892
c10b10  mov r4,r12
c10b12  mulu r4,r13
c10b14  mov r10,#0xffff
c10b18  mov r5,0xfe0c
c10b1c  mov r4,0xfe0e
c10b20  mov r11,#0x0
c10b22  calls 0xc28bb2
c10b26  mov r12,r4
c10b28  mov r14,r5
c10b2a  cmp r13,r12
c10b2c  jmpr cc_NE,0xc10b30
c10b2e  add r12,#0x1
c10b30  mov 0xe8a4,r12
c10b34  mov r12,#0x40
c10b38  or 0xe8a6,r12
c10b3c  rets
