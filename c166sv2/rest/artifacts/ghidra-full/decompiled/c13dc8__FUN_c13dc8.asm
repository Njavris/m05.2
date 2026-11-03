; c13dc8 FUN_c13dc8 size=24
c13dc8  mov [-r0],r8
c13dca  mov r8,#0x0
c13dcc  mov r1,r12
c13dce  cmpb RL1,#0x8
c13dd2  jmpr cc_UGT,0xc13e8e
c13dd4  movbz r12,RL1
c13dd6  shl r12,#0x1
c13dd8  add r12,#0x71b4
c13ddc  mov r12,[r12]
c13dde  jmpi cc_UC,[r12]
