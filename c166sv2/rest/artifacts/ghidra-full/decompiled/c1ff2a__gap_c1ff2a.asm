; c1ff2a gap_c1ff2a size=180
c1ff2a  mov r12,#0xca8a
c1ff2e  mov r13,#0xca88
c1ff32  mov r14,#0x1
c1ff34  calls 0xc159bc
c1ff38  movb RL1,0xc93c
c1ff3c  cmpb RL1,#0x1
c1ff3e  jmpr cc_NE,0xc1ffdc
c1ff40  mov r12,0xfd18
c1ff44  jnb r12.0x3,0xc1ffb6
c1ff48  movb RL2,0xc9e7
c1ff4c  extp 0x301, #0x1
c1ff50  cmpb RL2,0x2cfc
c1ff54  jmpr cc_EQ,0xc1ff60
c1ff56  extp 0x301, #0x1
c1ff5a  cmpb RL2,0x2cfd
c1ff5e  jmpr cc_NE,0xc1ff68
c1ff60  movb RL1,#0x1
c1ff62  movb 0xca88,RL1
c1ff66  jmpr cc_UC,0xc1ff6c
c1ff68  movb 0xca88,0xff1c
c1ff6c  mov r12,0xca8a
c1ff70  cmp r12,#0x64
c1ff74  jmpr cc_NC,0xc1ff88
c1ff76  extp 0x301, #0x1
c1ff7a  movb RL1,0x2cfc
c1ff7e  extp 0x380, #0x1
c1ff82  movb 0x855,RL1
c1ff86  rets
c1ff88  mov r12,0xca8a
c1ff8c  cmp r12,#0xa4
c1ff90  jmpr cc_NC,0xc1ffa4
c1ff92  extp 0x301, #0x1
c1ff96  movb RL1,0x2cfd
c1ff9a  extp 0x380, #0x1
c1ff9e  movb 0x855,RL1
c1ffa2  rets
c1ffa4  extp 0x301, #0x1
c1ffa8  movb RL1,0x2ce2
c1ffac  extp 0x380, #0x1
c1ffb0  movb 0x855,RL1
c1ffb4  rets
c1ffb6  movb RL1,0xc9e7
c1ffba  extp 0x301, #0x1
c1ffbe  cmpb RL1,0x2ce2
c1ffc2  jmpr cc_EQ,0xc1ffd4
c1ffc4  extp 0x301, #0x1
c1ffc8  movb RL2,0x2ce2
c1ffcc  extp 0x380, #0x1
c1ffd0  movb 0x855,RL2
c1ffd4  movb 0xca88,0xff1c
c1ffd8  mov 0xca8a,0xff1c
c1ffdc  rets
