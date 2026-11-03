; c1deee gap_c1deee size=210
c1deee  mov [-r0],r8
c1def0  movb 0xca3c,0xff1c
c1def4  movb RL1,0xc702
c1def8  jmpr cc_EQ,0xc1df0c
c1defa  mov r12,#0xc008
c1defe  extp 0x301, #0x1
c1df02  mov r13,0x3098
c1df06  calls 0xc166a2
c1df0a  jmpr cc_UC,0xc1df26
c1df0c  mov r12,0xc008
c1df10  extp 0x301, #0x1
c1df14  mov r13,0x3090
c1df18  calls 0xc276a4
c1df1c  mov r13,r4
c1df1e  mov r12,#0xc008
c1df22  calls 0xc166a2
c1df26  mov 0xca26,0xff1c
c1df2a  mov r12,#0x5
c1df2c  calls 0xc13dc8
c1df30  mov 0xca38,r4
c1df34  mov r12,r4
c1df36  mov r13,0xc008
c1df3a  mov r14,#0x1
c1df3c  mov r15,#0x1
c1df3e  calls 0xc28a54
c1df42  mov r13,r4
c1df44  extp 0x301, #0x1
c1df48  mov r12,0x309c
c1df4c  mov r14,#0xe
c1df4e  calls 0xc2849c
c1df52  mov r8,r4
c1df54  cmp r8,#0x0
c1df56  jmpr cc_ULE,0xc1df5c
c1df58  mov r12,r8
c1df5a  jmpr cc_UC,0xc1df5e
c1df5c  mov r12,#0x0
c1df5e  cmp r12,#0x8000
c1df62  jmpr cc_ULE,0xc1df6e
c1df64  mov r8,#0x8000
c1df68  mov 0xca2a,r8
c1df6c  jmpr cc_UC,0xc1df72
c1df6e  mov 0xca2a,r12
c1df72  extp 0x301, #0x1
c1df76  movb RL1,0x107b
c1df7a  cmpb RL1,#0x1
c1df7c  jmpr cc_NE,0xc1dfa4
c1df7e  mov r12,#0x51aa
c1df82  mov r13,#0xc0
c1df86  mov r14,0xca0a
c1df8a  calls 0xc28544
c1df8e  mov r12,r4
c1df90  mov r8,r12
c1df92  mov r12,#0x6d48
c1df96  mov r13,#0xc0
c1df9a  mov r14,r8
c1df9c  calls 0xc27fca
c1dfa0  mov 0xca2a,r4
c1dfa4  mov r8,0xca2a
c1dfa8  mov 0xca3a,r8
c1dfac  mov 0xca2c,r8
c1dfb0  mov 0xca2e,r8
c1dfb4  mov 0xca30,0xff1c
c1dfb8  mov 0xca20,r8
c1dfbc  mov r8,[r0+]
c1dfbe  rets
