; c25026 gap_c25026 size=40
c25026  mov [-r0],r8
c25028  mov r8,#0x0
c2502a  mov r12,r8
c2502c  calls 0xc245d2
c25030  mov r12,r8
c25032  calls 0xc245f8
c25036  mov r12,r8
c25038  calls 0xc24388
c2503c  cmpi1 r8,#0x26
c25040  jmpr cc_SLT,0xc2502a
c25042  movb 0xc1b7,0xff1c
c25046  movb 0xc1b8,0xff1c
c2504a  mov r8,[r0+]
c2504c  rets
