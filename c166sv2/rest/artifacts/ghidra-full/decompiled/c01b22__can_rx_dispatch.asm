; c01b22 can_rx_dispatch size=194
c01b22  mov r12,0xc1d2
c01b26  cmp r12,#0xa
c01b2a  jmpr cc_NE,0xc01bd4
c01b2c  extp 0x3, #0x1
c01b30  movb RL1,0x3744
c01b34  movbz r13,RL1
c01b36  mov 0xc1d4,r13
c01b3a  shl r13,#0x8
c01b3c  mov 0xc1d4,r13
c01b40  extp 0x3, #0x1
c01b44  movb RL2,0x3745
c01b48  movbz r14,RL2
c01b4a  or 0xc1d4,r14
c01b4e  extp 0x3, #0x1
c01b52  movb RL3,0x3740
c01b56  movbz r3,RL3
c01b58  mov r13,#0x0
c01b5a  mov 0xc1d8,r3
c01b5e  mov 0xc1da,r13
c01b62  mov r14,r3
c01b64  shl r3,#0x8
c01b66  shl r13,#0x8
c01b68  shr r14,#0x8
c01b6a  or r13,r14
c01b6c  extp 0x3, #0x1
c01b70  movb RL4,0x3741
c01b74  movbz r4,RL4
c01b76  mov r14,#0x0
c01b78  or r3,r4
c01b7a  or r13,r14
c01b7c  mov 0xc1d8,r3
c01b80  mov 0xc1da,r13
c01b84  mov r15,r3
c01b86  shl r3,#0x8
c01b88  shl r13,#0x8
c01b8a  shr r15,#0x8
c01b8c  or r13,r15
c01b8e  extp 0x3, #0x1
c01b92  movb RL4,0x3742
c01b96  movbz r4,RL4
c01b98  mov r15,#0x0
c01b9a  or r3,r4
c01b9c  or r13,r15
c01b9e  mov 0xc1d8,r3
c01ba2  mov 0xc1da,r13
c01ba6  mov r4,r3
c01ba8  shl r3,#0x8
c01baa  shl r13,#0x8
c01bac  shr r4,#0x8
c01bae  or r13,r4
c01bb0  extp 0x3, #0x1
c01bb4  movb RL4,0x3743
c01bb8  movbz r4,RL4
c01bba  mov r5,#0x0
c01bbc  or r3,r4
c01bbe  or r13,r5
c01bc0  mov 0xc1d8,r3
c01bc4  mov 0xc1da,r13
c01bc8  mov 0xc1dc,r3
c01bcc  mov 0xc1de,r13
c01bd0  calls 0xc01be4
c01bd4  mov r12,0xc1d2
c01bd8  cmp r12,#0x9
c01bdc  jmpr cc_NE,0xc01be2
c01bde  calls 0xc01c6e
c01be2  rets
