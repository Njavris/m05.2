; c1db18 gap_c1db18 size=372
c1db18  mov [-r0],r8
c1db1a  mov r12,#0x5146
c1db1e  mov r13,#0xc0
c1db22  mov r14,0xc9d0
c1db26  calls 0xc28544
c1db2a  mov r8,r4
c1db2c  mov r12,#0x753a
c1db30  mov r13,0xc9f4
c1db34  calls 0xc2850e
c1db38  mov r14,r4
c1db3a  mov r12,#0x6e50
c1db3e  mov r13,#0xc0
c1db42  mov r15,r8
c1db44  calls 0xc2826e
c1db48  mov 0xca16,r4
c1db4c  mov r12,0xc06a
c1db50  extp 0x301, #0x1
c1db54  mov r13,0x2b96
c1db58  mov r14,#0x8
c1db5a  calls 0xc27b86
c1db5e  mov 0xca12,r4
c1db62  mov r12,r4
c1db64  mov r13,0xca16
c1db68  mov r14,#0x8
c1db6a  calls 0xc2849c
c1db6e  mov 0xca06,r4
c1db72  mov r12,r4
c1db74  mov r13,0xc9ee
c1db78  mov r14,#0xf
c1db7a  calls 0xc2849c
c1db7e  mov 0xca1c,r4
c1db82  movb RL1,0xcc32
c1db86  jmpr cc_NE,0xc1dbd8
c1db88  movb RL2,0xca18
c1db8c  jmpr cc_NE,0xc1dbd8
c1db8e  mov r8,0xca2a
c1db92  extp 0x301, #0x1
c1db96  cmp r8,0x314a
c1db9a  jmpr cc_NC,0xc1dbb2
c1db9c  movb RL3,0xc841
c1dba0  jmpr cc_NE,0xc1dbb2
c1dba2  mov r12,0xca04
c1dba6  mov 0xca1c,r12
c1dbaa  movb RL4,#0x1
c1dbac  movb 0xca10,RL4
c1dbb0  jmpr cc_UC,0xc1dbdc
c1dbb2  movb RL1,0xca10
c1dbb6  cmpb RL1,#0x1
c1dbb8  jmpr cc_NE,0xc1dbd8
c1dbba  mov r8,0xca2a
c1dbbe  extp 0x301, #0x1
c1dbc2  cmp r8,0x314c
c1dbc6  jmpr cc_NC,0xc1dbd8
c1dbc8  movb RL2,0xc841
c1dbcc  jmpr cc_NE,0xc1dbd8
c1dbce  mov r12,0xca04
c1dbd2  mov 0xca1c,r12
c1dbd6  jmpr cc_UC,0xc1dbdc
c1dbd8  movb 0xca10,0xff1c
c1dbdc  extp 0x301, #0x1
c1dbe0  movb RL1,0x107b
c1dbe4  cmpb RL1,#0x1
c1dbe6  jmpr cc_NE,0xc1dbf0
c1dbe8  mov r8,0xca04
c1dbec  mov 0xca1c,r8
c1dbf0  mov r8,0xc06a
c1dbf4  cmp r8,0xca1c
c1dbf8  jmpr cc_ULE,0xc1dc0a
c1dbfa  mov r12,r8
c1dbfc  mov r13,0xca1c
c1dc00  calls 0xc28852
c1dc04  mov 0xc9fc,r4
c1dc08  jmpr cc_UC,0xc1dc0e
c1dc0a  mov 0xc9fc,0xff1c
c1dc0e  mov r8,0xc06a
c1dc12  cmp r8,0xca04
c1dc16  jmpr cc_ULE,0xc1dc28
c1dc18  mov r12,r8
c1dc1a  mov r13,0xca04
c1dc1e  calls 0xc28852
c1dc22  mov 0xca1e,r4
c1dc26  jmpr cc_UC,0xc1dc2c
c1dc28  mov 0xca1e,0xff1c
c1dc2c  mov r8,0xca1c
c1dc30  extp 0x380, #0x1
c1dc34  cmp r8,0x86e
c1dc38  jmpr cc_ULE,0xc1dc5c
c1dc3a  mov r12,r8
c1dc3c  extp 0x380, #0x1
c1dc40  mov r13,0x86e
c1dc44  calls 0xc28852
c1dc48  extp 0x380, #0x1
c1dc4c  mov 0x86a,r4
c1dc50  movb RL1,#0x1
c1dc52  extp 0x380, #0x1
c1dc56  movb 0x86c,RL1
c1dc5a  jmpr cc_UC,0xc1dc7c
c1dc5c  extp 0x380, #0x1
c1dc60  mov r12,0x86e
c1dc64  mov r13,0xca1c
c1dc68  calls 0xc28852
c1dc6c  extp 0x380, #0x1
c1dc70  mov 0x86a,r4
c1dc74  extp 0x380, #0x1
c1dc78  movb 0x86c,0xff1c
c1dc7c  mov r8,0xca1c
c1dc80  extp 0x380, #0x1
c1dc84  mov 0x86e,r8
c1dc88  mov r8,[r0+]
c1dc8a  rets
