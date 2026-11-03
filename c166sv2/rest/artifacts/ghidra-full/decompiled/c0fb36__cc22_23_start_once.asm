; c0fb36 cc22_23_start_once size=56
c0fb36  mov [-r0],r8
c0fb38  movb RL1,0xc456
c0fb3c  jmpr cc_NE,0xc0fb6a
c0fb3e  movb RL2,#0x1
c0fb40  movb 0xc456,RL2
c0fb44  calls 0xc0bd54
c0fb48  calls 0xc1064c
c0fb4c  mov r8,r4
c0fb4e  mov r12,#0x0
c0fb50  mov r13,r8
c0fb52  calls 0xc0face
c0fb56  mov r12,#0x1
c0fb58  mov r13,r8
c0fb5a  calls 0xc0face
c0fb5e  extp 0x301, #0x1
c0fb62  add r8,0x39da
c0fb66  mov 0xc448,r8
c0fb6a  mov r8,[r0+]
c0fb6c  rets
