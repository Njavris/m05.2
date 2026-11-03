; c0d71e FUN_c0d71e size=96
c0d71e  mov r4,r13
c0d720  mulu r4,r12
c0d722  mov r10,#0xf
c0d724  mov r5,0xfe0c
c0d728  mov r4,0xfe0e
c0d72c  mov r11,#0x0
c0d72e  calls 0xc28bb2
c0d732  mov r12,r5
c0d734  shr r4,#0x6
c0d736  shr r5,#0x6
c0d738  shl r12,#0xa
c0d73a  or r4,r12
c0d73c  mov 0xc3a6,r4
c0d740  mov 0xc3a8,r5
c0d744  sub r4,#0xff00
c0d748  subc r5,#0x0
c0d74a  jmpr cc_ULE,0xc0d76e
c0d74c  mov r12,#0xff00
c0d750  sub 0xc3a6,r12
c0d754  subc 0xc3a8,0xff1c
c0d758  mov r13,#0x1
c0d75a  mov 0xc3aa,r13
c0d75e  mov r14,0xfe70
c0d762  mov r15,0xc48e
c0d766  add r14,#0xff00
c0d76a  mov [r15],r14
c0d76c  rets
c0d76e  mov r12,0xc3a6
c0d772  add r12,0xfe70
c0d776  mov r13,0xc48e
c0d77a  mov [r13],r12
c0d77c  rets
