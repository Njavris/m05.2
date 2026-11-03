; c1ed9e gap_c1ed9e size=408
c1ed9e  movb RL1,0xca7a
c1eda2  cmpb RL1,#0x1
c1eda4  jmpr cc_NE,0xc1edac
c1eda6  mov r12,#0x6
c1eda8  calls 0xc14cec
c1edac  movb RL1,0xca7a
c1edb0  cmpb RL1,#0x1
c1edb2  jmpa cc_NE,0xc1eefc
c1edb6  calls 0xc1f2b0
c1edba  mov r12,#0x5122
c1edbe  mov r13,#0xc0
c1edc2  mov r14,0xc9d0
c1edc6  calls 0xc28544
c1edca  mov r14,r4
c1edcc  mov r12,#0x7616
c1edd0  mov r13,#0xc0
c1edd4  calls 0xc27ca4
c1edd8  mov r12,r4
c1edda  extp 0x380, #0x1
c1edde  movb RL1,0x81a
c1ede2  cmpb RL1,#0x1
c1ede4  jmpr cc_NE,0xc1edf4
c1ede6  extp 0x301, #0x1
c1edea  mov r12,0x3614
c1edee  mov 0xca7c,r12
c1edf2  jmpr cc_UC,0xc1edf8
c1edf4  mov 0xca7c,r12
c1edf8  extp 0x380, #0x1
c1edfc  movb RL1,0x87e
c1ee00  jmpr cc_NE,0xc1ee7a
c1ee02  mov r12,0xca7e
c1ee06  cmp r12,0xca7c
c1ee0a  jmpr cc_C,0xc1ee16
c1ee0c  mov 0xca80,0xff1c
c1ee10  movb 0xca82,0xff1c
c1ee14  jmpr cc_UC,0xc1eef2
c1ee16  mov r12,#0x77d6
c1ee1a  mov r15,#0xc0
c1ee1e  mov r13,0xc862
c1ee22  shl r13,#0x1
c1ee24  mov r14,#0x0
c1ee26  add r12,r13
c1ee28  addc r15,r14
c1ee2a  exts r15, #0x1
c1ee2c  mov r12,[r12]
c1ee2e  cmp r12,0xca80
c1ee32  jmpr cc_UGT,0xc1ee58
c1ee34  mov r15,#0x774e
c1ee38  mov r1,#0xc0
c1ee3c  add r15,r13
c1ee3e  addc r1,r14
c1ee40  exts r1, #0x1
c1ee42  mov r12,[r15]
c1ee44  add 0xca7e,r12
c1ee48  cmp r12,0xca7e
c1ee4c  jmpr cc_ULE,0xc1ee52
c1ee4e  mov 0xca7e,0xff1e
c1ee52  mov 0xca80,0xff1c
c1ee56  jmpr cc_UC,0xc1ee5e
c1ee58  movb RL1,#0x1
c1ee5a  movb 0xca82,RL1
c1ee5e  mov r12,0xca7e
c1ee62  extp 0x301, #0x1
c1ee66  cmp r12,0x3612
c1ee6a  jmpr cc_UGT,0xc1ef08
c1ee6c  extp 0x301, #0x1
c1ee70  mov r13,0x3612
c1ee74  mov 0xca7e,r13
c1ee78  jmpr cc_UC,0xc1ef08
c1ee7a  extp 0x380, #0x1
c1ee7e  movb RL1,0x87e
c1ee82  cmpb RL1,#0x1
c1ee84  jmpr cc_NE,0xc1eee0
c1ee86  mov r12,#0x77d6
c1ee8a  mov r15,#0xc0
c1ee8e  mov r13,0xc862
c1ee92  shl r13,#0x1
c1ee94  mov r14,#0x0
c1ee96  add r12,r13
c1ee98  addc r15,r14
c1ee9a  exts r15, #0x1
c1ee9c  mov r12,[r12]
c1ee9e  cmp r12,0xca80
c1eea2  jmpr cc_UGT,0xc1eeca
c1eea4  mov r15,#0x7792
c1eea8  mov r2,#0xc0
c1eeac  add r15,r13
c1eeae  addc r2,r14
c1eeb0  exts r2, #0x1
c1eeb2  mov r12,[r15]
c1eeb4  cmp r12,0xca7e
c1eeb8  jmpr cc_ULE,0xc1eec0
c1eeba  mov 0xca7e,0xff1c
c1eebe  jmpr cc_UC,0xc1eec4
c1eec0  sub 0xca7e,r12
c1eec4  mov 0xca80,0xff1c
c1eec8  jmpr cc_UC,0xc1eed0
c1eeca  movb RL1,#0x1
c1eecc  movb 0xca82,RL1
c1eed0  mov r12,0xca7e
c1eed4  extp 0x301, #0x1
c1eed8  cmp r12,0x3612
c1eedc  jmpr cc_NC,0xc1ef08
c1eede  jmpr cc_UC,0xc1eefc
c1eee0  mov 0xca80,0xff1c
c1eee4  movb 0xca82,0xff1c
c1eee8  mov r12,0xca7e
c1eeec  cmp r12,0xca7c
c1eef0  jmpr cc_C,0xc1ef08
c1eef2  mov r12,0xca7c
c1eef6  mov 0xca7e,r12
c1eefa  jmpr cc_UC,0xc1ef08
c1eefc  mov 0xca80,0xff1c
c1ef00  movb 0xca82,0xff1c
c1ef04  mov 0xca7e,0xff1c
c1ef08  mov r12,0xca7e
c1ef0c  mov r13,#0x8000
c1ef10  mov r14,#0xf
c1ef12  calls 0xc27b86
c1ef16  mov 0xc98c,r4
c1ef1a  mov r12,#0x8000
c1ef1e  mov r13,r4
c1ef20  calls 0xc28852
c1ef24  mov 0xc98c,r4
c1ef28  mov r12,#0x6
c1ef2a  mov r13,#0x40
c1ef2e  mov r14,r4
c1ef30  calls 0xc14c70
c1ef34  rets
